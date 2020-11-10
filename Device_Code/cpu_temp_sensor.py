# cpu_temp_sensor.py
# Temperature sensor classes for use with a device_server
# Authors: Brent Rubell, Todd Moorehouse for UMass Dartmouth ECE565
# LICENSE: MIT-0

# TODO: Switch to checking the internal CPU temperature sensor
# as a unix syscall!
from random import randint


get_temperature():
    """Mocks a CPU temperature sensor outputting once every second.

    """
    while True:
        temperature_data = randint(0, 100)
        print(temperature_data)
        time.sleep(1)

if __name__ == '__main__':
    print("Started CPU temperature sensor!")
    get_temperature()


