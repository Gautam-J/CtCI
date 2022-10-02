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

void solve() {
    // Algorithm:
    // Count the number of spaces in the given string.
    // Iterate from back, and replace spaces with %20, else copy before char.
    //
    // Time: O(n) where n is the true length of the string
    // Space: O(1)

    char s[] = "Mr John Smith    ";
    int trueLength = 13;

    cout << "Original: " << s << nl;

    int nSpaces = 0;
    for (int i = 0; i < trueLength; ++i) {
        if (s[i] == ' ')
            ++nSpaces;
    }

    int extendedLength = trueLength + nSpaces * 2;
    /* cout << "Index: " << index << nl; */

    int n = (sizeof(s) / sizeof(s[0])) - 1;  // -1 to avoid '\0'
    /* cout << "N: " << n << nl; */

    if (trueLength < n)  // shorten the string, remove whitespaces at the end
        s[trueLength] = '\0';

    int i = extendedLength - 1;
    for (int j = trueLength - 1; j >= 0; j--) {
        if (s[j] != ' ')
            s[i--] = s[j];
        else {
            s[i--] = '0';
            s[i--] = '2';
            s[i--] = '%';
        }
    }

    cout << "URLified: " << s << nl;
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
