// TODO:啥玩意？这啥错？怎么改？
/* TODO: ERR:
    No valid executable file was produced by the compiler
    ./ccdpll8r.o: in function `__static_initialization_and_destruction_0(int, int)':
    src:(.text+0x2f4): relocation truncated to fit: R_X86_64_PC32 against `.bss'
    src:(.text+0x30d): relocation truncated to fit: R_X86_64_PC32 against `.bss'
    collect2: 错误：ld 返回 1
*/
//  核心算法：三路快排
#include <iostream>
using std::cin;
using std::cout;
using std::make_pair;
using std::pair;
using std::swap;

#define MAX_N 1000000010
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
    Board board = Classify(left, right);
    if (CheckBoardEqualsTo(board, emptyPair))
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