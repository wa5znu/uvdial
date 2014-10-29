#!/usr/local/bin/python

import serial
import time
import psutil

port = serial.Serial("/dev/tty.usbserial-DA00UGKT", 57600)
time.sleep (0.5)

while True:
    port.write(str(int(round(psutil.cpu_percent()))))
    port.write('\n')
    time.sleep (0.7)

