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
void bfs(int src,int des,vector<int>& dist){
    queue<int> qu;
    qu.push(src);
    visited.clear();
    dist.resize(v,INT_MAX);
    visited.insert(src);
    dist[src] = 0;
    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();
        for(auto neighbours : graph[curr]){
            if(visited.find(neighbours) == visited.end()){
                visited.insert(neighbours);
                dist[neighbours] = dist[curr] + 1;
                qu.push(neighbours);
            }
        }
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

    bfs(src,des,dist);
    
    for(int i=0;i<dist.size();i++){
        cout<<i<<" -> "<<dist[i]<<endl;
    }

}

