#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define PI 3.14159265358979
#define inf 0x3f3f3f3f
int main() {
    freopen("input.txt", "r", stdin);
    // freopen("taming.in", "r", stdin);
    // freopen("taming.out", "w", stdout);
	int logs[101];
	int N;
	cin >> N;
	for (int i=0; i<N; i++) {
		int x;
		cin >> x;
		logs[i] = x;
	}
	int base = 0;
	for (int i=0; i<N; i++) {
		if (logs[i] == -1) {
			continue;
		}
		base++;
		if (logs[i] > i) {
			cout << -1 << endl;
			return 0;
		}
		int upto = i-logs[i];
		int cur_val = logs[i]-1;
		for (int j=i-1; j >= upto; j--) {
			if (logs[j] != -1) {
				cout << -1 << endl;
				return 0;
			}
			logs[j] = cur_val;
			cur_val -= 1;
		}
	}
	int mn = base, mx = base;
	// mn
	bool streak = false;
	for (int i=0; i<N; i++) {
		if (logs[i] == -1 && !streak) {
			streak = true;
			mn++;
		}
		else {
			streak = false;
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
