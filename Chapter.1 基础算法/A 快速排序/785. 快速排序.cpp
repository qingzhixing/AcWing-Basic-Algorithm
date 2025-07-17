#include <iostream>
#include <vector>
using namespace std;

// =w=

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
    int numAmount = 0;
    cin >> numAmount;

    for (int i = 0; i < numAmount; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    QuickSort(nums, 0, numAmount - 1);

    for (int i = 0; i < numAmount; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}