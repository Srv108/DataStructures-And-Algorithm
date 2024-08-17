#include<iostream>
using namespace std;
int main(){
    int arr[] = {9,3,1,4,7,2,6,0};
    int i=0,j=0;
    while(j < 8){
        if(arr[j] > 5) j++;
        else if(arr[j] < 5){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
            i++;
        }
    }
    for(int i=0;i<8;i++) cout<<arr[i]<<" ";
}




