#include<iostream>
#include<vector>

using namespace std;

void shownums(vector<int>& nums)
{
	for (int& d : nums)
		cout << d << " ";
	cout << endl;
}

int search(vector<int>& nums, int target)
{
	int n = nums.size();
	if (n == 0) return -1;
	if (n == 1) return nums[0] == target ? 0 : -1;
	int start = 0, end = n - 1;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		if (nums[mid] == target) return mid;
		if (nums[0] <= nums[mid])//ȷ��ǰ�벿���Ƿ����� -- ��ʱΪ [0,mid]
		{
			if (nums[0] <= target && target < nums[mid])//ȷ���Ƿ�����ڵ�ǰ���򲿷������У�����ȷ���ò��ֵĽ�βend
				end = mid - 1;
			else//������ȷ����һ���ֵ���ʼλ��
				start = mid + 1;
		}
		else
		{
			if (nums[mid] < target && target <= nums[n - 1])
				start = mid + 1;
			else
				end = mid - 1;
		}
	}
	return -1;
}

void test()
{
	vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
	int target = 1;
	cout << "\nԭ����Ϊ��"; shownums(nums); 
	cout << "Ҫ���ҵ�ֵΪ��" << target << endl; cout << endl;
	cout << "Ŀ���������ڵ�λ�ã�" << search(nums, target) << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}