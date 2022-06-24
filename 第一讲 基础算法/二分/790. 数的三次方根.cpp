#include<iostream>
using namespace std;

inline double CalculateThird(double number){
    return number*number*number;
}

int main(){
    double n;
    double answer;
    cin>>n;
    double left=-1e9,right=1e9;
    for(int i=1;i<=1000;i++){
        double mid=(left+right)/2;
        if(CalculateThird(mid)>=n){
            right=mid;
        }else{
            left=mid;
        }
    }
    printf("%.6f",left);
}