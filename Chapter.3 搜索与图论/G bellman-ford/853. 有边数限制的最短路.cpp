#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX_N 10010

struct Edge{
    int from,to,weight;
};

vector<Edge> edges;
int dist[MAX_N];
//backup用于保存上一次的dist,新一次dist在backup基础上推导出
//防止更新[该次更新的边]的边已经变化
int backup[MAX_N];

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        edges.push_back({from,to,weight});
    }

    //初始化
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;

    for(int updateTime=1;updateTime<=k;updateTime++){
        //保存上一个状态
        memcpy(backup,dist,sizeof(backup));
        for(auto edge:edges){
            int from=edge.from,to=edge.to,weight=edge.weight;
            //用上一状态更新当前状态
            dist[to]=min(dist[to],backup[from]+weight);
        }
    }
    if(dist[n]>1e8){
        cout<<"impossible"<<endl;
    }else{
        cout<<dist[n]<<endl;
    }
    return 0;
}
