#include<iostream>
#define _print(a) for(auto t: a) cout<<t<<" "
using namespace std;
int n;
int ar[1000000];
template<class T>
void p(T a[], int n){
        cout<<"***";
        for(int i =0 ; i < n; i++) cout<<a[i]<<" ";
        cout<<"\n";
}
template<class T>
void pp(T a[], int st, int en){
        for(int i = st;i  <= en; i++) cout<<a[i]<<" ";
        cout<<"\n";
}
template<class T>
void merge(T arr[], int s, int m, int e){
        T a1[100005];
        T a2[100005];
        int i1= 0,i2= 0;
        for(int i = s;  i <= m; i++ ){
                a1[i-s] = arr[i];
        }
        for(int i = m+1; i <= e; i++){
                a2[i-m-1] = arr[i];
        }
        int i;
        for(i = s; ((i1  < m-s+1) and (i2 < e-m)); i++){
                if(a1[i1] <= a2[i2]){
                        arr[i] = a1[i1];
                        i1++;
                }
                else{
                        arr[i] = a2[i2];
                        i2++;
                }
        }
        while(i1 < m-s+1){
                arr[i] = a1[i1];
                i1++;
                i++;
        }
        while(i2 < e-m){
                arr[i] = a2[i2];
                i2++;
                i++;
        }
}
template<class T>
void mergesort(T arr[],int start ,int end){
        if(end <= start) return;
        int mid = start + (end-start)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
}
int main(){
        cin>>n;
        for(int i = 0; i < n ; i++){
                cin>>ar[i];
        }
        mergesort(ar,0,n-1);
        for(int i = 0; i < n; i++) cout<<ar[i]<<" ";
}
