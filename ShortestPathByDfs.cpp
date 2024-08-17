#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>
#include <unordered_set>
using namespace std;


int v;
vector<list<int> > graph;
unordered_set<int> visited;
vector<int> dist;

void add_edge(int src,int des,bool bi_dir = true){
    graph[src].push_back(des);
    if(bi_dir){
        graph[des].push_back(src);
    }
}


// breadth first search
void dfs(int src,int des,vector<int>& dist){
    
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

    int src,des;
    cin>>src>>des;

    dfs(src,des,dist);
    
    for(int i=0;i<dist.size();i++){
        cout<<i<<" -> "<<dist[i]<<endl;
    }

}

