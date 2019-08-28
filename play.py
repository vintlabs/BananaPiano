import serial
import os

ser = serial.Serial(port="/dev/ttyUSB0",baudrate=115200)

while True:
    for line in ser.readline():
        print(chr(line))

        if chr(line) == '0':
            os.system("aplay ./wav-piano-sound/wav/c1.wav")

        if chr(line) == '1':
            os.system("aplay ./wav-piano-sound/wav/d1.wav")

        if chr(line) == '2':
            os.system("aplay ./wav-piano-sound/wav/e1.wav")

        if chr(line) == '3':
            os.system("aplay ./wav-piano-sound/wav/f1.wav")

ser.close()
