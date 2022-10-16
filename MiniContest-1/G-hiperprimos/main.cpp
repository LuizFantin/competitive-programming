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
#define MAX_TAM 2000010

vector<bool> sieveOfEratosthenes(ll n) {
    vector<bool> prime(n+1, true);

    prime[0] = prime[1] = false;
    for (long long i = 2; i <= n; i++) {
        if (prime[i] && i * i <= n) {
            for (long long j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }
    return prime;
}

ll countDivisors(ll n) {
    ll numberOfDivisors = 0;
    ll i;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0)
            numberOfDivisors++;
    }
    if (i - (n / i) == 1) {
        i--;
    }
    for (; i >= 1; i--) {
        if (n % i == 0)
            numberOfDivisors++;
    }

    return numberOfDivisors;
}

vector<bool> perfectSquareIsHyperPrime(ll n, vector<bool> sieve){
    vector<bool> perfectSquares(n+1, false);

    for (ll i = 2; i*i <= n; i++){
        if(sieve[countDivisors(i*i)]){
            perfectSquares[i*i] = true;
        }
    }

    return perfectSquares;
    
}

int main() {
    FASTIO

    ll n;
    ll countOfHyperPrimes;
    vector<bool> sieve = sieveOfEratosthenes(MAX_TAM);
    vector<bool> perfectSquares = perfectSquareIsHyperPrime(MAX_TAM, sieve);

    vll hyperPrimes(MAX_TAM, 0);
    hyperPrimes[2] = 1;
    for(ll i = 3; i < hyperPrimes.size(); i++) {
        if(sieve[i] || perfectSquares[i]){
            hyperPrimes[i] = hyperPrimes[i - 1] + 1;
            continue;
        }
        hyperPrimes[i] = hyperPrimes[i-1];
    }
    while(cin >> n){
        cout << hyperPrimes[n] << endl;
    }
    return 0;
}