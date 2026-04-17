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

/*
给定一个长度为 𝑛，初始值全为 0 的数组 𝑎，现在对该数组进行 𝑚 次操作，每次操作
给定四个数𝑙, 𝑟, 𝑠𝑡, 𝑘，将区间[𝑙, 𝑟] 的每一个数分别对应加上一个以 𝑠𝑡 为首项，
以 𝑘为公差的等差数列。（题面与原题有略微区别）
其中 𝑛 ≤ 10^7, 𝑚 ≤ 3 × 10^5 ，保证操作使得数在 ll 范围内。
例如：
数组 𝑎 初始为：[0, 0, 0, 0, 0, 0]
一次操作为 𝑙 = 1, 𝑟 = 5, 𝑠𝑡 = 3, 𝑘 = 2
操作过后 𝑎 变为：[3, 5, 7, 9, 11, 0, 0]
我们要求出 𝑚 次操作后的 𝑎 数列。*/
ll n, m;
signed main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	//解题关键是对差分数组再次差分
	cin >> n >> m;
	vector<ll>  a(n+10,0);
	vector<ll> d1(n+10,0);
	vector<ll> d2(n+10,0);
	for (int i = 1; i <= m; i++) {
		int l, r, s, e;
		cin >> l >> r >> s >> e;
		//特判
		if (l == r) {
			d2[l] += s;
			d2[l + 1] -= s;
			continue;
		}
		//计算公差
		int d = (e - s) / (r - l);
		d2[l] += s, d2[l + 1] += d - s;
		d2[r + 1] -= d + e, d2[r + 2] += e;
	}
	ll xor_sum = 0;//异或和
	ll max_val = LLONG_MIN;//最大值
	ll Ans = LLONG_MIN;
	for (int i = 1; i <= n; i++) d1[i] = d1[i - 1] + d2[i];//还原一阶
	for (int i = 1; i <= n; i++) a[i] = a[i - 1] + d1[i];//还原数组
	for (ll i = 1; i <= n; i++) {
		xor_sum ^= a[i];
		if (a[i] > max_val) {
			max_val = a[i];
		}
	}
	cout << xor_sum << " " << max_val << '\n';
	return 0;
}