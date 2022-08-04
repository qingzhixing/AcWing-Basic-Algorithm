#include<iostream>
#include<cstring>
using namespace std;

#define MAX_N 510
int map[MAX_N][MAX_N];
//点到集合的距离
int dist[MAX_N];
bool isInGather[MAX_N];

int main(){
    int n,m;
    int answer=0;

    cin>>n>>m;

    //init
    memset(dist,0x3f,sizeof(dist));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=0x3f3f3f3f;
        }
    }

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        map[a][b]=map[b][a]=min(map[a][b],c);
    }

    //Prim
    for(int i=1;i<=n;i++){
        //select min point from not in gather
        int minDistancePoint=-1;
        for(int j=1;j<=n;j++){
            if(!isInGather[j] && (minDistancePoint==-1 || dist[j]<dist[minDistancePoint])){
                minDistancePoint=j;
            }
        }

        //判断连通性：
        //非第一个点且到集合距离是INF则说明不连通
        if(i!=1&&dist[minDistancePoint]==0x3f3f3f3f){
            cout<<"impossible"<<endl;
            return 0;
        }
        if(i!=1){
            answer+=dist[minDistancePoint];
        }

        //add to gather
        isInGather[minDistancePoint]=true;

        //update dist
        for(int j=1;j<=n;j++){
            if(!isInGather[j]){
                dist[j]=min(dist[j],map[minDistancePoint][j]);
            }
        }
    }
    cout<<answer<<endl;

    //DEBUG:
    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
    // puts("");

    return 0;
}