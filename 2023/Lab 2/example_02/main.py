import esp32
import time

while True:
    magnet = esp32.hall_sensor()

    if magnet < 0:
        print('Found a magnet!')
        print("it's strength is ", magnet)

    time.sleep(1)
