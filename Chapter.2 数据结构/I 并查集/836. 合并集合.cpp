#include<iostream>
using namespace std;

#define MAX_N 100010

int father[MAX_N];
int n,m;

int QueryAncestors(int id){
    int ancestors=father[id];
    while(ancestors!=father[ancestors]){
        ancestors=father[ancestors];
    }
    //路径压缩
    while(id!=ancestors){
        int temp=father[id];
        father[id]=ancestors;
        id=temp;
    }
    return ancestors;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        father[i]=i;
    }
    while(m--){
        char command;
        int a,b;
        cin>>command>>a>>b;
        switch(command){
            case 'M':
                father[QueryAncestors(a)]=QueryAncestors(b);
                break;
            case 'Q':
                cout<<((QueryAncestors(a)==QueryAncestors(b))?
                "Yes":"No")<<endl;
                break;
        }
    }
    return 0;
}