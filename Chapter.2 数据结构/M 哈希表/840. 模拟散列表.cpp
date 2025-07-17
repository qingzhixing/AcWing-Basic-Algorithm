#include<iostream>
using namespace std;
#define MAX_N 100010
#define HASH_SIZE 100010
struct Node{
    int value;
    Node* next;
};
Node *hashTable[HASH_SIZE];

void PrintList(int hash){
    Node* pointer = hashTable[hash];
    while(pointer != nullptr){
        cout << pointer->value << " ";
        pointer = pointer->next;
    }
    puts("");
}

int CalculateHash(int value){
    return abs(value) % HASH_SIZE;
}

void Insert(int value){
    int hash = CalculateHash(value);
    Node* pointer = hashTable[hash];
    if(pointer == nullptr){
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;
        hashTable[hash] = newNode;
        return;
    }
    while(pointer->next != nullptr){
        if(pointer->next->value == value){
            return;
        }
        pointer = pointer->next;
    }
    pointer->next = new Node({value, nullptr});
}

bool IsExist(int value){
    int hash = CalculateHash(value);
    Node* pointer=hashTable[hash];
    while(pointer!=nullptr){
        if(pointer->value==value){
            return true;
        }
        pointer=pointer->next;
    }
    return false;
}

int n;
int main(){
    cin>>n;
    while(n--){
        char command;
        int value;
        cin>>command>>value;
        switch(command){
            case 'I':{
                Insert(value);
                break;
            }
            case 'Q':{
                cout<<(IsExist(value)?"Yes":"No")<<endl;
                break;
            }
        }
    }
    return 0;
}
