#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int cnt[26];
int main() {
    #ifdef SUBLIME_RUN
    freopen("B.txt", "r", stdin);
    #elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    string s; cin >> s;
    set<char> chars;
    for (int i=0; i<s.size(); ++i){
    	++cnt[s[i]-'a'];
    	chars.insert(s[i]);
    }
    if (chars.size() == 4) {
    	puts("Yes");
    }
    else if (chars.size() > 4 || chars.size() == 1) {
    	puts("No");
    }
    else {
    	if (chars.size() == 2) {
    		for (int i=0; i<26; ++i) {
    			if (cnt[i] == 1) {
    				return 0*puts("No");
    			}
    		}
    	}
    	else {
    		if (s.size() == 3) {
    			return 0*puts("No");
    		}
    	}
    	puts("Yes");
    }
}
