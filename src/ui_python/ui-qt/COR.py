import abc
from PySide6 import QtWidgets, QtCore
from PySide6.QtGui import *
class DCircle():
    def __init__(self):
        pass
    
    def detected(self, form, app):
        if "Circle" in form:
            return True
        return False

    def draw(self,form, app) :
        app.add_form((self.drawingMethod, form))

    def drawingMethod(self, arg):
        p = QPainter(arg[-1])
        p.setBrush(Qt.SolidPattern)
        p.setBrush(Qt.SolidPattern)
        p.setBrush(QColor(arg[-2]))
        p.begin(arg[-1])
        p.drawEllipse(int(float(arg[1])), int(float(arg[2])), int(float(arg[3])), int(float(arg[3])))
        p.end()

class DPolygon():
    def __init__(self):
        pass
    
    def detected(self, form, app):
        if "PolygonG" in form:
            return True
        return False

    def draw(self,form, app) :
        app.add_form((self.drawingMethod, form))

    def drawingMethod(self, arg):
        p = QPainter(arg[-1])
        p.begin(arg[-1])
        p.setBrush(Qt.SolidPattern)
        p.setBrush(QColor(arg[-2]))
        polygon = QPolygon()
        x = 0
        y = 0
        cpt = 0
        for val in arg :
            if not val == arg[-2] and not val == arg[-1] and not val == arg[0]:
                if cpt%2 == 0:
                    x = int(float(val))
                else :
                    y = int(float(val))
                    polygon.append(QtCore.QPoint(x, y))
                cpt = cpt + 1
        p.drawPolygon(polygon)
        p.end()

class DSegment():
    def __init__(self):
        pass
    
    def detected(self, form, app):
        if "Segment" in form:
            return True
        return False

    def draw(self,form, app) :
        app.add_form((self.drawingMethod, form))

    def drawingMethod(self, arg):
        p = QPainter(arg[-1])
        p.begin(arg[-1])
        p.setBrush(Qt.SolidPattern)
        p.setBrush(QColor(arg[-2]))
        
        p.drawLine(int(float(arg[1])), int(float(arg[2])), int(float(arg[3])), int(float(arg[4])))
        p.end()

class DClear():
    def __init__(self):
        pass
    
    def detected(self, form, app):
        if "Clear" in form:
            return True
        return False

    def draw(self,form, app) :
        app.add_form((self.drawingMethod, form))

    def drawingMethod(self, arg):
        arg[-1].clear_window()


class DResize():
    def __init__(self):
        pass
    
    def detected(self, form, app):
        if "Resize" in form:
            return True
        return False

    def draw(self,form, app) :
        app.add_form((self.drawingMethod, form))

    def drawingMethod(self, arg):
        arg[-1].swapSize(arg)
  








    
