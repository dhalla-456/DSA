//Split circular LL in two eual part with separate head and tail

#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;

    }

};

void insert(Node* &head, int d){

    if(head == NULL){
        Node* n1 = new Node(d);
        n1 -> next = n1;
        head = n1;
        return;
    }   

    Node* temp = head;
    Node* n1 = new Node(d);
    while(temp->next != head){
        temp = temp -> next;
    }
    temp -> next = n1;
    n1 -> next = head;


}
void print(Node* &head){
    Node* temp = head;
    Node* curr = head;
    while(temp ->next != curr){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<temp->data<<" ";
    cout<<endl;
}

int getLength(Node* &head){
    Node* temp = head;
    int count = 1;
    while(temp -> next != head){
       count++;
       temp = temp -> next;
    }
    return count;
}
 Node* splitList(Node* &head, int count){

     

    Node* temp = head;
 if(count % 2 == 0){
      int count2 = 1;
      while(count2 < count/2){
         
        temp = temp -> next;
        count2++;

      }
      Node* restPart = temp -> next;
      Node* restPartNode = restPart;
      temp -> next = head;
      
      count2 = 1;
   while(count2 < count/2){
         
        restPart = restPart -> next;
        count2++;

      }
       restPart -> next = restPartNode;
       return restPartNode;
 }
 else{
        int count2 = 0;
      while(count2 < count/2){
         
        temp = temp -> next;
        count2++;

      }
      Node* restPart = temp -> next;
      Node* restPartNode = restPart;
      temp -> next = head;

      count2 = 1 ;
   while(count2 < count/2){
         
        restPart = restPart -> next;
        count2++;

      }
       restPart -> next = restPartNode;
       return restPartNode;

 }
 }

int main(){

Node* head = NULL;

insert(head, 12);
insert(head, 31);
insert(head, 15);
insert(head, 1);
insert(head, 6);
insert(head, 9);
insert(head, 17);
insert(head, 25);

print(head);

int count = getLength(head);
Node* restPart = splitList(head, count);
print(head);
print(restPart);
    
return 0;
}