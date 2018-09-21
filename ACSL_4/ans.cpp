// Michael Chen
// Canyon Crest Academy
// 11th grade
// Senior Division

// Standard Input/Output (Keyboard, not file)
// C++11

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

struct Node { // A node in our binary tree
    char c; // the character it represents
    int count; // the counter for the character
    int l, r; // the left and right children nodes
    Node() : count(0), l(0), r(0) {} // initialize each node with 0 for the values
};

Node tree[27]; // up to 26 nodes, one for each letter
int ans, cur; // the answer for each test case, and the current node number

void insert(int node, char c) {
	// insert a letter with character c. We are currently at the node with number
	// given by the variable node.

    if (tree[node].count == 0 || tree[node].c == c) { 
    	// there is no node here yet or this node matches our character we want to insert
        tree[node].count++;
        tree[node].c = c;
        return;
    }
    if (c <= tree[node].c) {
    	// if the inserted character is less than or equal to the current node
        if (tree[node].l == 0) tree[node].l = cur++; // if the current node doesn't have a left child
        insert(tree[node].l, c);
    }
    
    else { // same as above but with right node
        if (tree[node].r == 0) tree[node].r = cur++;
        insert(tree[node].r,  c);
    }
}

void dfs(int node) {
	// dfs = depth first search -- this is how we get our answer
    if (!tree[node].count) return; // if node does not exist then don't do anything
    if ((tree[tree[node].l].count > 0) ^ (tree[tree[node].r].count > 0)) { // if there is one child
        ans += tree[node].count;
    }
    // go to the children
    dfs(tree[node].l);
    dfs(tree[node].r);
}

int main() {
#if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE) // if run on my computer, use input file
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); // makes input/output faster

    int diff = 'a' - 'A'; // used to convert lowercase to capital
    int q = 5; // 5 test cases
    while (q--) {
        for (int i=0; i<27; ++i) {
            tree[i] = Node(); // initialize nodes with values of 0
        }
        cur = 2; // the next node we insert will have index 2
        string s;
        getline(cin, s);
        int N = s.size();
        string word;
        // word is the final string after it is converted to uppercase and nonletters are removed
        for (int i=0; i<N; ++i) {
            if (!(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))) {
                continue;
            }
            if (s[i] - 'A' <= 25) {
                word += s[i];
            }
            else if (s[i] - 'a' <= 25) {
                word += (s[i] - diff);
            }
        }
        N = word.size();
        
        // initialize the first node in our tree
        tree[1].count = 1;
        tree[1].c = word[0];
        for (int i=1; i<N; ++i) {
            insert(1, word[i]); // insert the ith letter into the tree. We always start at node 1 when inserting.
        }
        ans = 0;
        dfs(1); // depth first search for our answer
        cout << 5-q << ". " << ans << endl; // print answer with formatting
    }
    return 0;
}

