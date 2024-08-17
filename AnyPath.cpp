#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<unordered_map>
#include<unordered_set>


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

bool dfs(int curr,int des){
    if(curr == des) return true;
    visited.insert(curr); // mark 
    for(auto ele : graph[curr]){
        if(visited.find(ele)==visited.end()){
            bool result = dfs(ele,des);
            if(result) return true;
        }
    }
    return false;   
}
bool anyPath(int src,int des){
    return dfs(src,des);
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

    int x, y;
    cout<<"Enter source and destination : ";
    cin>>x>>y;
    bool result = anyPath(x,y);
    if(result) cout<<"Path Exists";
    else cout<<"No Path Exists";
    return 0;
}

