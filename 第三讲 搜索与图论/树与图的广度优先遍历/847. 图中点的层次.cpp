#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX_N 100010

struct Node{
    int id;
    int step;
};

vector<vector<int>> map(MAX_N);
//是否被遍历
bool visited[MAX_N];
int n,m;

int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        map[a].push_back(b);
    }
    queue<Node> q;
    q.push({1,0});
    visited[1]=true;

    while(q.size()){
        Node currentNode=q.front();
        q.pop();
        //剪枝
        if(currentNode.step>n){
            break;
        }
        if(currentNode.id==n){
            cout<<currentNode.step<<endl;
            return 0;
        }
        for(auto next:map[currentNode.id]){
            if(!visited[next]){
                visited[next]=true;
                q.push({next,currentNode.step+1});
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}