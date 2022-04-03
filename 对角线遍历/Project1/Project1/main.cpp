#include<iostream>
#include<vector>

using namespace std;

void shownums(vector<vector<int>>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums[0].size(); j++)
			cout << nums[i][j] << " ";
		cout << "\n";
	}cout << endl;
}

void shownums2(vector<int>& nums)
{
	for (int &d : nums)
		cout << d << " ";
	cout << endl;
}

/* ����1 -- ���öԽ��ߵĸ��� */
//vector<int> findDiagonalOrder(vector<vector<int>>& mat)
//{
//	int index = 0;//�������
//	int m = mat.size();
//	int n = mat[0].size();
//	int i, j;//����Ԫ�صĺ�������
//	int tmp;//�м�ֵ
//	vector<int> ans;
//	while (index < (m + n))
//	{
//		if (index % 2 == 0)
//		{
//			i = index, j = 0;
//			if (index >= m)
//			{
//				i = mat.size() - 1;
//				j = index - i;
//			}
//			tmp = (index > (n - 1)) ? n : (index + 1);
//			while (j < tmp)
//			{
//				ans.push_back(mat[i][j]);
//				i--; j++;
//			}
//		}
//		else if (index % 2 == 1)
//		{
//			i = 0, j = index;
//			if (index >= n)
//			{
//				j = mat[0].size() - 1;
//				i = index - j;
//			}
//			tmp = (index > (m - 1)) ? m : (index + 1);
//			while (i < tmp)
//			{
//				ans.push_back(mat[i][j]);
//				i++; j--;
//			}
//		}
//		index++;
//	}
//	return ans;
//}

/* ����2 -- ����Ԫ�صĸ��� */
vector<int> findDiagonalOrder(vector<vector<int>>& mat)
{
	int x = 0, y = 0;//��������
	int n = mat[0].size(), m = mat.size();
	vector<int> ans;
	for (int i = 0; i < n*m; i++)
	{
		ans.push_back(mat[x][y]);
		if ((x + y) % 2 == 0)
		{
			if (y == n - 1) ++x;
			else if (x == 0) ++y;
			else --x, ++y;
		}
		else
		{
			if (x == m - 1) ++y; 
			else if (y == 0) ++x;
			else ++x, --y;
		}
	}
	return ans;
}

void test()
{
	vector<vector<int>> nums = {
			{ 0, 1, 2, 3, 4 },
			{ 5, 6, 7, 8, 9 },
			{ 10, 11, 12, 13, 14 } };
	/*vector<vector<int>> nums = {
			{ 1,2},
			{3,4}};*/
	cout << "\nԭ���飺\n"; shownums(nums);
	cout << "\n���Խ��߱�����Ľ����\n";
	shownums2(findDiagonalOrder(nums));
}

int main()
{
	test();
	system("pause");
	return 0;
}