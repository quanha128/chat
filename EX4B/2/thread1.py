import time
import threading

global counter
counter = 0

def func1():
    global counter
    while True:
        print(f'{counter}:func1')
        if counter >= 9:
            print("func1 Stopped")
            break
        time.sleep(1)
        counter += 1

def func2():
    global counter
    while True:
        print(f'{counter}:func2')
        if counter >= 9:
            print("func2 Stopped")
            break
        time.sleep(1)
        counter += 1

if __name__ == "__main__":
    thread_1 = threading.Thread(target=func1)
    thread_2 = threading.Thread(target=func2)

    thread_1.start()
    thread_2.start()