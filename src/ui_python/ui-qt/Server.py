# This Python file uses the following encoding: utf-8
from PySide6 import *
import main
import threading
import User
import socket
import time


class Server(threading.Thread):
    def __init__(self, app):
        super().__init__()
        self.app = app

    def run(self):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind(('localhost',9111))
        while True:
            s.listen(10)
            user, adress = s.accept()
            User.User(user, self.app).start()
            
if __name__ == "__main__":
    s = Server(None).run()
