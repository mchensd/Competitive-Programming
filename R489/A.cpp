#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
    #ifdef SUBLIME_RUN
    freopen("A.txt", "r", stdin);
    #elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);

    int N; cin >> N;
    vi a(N);
    set<int> s;
    for (int i=0; i<N; ++i) {
    	cin >> a[i];
    	if (a[i] != 0) s.insert(a[i]);
    }
    cout << s.size() << endl;
}
