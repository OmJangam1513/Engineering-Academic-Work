class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class HashTable:
    def __init__(self, size):
        self.size = size
        self.table = [None for i in range(size)]

    def insert(self, key, value):
        index = key % self.size
        new_node = Node(key, value)
        new_node.next = self.table[index]
        self.table[index] = new_node
        print(f"Inserted key={key}, value={value} at index={index}")

    def search(self, key):
        index = key % self.size
        current = self.table[index]
        while current:
            if current.key == key:
                print(f"Found key={key} with value={current.value} at index={index}")
                return current.value
            current = current.next
        print(f"Key={key} not found")
        return None

    def delete(self, key):
        index = key % self.size
        current = self.table[index]
        prev = None
        while current:
            if current.key == key:
                if prev:
                    prev.next = current.next
                else:
                    self.table[index] = current.next
                print(f"Key={key} deleted from index={index}")
                return
            prev = current
            current = current.next
        print(f"Key={key} not found at index={index}")

    def display(self):
        print("Hash Table:")
        for i in range(self.size):
            current = self.table[i]
            print(f"Index {i}:", end=" ")
            if current is None:
                print("Empty")
            else:
                while current:
                    print(f"({current.key}, {current.value})", end="")
                    if current.next:
                        print(" -> ", end="")
                    current = current.next
                print()  # for newline after the last node

def main():
    size = int(input("Enter the size of the hash table: "))
    hash_table = HashTable(size)

    while True:
        print("\nHash Table Operations:")
        print("1. Insert key-value pair")
        print("2. Search for a key")
        print("3. Delete a key")
        print("4. Display hash table")
        print("5. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            key = int(input("Enter the key: "))
            value = input("Enter the value: ")
            hash_table.insert(key, value)
        elif choice == 2:
            key = int(input("Enter the key to search: "))
            hash_table.search(key)
        elif choice == 3:
            key = int(input("Enter the key to delete: "))
            hash_table.delete(key)
        elif choice == 4:
            hash_table.display()
        elif choice == 5:
            print("Exiting program...")
            break
        else:
            print("Invalid choice! Please try again.")

main()