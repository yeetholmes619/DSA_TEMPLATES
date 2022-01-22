//Author = Anirudh Srikanth (yeetholmes619) [B20CS006]
#include<iostream>
using namespace std;
class Node{
        public:
            int data;
            Node* right;
            Node* left;
            Node (int data){
                    this->data = data;
                    this->right = NULL;
                    this->left = NULL;
            }
};

class Tree{
        public:
                Node *root;
                void insertBinSearch(int d);
                void inorder(Node* c);
                void FindLeftnRight(Node* curr,int data, Node* &l, Node* &r);
                void remove (Node* curr, int d);
                void del(int d);
                void inserttree(Node* child);
                Tree(){
                        root = NULL;
                }
};
void Tree::inorder(Node* c){
        if(c == NULL) return;
        inorder(c->left);
        cout<<c->data<<" ";
        inorder(c->right);
}
void Tree::FindLeftnRight(Node* rr, int d, Node* &l, Node* &r){
        if(rr == NULL) return;
        FindLeftnRight(rr->left,d,l,r);
        if(rr->data == d){
//                cerr<<"YES\n";
                l = rr->left;
                r = rr->right;
        }
        FindLeftnRight(rr->right,d,l,r);
}

void Tree::remove(Node* curr, int d){
        if(curr == NULL) return;
        remove(curr->left,d);
        if((curr->left) != NULL){
                if((curr->left)->data == d){
                        curr->left = NULL;
                }
        }
        if((curr->right) != NULL){
                if((curr->right)->data == d){
                        curr->right = NULL;
                }
        }
        remove(curr->right,d);
}

void Tree::inserttree(Node* carry){
        if(carry == NULL) return;
        int d = carry->data;
        if(root == NULL){
                root = carry;
                return;
        }
        Node *temp = root;
        while(1){
                if(d > temp->data){
                        if(temp->right == NULL) {
                                temp->right = carry;
                                break;
                        }
                        else temp = temp->right;
                }
                else if(d <= temp->data){
                        if(temp->left == NULL) {
                                temp->left = carry;
                                break;
                        }
                        else temp = temp->left;
                }
        }
}

void Tree::del(int d){
        Node*l = NULL;
        Node*r = NULL;
        FindLeftnRight(root,d,l,r);
//        if(l == NULL){
//                cerr<<-1<<" ";
//        }
//        else cerr<<l->data<<" ";
//        if(r == NULL){
//                cerr<<-1<<"\n";
//        }
//      else cerr<<r->data<<"\n";
        if(d != root->data){
                remove(root,d);
                inserttree(l);
                inserttree(r);
        }
        else{
                root = r;
                inserttree(l);
        }
}
void Tree::insertBinSearch(int d){
        Node* carry = new Node(d);
        if(root == NULL){
                root = carry;
                return;
        }
        Node *temp = root;
        while(1){
                if(d > temp->data){
                        if(temp->right == NULL) {
                                temp->right = carry;
                                break;
                        }
                        else temp = temp->right;
                }
                else if(d <= temp->data){
                        if(temp->left == NULL) {
                                temp->left = carry;
                                break;
                        }
                        else temp = temp->left;
                }
        }
}
int main() {
        int n;
        cin>>n;
        Tree t;
        for(int i = 0; i < n; i++){
                int k;
                cin>>k;
                t.insertBinSearch(k);
        }
}
