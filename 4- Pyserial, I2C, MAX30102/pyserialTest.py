import time
import serial


# configure the serial connections (the parameters differs on the device you are connecting to)
ser = serial.Serial(
    port='COM22',
    baudrate=9600,
    parity=serial.PARITY_NONE
    )



print ('Enter your commands below.\r\nInsert "exit" to leave the application.')

raw_input=1
           
while 1 :
    raw_input = input(">>")
    print (raw_input)

    if raw_input == 'exit':
        ser.close()
        exit()
    else:
        # send the character to the device
        ser.write(raw_input.encode())

        time.sleep(0.5)

        out = ""
        while ser.inWaiting() > 0:
            c = ser.read()
            c = c.decode()
            print (c)
            out = out + (c[0])
            #if c == '\n':
            #    print("finished:")
            #    break
        #print(out.encode())
        if out == "Bye\r\n":
            print("done")


ser.close()