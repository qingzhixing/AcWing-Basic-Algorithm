#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Char vector从右往左读string,高位在末尾
vector<char> StringToCharVector(const string& str){
    vector<char> number;
    for(int i=str.size()-1;i>=0;i--){
        number.push_back(str[i]-'0');
    }
    if(number.size()==0)number.push_back(0);
    return move(number);
}

string CharVectorToString(const vector<char>& number){
    string str;
    for(auto item:number){
        str=(char(item+'0'))+str;
    }
    return move(str);
}

vector<char> CharVectorMinus(const vector<char>& number1,const vector<char>& number2){
    const vector<char>* greater=nullptr;
    const vector<char>* less=nullptr;
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
        return vector<char>(1,0);
    }
    vector<char> result;
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
    vector<char> number1,number2;
    string str1,str2;
    cin>>str1>>str2;
    number1=StringToCharVector(str1);
    number2=StringToCharVector(str2);
    vector<char> answer=CharVectorMinus(number1,number2);
    cout<<CharVectorToString(answer)<<endl;
    return 0;
}