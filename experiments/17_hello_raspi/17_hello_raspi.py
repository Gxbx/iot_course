import RPi.GPIO as gpio 
#Esto es para iniciar la board
gpio.setmode(gpio.BOARD)
gpio.setup(12, gpio.OUT)
gpio.output(12, True)
gpio.output(12, False)