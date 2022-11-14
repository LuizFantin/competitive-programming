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

    ll n, m;

    cin >> n >> m;

    multiset<ll> tickets;

    for (ll i = 0; i < n; i++){
        ll input;
        cin >> input;
        tickets.insert(input);
    }

    for(ll j = 0; j < m; j++){
        ll clientPrice;
        cin >> clientPrice;

        if(tickets.size() == 0){
            cout << -1 << endl;
            continue;
        }

        auto currentTicket = tickets.lower_bound(clientPrice);

        if(*currentTicket == clientPrice){
            cout << (*currentTicket) << endl;
            tickets.erase(currentTicket);
            continue;
        }

        --currentTicket;
       
        if(currentTicket != tickets.end()){
            
            if(*currentTicket < clientPrice){
                cout << (*currentTicket) << endl;
                tickets.erase(currentTicket);
                continue;
            }
            else{
                cout << -1 << endl;
            }
        }
        else{
            cout << -1 << endl;
        }
    }
    


    return 0;
}