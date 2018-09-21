#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 200005;
int  ans1[MAXN], ans2[MAXN];
pii sock[MAXN];
map<int, vector<int> > cnt;
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    for (int i=1; i<=N; ++i) {
    	int x;cin >> x;
    	cnt[x].pb(i);
    }
    for (int i=1; i<=M; ++i) {
    	cin >> sock[i].first; sock[i].second = i;
    }

    int c=0, u=0;
    sort(sock+1, sock+M+1);
    for (int i=1; i<=M; ++i) {
    	int cur=sock[i].first;
    	int ndiv = 0;
    	// cout << cur << endl;
    	while (true) {
    		vector<int>& st = cnt[cur];
    		if (st.size()) {
    			ans1[sock[i].second]=ndiv;
    			ans2[(st).back()] = sock[i].second;
    			// cout << cnt[cur].size() << endl;
    			(st).pop_back();
    			// cout << cnt[cur].size() << endl;
    			++c;
    			u+=ndiv;
    			break;
    		}
    		if (cur == 1) break;
    		++ndiv;
    		cur = cur/2 + (cur&1);
    	}
    }
    cout << c << ' ' << u << '\n';
    for (int i=1;i<=M;++i) {
    	cout << ans1[i] << ' ';
    }
    cout << '\n';
    for (int i=1; i<=N; ++i) {
    	cout << ans2[i] << ' ';
    }
    cout << '\n';
}
