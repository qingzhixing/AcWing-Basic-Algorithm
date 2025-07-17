#include<iostream>
using namespace std;

#define MAX_N 100010
int n,nums[MAX_N];
bool isExist[MAX_N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    int head=1,tail=-1;
    int maxLen=0;
    while(tail<n){
        tail++;
        while(isExist[nums[tail]]&&head<tail){
            isExist[nums[head]]=false;
            head++;
        }
        isExist[nums[tail]]=true;
        maxLen=max(maxLen,tail-head+1);
    }
    cout<<maxLen<<endl;
    return 0;
}