#include<iostream>
#include<vector>
using namespace std;

void showArr(vector<int>& nums)
{
	for (int& d : nums)
		cout << d << " ";
	cout << endl;
}

/*����1 ~ ���ö��ַ�*/
//class Solution {
//public:
//	/*���ö��ַ�*/
//	int findDuplicate(vector<int>& nums) {
//		int start = 1, end = nums.size() - 1;
//		int ans;
//		while (start <= end)
//		{
//			int n = 0;//ͳ�Ƶ�ǰ����Ԫ��������Ҫ��ĸ���
//			int mid = (end - start) / 2 + start;
//			for (int i = 0; i<nums.size(); i++)
//				n += nums[i] <= mid;
//			if (n <= mid)
//				start = mid + 1;
//			else
//			{
//				end = mid - 1;
//				ans = mid;
//			}
//		}
//		return ans;
//	}
//	/*������ͨ����  -- ���ֻᳬ��ʱ��*/
//	//int findDuplicate(vector<int>& nums) {
//	//	int start = 1, end = nums.size() - 1;
//	//	int ans;
//	//	while (start <= end)
//	//	{
//	//		int n = 0;//ͳ�Ƶ�ǰ����Ԫ��������Ҫ��ĸ���
//	//		//int mid = (end - start) / 2 + start;
//	//		for (int i = 0; i<nums.size(); i++)
//	//			n += nums[i] <= start;
//	//		if (n <= start)
//	//			start++;
//	//		else
//	//		{
//	//			ans = start;
//	//			break;
//	//		}
//	//	}
//	//	return ans;
//	//}
//};

/*����2 ~ ���ÿ���ָ��*/
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0;
		// ���ҳ����������е���һ��
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);
		slow = 0;
		// �ҳ������������ʼ��
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];
		}
		return slow;
	}
};

void test()
{
	vector<int> nums = { 1, 3, 4, 2, 2 };
	showArr(nums);
	Solution s;
	cout << "nums �е��ظ���Ϊ��" << s.findDuplicate(nums) << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}
