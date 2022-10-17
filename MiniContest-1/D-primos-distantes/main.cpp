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
#define MAX_TAM 1299709

vector<bool> sieveOfEratosthenes(ll n) {
    vector<bool> prime(n+1, true);

    prime[0] = prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (prime[i] && i * i <= n) {
            for (ll j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    return prime;
}

vll generateOrderedPrimeArray(ll n, vector<bool> sieve){
    vll primes;

    for( ll i = 0; i < n; i++){
        if(sieve[i]){
            primes.push_back(i);
        }
    }
    return primes;
}


int main() {
    FASTIO;

    
    ll n;
    vector<bool> sieve = sieveOfEratosthenes(MAX_TAM);
    vll primes = generateOrderedPrimeArray(MAX_TAM, sieve);

    while (cin >> n) {
        if(n == 0)
            break;
        
        if(sieve[n]){
            cout << 0 << endl;
            continue;
        }
        
        auto upperPrime = upper_bound(primes.begin(), primes.end(), n);
        auto lowerPrime = lower_bound(primes.begin(), primes.end(), n);
        if(upperPrime != primes.end() && lowerPrime != primes.end()){
            cout << primes[upperPrime - primes.begin()] - primes[lowerPrime - primes.begin() - 1] << endl;
        }
    }
    return 0;
}