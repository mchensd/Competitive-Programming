#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

bool poss[150];
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
	int N;
	cin >> N;
	bool done = false;
	string c="";
	int out =0;

	for (int i=0;i<150;++i)
		poss[i]=1;
	int cnt = 26;
	while (N--) {
		// cout << cnt << endl;
		char q; string s; cin >> q >> s;
		if (done) {
			if (q == '!')
				++out;
			else if (q == '?') {
				if (s != c)
					++out;
			}	
			// cout << q << ' ' << s << endl;
		}
		else {
			if (q == '?') {
				if (poss[s[0]]) {
					poss[s[0]] = 0;
					if (cnt == 1) {
						done = 1; c = s;
					}
					else
						--cnt;
				}
			}
			else if (q == '!') {
				for (int i='a'; i<='z'; ++i) {
					bool in = 0;
					for (int j=0; j<s.size(); ++j) {
						if (s[j] == i) in = 1;
					}
					if (!in) {
						if (poss[i]) {
							--cnt;
							poss[i] = 0;
						}
					}
				}
			}
			else {
				for (int i=0; i<s.size(); ++i) {
					if (poss[s[i]]) {
						--cnt;
						poss[s[i]] = 0;
					}
				}
			}
			if (cnt == 1) {
				done = 1;
				for (int i='a'; i<='z'; ++i){
					if (poss[i]) c += i;
				}
			}
		}
	}
	// cout << done << ' ' << c << endl;
	cout << out << endl;
}
