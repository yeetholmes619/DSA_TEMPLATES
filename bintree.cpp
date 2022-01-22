#include<iostream>
using namespace std;
class Node{
        public:
        int data;
        Node* left;
        Node* right;
        Node(){
                left = NULL;
                right = NULL;
                data = 0;
        }
};
class node{
        public:
                Node* data;
                node* next;
                node(){
                        next = NULL;
                        data = NULL;
                }
};
class Queue{
        public:
            node *head;
            node *tail;
            void enqueue(Node* value);
            int size;
            void dequeue();
            void printer();
            Node* front();
            Node* rear();
            Queue(){
                    head = NULL;
                    tail = NULL;
                    size = 0;
            }
};
Node* Queue::front(){
        return head->data;
}
Node* Queue::rear(){
        return tail->data;
}
void Queue::enqueue(Node* value){
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

class BinTree{
        public:
            Node* root;
            void insert(int num);
            void inorder(Node* t);

            BinTree(){
                    root = NULL;
            }
};

void BinTree::insert(int num){
        if(root == NULL){
                root = new Node;
                root->data = num;
                return;
        }
        Queue q;
        q.enqueue(root);
        while(q.size != 0){
                Node* t = q.front();
                q.dequeue();
                if(t->left != NULL){
                        q.enqueue(t->left);
                }
                else{
                        t->left = new Node;
                        (t->left)->data = num;
                        return;
                }
                if(t->right != NULL){
                        q.enqueue(t->right);
                }
                else{
                        t->right = new Node;
                        (t->right)->data = num;
                        return;
                }
        }
}

void BinTree::inorder(Node* t){
        if(t == NULL) return;
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
}
int main(){
        BinTree t;
        int n;
        cin>>n;
        while(n--){
                int k;
                cin>>k;
                t.insert(k);
        }
        t.inorder(t.root);
}
