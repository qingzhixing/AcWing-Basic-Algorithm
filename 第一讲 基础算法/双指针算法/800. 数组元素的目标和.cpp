#include<iostream>
#include <vector>
using namespace std;

int main(){
    //解题思路：暴力求解，利用单调性进行优化
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> A,B;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        A.push_back(a);
    }
    for(int i=0;i<m;i++){
        int b;
        cin>>b;
        B.push_back(b);
    }
    for(int i=0,j=m-1;i<n;i++){
        //j不用多开一维循环是因为单调性优化，i不断增大,
        //所以如果A[i]+B[j]<=x,A[i+1]+B[k]<=x,则k<=j,
        //即j只用从上一层循环的位置继续递减
        while(j>0&&A[i]+B[j]>x){
            j--;
        }
        if(A[i]+B[j]==x){
            cout<<i<<" "<<j<<endl;
            return 0;
        }
    }
    cout<<"No Solution!"<<endl;
    return 0;
}