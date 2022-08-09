#include<iostream>
#include<cstring>
using namespace std;

#define MAX_N 510

//map[i][j]=true表示存在左侧节点i到右侧节点j的边
bool map[MAX_N][MAX_N];
//match [i]=j表示右侧点i与左侧点j匹配
int match[MAX_N];
int visited[MAX_N];
int n1,n2,m;

//匈牙利算法，返回是否匹配成功
bool Hungary(int id){
    for(int nextNode=1;nextNode<=n2;nextNode++){
        //判断是否有边并且防止重复选择
        if(!map[id][nextNode]||visited[nextNode]){
            continue;
        }
        visited[nextNode]=true;
        //没有被匹配或者匹配该点的点还有其他选择则匹配成功
        if(match[nextNode]==0||Hungary(match[nextNode])){
            match[nextNode]=id;
            return true;
        }
    }
    return false;
}

int main(){
    cin>>n1>>n2>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        //仅记录左到右到边
        map[x][y]=true;
    }

    int ans=0;
    for(int i=1;i<=n1;i++){
        /*
        * visited用来记录每一回合右侧点是否在当前回合被访问过
        * 作用是防止递归时先前节点重复选择递归前被绑定的节点
        * 比如说b在a后面选择了c,这时候要给c打上标记，防止c被选择两次
        * 这样才能知道a是否还有其它点能够被匹配
        */
        memset(visited,0,sizeof(visited));
        ans+=Hungary(i);
    }

    cout<<ans<<endl;
    return 0;
}