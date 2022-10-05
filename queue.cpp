#include<iostream>
using namespace std;

#define n 1000
class queue
{
    int *arr;
    int front;
    int back;
    public:
    queue()
    {
         arr =new int[n];
        front =-1;
        back=-1;
    }
    void enqueue(int x)
    {
        if(back==n-1)
        {
            cout<<"queue overflow"<<endl;
            return ;
        }
        if(back==-1)
        {
            back++;
            front++;
            arr[back]=x;
        }
        else
        {
            back++;
            arr[back]=x;
        }
    }
    void dequeue()
    {
        
        if(front>back|| front==-1)
        cout<<"no element to pop"<<endl;
        else if(front<=back)
        {
        front++;
        }

    }
    int peek()
    {
        
         if(front>back || front==-1)
        {
    //    cout<<"no element in queue"<<endl;
        return -1;
        }
        else if(front<=back)
        {
            return arr[front];
        }
    }

    bool empty()
    {
        if(front>back || front==-1)
        return true;
        else 
        return false;
    }

};
int main()
{
      queue q;
      q.enqueue(1);
      q.enqueue(2);
      q.enqueue(3);
      q.enqueue(4);

      cout<<q.peek()<<endl;
      q.dequeue();

      cout<<q.peek()<<endl;
      q.dequeue();

      cout<<q.peek()<<endl;
      q.dequeue();

      cout<<q.peek()<<endl;
      q.dequeue();

      cout<<q.empty()<<endl;

}