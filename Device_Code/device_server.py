import socketserver
import socket
import threading
import logging
import xml.etree.ElementTree as ET

# Configuration #

# Desired server address
SERVER_ADDRESS = "localhost"

# Desired server port, must be an ephermal port
SERVER_PORT = 7000

# Logger
logging.basicConfig(level=logging.DEBUG,
                    format='%(name)s: %(message)s',
                    )

class RPC_Handler(socketserver.BaseRequestHandler):
    """Request handler class for a RPC_Server. 
    Handles communication with a connected TCP client.

    """

    def parse_command(self, xml_cmd_string):
        """Parses XML message using message table.
        :param str xml_cmd_string: XML message.

        """
        # 
        msg_id = None
        msg_result = None
        msg_sensor_id = None
        msg_pid = None

        try:
            root = ET.fromstring(xml_cmd_string)
        except:
            print("ERROR: Unable to parse command!")
            return False
        print('Message Fields: ', len(root))

        # Parse out XML message
        for child in root:
            if child.tag == "id":
                msg_id = child.text
                print("Message ID: ", msg_id)
            elif child.tag == "data":
                # Check attribute for each data type
                if "result" in child.attrib['name']:
                    msg_result = child.text
                    print("Message Result: ", msg_result)
                elif "sensorid" in child.attrib['name']:
                    msg_sensor_id = child.text
                    print("Message sensorID: ", msg_sensor_id)
                elif "pid" in child.attrib['name']:
                    msg_pid = child.text
                    print("Message PID: ", msg_pid)
                else:
                    print("ERROR: Unexpected message field.")

        return True

    def handle(self):
        """Handles all incoming TCP messages
        using BaseRequestHandler.

        """
        close = 0
        while not close:
            _data = self.request.recv(1024)
            print("{} bytes rcvd: {}: ".format(len(_data), _data))

            # Parse XML command, should return if OK
            if not self.parse_command(_data.decode()):
                # Unable to parse command, close socket
                # to prevent future malformed commands
                close = 1

            # Keep TCP server alive
            # TODO: Handle an incoming msg which contains a command
            # which kills the server (shuts socket)
            if not _data:
                # EOF, client closed, just return
                return
            if b'quit' in _data:
                close = 1

if __name__ == '__main__':
    import socket
    server_address = (SERVER_ADDRESS, SERVER_PORT)

    with socketserver.TCPServer(server_address, RPC_Handler) as server:
        print("Server Active on {}:{}".format(SERVER_ADDRESS, SERVER_PORT))
        server.serve_forever()
