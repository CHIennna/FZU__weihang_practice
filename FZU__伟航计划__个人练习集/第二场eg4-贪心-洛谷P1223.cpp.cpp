#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int n;
signed main() {
	cin >> n;
	vector<int> a(n,0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b(a);
	sort(a.begin(), a.end());
	double avg_time = 0.0;
	vector<bool> used(n,false);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//排除重复数据影响 不然会重复输出
			if (!used[j] && a[i] == b[j]) {
				cout << j + 1 << " ";
				used[j] = true;
			}
		}
	}
	cout << endl;
	double sum = 0.0;
	for (int i = 0; i < n - 1; i++) {
		sum += a[i];
		avg_time += sum;
	}
	avg_time = avg_time / n;
	cout << fixed << setprecision(2) << avg_time << endl;
	return 0;
}