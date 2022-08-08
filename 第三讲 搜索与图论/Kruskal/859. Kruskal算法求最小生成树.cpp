#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_N 100010

struct Edge{
    int from,to,weight;
    bool operator<(const Edge& e) const{
        return weight<e.weight;
    }
};

vector<Edge> edges;
//并查集记录是否连通
int father[MAX_N];

int QueryAncestor(int id){
    if(father[id]==0) return id;
    //返回并且路径压缩
    return father[id]=QueryAncestor(father[id]);
}

inline bool HaveSameAncestor(int id1,int id2){
    return QueryAncestor(id1)==QueryAncestor(id2);
}

void Merge(int id1,int id2){
    if(HaveSameAncestor(id1,id2)) return;
    father[QueryAncestor(id1)]=QueryAncestor(id2);
}

int n,m;
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back((Edge){u,v,w});
    }

    //sort the edges
    sort(edges.begin(),edges.end());

    //traverse the edges
    int ans=0,count=0;
    for(auto edge:edges){
        if(!HaveSameAncestor(edge.from,edge.to)){
            ans+=edge.weight;
            count++;
            Merge(edge.from,edge.to);
        }
    }
    //check whether the graph is connected to another
    if(count<n-1){
        cout<<"impossible"<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}