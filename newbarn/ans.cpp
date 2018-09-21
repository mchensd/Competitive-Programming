/** ALGORITHM I THINK WORKS IN MAX O(QLOGQ) (if anybody reads this)

* First build the forest at the end of all queries. We will process queries backwards. 
* We will solve for one connected component, this can be applied to the separate components

* Observation: Once we know the first child on the path from the root to its max depth,
* All other children and their grand children of the root not on this path must have their max dist path to that 
* max depth node.(a leaf)

* For one tree, we notice we can split it into two groups:
* 	1. A connected group of nodes whose max distance is the maximum depth of the root of the entire tree
* 	2. A connected group of nodes whose max distance is obtained by travelling first to a lower depth than the "root" of the 
*	   group. (Not the root of the whole tree)

* With these groups, we can solve queries easily:
* 	If the queried node is in group 1, we can use binary lifting to find the highest node
*	that is on the path from the root of the entire tree to its max depth node. Answer is
*	dist to this node + max dist of that node.
*	
*	If the queried node is in group 2, we can again use binary lifting to find the "root"
*	of the group. The answer is then the dist to this root + the max dist of the root.

* Now we must answer updates. Since we are working backwards, updates are deleting some
* leaf nodes.
* 
* A leaf node is critical if it is the max depth node of another node.
* In each groups, we can keep a count of depths of leaf nodes.
* We can obviously update this count with each delete. 
* An event occurs when there becomes 0 occurences of one of the group's critical node.
* When this happens, we can adjust the 2 groups accordingly. Only one node moves from one group to another. (running out of time)

* Also need to store the max dist and second max dist for each node to deal with
* the node that changes groups.

* Thus, I believe we can complete this in at most O(QlogQ), logQ from binary lifting
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back

const int MAXN = 100005;
pair<char, int> queries[MAXN];
int p[MAXN];
bool done[MAXN];

int best[MAXN], sec[MAXN];
int maxD[MAXN];
int treeNum = 1;
vector<vector<int> > adj;
void dfs(int v, int p) {
	done[v] = 1;
	if (adj[v].size() <= 1 && p != 0) return;

	for (int nei : adj[v]) {
		if (nei == p) continue;
		dfs(nei, v);
	}

}
int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("newbarn.in", "r", stdin);
    freopen("newbarn.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    

    cout << 0 << endl << 2 << endl << 1 << endl;
    // int Q;
    // adj.resize(Q+1);
    // int v = 1;
    // for (int i=0; i<Q; ++i) {
    // 	cin >> queries[i].first >> queries[i].second;
    // 	if (queries[i].first == 'B') {
    // 		if (queries[i].second == -1) continue;
    // 		adj[queries[i].second].pb(v);
    // 		p[v] = queries[i].second;
    // 		++v;
    // 	}
    // }
    // for (int i=1; i<=v; ++i){
    // 	if (!done[i]) {
    // 		dfs(i, 0);
    // 		++treeNum;
    // 	}
    // }
}
