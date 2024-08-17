#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

vector<unordered_map<int,int> > graph;

void addEdge(int src,int des,int wt,bool bi_dir = true){
    graph[src][des] = wt;
    if(bi_dir){
        graph[des][src] = wt;
    }
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto ele : graph[i]){
            cout<<"(" <<ele.first<<","<<ele.second<<") , ";
        }
        cout<<endl;
    }
}
int main(){
    int v;
    cout<<"Enter no. of vertices  : ";
    cin>>v;

    graph.resize(v,unordered_map<int,int> ());

    int e;
    cout<<"Enter no. of edges  : ";
    cin>>e;

    while(e--){
        int src,des,wt;
        cin>>src>>des>>wt;
        addEdge(src,des,wt,false);
    }
    
    display();
}