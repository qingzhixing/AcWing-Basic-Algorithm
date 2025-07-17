#include<iostream>
using namespace std;
bool isExist[8];
int numberArray[8];
int n;

void DFS(int depth){
    for(int i=1;i<=n;i++){
        if(!isExist[i]){
            isExist[i]=true;
            numberArray[depth]=i;
            DFS(depth+1);
            isExist[i]=false;
        }
    }
    if(depth == n){
        for(int i=1;i<=n;i++){
            cout<<numberArray[i]<<' ';
        }
        puts("");
        return;
    }
}

int main(){
    cin>>n;
    DFS(1);
    return 0;
}