#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX_N 510


int dist[MAX_N];
//已确定最短路的点
bool isShortest[MAX_N];
//map[i][j]表示i到j的距离
int map[MAX_N][MAX_N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        if(map[u][v]==0||map[u][v]>w){
            map[u][v]=w;
        }
    }

    //初始化
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;

    //n个点需要更新n次
    for(int i=1;i<=n;i++){
        int minDistance=0x3f;
        int minIndex=0;
        //查找距离最近的未确定最短路的点
        for(int j=1;j<=n;j++){
            if(!isShortest[j]&&dist[j]<minDistance){
                minDistance=dist[j];
                minIndex=j;
            }
        }

        //将该点确认为最短路
        isShortest[minIndex]=true;

        //更新距离
        for(int next=1;next<=n;next++){
            //无边则跳过
            if(map[minIndex][next]==0)continue;
            int distance=map[minIndex][next];

            //DEBUG:
            // printf("point %d enable to reach point %d distance %d\n",minIndex,next,distance);

            if(dist[next]>dist[minIndex]+distance){
                dist[next]=dist[minIndex]+distance;

                //DEBUG: 
                // printf("point %d distance:%d updated point %d distance:%d\n",minIndex,dist[minIndex],next,dist[next]);
            }
        }
    }
    //无法走到:
    if(dist[n]>5000000){
        cout<<-1<<endl;
    }
    else{
        cout<<dist[n]<<endl;
    }
    //DEBUG:
    // for(int i=1;i<=n;i++){
    //     cout<<dist[i]<<" ";
    // }
    return 0;
}
//TODO:DEBUG

/*
hand-made data:
9 16
1 2 1
1 3 3
2 3 2
2 4 5
3 4 7
3 5 6
3 6 7
4 7 3
4 9 8
4 6 6 
5 8 2
6 1 4
6 9 5
7 6 1
7 9 4
8 9 1

answer:
12
distance:
0 1 3 6 9 10 9 11 12

correct answer.
what is wrong?
wtf???
*/