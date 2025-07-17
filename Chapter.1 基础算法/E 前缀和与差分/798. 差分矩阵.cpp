#include<iostream>
using namespace std;
#define MAX_N 1010

int n,m,q;
int matrix[MAX_N][MAX_N];
int change[MAX_N][MAX_N];
int main(){
    //解题思路：
    //单独用一个差分数组记录修改的值
    //最后用差分数组的前缀和数组加上原数组得到答案
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>matrix[i][j];
        }
    }
    while(q--){
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        change[x1][y1]+=c;
        change[x1][y2+1]-=c;
        change[x2+1][y1]-=c;
        change[x2+1][y2+1]+=c;
    }
    //计算前缀和
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            change[i][j]=change[i][j]+change[i-1][j]+change[i][j-1]-change[i-1][j-1];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<matrix[i][j]+change[i][j]<<' ';
        }
        puts("");
    }
}