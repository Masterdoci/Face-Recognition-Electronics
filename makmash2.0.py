import serial

ser = serial.Serial('COM8', 9600, timeout=0)
while 1:
    ser.write("hi".encode())
    while True:
        txt = ser.readline()
        if txt == "OK\n":
            break
        print(f"Got text: {txt}")
    print("Succedded")