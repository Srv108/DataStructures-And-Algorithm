#include<iostream>
using namespace std;
int main(){
    int arr[] = {9,11,13,6,3,1,21,7,4,15,21,8,2,5,0,22,12,17,19};
    int p = 7;
    int n = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
    int j = n-1;
    while(i < j){
        if(arr[i] >= p){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            if(arr[j] != p) j--;
        }else i++;
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl<<arr[j];
}