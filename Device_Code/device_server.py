# device_server.py
# Interactive RPC-ish server
# interfaces with the remote sensor node interface
# Authors: Brent Rubell, Todd Moorehouse for UMass Dartmouth ECE565
# LICENSE: MIT-0

import logging
import socket
import socketserver
import subprocess
import threading
import xml.etree.ElementTree as ET
from xml.dom import minidom

# Configuration #

# Desired server address
SERVER_ADDRESS = "localhost"

# Desired server port, must be an ephermal port
SERVER_PORT = 7000

# Logger
logging.basicConfig(level=logging.DEBUG,
                    format='%(name)s: %(message)s',
                    )

# Sensor IDs
SENSOR_TEMP      = 1
SENSOR_HUMID     = 2
SENSOR_CPU_USAGE = 3
SENSOR_CPU_TEMP  = 4
SENSOR_DUMMY     = 5

# PID Pool - stores all the PIDs currently in-use
PID_POOL = []

def dispatch_sensor_process(sensor_id):
    """Dispatches a sensor process based on the sensor
    identifier.
    :param int sensor_id: Sensor type.

    """
    # Verify that sensor process is within the node's ATTACHED_SENSORS
    if int(sensor_id) not in ATTACHED_SENSORS:
        print("ERROR: Sensor node does not contain this sensor type!")
        return 0 # failed

    print("Spawning process type: %d..."%int(sensor_id))
    proc = subprocess.Popen(['python3', 'temperature_sensor.py'],stdout=subprocess.PIPE)
    print('Process PID: ', proc.pid)
    # Add PID object and process to the active PID pool
    PID_POOL.append((proc.pid, proc))
    return proc.pid

def read_sensor_process(pid):
    """Reads and returns an active sensor process' STDOUT
    :param int pid: A valid PID.
    """
    print("Reading sensor process: %d"%pid)
    if pid not in PID_POOL:
        print("ERROR: PID not found in PID pool")
        return False

    proc_out = PID_POOL[pid][1].stdout.readline()
    # TODO: This should be moved within parse_command
    print("Output: ", proc_out)
    return proc_out

def kill_sensor_process(pid):
    """Kills an active sensor process.
    :param int pid: A valid process identifier.

    """
    print("Killing process %d"%pid)
    print(PID_POOL)
    if pid not in PID_POOL[0]:
        print("ERROR: PID not found in PID pool")
        return False
    # obtain index of subprocess.Popen object
    pid_index = next((i for i, v in enumerate(PID_POOL) if v[0] == pid), None)
    # kill it
    PID_POOL[pid_index][1].terminate()
    # wait for child process to terminate from zombie state
    PID_POOL[pid_index][1].wait()
    # Negative return code indicates process has terminated
    if PID_POOL[pid_index][1].returncode < 0:
        print("Process killed!")
        return True
    return False

def prettify(elem):
    """Return a pretty-printed XML string for the Element.

    from https://pymotw.com/3/xml.etree.ElementTree/create.html
    """
    rough_string = ET.tostring(elem, 'utf-8')
    reparsed = minidom.parseString(rough_string)
    return reparsed.toprettyxml(indent="  ")

