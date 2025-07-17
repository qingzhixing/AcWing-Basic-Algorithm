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

CharVec CharVectorMinus(const CharVec& number1,const CharVec& number2){
    const CharVec* greater=nullptr;
    const CharVec* less=nullptr;
    //比大小
    if(number1.size()>number2.size()){
        greater=&number1;
        less=&number2;
    }else if(number1.size()<number2.size()){
        greater=&number2;
        less=&number1;
    }else{
        for(int i=number1.size()-1;i>=0;i--){
            if(number1[i]>number2[i]){
                greater=&number1;
                less=&number2;
                break;
            }else if(number1[i]<number2[i]){
                greater=&number2;
                less=&number1;
                break;
            }
        }
    }
    if(greater==nullptr||less==nullptr){
        return CharVec(1,0);
    }
    CharVec result;
    int borrow=0;
    int pointer=0;
    while(pointer<greater->size()){
        int digit=0;
        if(pointer>less->size()-1){
            digit=greater->at(pointer)-borrow;
            borrow=0;
            if(digit<0){
                digit+=10;
                borrow=1;
            }
            result.push_back(digit%10);
        }else{
            digit=greater->at(pointer)-(less->at(pointer))-borrow;
            borrow=0;
            if(digit<0){
                digit+=10;
                borrow=1;
            }
            result.push_back(digit%10);
        }
        pointer++;
    }
    //处理高位0
    while(result.size()>1&&result.back()==0){
        result.pop_back();
    }
    if(greater!=&number1){
        result.push_back('-'-'0');//打印函数自动+'0'补成'-'
    }
    return move(result);
}

int main(){
    CharVec number1,number2;
    string str1,str2;
    cin>>str1>>str2;
    number1=StringToCharVector(str1);
    number2=StringToCharVector(str2);
    CharVec answer=CharVectorMinus(number1,number2);
    cout<<CharVectorToString(answer)<<endl;
    return 0;
}