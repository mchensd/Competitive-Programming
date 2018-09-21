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
    int depth[300];
    int N, B;
    cin >> N >> B;
    for (int i=0; i<N; i++){
        int x;
        cin >> x;
        depth[i] = x;
    }
    PII boots[300];
    for (int i=0; i<B; i++) {
        int s, d;
        cin >> s >> d;
        boots[i] = make_pair(s, d);
    }
    int dp[300];
    for (int i=0; i<N; i++) {
        dp[i] = B-1;
    }
    dp[0]=0;
    for (int i=0; i<N; i++) {
        int cur_boot = dp[i];
        for (int inc=0; inc<B; inc++) {
            int next_boot = cur_boot + inc;
            if (next_boot >= B) {
                break;
            }
            PII boot = boots[next_boot];
            if (boot.first < depth[i]) {
                continue;
            }
            int upto = min(i + boot.second, N-1);
            for (int d=i+1; d<=upto; d++) {
                if (boot.first >= depth[d]) {
                    dp[d] = min(dp[d], next_boot);
                }
            }
        }
    }
    cout << dp[N-1] << endl;
}


