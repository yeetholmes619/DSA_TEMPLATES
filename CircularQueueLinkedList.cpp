#include<iostream>
using namespace std;
class Node{
        public:
                int data;
                Node *next;
                Node(){
                        data = -1;
                        next = NULL;
                }
};
class CircularQueueLinkedList{
        public:
                int size;
                Node *tail;
                void enqueue(int a);
                int dequeue();
                void printer(int a);
                CircularQueueLinkedList(){
                        size = 0;
                        tail = NULL;
                }
};

void CircularQueueLinkedList::enqueue(int a){
        if(size == 0){
                tail = new Node;
                tail->data = a;
                tail->next = tail;
        }
        else{
                Node *temp = new Node;
                temp->data = a;
                temp->next = tail->next;
                tail->next = temp;
                tail = tail->next;
        }
        size++;
}

int CircularQueueLinkedList::dequeue(){
        if(size == 0){
                cout<<"Queue Empty\n";
                return -1e9;
        }
        size--;
        int k = (tail->next)->data;
        if(size == 1){
                tail = NULL;
                return k;
        }
        tail->next = (tail->next)->next;
        return k;
}
void CircularQueueLinkedList::printer(int start = 1){
        if(size == 0) return;
        Node *temp = tail->next;
        for(int j = 0; j < start-1; j++) temp = temp->next;
        for(int i = 0;i < size; i++){
                cout<<temp->data<<" ";
                temp = temp->next;
        }
        cout<<"\n";
}
CircularQueueLinkedList q;
int main(){
}
