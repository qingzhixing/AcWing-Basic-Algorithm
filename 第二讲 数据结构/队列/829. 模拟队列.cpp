#include<iostream>
#include<string>
using namespace std;
#define MAX_N 100010

int queue[MAX_N];
int head=0,tail=-1;

void Push(int x){
    queue[++tail]=x;
}

void Pop(){
    head++;
}

bool Empty(){
    return tail<head;
}

int Top(){
    return queue[head];
}

int main(){
    int m;
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
        if(command=="query"){
            cout<<Top()<<endl;
            continue;
        }
        if(command=="empty"){
            cout<<(Empty()?"YES":"NO")<<endl;
            continue;
        }
    }
}