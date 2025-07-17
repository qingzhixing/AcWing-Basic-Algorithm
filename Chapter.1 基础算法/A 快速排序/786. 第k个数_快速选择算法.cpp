#include <iostream>
#include <vector>
using namespace std;

// 时间复杂度O(N)

/**
 * @brief 快速选择算法
 *
 *
 * @param nums 数列
 * @param left 左边界
 * @param right 右边界
 * @param k 要找的第k大的数
 * @return
 */
int QuickSelect(vector<int> &nums, const int left, const int right, const int k)
{
    if (left >= right)
        return nums[left];
    int midNum = nums[(left + right) / 2];
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
    /*
     * Tips: 排序区间完成我们得到以下特性:
     * 	A. pointerLeft左边的，即[left, pointerLeft - 1]，都小于我们的参考点；
     * 	B. pointerRight右边的，即[pointerRight + 1, right]，都大于我们的参考点；
     *
     * 设左部分区间大小为SL。
     * 则可以根据上述特性我们有如下推论，midNum是我们第SL大的数。
     *
     * 若 k > SL, 则 k 在右侧区间，是第 (k - SL)大的数
     * 若 k < SL, 则 k 在左侧区间，第 k 大的数
     * 若 k == SL, 则 k 就是我们要找的数
     * */
    const int SL = pointerRight - left + 1;
    if (k <= SL)
        return QuickSelect(nums, left, pointerRight, k);
    if (k > SL)
        return QuickSelect(nums, pointerRight + 1, right, k - SL);
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

    cout << QuickSelect(nums, 0, numAmount - 1, k);

    return 0;
}