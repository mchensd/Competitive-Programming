#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define PI 3.14159265358979
#define inf 0x3f3f3f3f
typedef pair<int, int> PII;
int main() {
    freopen("input.txt", "r", stdin);
    // freopen("snowboots.in", "r", stdin);
    // freopen("snowboots.out", "w", stdout);
    int depth[251];
    PII boots[251];
    bool visited[251][251]; // have we visited state where we at pos i and boots j
    int N, B;
    cin >> N >> B;
    for (int i=0; i<N; i++) {
        int d;
        cin >> d;
        depth[i] = d;
    }
    for (int i=0; i<B; i++) {
        int d, s;
        cin >> s >> d;
        boots[i] = make_pair(s, d);
    }
    queue<PII> BFSq;
    BFSq.push(make_pair(0, -1));
    int ans = B+1;
    while (!BFSq.empty()) {
        PII state = BFSq.front();
//        cout << state.F << " " << state.S << endl;
        BFSq.pop();
        if (state.F == N-1) {
            ans = min(ans, state.S);
            continue;
        }
        for (int inc=0; inc<B; inc++) {
            if (state.S + inc >= B) {
                break;
            }
            if (state.S + inc == -1) {
                continue;
            }
            PII next_boot = boots[state.S + inc];
            if (next_boot.F < depth[state.F]) {
                continue;
            }
            int upto = min(state.F+next_boot.S, N-1);
            for (int d=state.F+1; d<=upto; d++) {
                if (next_boot.F < depth[d]) {
                    continue;
                }
                if (!visited[d][state.S + inc]) {
                    visited[d][state.S + inc] = true;
                    BFSq.push(make_pair(d, state.S + inc));
                }
            }
        }
    }
    cout << ans << endl;
}
