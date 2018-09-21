#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
#if defined(USE_INPUT_FILE) || defined(SUBLIME_RUN)
	freopen("input.txt", "r", stdin);    
#else
    freopen("sort", "r", stdin);
    freopen("sort", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    int N; cin >> N;
    vi nums(N);
    for (int i=0; i<N; ++i) {
    	cin >> nums[i];
    	cout << nums[i] << ' ';
    }
    bool sorted = 0;
    cout << "\nsorting\n";
    while (!sorted) {
    	sorted = 1;
    	// cout << "d\n";
    	for (int i=0;i<N-1; ++i) {
    		if (nums[i+1] < nums[i]) {
    			swap(nums[i+1], nums[i]);
    		}
    		cout << nums[i] << ' ';
    	}
    	cout << nums[N-1] << '\n';
    	for (int i=N-2; i>=0; --i) {
    		if (nums[i+1] < nums[i]) {
    			swap(nums[i+1], nums[i]);
    		}
    	}
    	for (int i=0; i<N-1; ++i) {
    		cout << nums[i] << ' ';
    		if (nums[i+1] < nums[i]) {
    			sorted = 0;
    		}
    	}
    	cout << nums[N-1] << '\n';
    	cout << "done\n";
    }
}
