#ifndef _SOLUTION_H_
#define _SOLUTION_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
	/* 832. Flipping an Image */
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		vector<vector<int>> B;
		int row = A.size();
		int col = A[0].size();
		for (int i = 0; i < row; ++i) {
			vector<int> tmp;
			for (int j = col - 1; j >= 0; --j) {
				if (A[i][j] == 0)
					tmp.push_back(1);
				else
					tmp.push_back(0);
			}
			B.push_back(tmp);
		}
		return B;
	}
	/* 833. Find And Replace in String */
	string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
		string res = "";
		int n = indexes.size();
		map<int, int> mp;
		for (int i = 0; i < n; ++i) {
			int pos = indexes[i];
			if (S.substr(pos, sources[i].size()) == sources[i]) {
				mp[pos] = i;
			}
		}
		int offset = 0;
		for (auto it = mp.cbegin(); it != mp.cend(); ++it) {
			S.replace(it->first + offset, sources[it->second].size(), targets[it->second]);
			offset = offset + targets[it->second].size() - sources[it->second].size();
		}
		return S;
	}
	/*835. Image Overlap*/
	int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
		int n = A.size(), ans = 0;
		for (int i = -n + 1; i <= n - 1; ++i)
			for (int j = -n + 1; j <= n - 1; ++j) {
				int overlap_num = 0;
				for (int k = 0; k < n; ++k) {
					for (int l = 0; l < n; ++l) {
						int x = i + k, y = j + l;
						if (x < 0 || x >= n || y < 0 || y >= n)
							continue;
						overlap_num += (A[k][l] & B[x][y]);
					}
				}
				ans = max(overlap_num, ans);
			}
		return ans;
	}

	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
		vector<int> ans(N, 0), son_dist(N, 0), son_num(N, 0);
		vector<vector<int>> edge_table(N, vector<int>(0, 0));
		for (const auto& iter : edges) {
			edge_table[iter[0]].push_back(iter[1]);
			edge_table[iter[1]].push_back(iter[0]);
		}
		for (auto& row : edge_table) {
			for (auto& col : row)
				cout << col << " ";
			cout << endl;
		}
		cout << endl;
		dfs(0, -1, son_dist, son_num, edge_table);
		getAns(0, -1, son_dist, son_num, edge_table, ans);
		return ans;
	}

	void dfs(int root, int father, vector<int>& son_dist, vector<int>& son_num, vector<vector<int>>& edge_table) {
		son_num[root]++;
		for (const auto& iter : edge_table[root]) {
			if (iter == father)
				continue;
			dfs(iter, root, son_dist, son_num, edge_table);
			son_num[root] += son_num[iter];
			son_dist[root] += son_dist[iter] + son_num[iter];
		}
	}

	void getAns(int root, int father, vector<int>& son_dist, vector<int>& son_num, vector<vector<int>>& edge_table, vector<int>& ans) {
		if (father == -1)
			ans[root] = son_dist[root];
		else
			ans[root] = ans[father] + son_num.size() - 2 * son_num[root];
		for (const auto& iter : edge_table[root]) {
			if (iter == father)
				continue;
			getAns(iter, root, son_dist, son_num, edge_table, ans);
		}
	}
};
#endif

