#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>

using namespace std;
int v;
vector<list<int> > graph;

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
}

