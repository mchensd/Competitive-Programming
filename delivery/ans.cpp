#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN=105;
set<pii> has;
vector<vector<pii> > adj;
int fw[MAXN*5][MAXN*5];
int N;
vector<pii> points;
int dist(int a, int b) {
    pii p1 = points[a];
    pii p2 = points[b];
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}
bool can(int a, int b) {
    pii p1 = points[a];
    pii p2 = points[b];
    if (p1.first > p2.first)swap(p1, p2);
    bool v = false; // vert first
    bool h = false; // horiz first
    for (int i=0; i<N; ++i ){
        if (i == a || i == b) continue;
        pii k = points[i];
        if (k == p1 || k == p2) continue;
        if (p1.first < k.first && k.first <= p2.first && k.second == p1.second) h=1;
        if (k.first == p2.first) {
            if (min(p1.second, p2.second) <= k.second && k.second <= max(p1.second, p2.second))
                h=1;
        }
        if (p1.first <= k.first && k.first < p2.first && k.second == p2.second) v = 1;
        if (k.first == p1.first) {
            if (min(p1.second, p2.second) <= k.second && k.second <= max(p1.second, p2.second))
                v=1;
        }
        
    }
    return (!(v&&h));
}
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("delivery.in", "r", stdin);
    freopen("delivery.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin >> N;
    
    for (int i=0; i<N; ++i){
        int a,b; cin >> a >> b;
        points.pb(mp(a, b));
        has.insert(mp(a, b));
    }
    for (int i=0; i<N; ++i){
        int chx[] = {-1, 0, 0, 1};
        int chy[] = {0, 1, -1, 0};
        for (int k=0;k<4;++k){
            int nx = points[i].first+chx[k];
            int ny = points[i].second+chy[k];
            pii np = mp(nx, ny);
            if (!has.count(np)) {
                points.pb(np);
                has.insert(np);
            }
        }
    }
    int NN = (int)points.size();
    adj.resize(NN+1);
    for (int i=0; i<5*MAXN; ++i) {
        for (int j=0; j<5*MAXN; ++j) {
            fw[i][j] =INT_MAX;
        }
    }
//    cout << can(0, 1) << endl;
    for (int i=0; i<NN; ++i) {
        for (int j=i+1; j<NN; ++j) {
            if (can(i, j)) {
                adj[i].pb(mp(j, dist(i, j)));
                adj[j].pb(mp(i, dist(i,j)));
                fw[i][j] = dist(i, j);
                fw[j][i] = dist(j, i);
            }
        }
    }
    
    for (int k=N; k<NN; ++k){
        for (int i=0; i<NN; ++i) {
            for (int j=0; j<NN; ++j) {
                if (fw[i][k] < INT_MAX && fw[k][j] <INT_MAX) {
                    fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
                    if (i == 2 && j == 3)  {
//                        printf("dist %d %d %d\n", k, fw[i][k], fw[k][j]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i=0; i<N-1; ++i) {
        if (fw[i][i+1] == INT_MAX) return 0*puts("-1");
        ans += fw[i][i+1];
//        printf("%d %d %d\n", i+1, i+2, fw[i][i+1]);
    }
    if (fw[N-1][0] == INT_MAX) return 0*puts("-1");
    ans += fw[N-1][0];
//    cout << fw[N-1][0] << endl;
    cout << ans << endl;
}
