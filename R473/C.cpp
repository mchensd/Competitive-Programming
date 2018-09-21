#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef SUBLIME_RUN
    freopen("C.txt", "r", stdin);
    #elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N; cin >> N;
    // 1
    if (N <= 5) cout << -1 << '\n';
    else {
    	int i;
    	for (i=0; i<N/2; ++i) {
    		cout << 1 << ' ' << i+2 << '\n';
    	}
    	for (;i<N-1; ++i ){
    		cout << 2 << ' ' << i+2 << '\n';
    	}
    }
    // cout << '\n';
    //2
    for (int i=2; i<=N; ++i) {
    	cout << i-1 << ' ' << i << '\n';
    }
    cout << '\n';
    for (int i=2; i<=20; ++i) {
    	cout << i << ' ' << (2^i) << '\n';
    }
}
