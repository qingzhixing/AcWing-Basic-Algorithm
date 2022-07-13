// #include<iostream>
// #include<string>
// using namespace std;

// #define MAX_N 100010

// int s_len,p_len;
// string s,p;
// int prefixArray[MAX_N];

// int main(){
//     cin>>p_len>>p;
//     cin>>s_len>>s;

//     //构建前缀数组
//     prefixArray[0]=0;
//     //j指向相同前缀中第一个前缀的最后一个字符
//     for(int i=1,j=0;i<p_len;i++){
//         //若无法继续在长度为j的前缀中扩展前缀，则j逐级缩小直到能扩展为止
//         while(j&&p[i]!=p[j-1+1])j=prefixArray[j];
//         //能扩展则j++
//         if(p[i]==p[j-1+1])j++;
//         prefixArray[i]=j;
//     }


//     //test prefixArray
//     for(int i=0;i<p_len;i++){
//         cout<<prefixArray[i]<<' ';
//     }
//     puts("");

//     kmp匹配
//     for(int p_ptr=0,s_ptr=0;s_ptr<s_len;s_ptr++){

//         if(p[p_ptr]==s[s_ptr]){
//             p_ptr++;
//             if(p_ptr==p_len){
//                 cout<<s_ptr-p_len+1<<' ';
//                 puts("");
//             }
//         }else{
//             while(p_ptr&&p[p_ptr+1]!=s[s_ptr]){
//                 printf("p_ptr turned form %d to %d\n",p_ptr,prefixArray[p_ptr]);
//                 p_ptr=prefixArray[p_ptr];
//             }
//         }

//         printf("s_ptr=%d , p_str=%d\n",s_ptr,p_ptr);
//     }
	
//     return 0;
// }

/*
* https://www.acwing.com/problem/content/833/
*/
#include<vector>
#include <iostream>
#include <algorithm>
#include<stack>
using std::vector;
using std::cin;
using std::cout;
using std::endl;

const int N = 100010;
const int M = 1000010;
char p[N], s[M];
int n, m;
void Solution()
{
	cin >> n >> p + 1 >> m >> s + 1;

	//p的 next数组，next[i]=j时，表示p[1~j]=p[(i-j)~i]
	int next[N] = {};

	//求p的next数组
	for (int i = 2, j = 0; i<=n;i++)
	{
		while (j && p[j + 1] != p[i])j = next[j];
		if (p[i] == p[j + 1])j++;
		next[i] = j;
	}

	//kmp匹配
	for (int i = 1, j = 0; i <= m; i++)
	{
		while (j && p[j + 1] != s[i])j = next[j];
		if (p[j + 1] == s[i])j++;
		if (j == n)
		{
			cout << (i - n + 1) - 1 << ' ';
		}
	}
}
int main()
{
	Solution();
	return 0;
}