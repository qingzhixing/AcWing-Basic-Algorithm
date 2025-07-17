#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define MAX_N 1000010

struct Edge {
    int toId;
    int weight;
};

struct QueueNode{
    int id;
    int distanceToStart;
    bool operator<(const QueueNode& other)const{
        return distanceToStart>other.distanceToStart;
    }
};

vector<Edge> map[MAX_N];
int dist[MAX_N];
bool isShortest[MAX_N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        map[u].push_back({v,w});
    }

    //初始化
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;

    //待选堆，存储未确定最短路的点
    //这里只放起点原因是因为其它点的距离是正无穷，不可能在起点更新后用到
    priority_queue<QueueNode> q;
    q.push({1,0});

    while(q.size()){
        QueueNode currentNode=q.top();
        q.pop();
        int currentId=currentNode.id;
        int currentDistance=currentNode.distanceToStart;
        if(isShortest[currentId])continue;

        isShortest[currentId]=true;

        for(auto edge:map[currentId]){
            int nextId=edge.toId;
            int nextDistance=currentDistance+edge.weight;
            if(dist[nextId]>nextDistance){
                dist[nextId]=nextDistance;
                q.push({nextId,nextDistance});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f)cout<<-1<<endl;
    else cout<<dist[n]<<endl;
    return 0;
}