#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN=  300005;
int nums[MAXN];
int s[MAXN];
vector<vector<int> > foes;
int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
    	cin >> nums[i];
    }
    foes.resize(N+1);
    for (int i=0; i<M; ++i){ 
    	int a, b; cin >> a >> b;
    	foes[a].pb(b);
    	foes[b].pb(a);
    }
    int l =0, r=0;
    int ans = 0;
    while (true) {
    	// printf("%d %d %d\n", nums[l], nums[r], ans);
    	// cout << s[5] << endl;
    	if (r == N) {
    		while (l < N) {
    			ans += r-l;
    			++l;
    		}
    		cout << ans << endl;
    		break;
    	}
    	if (!s[nums[r]]) {
    		for (int x : foes[nums[r]]){++s[x];}
    		++r;
    	}
    	else {
    		for (int x : foes[nums[l]]) -- s[x];
    		ans += r-l;
    		++l;
    	}
    }
}
