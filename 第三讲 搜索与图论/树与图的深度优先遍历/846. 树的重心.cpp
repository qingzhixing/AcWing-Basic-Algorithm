#include<iostream>
#include<vector>
using namespace std;

#define MAX_N 100010

vector<vector<int>> map(MAX_N);
//是否被遍历
bool traversed[MAX_N];
int n,ans=2147483647;

inline void Connect(int point1,int point2){
    map[point1].push_back(point2);
    map[point2].push_back(point1);
}

int CalculateTreeSize(int root){
    traversed[root] = true;
    int size = 1;

    //删除该节点产生的几棵子树大小的最大值
    int maxSubTreeSize=-1;

    for(auto next:map[root]){
        if(!traversed[next]){
            int subTreeSize = CalculateTreeSize(next);
            size += subTreeSize;
            maxSubTreeSize = max(maxSubTreeSize,subTreeSize);
        }
    }

    //整棵树除去该节点树的大小
    int otherNodeSum=n-size;
    
    maxSubTreeSize = max(maxSubTreeSize,otherNodeSum);
    ans = min(ans,maxSubTreeSize);
    return size;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        Connect(a,b);
    }
    CalculateTreeSize(1);
    cout<<ans<<endl;
    return 0;
}