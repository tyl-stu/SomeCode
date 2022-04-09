#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

void shownums(vector<int>& nums)
{
	for (int& d : nums)
		cout << d << " ";
	cout << endl;
}

/* ����1 ~ ����API */
int findMin(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	return nums[0];
}


int findMin(vector<int>& nums)
{
	int start = 0, end = nums.size() - 1;
	while (start < end)
	{
		int mid = start + (end - start) / 2;
		if (nums[mid] < nums[end])//����ȷ����С�ķ�Χ
			end = mid;
		else //����ȷ���������н�С��ֵ�ķ�Χ
			start = mid + 1;
	}
	return nums[start];
}

void test()
{
	//ԭ����Ϊ��0,1,2,3,4,5,6,7
	vector<int> nums = { 4, 5, 6, 7, 0, 1 };
	cout << "\n�账������飺"; shownums(nums); cout << endl;
	vector<int> tmp = nums;
	sort(tmp.begin(), tmp.end());
	cout << "\nĿ�������ԭ���飺"; shownums(tmp); cout << endl;
	cout << "\n��Сֵ��" << findMin(nums) << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}