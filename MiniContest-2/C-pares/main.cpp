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

    ll N, I, f, count = 0;

    cin >> N;
    cin >> I;
    cin >> f;

    vll data(N);

    for (auto &item : data){
        cin >> item;
    }

    for (ll i = 0; i < N - 1; i++) {
        for(ll j = i+1; j < N; j++) {
            ll soma = data[i] + data[j];
            if(j != i && soma >= I && soma <= f)
                count++;
        }
    }

    cout << count << endl;

    return 0;
}