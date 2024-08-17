

#include<iostream> /*               || जय सिया राम ❤️ ||               */        
#include<vector> 
using namespace std;


void Union(vector<int>& parents,vector<int>& size,int a,int b){      // add two two groups 
    int a = parents[a];
    int b = parents[b];

    if(a == b) return;
    if(size[a] > size[b]){
        for(int i=0;i<parents.size();i++){
            if(parents[i] == b) parents[i] = a;
        }
        size[a] += size[b];
    }else{
        for(int i=0;i<parents.size();i++){
            if(parents[i] == a) parents[i] = a;
        }
        size[b] += size[a];
    }
}

int find(int a,vector<int>& parents){
    return parents[a];
}


int main(){
    int n,m;
    cin>>n,m;


    vector<int> size(n,1);
    vector<int> parent(5);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    while(m--){
        string str;
        cin>>str;

        if(str == "union") {
            int a,b;
            cin>>a>>b;
            Union(parent,size,a,b);
        }
        else {
            int a;cin>>a;
            int ans = find(a,parent);
        }
    }

}