#include <vector>
#include <iomanip>
#include <iostream>
#include <utility>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
constexpr int maxn = 310;
constexpr ll INF = 4e18;
constexpr double eps = 1e-9;

int n, p;

signed main() {
	//差分模板题
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> p;
	vector<int> a(n+1, 0);
	vector<int> diff(n+1, 0);
	int Ans = INT_MAX;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		diff[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i <= p; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		diff[x] += z;
		diff[y + 1] -= z;
	}
	for (int i = 1; i <= n; i++) {
		diff[i] += diff[i - 1];
	}//差分还原
	for (int i = 1; i <= n; i++) {
		Ans = min(Ans, diff[i]);
	}
	cout << Ans << '\n';
	return 0;
}