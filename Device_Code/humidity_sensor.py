# humidity_sensor.py
# Humidity sensor classes for use with a device_server
# Authors: Brent Rubell, Todd Moorehouse for UMass Dartmouth ECE565
# LICENSE: MIT-0
from random import randint

get_humidity():
    """Mocks a humidity sensor outputting once every second.

    """
    while True:
        humidity_data = randint(0, 100)
        print(humidity_data)
        time.sleep(1)

if __name__ == '__main__':
    print("Started humidity sensor!")
    get_humidity()


