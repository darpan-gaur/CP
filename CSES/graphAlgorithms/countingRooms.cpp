#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9+7;

void dfs(int i, int j, int n, int m,vector<vector<char>>& grid) {
	if (min(i,j)<0 || i>=n || j>=m) return;
	if (grid[i][j]=='#') return;
	grid[i][j] = '#';
	dfs(i+1, j, n, m, grid);
	dfs(i-1, j, n, m, grid);
	dfs(i, j+1, n, m, grid);
	dfs(i, j-1, n, m, grid);
}

int main() {
	int n,m,i,j,ans=0;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char> (m));
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) cin >> grid[i][j];
	}
	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			if (grid[i][j]=='.') {
				dfs(i, j, n, m, grid);
				ans++;
			}
		}
	}
	cout << ans << "\n";

	// extra for fun 
	
	return 0;
}