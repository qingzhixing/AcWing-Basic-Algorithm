#include<iostream>
#include<utility>
#include<queue>
using namespace std;

#define MAX_N 110
#define ENABLE 0
#define DISABLE 1

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

struct Coord{
    int x,y;
};

bool map[MAX_N][MAX_N];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
        }
    }
    //记录坐标和从起点开始的步数
    queue<pair<Coord,int>> queue;
    queue.push(make_pair(Coord{1,1},0));
    map[1][1]=DISABLE;
    while(queue.size()){
        auto currentNode=queue.front();
        Coord coord=currentNode.first;
        int step=currentNode.second;
        queue.pop();
        for(int direction=0;direction<4;direction++){
            int nextX=coord.x+dx[direction];
            int nextY=coord.y+dy[direction];
            if(nextX<1||nextX>n||nextY<1||nextY>m) continue;
            if(map[nextX][nextY]==ENABLE){
                map[nextX][nextY]=DISABLE;
                queue.push(make_pair(Coord{nextX,nextY},step+1));
                if(nextX==n&&nextY==m){
                    cout<<step+1<<endl;
                    return 0;
                }
            }
        }
    }
    cout <<"No Solution"<<endl;
    return 0;
}
