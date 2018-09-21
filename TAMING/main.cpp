#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define PI 3.14159265358979
#define inf 0x3f3f3f3f
int main() {
    // freopen("input.txt", "r", stdin);
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
	int logs[101];
	bool breakaway[101];
	int N;
	cin >> N;
	for (int i=0; i<N; i++) {
		int x;
		cin >> x;
		logs[i] = x;
	}
	int base = 0;
	if (logs[0] > 0) {
		cout << -1 << endl;
		return 0;
	}
	logs[0] = 0;
	for (int i=0; i<N; i++) {
		if (logs[i] == -1) {
			continue;
		}
		if (logs[i] > i) {
			cout << -1 << endl;
			return 0;
		}
		int upto = i-logs[i];
		int cur_val = logs[i]-1;
		for (int j=i-1; j >= upto; j--) {
			if (logs[j] != -1 && logs[j] != cur_val) {
				// cout << cur_val << endl;
				cout << -1 << endl;
				return 0;
			}
			logs[j] = cur_val;
			cur_val -= 1;
		}
	}
	for (int i=0; i<N; i++) {
		if (logs[i] == 0) {
			base++;
		}
	}
	int mn = 0, mx = base;
	bool streak = false;
	for (int i=0; i<N; i++) {
		if (logs[i] == 0) {
			mn++;
		}
	}

	// mx 
	for (int i=0; i<N; i++) {
		if (logs[i] == -1) {
			mx++;
		}
	}
	cout << mn << " ";
	cout << mx << endl;
}
