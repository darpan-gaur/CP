/*
https://codedrills.io/problems/remove-nodes
*/

// Solution 1
// Time complexity: O(N+M + NlogN)
// Space complexity: O(M)
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class RemoveNodes {
public:
	// DO NOT read from stdin or write to stdout.
	// Input is given as the function arguments.
	// Output is taken as the function return value.
	std::vector<int> findMinimalRemoval(int N, int M, int A, int B, std::vector<int> edgeFrom, std::vector<int> edgeTo) {
		int i;
		vector<vector<int>> adj(N);
		for (i=0;i<M;i++) {
			adj[edgeFrom[i]].push_back(edgeTo[i]);
		}
		vector<int> ans;
		vector<bool> visited(N, false);
		queue<int> q;
		q.push(A);
		visited[A] = true;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (int u:adj[curr]) {
				if (!visited[u]) {
					if (u==B) {
						ans.push_back(curr);
						continue;
					}
					q.push(u);
					visited[u] = true;
				}
			}
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
};