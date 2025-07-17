#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Reference: https://oi-wiki.org/basic/quick-sort/#%E4%B8%89%E8%B7%AF%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F
// TODO: 代码运行状态： Segmentation Fault
/**
 * @brief 对nums[left,right) 进行 三路快速排序
 *
 * 过程:
 * 	与原始的快速排序不同，三路快速排序在随机选取分界点 m 后，
 * 	将待排数列划分为三个部分：
 * 		小于 m、等于 m 以及大于 m。
 * 	这样做即实现了将与分界元素相等的元素聚集在分界元素周围这一效果。
 *
 * 性质：
 *	三路快速排序在处理含有多个重复值的数组时，效率远高于原始快速排序。其最佳时间复杂度为 O(n)。
 */
void ThreeWayRadixQuickSort(vector<int> &nums, const int left, const int right)
{
	if (left >= right)
		return;

	// 取随机参考点
	int pivotIndex = left == 0 ? (rand() % right) : (rand() % (right - left) + left);
	int pivotNumber = nums[pivotIndex];
	// currentNumIndex：当前操作的元素下标
	// nums[left, pointerLeft)：存储小于 pivot 的元素
	// nums[pointerRight, right)：存储大于 pivot 的元素
	int currentNumIndex = 0, pointerLeft = left, pointerRight = right;

	// 完成一趟三路快排，将序列分为：
	// 小于 pivot 的元素 | 等于 pivot 的元素 | 大于 pivot 的元素
	while (currentNumIndex < right)
	{
		if (nums[currentNumIndex] < pivotNumber)
		{
			swap(nums[currentNumIndex], nums[pointerLeft]);
			currentNumIndex++;
			pointerLeft++;
		}
		else if (nums[currentNumIndex] > pivotNumber)
		{
			swap(nums[currentNumIndex], nums[pointerRight]);
			pointerRight--;
			// 换过来的数还没有跟pivot比，不知道放哪所以currentNumIndex不动
		}
		else
		{
			currentNumIndex++;
		}
	}

	ThreeWayRadixQuickSort(nums, left, pointerLeft);
	ThreeWayRadixQuickSort(nums, pointerRight, right);
}

int main()
{
	srand(time(0));

	int numAmount;
	vector<int> nums;

	cin >> numAmount;
	for (int i = 0; i < numAmount; i++)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}

	ThreeWayRadixQuickSort(nums, 0, numAmount - 1);

	for (int i = 0; i < numAmount; i++)
	{
		cout << nums[i];
	}
	return 0;
}