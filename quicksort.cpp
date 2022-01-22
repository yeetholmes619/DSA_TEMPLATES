#include<iostream>
using namespace std;
int n;
int arr[10000];
void swap(int &a, int &b){
        if(a == b) return;
        a ^= b;
        b ^= a;
        a ^= b;
}
int partition(int a[],int lb, int ub){
        int pivot=  a[lb];
        int start = lb;
        int end = ub;
        while(start < end){
                while((start <= ub) and (a[start] <= pivot)){
                        start++;
                }
                while(a[end] > pivot) end--;
                if(start < end){
                        swap(a[start],a[end]);
                }
        }
       // cerr<<a[lb]<<" "<<a[end]<<"\n";
        swap(a[lb],a[end]);
       // cerr<<a[lb]<<" "<<a[end]<<"\n";
       // for(int i = 0; i < n ; i ++) cout<<arr[i]<<" ";
       // cout<<"\n";
        return end;
}
void quicksort(int a[], int lb, int ub){
        if(lb < ub){
                int loc = partition(a,lb,ub);
                quicksort(a,lb,loc-1);
                quicksort(a,loc+1,ub);
        }
}
int main(){
        cin>>n;
        for(int i = 0; i < n; i++) cin>>arr[i];
        quicksort(arr,0,n-1);
        for(int i = 0; i < n ; i ++) cout<<arr[i]<<" ";

}
