#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	int myAtoi(string s)
	{
		int start = 0, n = s.size(), flag = 0;// start -- 遍历索引，n--字符串元素个数，flag -- 数字的符号位
		while (s[start] < '0' || s[start] > '9' && start < n)
		{
			if (s[start] == '-' && flag == 0)
				flag = -1;
			else if (s[start] == '+' && flag == 0)
				flag = 1;
			else if (flag != 0) //防止出现其他的 + / -
				return 0;
			if (s[start] == '-' || s[start] == '+' || s[start] == ' ')
			{
				start++;
			}
			else
				return 0;
		}
		flag = flag == 0 ? 1 : flag;//判断flag的值，若不为0，则说明已确定符号位，若为0，则说明字符串中没出现+/-，即flag需设为1
		long ans = 0;//设为长整型，是为了防止数字越界
		while (start < n && s[start] >= '0' && s[start] <= '9')
		{
			ans = ans * 10 + s[start] - '0';
			if (ans > INT_MAX)
				return flag == 1 ? INT_MAX : INT_MIN;//当越界后根据符号位返回最大或最小值
			start++;
		}
		ans *= flag;//最后乘符号位
		return (int)ans;//将长整型强转为整型
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