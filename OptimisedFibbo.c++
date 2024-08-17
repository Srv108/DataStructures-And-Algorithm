#include<iostream>
#include<unordered_map>
using namespace std;
int fibbo(int n,unordered_map<int,int> &m){
    if(n == 1 || n == 0) return n;
    if(m.find(n) != m.end()) return m[n];
    int x = fibbo(n-1,m) + fibbo(n-2,m);
    m[n] = x;
    return x;
}
int main(){
    unordered_map <int,int> m;
    cout<<fibbo(9,m);
}