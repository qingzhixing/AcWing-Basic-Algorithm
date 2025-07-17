/*
* https://www.acwing.com/problem/content/841/
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

//ph[i]=j意思是第i个插入的点在堆中编号为j
int ph[100010];
//hp[i]=j堆中编号为i的点是第j次插入的
int hp[100010];
//小根堆
template<class T>
class Heap
{
public:
	typedef T DataType;

public:

	Heap() :
		data(vector<DataType>(1)) {}
	Heap(const vector<DataType>& _data)
	{
		data = vector<DataType>(1);
		for (auto i : _data)
			Insert(i);
	}
	Heap(const Heap<T>& _instance)
	{
		data.assign(_instance.data.begin(), _instance.data.end());
	}

public:
	void Insert(DataType v)
	{
		data.push_back(v);
		Up(data.size() - 1);
	}
	void Pop()
	{
		HeapSwap(1, data.size() - 1);
		data.pop_back();
		Down(1);
	}
	DataType Top()
	{
		return data[1];
	}
	//删除编号为x的数，编号非法则不操作
	void Erase(int x)
	{
		if (x > data.size() - 1)return;
		HeapSwap(data.size() - 1, x);
		data.pop_back();
		Down(x);
		Up(x);
	}
	//将编号为x的数的值改为d
	void Change(int x, DataType d)
	{
		if (x > data.size() - 1)return;
		data[x] = d;
		Down(x);
		Up(x);
	}
	void HeapSwap(int x, int y)
	{
		swap(data[x], data[y]);
		swap(ph[hp[x]], ph[hp[y]]);
		swap(hp[x], hp[y]);
	}
	int Size()
	{
		return data.size();
	}
protected:

private:
	vector<DataType> data;
private:
	//将编号为x的点向上调整
	void Up(int x)
	{
		while (x > 1 && x / 2 >= 1 &&data[x] < data[x / 2])
		{
			HeapSwap(x / 2, x);
			x /= 2;
		}
	}
	//将编号为x的点向下调整
	void Down(int x)
	{

		//无左右子节点
		if (2 * x > data.size() - 1)
			return;
		//无右节点
		if (2 * x + 1 > data.size() - 1)
		{
			if (data[x] > data[2 * x])
				HeapSwap(x, 2 * x);
			else return;
			Down(x * 2);
		}
		else
		{
			int Min = data[2 * x] > data[2 * x + 1] ? 2 * x + 1 : 2 * x;
			if (data[x] < data[Min])
				return;
			HeapSwap(x, Min);
			Down(Min);
		}
	}
};


void Solution()
{
	int n;
	Heap<int> heap;
	cin >> n;
	int cnt = 0;
	while (n--)
	{
		string command;
		cin >> command;
		if (command == "I")
		{
			int x;
			cin >> x; 
			cnt++;
			ph[cnt] = heap.Size();
			hp[heap.Size()] = cnt;
			heap.Insert(x);
		}
		else if (command == "PM")
		{
			cout << heap.Top() << endl;
		}
		else if (command == "DM")
		{
			heap.Pop();
		}
		else if (command == "D")
		{
			int k;
			cin >> k;
			heap.Erase(ph[k]);
		}
		else
		{
			int k, x;
			cin >> k >> x;
			heap.Change(ph[k], x);
		}
	}
}
int main()
{
	Solution();
	return 0;
}