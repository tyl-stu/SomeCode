#include<iostream>
#include<string>
using namespace std;

void test()
{
	string s = "ababab";
	string s1 = "%20";

	string::iterator it = s.begin();
	int len = s.size();
	int i = 0;
	cout << s;
	/*while (i < s.size())
	{
		if (s[i] == 'b')
		{
			s.erase(i, 1);
			s.insert(i, s1);
			len = s.size();
		}
		i++;
	}*/
	s.replace(' ', "%20");

	cout << s;

}

int main()
{
	test();
	system("pause");
	return 0;
}