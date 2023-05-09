#include <iostream>
using namespace std;
#define MAX_N 100010

int n, q, a[MAX_N];

int FindFirstMoreOrEqual(int target)
{
    int leftPointer = 0;
    int rightPointer = n - 1;
    while (leftPointer < rightPointer)
    {
        int mid = (leftPointer + rightPointer) >> 1;
        if (a[mid] < target)
        {
            leftPointer = mid + 1;
        }
        else
        {
            rightPointer = mid;
        }
    }
    return leftPointer;
}

int FindLastLessOrEqual(int target)
{
    int leftPointer = 0;
    int rightPointer = n - 1;
    while (leftPointer < rightPointer)
    {
        // 注意+1不然最后死循环
        int mid = (leftPointer + rightPointer + 1) >> 1;
        if (a[mid] <= target)
        {
            leftPointer = mid;
        }
        else
        {
            rightPointer = mid - 1;
        }
    }
    return leftPointer;
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (q--)
    {
        int target;
        cin >> target;
        int leftPointer = FindFirstMoreOrEqual(target);
        // cout << "left get\n";
        int rightPointer = FindLastLessOrEqual(target);
        // cout << "right get\n";
        if (a[leftPointer] == target)
        {
            cout << leftPointer << ' ' << rightPointer << endl;
        }
        else
        {
            cout << "-1 -1\n";
        }
    }
    return 0;
}