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
    return move(number);
}

string CharVectorToString(const vector<char>& number){
    string str;
    for(auto item:number){
        str=(char(item+'0'))+str;
    }
    return move(str);
}

vector<char> CharVectorAdd(const vector<char>& number1,const vector<char>& number2){
    vector<char> answer;
    int pointer=0;
    int carry=0;
    while(pointer<=number1.size()-1||pointer<=number2.size()-1){
        int digitSum=0;
        if(pointer<=number1.size()-1){
            digitSum+=number1[pointer];
        }
        if(pointer<=number2.size()-1){
            digitSum+=number2[pointer];
        }
        digitSum+=carry;
        carry=digitSum/10;
        digitSum%=10;
        answer.push_back(digitSum);
        pointer++;
    }
    if(carry){
        answer.push_back(carry);
        carry=0;
    }
    return move(answer);
}

int main(){
    vector<char> number1,number2;
    string str1,str2;
    cin>>str1>>str2;
    number1=StringToCharVector(str1);
    number2=StringToCharVector(str2);
    vector<char> answer=CharVectorAdd(number1,number2);

    //debug:
    // cout<<CharVectorToString(number1)<<endl;
    // cout<<CharVectorToString(number2)<<endl;

    string answerStr = CharVectorToString(answer);
    cout<<answerStr<<endl;
}