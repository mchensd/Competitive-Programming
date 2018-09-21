#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 1000005;
int pos[MAXN];
int main() {
    #ifdef USE_INPUT_FILE
    freopen("B.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N; cin >> N;
    for (int i=1; i<=N; ++i ){
    	int x; cin >> x;
    	pos[x] = true;
    }
    int i1=1, i2=(int)1e6;
    int ans=-1;
    int cnt=N;
    while (cnt) {
    	// printf("%d %d %d %d\n", i1,i2,pos[i1], pos[i2]);
    	if (pos[i1])--cnt;
    	if (pos[i2])--cnt;
    	++i1;--i2;++ans;
    }
    cout << ans << endl;
}
