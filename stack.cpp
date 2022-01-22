#include<iostream>
#include<assert.h>
using namespace std;
class node{
        public:
                int data;
                node* next;
                node(){
                        next = NULL;
                }
};
class Stack{
        public:
            node *head;
            int size;
            void push(int val);
            int pop();
            int top();
            void printer();
            Stack(){
                    size = 0;
            }
};

void Stack::push(int val){
        node *temp = new node;
        temp->data = val;
        temp->next = head;
        head = temp;
        temp = NULL;
        size++;
        assert(head->data == val);
}

int Stack::pop(){
        size--;
        node*temp = head;
        head = head->next;
        return temp->data;
}

int Stack::top(){
        return head->data;
}

void Stack::printer(){
        node *temp = head;
        while(temp != NULL){
                cerr<<temp->data<<" ";
                temp = temp->next;
        }
        cout<<"\n";
}

int main(){

}
