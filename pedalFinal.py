import serial
import datetime
import glob
import sys
from sys import stdout
# I2C device definition
PORT = '/dev/tty.usbserial-14240'
BAUDRATE = 115200

def serial_ports():
    """Lists serial ports
    :raises EnvironmentError:
        On unsupported or unknown platforms
    :returns:
        A list of available serial ports
    """
    if sys.platform.startswith('win'):
        ports = ['COM' + str(i + 1) for i in range(256)]

    elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
        # this is to exclude your current terminal "/dev/tty"
        ports = glob.glob('/dev/tty[A-Za-z]*')

    elif sys.platform.startswith('darwin'):
        ports = glob.glob('/dev/tty.*')

    else:
        raise EnvironmentError('Unsupported platform')

    result = []

    for port in ports:
        try:
            s = serial.Serial(port)
            s.close()
            result.append(port)
        except (OSError, serial.SerialException):
            pass
    return result

def ReadSerial(serial):
    recv = serial.readline()
    return recv

# Retrieve constants (ports, time, header)
ports = serial_ports()
ser = serial.Serial(ports[2], 115200)
# print (ser)

# Create header
print ("TIME, LIGHT")
print(ports)

# Create the reading
while True:
    timestamp = datetime.datetime.now()
    reading = ReadSerial(ser)
    print(reading)
    sys.stdout.flush()