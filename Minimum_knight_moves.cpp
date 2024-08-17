#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>
#include <unordered_set>

using namespace std;

vector< vector<int> > dir = {{2,-1},{2,1},{1,2},{-1,2},{1,-2},{-1,-2},{-2,1},{-2,-1}};
vector< vector<bool> > visited(309,vector<bool> (309,false));


int moves(int x,int y){
    int X = x + 154;
    int Y = y + 154;
    queue<pair<pair<int,int> ,int> > qu;
    qu.push({{154,154},0});
    while(!(qu.empty())){
        auto cell = qu.front();
        qu.pop();
        int currX = cell.first.first;
        int currY = cell.first.second;
        
        visited[currX][currY] = true;
        int step = cell.second;
        if(currX == X && currY == Y) return step;
        
        for(int i=0;i<8;i++){
            int newX = currX + dir[i][0];
            int newY = currY = dir[i][1];

            if(newX < 0 || newY < 0 || newX >= 309 || newY >= 309) continue;
            if(visited[newX][newY]) continue;
            qu.push({{newX,newY},step+1});
        }

        
    }
    return -1;

}
int main(){
    int x,y;
    cout<<"Minimum number of moves is : "<<moves(2,1);

}
