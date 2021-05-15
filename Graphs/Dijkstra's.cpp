#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define f(i,n) for(int i = 0;i <(int)(n);++i)
#define fr(i,n) for(int i = (int)(n) - 1;i>=0;i--)
#define rep(i,a,b) for(int i = (int)(a); i<=(int) (b); ++i)
#define repr(i,a,b) for(int i = (int)(b); i>=(int) (a); i--)
#define ar array
#define ll long long
#define rnd(x) cout<<setprecision((int)(x) +1)
#define nl "\n"

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int,int>> vpi;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" = ";_print(x); cerr<<endl;
#else
#define debug(x)
#endif

template<class T> void _print(T a){
    cerr<<a; 
}

template<class T> void _print(vector<T> vi){
    cerr<<"[ ";
    for(T i:vi){ _print(i); cerr<<" ";}
    cerr<<"]"; 
}

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n;
vi dist(MAX_N,INT_MAX);
vpi adj[MAX_N];
priority_queue<pi,vpi, greater<pi>> pq;


void shortest(int src){
	pq.emplace(0,src);
	dist[src] = 0;
	while(!pq.empty()){
		int dis  = pq.top().fi;
		int prev = pq.top().se;
		pq.pop();
		debug(prev);
		for(auto x:adj[prev]){
			int nxt = x.fi;
			int nxtDst = x.se;
			debug(nxt);
			if(dist[prev] + nxtDst <dist[nxt]){
				dist[nxt] = dist[prev] + nxtDst;
				pq.emplace(dist[nxt],nxt);
			}
		}
		rep(i,1,n){
			cerr<<dist[i]<<" ";
		}
		cerr<<nl;
	}
}

void Solve(){
	int e;
	cin>>n>>e;
	f(i,e){
	    int x,y,z;
	    cin>>x>>y>>z;
	    adj[x].eb(y,z);
	    adj[y].eb(x,z);
	}
	rep(i,1,n){
		cout<<i<<" -> ";
		for(auto x:adj[i])
			cout<<x.fi<<" "<<x.se<<" ";
		cout<<nl;
	}
	int start;
	cin>>start;
	shortest(start);
	debug(start);
	rep(i,1,n){
		cout<<dist[i]<<" ";
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
    #endif
    int t = 1;
    //cin>>t;
    while(t--){
        Solve();
    }
}

/*
	Testcase for the code
	5 6
	1 2 2
	1 4 1
	2 3 4
	4 3 3
	3 5 1
	2 5 5
	1
*/