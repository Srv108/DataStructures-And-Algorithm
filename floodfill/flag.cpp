#include<iostream>
using namespace std;
int main(){
    for(int i=0;i<10;i++){
        for(int k=0;k<10;k++){
            if(k >= i) cout<<"#";
            else cout<<"*";
        }
        cout<<endl;
    }
}