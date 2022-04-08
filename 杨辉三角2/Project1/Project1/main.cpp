#include<iostream>
#include<vector>
using namespace std;

void shownums(vector<vector<int>>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums[i].size(); j++)
		{
			cout << nums[i][j] << " ";
		}cout << endl;
	}cout << endl;
}

void showrow(vector<int>& row)
{
	for (int& d : row)
		cout << d << " ";
	cout << endl;
} 

/* ����1 ~ ͨ������������������ */
//vector<int> getRow(int rowIndex) 
//{
//	rowIndex++;
//	vector<vector<int>> ans;
//	for (int i = 0; i < rowIndex; ++i)  
//		ans.push_back(vector<int>(i+1,0));
//	ans[0][0] = 1;
//	for (int i = 1; i < rowIndex; i++)
//	{
//		ans[i][0] = 1; ans[i][i] = 1;
//		for (int j = 1; j < i; j++)
//		{
//			ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
//		}
//	}
//	return ans[rowIndex-1];
//}

///* ����2 ~ ������ѧ���� ���ý׳�*/
//int factorial(int x)
//{
//	if (x == 1)
//		return 1;
//	return x*factorial(x - 1);
//}
//vector<int> getRow(int rowIndex)
//{
//	vector<int> ans(rowIndex + 1);
//	ans[0] = 1, ans[rowIndex] = 1;
//	for (int i = 1; i < rowIndex; i++)
//	{
//		ans[i] = 1LL*factorial(rowIndex) / (factorial(i) * factorial(rowIndex - i));
//	}
//	return ans;
//}

/* ����2 ~ ������ѧ����2*/
vector<int> getRow(int rowIndex)
{
	vector<int> ans(rowIndex + 1);
	ans[0] = 1;
	for (int i = 1; i <= rowIndex; i++)
	{
		ans[i] = 1LL * ans[i - 1] * (rowIndex - i + 1) / i;//1LL,LL��ʵ����long long��*1LL��Ϊ���ڼ���ʱ����int���͵ı���ת��Ϊlong long��Ȼ���ٸ�ֵ��long long���͵ı���
	}
	return ans;
}

void test()
{
	int n = 5;
	//cout << n << "�Ľ׳� = " << factorial(n) << endl;
	cout << "�����������" << n << endl;
	cout << "\n���ɵ�������ǣ�\n";
	showrow(getRow(n)); cout << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}