#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int mod = 1e9+7;

int main() {
	int n, m, i, j, d, bi,bj,ai,aj;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char> (m));
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			cin >> grid[i][j];
			if (grid[i][j]=='A') {
				ai = i;
				aj = j;
			}
			if (grid[i][j]=='B') {
				bi = i;
				bj = j;
			}
		}
	}

	
	// bfs
	vector<vector<int>> prevDir(n, vector<int> (m, -1));
	string dir = "LRUD";
	queue<pair<int,int>> q;
	vector<vector<bool>> visited(n, vector<bool> (m,false));
	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {-1, 1, 0, 0};
	q.push({ai,aj});
	visited[ai][aj] = true;
	while (!q.empty()) {
		i = q.front().first;
		j = q.front().second;
		q.pop();
		for (int d=0;i<4;i++) {
			if (min(i+dx[d],j+dy[d])<0 || (i+dx[d])>n || (j+dy[d])>m) continue;
			if (grid[i+dx[d]][j+dy[d]]=='#' || visited[i+dx[d]][j+dy[d]]) continue;
			visited[i+dx[d]][j+dy[d]] = true;
			prevDir[i+dx[d]][j+dy[d]] = d;
			q.push({i+dx[d], j+dy[d]});
		}
	}
	vector<char> steps;
	if (visited[bi][bj]!=-1) {
		cout << "YES\n";
		while (bi!=ai && bj!=aj) {
			steps.push_back(dir[prevDir[bi][bj]]);
			bi = bi - dx[prevDir[bi][bj]];
			bj = bj - dy[prevDir[bi][bj]];
		}
		cout << steps.size() << "\n";
	}else {
		cout << "NO\n";
	}



	// extra for fun 
	
	return 0;
}