#include<iostream>
#include<vector>

using namespace std;

/* ���� ֮ ԭ�ؽ����������� */
void test()
{
	vector<int> nums = { 2, 3, 1, 0, 5, 4, 6 };
	std::cout << std::endl << "ԭ���飺";
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
	std::cout << "��������飺";
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