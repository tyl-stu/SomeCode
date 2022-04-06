#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

/* https://leetcode-cn.com/problems/two-sum/ */

void showarr(vector<int>& nums)
{
	for (int &i : nums)
		cout << i << " ";
	cout << endl;
}

/* ����1 ���ù�ϣ�� */
vector<int> twoSum(vector<int>& numbers, int target) {
	unordered_map<int, int> m;
	for (int i = 0; i<numbers.size(); i++)
	{
		int tmp = target - numbers[i];
		if (m.find(tmp) != m.end() && m[tmp] != i)
			return { m[tmp]+1, i+1};
		m[numbers[i]] = i;
	}
	return{};
}

/* ����2 ˫ָ�� */
vector<int> twoSum(vector<int>& numbers, int target) {
	int len = numbers.size();
	int start = 0, end = len - 1;
	while (start < end)
	{
		int sum = numbers[start] + numbers[end];
		if (sum == target)
			return{ start + 1, end + 1 };
		else if (sum > target)
			end--;
		else
			start++;
	}
	return{};
}

/* ����3 ���ֲ��� */
vector<int> twoSum(vector<int>& numbers, int target) {
	for (int i = 0; i < numbers.size(); i++)
	{
		int start = i+1, end = numbers.size() - 1;
		while (start <= end)
		{
			int mid = (end - start) / 2 + start;
			if ((numbers[i] + numbers[mid]) == target)
				return{ i + 1, mid + 1 };
			else if ((numbers[i] + numbers[mid]) < target)//��ʱi��ֵ���䣬���ֻ����mid���������ĺ���С��target�������Ҫ��mid�����ƣ���mid++
				start = mid + 1;
			else
				end = mid - 1;
		}
	}
	return{};
}

void test()
{
	vector<int> arr = {0,0,3,4};
	cout << "\nԭ���飺"; showarr(arr);
	int target = 0;
	cout << "ָ��ֵ��" << target << endl;
	cout << "����������������±꣺"; showarr(twoSum(arr,target)); cout << endl;
	
}

int main()
{
	test();
	system("pause");
	return 0;
}