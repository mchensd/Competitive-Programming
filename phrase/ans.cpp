#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

string phrase[10005];
string call[10005];
int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    // string s;
    // string inp;
    // while (getline(cin, inp)) {
    // 	s += inp;
    // }
    // cout << s << endl;
    int M, N;
    cin >> M >> N;
    string s;
    getline(cin, s);

    for (int i=0; i<M; ++i) {
    	getline(cin, phrase[i]);
    }

    sort(phrase, phrase+M);

    int ans = 0;
    for (int i=0; i<N; ++i) {
    	getline(cin, call[i]);
    	int lo = 0;
    	int hi = M-1;
    	if (phrase[lo].substr(0, min(phrase[lo].length(), call[i].length())) > call[i]) 
    		continue;

    	while (lo < hi) {
    		int mid = (lo+hi+1)/2;
    		if (phrase[mid].substr(0, min(phrase[mid].length(), call[i].length())) <= call[i]) {
    			lo = mid;
    		}
    		else {
    			hi = mid-1;
    		}
    	}
    	if (phrase[lo].substr(0, min(phrase[lo].length(), call[i].length())) == call[i]) {
    		++ans;
    	}
    }
    cout << ans << endl;
}
