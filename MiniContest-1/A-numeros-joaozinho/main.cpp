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

/*
    Return the numbers in an interval that the sum of the digits in 10, 12 and 16 base is equal.
*/

ll formatSum(ll number, ll base){
    ll soma = 0;
    while(number > 0){
        soma += number % base;
        number /= base;
    }
    return soma;
}

int main() {
    FASTIO;

    ll a, b;

    cin >> a;
    cin >> b;

    for(ll i = a; i <= b; i++) {
        if(formatSum(i, 10) == formatSum(i, 12) && formatSum(i, 10) == formatSum(i, 16)){
            cout << i << endl;
        }
    }

    return 0;
}