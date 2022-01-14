import time
import sys
import threading
from multiprocessing import Value

x = Value('i')
x.value = 0
lock = threading.Lock()

def func1():
  while True:
    lock.acquire()
    if x.value == 10:
      print('func1 thread complete')
      lock.release()
      sys.exit()
    x.value += 1
    print(f'{x.value} func1')
    lock.release()
    time.sleep(1)

def func2():
  while True:
    lock.acquire()
    if x.value == 10:
      print('func2 thread complete')
      lock.release()
      sys.exit()
    x.value += 1
    print(f'{x.value} func2')
    lock.release()
    time.sleep(1)

if __name__ == "__main__":
  thread_1 = threading.Thread(target=func1)
  thread_2 = threading.Thread(target=func2)

  thread_1.start()
  thread_2.start()