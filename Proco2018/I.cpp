#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
int N;
vector<string> words;
int wordcnt[16][28];
int curcnt[26];
int cnt[26];
vector<int> ans;
bool good = 0;
void go(int ind) {
	if (ind == N) {
		bool ok = 1;
		for (int i=0; i<26; ++i) {
			if (curcnt[i] != cnt[i]) {
				ok=0;
			}
		}
		if (ok) {
			cout << "possible\n";
			for (int i=0; i<ans.size(); ++i) {
				if (i) cout << ' ';
				cout << ans[i];
			}
			cout << '\n';
		}
		good = 1;
		return;
	}
	ans.pb(0);
	go(ind+1);
	ans.pop_back();
	ans.pb(1);
	for (int i=0; i<26; ++i) {
		curcnt[i] += wordcnt[ind][i];
	}
	go(ind+1);
	ans.pop_back();
	for (int i=0; i<26; ++i) {
		curcnt[i] -= wordcnt[ind][i];
	}
	ans.pb(2);
	for (int i=0; i<26; ++i) {
		curcnt[i] += 2*wordcnt[ind][i];
	}
	ans.pop_back();
	for (int i=0; i<26; ++i) {
		curcnt[i] -= 2*wordcnt[ind][i];
	}
}
int main() {
    #ifdef SUBLIME_RUN
    freopen("E.txt", "r", stdin);
    #elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin >> N;
    words.resize(N); 
    for (int i=0; i<N; ++i) {
    	cin >> words[i];
    	for (int j=0; j<words[i].size(); ++j) {
    		wordcnt[i][words[i][j]-'a']++;
    	}
    }
    go(0);
    if (!good)
    	cout << "impossible\n";

}
