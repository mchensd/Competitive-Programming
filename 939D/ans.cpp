#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

int id[200];

int find (int p) {return (id[p]==p?p:id[p]=find(id[p]));}
bool join (int a, int b) {
	int p=find(a), q=find(b);
	if (p == q) return false;
	id[p]=q;
	return true;
}
int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N;cin>>N;
    string a,b;cin>>a>>b;
    for (int i=1;i<200;++i)id[i]=i;
    vector<pair<char,char> > ans;
    for (int i=0; i<N; ++i) {
    	if (join(a[i], b[i])) {
    		ans.pb(mp(a[i],b[i]));
    	}
    }
    cout << ans.size() << endl;
    for (pair<char, char> p : ans) {
    	cout << p.first << ' ' << p.second << '\n';
    }
}
