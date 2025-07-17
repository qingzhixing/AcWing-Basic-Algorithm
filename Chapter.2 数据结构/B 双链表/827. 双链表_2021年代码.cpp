#include <iostream>
using namespace std;

const int MAX_N = 100010;

//数组模拟双链表
int value[MAX_N], l[MAX_N], r[MAX_N], cnt;

//在x节点后插入一个值为k的节点
void AddNext(int x, int k)
{
	value[++cnt] = k;
	r[cnt] = r[x];
	l[r[x]] = cnt;
	r[x] = cnt;
	l[cnt] = x;
}

//移除x节点
void Delete(int x)
{
	r[l[x]] = r[x];
	l[r[x]] = l[x];
}
int main()
{
    //定义0为头节点1为尾节点
	r[0] = 1;
	l[1] = 0;
	cnt = 1;
	int m;
	cin >> m;
	while (m)
	{
		m--;
		char command;
		cin >> command;
		switch (command)
		{
		case 'L':
		{
			int x;
			cin >> x;
			AddNext(0, x);
			break;
		}
		case 'R':
		{
			int x;
			cin >> x;
			AddNext(l[1], x);
			break;
		}
		case 'D':
		{
			int x;
			cin >> x;
			Delete(x + 1);
			break;
		}
		case 'I':
		{
			switch (getchar())
			{
			case 'L':
			{
				int x, v;
				cin >> x >> v;
				AddNext(l[x + 1], v);
				break;
			}
			case 'R':
			{
				int x, v;
				cin >> x >> v;
				AddNext(x + 1, v);
				break;
			}
			default:
				break;
			}
			break;
		}
		}
	}
	int ptr = 0;
	while (r[ptr] != 1)
	{
		ptr = r[ptr];
		cout << value[ptr] << ' ';
	}
	return 0;
}