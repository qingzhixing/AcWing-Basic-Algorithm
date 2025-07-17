#include<iostream>
#include<string>
#include<climits>
using namespace std;
#define HASH_SIZE ULLONG_MAX 
#define NUMBER_SYSTEM 131
#define MAX_N 100010

int n,m;
//记录已经计算过的hash值
unsigned long long hashValue[MAX_N];
//进制数的阶乘
unsigned long long systemPow[MAX_N];
string str;

//index: 0~(str.size()-1)
unsigned long long CalculatePrefixHash(int index){
    if(index<0)return 0;
    //数组下标从1开始存储
    int arrayIndex=index+1;
    if(hashValue[arrayIndex]!=0){
        return hashValue[arrayIndex];
    }else if(index==0){
        hashValue[arrayIndex]=str[index]-'0'+1;
        return hashValue[arrayIndex];
    }
    unsigned long long hash=0;
    hash=CalculatePrefixHash(index-1)*NUMBER_SYSTEM+str[index]-'0'+1;
    hashValue[arrayIndex]=hash;
    return hash;
}

unsigned long long CalculateSystemPow(int value){
    if(systemPow[value]!=0){
        return systemPow[value];
    }else if(value==0){
        systemPow[value]=1;
        return 1;
    }
    systemPow[value]=CalculateSystemPow(value-1)*NUMBER_SYSTEM;
    return systemPow[value];
}

unsigned long long CalculateRangeHash(int start,int end){
    return CalculatePrefixHash(end)-CalculatePrefixHash(start-1)*CalculateSystemPow(end-start+1);
}

int main(){
    cin>>n>>m;
    cin>>str;
    while(m--){
        int start1,end1,start2,end2;
        cin>>start1>>end1>>start2>>end2;
        //将编号从1开始转化为从0开始
        start1--;
        end1--;
        start2--;
        end2--;

        unsigned long long hash1=CalculateRangeHash(start1,end1);
        unsigned long long hash2=CalculateRangeHash(start2,end2);
        cout<<(hash1==hash2?"Yes":"No")<<endl;
    }

    // //DEBUG:
    // for(int i=0;i<n;i++){
    //     cout<<CalculatePrefixHash(i)<<endl;
    // }
    return 0;
}