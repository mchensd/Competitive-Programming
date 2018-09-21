#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back
int main() {
    #ifdef USE_INPUT_FILE
    freopen("C.in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int n,t;cin>>n>>t;
    string s;cin>>s;
    bool seen[26];
    vector<char> cs;
    for (int i=0; i<n; ++i) {
    	if (!seen[s[i]-'a']) {
    		seen[s[i]-'a'] = true;
    		cs.pb(s[i]);
    	}
    }
    sort(cs.begin(), cs.end());
    if (t > n) {
    	cout << s;
    	for (int i=0; i<t-n; ++i)
    		cout << cs[0];
    	cout << '\n';
    }
    else {
    	char big='a';
    	int pos=0;
    	for (int i=t-1; i>=0; --i) {
    		if (s[i] != cs.back()) {
    			for (int j=0; j<cs.size(); ++j) {
    				if (s[i] == cs[j]) {
    					big = cs[j+1];
    					pos = i;
    					break;
    				}
    			}
    			break;

    		}
    	}
    	for (int i=0; i<pos; ++i) {
    		cout << s[i];
    	}
    	cout << big;
    	for (int i=0; i<t-pos-1; ++i) {
    		cout <<cs[0];
    	}
    	cout << '\n';
    }

}
