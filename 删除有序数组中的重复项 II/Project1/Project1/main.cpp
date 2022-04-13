#include<iostream>
#include<vector>
using namespace std;

void shownums(vector<int>& nums,int n)
{
	for (int i = 0; i < n;i++)
		cout << nums[i] << " ";
	cout << endl;
}

/* ����1 */
int removeDuplicates(vector<int>& nums) 
{
	int n = nums.size();
	if (n <= 2) {
		return n;
	}
	int slow = 2, fast = 2;
	while (fast < n) {
		if (nums[slow - 2] != nums[fast]) {
			nums[slow] = nums[fast];
			++slow;
		}
		++fast;
	}
	return slow;
}

/* ����2 */
int removeDuplicates(vector<int>& nums)
{
	int len = 0;
	for (int &d : nums)//d���ڱ����ģ�����len���䣬lenҲ�ڱ䣡����
		if (len < 2 || nums[len - 2] != d)
			nums[len++] = d;
	return len;
}

void test()
{
	vector<int> nums = { 0, 0, 1, 1, 1, 1, 2, 3, 3 };
	cout << "\nԭ���飺"; shownums(nums, nums.size()); cout << endl << endl;
	cout << removeDuplicates(nums) << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}