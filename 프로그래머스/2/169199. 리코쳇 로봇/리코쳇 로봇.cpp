#include <string>
#include <vector>
#include <math.h>
#include <limits.h>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int r,c;
char arr[101][101];
int visited[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
pair<int,int> startValue;
pair<int,int> endValue;
int ans= INT_MAX;

pair<int,int> move(int dir,int y, int x){
    int py = y;
    int px = x;
    int prevPy;
    int prevPx;
    visited[py][px] = 1;
    while(1){
        prevPy = py;
        prevPx = px;
        py +=dy[dir];
        px +=dx[dir];
        if(py < 0 || px < 0 || py >= r || px >=c ){
          break;
        }
        if(arr[py][px] == 'D'){
            break;
        }
    }
    if(visited[prevPy][prevPx] == 0){
        visited[prevPy][prevPx] = 1;
        return {prevPy, prevPx};
    }
    else{
        return {-1,-1};
    }
}

void bfs(){
    queue<pair<int,pair<int,int>>> q;
    q.push({startValue.first,{startValue.second,0}});
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second.first;
        int time = q.front().second.second;
        
        q.pop();
    if(y == endValue.first && x == endValue.second){
            ans = min(time,ans);
        }
        for(int i=  0 ; i<4; i++){
          pair<int,int> next = move(i ,y ,x);
        if(next.first == -1 && next.second == -1){
            
        }
        else{
            q.push({next.first,{next.second,time+1}});
        }
    
        }
    }
}

int solution(vector<string> board) {
    r = board.size();
    c = board[0].size();
   
    for(int i = 0 ; i<board.size(); i++){
        for(int j = 0 ; j<board[i].size(); j++){
            if(board[i][j] == 'R'){
                startValue = {i,j};
            }
            else if(board[i][j] == 'G'){
                endValue = {i,j};
            }
            arr[i][j] = board[i][j];
        }
    }
   
    bfs();
    int answer = 0;
    if(ans == INT_MAX){
        answer = -1;
    }
    else{
        answer = ans;
    }
    
    
    return answer;
}