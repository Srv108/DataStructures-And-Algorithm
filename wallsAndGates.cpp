#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>
#include <unordered_set>

using namespace std;

int rows,cols;
vector<vector<int> > grid = {{-2,-1,0,-2},{-2,-2,-2,-1},{-2,-1,-2,-1},{0,-1,-2,-2}};
vector< vector<int> > dir = {{-1,0},{0,-1},{1,0},{0,1}};
vector<vector<int> > result(rows,(vector<int> (cols,-1)));
vector< vector<bool> > visited(rows,vector<bool> (cols,false));


vector<vector<int> >  moves(queue<pair<pair<int,int> ,int> >& qu){
    while(!(qu.empty())){
        auto cell = qu.front();
        qu.pop();
        int currX = cell.first.first;
        int currY = cell.first.second;
        
        visited[currX][currY] = true;
        int dis = cell.second;
        result[currX][currY] = dis;

        for(int i=0;i<4;i++){
            int newX = currX + dir[i][0];
            int newY = currY = dir[i][1];

            if(newX < 0 || newY < 0 || newX >= rows || newY >= cols || grid[newX][newY] == -1) continue;
            if(visited[newX][newY]) continue;
            qu.push({{newX,newY},dis+1});
        }

        
    }
    return result;

}
int main(){
    rows = grid.size();
    cols = grid[0].size();

    queue<pair<pair<int,int> ,int> > qu;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(grid[i][j] == 0){
                qu.push({{i,j},0});
                visited[i][j] = true;
                result[i][j] = 0;
            }
        }
    }
    moves(qu);
}