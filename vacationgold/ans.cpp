#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define mp make_pair
#define pb push_back

bool ishub[20005];
map<int, map<int,bool> > conn;
map<int, map<int, ll> > best;
vector<vector<pii> > adj;
vector<vector<int> > adj2;
map<int, map<int, int> > weight;
void dijkstra(int s) {
    priority_queue<pli,vector<pli>, greater<pli> > pq;
    pq.push(mp(0,s));
    best[s][s]=0;
    while (pq.size()) {
        pli next = pq.top();
        pq.pop();
        if (next.first != best[s][next.second]) continue;
        for (int nei : adj2[next.second]) {
            if (best[s][nei] > next.first+weight[next.second][nei]) {
                best[s][nei] = next.first+weight[next.second][nei];
                if (ishub[nei])
                    pq.push(mp(best[s][nei], nei));
            }
        }
    }
}
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("vacationgold.in", "r", stdin);
    freopen("vacationgold.out", "w", stdout);
#endif
    
    ios::sync_with_stdio(0);
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    adj.resize(N+1);
    adj2.resize(N+1);
    for (int i=0; i<M; ++i) {
        int a,b,w;cin>>a>>b>>w;
        adj[a].pb(mp(b,w));
    }
    vector<vector<pii> > hubadj(K+1);
    vector<int> hubs;
    for (int i=0; i<K; ++i) {
        int x;cin>>x;ishub[x]=1;
        hubs.pb(x);
    }
    for (int h : hubs) {
        for (pii nei : adj[h]) {
            if (!conn[h][nei.first]) {
                conn[h][nei.first]=1;
                adj2[h].pb(nei.first);
            }
            if (weight[h][nei.first] == 0)
                weight[h][nei.first]=nei.second;
            if (ishub[nei.first]) {
                if (nei.second > weight[h][nei.first])
                    weight[h][nei.first] = nei.second;
                continue;
            }
            for(pii nei2 : adj[nei.first]) {
                if (weight[h][nei2.first] == 0)
                    weight[h][nei2.first] = nei.second+nei2.second;
                if (!conn[h][nei2.first]) {
                    adj2[h].pb(nei2.first);
                    conn[h][nei2.first] = 1;
                }
                weight[h][nei2.first] = min(weight[h][nei2.first], nei.second + nei2.second);
            }
        }
    }
    for (int h : hubs) {
        for (int i=1;i<=N; ++i) best[h][i] = LLONG_MAX;
        dijkstra(h);
    }
    vector<ll> outs;
    while (Q--) {
        int a,b;
        cin >> a >> b;
        ll ans = LLONG_MAX;
        if (ishub[a]) {
            if (best[a][b] != LLONG_MAX) {
                ans = best[a][b];
                outs.pb(best[a][b]);
            }
        }
        else {
            for(pii nei : adj[a]) {
                if (best[nei.first][b] == LLONG_MAX)continue;
                ans = min(ans, nei.second+best[nei.first][b]);
            }
            if (ans != LLONG_MAX) outs.pb(ans);
        }
//        printf("%d %d %lld\n", a,b,ans);
    }
    cout << outs.size() << '\n';
    ll ans = 0;
    for (ll x : outs)
        ans += x;
    cout << ans << '\n'	;
}

