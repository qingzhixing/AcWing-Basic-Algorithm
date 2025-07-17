#include<iostream>
#include<vector>
using namespace std;

long long Merge(vector<int>& nums,int left,int mid,int right){
    long long reversePairAmount=0;
    if(left>=right)return 0;
    int pointerLeft=left;
    int pointerRight=mid+1;
    vector<int> tempVector;
    while(tempVector.size()<right-left+1){
        if(pointerLeft>mid){
            tempVector.push_back(nums[pointerRight++]);
            continue;
        }
        if(pointerRight>right){
            tempVector.push_back(nums[pointerLeft++]);
            continue;
        }
        if(nums[pointerLeft]<=nums[pointerRight]){
            tempVector.push_back(nums[pointerLeft++]);
        }else{
            tempVector.push_back(nums[pointerRight++]);
            //push的这个数比左侧所有没放的数都小，所以reversePairAmount不是加一
            reversePairAmount+=mid-pointerLeft+1;
        }
    }

    for(int i=0;i<tempVector.size();i++){
        nums[left+i]=tempVector[i];
    }

    return reversePairAmount;
}

long long CalculateReversePairAmount(vector<int>& nums,int left,int right){
    if(left>=right)return 0;
    int mid=(left+right)>>1;
    long long subReversePairAmount=0;
    subReversePairAmount+=CalculateReversePairAmount(nums,left,mid);
    subReversePairAmount+=CalculateReversePairAmount(nums,mid+1,right);
    subReversePairAmount+=Merge(nums,left,mid,right);
    return subReversePairAmount;
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
    cout<<CalculateReversePairAmount(nums,0,n-1);
    return 0;
}