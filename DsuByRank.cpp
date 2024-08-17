

#include<iostream> /*               || जय सिया राम ❤️ ||               */        
#include<vector> 
using namespace std;

int Find(int x,vector<int>& parents){
    return parents[x] = (parents[x] == x ? x : Find(parents[x],parents));
}

void Union(vector<int>& parents,vector<int>& rank,vector<int>& size,int x,int y){      // add two two groups 
    int a = Find(x,parents);
    int b = Find(y,parents);

    if(a == b) return;
    if(rank[a] >= rank[b]){
        rank[a]++;
        parents[b] = a;
        size[a] += size[b];
    }else{
        rank[b]++;
        parents[a] = b;
        size[b] += size[a];
    }
}



int main(){
    int n,m;
    cout<<"Enter n and m : ";
    cin>>n>>m;


    vector<int> size(n+1,1);
    vector<int> parent(n+1);
    vector<int> rank(n+1,0);

    for(int i=0;i<=n;i++){
        parent[i] = i;
    }

    while(m--){
        string str;
        cin>>str;

        if(str == "union") {
            int a,b;
            cin>>a>>b;
            Union(parent,rank,size,a,b);
        }
        else {
            int a;cin>>a;
            int ans = Find(a,parent);
        }
    }

}