/*                              || जय सिया राम ❤️ ||                               */
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

void makeEdge(vector<vector<int> >& graph,int src,int dest,bool bidir){
    graph[src].push_back(dest);
    if(bidir) graph[dest].push_back(src);
}

void TopoBfs(vector<vector<int> >& graph){
    int n = graph.size();
    vector<int> indegree(n);

    for(int i=0;i<n;i++){
        for(auto neighbour : graph[i]){
            // i  --->  neighbour pe directed h
            indegree[neighbour]++;
        }
    }

    queue<int> qu;
    unordered_set<int> vis;

    for(int i=0;i<n;i++){
        if(indegree[i] == 0){
            qu.push(i);
            vis.insert(i);
        }
    }

    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();

        for(auto neighbour : graph[curr]){
            if(!vis.count(neighbour)) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    qu.push(neighbour);
                    vis.insert(neighbour);
                }
            }else{
                cout<<"Cycle detected";
                return;
            }

        }
    }

}

int main(){
    int n;   // no. of vertices
    int e;   // no. of edges

    cin>>n>>e;
    vector< vector<int> > graph(n);

    while(e--){
        int a,b; // take input of edges
        cin>>a>>b;
        makeEdge(graph,a,b,false);
    }

}