#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
//************************************************
        //Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        };
//**************************************************

bool isCircular(Node* head){
    if(head == NULL)
    {
        return true;
    }
    else
    {
    Node* temp = head;
    while (temp != NULL && temp != head) {
      temp = temp->next;
    }

    if (temp == head) {
      return true;
    }
    }
    return false;
    
}
