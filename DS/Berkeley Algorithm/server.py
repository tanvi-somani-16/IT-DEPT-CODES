import socket
import time

#creating server socket
s=socket.socket()

s.bind(("0.0.0.0",9999));       #can accept connection from any IP
s.listen(5)     #will listen to 1 client 

print("Time Daemon Server Waiting...")

while True:
    conn,addr=s.accept()        #conn->communication channel
    print("Connected to ",addr)

    #Request client for time
    conn.send(b"send time")

    #Recieve client time
    #recv(1024) → receive data ,.decode() → bytes → string, float() → string → number
    client_time=float(conn.recv(1024).decode())

    server_time=time.time()

    #calculate average time
    avg_time=(client_time+server_time)/2
    adjustment=avg_time-client_time

    print("Server Time :",server_time)
    print("Client Time :",client_time)
    print("Adjustment :",adjustment)

    #send synchronized time to clinet
    conn.send(str(adjustment).encode())

    conn.close()







