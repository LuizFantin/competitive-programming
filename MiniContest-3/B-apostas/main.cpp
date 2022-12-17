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

vll ans(1000010);

void calculateAnswer(){
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;
    ans[4] = 8;
    ans[5] = 16;
    ans[6] = 32; 
    for(int i = 7; i < 1000010; i++){
        ans[i] = (ans[i-1] + ans[i-2] + ans[i-3] + ans[i-4] + ans[i-5] + ans[i-6]) %MOD;
    }
}

int main() {
    FASTIO;
    ll n;

    calculateAnswer();

    while (true){
        cin >> n;
        if(n == 0){
            break;
        }

        cout << ans[n] << endl;

    }
    return 0;
}