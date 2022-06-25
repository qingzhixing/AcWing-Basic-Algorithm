#include<iostream>
using namespace std;

#define MAX_N 1010

int matrix[MAX_N][MAX_N];
int n,m,q;
int main(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>matrix[i][j];
        }
    }
    //计算前缀和，用matrix存储
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            matrix[i][j]=matrix[i-1][j]+matrix[i][j-1]+matrix[i][j]-matrix[i-1][j-1];
        }
    }
    while(q--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<matrix[x2][y2]-matrix[x1-1][y2]-matrix[x2][y1-1]+matrix[x1-1][y1-1]<<endl;
    }
}