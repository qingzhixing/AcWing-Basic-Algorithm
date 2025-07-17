#include<iostream>
#include<vector>
using namespace std;

int Partition(vector<int>& nums,int left,int right){
    int i=left-1;
    int pivotNumber=nums[right];
    for(int j=left;j<=right-1;j++){
        if(nums[j]<=pivotNumber){
            swap(nums[++i],nums[j]);
        }
    }
    swap(nums[right],nums[++i]);
    return i;
}

void QuickSort(vector<int>& nums,int left,int right){
    if(left>=right)return;
    int pivotPointer=Partition(nums,left,right);
    QuickSort(nums,left,pivotPointer-1);
    QuickSort(nums,pivotPointer+1,right);
}

int main(){
    int n,k;
    vector<int> nums;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    QuickSort(nums,0,n-1);
    cout<<nums[k-1];
    return 0;
}