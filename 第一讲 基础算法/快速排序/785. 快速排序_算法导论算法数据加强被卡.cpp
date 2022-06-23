#include<iostream>
#include<vector>
#include<random>
#include<time.h>
using namespace std;

int Partition(vector<int>& nums,int left,int right){
    //pivotPointer=right;
    int pivotNumber=nums[right];
    int i=left-1;
    for(int j=left;j<=right-1;j++){
        if(nums[j]<=pivotNumber){
            swap(nums[j],nums[++i]);
        }
    }
    //将pivotNumber放在left~i,i+1~right-1之间
    swap(nums[++i],nums[right]);
    //现在pivotNumber在nums[i];
    return i;
}

void QuickSort(vector<int>& nums,int left,int right){
    if(left>=right)return;
    /*
        调用Partition后数组满足：
        对于任意数组下标k，有：
        1.若 left <= k < pivotPointer,则nums[k] <= nums[pivotPointer]
        2.若 pivotPointer < k <= right,则nums[k] > nums[pivotPointer]
    */
    int pivotPointer=Partition(nums,left,right);
    QuickSort(nums,left,pivotPointer-1);
    QuickSort(nums,pivotPointer+1,right);
}

int main(){
    ios::sync_with_stdio (false);
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