import socket

if __name__ == "__main__":
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(("localhost", 9111))
    msg = "Circle,100,100,10,couleur\n"
    s.send(str. encode(msg))
    msg = "PolygonG,10,10,10,30,30,30,30,10,#ffffff\n"
    s.send(str. encode(msg))
    msg = "Resize, 100, 100\n"
    s.send(str. encode(msg))
'''    
 
    s.send(str. encode(msg))
    msg = "PolygonG,10,10,10,30,30,30,30,10,#ffffff\n"
    s.send(str. encode(msg))
    msg = "PolygonG,10,10,10,30,30,30,30,10,#ffffff\n"
    s.send(str. encode(msg))
    msg = "PolygonG,10,10,10,30,30,30,30,10,#ffffff\n"
    s.send(str. encode(msg))
    msg = "PolygonG,10,10,10,30,30,30,30,10,#ffffff\n"
    s.send(str. encode(msg))
'''
