#include <iostream>
using namespace std;
#define MAX_N 100010

int n, a[MAX_N], ans;
bool exist[MAX_N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int right = 0, left = 1;
    while (right < n)
    {
        right++;
        // cout << left << ' ' << right << endl;
        while (exist[a[right]] && left <= right)
        {
            exist[a[left]] = false;
            left++;
        }
        exist[a[right]] = true;
        ans = max(ans, right - left + 1);
    }
    cout << ans;
    return 0;
}