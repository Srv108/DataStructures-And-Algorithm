#include<iostream>
using namespace std;
int main(){
    int arr[] = {9,11,13,6,3,1,21,7,4,15,21,8,2,5,0,22,12,17,19};
    int p = 15;
    int n = sizeof(arr)/sizeof(arr[0]);
    int i = 0,j=0;

    for(j=0,i=0;j<n;j++){
        if(arr[j] == p && p != n-1){
            int temp = arr[n-1];
            arr[n-1] = arr[j];
            arr[j] = temp;
        }
        if(arr[j] <= p){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }else continue;
    }   
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl<<arr[i-1];
}