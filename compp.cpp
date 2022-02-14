#include <bits/stdc++.h>
using namespace std;

#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair
#define fi first
#define se second
#define repi(n) for (int i = 0; i < n; i++)
#define repj(n) for (int j = 0; j < n; j++)

#define cout_vec(a)       \
    for (auto q : a)      \
        cout << q << " "; \
    cout << "\n"

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define t_cases \
    int t;      \
    cin >> t;   \
    while (t--)

#define debug(a) cout << a << "\n"

using intl = long long;
using vi = vector<int>;
using vd = vector<double>;
using vil = vector<intl>;
using pi = pair<int, int>;
using pil = pair<intl, intl>;
using vpi = vector<pair<int, int>>;
using vpil = vector<pair<intl, intl>>;

const intl MOD = 1000000007;
const intl MAXL = 1000;

intl gcd(intl a, intl b) {

    if (a == 0) return b;
    return gcd(b % a, a);

}

intl lcm(intl a, intl b) {
    return (a * b) / gcd(a, b);
}

void solve() {

    int n; cin >> n;
    vil a(n); repi(n) cin >> a[i];

    intl d = 1;

    repi(n) {

        d = lcm(d, i + 2);

        if (a[i] % d == 0) {
            cout << "NO\n";
            return;
        }


    }

    cout << "YES\n";

}

int main() {

    FAST;

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    t_cases solve();
    //  solve();

}