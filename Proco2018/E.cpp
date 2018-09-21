#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
#ifdef SUBLIME_RUN
    freopen("E.txt", "r", stdin);
#elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    vi x(N);
    multiset<int> p;
    for (int i=0; i<N; ++i) {
        cin >> x[i];
    }
    for (int i=0; i<N; ++i){
        int a; cin >> a; p.insert(a);
    }
    
    for (int i=0; i<N; ++i) {
        if (i) cout << ' ';
        auto it = p.upper_bound(x[i]);
        if (it != p.begin()) --it;
        if (*it > x[i]) {
            // cout << "it" << *it << endl;
            cout << -1;
            continue;
        }
        cout << *it;
        p.erase(it);
    }
    cout << '\n';
}
