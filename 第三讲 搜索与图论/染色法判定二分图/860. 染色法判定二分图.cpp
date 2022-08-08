#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX_N 100010

enum Color{
    WHITE,
    BLACK,
    EMPTY
};

Color ReverseColor(Color color){
    if(color == WHITE)
        return BLACK;
    else if(color == BLACK)
        return WHITE;
    else
        return EMPTY;
}

vector<int> edges[MAX_N];
Color color[MAX_N];
int n, m;

bool BFSDye(int startId){
    queue<int> q;
    q.push(startId);
    color[startId] = BLACK;

    while(q.size()){
        int currentNode=q.front();
        q.pop();

        for(auto next:edges[currentNode]){
            if(color[next] == EMPTY){
                color[next] = ReverseColor(color[currentNode]);
                q.push(next);
            }
            else if(color[next] == color[currentNode]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    //init color
    for(int i = 1; i <= n; i++){
        color[i] = EMPTY;
    }
    
    for(int i = 1; i <= n; i++){
        if(color[i] == EMPTY){
            if(!BFSDye(i)){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}