import serial

# open a connection to the Arduino on COM11
ser = serial.Serial('COM11', 9600)

# send a string to the Arduino
ser.write(b'hello')

# read the response from the Arduino
response = ser.read_until()

# print the response
print(response.decode())
