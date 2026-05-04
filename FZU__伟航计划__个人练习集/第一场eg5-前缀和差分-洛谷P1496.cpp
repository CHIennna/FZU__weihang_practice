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

int n;

signed main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	vector<pii> intervals(n);
	for (int i = 0; i < n; i++) {
		cin >> intervals[i].first >> intervals[i].second;
	}
	sort(intervals.begin(), intervals.end());
	vector<pii> res;
	for (auto &p : intervals) {
		if (res.empty() || p.first > res.back().second) {
			res.push_back({ p.first,p.second });
		}
		else {
			res.back().second = max(res.back().second, p.second);
		}
	}
	int tot = 0;
	for (auto& p : res) {
		tot += p.second - p.first;
	}
	cout << tot << endl;
	return 0;
}

//推荐做法 差分离散化

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pii> intervals(n);
    vector<int> coords;

    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
        coords.push_back(intervals[i].first);
        coords.push_back(intervals[i].second);
    }

    // 离散化坐标
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    // 差分数组
    vector<int> diff(coords.size(), 0);

    for (auto& [l, r] : intervals) {
        int li = lower_bound(coords.begin(), coords.end(), l) - coords.begin();
        int ri = lower_bound(coords.begin(), coords.end(), r) - coords.begin();
        diff[li]++;
        diff[ri]--;
    }

    // 前缀和恢复覆盖次数
    vector<int> cover(coords.size(), 0);
    int sum = 0;
    for (int i = 0; i < coords.size(); i++) {
        sum += diff[i];
        cover[i] = sum;
    }

    // 计算总长度
    long long total = 0;
    for (int i = 0; i < coords.size() - 1; i++) {
        if (cover[i] > 0) {
            total += coords[i + 1] - coords[i];
        }
    }

    cout << total << endl;

    return 0;
}
*/