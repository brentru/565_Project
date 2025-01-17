# humidity_sensor.py
# Humidity sensor classes for use with a device_server
# Authors: Brent Rubell, Todd Moorehouse for UMass Dartmouth ECE565
# LICENSE: MIT-0
import random

def get_humidity():
    """Mocks a humidity sensor outputting once every second.

    """
    humidity_data = round(random.uniform(10,80),2)
    print("%fRH"%humidity_data)

if __name__ == '__main__':
    while True:
        get_humidity()


