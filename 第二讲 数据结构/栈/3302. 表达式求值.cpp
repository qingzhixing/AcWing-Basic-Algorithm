#include<iostream>
#include<stack>
#include <unordered_map>
#include<string>
using namespace std;

stack<int> numberStack;
stack<char> operatorStack;
//映射的数组越大优先级越高
unordered_map<char,int> priority={{'-',1},{'+',1},{'*',2},{'/',2}};

void CalculateTopTwoNumber(){
    //先入的后出
    int number2=numberStack.top();
    numberStack.pop();
    int number1=numberStack.top();
    numberStack.pop();
    char op=operatorStack.top();
    operatorStack.pop();
    int answer=0;
    switch(op){
        case '+': answer=number1+number2; break;
        case '-': answer=number1-number2; break;
        case '*': answer=number1*number2; break;
        case '/': answer=number1/number2; break;
    }
    numberStack.push(answer);
}

int main(){
    string expression;
    cin>>expression;
    for(int i=0;i<expression.length();i++){
        char c=expression[i];
        if(isdigit(c)){
            	//双指针读入数字
			int x = 0, j = i;
			while (j < expression.size() && isdigit(expression[j]))
				x = x * 10 + expression[j++] - '0';
			numberStack.push(x);
			i = j - 1;
            continue;
        }
        if(c=='('){
            operatorStack.push(c);
            continue;
        }
        if(c==')'){
            while(operatorStack.top()!='('){
                CalculateTopTwoNumber();
            }
            operatorStack.pop();
            continue;
        }
        //运算符优先级下行或者同级则可以进行运算
        while(operatorStack.size()&&operatorStack.top()!='('&&
        priority[operatorStack.top()]>=priority[c]){
            CalculateTopTwoNumber();
        }
        operatorStack.push(c);
    }
    while(operatorStack.size())CalculateTopTwoNumber();
    cout<<numberStack.top()<<endl;
    return 0;
}