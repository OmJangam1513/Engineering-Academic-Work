#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to create a linked list of student roll numbers
    void createNode(int n) {
        int roll;
        Node* p;
        Node* t;
        
        for (int i = 0; i < n; i++) {
            cout << "\nEnter the roll number of student " << i + 1 << ": ";
            cin >> roll;
            p = new Node(roll);
            p->next = nullptr;

            if (head == nullptr) {
                head = p;
            } else {
                t = head;
                while (t->next != nullptr) {
                    t = t->next;
                }
                t->next = p;
            }
        }
    }

    // Function to print the list of student roll numbers
    void print() {
        Node* p = head;
        int cnt = 0;
        while (p != nullptr) {
            cout << "\t" << p->data;
            p = p->next;
            cnt++;
        }
        cout << "\nTotal number of students = " << cnt << endl;
    }

    // Function to return the total count of students in the linked list
    int count() {
        Node* p = head;
        int cnt = 0;
        while (p != nullptr) {
            p = p->next;
            cnt++;
        }
        return cnt;
    }

    // Function to find the union of two linked lists
    int uni(LinkedList& otherList) {
        unordered_set<int> studentSet;
        Node* p = head;
        int count = 0;

        // Add all students from the first list to the set
        while (p != nullptr) {
            studentSet.insert(p->data);
            p = p->next;
            count++;
        }

        // Add students from the second list if they are not already in the set
        Node* q = otherList.head;
        while (q != nullptr) {
            if (studentSet.find(q->data) == studentSet.end()) {
                studentSet.insert(q->data);
                count++;
            }
            q = q->next;
        }

        // Print all unique students in the union
        for (const int& roll : studentSet) {
            cout << "\t" << roll;
        }
        cout << endl;
        return count;
    }

    // Function to find the intersection of two linked lists
    void inter(LinkedList& otherList) {
        unordered_set<int> studentSet;
        Node* p = head;

        // Add all students from the first list to the set
        while (p != nullptr) {
            studentSet.insert(p->data);
            p = p->next;
        }

        // Print students from the second list that are also in the first list
        Node* q = otherList.head;
        cout << "\nStudents who like both vanilla and butterscotch:\n";
        while (q != nullptr) {
            if (studentSet.find(q->data) != studentSet.end()) {
                cout << "\t" << q->data;
            }
            q = q->next;
        }
        cout << endl;
    }

    // Getter for the head node
    Node* getHead() {
        return head;
    }
};

int main() {
    LinkedList vanillaList, butterscotchList;
    int m, choice = 0, count;

    cout << "\nEnter the total number of second-year computer students: ";
    cin >> m;

    while (choice != 6) {
        cout << "\n============= Sets Using Linked List ==============\n";
        cout << "1. Create\n2. Print\n3. Like both vanilla and butterscotch\n";
        cout << "4. Like either vanilla or butterscotch\n5. Like neither vanilla nor butterscotch\n";
        cout << "6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n!!! Total Students who like vanilla !!!\n";
                vanillaList.createNode(m);
                cout << "\n!!! Total Students who like butterscotch !!!\n";
                butterscotchList.createNode(m);
                break;
            case 2:
                cout << "\n!!! Students who like vanilla !!!\n";
                vanillaList.print();
                cout << "\n!!! Students who like butterscotch !!!\n";
                butterscotchList.print();
                break;
            case 3:
                cout << "\n!!! Students who like both vanilla & butterscotch !!!\n";
                vanillaList.inter(butterscotchList);
                break;
            case 4:
                cout << "\n!!! Students who like vanilla or butterscotch !!!\n";
                count = vanillaList.uni(butterscotchList);
                break;
            case 5:
                cout << "\nNumber of students who like neither vanilla nor butterscotch = " << m - count << endl;
                break;
        }
    }

    return 0;
}
