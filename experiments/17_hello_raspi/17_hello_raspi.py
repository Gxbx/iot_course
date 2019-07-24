import RPi.GPIO as gpio 
import time
#Esto es para iniciar la board
gpio.setmode(gpio.BCM)
gpio.setup(23, gpio.IN, pull_up_down = gpio.PUD_UP)
gpio.setup(24, gpio.OUT)

while True:
    input_state = gpio.input(23)
    if input_state == False:
        gpio.output(24, True)
    else:
        gpio.output(24, False)
time.sleep(0.3)
gpio.cleanup(23)
gpio.cleanup(24)