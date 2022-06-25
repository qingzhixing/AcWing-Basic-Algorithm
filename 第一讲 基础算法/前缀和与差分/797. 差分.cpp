#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int number;
        cin>>number;
        nums.push_back(number);
    }
    //计算差分数组,nums存储
    for(int i=n-1;i>=1;i--){
        nums[i]-=nums[i-1];
    }

    while(m--){
        int l,r,c;
        cin>>l>>r>>c;
        nums[l-1]+=c;
        if(r-1<=n-1){
            nums[r-1+1]-=c;
        }
    }
    //计算前缀和数组
    for(int i=1;i<=n;i++){
        nums[i]+=nums[i-1];
    }
    
    for(auto item:nums){
        cout<<item<<' ';
    }
}