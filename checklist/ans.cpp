#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define INF 1e9

pii hol[1005], guer[1005];
int dp_h[1005][1005], dp_g[1005][1005];
int sqdist(pii a, pii b) {
	return (a.first-b.first)*(a.first-b.first) + (a.second-b.second) * (a.second-b.second);
}
int main() {
	freopen("checklist.in", "r", stdin);
        freopen("checklist.out", "w", stdout);
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int H, G;
    cin >> H >> G;
    for (int i=1; i<=H; ++i) {
    	cin >> hol[i].first >> hol[i].second;
    }
    for (int i=1; i<=G; ++i ){
    	cin >> guer[i].first >> guer[i].second;
    }
    for (int i=0; i<H+2; ++i) {
    	for (int j=0; j<G+2; ++j) {
    		dp_h[i][j] = INF;
    		dp_g[i][j] = INF;
    	}
    }
    dp_h[1][0] = 0;
    for (int i=1; i<=H; ++i) {
    	for (int j=0; j<=G; ++j) {
    		if (i == 1 && j == 0)
    			continue;
    		if (i > 0) {
    			dp_h[i][j] = min(dp_h[i-1][j] + sqdist(hol[i-1], hol[i]),\
    			dp_g[i-1][j] + sqdist(guer[j], hol[i]));
    		}

    		if (j>0) {
    			dp_g[i][j] = min(dp_g[i][j-1] + sqdist(guer[j-1], guer[j]),\
    			dp_h[i][j-1] + sqdist(hol[i], guer[j]));
    		}
    	}
    }
    cout << dp_h[H][G] << endl;
}
