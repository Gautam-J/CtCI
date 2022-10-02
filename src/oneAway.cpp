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

void checkReplacement(string& s1, string& s2) {
    int n = sz(s1);
    bool oneEditAway = false;
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            if (oneEditAway) {
                cout << "NO" << nl;
                return;
            }
            oneEditAway = true;
        }
    }
    cout << "YES" << nl;
}

void checkInsertion(string& s1, string& s2) {
    int n = sz(s1), m = sz(s2);
    int index1 = 0, index2 = 0;

    while (index1 < n && index2 < m) {
        if (s1[index1] != s2[index2]) {
            if (index1 != index2) {
                cout << "NO" << nl;
                return;
            }
        } else {
            index1++;
        }
        index2++;
    }
    cout << "YES" << nl;
}

void solve() {
    // Algorithm:
    // ==========
    // If len(s1) == len(s2), check for replacement.
    // If len(s1) + 1 == len(s2), check for insertion.
    // If len(s1) - 1 == len(s2), check for removal, or insertion with swapped str
    //
    // Replacement:
    // if only one char differs at max one index.
    // Insertion:
    // if char are same, then move both pointers.
    // if char are different, if index values are different, return false
    // if index values are same, increment shorter string pointer.
    // increment longer string pointer in all cases.
    //
    // Time: O(n)  n is the length of the (shorter) string
    // Space: O(1)

    string s1, s2;
    cin >> s1 >> s2;

    int n = sz(s1), m = sz(s2);

    if (n == m)
        checkReplacement(s1, s2);
    else if (n + 1 == m)
        checkInsertion(s1, s2);
    else if (n - 1 == m)
        checkInsertion(s2, s1);
    else
        cout << "NO" << nl;
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
