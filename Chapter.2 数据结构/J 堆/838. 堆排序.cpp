#include<iostream>
using namespace std;

#define MAX_N 100010
#define LEFT_SON(i) (i<<1)
#define RIGHT_SON(i) (i<<1|1)
#define FATHER(i) (i>>1)

int heap[MAX_N];
//最后一个节点位置
int cnt;
int n,m;

void MoveUp(int id){
    while(id>1&&heap[id]<heap[FATHER(id)]){
        swap(heap[id],heap[FATHER(id)]);
        id=FATHER(id);  
    }
}

void MoveDown(int id){
    while(id<cnt){
        //判断有无子节点
        if(LEFT_SON(id)>cnt)break;
        //判断是否有右子节点，有则判断是否当前节点比右子节点小，
        //小则与左子节点比较，谁小谁是左子节点，比右子节点大则交换当前节点与右子节点
        if(RIGHT_SON(id)>cnt){
            if(heap[id]>heap[LEFT_SON(id)]){
                swap(heap[id],heap[LEFT_SON(id)]);
                id=LEFT_SON(id);
            }else break;
        }else{
            //二者选择小的与当前节点比较
            int minorId=LEFT_SON(id);
            if(heap[minorId]>heap[RIGHT_SON(id)]){
                minorId=RIGHT_SON(id);
            }
            if(heap[id]>heap[minorId]){
                swap(heap[id],heap[minorId]);
                id=minorId;
            }else break;
        }
    }
}

void Insert(int number){
    heap[++cnt]=number;
    MoveUp(cnt);
}

int Top(){
    return heap[1];
}

void Pop(){
    swap(heap[1],heap[cnt--]);
    MoveDown(1);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        Insert(x);
        // puts("DEBUG");
        // for(int i=1;i<=cnt;i++){
        //     cout<<heap[i]<<" ";
        // }
        // puts("");
    }
    for(int i=1;i<=m;i++){
        cout<<Top()<<' ';
        Pop();
    }
    return 0;
}