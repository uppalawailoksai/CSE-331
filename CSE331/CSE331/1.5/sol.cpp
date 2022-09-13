#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0);

void solve() {
	int n, d; cin >> n >> d;
	int p[n], s[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		if (p[i] <= d)
			v.push_back({p[i], s[i]});
	}
	sort(v.begin(), v.end());

	int ans = 0;
	int i = 0;
	multiset<pair<int, int>> st;
	for (int j = v.size() - 1; j >= 0; j--) {
		while (i < j and v[j].first + v[i].first <= d) {
			st.insert({v[i].second, v[i].first});
			i++;
		}
		auto it = st.find({v[j].second, v[j].first});
		if (j <= i - 1 and it != st.end()) st.erase(it);
		int here = v[j].second;
		if (!st.empty())
			here += (*st.rbegin()).first;
		ans = max(ans, here);
	}
	cout << ans << '\n';
}

signed main() {
	fast;

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int t = 1;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		// cout << "Case #" << tt << ": ";
		solve();
	}
	return 0;
}