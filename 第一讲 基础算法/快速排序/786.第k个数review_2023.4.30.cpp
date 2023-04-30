#include <iostream>
#include <utility>
using namespace std;

#define MAX_N int(1e9 + 10)
const pair<int, int> emptyPair = make_pair(-1, -1);
int n, k;
int a[MAX_N];

/*
    返回值：3个两个间隔元素下标
    Classify 将数组分为3个区域,对于a[k]:
        0<=k<return.first:a[k]<基准值
        return.first<=k<=return.right:a[k]=基准值
        return.second<k<=right:a[k]>基准值
*/
pair<int, int> Classify(int left, int right)
{
    if (left > right)
        return emptyPair;

    // 默认最右边的为基准值
    int pivotIndex = right;
    int pointer = left;
    // 中间区域左右边界:[leftBoard,rightBoard]
    int leftBoard = left, rightBoard = right + 1;
    while (pointer < rightBoard)
    {
        if (a[pointer] < a[pivotIndex])
        {
            swap(a[pivotIndex++], a[leftBoard++]);
            continue;
        }
        if (a[pointer] > a[pivotIndex])
        {
            swap(a[pivotIndex++], a[--rightBoard]);
            continue;
        }
        pointer++;
    }
    return make_pair(leftBoard, rightBoard);
}

void Solute(int left, int right)
{
    if (left >= right)
        return;
    pair<int, int> board = Classify(left, right);
    if (board == emptyPair)
        return;
    if (k < board.first)
    {
        Solute(left, board.first - 1);
    }
    else if (k > board.second)
    {
        Solute(board.second + 1, right);
    }
    else
    {
        cout << a[k];
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solute(0, n - 1);
    return 0;
}