#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

struct diffs {
	int ld;
	int rd;
	int ind;
};

struct cmp {
	bool operator() (diffs a, diffs b) const {
		int ma = min(a.ld, a.rd);
		int mb = min(b.ld, b.rd);
		if (ma < mb) {
			return true;
		}
		else if (ma == mb) {
			return a.ind < b.ind;
		}

		else {
			return false;
		}	
	}
}; 
int getith(set<int> s, int ind) {
	auto it = s.begin();
	while (ind--)++it;
	return *it;
}
int L,M,N;
vi pos;
bool works(int val) {
	int prev = 0;
	int cnt = 0;
	for (int i=1; i<N+1; ++i) {
		if (pos[i] - pos[prev] < val) {
			++cnt;
		}
		else {
			prev = i;
		}
	}
	return cnt <= M;
}
int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);

    cin >> L >> N >> M;
    pos.pb(0);
    pos.pb(L);
    int minDiff = INT_MAX;
    for (int i=0;i<N;++i){
    	int x;
    	cin >> x;
    	pos.pb(x);
    }
    sort(pos.begin(), pos.end());
	int lo=0, hi=L;
	while (true) {
		// printf("%d %d\n", lo,hi);
		if (lo == hi)
			break;
		int mid = (lo+hi+1)/2;
		if (works(mid)) {
			lo = mid;
		}
		else {
			hi = mid-1;
		}
	}
	// cout << works(4) << endl;
	cout << lo << endl;

    // set<int> locs;
    // locs.insert(0);
    // int prev = 0;
    // for (int i=0; i<N; ++i) {
    // 	int x;
    // 	cin >> x;
    // 	locs.insert(x);
    // }
    // set<diffs, cmp> s;
    // for (int i=1; i<N+1; ++i) {
    // 	int d1 = getith(locs, i) - getith(locs, i-1);
    // 	int d2 = getith(locs, i+1) - getith(locs, i);
    // 	diffs d;
    // 	d.ld = d1;
    // 	d.rd = d2;
    // 	d.ind = i;
    // 	s.insert(d);
    // }
    // for (auto it=s.begin(); it!=s.end(); ++it) {
    // 	diffs ref = *it;
    // 	// diffs* ref = (&it);
    // 	// printf("%d %d %d\n", ref.ld, ref.rd, ref.ind);
    // }

    // while (M--) {
    // 	auto rem = s.begin();
    // 	diffs d = *rem;
    // 	diffs to_find;
    // 	diffs to_insert;
    // 	if (d.ind > 1) {
    // 		to_find.ld = getith(locs, d.ind-1) - getith(locs, d.ind-2);
    // 		to_find.rd = getith(locs, d.ind) - getith(locs, d.ind-1);
    // 		to_find.ind = d.ind-1;
    // 		auto lref = s.find(to_find);
    // 		to_insert.ld = to_find.ld;
    // 		to_insert.ind = to_find.ind;
    // 		to_insert.rd = 
    // 	}
    // }

}
