#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    stack<int> monotonousStack;
    for(int i=0; i<n;i++){
        int x;
        cin>>x;

        while(monotonousStack.size()&&monotonousStack.top()>=x){
            monotonousStack.pop();
        }

        if(monotonousStack.empty()){
            cout<<"-1"<<' ';
        }else{
            cout<<monotonousStack.top()<<' ';
        }
        monotonousStack.push(x);
    }
    return 0;
}