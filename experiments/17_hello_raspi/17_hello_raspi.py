import RPi.GPIO as gpio 
import time
#Esto es para iniciar la board
gpio.setmode(gpio.BOARD)
gpio.setup(24, gpio.OUT)
gpio.setup(23, gpio.IN)
# gpio.output(24, True)
# time.sleep(20)
# gpio.output(24, False)
# gpio.cleanup(24)
while True:
    input_state = GPIO.input(23)
    if input_state == False:
        gpio.output(24, True)
    else:
        gpio.output(24, False)