#include<iostream>
#include<vector>
using namespace std;

/* ������ 69. x ��ƽ���� ��Ľⷨ https://leetcode-cn.com/problems/sqrtx/ */
/*����1 ~ ��ͨ�Ľⷨ*/
//int mySqrt(int x) 
//{
//	if (x <= 1)  return x;
//	int ans = x / 2;
//	while (ans)
//	{
//		if ((x / ans) >= ans && (ans + 1)>(x / (ans + 1)))
//			return ans;
//		else if ((x / ans) < ans)
//			ans /= 2;
//		else if ((x / ans) > ans)
//			ans++;
//	}
//	return -1;
//}

/*����2 ~ ���ö��ַ�*/
int mySqrt(int x) 
{
	if (x <= 1) return x;
	int left = 0, right = x;
	int mid, ans;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (x / mid >= mid)
		{
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return ans;
}

/* ���� 367. ��Ч����ȫƽ���� �Ľⷨ https://leetcode-cn.com/problems/valid-perfect-square/ */
/*����1 ���ַ�*/
//bool isPerfectSquare(int num) {
//	int start = 0, end = num;
//	while (start <= end)
//	{
//		int mid = start + (end - start) / 2;
//		long s = (long)mid*mid;
//
//		if (s< num) start = mid + 1;
//		else  if (s>num) end = mid - 1;
//		else return true;
//	}
//	return false;
//}
/* ����2 ��ѧ���� https://leetcode-cn.com/problems/valid-perfect-square/solution/zhi-xing-yong-shi-0-ms-zai-suo-you-c-ti-jiao-zh-44/ */
bool isPerfectSquare(int num) {
	int x = 1;
	while (num > 0)
	{
		num -= x;
		x += 2;
	}
	return num == 0;
}

void test()
{
	int x = 25;
	cout << endl << x << "��ƽ������" << mySqrt(x) << endl << endl;
	cout << x << "�Ƿ�Ϊ��ȫƽ������" << boolalpha << isPerfectSquare(x) << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}