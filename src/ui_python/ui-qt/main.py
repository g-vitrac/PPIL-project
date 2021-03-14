from PySide6 import QtWidgets, QtGui
from PySide6.QtGui import *
from PySide6.QtCore import QRectF
import Server
import sys


class App(QtWidgets.QWidget):
    def __init__(self):
        super().__init__()
        print("ixi")
        self.x = 0
        self.forms = []

    def add_form(self, form):
        self.forms.append(form)
        self.repaint()

    def swapSize(self, arg):
        self.setFixedSize(int(float(arg[1])),int(float((arg[2]))))

    def clear_window(self):
        self.forms.clear()

    def paintEvent(self, event):
        for form in self.forms:
            method, arg = form
            method(arg)
        


        
if __name__ == "__main__":
    app = QtWidgets.QApplication([])
    widget = App()
    widget.show()
    server = Server.Server(widget)
    server.start()
    sys.exit(app.exec_())
