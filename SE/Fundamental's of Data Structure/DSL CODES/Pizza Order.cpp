/*Pizza parlor accepting maximum M orders. Orders are served in first come first served basis. 
Order once placed cannot be cancelled.
Write C++ program to simulate the system using circular queue using*/

#include<iostream>
using namespace std;
class Queue{
    public:
const static int size=5;    
int rear=-1;
int front=-1;
int queue[size];
void Place_order(int x)
{
    if(front==-1 and rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if(((rear+1)%size)==front)
    {
        cout<<"Ooo So Sorry, You Can't order as the orders are reached to the maximum."<<endl;
    }
    else
    {
        rear=(rear+1)%size;
        queue[rear]=x;
    }
}
void delivered_order()
{
    if(front==-1 and rear==-1)
    {
        cout<<"All the Pizzas are Delivered!!!"<<endl;
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        cout<<"Delivered Pizza:"<<queue[front];
        front=(front+1)%size;
    }
}
void display()
{
    int i=front;
    if(front==-1 and rear==-1)
    {
        cout<<"All the Pizzas are Delivered!!!"<<endl;
    }
    else
    {
        
        while(i!=rear)
        {
            cout<<"The ordered Pizza's are:"<<queue[i]<<endl;
            i=(i+1)%size;
        }
        cout<<"The ordered Pizza's are:"<<queue[rear];
    }
}
};
int main()
{
    Queue q;
    int val,choice;
     do{
        cout << "\n\nWelcome To Pizza Parlor. Enter option number for Order. Enter 0 to exit" << endl;
        cout << "1.Place an Order" << endl;
        cout << "2.Display Order" << endl;
        cout << "3.Deliver Order" << endl;
        
        cin >> choice;
    switch(choice)
    {
        case 0:
        break;
        case 1:
        int val;
        cout<<"Pizza types:1.Margherita  2.Paneer  3.Cheese  4.Italian"<<endl;
        cout<<"Pizza order for:"<<endl;
        cin>>val;
        if(val>4)
        {
            cout<<"Sorry this can't be ordered!!"<<endl;
        }
         else
        {
        cout<<"Your ordered pizza "<<val<<" Placed!!"<<endl;
        q.Place_order(val);
        }
        break;
        case 2:
        q.display();
        break;
        case 3:
         q.delivered_order();
        
        break;
        default:
        cout<<"Plz enter valid no!!"<<endl;
    }
     }while(choice!=0);
        
        
    return 0;
}


