#include<iostream>
#include<string>
using namespace std;
class CircularQueueArray{
        public:
                int maxsize;
                int size;
                int arr[1000];
                int front,rear;
                CircularQueueArray(int space){
                        maxsize = space;
                        size = 0;
                        front  = -1;
                        rear = -1;
                }
                void enqueue(int data);
                int dequeue();
                void printer();
};
void CircularQueueArray::enqueue(int data){
        if(size == 0){
                front = 0;
                size++;
                rear = 0;
                arr[front] = data;
        }
        else if(size == maxsize){
                cout<<"Queue Full\n";
        }
        else{
                rear++;
                arr[rear%maxsize] = data;
                size++;
        }
}
int CircularQueueArray::dequeue(){
        if(size == 0){
                cout<<"Queue Empty\n";
                return -1e9;
        }
        size--;
        int k = arr[front%maxsize];
        front++;
        return k;
}
void CircularQueueArray::printer(){
        for(int i = front; i <= rear; i++){
                cout<<arr[i%maxsize]<<" ";
        }
        cout<<"\n";
}
CircularQueueArray q = CircularQueueArray(5);
int main(){
}
