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


    vll pai;
    vll tamanho;
    ll maxTam;

    void init(ll N) {
        pai.resize(N + 1);
        tamanho.resize(N + 1, 1);
        iota(pai.begin(), pai.end(), 0); 
    }

    ll find(ll x) { 
        if(x == pai[x]) 
            return x;
        else
            return pai[x] = find(pai[x]); 
    }

    void join(ll a, ll b) { 
        a = find(a);
        b = find(b);
        if (a != b) {
            if (tamanho[a] < tamanho[b])
                swap(a, b);
            pai[b] = a;
            tamanho[a] += tamanho[b];
            if(tamanho[a] > maxTam)
                maxTam = tamanho[a];
        }
    }

int main() {
    FASTIO;

    ll n,m;

    cin >> n;
    cin >> m;

    vll cities(n);

    init(n);
    iota(all(cities), 1);

    vpll ans;
    ll numberOfGroups = cities.size();

    for(ll i = 0; i < m; i++){
        ll first, second;

        cin >> first >> second;

        if(find(first) != find(second)){
            numberOfGroups--;
        }

        join(first, second);

        pll result;
        
        result.first = numberOfGroups;
        result.second = maxTam; 
        ans.push_back(result);
    }

    for (auto i: ans){
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}