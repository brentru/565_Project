# cpu_temp_sensor.py
# Temperature sensor classes for use with a device_server
# Authors: Brent Rubell, Todd Moorehouse for UMass Dartmouth ECE565
# LICENSE: MIT-0

# TODO: Switch to checking the internal CPU temperature sensor
# as a unix syscall!
from random import randint


def get_temperature():
    """Mocks a temperature sensor outputting once every second.

    """
    temperature_data = randint(0, 99)
    print("%dF"%temperature_data)

if __name__ == '__main__':
    while True:
        get_temperature()


