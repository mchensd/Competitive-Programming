#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
int cnt[1005][1005];
int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vi a(N);
    vi b(N);
    for (int i=0; i<N; ++i) {
    	cin >> a[i];
    	b[i] = a[i];
    }
    sort(b.begin(), b.end());
    for (int i=0;i<N; ++i) {
    	cnt[a[i]][b[i]]++;
    }
    int ans = 0;
    for (int i=1; i<=2; ++i) {
    	for (int j=i+1; j<=3; ++j) {
    		int m = min(cnt[i][j], cnt[j][i]);
    		ans += m;
    		cnt[i][j] -= m;
    		cnt[j][i] -= m;
    	}
    }

    ans += 2*(cnt[1][2] + cnt[2][1]);
    cout << ans << endl;

}
