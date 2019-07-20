#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int dp[10005];
int dist[10005];
int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M; 
    for (int i=0; i<N; ++i) {
    	cin >> dist[i];
    }

    for (int i=N-1; i>=0; --i) {
        dp[i] = max(dp[i], dp[i+1]);
        int pos = i+2;
        int ind = i;
        int curd = 0;
        for (int j=0; j<M; ++j) {
            if (pos > N) 
                break;
            curd += dist[ind++]; 
            dp[i] = max(dp[i], curd+dp[pos]);
            pos += 2;
        }
    }   

    cout << dp[0] << endl;

}
