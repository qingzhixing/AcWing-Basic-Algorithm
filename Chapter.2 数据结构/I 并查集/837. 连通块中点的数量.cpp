#include<iostream>
#include<string>
using namespace std;

#define MAX_N 100010

struct Node{
    int father;
    int nodeCount;
    Node(int _father=0,int _nodeCount=1):father(_father),nodeCount(_nodeCount){}
};

Node nodes[MAX_N];

int QueryAncestors(int id){
    int ancestors=nodes[id].father;
    while(ancestors!=nodes[ancestors].father){
        ancestors=nodes[ancestors].father;
    }
    //路径压缩
    while(id!=ancestors){
        int temp=nodes[id].father;
        nodes[id].father=ancestors;
        id=temp;
    }
    return ancestors;
}

void Merge(int id1,int id2){
    int ancestor1=QueryAncestors(id1);
    int ancestor2=QueryAncestors(id2);
    if(ancestor1==ancestor2){
        return;
    }
    //合并优化
    if(nodes[ancestor1].nodeCount<nodes[ancestor2].nodeCount){
        nodes[ancestor1].father=ancestor2;
        nodes[ancestor2].nodeCount+=nodes[ancestor1].nodeCount;
        nodes[ancestor1].nodeCount=0;
    }else{
        nodes[ancestor2].father=ancestor1;
        nodes[ancestor1].nodeCount+=nodes[ancestor2].nodeCount;
        nodes[ancestor2].nodeCount=0;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        nodes[i]=Node(i,1);
    }
    while(m--){
        string command;
        cin>>command;
        if(command=="C"){
            int a,b;
            cin>>a>>b;
            Merge(a,b);
            continue;
        }
        if(command=="Q1"){
            int a,b;
            cin>>a>>b;
            cout<<((QueryAncestors(a)==QueryAncestors(b))?
            "Yes":"No")<<endl;
            continue;
        }
        if(command=="Q2"){
            int a;
            cin>>a;
            cout<<nodes[QueryAncestors(a)].nodeCount<<endl;
            continue;
        }
    }
    return 0;
}