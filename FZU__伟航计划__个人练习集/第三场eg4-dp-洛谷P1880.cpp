#include <vector>
#include <iomanip>
#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
constexpr int maxn = 310;
constexpr ll INF = 0x3f3f3f3f;
constexpr double eps = 1e-9;
#define MAXN 22

int n;
int a[maxn];
int sum[maxn];
int dp[maxn][maxn];
int mx[maxn][maxn];

//简单思考，由题意看作区间dp
//dp[l][r] 表示把第 l 堆到第 r 堆石子合并成一堆的最小总得分 因为我们不能只用一维数组，这样你确定状态转移方程的时候，找不出前两堆是如何到现在的状态的
//如果要把[l, r] 这一整段合并成一堆，那么最后一次合并之前，它一定被分成了[l, k] 和[k + 1, r]两堆
//可以推出状态转移方程是 f[l][r] = min(f[l][k] + f[k+1][r] + sum(l,r))
//其中 l <= k < r
//前缀和求sum(l, r) = s[r] - s[l - 1]
//考虑圆形断开成链 需要复制原数组 枚举长度为n的连续区间 表示圆从不同位置断开的情况
//min(f[i][i+n-1])

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}

	for (int i = 1; i <= 2 * n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}

	memset(dp, 0x3f, sizeof(dp));
	memset(mx, 0, sizeof(mx));

	for (int i = 1; i <= 2 * n; i++) {
		dp[i][i] = 0;
		mx[i][i] = 0;
	}

	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= 2 * n; l++) {
			int r = l + len - 1;
			for (int k = l; k < r; k++) {
				int cost = dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1];
				int fuck = mx[l][k] + mx[k + 1][r] + sum[r] - sum[l - 1];
				dp[l][r] = min(dp[l][r], cost);
				mx[l][r] = max(mx[l][r], fuck);
			}
		}
	}

	int min_ans = INF;
	int max_ans = -INF;
	for (int i = 1; i <= n; i++) {
		min_ans = min(min_ans, dp[i][i + n - 1]);
		max_ans = max(max_ans, mx[i][i + n - 1]);
	}
	cout << min_ans << endl;
	cout << max_ans << endl;
	return 0;
}