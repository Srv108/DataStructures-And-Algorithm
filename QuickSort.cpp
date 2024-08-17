#include<iostream>
using namespace std;


void Demo(int* arr,int st,int en){
    if(st == en) return;
    int i = st;
    int j = en-1;
    int pi = arr[st];
    while(i < j){
        if(arr[i] >= pi){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            if(arr[j] != pi) j--;
        }else i++;
    }
    Demo(arr,st,j);
    Demo(arr,j+1,en);
}

int main(){
    int arr[] = {9,11,13,6,3,1,21,7,4,15,21,8,2,5,0,22,12,17,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    Demo(arr,0,n);
    
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}