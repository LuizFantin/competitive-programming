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

vll moedas;

int main() {
    FASTIO;

    ll v, m;
    cin >> v >> m;
    moedas.resize(m);

    FOR(i, 0, m){
        cin >> moedas[i];
    }

    vector<vector<bool>> dp(m+1, vector<bool>(v+1, false));
    FOR(i, 0, m+1){
        dp[i][0] = true;
    }

    for(ll c = 1; c <= m; c++){
        ll valorMoeda = moedas[c-1];
        for(ll j = 1; j <= v; j++){
            if(j < valorMoeda){
                dp[c][j] = dp[c-1][j];
            }
            else{
                dp[c][j] = dp[c-1][j] || dp[c-1][j-valorMoeda];
            }
        }
    }

    cout << (dp[m][v] ? "S" : "N") << endl;

    return 0;
}