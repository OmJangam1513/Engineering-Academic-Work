/*Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not use
priorities, then the jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and delete job from queue.*/

#include<iostream>
using namespace std;
class Queue
{
    public:
    const static int size=10;
    int rear=-1;
    int front=-1;
    int queue[size];
    void enqueue(int x)
    {
        if(rear==size-1)
        {
            cout<<"Overflow!!!";
        }
        else if(front==-1 and rear==-1)
        {
            front=rear=0;
            queue[rear]=x;
        }
        else
        { 
            rear++;
            queue[rear]=x;
        }
    }
    void dequeue()
    {
        
        if(front==-1 and rear==-1)
        {
            cout<<"Underflow!!![Queue is Empty]"<<endl;
            
        }
             
       else if(front == rear)
        {
            front = rear = -1;
        }
       else
        {
            cout<<queue[front]<<endl;
            front = (front+1)%size;
            
        }
        
    
    }
    void display()
    {   
        if (front==-1 and rear==-1)
        {
            cout<<"Queue is Empty!"<<endl;
        }
        else
       { cout<<"Queue Contains:";
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<" ";
        }
        cout<<endl;
       }
    }
    
};

int main()
{
Queue job_line;
int choice,val;

do{
cout<<"Enter the option No. to perform the operations:"<<endl;
cout<<"Note:(Job no. should be in integer type)"<<endl;
cout<<"1.To Add Job"<<endl;
cout<<"2.To Delete Job "<<endl;
cout<<"3.To display Queue"<<endl;
cout<<"4. exit"<<endl;
cin>>choice;
  
  switch(choice)
  {
   case 1:
   cout<<"Enter Job:"<<endl;
   cin>>val;
   job_line.enqueue(val);
   break;
   case 2:
   cout<<"The Deleted Job No.:";
   job_line.dequeue();
   //job_line.display();
   
   break;
   case 3:
   //cout<<"The Queue is:"<<endl;
   job_line.display();
   break;
   case 4:
   break;
   default:
   cout<<"Enter valid option:";
   break;
  }
}
  while(choice!=4);


return 0;
}

























