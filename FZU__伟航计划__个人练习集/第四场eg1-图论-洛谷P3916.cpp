#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
vector<int> e[MAXN];
int A[MAXN];
//P3916 图的遍历
void dfs(int x, int i) {
	if (A[x]) return;//已经访问过
	A[x] = i;//记录答案
	for (int y : e[x]) { dfs(y, i); }
}
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		e[i].clear();
		A[i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		e[y].push_back(x);//反向建边
	}
	for (int i = n; i >= 1; i--) 
		dfs(i, i);
	for (int i = 1; i <= n; i++) 
		cout << A[i] << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	solve();
	return 0;
}