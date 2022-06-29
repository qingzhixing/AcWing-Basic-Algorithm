//TODO:DEBUG!!!
#include<iostream>
using namespace std;
#define MAX_N (10010+2)
struct Node{
    int value;
    int front;
    int next;
}nodes[MAX_N];
int head=0,tail=1;//虚拟头尾节点
int cnt=tail;//最后一个节点位置

inline int GetKthInsertedNumberIndex(int k){
    return k+1;
}

void AddNext(int k,int x){
    nodes[++cnt]={x,k,nodes[k].next};
    nodes[k].next=cnt;
    nodes[nodes[k].next].front=cnt;
}

void Delete(int k){
    nodes[nodes[k].next].front=nodes[k].front;
    nodes[nodes[k].front].next=nodes[k].next;
}

int main(){
    int m;
    cin>>m;
    //初始化头尾节点
    nodes[head].front=nodes[tail].next=-1;
    nodes[head].next=tail;
    nodes[tail].front=head;
    while(m--){
        char command;
        cin>>command;
        switch(command){
            case 'L':{
                int value;
                cin>>value;
                AddNext(head,value);
                break;
            }
            case 'R':{
                int value;
                cin>>value;
                AddNext(nodes[tail].front,value);
                break;
            }
            case 'D':{
                int k;
                cin>>k;
                int index=GetKthInsertedNumberIndex(k);
                Delete(index);
                break;
            }
            case 'I':{
                char ch;
                cin>>ch;
                switch(ch){
                    case 'L':{
                        int k,value;
                        cin>>k>>value;
                        int index=GetKthInsertedNumberIndex(k);
                        AddNext(nodes[index].front,value);
                        break;
                    }
                    case 'R':{
                        int k,value;
                        cin>>k>>value;
                        int index=GetKthInsertedNumberIndex(k);
                        AddNext(index,value);
                        break;
                    }
                }
                break;
            }
        }
    }
    for(int pointer=nodes[head].next;pointer!=1;pointer=nodes[pointer].next){
        cout<<nodes[pointer].value<<' ';
    }
    return 0;
}