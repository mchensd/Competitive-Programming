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
    int N;
    cin >> N;
    int debt = 0;
    int dist = 0;
    int prevNeg = 0;
    for (int i=0; i<N; ++i) {
    	int x; cin >> x;
    	dist ++;
    	int newDebt = debt+x;
    	if (debt < 0) {
    		if (newDebt >= 0) {
    			dist += 2*(i-prevNeg);
    		}
    	}
    	else {
    		if (newDebt < 0) {
    			prevNeg = i;
    		}
    	}
    	debt = newDebt;
    }
    cout << dist << endl;
}
