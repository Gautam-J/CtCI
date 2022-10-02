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

void nullifyRow(vvi& a, int row) {
    for (int i = 0; i < sz(a[0]); ++i)
        a[row][i] = 0;
}

void nullifyColumn(vvi& a, int column) {
    for (int i = 0; i < sz(a); ++i)
        a[i][column] = 0;
}

void solve() {
    // Algorithm:
    // ==========
    // Keep track of rows and cols that have zeros.
    // After iterating through the entire matrix, based on the tracking,
    // nullify the rows and cols, i.e., change all elements to zero.
    //
    // Instead of creating a new array for keeping track of rows and cols,
    // use the first row and first col of the matrix.
    // Before that check whether the first row and col has to be nullified or not.
    //
    // Use the first row and first col to nullify the necessary rows and cols.
    // Nullify first row and first col if necessary, based on the check made at the start.
    //
    // Time: O(mn)  m is the number of rows and n is the number of columns
    // Space: O(1)

    int nRows, nCols;
    cin >> nRows >> nCols;

    vvi a(nRows, vi(nCols));
    trav(r, a) {
        trav(c, r)
            cin >> c;
    }

    bool firstRowZero = false, firstColZero = false;

    // check if first row has zero
    for (int i = 0; i < nCols; ++i) {
        if (a[0][i] == 0) {
            firstRowZero = true;
            break;
        }
    }

    // check if first col has zero
    for (int i = 0; i < nRows; ++i) {
        if (a[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }

    // track rows and cols that has zeros
    for (int i = 1; i < nRows; ++i) {
        for (int j = 1; j < nCols; ++j) {
            if (a[i][j] == 0) {
                a[i][0] = 0;  // ith row has zero, store in first col
                a[0][j] = 0;  // jth col has zero, store in first row
            }
        }
    }

    // nullify rows based on first col
    for (int i = 1; i < nRows; ++i) {
        if (a[i][0] == 0)
            nullifyRow(a, i);
    }

    // nullify cols based on first row
    for (int i = 1; i < nCols; ++i) {
        if (a[0][i] == 0)
            nullifyColumn(a, i);
    }

    // nullify first row if necessary
    if (firstRowZero)
        nullifyRow(a, 0);

    // nullify first col if necessary
    if (firstColZero)
        nullifyColumn(a, 0);

    trav(r, a) {
        trav(c, r)
            cout << c << " ";
        cout << nl;
    }
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
