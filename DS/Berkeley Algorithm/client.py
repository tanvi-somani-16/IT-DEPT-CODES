import socket
import time

s=socket.socket()

s.connect(("localhost",9999))

msg=s.recv(1024)

if msg.decode()=="send time":
    current_time=time.time()

    s.send(str(current_time).encode())

    adjustment=float(s.recv(1024).decode())

    new_time=current_time+adjustment
    
    print("Old Time:", current_time)
    print("Adjustment:", adjustment)
    print("Synchronized Time:", new_time)

s.close()

