#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define MAX_N 2010

struct Edge{
    int to,w;
};

vector<Edge> map[MAX_N];
int dist[MAX_N];
//用于记录路径长度
int cnt[MAX_N];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u].push_back((Edge){v,w});
    }

    //spfa

    //init
    queue<int> updated;
    //放置所有点原因:防止存在1点到达不了的负环
    for(int i=1;i<=n;i++){
        updated.push(i);
    }

    while(updated.size()){
        int point=updated.front();
        updated.pop();
        for(auto edge:map[point]){
            if(dist[edge.to]>dist[point]+edge.w){
                dist[edge.to]=dist[point]+edge.w;
                updated.push(edge.to);
                cnt[edge.to]=cnt[point]+1;
                //抽屉原理判断负环
                if(cnt[edge.to]>=n){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}