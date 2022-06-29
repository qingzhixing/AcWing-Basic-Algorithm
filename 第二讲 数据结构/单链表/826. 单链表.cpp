#include<iostream>
using namespace std;
#define MAX_N 100010
struct Node{
    int data;
    int next;
};

Node list[MAX_N];
int cnt=-1;//最后一个插入的节点的位置
int head=-1;

int main(){
    int m;
    cin>>m;
    while(m--){
        char ch;
        cin>>ch;
        switch (ch)
        {
            case 'H':{
                int value;
                cin>>value;
                list[++cnt]={value,head};
                head=cnt;
                break;
            }
            case 'D':{
                int value;
                cin>>value;
                if(value==0){
                    head=list[head].next;
                }else{
                    list[value-1].next=list[list[value-1].next].next;
                }
                break;
            }
            case 'I':{
                int k,value;
                cin>>k>>value;
                list[++cnt]={value,list[k-1].next};
                list[k-1].next=cnt;
                break;
            }
        }
    }
    for(int pointer=head;pointer!=-1;pointer=list[pointer].next){
        cout<<list[pointer].data<<' ';
    }
    return 0;
}