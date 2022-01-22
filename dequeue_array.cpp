#include<iostream>
using namespace std;
const int big = 1e5;
class dequeue_array{
        public:
                int arr[big];
                int maxsize;
                int size;
                int front,rear;
                void ib(int data);
                void ie(int data);
                void printer();
                int db();
                int de();
                dequeue_array(int space = 5){
                        size = 0;
                        maxsize = space;
                        for(int i = 0; i < space ;i++) arr[i] = -1;
                        front  = -1;
                        rear = -1;
                }
};

void dequeue_array::ib(int data){
        if(size == 0){
                front= 0;
                rear= 0;
                arr[front] = data;
                size++;
        }
        else if(front == 0){
                cout<<"Dequeue Full\n";
        }
        else{
                front--;
                size++;
                arr[front] = data;
        }
}

void dequeue_array::ie(int data){
        if(size == 0){
                front= 0;
                rear= 0;
                arr[front] = data;
                size++;
        }
        else if(front == maxsize-1){
                cout<<"Dequeue Full\n";
        }
        else{
                rear++;
                arr[rear] = data;
                size++;
        }
}
int dequeue_array::db(){
        if(size == 0){
                cout<<"Dequeue Empty\n";
                return -1e9;
        }
        else{
                int k = arr[front];
                front++;
                size--;
                return k;
        }
}

int dequeue_array::de(){
        if(size == 0){
                cout<<"Dequeue Empty\n";
                return -1e9;
        }
        else{
                int  k = arr[rear];
                rear--;
                size--;
                return k;
        }
}
void dequeue_array::printer(){
        for(int i = front; i <= rear; i++){
                cout<<arr[i]<<" ";
        }
        cout<<"\n";
}
dequeue_array dq;
int tt = 1;
void choice(){
        string s;
        cin>>s;
        if(s[0] == 'D'){
                if(s[1] == 'E'){
                        int pr = dq.de();
                        if(pr != -1e9) cout<<pr<<"\n";
                }
                else{
                        int pr = dq.db();
                        if(pr != -1e9) cout<<pr<<"\n";
                }
                return;
        }
        else if(s[0] == 'P'){
                dq.printer();
                return;
        }
        else{
                int t = 2;
                if(s[2] == '-') t++;
                int in = stoi(s.substr(t,s.size()-t));
                if(t == 3){
                        in *= -1;
                }
                if(s[1] == 'B') dq.ib(in);
                else dq.ie(in);
        }
        tt++;
}
int main(){
        int n;
        cin>>n;
        while(n--) choice();
}




