import RPi.GPIO as IO
import time, sys
IO.setwarnings(False)
IO.setmode(IO.BCM)
IO.setup(19,IO.IN) #GPIO 2 -> Left IR out
IO.setup(26,IO.IN) #GPIO 3 -> Right IR out
IO.setup(23,IO.OUT) #GPIO 4 -> Motor 1 terminal A
IO.setup(24,IO.OUT) #GPIO 14 -> Motor 1 terminal B
IO.setup(20,IO.OUT) #GPIO 17 -> Motor Left terminal A
IO.setup(21,IO.OUT) #GPIO 18 -> Motor Left terminal B
try:
    while 1:
        print(IO.input(19), IO.input(26))
        if(IO.input(19)==True and IO.input(26)==False): #both while move forward     
            IO.output(23,True) #1A+
            IO.output(24,False) #1B-
            IO.output(20,True) #2A+
            IO.output(21,False) #2B-
            
except Exception as e:
    print(str(e))
finally:
    IO.cleanup()
    sys.exit()
    
       



