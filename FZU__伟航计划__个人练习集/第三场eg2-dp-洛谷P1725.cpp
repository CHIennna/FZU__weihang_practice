#include <vector>
#include <deque>
#include <iomanip>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
constexpr int maxn = 200005;
constexpr int INF = 0x3F3F3F3F;
constexpr double eps = 1e-9;

int n, l, r;
ll A[maxn] = { 0 };
ll dp[maxn];
//P1725 琪露诺
signed main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> l >> r;
	for (int i = 0; i <= n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i <= n; i++) {
		dp[i] = -INF;
	}
	dp[0] = A[0];
	deque<int> q;
	for (int i = 1; i <= n; i++) {
		int index = i - l;
		if (index >= 0) {
			while (!q.empty() && dp[q.back()] <= dp[index]) {
				q.pop_back();
			}
			q.push_back(index);
		}
		while (!q.empty() && q.front() < (i - r)) {
			q.pop_front();
		}
		if (!q.empty()) {
			dp[i] = A[i] + dp[q.front()];
		}
	}
	ll ans = -INF;
	//注意这里的范围 不要从零开始 应当是从哪个能够一步跳出到结尾的
	for (int i = max(0,n-r+1); i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}