#include<iostream>
#include<vector>
using namespace std;

void QuickSort(vector<int>& nums,int left,int right){
    if(left>=right)return;

    int pointerLeft=left-1;
    int pointerRight=right+1;
    int midNum=nums[(left+right)/2];
    while(pointerLeft<pointerRight){
        do pointerLeft++;while(nums[pointerLeft]<midNum);
        do pointerRight--;while(nums[pointerRight]>midNum);
        if(pointerLeft<pointerRight){
            swap(nums[pointerLeft],nums[pointerRight]);
        }
    }
    QuickSort(nums,left,pointerRight);
    QuickSort(nums,pointerRight+1,right);
}

int main(){
    vector<int> nums;
    int numAmount=0;
    cin>>numAmount;
    for(int i=1;i<=numAmount;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    QuickSort(nums,0,numAmount-1);
    for(auto item:nums){
        cout<<item<<' ';
    }
    return 0;
}