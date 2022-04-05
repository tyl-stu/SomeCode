#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> findRange(string& s, int left, int right)
{
	while (left >= 0 && right < s.size() && s[left] == s[right])
	{
		--left;
		++right;
	}
	return { ++left, --right };
}

string longestPalindrome(string s) 
{
	int start = 0, end = 0;
	vector<int> n1, n2;
	for (int i = 0; i < s.size(); i++)
	{
		n1 = findRange(s, i, i);//�������ַ�������Ϊ����
		n2 = findRange(s, i, i + 1);//�������ַ�������Ϊ˫��
		if ((n1[1] - n1[0]) > (end - start))
		{
			start = n1[0];
			end = n1[1];
		}
		if ((n2[1] - n2[0]) > (end - start))
		{
			start = n2[0];
			end = n2[1];
		}
	}
	return s.substr(start, end - start + 1);
}

void test()
{
	string s = "babad";
	cout << "\nԭ�ַ�����" << s << endl << endl;
	cout << "\n������ִ���" << longestPalindrome(s) << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}