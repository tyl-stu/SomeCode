#include<iostream>
#include<vector>
using namespace std;
#include<algorithm>

///* 方法1 ~ 利用递归 （有问题）*/
//double ans(double x, int n)
//{
//	if (n < 0)
//	{
//		n = -n;
//		x = 1 / x;
//	}
//	if (n < 1)
//		return 1;
//	--n;
//	return ans(x, n)*x;
//}
//double myPow(double x, int n)
//{
//	return ans(x, n);
//}
//
///* 方法2 ~ 遍历 （有问题）*/
//double myPow(double x, int n) {
//	double res = 1.0;
//	if (n < 0) n = -n, x = 1 / x;
//	for (int i = 0; i < n; i++)
//	{
//		res *= x;
//	}
//	return res;
//
//}

/* 方法3 ~ 奇数幂 */
double myPow(double x, int n) {
	double ans = 1.0;
	for (int i = n; i != 0; i /= 2)
	{
		if (i % 2 != 0)
		{
			ans *= x;
		}
		x *= x;
	}
	return n < 0 ? 1 / ans : ans;
}

void test()
{
	double x = 2.0; int n = 3;
	cout << "\n输入：x = " << x << "  n = " << n << endl;
	cout << "\n结果：";
	cout << myPow(x,n) << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}