#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
vector<int> e[MAXN];//存储图
int A[MAXN];//存储res
//P3916 图的遍历
/*按题目来每次考虑每个点可以到达点编号最大的点，
不如考虑较大的点可以反向到达哪些点
循环从N到1，则每个点i能访问到的结点的A值都是i
每个点访问一次，这个A值就是最优的，
因为之后如果再访问到这个结点那么答案肯定没当前大了*/
void dfs(int x, int i) {//在反向图中，从点x出发，所有能到达的点，都标记为i
	if (A[x]) return;//已经访问过

	A[x] = i;//记录答案 i → x

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