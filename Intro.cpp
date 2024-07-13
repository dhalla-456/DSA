#include<iostream>
#include<stack>
using namespace std;

//Stack Implementation Using Array
class Stack
{
    //properties
    public:
    int top;
    int *arr;
    int size;

    //behaviour
    Stack(int size)
    {
        this -> size = size;
        arr = new int[size];
        top = -1 ;
    }

    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout<<"Stack OverFlow !! "<<endl;
        }
    }

    void pop()
    {
        if (top >=0)
        {
            top--;
        }
        else
        {
            cout<<"Stack UnderFlow !! " <<endl;
        }
    }

    int peak()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout<<"Stack Is Empty"<<endl;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int main()
{
    /*
    stack <int> s;

    s.push(1);
    s.push(2);

    cout<<"Stack Top : " << s.top()<<endl;
    cout<<"Size of Stack is : "<<s.size()<<endl;

    s.pop();

    cout<<"Stack Top : " << s.top()<<endl;

    if (s.empty())
    {
        cout<<"Empty"<<endl;
    }

    else
    {
        cout<<"Non - Empty"<<endl;
        cout<<"Size of Stack is : "<<s.size()<<endl;
    }

    s.pop();

    if (s.empty())
    {
        cout<<"Empty"<<endl;
        cout<<"Size of Stack is : "<<s.size()<<endl;
    }

    else
    {
        cout<<"Non - Empty"<<endl;
    }
    return 0;
    */

    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(43);
    s.push(44);

    cout << s.peak() << endl;

    s.pop();

    cout << s.peak() << endl;

    s.pop();

    cout <<s.peak() << endl;

    s.pop();

    cout << s.peak() << endl;

    //s.pop();

    if(s.isEmpty()) {
        cout << "Stack is Empty mere dost " << endl;
    }
    else{
        cout << "Stack is not Empty mere dost " << endl;
    }
 
}
