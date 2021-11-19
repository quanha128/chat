import time
import sys
import threading
from multiprocessing import Value

x = Value('i')
x.value = 0

def func1():
	while True:
		x.value += 1
		print(f'{x.value} func1')
		if x.value == 10:
			print('func1 スレッドを終わります')
			sys.exit()
		time.sleep(1)


def func2():
	while True:
		x.value += 1
		print(f'{x.value} func2')
		if x.value == 10:
			print('func2 スレッドを終わります')
			sys.exit()
		time.sleep(1)

if __name__ == "__main__":
	thread_1 = threading.Thread(target=func1)
	thread_2 = threading.Thread(target=func2)

	thread_1.start()
	thread_2.start()