#include<iostream>
#include<string>
using namespace std;
#define MAX_N 100010

int m;
int stack[MAX_N],top=-1;

void Push(int x){
    stack[++top]=x;
}

void Pop(){
    top--;
}

bool Empty(){
    return top==-1;
}

int Top(){
    return stack[top];
}

int main(){
    cin>>m;
    while(m--){
        string command;
        cin>>command;
        if(command=="push"){
            int x;
            cin>>x;
            Push(x);
            continue;
        }
        if(command=="pop"){
            Pop();
            continue;
        }
        if(command=="empty"){
            cout<<(Empty()?"YES":"NO")<<endl;
            continue;
        }
        if(command=="query"){
            cout<<Top()<<endl;
        }
    }
    return 0;
}