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

short int memori8 [100010][1010];
vll coins(1010);
ll N;

int checkSumPossible (ll target, ll iterator) {

    if (target == 0){
        return 1;
    } 

    if (iterator <= 0){
        return 0;
    } 

    if(coins[iterator-1] > target){
        return checkSumPossible(target, iterator-1);
    }

    if(memori8[target][iterator-1] != -1){
        return memori8[target][iterator-1];
    }

    int withoutCurrentCoin = checkSumPossible(target, iterator-1);
    int withCurrentCoin = checkSumPossible(target - coins[iterator], iterator-1);
    return memori8[target][iterator-1] = (withoutCurrentCoin == 1 || withCurrentCoin == 1);
}

int main() {
    FASTIO;

    memset(memori8, -1, sizeof(memori8));

    ll T;

    cin >> T >> N;

    for (ll i = 0; i < N; i++) {
        cin >> coins[i];
    }

    if(checkSumPossible(T, N-1) == 1)
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}