#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

/* ����ʵ�� - ����ջ ��δ�Ż��� */
//class Solution {
//public:
//	stack<string> st;
//	void addData(string s, int idx)
//	{
//		string data;
//		while (isdigit(s[idx]))
//		{
//			data += s[idx];
//			idx++;
//		}
//		st.push(data);
//	}
//	void addString(string s, int idx)
//	{
//		string str;
//		while (isalpha(s[idx]) || s[idx] == '[')
//		{
//			str += s[idx];
//			idx++;
//		}
//		st.push(str);
//	}
//	string decodeString(string s) {
//		int idx = 0;
//		string ans;
//		while (idx < s.size())
//		{
//			if (isdigit(s[idx]))
//			{
//				addData(s, idx);
//				idx += st.top().size();
//			}
//			else if (isalpha(s[idx]) || s[idx] == '[')
//			{
//				addString(s, idx);
//				idx += st.top().size();
//			}
//			else
//			{
//				string tmp;
//				string t2,t1;
//				int n;
//				if (s[idx] == ']')
//				{
//					t1 = st.top();
//					string top2;
//					while(!isdigit(t1[0]))
//					{
//						st.pop();
//						top2 = t1 + top2;
//						t1 = st.top();	
//					}
//					tmp = top2 == "" ? t1 : top2;
//					tmp = tmp.substr(1);
//					n = stoi(st.top());
//					st.pop();
//					idx++;
//				}
//				while (n--)
//					t2 += tmp;
//				if (!st.empty())
//				{
//					string top = st.top();
//					st.pop();
//					top += t2;
//					st.push(top);
//				}
//				else
//					st.push(t2);
//			}
//		}
//		int size = st.size();
//		while (size--)
//		{
//			string top = st.top();
//			ans.insert(0, top);
//			st.pop();
//		}
//		return ans;
//	}
//};

/* ����ʵ�� - ����ջ �����Ż��� */
//class Solution {
//public:
//	stack<string> st;
//	void addData(string s, int idx)
//	{
//		string data;
//		while (isdigit(s[idx]))
//		{
//			data += s[idx];
//			idx++;
//		}
//		st.push(data);
//	}
//	void addString(string s, int idx)
//	{
//		string str;
//		while (isalpha(s[idx]) || s[idx] == '[')
//		{
//			str += s[idx];
//			idx++;
//		}
//		st.push(str);
//	}
//	string decodeString(string s) {
//		int idx = 0;
//		string ans;
//		while (idx < s.size())
//		{
//			if (isdigit(s[idx])) //�Ȼ�ȡ���ֲ��֣�Ȼ������ idx ������ǰ�������ֵĺ�һλ��������ջst
//			{
//				addData(s, idx);
//				idx += st.top().size();
//			}
//			else if (isalpha(s[idx]) || s[idx] == '[') //��ȡ����ĸ������'['Ϊ��ͷ����']' Ϊ��β�Ĳ���,������ջst
//			{
//				addString(s, idx);
//				idx += st.top().size();
//			}
//			else
//			{
//				string tmp, top;//tmp,top Ϊ�м����������� st �е����ݽ��в���
//				int n;
//				if (s[idx] == ']') //������ ']' ʱ˵����Ҫ����ǰ������ֶԵ�ǰ���ַ����з���ƴ��
//				{
//					string top2;
//					while (!isdigit(st.top()[0])) //�� st ������ ']' ǰ��λ�õ������ַ���������
//					{
//						tmp = st.top() + tmp;
//						st.pop();
//					}
//					tmp = tmp.substr(1);//��tmp�е� '[' ȥ����ֻ������ĸ����
//					n = stoi(st.top());//��ȡ����
//					st.pop();
//					idx++;//�����Լӣ�����ȱ�٣�����
//				}
//				while (n--)
//					top += tmp;
//				st.push(top);//����������ַ�����st���Է����������
//			}
//		}
//		while (!st.empty())//������������st�п��ܲ�ֹһ��Ԫ�أ���ʱ���������
//		{
//			ans = st.top() + ans;
//			st.pop();
//		}
//		return ans;
//	}
//};

/* �ݹ�ʵ�� */
class Solution {
public:
	string src;
	int idx; //��������Ϊȫ�ֱ���ֻ��Ϊ�˷����������
	int getNums()
	{
		int ret = 0;
		while (idx < src.size() && isdigit(src[idx]))
			ret = ret * 10 + src[idx++] - '0';
		return ret;
	}
	string getString()
	{
		if (idx == src.size() || src[idx] == ']')
			return "";
		int nums;
		string ret;
		if (isdigit(src[idx]))
		{
			nums = getNums();
			++idx;//����'['
			string tmp = getString();
			++idx;//���� ']'
			while (nums--)
				ret += tmp;
		}
		else if (isalpha(src[idx]))
		{
			ret = string(1, src[idx++]);//�˴�idx�����Լӻ������ƣ������޷����к����ַ��ı�����������
		}
		return ret + getString();
	}
	string decodeString(string s) {
		src = s;
		idx = 0;
		return getString();
	}
};

void test()
{
	string s = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
	Solution sol;
	cout << sol.decodeString(s) << endl;
}

int main()
{
	test();
	system("pause");
	return 0;
}