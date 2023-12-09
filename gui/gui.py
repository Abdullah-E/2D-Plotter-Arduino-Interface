import serial
import time

arduino = serial.Serial(port = 'COM8', baudrate=115200, timeout=0.1)


coords = [(1000,1000), (-1000, -1000), (1000,500), (-1000, -500)]
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.1)
    return_val = arduino.readline()
    return return_val

def send_coordinate(x, y):
    coordinate = f"{x},{y}\n"
    arduino.write(coordinate.encode())

def receive_result():
    result = ""
    while True:
        byte = arduino.read().decode()
        if byte == '\n':
            break
        result += byte
    return result

# for coord in coords:
#     send_coordinate(coord[0], coord[1])
#     print(f"Sent {coord[0]}, {coord[1]}")
#     time.sleep(1)
#     result = receive_result()
    # print('Arduino reply:' + result)
while True:
    # inp = input("Enter a command: ")
    x_coord = input("x: ").replace('\r\n', '')
    y_coord = input("y: ").replace('\r\n', '')
    
    send_coordinate(x_coord, y_coord)
    time.sleep(1)
    result = receive_result()
    print('Arduino reply:' + result)