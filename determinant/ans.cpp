#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back


int det(vector<vector<int> > v) {
	int N = v.size();
	for (int i=0; i<N; ++i) {
		// for (int j=0; j<N; ++j) {
		// 	cout << v[i][j] << ' ';
		// }
		if (v[i].size() != N) {
			return -42069;
		}
		// cout << '\n';
	}
	// cout << '\n';
	if (N == 1) {
		return v[0][0];
	}
	// if (N == 2) {
	// 	return v[0][0] * v[1][1] - v[0][1]*v[1][0];
	// }
	int ret = 0;
	for (int k=0; k<N; ++k) {
		vector<vector<int> > next;
		for (int i=0; i<N; ++i ){
			if (i == k) continue;
			vector<int> row;
			for (int j=1; j<N; ++j) {
				row.pb(v[i][j]);
			}
			next.pb(row);
		}
		ret += pow(-1, k%2)*v[k][0]*det(next);
	}
	return ret;
}
int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vector<vector<int> > mat(N);
    for (int i=0; i<N; ++i) {
    	for (int j=0; j<N; ++j) {
    		int x; cin >> x;
    		mat[i].pb(x);
    	}
    }
    cout << det(mat) << endl;
}
