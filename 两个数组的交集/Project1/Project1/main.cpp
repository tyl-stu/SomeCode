#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

/*两个数组的交集 https://leetcode-cn.com/leetbook/read/top-interview-questions-easy/x2y0c2/ */

void shownums(vector<int> &nums)
{
	for (int &i : nums)
		cout << i << " ";
	cout << endl;
}

/*方法1  利用map*/
//vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
//{
//	map<int, int> m1;//存储nums1
//	vector<int> ans;
//	for (int &d : nums1)
//		m1[d]++;
//	for (int &i : nums2)
//	{
//		if (m1[i] > 0)
//		{
//			ans.push_back(i);
//			--m1[i];
//		}
//	}
//	return ans;
//}

/*方法2  利用双指针*/
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
{
	vector<int> ans;
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());
	int index1 = 0;
	int index2 = 0;
	while (index1<nums1.size() && index2<nums2.size())
	{
		if (nums1[index1]<nums2[index2])
			index1++;
		else if (nums1[index1]>nums2[index2])
			index2++;
		else
		{
			ans.push_back(nums1[index1]);
			index2++;
			index1++;
		}
	}
	return ans;
}

void test()
{
	vector<int> nums1 = { 4, 9, 5 };
	vector<int> nums2 = { 9, 4, 9, 8, 4 };
	cout << "nums1: "; shownums(nums1);
	cout << "nums2: "; shownums(nums2);cout  << endl;

	vector<int> ans = intersect(nums1, nums2);
	cout << "两数组的交集："; shownums(ans); cout << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}
