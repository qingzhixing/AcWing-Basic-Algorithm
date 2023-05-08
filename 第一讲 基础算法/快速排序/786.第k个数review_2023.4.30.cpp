//  核心算法：三路快排
#include <iostream>
using std::cin;
using std::cout;
using std::make_pair;
using std::pair;
using std::swap;

#define MAX_N 100010
typedef pair<int, int> Board;
const Board emptyPair = make_pair(-1, -1);
int n, k;
int a[MAX_N];

bool CheckBoardEqualsTo(const Board &source, const Board &target)
{
    return source.first == target.first && source.second == target.second;
}

/*
    返回值：3个两个间隔元素下标
    Classify 将数组分为3个区域,对于a[k]:
        0<=k<return.first:a[k]<基准值
        return.first<=k<=return.right:a[k]=基准值
        return.second<k<=right:a[k]>基准值
*/
Board Classify(int left, int right)
{
    if (left > right)
        return emptyPair;

    // 默认最右边的为基准值
    // 基准值位置会变动所以不能取pivotIndex得提前取值
    int pivot = a[right];
    int pointer = left;
    // 中间区域左右边界:[leftBoard,rightBoard]
    int leftBoard = left, rightBoard = right + 1;
    while (pointer < rightBoard)
    {
        if (a[pointer] < pivot)
        {
            swap(a[pointer++], a[leftBoard++]);
            continue;
        }
        if (a[pointer] > pivot)
        {
            swap(a[pointer], a[--rightBoard]);
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
    Board board = Classify(left, right);
    if (CheckBoardEqualsTo(board, emptyPair))
        // TODO: 三路排序需要debug
        /*	return;
        if (k < board.first)
        {
            Solute(left, board.first - 1);
        }
        else if (k > board.second - 1)
        {
            Solute(board.second, right);
        }
        else
        {
            cout << a[k];
        }*/
        Solute(left, board.first - 1);
    Solute(board.second + 1, right);
}

int main()
{
    cin >> n >> k;
    k--; // 从0开始
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solute(0, n - 1);
    /*for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }*/
    cout << a[k];
    return 0;
}