#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	int myAtoi(string s)
	{
		int start = 0, n = s.size(), flag = 0;// start -- ����������n--�ַ���Ԫ�ظ�����flag -- ���ֵķ���λ
		while (s[start] < '0' || s[start] > '9' && start < n)
		{
			if (s[start] == '-' && flag == 0)
				flag = -1;
			else if (s[start] == '+' && flag == 0)
				flag = 1;
			else if (flag != 0) //��ֹ���������� + / -
				return 0;
			if (s[start] == '-' || s[start] == '+' || s[start] == ' ')
			{
				start++;
			}
			else
				return 0;
		}
		flag = flag == 0 ? 1 : flag;//�ж�flag��ֵ������Ϊ0����˵����ȷ������λ����Ϊ0����˵���ַ�����û����+/-����flag����Ϊ1
		long ans = 0;//��Ϊ�����ͣ���Ϊ�˷�ֹ����Խ��
		while (start < n && s[start] >= '0' && s[start] <= '9')
		{
			ans = ans * 10 + s[start] - '0';
			if (ans > INT_MAX)
				return flag == 1 ? INT_MAX : INT_MIN;//��Խ�����ݷ���λ����������Сֵ
			start++;
		}
		ans *= flag;//���˷���λ
		return (int)ans;//��������ǿתΪ����
	}
};

void test()
{
	string s = "  +-12";
	Solution sol;
	cout<< sol.myAtoi(s);
}

int main()
{
	test();
	system("pause");
	return 0;
}