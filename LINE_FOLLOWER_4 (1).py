import RPi.GPIO as IO
import time, sys
TRIGGER = 17
ECHO = 27
maxtime = 0.04
EN1=19
EN2=26
M11=23
M12=24
M21=20
M22=21

IO.setwarnings(False)
IO.setmode(IO.BCM)
IO.setup(EN1,IO.IN) #GPIO 2 -> Left IR out
IO.setup(EN2,IO.IN) #GPIO 3 -> Right IR out
IO.setup(M11,IO.OUT) #GPIO 4 -> Motor 1 terminal A
IO.setup(M12,IO.OUT) #GPIO 14 -> Motor 1 terminal B
IO.setup(M21,IO.OUT) #GPIO 17 -> Motor Left terminal A
IO.setup(M22,IO.OUT) #GPIO 18 -> Motor Left terminal B
IO.setup(TRIGGER,IO.OUT) #Trigger
IO.setup(ECHO,IO.IN)  #Echo
 
def distance():
    # set Trigger to HIGH
    IO.output(TRIGGER, True)
 
    # set Trigger after 0.01ms to LOW
    time.sleep(0.00001)
    IO.output(TRIGGER, False)
 
    StartTime = time.time()
    StopTime = time.time()
 
    # save StartTime
    StartTime = time.time()
    timeout = StartTime + maxtime
    while IO.input(ECHO) == 0 and StartTime < timeout:
        StartTime = time.time()
 
    # save time of arrival
    StopTime = time.time()
    timeout = StopTime + maxtime
    while IO.input(ECHO) == 1 and StopTime < timeout:
        StopTime = time.time()
 
    # time difference between start and arrival
    TimeElapsed = StopTime - StartTime
    # multiply with the sonic speed (34300 cm/s)
    # and divide by 2, because there and back
    distance = (TimeElapsed * 34300) / 2
 
    return distance


try:
    count = 0
    while 1:
        count += 1
        print(count)
        x= distance()
        
        print("distance=", x)
        print(IO.input(EN1), IO.input(EN2))
        if(x>10):
            if(IO.input(EN1)==True and IO.input(EN2)==True): #both while move forward     
                IO.output(M11,True) #1A+
                IO.output(M12,False) #1B-
                IO.output(M21,True) #2A+
                IO.output(M22,False) #2B-
            elif(IO.input(EN1)==False and IO.input(EN2)==True): #turn right  
                IO.output(M11,True) #1A+
                IO.output(M12,True) #1B-
                IO.output(20,True) #2A+
                IO.output(21,False) #2B-
            elif(IO.input(19)==True and IO.input(26)==False): #turn left
                IO.output(23,True) #1A+
                IO.output(24,False) #1B-
                IO.output(20,True) #2A+
                IO.output(21,True) #2B-
            elif(IO.input(19)==False and IO.input(26)==False):
                IO.output(23,True) #1A+
                IO.output(24,True) #1B-
                IO.output(20,True) #2A+
                IO.output(21,True) #2B-
            
        else:
            IO.output(23,True) #1A+
            IO.output(24,True) #1B-
            IO.output(20,True) #2A+
            IO.output(21,True) #2B-
            continue
        
        
except Exception as e:
    print(str(e))
finally:
    IO.cleanup()
    sys.exit()
    
    
    
       



