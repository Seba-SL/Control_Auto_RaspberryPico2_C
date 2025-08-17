from machine import Pin
from utime import sleep

pin = Pin("LED", Pin.OUT)

print("LED starts flashing...")
while True:
    try:
        print("Probando...")
        pin.toggle()
        sleep(5) # sleep 1sec
    except KeyboardInterrupt:
        break
pin.off()
print("Finished.")



