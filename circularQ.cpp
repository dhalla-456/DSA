#include<iostream>
#include<queue>
using namespace std; 
class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //checking if queue is full or not
        if((front  == 0 && rear == size-1) || (rear == (front-1)%(size-1))) //%(size-1) isko hta bhi skte h
        {
            return false;
        }
        else if (front  == -1){ //pushing first element
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0)
        {
            rear = 0; //to maintain cyclic nature
        }
        else{ // normal push
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        //to check if queue is already empty
        if(front  == -1)
        {
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) // tlb ek hi element tha usse bhi delete kr diya
        {
            front = rear = -1; //ab empty h 
        }
        else if(front == size-1){ //to maintain circular nature
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }
};