import serial
import time

def init_serial(arduino_port):
    arduino = serial.Serial(port = arduino_port, baudrate=115200, timeout=0.1)
    return arduino

def send_lines(lines, arduino):
    scale = 3
    parsed_coords = []
    for (start, end) in lines:
        parsed_coords.append((start[0]*scale, start[1]*scale, 1))
        parsed_coords.append((end[0]*scale, end[1]*scale, 0))
    for coord in parsed_coords:
        time.sleep(2)
        send_coordinate(coord[0], coord[1], coord[2], arduino)
        # time.sleep(2)
        result = receive_result(arduino)
        print('Arduino reply:' + result)

def send_coordinate(x, y, z, arduino):
    coordinate = f"{x},{y},{z}\n"
    arduino.write(coordinate.encode())
    print("sent: ", coordinate.encode())

def receive_result(arduino):
    result = ""
    while True:
        byte = arduino.read().decode()
        if byte == '\n':
            break
        result += byte
    return result