#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXK=11;
const int MAXN=  50005;
string ps[MAXK];

map<vector<int>, vector<int> > indsMap;
map<vector<int>, int> curInd;
int pref[MAXK][MAXN];
int early[MAXK][MAXN];
int indval[2*MAXN];
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("cbs.in", "r", stdin);
    freopen("cbs.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int K, N;
    cin >> K >> N;
    for (int i=0; i<K; ++i) {
    	cin >> ps[i];
    	pref[i][0] = MAXN;
    	for (int j=1; j<=N; ++j){
    		if (ps[i][j-1]=='(') {
    			pref[i][j] = pref[i][j-1] + 1;
    		}
    		else {
    			pref[i][j] = pref[i][j-1] - 1;
    		}
    	}
    	for (int j=0; j<2*MAXN; ++j)
    		indval[j] = 1;
    	for (int j=1; j<=N; ++j ){
    		early[i][j] = indval[pref[i][j]];
    		indval[pref[i][j]+1] = j+1;
    		// printf("%d %d\n", pref[i][j], early[i][j]);
    	}
    	// cout << '\n';
    }
    int ans = 0;
    for (int j=1; j<=N; ++j) {
    	vector<int> prefs;
    	int upto = 1;
    	for (int i=0; i<K; ++i ){
    		prefs.pb(pref[i][j]);
    		upto = max(upto, early[i][j]);
    	}
    	int tmpi = curInd[prefs];
    	vector<int> inds = indsMap[prefs];
    	while (tmpi < inds.size() && inds[tmpi] < upto) {
    		++tmpi;
    	}
    	ans += inds.size() - tmpi;
    	indsMap[prefs].pb(j);
    	curInd[prefs] = tmpi;
    }
    cout << ans << endl;
}
