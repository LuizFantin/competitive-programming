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

typedef struct vertice {
    int no;
    struct vertice *next;
}Vertice;

typedef struct grafo {
    int V;
    int E;
    Vertice *adj;
}Grafo;

Grafo *createGrafo(int V){
    Grafo *grafo = (Grafo *) malloc(sizeof (Grafo));
    grafo->V = V;
    grafo->E = 0;
    grafo->adj = (Vertice *) calloc(V,sizeof (Vertice));
    return grafo;
}

Vertice *createVertice(int x){
    Vertice *vertice = (Vertice *) malloc(sizeof (Vertice));
    if(vertice == NULL) exit(1);
    vertice->no = x;
    vertice->next = NULL;
    return vertice;
}

void insertAresta(Grafo *G, int v, int w){
    Vertice *vertice = createVertice(w);
    vertice->next = G->adj[v].next;
    G->adj[v].next = vertice;
    G->E++;
}

int main() {
    FASTIO;

    int N;

    while(true){
        cin >> N;
        if(N == 0)
            break;
        
        queue<int> fila;
        vector<int> alc(N, false);
        vector<int> niv(N, 0);
        Grafo *grafo = createGrafo(N);
        fila.push(0);

        alc[0] = 1; 
        niv[0] = 1;

        for(int i = 0; i < N; i++){
            int current;
            cin >> current;

            char input[100];
            cin.getline(input, 100);

            char *ptr;

            ptr = strtok(input, " ");

            while (ptr != NULL){
                int x = atoi(ptr);
                insertAresta(grafo, current, x-1);
                ptr = strtok(NULL, " ");
            }
        }

        while(fila.size() != 0){
            int currentNode = fila.front();
            fila.pop();

            //? Parei na linha 9 do pseudocódigo
        }
    }

    return 0;
}