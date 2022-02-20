import serial

ser = serial.Serial('COM8', 9600, timeout=0)
ser.write("hi".encode())
txt = ser.read_until("\n")
if txt == "OK\n":
    print("Succedded")
print(f"Got text: {txt}")