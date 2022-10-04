#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define forn(i, l, r) for (int i = (int)l; i < (int)r; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define trav(i, a) for (auto& i : a)
#define allit(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define shuf(v) shuffle(all(v), rng)
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN

#ifdef _GLIBCXX_DEBUG
#define debug(...) cerr << "[DEBUG]: [" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< pi > vpi;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
/* const ld PI = acos(-1.0); */

struct Node {
    int data = 0;
    Node* next = nullptr;
};

void insertAtEnd(Node* &head, int data) {
    Node* newNode = new Node;
    newNode->data = data;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" << nl;
}

int printKthToLast(Node* head, int k) {
    if (head == nullptr)
        return 0;

    int index = printKthToLast(head->next, k) + 1;
    if (index == k)
        cout << head->data << nl;
    return index;
}

void solveRecursive() {
    // Algorithm:
    // ==========
    // The most trivial solution is to traverse through the entire list,
    // get to known the total length of the list, and then iterate for len - k
    // times. This does give O(1) space and O(n) time, best possible complexities.
    //
    // We can use recursion and the stack it provides. We return a value starting
    // from 0 when we hit the last node, and then increment the returned value.
    // When the value returned it equal to k, we print the value at the node.
    // This is very similar to using recursion to print 1 to n, in reverse.
    //
    // Assume k = 0 is not accepted, k = 1 returns the last element.
    //
    // Time: O(n)
    // Space: O(n)  space taken for recursion stack

    int n = 5;
    Node* head = nullptr;
    fore(i, 1, n)
        insertAtEnd(head, i * 2);
    printList(head);

    int k;
    cin >> k;

    printKthToLast(head, k);

}

void solve() {
    // Algorithm:
    // ==========
    // Iterative version.
    // We use two pointers, and keep them k nodes apart. Then we move both the
    // pointers until the second pointer reaches the end. Now, the first pointer
    // will be at (length - k) node, the answer.
    //
    // This version enables us to return the entire node itself.
    //
    // Time: O(n)
    // Space: O(1)

    int n = 5;
    Node* head = nullptr;
    fore(i, 1, n)
        insertAtEnd(head, i * 2);
    printList(head);

    int k;
    cin >> k;

    Node* p1 = head, *p2 = head;
    forn(i, 0, k)
        p2 = p2->next;

    while (p2 != nullptr) {
        p1 = p1->next;
        p2 = p2->next;
    }

    cout << p1->data << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
