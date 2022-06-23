#include<iostream>
#include<vector>
using namespace std;

void Merge(vector<int>& nums,int left,int mid,int right){
    if(left>=right)return;
    int pointerLeft=left;
    int pointerRight=mid+1;
    vector<int> temp;
    while(temp.size()<right-left+1){
        if(pointerLeft>mid){
            temp.push_back(nums[pointerRight++]);
            continue;
        }
        if(pointerRight>right){
            temp.push_back(nums[pointerLeft++]);
            continue;
        }
        if(nums[pointerLeft]<=nums[pointerRight]){
            temp.push_back(nums[pointerLeft++]);
        }else{
            temp.push_back(nums[pointerRight++]);
        }
    }
    for(int i=0;i<temp.size();i++){
        nums[left+i]=temp[i];
    }
}

void MergeSort(vector<int>& nums,int left,int right){
    if(left>=right)return;
    int mid=(left+right)>>1;
    MergeSort(nums,left,mid);
    MergeSort(nums,mid+1,right);
    Merge(nums,left,mid,right);
}

int main(){
    int n;
    vector<int> nums;
    cin>>n;
    for(int i=0; i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    MergeSort(nums,0,n-1);
    for(auto item:nums){
        cout<<item<<' ';
    }
    return 0;
}