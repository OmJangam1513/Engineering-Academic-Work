#include<iostream>
#include<string>
using namespace std;

struct student {
    int rollno;
    string name;
    float marks;
    student* next;
};

class studentDatabase {
    private:
        student* head;

    public:
        studentDatabase() {
            head = nullptr;
        }

        void add(int rollno, const string &name, float marks) {
            student *newstudent = new student;
            newstudent->rollno = rollno;
            newstudent->name = name;
            newstudent->marks = marks;
            newstudent->next = nullptr;

            if (head == nullptr) {
                head = newstudent;  
            } else {
                student* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newstudent;
            }
        }

        void display() {
            if (head == nullptr) {
                cout << "Records Not Available" << endl;
                return;
            }

            student* temp = head;
            while (temp != nullptr) {
                cout << "Roll No: " << temp->rollno << ", Name: " << temp->name << ", Marks: " << temp->marks << endl;
                temp = temp->next;
            }
        }
};

int main() {
    studentDatabase db;
    int ch;
    int rollno;
    string name;
    float marks;

    do {
        cout << "\n-----------MENU-----------" << endl;
        cout << "1] Add Student" << endl;
        cout << "2] Display All Students" << endl;
        cout << "3] Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter Roll No: ";
                cin >> rollno;  
                cout << "Enter Name: ";
                cin>> name;  
                cout << "Enter Marks: ";
                cin >> marks;
                db.add(rollno, name, marks);
                break;

            case 2:
                cout << "\n----------Students Records---------" << endl;
                db.display();
                break;

            case 3:
                cout << "Thank You!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (ch != 3);

    return 0;
}
