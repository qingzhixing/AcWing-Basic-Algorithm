#include <iostream>
#include <vector>
using namespace std;

// 时间复杂度O(NlogN)

void QuickSort(vector<int> &nums, const int left, const int right)
{
    if (left >= right)
        return;
    int midNum = nums[(left + right + 1) / 2];
    int pointerLeft = left - 1;
    int pointerRight = right + 1;

    while (pointerLeft < pointerRight)
    {
        do
        {
            pointerLeft++;
        } while (nums[pointerLeft] < midNum);
        do
        {
            pointerRight--;
        } while (nums[pointerRight] > midNum);

        if (pointerLeft < pointerRight)
        {
            swap(nums[pointerLeft], nums[pointerRight]);
        }
    }
    QuickSort(nums, left, pointerLeft - 1);
    QuickSort(nums, pointerLeft, right);
}

int main()
{
    vector<int> nums;
    int numAmount = 0, k;
    cin >> numAmount >> k;

    for (int i = 0; i < numAmount; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    QuickSort(nums, 0, numAmount - 1);

    cout << nums[k - 1];

    return 0;
}