class RPC_Handler(socketserver.BaseRequestHandler):
    """Request handler class for a RPC_Server. 
    Handles communication with a connected TCP client.

    """

    def parse_command(self, xml_cmd_string):
        """Parses XML message using message table.
        :param str xml_cmd_string: XML message.

        """

        msg_id = None
        msg_result = None
        msg_sensor_id = None
        msg_pid = None

        try: # attempt to parse XML command from interface
            root = ET.fromstring(xml_cmd_string.decode())
        except:
            print("ERROR: Unable to parse command!")
            return False
        # Parse out XML message
        for child in root:
            if child.tag == "id":
                msg_id = int(child.text)
                print("Message ID: ", msg_id)
            elif child.tag == "data":
                # Check attribute for each data type
                if "result" in child.attrib['name']:
                    msg_result = child.text
                    print("Message Result: ", msg_result)
                elif "sensorid" in child.attrib['name']:
                    msg_sensor_id = child.text
                    print("Message sensorID: ", msg_sensor_id)
                    # Attempt to spawn a sensor process
                    # with desired sensor id
                    msg_pid = dispatch_sensor_process(msg_sensor_id)
                    msg_result = 1
                elif "PID" in child.attrib['name']:
                    msg_pid = child.text
                    print("Message PID: ", msg_pid)
                    if msg_id == 1: # Kill active sensor process
                        print("Killing active process..")
                        kill_sensor_process(int(msg_pid))
                    elif msg_id == 3:
                        # Re-dispatch the process
                        # TODO!
                        print("Reset process")
                    elif msg_id == 15:
                        # Get process status
                        # TODO
                        print("Process status")
                else:
                    print("ERROR: Unexpected message field.")
                    msg_result = -1
        return (msg_id, msg_result, msg_sensor_id, msg_pid)


    def build_xml_document(self, ret_data):
        """Builds a XML document to send back to the interface.

        Example of desired XML response format:
        ```
        <message>
            <id>8</id>
            <data type="uint8_t" name="result">1</data>
            <data type="uint8_t" name="sensorid">1</data>
            <data type="uint32_t" name="pid">12232</data>
        </message>
        ```

        """
        print("Building XML response...")
        message = ET.Element('message')

        # Append subelement, <id>
        if ret_data[0] is not None:
            xml_id = ET.SubElement(message,"id")
            xml_id.text = str(ret_data[0]+1) # Resp is always id++

        # Append subelement result
        if ret_data[1] is not None:
            xml_result = ET.SubElement(message, "data", {
                "name":"result",
                "type":"uint8_t"
            })
            xml_result.text = str(ret_data[1])

        # Append subelement sensor_id
        if ret_data[1] is not None:
            xml_sensor_id = ET.SubElement(message, "data", {
                "name":"sensorid",
                "type":"uint8_t"
            })
            xml_sensor_id.text = str(ret_data[2])

        # Append subelement sensor_pid
        if ret_data[1] is not None:
            xml_sensor_id = ET.SubElement(message, "data", {
                "name":"pid",
                "type":"uint32_t"
            })
            xml_sensor_id.text = str(ret_data[3])

        # Print message
        print(prettify(message))
        # Convert to bytestring for the socket
        message = ET.tostring(message)
        return message

    def handle(self):
        """Handles all incoming TCP messages
        using BaseRequestHandler.

        """
        close = 0

        # Shared between requests and responses
        while not close:
            _data = self.request.recv(1024)
            print("{} bytes rcvd: {}: ".format(len(_data), _data))

            # Parse XML command, should return if OK
            ret_data = self.parse_command(_data)
            print(ret_data)

            # Build XML response
            xml_msg = None
            xml_msg = self.build_xml_document(ret_data)

            # Send bytestring XML response back to interface
            if xml_msg is not None:
                self.request.sendall(xml_msg)

            # Keep TCP server alive
            # TODO: Handle an incoming msg which contains a command
            # which kills the server (shuts socket)
            if not _data:
                # EOF, client closed, just return
                return
            if b'quit' in _data:
                close = 1

def start_server():
    with socketserver.TCPServer(server_address, RPC_Handler) as server:
        print("Server Active on {}:{}".format(SERVER_ADDRESS, SERVER_PORT))
        server.serve_forever()

if __name__ == '__main__':
    # Create a list of sensors attached to the node
    ATTACHED_SENSORS = [SENSOR_TEMP, SENSOR_HUMID,
                    SENSOR_CPU_USAGE, SENSOR_CPU_TEMP,SENSOR_DUMMY]

    # Define server address
    server_address = (SERVER_ADDRESS, SERVER_PORT)

    # Create and initialize server
    # NOTE: This starts a blocking loop
    start_server()
