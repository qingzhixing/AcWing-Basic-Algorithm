#include<iostream>
#include<cstring>
using namespace std;
#define MAX_N 510

int map[MAX_N][MAX_N];
int dist[MAX_N];
bool isShortest[MAX_N];
int n,m;

int main(){
    cin>>n>>m;
    
    //init
    memset(map,0x3f,sizeof(map));
    memset(dist,0x3f,sizeof(dist));

    for(int i=1;i<=m;i++){
        int from,to,weight;
        cin>>from>>to>>weight;
        map[from][to]=min(map[from][to],weight);
    }

    //dijkstra
    dist[1]=0;

    for(int i=1;i<=n;i++){
        //find shortest distance
        int shortestPoint=-1;
        for(int j=1;j<=n;j++){
            if(!isShortest[j] && (shortestPoint==-1 || dist[j]<dist[shortestPoint])){
                shortestPoint=j;
            }
        }

        //update
        isShortest[shortestPoint]=true;
        for(int j=1;j<=n;j++){
            dist[j]=min(dist[j],dist[shortestPoint]+map[shortestPoint][j]);
        }
    }
    if(dist[n]==0x3f3f3f3f){
        cout<<-1<<endl;
    }else 
    {
        cout<<dist[n]<<endl;
    }
    return 0;
}