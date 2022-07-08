#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main(){
    int n,windowLength;
    vector<int> nums;
    cin>>n>>windowLength;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }

    /*
    * Q1:
    * monotonousQueue用于维护数字的编号，
    * 维护的数据具有依次增大，并且数据对应的值依次增大的特征。
    */
    deque<int> monotonousQueue;

    for(int i=0;i<n;i++){
        //此时nums[i]是检查入队的元素

        //判断窗口左端点越过队首的情况
        if(monotonousQueue.size()&&
        monotonousQueue.front()<(i-windowLength+1)){
            monotonousQueue.pop_front();
        }

        //判断即将入队的元素是否比队尾小，小则弹出队尾，直到最后入队，维护单调性
        while(monotonousQueue.size()&&
        nums[monotonousQueue.back()]>nums[i]){
            monotonousQueue.pop_back();
        }

        monotonousQueue.push_back(i);

        if((i+1)>=windowLength)cout<<nums[monotonousQueue.front()]<<' ';
    }

    /*
    * Q2:
    * monotonousQueue此时用于维护数字的编号，
    * 维护的数据有依次增大，对应数据依次减小的特征。
    */
    monotonousQueue.clear();
    puts("");

    for(int i=0;i<n;i++){
        //此时nums[i]入队
        //判断队首越界情况
        if(monotonousQueue.size()&&
        monotonousQueue.front()<(i-windowLength+1)){
            monotonousQueue.pop_front();
        }

        //判断入队元素是否比队尾大，是则一直弹出直到入队元素小于等于队尾，维护单调性
        while(monotonousQueue.size()&&
        nums[monotonousQueue.back()]<nums[i]){
            monotonousQueue.pop_back();
        }

        monotonousQueue.push_back(i);

        if((i+1)>=windowLength)cout<<nums[monotonousQueue.front()]<<' ';
    }

    return 0;
}