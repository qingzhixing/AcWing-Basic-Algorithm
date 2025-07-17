#include<iostream>
#include<cstring>
using namespace std;

#define MAX_N 210
#define INF 1e9

//dist[i][j]表示从i到j的最短路径长度,一开始的图也用dist存储
int dist[MAX_N][MAX_N];
int n,m,k;

int main(){
    cin>>n>>m>>k;

    //init
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=INF;
            if(i==j){
                dist[i][j]=0;
            }
        }
    }

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=min(dist[u][v],w);
    }

    //Calculate shortest path between every pair of points
    for(int transitPoint=1;transitPoint<=n;transitPoint++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][transitPoint]+dist[transitPoint][j]);
            }
        }
    }

    //Query
    while(k--){
        int a,b;
        cin>>a>>b;
        if(dist[a][b]>=2e8){
            cout<<"impossible"<<endl;
        }else{
            cout<<dist[a][b]<<endl;
        }
    }
    return 0;
}