#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        int binaryOneCounter=0;
        while(num){
            binaryOneCounter+=num&1;
            num>>=1;
        }
        cout<<binaryOneCounter<<' ';
    }
}