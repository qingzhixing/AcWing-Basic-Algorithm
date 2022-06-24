#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<char> StringToCharVector(const string& str){

}

string CharVectorToString(const vector<char>& number){

}

vector<char> CharVectorAdd(const vector<char>& number1,const vector<char>& number2){
    
}

int main(){
    vector<char> number1,number2;
    string str1,str2;
    cin>>str1>>str2;
    number1=StringToCharVector(str1);
    number2=StringToCharVector(str2);
    string answer = CharVectorToString(CharVectorAdd(number1,number2));
    cout<<answer<<endl;
}