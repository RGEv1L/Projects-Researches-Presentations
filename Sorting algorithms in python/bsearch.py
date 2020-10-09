import sys
import time

# Binary Search Q2
# variable initialised = 3
# list initialised = 1
# Complexity = 0(logn)


def main():
    li = [10,14,19,26,27,31,33,35,42,44]
    value = 33
    start = 0
    end = len(li) - 1
    

    while True:
        
        mid = (start + end) // 2        
        print(mid)
        time.sleep(1)
        if (li[mid] == value):
           print("Found @ index",mid)
           sys.exit()

        elif (li[mid] > value ):
            end = mid -1

        else:
            start = mid + 1


if __name__ == '__main__':main()
