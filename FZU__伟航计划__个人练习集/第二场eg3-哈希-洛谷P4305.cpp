#include <map>
#include <set>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
constexpr int maxn = 1000011;
constexpr ll INF = 4e18;

//快速读入
char buf[1 << 23], * p1 = buf, * p2 = buf;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline unsigned long long rd() {//读入一个 64 位无符号整数
	unsigned long long x = 0;
	char ch = gc();
	while (!isdigit(ch))ch = gc();
	while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = gc();
	return x;
}

int t;

int main() {
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> nums(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> nums[i];
		}
		set<int> res(n + 1);
		if () {

		}
		for (set<int>::iterator i = res.begin(); i != res.end(); i++) {
			cout << *i;
		}
	}

	return 0;
}