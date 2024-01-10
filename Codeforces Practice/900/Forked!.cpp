#include <bits/stdc++.h>
 
using namespace std;
 
int T;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		int a, b, x, y, z, w;
		cin >> a >> b >> x >> y >> z >> w;
		const int dx[8] = {a, a, -a, -a, b, b, -b, -b};
		const int dy[8] = {b, -b, b, -b, a, -a, a, -a};
		int ans = 0;
		for (int i = 0; i < (a == b ? 4 : 8); ++i) {
			int px = x + dx[i], py = y + dy[i];
			int tx = abs(px - z), ty = abs(py - w);
			if ((tx == a && ty == b) || (tx == b && ty == a)) ++ans;
		} 
		cout << ans << '\n';
	}
	return 0;
}