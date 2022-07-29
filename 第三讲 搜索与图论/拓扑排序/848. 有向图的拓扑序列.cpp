#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX_N 100010

vector<vector<int> > map(MAX_N);
int inDegree[MAX_N];
bool isDeleted[MAX_N];
vector<int> deletedNums;
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        map[a].push_back(b);
        inDegree[b]++;
    }
    queue<int> deleteQueue;
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            deleteQueue.push(i);
        }
    }
    while(deleteQueue.size()){
        int currentNode=deleteQueue.front();
        deleteQueue.pop();
        isDeleted[currentNode]=true;
        deletedNums.push_back(currentNode);
        for(auto next:map[currentNode]){
            inDegree[next]--;
            if(inDegree[next]==0){
                deleteQueue.push(next);
            }
        }
    }
    if(deletedNums.size()!=n){
        cout<<-1<<endl;
    }else{
        for(auto num:deletedNums){
            cout<<num<<' ';
        }
        cout<<endl;
    }
    return 0;
}