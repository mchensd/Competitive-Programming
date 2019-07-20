#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

char c[55];
int cowa[55];
int cowb[55];
int type[55];
int N, K;
int ans = 0;
void rec(int ind) {
	if (ind > N) {
		for (int i=0; i<K; ++i) {
			if ((c[i] == 'S' && type[cowa[i]] != type[cowb[i]]) || (c[i] == 'D' && \
				type[cowa[i]] == type[cowb[i]])) {
				return;
			}
		}
		ans++;
		return;
	}
	for (int i=1; i<=3; ++i) {
		type[ind] = i;
		rec(ind+1);
	}
}
int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for (int i=0; i<K; ++i) {
    	cin >> c[i] >> cowa[i] >> cowb[i];
    }
    rec(1);
    cout << ans << endl;
}
