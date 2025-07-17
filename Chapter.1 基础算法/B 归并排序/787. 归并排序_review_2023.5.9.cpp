#include <iostream>
using namespace std;
#define MAX_N 100010

int a[MAX_N], n;

// 合并两区间:[left,mid],[mid+1,right]
void Merge(int left, int mid, int right)
{
    if (left >= right)
        return;
    int *tempArray = new int[right - left + 1 + 10];
    int tempArrayPointer = 0;
    int leftPointer = left;
    int rightPointer = mid + 1;

    while (tempArrayPointer < right - left + 1)
    {
        // 左区间放完了直接全部放右区见
        if (leftPointer > mid)
        {
            tempArray[tempArrayPointer++] = a[rightPointer++];
            continue;
        }
        // 右区间放完了放左区间
        if (rightPointer > right)
        {
            tempArray[tempArrayPointer++] = a[leftPointer++];
            continue;
        }
        // 否则谁小放谁
        if (a[leftPointer] <= a[rightPointer])
        {
            tempArray[tempArrayPointer++] = a[leftPointer++];
        }
        else
        {
            tempArray[tempArrayPointer++] = a[rightPointer++];
        }
    }
    // 排序完放回原数组
    for (int i = 0; i < right - left + 1; i++)
    {
        a[left + i] = tempArray[i];
    }
    delete tempArray;
}
void Divide(int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) >> 1;
    Divide(left, mid);
    Divide(mid + 1, right);
    Merge(left, mid, right);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Divide(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}