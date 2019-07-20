#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, T;
     cin >> N >> T;
     vi final(N);
     for (int i=0; i<N; ++i) {
     	int x,s;cin>>x>>s;
     	final[i] = x+s*T;
     }
    // sort(final.begin(), final.end());
    int las =  final[N-1];
    int ans = 0;
    for (int i=N-1; i>=0; --i) {
    	if (final[i] < las) {
    		ans++;
    	}
    }
}
