class Searching():
    def __init__(self):
        self.count = 0
        self.arr = []
        self.check = 0
        self.low = 0
        self.high = 0
        self.mid = 0

    def Input(self):
        while True:
            print("Enter the Roll_No of the Students (Enter -1 To stop entering):")
            Roll_No = int(input())
            if Roll_No == -1:
                break
            self.arr.append(Roll_No)
            self.count += 1

    def Linear_Search(self):
        found = False
        print("Enter the Roll_No which is to be searched:")
        self.check = int(input())
        for i in range(self.count):
            if self.arr[i] == self.check:
                found = True
                break
        if found:
            print(f"Roll Number {self.check} is present")
        else:
            print(f"Roll Number {self.check} is not present")

    def Sentinel_Search(self):
        print("Enter the Roll_No which is to be searched:")
        self.check = int(input())
        
        # Place the sentinel
        self.arr.append(self.check)
        i = 0
        while self.arr[i] != self.check:
            i += 1
        
        # Check if the search found the element within the original array bounds
        if i < self.count:
            print(f"Roll Number {self.check} is present")
        else:
            print(f"Roll Number {self.check} is not present")

    def Binary_Search(self):
        print("Enter the Roll_No which is to be searched:")
        self.check = int(input())

        self.low = 0
        self.high = self.count - 1

        while self.low <= self.high:
            self.mid = (self.low + self.high) // 2

            if self.arr[self.mid] == self.check:
                print(f"Roll Number {self.check} is present")
                return True

            if self.arr[self.mid] < self.check:
                self.low = self.mid + 1
            else:
                self.high = self.mid - 1

        print(f"Roll Number {self.check} is not present")
        return False

    def Fibonacci_Search(self):
        print("Enter the Roll_No which is to be searched:")
        self.check = int(input())

        # Initialize the first two Fibonacci numbers
        fib_m2 = 0  # F(m-2)
        fib_m1 = 1  # F(m-1)
        fib_m = fib_m1 + fib_m2  # F(m)

        # Find the smallest Fibonacci number greater than or equal to the count
        while fib_m < self.count:
            fib_m2 = fib_m1
            fib_m1 = fib_m
            fib_m = fib_m1 + fib_m2

        # Marks the eliminated range from front
        offset = -1

        # Start searching
        while fib_m > 1:
            i = min(offset + fib_m2, self.count - 1)

            if self.arr[i] < self.check:
                fib_m = fib_m1
                fib_m1 = fib_m2
                fib_m2 = fib_m - fib_m1
                offset = i
            elif self.arr[i] > self.check:
                fib_m = fib_m2
                fib_m1 = fib_m1 - fib_m2
                fib_m2 = fib_m - fib_m1
            else:
                print(f"Roll Number {self.check} is present")
                return True

        # Check the last element
        if fib_m1 and self.arr[offset + 1] == self.check:
            print(f"Roll Number {self.check} is present")
            return True

        print(f"Roll Number {self.check} is not present")
        return False


def Select(obj, choice):
    if choice == 1:
        obj.Linear_Search()
    elif choice == 2:    
        obj.Sentinel_Search()
    elif choice == 3:
        obj.Binary_Search()
    elif choice == 4:
        obj.Fibonacci_Search()
    else:
        print("Invalid Input! Try entering again.")
    
    return True


def main():
    obj = Searching()
    obj.Input()

    while True:
        print("_______MENU_______")
        print("1. Linear Search")
        print("2. Sentinel Search")
        print("3. Binary Search")
        print("4. Fibonacci Search")

        choice = int(input("Enter your choice: "))
        Select(obj, choice)



