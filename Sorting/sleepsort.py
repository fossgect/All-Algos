import threading
from time import sleep


unsorted_array = [1, 7, 3, 2, 5, 9, 4]

def sleep_on_item(i):
    sleep(i);
    print(i)

def main():
    for i in unsorted_array:
        threading.Thread(target = sleep_on_item, args=(i,)).start()

if __name__ == "__main__":
    main()
