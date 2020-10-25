import socketserver
import socket
import threading
import logging

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
    def handle(self):
        close = 0
        while not close:
            _data = self.request.recv(1024)
            print("{} bytes rcvd: {}: ".format(len(_data), _data))

            # Server handler keep-alive loop
            # TODO: Handle message which contains a command
            # which kills the server
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
