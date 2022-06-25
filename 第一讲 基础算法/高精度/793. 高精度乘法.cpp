#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef vector<char> CharVec;

//Char vector从右往左读string,高位在末尾
CharVec StringToCharVector(const string& str){
    CharVec number;
    for(int i=str.size()-1;i>=0;i--){
        number.push_back(str[i]-'0');
    }
    if(number.size()==0)number.push_back(0);
    return move(number);
}

string CharVectorToString(const CharVec& number){
    string str;
    for(auto item:number){
        str=(char(item+'0'))+str;
    }
    return move(str);
}