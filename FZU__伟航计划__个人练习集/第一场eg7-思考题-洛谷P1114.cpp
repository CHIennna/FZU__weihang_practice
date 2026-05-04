#include <vector>
#include <iomanip>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
constexpr int maxn = 310;
constexpr ll INF = 4e18;
constexpr double eps = 1e-9;

int n;
signed main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	int sum = 0;
	int ans = 0;
	/*  把 0 当作 -1，1 当作 +1。
	问题变成了：找最长子数组，其元素和为 0。
	这就变成了 最长和为 0 的子数组长度。  */
	//“找相同前缀和的最远距离”
	//一边算前缀和，一边记录 每个前缀和第一次出现的位置
	//如果遇到相同的前缀和，就用当前位置 − 第一次出现的位置，更新答案
	//前缀和可能是负数（比如 - 1， - 2， - 3），但数组下标不能为负。
	//解决办法：加一个偏移量。
	//最小前缀和可能到 - n，最大到 n，范围长度 = 2n + 1。
	//我们把每个前缀和 + n 作为数组下标
	vector<int> first(2 * n + 2, -1);
	first[n] = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		//sum 前缀和
		if (x == 1)sum++;
		else sum--;
		int index = sum + n;//下标
		if (first[index] != -1) {//可以计算区间了
			ans = max(ans, i - first[index]);
		}
		else {
			first[index] = i;
		}
	}
	cout << ans << endl;

	/*for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int l = 1; l <= n; l++) {
		int cnt0 = 0, cnt1 = 0;
		for (int r = l; r <= n; r++) {
			if (a[r] == 0) cnt0++;
			else cnt1++;
			if (cnt0 == cnt1) {
				ans = max(ans, r - l + 1);
			}
		}
	}
	if (ans == 0)cout << 0;
	else {
		cout << ans << endl;
	}*/
	return 0;
}