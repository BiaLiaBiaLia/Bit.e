#include <iostream>
#include <string>
#include <vector>
using namespace std;

//��������
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[0].size(); ++j)
			{
				// ʹ�û��ݷ�����
				if (dfs(board, word, i, j, 0)) return true;
			}
		}
		return false;
	}
	bool dfs(vector<vector<char>>& board, string word, int i, int j, int w)
	{
		// �������Խ�磬����ֵ��ƥ�䣬����false
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[w]) return false;
		if (w == word.length() - 1) return true;
		char temp = board[i][j];
		board[i][j] = '\0'; // ����ǰԪ�ر��Ϊ'\0'����һ�������ܳ�����word���Ԫ�أ�������ǰԪ�ز����ٲ���Ƚ�
		if (dfs(board, word, i - 1, j, w + 1)
			|| dfs(board, word, i + 1, j, w + 1)
			|| dfs(board, word, i, j - 1, w + 1)
			|| dfs(board, word, i, j + 1, w + 1))
		{
			// ��ǰԪ�ص��������ң������ƥ�䵽�ģ�����true
			return true;
		}
		board[i][j] = temp; // ����ǰԪ�ػָ����䱾��ֵ
		return false;
	}
};

int main()
{
	vector<vector<char>> board = { {'A', 'B', 'C', 'E'},
		                           {'S', 'F', 'C', 'S'},
		                           {'A', 'D', 'E', 'E'} };
	Solution s;
	string str = "ABCCED";
	cout << s.exist(board, str) << endl;

	system("pause");
	return 0;
}