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
    int n;
    ll rod[500005];
    ll pref[500005];
    ll s = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> rod[i];
    }
    sort(rod, rod + n);
    for(int i = 0; i < n; i++){
    	s += rod[i];
    	pref[i] = s;
    	//cout << pref[i] << endl;
    }
    ll a1 = -1, a2 = -1;
    for(int i = n - 1; i > 1; i--){
    	if(rod[i] < pref[i - 1]){
    		a2 = i + 1;
    		a1 = pref[i];
    		break;
    	}
    }
    cout << a1 << ' ' << a2 << endl;
}
