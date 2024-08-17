#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<unordered_map>

using namespace std;
int v;
vector<list<int> > graph;
unordered_set<int> visited;

void add_edge(int src,int des,bool bi_dir = true){
    graph[src].push_back(des);
    if(bi_dir){
        graph[des].push_back(src);
    }
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto ele : graph[i]){
            cout<<ele<<" , ";
        }
        cout<<"\n";
    }
}

void dfs(int src){
    visited.insert(src);
    for(auto ele : graph[src]){
        if(! visited.count(ele)){
            dfs(ele);
        }
    }
}
void connectedComponent(int vertices){
    int count = 0;
    for(int i=0;i<vertices;i++){
        if(visited.count(i) == 0){
            count++;
            dfs(i);
        }
    }
    cout<<count;
}
int main(){
    cout<< "Enter no. of vertices : ";
    cin>>v;

    graph.resize(v,list<int> ());
    int e;
    cout<<"Enter no. of Edges : ";
    cin>>e;

    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }

    display();
    cout<<"Number of connected componenets is : ";
    connectedComponent(v);
}

