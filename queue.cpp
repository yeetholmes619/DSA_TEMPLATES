#include<iostream>
using namespace std;
class node{
        public:
                int data;
                node* next;
                node(){
                        next = NULL;
                }
};

class Queue{
        public:
            node *head;
            node *tail;
            void enqueue(int value);
            int size;
            void dequeue();
            void printer();
            void front();
            void rear();
            Queue(){
                    head = NULL;
                    tail = NULL;
                    size = 0;
            }
};
void Queue::front(){
        cout<<head->data<<"\n";
}
void Queue::rear(){
        cout<<tail->data<<"\n";
}
void Queue::enqueue(int value){
        size++;
        node* temp = new node;
        temp->data = value;
        if(head == NULL){
                head= temp;
                tail = temp;
        }
        else{
                tail->next = temp;
                tail = tail->next;
        }
}
void Queue::dequeue(){
        size--;
        head = head->next;
}
void Queue::printer(){
        node *temp = head;
        while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
        }
        cout<<"\n";
}


int main(){
}
