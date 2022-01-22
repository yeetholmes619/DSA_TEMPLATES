#include<iomanip>
#include<math.h>
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
int mp[100] = {0};
double ans = 0;
template<class T>
void swp(T &a, T &b) {
    T c;
    c = a ;
    a = b;
    b = c;
}

class Node {
public:
    int data;
    int height;
    Node* left;
    Node* right;
    char c;
    Node(int d = 0) {
        left = NULL;
        right = NULL;
        data = d;
        c = '.';
        height = 0;
    }
};
class node {
public:
    Node* data;
    node* next;
    node() {
        next = NULL;
        data = NULL;
    }
};
class Queue {
public:
    node *head;
    node *tail;
    void enqueue(Node* value);
    int size;
    void dequeue();
    void printer();
    Node* front();
    Node* rear();
    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
};
Node* Queue::front() {
    return head->data;
}
Node* Queue::rear() {
    return tail->data;
}
void Queue::enqueue(Node* value) {
    size++;
    node* temp = new node;
    temp->data = value;
    if (head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = tail->next;
    }
}
void Queue::dequeue() {
    size--;
    head = head->next;
}
void Queue::printer() {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

class BinTree {
public:
    Node* root;
    void insert(int num);
    void inorder(Node* t , int level = 0);
    void postorder(Node* t );

    BinTree() {
        root = NULL;
    }
};
void BinTree::postorder(Node* t){
        if(t == NULL) return;
        postorder(t->left);
        postorder(t->right);
        cout<<(t->c)<<" "<<(t->data)<<"\n";
}
void BinTree::insert(int num) {
    if (root == NULL) {
        root = new Node;
        root->data = num;
        return;
    }
    Queue q;
    q.enqueue(root);
    while (q.size != 0) {
        Node* t = q.front();
        q.dequeue();
        if (t->left != NULL) {
            q.enqueue(t->left);
        }
        else {
            t->left = new Node;
            (t->left)->data = num;
            (t->left)->height = (t->height) + 1;
            return;
        }
        if (t->right != NULL) {
            q.enqueue(t->right);
        }
        else {
            t->right = new Node;
            (t->right)->data = num;
            (t->right)->height = (t->height) + 1;
            return;
        }
    }
}

void BinTree::inorder(Node* t , int level) {
    if (t == NULL) return;
    inorder(t->left, level + 1);
    //cout<<t->data<<" ";
        cout<<(t->c)<<" "<<(t->data)<<"\n";
    if (t->left == NULL and t->right == NULL) {
//        cerr<<t->c<<" "<<level<<"\n";
        ans += level*mp[(int)((t->c) - 'a')];
    }
    inorder(t->right, level + 1);
}


class MaxHeap {
public:
    int size = 0;
    Node* arr[10000] ;
    void insert(Node* b);
    void printer();
    void heapify();
    void printfull(int n);
    Node* del();
    MaxHeap() {
        size = 0;
    }
};
void MaxHeap::heapify() {
    int n = size;
    for (int i = n / 2 - 1; i > -1; i--) {
        int j = 2 * i + 1;
        while (j < n) {
            if (j < n - 1)
                if ((arr[j + 1]->data) > (arr[j]->data)) j++;
            if ((arr[i]->data) < (arr[j]->data)) {
                swp(arr[i], arr[j]);
                i = j;
                j = 2 * i + 1;
            }
            else break;
        }
    }
}

void MaxHeap::insert(Node* b) {
    Node* hold = b;


    int k = size;
    while ((k != 0) and ((arr[(k - 1) / 2]->data) < (hold->data))) {
        arr[k] = arr[(k - 1) / 2];
        k = (k - 1) / 2;
    }
    arr[k] = hold;
    size++;
}
Node* MaxHeap::del() {
    Node* ret = arr[0];
    swp(arr[size - 1], arr[0]);
    // arr[size-1] ^= arr[0];
    // arr[0] ^= arr[size-1];
    // arr[size-1] ^= arr[0];
    int i = 0;
    while (2 * i + 1  < size - 1) {
        if (2 * i + 1 == size - 2) {
            if ((arr[i]->data) < (arr[2 * i + 1]->data)) {
                swp(arr[i], arr[2 * i + 1]);
                // arr[i] ^= arr[2*i + 1];
                // arr[2*i + 1] ^= arr[i];
                // arr[i] ^= arr[2*i +1];
                i = 2 * i + 1;
            }
            else break;
        }


        else if (arr[2 * i + 1]->data >= arr[2 * i + 2]->data) {
            if ((arr[i]->data) < (arr[2 * i + 1]->data)) {
                // arr[i] ^= arr[2*i + 1];
                // arr[2*i + 1] ^= arr[i];
                // arr[i] ^= arr[2*i +1];
                swp(arr[i], arr[2 * i + 1]);
                i = 2 * i + 1;
            }
            else break;
        }
        else {
            if ((arr[i]->data) < (arr[2 * i + 2]->data)) {
                swp(arr[i], arr[2 * i + 2]);
                // arr[i] ^= arr[2*i + 2];
                // arr[2*i + 2] ^= arr[i];
                // arr[i] ^= arr[2*i + 2];
                i = 2 * i + 2;
            }
            else break;
        }
    }
    size--;
    return ret;
}

void MaxHeap::printer() {
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\n";
}

void MaxHeap::printfull(int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}
string s;
int vn = 0;
int main() {
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        mp[(int)(s[i] - 'a')]++;
    }
    MaxHeap m;
    BinTree bt;
    for (int i = 0; i < 28; i++) {
        if (mp[i] != 0) {
            Node* temp = new Node(-1 * mp[i]);
            temp->c = (char)(i+'a');
            m.insert(temp);
            vn++;
        }
    }
//
    while (m.size >= 2) {
        Node* a = m.del();
        Node* b = m.del();
        Node* c = new Node(a->data + b->data);
        c->left = a;
        c->right = b;
        m.insert(c);
    }
    bt.root = m.del();
    bt.inorder(bt.root);
    bt.postorder(bt.root);
    cerr<<ans<<"\n";
    //cout << ans / vn;
    ans /= vn;
    ans *= 10000;
//    cerr<<ans<<"\n";
    int a = (int)ans;
    //cout<<fixed<<-1*(1.0*llround(-1*ans))/10000;
    cout<<fixed<<setprecision(4)<<(1.0*a)/10000;
    

    //   int n;
    //   cin>>n;
    //   MaxHeap m;
    //   for(int i = 0; i < n; i++){
    //           int k;
    //           cin>>k;
    //           m.insert(k);
    //           m.printer();
    //   }
    //   for(int i =0 ; i < n-1; i++){
    //           m.del();
    //           m.printfull(n);
    // }
}
