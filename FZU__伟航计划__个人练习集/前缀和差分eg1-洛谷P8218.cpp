#include <vector>
#include <iomanip>
#include <iostream>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
constexpr int maxn = 310;
constexpr ll INF = 4e18;
constexpr double eps = 1e-9;

int n;
int m;

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	vector<int> a(n);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> m;
	vector<int> pre(n + 1, 0);
	pre[0] = 0;
	pre[1] = a[1];
	for (int i = 2; i <= n; i++) {
		pre[i] = a[i] + pre[i - 1];//Ç°×ººÍ
	}
	// 4 3 2 1     a[i]
	// 4 7 9 10    pre[i]
	for (int i = 1; i <= m; i++) {
		int l, r;
		cin >> l >> r;
		cout << pre[r] - pre[l - 1] << '\n';
	}
	return 0;
}