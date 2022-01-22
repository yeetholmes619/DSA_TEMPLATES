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
            int front();
            void rear();
            Queue(){
                    head = NULL;
                    tail = NULL;
                    size = 0;
            }
};
int Queue::front(){
        return head->data;
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
const int NODE_SIZE = 100;
const int NEIGHBOUR_SIZE = 100;
class graph{
        public:
                int adj[NODE_SIZE][NEIGHBOUR_SIZE] = {0};
                int degree[NODE_SIZE]= {0};
                int visited[NODE_SIZE] = {0};
                void addEdge(int a,int b){
                        adj[a][degree[a]] = b;
                        degree[a]++;
                }
                void dfs(int a = 1){
                        cout<<a<<" ";
                        visited[a] = 1;
                        for(int i =0 ; i < degree[a]; i++){
                                if(!visited[adj[a][i]]) dfs(adj[a][i]);
                        }
                }
                bool hasCycle(int a = 1,int parent = -1){
//                        cout<<a<<" ";
                        visited[a] = 1;
                        for(int i =0 ; i < degree[a]; i++){
                                if(!visited[adj[a][i]]){
                                         if(hasCycle(adj[a][i],a)) return true;
                                }
                                else if(adj[a][i] != parent) return true;
                        }
                        return false;
                }
                void bfs(int a = 1){
                        cout<<a<<" ";
                        visited[a] = 1;
                        Queue q;
                        q.enqueue(a);
                        while(q.size){
                                int t = q.front();
                                q.dequeue();
                                for(int i =0 ; i < degree[t]; i++){
                                        if(!visited[adj[t][i]]){
                                                cout<<adj[t][i]<<" ";
                                                q.enqueue(adj[t][i]);
                                                visited[adj[t][i]] = 1;
                                        }
                                }
                        }
                }
};
int main(){
}
