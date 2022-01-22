#include<iostream>
using namespace std;
class node{
        public:
                int data;
                node* left;
                node* right;
                node(){
                        left = NULL;
                        right = NULL;
                        data = 0;
                }
                node(int d){
                        left = NULL;
                        right = NULL;
                        data = d;
                }
};
class avl{
        public:
            int height(node* n);
            int difference(node* n);
            node* rr_rotate(node* n);
            node* ll_rotate(node *n);
            node* lr_rotate(node* n);
            node* rl_rotate(node *n);
            node* balance(node *n);
            node* insert(node* n,int d);
            void inorder(node* n);
            void preorder(node* n);
            void postorder(node* n);
            void avlsort(node* n,int *arr, int &index);
};

int avl::height(node* n){
        if(n == NULL){
                return 0;
        }
        else{
                return max(height(n->left),height(n->right)) + 1;
        }
}
int avl::difference(node*n){
        return height(n->left) - height(n->right);
}

node* avl::rr_rotate(node* mom){
        node* adopted;
        adopted = mom->right;
        mom->right = adopted->left;
        adopted->left = mom;
        return adopted;
}
node* avl::ll_rotate(node *mom) {
   node *adopted;
   adopted = mom->left;
   mom->left = adopted->right;
   adopted->right = mom;
   return adopted;
}
node* avl::lr_rotate(node *mom) {
   node *adopted;
   adopted = mom->left;
   mom->left = rr_rotate(adopted);
   return ll_rotate(mom);
}
node* avl::rl_rotate(node *mom) {
   node *adopted;
   adopted = mom->right;
   mom->right = ll_rotate(adopted);
   return rr_rotate(mom);
}
node* avl::balance(node *t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->left) > 0)
         t = ll_rotate(t);
      else
         t = lr_rotate(t);
   } else if (bal_factor < -1) {
      if (difference(t->right) > 0)
         t = rl_rotate(t);
      else
         t = rr_rotate(t);
   }
   return t;
}
node* avl::insert(node *r, int v) {
   if (r == NULL) {
      r = new node;
      r->data = v;
      r->left = NULL;
      r->right = NULL;
      return r;
   } 
   else if (v >= r->data) {
      r->right = insert(r->right, v);
      r = balance(r);
   } 
   else if (v< r->data) {
      r->left = insert(r->left, v);
      r = balance(r);
   } 
   return r;
}
void avl::inorder(node* n){
        if(n == NULL) return;
        inorder(n->left);
        cout<<n->data<<" ";
        inorder(n->right);
}
void avl::preorder(node* n){
        if(n == NULL) return;
        cout<<n->data<<" ";
        preorder(n->left);
        preorder(n->right);
}
void avl::postorder(node* n){
        if(n == NULL) return;
        postorder(n->left);
        postorder(n->right);
        cout<<n->data<<" ";
}
void avl::avlsort(node* n,int* arr, int &index){
        if(n == NULL) return;
        avlsort(n->left,arr,index);
        arr[index] = n->data;
        index++;
        avlsort(n->right,arr,index);
}
int main(){
        node* root = NULL;
        avl a;
        int n;
        cin>>n;
        for(int i =0; i < n; i++){
                int t;
                cin>>t;
                root = a.insert(root,t);
        }
        a.preorder(root);
}
