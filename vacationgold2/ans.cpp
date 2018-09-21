#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define mp make_pair
#define pb push_back

const int MAXN = 20005;
const int MAXK = 205;

int weight[MAXK][MAXN];
ll best[MAXK][MAXN];
vector<vector<pii> > adj;
vector<vector<int> >adj2;
int hub[MAXK], hubid[MAXN];
bool ishub[MAXN], conn[MAXK][MAXN];

void dijkstra(int s) {
    int id = hubid[s];
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    pq.push(mp(0, s));
    best[id][s] = 0;
    while (pq.size()) {
        pli next = pq.top(); pq. pop();
        if (best[id][next.second] != next.first) continue;
        int nid = hubid[next.second];
        for (int nei : adj2[nid]) {
            if (best[id][nei] > next.first + weight[nid][nei]) {
                best[id][nei] = next.first + weight[nid][nei];
                if (ishub[nei]) {
                    pq.push(mp(best[id][nei], nei));
                }
            }
        }
    }
}
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
// #else
//     freopen("vacationgold.in", "r", stdin);
//     freopen("vacationgold.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    adj.resize(N+1);
    for (int i=0; i<M; ++i) {
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].pb(mp(b,w));
    }
    for (int i=1; i<=K; ++i){
        cin >> hub[i];
        hubid[hub[i]] = i;
        ishub[hub[i]]=1;
    }
    adj2.resize(K+1);
    for (int i=1; i<=K; ++i ) {
        int h = hub[i];
        for (pii nei : adj[h]) {
            if (!conn[i][nei.first]) {
                conn[i][nei.first] = 1;
                weight[i][nei.first] = nei.second;
                adj2[i].pb(nei.first);
            }
            
            if (ishub[nei.first]) {
                weight[i][nei.first] = min(weight[i][nei.first], nei.second);
            }
            
            else {
                for (pii nei2:adj[nei.first]){
                    if (!conn[i][nei2.first]) {
                        conn[i][nei2.first] = 1;
                        adj2[i].pb(nei2.first);
                        weight[i][nei2.first] = nei2.second + nei.second;
                    }
                    weight[i][nei2.first] = min(weight[i][nei2.first], nei2.second+nei.second);
                }
            }
        }
    }
    for (int i=1; i<=K; ++i) {
        for (int j=1; j<=N; ++j)
            best[i][j]=LLONG_MAX;
        dijkstra(hub[i]);
    }
    int num = 0;
    ll sum = 0;
    while (Q--) {
        int a,b;cin>>a>>b;
        if (ishub[a]) {
            if (best[hubid[a]][b] != LLONG_MAX) {
                ++num; sum+=best[hubid[a]][b];
            }
        }
        else {
            ll tmp = LLONG_MAX;
            for (pii nei : adj[a]) {
                if (best[hubid[nei.first]][b] != LLONG_MAX) {
                    tmp = min(tmp, best[hubid[nei.first]][b] + nei.second);
                }
            }
            if (tmp != LLONG_MAX) {
                ++num; sum += tmp;
            }
        }
    }
    cout << num << '\n' << sum << '\n';
}

