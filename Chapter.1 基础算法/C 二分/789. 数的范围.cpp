#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int FindFirstMoreOrEqualThan(vector<int>& nums,int element){
    int left=0,right=nums.size()-1;
    while(left<right){
        int mid=(left+right)>>1;
        if(nums[mid]<element){
            left=mid+1;
        }else{
            right=mid;
        }
    }
    return left;
}

int FindLastLessOrEqualThan(vector<int>& nums,int element){
    int left=0,right=nums.size()-1;
    while(left<right){
        int mid=(left+right+1)>>1;
        if(nums[mid]>element){
            right=mid-1;
        }else{
            left=mid;
        }
    }
    return left;
}

int main(){
    int n,q;
    vector<int> nums;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    while(q--){
        int element;
        cin>>element;
        int left=FindFirstMoreOrEqualThan(nums,element);
        if(nums[left]!=element){
            cout<<"-1 -1\n";
            continue;
        }
        int right=FindLastLessOrEqualThan(nums,element);
        cout<<left<<' '<<right<<endl;
    }
    return 0;
}
