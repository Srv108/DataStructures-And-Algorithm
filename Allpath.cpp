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
vector<vector<int> > result;


void add_edge(int src,int des,bool bi_dir = true){
    graph[src].push_back(des);
    if(bi_dir){
        graph[des].push_back(src);
    }
}

void dfs(int curr,int des,vector<int>& path){
    if(curr == des){
        path.push_back(curr);
        result.push_back(path);
        path.pop_back();
        return;
    };
    visited.insert(curr); // mark 
    path.push_back(curr);
    for(auto ele : graph[curr]){
        if(visited.find(ele)==visited.end()){
            dfs(ele,des,path);
        }
    }
    path.pop_back();
    visited.erase(curr);
}
bool anyPath(int src,int des){
    vector<int> v;
    dfs(src,des,v);
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

void DisplayPath(){
    for(int i=0;i<result.size();i++){
        for(auto ele : result[i]){
            cout<<ele<<" -> ";
        }
        cout<<"\n";
    }
    return;
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

    DisplayPath();
    return 0;
}

