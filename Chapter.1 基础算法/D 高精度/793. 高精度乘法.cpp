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

//copied from 791. 高精度加法.cpp
CharVec CharVectorMultipleInteger(const CharVec& number,int multiple){
    int carry=0;
    CharVec result;
    for(int i=0;i<number.size();i++){
        int temp=number[i]*multiple+carry;
        carry=temp/10;
        result.push_back(temp%10);
    }
    while(carry){
        result.push_back(carry%10);
        carry/=10;
    }
    //去除前导0
    while(result.size()>1&&result.back()==0){
        result.pop_back();
    }
    return move(result);
}

int main(){
    string numberStr;
    int multiple;
    cin>>numberStr>>multiple;
    CharVec number=StringToCharVector(numberStr);
    CharVec result=CharVectorMultipleInteger(number,multiple);
    cout<<CharVectorToString(result)<<endl;
    return 0;
}