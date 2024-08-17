#include<iostream>
using namespace std;
void helper(int* arr,int st,int en){
    if(st == en) return;
    if(arr[st] > arr[st+1]){
        int temp = arr[st];
        arr[st] = arr[st+1];
        arr[st+1] = temp;
    }
    helper(arr,st+1,en);
}
void Demo(int* arr,int st,int en){
    if(st == en) return;
    helper(arr,st,en);
    Demo(arr,st,en-1);
}
int main(){
    int arr[] = {9,11,13,6,3,1,21,7,4,15,21,8,2,5,0,22,12,17,19};
    int p = 11;
    int n = sizeof(arr)/sizeof(arr[0]);
    Demo(arr,0,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}