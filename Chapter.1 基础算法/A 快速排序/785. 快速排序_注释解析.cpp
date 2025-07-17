#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 快速排序
 *
 * @param left 排序左区间
 * @param right 排序右区间
 */
void QuickSort(vector<int> &nums, const int left, const int right)
{
    // 判断区间
    if (left >= right)
        return;

    /*
     * Step.1: 确定参考点（分界点）
     *
     * Tips:
     * 	这里需要备份一下参考点，否则它会在程序运行时被改变
     * 	要向上取整，否则会导致写 pointerLeft 递归时产生边界问题
     */
    int midNum = nums[(left + right + 1) / 2];

    /*
     * Step.2 排序:
     * 对于区间内的一个数:
     * 	若小于参考点，则放在其左边；
     * 	若大于参考点，则放在右边.
     */
    int pointerLeft = left - 1;
    int pointerRight = right + 1;

    while (pointerLeft < pointerRight)
    {
        // 移动左指针到第一个 大于等于参考点的数 (最后会停在参考点上)
        do
        {
            pointerLeft++;
        } while (nums[pointerLeft] < midNum); // 不能加等于号，否则左指针会跨越参考点

        // 移动右指针到第一个 小于等于参考点的数 (最后会停在参考点上)
        do
        {
            pointerRight--;
        } while (nums[pointerRight] > midNum);

        // 交换左右指针指向的数
        if (pointerLeft < pointerRight)
        {
            swap(nums[pointerLeft], nums[pointerRight]);
        }
    }

    /**
     * Step.3: 递归处理左右区间
     *
     * Tips: 排序区间完成我们得到以下特性:
     * 	A. pointerLeft左边的，即[left, pointerLeft - 1]，都小于我们的参考点；
     * 	B. pointerRight右边的，即[pointerRight + 1, right]，都大于我们的参考点；
     *
     * 而参考点，原先在(left + right)/2，现在地址已经改变了
     * 所以我们使用pointerLeft或者pointerRight来表示递归处理的区间:
     *
     * pointerLeft表示:
     * 	[left, pointerLeft - 1]
     * 	[pointerLeft, right]
     *
     * pointerRight表示:
     * 	[left, pointerRight]
     * 	[pointerRight + 1, right]
     */
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