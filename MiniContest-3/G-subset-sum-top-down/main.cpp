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

char memori8 [100010][1010];
vll coins(1010);
ll N;

char somaPossivel (ll alvo, ll iterator) {

    if (alvo == 0){
        return '1';
    } 

    if (alvo < 0 || iterator >= N){
        return '0';
    } 

    if (memori8[alvo][iterator] != 'x'){
        return memori8[alvo][iterator];
    } 
    char x1 = somaPossivel(alvo, iterator+1);
    char x2 = somaPossivel(alvo - coins[iterator], iterator+1);
    return memori8[alvo][iterator] = (x1 == '1' || x2 == '1' ? '1' : '0');
}

int main() {
    FASTIO;

    memset(memori8, 'x', sizeof(memori8));

    ll T;

    cin >> T >> N;

    for (ll i = 0; i < N; i++) {
        cin >> coins[i];
    }

    if(somaPossivel(T, 0) == '1')
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}