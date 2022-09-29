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

long long binPowMod(long long x, long long n) {
    if (n == 0)
        return 1;
    long long res = binPowMod(x, n / 2);
    if (n % 2)
        return res%MOD * res%MOD * x%MOD ;
    else
        return res%MOD * res %MOD;
}

int main() {
    FASTIO;

    long long numberOfTests;
    cin >> numberOfTests;

    long long tests[numberOfTests*2], resultOfTests[numberOfTests];
    for(int j = 0; j < numberOfTests*2; j+=2) {
      cin >> tests[j];
      cin >> tests[j + 1]; 
    }

    for (int j = 0; j < numberOfTests*2; j+=2) {
      resultOfTests[j] = binPowMod(tests[j], tests[j + 1]);
      cout << resultOfTests[j] << "\n";
    }
    
    return 0;
}