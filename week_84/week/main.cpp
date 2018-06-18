#include "solution.h"
#include <iostream>
using namespace std;

int main()
{
	int N = 6;
	vector<vector<int>> edges = { {0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5} };
	Solution solution;
	vector<int> res = solution.sumOfDistancesInTree(N, edges);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;
	system("pause");
	return 0;
}