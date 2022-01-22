#include<iostream>
using namespace std;
class node{
        public:
                int data;
                node* next;
                node(){
                        next = NULL;
                        data = 0;
                }
};

class LinkedList{
        public:
            node *head;
            void push(int value);
            void push_back(int value);
            int size;
            int pop();
            void printer();
            LinkedList(){
                    head = NULL;
                    size = 0;
            }
};

void LinkedList::push_back(int value){
        size++;
        node* temp = new node;
        temp->data = value;
        node* travel = head;
        if(travel == NULL){
                head = temp;
                temp = NULL;
                return;
        }
        while(travel->next != NULL) travel = travel->next;
        travel->next = temp;
        travel = NULL;
        temp = NULL;
}
void LinkedList::push(int value){
        size++;
        node *temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
        temp = NULL;
}
int LinkedList::pop(){
        size--;
        node*temp = head;
        head = head->next;
        return temp->data;
}
void LinkedList::printer(){
        node *temp = head;
        while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
        }
        cout<<"\n";
}

int main(){
        int n;
        cin>>n;
        LinkedList l;
        for(int i = 0; i < n;i++){
                int temp;
                cin>>temp;
                l.push_back(temp);
        }
}
