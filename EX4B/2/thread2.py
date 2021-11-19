import threading

lock = threading.Lock()

while True:
    balance = 0

    def change_it(n):
        lock.acquire()
        global balance
        balance += n
        balance += n
        balance += n
        balance -= n
        balance -= n
        balance -= n
        lock.release()

    def run_thread(n):
        for i in range(100000):
            change_it(n)

    t1 = threading.Thread(target=run_thread, args=(5,))
    t2 = threading.Thread(target=run_thread, args=(8,))
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print(balance)