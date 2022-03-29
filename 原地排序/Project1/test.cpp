#include<iostream>
#include<vector>

using namespace std;

/* 排序 之 原地交换！！！！ */
void test()
{
	vector<int> nums = { 2, 3, 1, 0, 5, 4, 6 };
	std::cout << std::endl << "原数组：";
	for (int &d : nums)
		std::cout << d << " ";
	std::cout << std::endl << std::endl;
	int i = 0;
	while (i < nums.size())
	{
		if (nums[i] == i)
		{
			i++;
			continue;
		}
		swap(nums[nums[i]], nums[i]);
	}
	std::cout << "排序后数组：";
	for (int &d : nums)
		std::cout << d << " ";
	std::cout << std::endl << std::endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}