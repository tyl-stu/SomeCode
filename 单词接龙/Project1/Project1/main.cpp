#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
	unordered_map<string, int> wordId;
	vector<vector<int>> edge;
	int nodeNum = 0;

	void addWord(string& word) {
		if (!wordId.count(word)) {
			wordId[word] = nodeNum++;
			edge.emplace_back();
		}
	}

	void addEdge(string& word) {
		addWord(word);
		int id1 = wordId[word];
		for (char& it : word) {
			char tmp = it;
			it = '*';
			addWord(word);
			int id2 = wordId[word];
			edge[id1].push_back(id2);
			edge[id2].push_back(id1);
			it = tmp;
		}
	}

	/* ����BFS */
 //	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	//	for (string& word : wordList) {
	//		addEdge(word);
	//	}
	//	addEdge(beginWord);
	//	if (!wordId.count(endWord)) {
	//		return 0;
	//	}
	//	vector<int> dis(nodeNum, INT_MAX);
	//	int beginId = wordId[beginWord], endId = wordId[endWord];
	//	dis[beginId] = 0;

	//	queue<int> que;
	//	que.push(beginId);
	//	while (!que.empty()) {
	//		int x = que.front();
	//		que.pop();
	//		if (x == endId) {
	//			return dis[endId] / 2 + 1;
	//		}
	//		for (int& it : edge[x]) {
	//			if (dis[it] == INT_MAX) //������������жϵ�ǰ��Ӧ����ĸ�Ƿ���ù�-- dis��Ӧ��edge�У��Լ�wordID�и���ĸ�����
	//			{
	//				dis[it] = dis[x] + 1;
	//				que.push(it);
	//			}
	//		}
	//	}
	//	return 0;
	//}

	/* ˫��BFS */
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		for (string& word : wordList) {
			addEdge(word);
		}
		addEdge(beginWord);
		if (!wordId.count(endWord)) {
			return 0;
		}

		int beginId = wordId[beginWord], endId = wordId[endWord];

		vector<int> disBegin(nodeNum, INT_MAX);
		disBegin[beginId] = 0;
		queue<int> queBegin;
		queBegin.push(beginId);

		vector<int> disEnd(nodeNum, INT_MAX);
		disEnd[endId] = 0;
		queue<int> queEnd;
		queEnd.push(endId);

		while (!queBegin.empty() && !queEnd.empty())
		{
			int queBeginSize = queBegin.size();
			while(queBeginSize)
			{
				int tmp = queBegin.front();
				queBegin.pop();
				if (disEnd[tmp] != INT_MAX)
					return (disBegin[tmp] + disEnd[tmp]) / 2 + 1;
				for (int& it : edge[tmp])
				{
					if (disBegin[it] == INT_MAX)
					{
						queBegin.push(it);
						disBegin[it] = disBegin[tmp] + 1;
					}
				}
				queBeginSize--;
			}

			int queEndSize = queEnd.size();
			while (queEndSize)
			{
				int tmp2 = queEnd.front();
				queEnd.pop();
				if (disBegin[tmp2] != INT_MAX)
					return (disBegin[tmp2] + disEnd[tmp2]) / 2 + 1;
				for (int& it2 : edge[tmp2])
				{
					if (disEnd[it2] == INT_MAX)
					{
						queEnd.push(it2);
						disEnd[it2] = disEnd[tmp2] + 1;
					}
				}
				queEndSize--;
			}
		}
		return 0;

		
	}
};

void test()
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = { "hot", "dot", "dog", "lot", "log", "cog" };

	Solution s;
	cout << "���ȣ�" << s.ladderLength(beginWord, endWord, wordList);
}

int main()
{
	test();
	system("pause");
	return 0;
}