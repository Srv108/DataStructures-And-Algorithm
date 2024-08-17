#include <iostream>/*               || जय सिया राम ❤️ ||               */        
#include <vector>
#define ll long long int
using namespace std;

int find(vector<int>& parent,int a){
    return parent[a] = ((parent[a] == a) ? a : find(parent,parent[a])); 
    // return parent if itself parent otherwise return parents of x
}

void Union(vector<int>& parent,vector<int>& rank,int a,int b){
    int parA = find(parent,a);
    int parB = find(parent,b);

    if(parA == parB) return;

    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
    }else{
        rank[b]++;
        parent[a] = b;
    }
}

struct Edge {
    int src;
    int dest;
    int wt;
};

bool cmp(Edge a,Edge b){
    return a.wt < b.wt;
}

ll Kruskal(vector<Edge>& input,int n,int e){
    sort(input.begin(),input.end(),cmp);

    vector<int> parent(n+1);
    vector<int> rank(n+1,1);

    vector<Edge> result;

    for(int i=0;i<=n;i++){
        parent[i] = i;
    }

    int i = 0;
    ll ans = 0;
    int edgeCount = 0;

    while(i < input.size() and edgeCount < n-1){
        Edge curr = input[i];
        int parSrc = find(parent,curr.src);
        int parDes = find(parent,curr.dest);

        if(parSrc != parDes){
            Union(parent,rank,parSrc,parDes);
            ans += curr.wt;
            edgeCount++;
            result.push_back(curr);
        }
        i++;
    }

    cout<<"Edges in MST are : "<<"\n";
    for(int j=0;j<result.size();j++){
        cout<<result[j].src<<" -> "<<result[j].dest<<" , ";
    }
    return ans;
}

int main(){
    int n,e;
    cout<<"Enter no. of vertices : ";cin>>n;
    cout<<"Enter no. of edges : ";cin>>e;

    vector<Edge> input(e);
    cout<<"Enter Edges of weighted Graph = > "<<endl;
    for(int i=0;i<e;i++){
        cin>>input[i].src>>input[i].dest>>input[i].wt;
    }
    int ans = Kruskal(input,n,e);
    cout<<"Mst weight : " <<ans;
}