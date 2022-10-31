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

#define filhoEsq(i) (2*(i) + 1)
#define filhoDir(i) (2*(i) + 2)

class SegTree {
private:
    vll st, A;
    ll size;

    ll el_neutro = 0;

    ll funcao(ll a, ll b) { // Função usada na SegTree: soma
        return a + b;
    }

    ll query(ll no, ll tl, ll tr, ll l, ll r){
        //O nó está fora do intervalo de interesse. 
        //Retorne o elemento neutro que não afeta a consulta.
        if(tr < l || r < tl)
            return el_neutro;

        // O nó está completamente incluído no intervalo de interesse. 
        // Retorne a informação contida no nó.
        if(tl >= l and tr <= r)
            return st[no];

        // Se chegarmos aqui, é porque esse nó está parcialmente contido no intervalo de interesse. 
        // Então, continuamos procurando nos filhos.
        ll m = tl + (tr - tl) / 2;
        return funcao(query(filhoEsq(no), tl, m, l, r), query(filhoDir(no), m + 1, tr, l, r));
    }

    void update(ll no, ll tl, ll tr, ll i, ll novoValor){
        // Chegamos no índice que queremos atualizar o valor
        if(tl == i and tr == i){
            st[no] = novoValor;
            A[i] = novoValor;
            return;
        }

        // O intervalo que estamos não contem o índice que queremos atualizar, retorne
        if(tl > i or tr < i)
            return;

        // O intervalo contém o índice, mas temos que chegar no nó específico. 
        // Repetimos o processo recursivamente nos filhos.
        ll m = tl + (tr - tl) / 2;
        update(filhoEsq(no),    tl,  m, i, novoValor);
        update(filhoDir(no), m + 1, tr, i, novoValor);

        // Após atualizar o filho (esquerdo ou direito), precisamos atualizar o valor do nó.
        st[no] = funcao(st[filhoEsq(no)], st[filhoDir(no)]);
    }

    void build(ll no, ll L, ll R) {
        //Chegamos no nó que deve conter o valor de A[L] ou A[R]
        if (L == R)
            st[no] = A[L];
        else {
            //Recursivamente construimos a SegTree
            ll m = L + (R - L) / 2;
            build(filhoEsq(no),     L, m);
            build(filhoDir(no), m + 1, R);
            st[no] = funcao(st[filhoEsq(no)], st[filhoDir(no)]);
        }
    }

public:
    SegTree(ll n): st(4*n, 0), A(n, 0), size(n){}
    SegTree(const vll &a) { 
        A = a;
        st.resize(4*A.size(), 0);
        size = A.size();
        build(0, 0, size - 1); 
    }
    ll query(ll l, ll  r) {
      return query(0, 0, size - 1, l, r);
    }
    void update(ll i, ll x){
      update(0, 0, size - 1, i, x);
    } 
};

int main() {

    FASTIO

    ll n, q;

    cin >> n >> q;

    vll a(n);

    for(auto &i: a){
        cin >> i;
    }

    vll ans;

    SegTree st(a);

    for(ll i = 0; i < q; i++){
        ll type, first, second;
        cin >> type >> first >> second;

        if(type == 1){
            st.update(first - 1, second);
        }

        else{
            ans.push_back(st.query(first - 1, second - 1));
        }
    }

    for (auto i: ans){
        cout << i << endl;
    }

    return 0;
}