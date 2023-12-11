import serial
import time
arduino_port = 'COM10'
arduino = serial.Serial(port = arduino_port, baudrate=115200, timeout=0.1)

zig_zag = [(i*500, 1000*(i%2), 0) for i in range(5)]
print(zig_zag)
    
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.1)
    return_val = arduino.readline()
    return return_val

def send_coordinate(x, y, z):
    coordinate = f"{x},{y},{z}\n"
    arduino.write(coordinate.encode())
    print("sent: ", coordinate.encode())

def receive_result():
    result = ""
    while True:
        byte = arduino.read().decode()
        if byte == '\n':
            break
        result += byte
    return result

def make_zig_zag():
    for line in zig_zag:
        time.sleep(3)
        send_coordinate(line[0], line[1], line[2])
        # print(f"Sent {line[0]}, {line[1]}, {line[2]}")
        time.sleep(3)
        result = receive_result()
        print('Arduino reply:' + result)

def pls():
    send_coordinate(0, 0, 0)


def input_drawing(): 
    while True:
    # inp = input("Enter a command: ")
        x_coord = input("x: ").replace('\r\n', '')
        y_coord = input("y: ").replace('\r\n', '')
        z_coord = input("z: ").replace('\r\n', '')

        send_coordinate(x_coord, y_coord, z_coord)

        time.sleep(3)
        result = receive_result()
        print('Arduino reply:' + result)
    
make_zig_zag()
# input_drawing()
