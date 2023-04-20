// 这个照样被卡常了
#include <iostream>
using namespace std;

#define MAX_N 100000
int n, a[MAX_N];

/*
 * return: 返回分类基准值的下标
 * 分类后，对于元素a[k]:
 * left <= k < pivotIndex: a[k] <= a[pivotIndex]
 * pivotIndex < k < right: a[k] > a[pivotIndex]
 */
int Classify(int left, int right)
{
    if (left >= right)
        return left;

    int pivotIndex = right;

    // 交换a[i]和a[pivotIndex]前，
    // i为小于等于与大于a[pivotIndex]的元素的分界线
    int i = left - 1;
    for (int j = left; j <= right - 1; j++)
    {
        if (a[j] <= a[pivotIndex])
            swap(a[++i], a[j]);
    }

    // 将a[pivotIndex]移到分界处
    swap(a[pivotIndex], a[i + 1]);
    pivotIndex = i + 1;

    return pivotIndex;
}

void QuickSort(int left, int right)
{
    if (left >= right)
        return;

    int pivotIndex = Classify(left, right);
    QuickSort(left, pivotIndex - 1);
    QuickSort(pivotIndex + 1, right);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    QuickSort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}