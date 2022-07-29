#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
#define MAX_N 100010

struct Edge{
    int next;
    int distance;
};

int dist[MAX_N];
//已确定最短路的点
bool isShortest[MAX_N];
int shortestAmount=0;
vector<Edge> map[MAX_N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u].push_back((Edge){v,w});
    }
    //初始化
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    while(shortestAmount<n){
        int minDistance=0x3f;
        int minIndex=0;
        //查找距离最近的未确定最短路的点
        for(int i=1;i<=n;i++){
            if(!isShortest[i]&&dist[i]<minDistance){
                minDistance=dist[i];
                minIndex=i;
            }
        }
        isShortest[minIndex]=true;
        shortestAmount++;
        //更新距离
        for(int i=0;i<map[minIndex].size();i++){
            int next=map[minIndex][i].next;
            int distance=map[minIndex][i].distance;

            //DEBUG:
            // printf("point %d enable to reach point %d distance %d\n",minIndex,next,distance);

            if(dist[next]>dist[minIndex]+distance){
                dist[next]=dist[minIndex]+distance;

                //DEBUG: 
                // printf("point %d distance:%d updated point %d distance:%d\n",minIndex,dist[minIndex],next,dist[next]);
            }
        }
        //DEBUG:
        // cout<<"shortest amount:"<<shortestAmount<<endl;
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