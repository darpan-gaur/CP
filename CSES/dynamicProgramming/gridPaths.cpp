#include <iostream>

using namespace std;

const int mod = 1e9+7;

// recursive 
int recursive(int i, int j, int n,char **grid) {
	// base case
	if (min(i,j)<0 || max(i,j)>=n) return 0;
	if (grid[i][j]=='*') return 0;
	if (i==n-1 && j==n-1) return 1;

	// bottom + right
	return (recursive(i+1, j, n, grid) + recursive(i, j+1, n, grid)) % mod;
}

// 

int main() {
	int n,i,j;
	cin >> n;
	char **grid = new char*[n];
	for (i=0;i<n;i++) {
		grid[i] = new char[n];
		for (j=0;j<n;j++) cin >> grid[i][j];
	}
	
	// extra for fun 
	cout << recursive(0, 0, n, grid) << "\n"; 

	return 0;
}