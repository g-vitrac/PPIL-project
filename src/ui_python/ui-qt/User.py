# This Python file uses the following encoding: utf-8
from PySide6 import *
import threading
import socket
import time
import COR


class User(threading.Thread):
    def __init__(self, s, app):
        super().__init__()
        self.app = app
        self.s = s
        self.c1 = COR.DCircle()
        self.c2 = COR.DPolygon()
        self.c3 = COR.DSegment()
        self.c4 = COR.DResize()
        self.c5 = COR.DClear()
        self.cor = [self.c1, self.c2, self.c3, self.c4, self.c5]

    def run(self):
        while True:
            message = self.s.recv(255)
            requetes = message.decode().split("\n")
            for requete in requetes :
                form = requete.split(",")
                form.append(self.app)
                for detector in self.cor:
                    if detector.detected(form[0], self.app) :
                        detector.draw(form, self.app);             
                

if __name__ == "__main__":
    user = User(None, None)

