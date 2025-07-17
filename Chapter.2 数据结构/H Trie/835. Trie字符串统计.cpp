#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TrieNode{
    TrieNode* children[25];
    int count=0;
}root;

void Insert(const string& str){
    TrieNode* pointer=&root;
    for(auto item:str){
        if(pointer->children[item-'a']==nullptr){
            pointer->children[item-'a']=new TrieNode();
        }
        pointer=pointer->children[item-'a'];
    }
    pointer->count++;
}

int ExistTime(const string& str){
    TrieNode* pointer=&root;
    for(auto item:str){
        if(pointer->children[item-'a']==nullptr){
            return 0;
        }
        pointer=pointer->children[item-'a'];
    }
    return pointer->count;
}

int main(){
    int n;
    cin>>n;
    char command;
    string str;
    while(n--){
        cin>>command>>str;
        if(command=='I'){
            Insert(str);
        }
        else{
            cout<<ExistTime(str)<<endl;
        }
    }
    return 0;
}