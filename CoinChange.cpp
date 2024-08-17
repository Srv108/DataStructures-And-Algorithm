#include<iostream>
#include<vector>
using namespace std;
int count(vector<int>& coins,int amount){
    if(amount == 0) return 0;
    if(amount < 0) return INT_MAX;
    int ans = INT_MAX;
    for(int i = 0; i < coins.size(); i++){
        if(coins[i] <= amount) ans = min(ans, count(coins,amount-coins[i]));
    }
    if(ans == INT_MAX) return INT_MAX;
    return ans+1;
}

int main(){
    int n;
    cout <<"Enter no. of coins: ";
    cin>>n;
    int amount;
    cout<<"Enter amount: ";
    cin>>amount;
    cout<<"Enter coins: ";
    vector<int> arr(n,1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int result = count(arr,amount);
    cout<<"result is : "<<result;
}