#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

struct Edge{
    int to,w;
};

#define MAX_N 100010

vector<Edge> map[MAX_N];
int dist[MAX_N];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u].push_back((Edge){v,w});
    }

    //初始化
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    //记录被更新过的点
    queue<int> updated;
    updated.push(1);

    while(updated.size()){
        int point=updated.front();
        updated.pop();
        for(auto edge:map[point]){
            //若可以更新则放入更新队列
            if(dist[point]+edge.w<dist[edge.to]){
                dist[edge.to]=dist[point]+edge.w;
                updated.push(edge.to);
            }
        }
    }

    if(dist[n]==0x3f3f3f3f){
        cout<<"impossible"<<endl;
    }else{
        cout<<dist[n]<<endl;
    }
    return 0;
}