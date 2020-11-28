# cpu_util_sensor.py
# CPU utilization sensor for use with a device_server
# Authors: Brent Rubell, Todd Moorehouse for UMass Dartmouth ECE565
# LICENSE: MIT-0
import random

def get_cpu_util():
    """Mock CPU utilization

    """
    cpu_util = random.randint(0,100)
    print("{}% Usage".format(cpu_util))

if __name__ == '__main__':
    while True:
        get_cpu_util()


