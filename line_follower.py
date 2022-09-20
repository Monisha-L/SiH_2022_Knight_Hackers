import RPi.GPIO as GPIO
from RPi.GPIO import OUT as OUTPUT
from RPi.GPIO import IN as INPUT
from time import sleep

M11 = 23
M12 = 24
M21 = 20
M22 = 21
EN1 = 5
EN2 = 6
IR1 = 19
IR2 = 26
ECHO = 17
TRIG = 27

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(M11,OUTPUT)
GPIO.setup(M12,OUTPUT)
GPIO.setup(M21,OUTPUT)
GPIO.setup(M22,OUTPUT)
GPIO.setup(EN1,OUTPUT)
GPIO.setup(EN2,OUTPUT)
GPIO.setup(IR1,INPUT)
GPIO.setup(IR2,INPUT)
GPIO.setup(ECHO,INPUT)
GPIO.setup(TRIG,INPUT)


while True:
    print(GPIO.input(IR1))
    print("IR2",GPIO.input(IR2))
    if ( IR1 == True and IR2 == True):
        GPIO.output(M11,True)
        GPIO.output(M12,False)
        GPIO.output(M21,True)
        GPIO.output(M22,False)
        
    elif(IR1 == False and IR2 == True):
        GPIO.output(M11,True)
        GPIO.output(M12,True)
        GPIO.output(M21,True)
        GPIO.output(M22,False)
        
    elif(IR1 == True and IR2 == False):
        GPIO.output(M11,True)
        GPIO.output(M12,False)
        GPIO.output(M21,True)
        GPIO.output(M22,True)
        
    elif(IR1 == False and IR2 == False):
        GPIO.output(M11,True)
        GPIO.output(M12,True)
        GPIO.output(M21,True)
        GPIO.output(M22,True)
        
        
        
        
        
        
        