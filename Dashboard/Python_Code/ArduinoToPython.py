import serial, time  # for Serial communication 
 
# print(serial.version)

arduino = serial.Serial('COM4', 9600, timeout=1)  # Update with your port 

time.sleep(2)  # wait for 2 seconds for the communication to get established 

print("Connected") 
 

while (1): 

    x = '<' + input("Input to arduino: ") + '>'
    arduino.write(x.encode())
    time.sleep(0.1)
    if (arduino.inWaiting() > 0): 
        arduinoOut = arduino.readline().decode('utf-8').strip() 
        print(arduinoOut)

 