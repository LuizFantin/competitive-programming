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
    vll st, lazy;
    vector<bool> marked;
    ll size;

    ll funcao(ll a, ll b) { // Função usada na SegTree: soma
        return a + b;
    }

    void propagate(ll p, ll L, ll R) {
        if (marked[p]) {
            // O valor do nó será: número de elementos que esse intervalo representa vezes o novo valor de cada elemento do intervalo
            st[p] = lazy[p] * (R - L + 1);
            if (L != R) {
                lazy[filhoDir(p)] = lazy[filhoEsq(p)] = lazy[p];
                marked[filhoDir(p)] = marked[filhoEsq(p)] = true;
            }
            marked[p] = false;
        }
    }

    ll query(ll no, ll tl, ll tr, ll l, ll r){
        //Precisamos propagar a possível atualização do nó
        propagate(no, tl, tr);

        //O nó está fora do intervalo de interesse. Retorne o elemento neutro que não afeta a consulta.
        if(tr < l || r < tl)
            return 0;

        // O nó está completamente incluído no intervalo de interesse. Retorne a informação contida no nó.
        if(tl >= l and tr <= r)
            return st[no];

        // Se chegarmos aqui, é porque esse nó está parcialmente contido no intervalo de interesse. Então, continuamos procurando nos filhos.
        ll m = tl + (tr - tl) / 2;
        return funcao(query(filhoEsq(no), tl, m, l, r), query(filhoDir(no), m + 1, tr, l, r));
    }

    void update(ll no, ll tl, ll tr, ll l, ll r, ll novoValor){
        //Precisamos propagar a possível atualização do nó
        propagate(no, tl, tr);

        // Chegamos no índice que queremos atualizar o valor
        if (tl >= l and tr <= r) {
            lazy[no] = novoValor;
            marked[no] = true;
            propagate(no, tl, tr);
            return;
        }

        // O intervalo que estamos não contem o índice que queremos atualizar, retorne
        if (tl > r or tr < l)
            return;

        // O intervalo contém o índice, mas temos que chegar no nó específico. Repetimos o processo recursivamente nos filhos.
        ll m = tl + (tr - tl) / 2;
        update(filhoEsq(no),    tl,  m, l, r, novoValor);
        update(filhoDir(no), m + 1, tr, l, r, novoValor);

        // Após atualizar o filho (esquerdo ou direito), precisamos atualizar o valor do nó.
        st[no] = funcao(st[filhoEsq(no)], st[filhoDir(no)]);
    }

    void build(ll no, ll L, ll R, const vll &A) {
     //Chegamos no nó que deve conter o valor de A[L] ou A[R]
     if (L == R)
      st[no] = A[L];
     else {
      //Recursivamente construimos a SegTree
      ll m = L + (R - L) / 2;
      build(filhoEsq(no),     L, m, A);
      build(filhoDir(no), m + 1, R, A);
      st[no] = funcao(st[filhoEsq(no)], st[filhoDir(no)]);
     }
    }

public:
    SegTree(ll n) : st(4 * n, 0), lazy(4 * n, 0), marked(4 * n, false), size(n) {}
    SegTree(const vll &a) {
        size = a.size();
        st.resize(4 * size, 0);
        lazy.resize(4 * size, 0);
        marked.resize(4 * size, false);
        build(0, 0, size - 1, a); 
 }
    ll query(ll l, ll  r) {
     return query(0, 0, size - 1, l, r);
    }
    void update(ll i, ll x){
     update(0, 0, size - 1, i, i, x);
    }
    void update(ll l, ll r, ll x){
     update(0, 0, size - 1, l, r, x);
    }
};

int main() {

    FASTIO;

    ll n, q; 

    cin >> n;
    cin >> q;

    vll data(n);
    vll ans;

    for(auto &i : data){
        cin >> i;
    }
    SegTree st(data);

    for( ll i = 0; i < q; i++){
        ll type, k, a, b, u;
        cin >> type;
        if(type == 2){
            cin >> k;
            ans.push_back(st.query(k-1, k-1));
        }
        else{
            cin >> a;
            cin >> b;
            cin >> u;
        }
    }

    for (auto i: ans){
        cout << i << endl;
    }

    // cout << st.query(0, 4) << "\n";   // 5
    // cout << st.query(5, 9) << "\n";   // 0
    // cout << st.query(0, 9) << "\n";   // 5
    // cout << st.query(0, 0) << "\n";   // 1
    // cout << st.query(5, 5) << "\n";   // 0

    // st.update(5, 9, 2);
    // cout << st.query(0, 4) << "\n"; // 5
    // cout << st.query(5, 9) << "\n"; // 10
    // cout << st.query(0, 9) << "\n"; // 15
    // cout << st.query(0, 0) << "\n"; // 1
    // cout << st.query(5, 5) << "\n"; // 2

    // st.update(0, 9, 1);
    // cout << st.query(0, 4) << "\n"; // 5
    // cout << st.query(5, 9) << "\n"; // 5
    // cout << st.query(0, 9) << "\n"; // 10
    // cout << st.query(0, 0) << "\n"; // 1
    // cout << st.query(5, 5) << "\n"; // 1

    // st.update(5, 20);
    // cout << st.query(0, 4) << "\n"; // 5
    // cout << st.query(5, 9) << "\n"; // 24
    // cout << st.query(0, 9) << "\n"; // 29
    // cout << st.query(0, 0) << "\n"; // 1
    // cout << st.query(5, 5) << "\n"; // 20

    return 0;
}