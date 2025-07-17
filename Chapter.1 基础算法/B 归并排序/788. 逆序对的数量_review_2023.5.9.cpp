#include <iostream>
#include <vector> //这玩意真省事
using namespace std;
#define MAX_N 100010

int n, a[MAX_N];
long long ans;

void Merge(int left, int mid, int right)
{
    if (left >= right)
        return;
    int leftPointer = left;
    int rightPointer = mid + 1;
    vector<int> temp;
    while (temp.size() < right - left + 1)
    {
        if (leftPointer > mid)
        {
            temp.push_back(a[rightPointer++]);
            continue;
        }
        if (rightPointer > right)
        {
            temp.push_back(a[leftPointer++]);
            // 先放右边后放左边，故左边大，但是在第三个if已经将该段序列逆序对统计完成，
            //  不可在此ans+=(right-(mid+1)+1)，不然重复计数
            continue;
        }
        if (a[leftPointer] <= a[rightPointer])
        {
            temp.push_back(a[leftPointer++]);
        }
        else // a[leftPointer]>a[rightPointer]
        {
            temp.push_back(a[rightPointer++]);
            // 右边这个数比左边没放的数都小，共(mid-leftPointer+1)个
            ans += mid - leftPointer + 1;
        }
    }

    for (int i = 0; i < temp.size(); i++)
    {
        a[left + i] = temp[i];
    }
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
    cout << ans;
    return 0;
}