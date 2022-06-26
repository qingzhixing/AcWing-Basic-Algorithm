#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> A,B;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        A.push_back(a);
    }
    for(int i=0;i<m;i++){
        int b;
        cin>>b;
        B.push_back(b);
    }
    int APointer=0,BPointer=0;
    while(BPointer<m&&APointer<n){
        if(A[APointer]==B[BPointer]){
            APointer++;
        }
        BPointer++;
    }
    if(APointer==n){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}