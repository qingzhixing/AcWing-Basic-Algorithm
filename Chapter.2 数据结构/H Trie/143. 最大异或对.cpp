#include<iostream>
#include<vector>
using namespace std;
struct TrieNode{
    TrieNode* children[2];
    bool isEnd;
    TrieNode(){
        children[0] = children[1] = nullptr;
        isEnd = false;
    }
}root;

void Insert(int number){
    TrieNode* cur = &root;
    for(int i = 30; i >= 0; i--){
        int bit = (number >> i) & 1;
        if(cur->children[bit] == nullptr){
            cur->children[bit] = new TrieNode();
        }
        cur = cur->children[bit];
    }
    cur->isEnd = true;
}
int FindMaxXorNumber(int number){
    //思路:从高位往低位查询，如果当前位为0，则查询1，
    //如果当前位为1，则查询0，如果查询到的节点为空，
    //则说明不存在，该数字的最大异或数字当前位和当前数字当前位相同。
    int result=0;
    TrieNode* cur = &root;
    for(int i = 30; i >= 0; i--){
        int currentBit = (number >> i) & 1;
        if(cur->children[!currentBit] != nullptr){
            result += ((!currentBit) << i);
            cur = cur->children[!currentBit];
        }else{
            result += ((currentBit) << i);
            cur = cur->children[currentBit];
        }
    }
    return result;
}
int main(){
    int n;
    cin>>n;
    vector<int> numbers;
    for(int i = 0; i < n; i++){
        int number;
        cin>>number;
        numbers.push_back(number);
        Insert(number);
    }
    int result=0;
    for(auto item:numbers){
        result = max(result,item ^ FindMaxXorNumber(item));
    }
    cout<<result<<endl;
    return 0;
}