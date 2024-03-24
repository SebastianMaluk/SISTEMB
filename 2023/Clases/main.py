import machine
import time
import _thread


internal_led = machine.Pin(2, machine.Pin.OUT)
lock = _thread.allocate_lock()

def second_thread():
    while True:
        lock.acquire()

        print("Hello, I'm here in the second thread writing every second")
        time.sleep(1)

        lock.release()

_thread.start_new_thread(second_thread, ())
while True:
    lock.acquire()
    internal_led.value(1)
    time.sleep(1)
    internal_led.value(0)
    time.sleep(1)
    lock.release()