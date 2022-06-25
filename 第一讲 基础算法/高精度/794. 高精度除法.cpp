#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include <algorithm>
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

//返回商与余数
pair<CharVec,int> CharVectorDevidInteger(const CharVec& number,int dividend){
    CharVec result;
    bool notFirstZero=false;
    int remainder=0;
    for(int i=number.size()-1;i>=0;i--){
        remainder=remainder*10+number[i];
        int digit=remainder/dividend;
        if(digit!=0){
            notFirstZero=true;
        }
        if(notFirstZero){
            result.push_back(digit);
        }
        remainder%=dividend;
    }
    if(result.size()==0)result.push_back(0);
    //商高位在前，要转换成高位在后的格式，故需要反转
    reverse(result.begin(),result.end());
    return pair<CharVec,int>(move(result),remainder);
}

int main(){
    string numberStr;
    int dividend;
    cin>>numberStr>>dividend;
    CharVec number=StringToCharVector(numberStr);
    pair<CharVec,int> result=CharVectorDevidInteger(number,dividend);
    cout<<CharVectorToString(result.first)<<endl<<result.second<<endl;
    return 0;
}