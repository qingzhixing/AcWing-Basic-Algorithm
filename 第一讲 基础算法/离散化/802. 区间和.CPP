#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_N 300010
int n,m;
vector<int> positions;
vector<pair<int,int>> add,query;
int nums[MAX_N];//存储每个位置的值，值的下标为位置映射之后的值

//获取坐标经过映射之后的值
//也就是这个坐标在positions里的位置
int FindPositionAfterMap(int position){
    int l=0,r=positions.size()-1;
    while(l<r){
        int mid=(l+r)>>1;
        //最终positions[l]或者positions[r]会是第一个大于等于position的值
        if(positions[mid]>=position)r=mid;
        else l=mid+1;
    }
    //将得到的坐标加1以至于所有坐标映射成1~positions.size()之间的值
    //便于前缀和使用
    return r+1;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});
        positions.push_back(x);
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});
        positions.push_back(l);
        positions.push_back(r);
    }
    //去重
    sort(positions.begin(),positions.end());
    positions.erase(unique(positions.begin(),positions.end()),positions.end());

    for(auto item:add){
        int index=FindPositionAfterMap(item.first);
        nums[index]+=item.second;
    }
    //求前缀和,放在nums里
    for(int i=2;i<=positions.size();i++){
        nums[i]+=nums[i-1];
    }
    for(auto item:query){
        int l=FindPositionAfterMap(item.first);
        int r=FindPositionAfterMap(item.second);
        cout<<nums[r]-nums[l-1]<<endl;
    }
    return 0;
}