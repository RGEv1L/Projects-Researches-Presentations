import sys

# Linear Search Q1
# variable initialised = 1
# list initialised = 1
# complexity = 0(n)


def main():
        li = [10,14,19,26,27,31,33,35,42,44]
    
        for x in li:
            if (x == 33):
                print("Number 33 is Present in the list")
                sys.exit()
    
        else:
            print("Number 33 not in the list")

if __name__ == '__main__':main()
