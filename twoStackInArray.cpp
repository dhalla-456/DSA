//implementing 2 stacks in a single array
//https://www.codingninjas.com/codestudio/problems/two-stacks_983634?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_CodestudioLovebabbar5thfeb
#include <bits/stdc++.h> 
class TwoStack {
public:
    int top1;
    int top2;
    int *arr;
    int size;
    
    // Initialize TwoStack.
    TwoStack(int size) {
        this -> size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size]; 
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top2 - top1 > 1)     //checing if atleast we have 1 space for num
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top2 - top1 > 1)    //checing if atleast we have 1 space for num
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 >= 0)
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 < size)
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }
};
