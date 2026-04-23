#include <iostream>
using namespace std;
int n, m;
long long square;
long long rectangle;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	//化成点 然后两点取排列Cxx
	long long total = ((n + 1) * n / 2) * ((m + 1) * m / 2);
	for (int s = 1; s <= min(n, m); s++) {
		square += (n - s + 1) * (m - s + 1);
	}
	
	cout << square << " " << total-square << '\n';
}

/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = i + 1; k <= n; k++) {
				for (int r = j + 1; r <= m; r++) {
					if (k - i == r - j) {
						square++;
					}
					else {
						triangle++;
					}
				}
			}
		}
	}*/