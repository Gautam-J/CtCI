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

Node* stablePartition(Node* head, int x) {
    // Algorithm:
    // ==========
    // Stable partition keeps the order, but requires extra memory.
    //
    // We create 2 new lists, one for storing nodes with value less than x,
    // and another for storing values greater than x or equal to x.
    //
    // Time: O(n)  n is number of nodes, i.e., length of the linked list
    // Space: O(n)  n is number of nodes, i.e., length of the linked list

    Node* temp = head;
    Node* leftHead = nullptr;
    Node* leftTail = nullptr;
    Node* rightHead = nullptr;
    Node* rightTail = nullptr;

    while (temp != nullptr) {
        if (temp->data < x) {
            if (leftHead == nullptr)
                leftHead = temp;
            else
                leftTail->next = temp;
            leftTail = temp;
        } else {
            if (rightHead == nullptr)
                rightHead = temp;
            else
                rightTail->next = temp;
            rightTail = temp;
        }

        temp = temp->next;
    }

    if (leftHead == nullptr)
        return rightHead;

    leftTail->next = rightHead;
    rightTail->next = nullptr;
    return leftHead;
}

Node* unstablePartition(Node* head, int x) {
    // Algorithm:
    // ==========
    // Unstable partition does not keep the order, but does not require extra space.
    //
    // This is very similar to the partition method for quicksort algorithm.
    // We consider the node with value x as the pivot element. All elements greater
    // than pivot are appended to the tail, and all elements lesser than pivot are
    // appended to the head.
    //
    // TODO: Fix segmentation fault error
    //
    // Time: O(n)  n is number of nodes, i.e., length of the linked list
    // Space: O(1)

    Node* temp = head;
    Node* start = nullptr;
    Node* end = nullptr;
    Node* next = nullptr;

    while (temp != nullptr) {
        next = temp->next;
        if (temp->data < x) {
            temp->next = start;
            start = temp;
        } else {
            end->next = temp;
            end = temp;
        }
        temp = next;
    }

    end->next = nullptr;
    return start;
}

void solve() {
    // Algorithm:
    // ==========
    // The original question does not require the operation to be stable.
    // Therefore, the order of elements less than partition / more than partition
    // in the final list does not matter.
    //
    // Time: O(n)  n is number of nodes, i.e., length of the linked list
    // Space: O(1)

    int n, t;
    cin >> n;

    Node* head = nullptr;
    forn(i, 0, n) {
        cin >> t;
        insertAtEnd(head, t);
    }

    int x;
    cin >> x;

    printList(head);

    Node* stableHead = stablePartition(head, x);
    /* Node* unstableHead = unstablePartition(head, x); */

    printList(stableHead);
    /* printList(unstableHead); */
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
