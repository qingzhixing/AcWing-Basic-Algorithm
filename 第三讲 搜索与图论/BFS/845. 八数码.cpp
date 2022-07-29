#include<iostream>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
using namespace std;

struct Node{
    string state;
    int step;
};

const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
const string correct="12345678x";

inline pair<int,int> NumberTo3x3Coord(int index){
    return make_pair(index/3,index%3);
}

inline int Coord3x3ToNumber(const pair<int,int>& coord){
    return coord.first*3+coord.second;
}

int main(){
    string str;
    char ch;
    for(int i=0;i<9;i++){
        cin>>ch;
        str+=ch;
    }
    queue<Node> q;
    unordered_map<string,bool> isExist;
    q.push({str,0});
    isExist[str]=true;

    while(q.size()){
        Node currentNode=q.front();
        q.pop();
        string &currentState=currentNode.state;
        int &currentStep=currentNode.step;
        if(currentState==correct){
            cout<<currentStep<<endl;
            return 0;
        }
        int index=currentState.find('x');
        auto coord=NumberTo3x3Coord(index);

        for(int direction=0;direction<4;direction++){
            int nextX=coord.first+dx[direction];
            int nextY=coord.second+dy[direction];
            if(nextX<0||nextX>=3||nextY<0||nextY>=3){
                continue;
            }
            int nextIndex=Coord3x3ToNumber(make_pair(nextX,nextY));
            string nextState=currentState;
            swap(nextState[index],nextState[nextIndex]);
            if(isExist[nextState]){
                continue;
            }
            isExist[nextState]=true;
            q.push({nextState,currentStep+1});
        }
    }
    cout<<-1<<endl;
    return 0;
}