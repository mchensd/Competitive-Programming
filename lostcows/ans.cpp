#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> state;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define x F.F
#define y F.S
const int MAXN=205;
int path[MAXN][MAXN];
vector<state> edges[MAXN][MAXN];
vector<int> seq[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];
bool past[MAXN];
bool nxt[MAXN];
bool v[MAXN];
int main() {
//#ifdef USE_INPUT_FILE
//    freopen("input.txt", "r", stdin);
//#endif
    // freopen("lostcows_tests/lostcows.2.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
cout << ("a" < "aa") << endl;
    auto start = clock();
    int N, M; cin >> N >> M;
    for (int i=1; i<=M; ++i) {
        for (int j=1; j<=N; ++j) {
            cin >> path[j][i];
        }
    }
    
    for (int i=1; i<=N; ++i){
        for (int j=1; j<=N; ++j) {
            for (int k=1; k<=M; ++k) {
                int ni = path[i][k];
                int nj = path[j][k];
                
                if (ni > nj) swap(ni, nj);
                int tmpi=min(i, j), tmpj = max(i, j);
                edges[ni][nj].pb(mp(mp(tmpi, tmpj), k));
                
            }
        }
    }
    queue<pii> q;
    for (int i=1; i<=N; ++i) {
        dp[1][1][i] = i;
        past[i] =1;
        nxt[i]=1;
    }
    q.push(mp(1, 1));
    while (q.size()) {
        pii next = q.front();
//        printf("%d %d\n", next.F, next.S);
        q.pop();
        for (state nei : edges[next.F][next.S]) {
            //            printf("%d %d\n", nei.x, nei.y);
            if (!dp[nei.x][nei.y][1]) {
                seq[nei.x][nei.y] = seq[next.F][next.S];
                seq[nei.x][nei.y].pb(nei.second);
                for (int i=1;i<=N; ++i) {
                    int j=path[i][nei.second];
                    dp[nei.x][nei.y][i] = dp[next.F][next.S][j];
                }
                q.push(mp(nei.x, nei.y));
            }
        }
    }
//    cout << 3 << endl;
    
    vector<pii> ans;
    while (true) {
        int f = past[1];
        int a=0, b=0;
        for (int i=1; i<=N; ++i) {
            if (past[i]) {
                if (!a) a=i;
                else if (!b) {b=i;}
                if (i>1)f=false;
                if (b) break;
            }
        }
        if (f) break;
        
        ans.pb(mp(a, b));
        for (int i=1; i<=N; ++i) {
            if (past[i]) {
                if (!v[i]) nxt[i] = 0;
                nxt[dp[a][b][i]] = 1;
                v[dp[a][b][i]] = 1;
            }
        }
        for (int i=1; i<=N; ++i) {past[i] = nxt[i]; v[i]=0;}
    }
    vector<int> chk;
    for (pii p : ans){
//        printf("%d %d\n", p.F, p.S);
        for (int i=(int)seq[p.F][p.S].size()-1; i>=0; --i) {
//            cout << seq[p.F][p.S][i] << endl;
            chk.pb(seq[p.F][p.S][i]);
        }
    }
    auto end = clock();

    /*
	*
	*
	*         SELF JUDGE
	*
	*/
	
    printf("Time elapsed: %f\n", ((double)(end-start))/CLOCKS_PER_SEC);
    for (int i=1; i<=N; ++i) {
        past[i] =1;
        nxt[i]=1;
        v[i]=0;
    }
    // chk[0]=1;
    // chk[1]=1;chk[2]=1;chk[3]=1;
    // cout << chk.size() << endl;
    for (int dir : chk) {
    	// dir=1;
    	// dir=0;
    	// cout << dir << endl;
        for (int i=1; i<=N; ++i) {
        	// cout << past[i] << ' ';
        	// cout << path[i][dir] << ' ';
            if (past[i]) {
                if (!v[i]) nxt[i] = 0;
                nxt[path[i][dir]] = 1;
                v[path[i][dir]] = 1;
            }
        }
        // cout << endl;
        for (int i=1; i<=N; ++i) {past[i] = nxt[i]; v[i]=0;}//cout << past[i] << ' '; v[i]=0;}
        for (int i=1; i<=N; ++i){ 
        	if (past[i]) {
        		bool ok = false;
        		for (int j=1; j<=N; ++j) {
        			if (path[j][dir] == i) {ok =1;break;}
        		}
        		if (!ok) printf("BAD CHECK\n");
        	}
        }
        // cout << '\n';
    }
    bool f=past[1];
    // cout << "asdf\n";
    // cout << past[1] << endl;
    for (int i=2; i<=N; ++i) {
    	if (!f) break;
        f = !past[i];
        // cout << past[i] << endl;
    }
    printf("Checker: ");
    if (f) printf("OK\n");
    else printf("Wrong answer\n");
}

