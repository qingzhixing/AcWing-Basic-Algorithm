#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    //新nums存储原nums的前缀和
    for(int i=1;i<n;i++){
        nums[i]+=nums[i-1];
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        if(l==1){
            cout<<nums[r-1]<<endl;
        }else{
            cout<<nums[r-1]-nums[l-1-1]<<endl;
        }
    }
    return 0;
}