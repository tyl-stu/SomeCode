#include<iostream>
#include<string>
#include<vector>
using namespace std;

/* ����1 ~ ��������*/
//int strStr(string haystack, string needle) 
//{
//	int n = haystack.size(), m = needle.size();
//	if (m <= 0)
//		return 0;
//	int i, j;
//	for (i = 0; i <= (n - m); i++)
//	{
//		for (j = 0; j < m; j++)
//		{
//			if (haystack[i + j] != needle[j])
//				break;
//		}
//		if (j == m)
//			return i;
//	}
//	return -1;
//}

/* ����2 ~ KMP�㷨�Ĵ���1 */
vector<int> GetNext(const string& str)
{
	vector<int> next(str.size());
	int j = 0, k = -1;
	next[0] = k;	
	while (j<(str.size()-1))//��Ϊ����next�ĸ�����ģʽ���������ǰ��׺�ĳ��ȣ���������ɳ��� str.size()-1
	{
		if (k == -1 || str[j] == str[k])
		{
			++j;
			++k;
			next[j] = k;
		}
		else
			k = next[k];
	}
	return next;
}

int strStr(string haystack, string needle) 
{
	vector<int> next = GetNext(needle);
	int n = haystack.size(), i = 0;
	int m = needle.size(), j = 0;
	if (m <= 0)
		return 0;
	while (i < n && j < m)
	{
		if (0>j || haystack[i] == needle[j])//����j<0�൱�������¿�ʼ�жϣ���Ϊnext �еĵ�һ������ -1
			i++, j++;
		else
			j = next[j];
		if (j == m )
			return i -j;
	}
	return -1;
}

/* KMP�㷨�Ĵ���2 */
//int strStr(string haystack, string needle) {
//	int n = haystack.size(), m = needle.size();
//	if (m == 0) {
//		return 0;
//	}
//	vector<int> pi(m);
//	//��Ѱģʽ���е���󹫹�ǰ׺��׺����
//	for (int i = 1, j = 0; i < m; i++) {
//		while (j > 0 && needle[i] != needle[j]) {//�൱���Ǵ�ʱԪ�ز���ͬ��Ȼ��ת����һ��λ�����¿�ʼ
//			j = pi[j - 1];
//		}
//		if (needle[i] == needle[j]) {
//			j++;
//		}
//		pi[i] = j;
//	}
//	for (int i = 0, j = 0; i < n; i++) {
//		while (j > 0 && haystack[i] != needle[j]) {//j�����仯ֻ��Ϊ�˸���Ч�ı���ģʽ��
//			j = pi[j - 1];
//		}
//		if (haystack[i] == needle[j]) {
//			j++;
//		}
//		if (j == m) {
//			return i - m + 1;
//		}
//	}
//	return -1;
//}

void test()
{
	string s1 = "mississippi";
	string s2 = "issip";
	cout << "\n������" << s1 << endl << "ģʽ����" << s2 << endl << endl;
	cout << "ģʽ���������г��ֵĵ�һ��λ�ã�" << strStr(s1, s2) << endl << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}