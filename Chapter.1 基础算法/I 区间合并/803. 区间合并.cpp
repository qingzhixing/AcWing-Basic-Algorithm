#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Range{
    int left,right;
    bool operator<(const Range& other) const{
        return left < other.left||(left == other.right&&right < other.right);
    }
};

int main(){
    int n;
    cin>>n;
    vector<Range> ranges;
    for(int i = 0; i < n;i++){
        int l,r;
        cin>>l>>r;
        ranges.push_back({l,r});
    }
    sort(ranges.begin(), ranges.end());
    Range range = ranges[0];
    int ans=1;
    for(int i = 1; i < ranges.size();i++){
        Range& currentRange= ranges[i];
        if(range.left <= currentRange.left&&range.right>=currentRange.left){
            range.right=max(currentRange.right,range.right);
        }else{
            ans++;
            range=currentRange;
        }
    }
    cout<<ans<<endl;
    return 0;
}