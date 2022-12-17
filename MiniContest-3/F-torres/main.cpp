#include <bits/stdc++.h>
using namespace std;
 
typedef long long   ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); ++i)
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size()
#define MOD 1000000007ll
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (((a)/__gcd(a, b)) * b)
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0);


int main() {
    FASTIO;

    ll N;

    multiset<ll> towers;

    cin >> N;

    ll cubo;

    for (ll i = 0; i < N; i++) {
        cin >> cubo;

        if(towers.size() == 0){
            towers.insert(cubo);
            continue;
        }

        auto bound = towers.upper_bound(cubo);
        if(bound != towers.end() && *bound != cubo){
            towers.erase(bound);
        }
        towers.insert(cubo);
    }

    cout << towers.size() << endl;
    return 0;
}