#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define ar array
#define ll long long
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define f(i,n) for(int i = 0;i <(int)(n);++i)
#define fr(i,n) for(int i = (int)(n) - 1;i>=0;i--)
#define rep(i,a,b) for(int i = (int)(a); i<=(int) (b); ++i)
#define repr(i,a,b) for(int i = (int)(b); i>=(int) (a); i--)
#define rnd(x) cout<<setprecision((int)(x) +1)

typedef vector<int> vi;
typedef pair<int, int> pi;

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

const int MAX_N = 1e4 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int r,c;
bool visited[MAX_N][MAX_N];

bool isValid(int a,int b){
	if( a<1 || a>r || b<1 || b>c)
		return false;
	if(visited[a][b])
		return false;
	return true;
}

//Grid positions

int dx[] = {0,0,-1,+1};
int dy[] = {-1,+1,0,0};

stack<pi> s;

//Recursive DFS
void recurdfs(int x,int y){
	visited[x][y] = 1;
	cout<<x<<" "<<y<<nl;
	f(i,4){
		if(isValid(x + dx[i], y+dy[i])){
			recurdfs(x+dx[i],y+dy[i]);
		}
	}
}
	/*
		Trying all the possible ways
		//Left
		if(isValid(x,y-1))
			dfs(x,y-1);

		//Right
		if(isValid(x,y+1))
			dfs(x,y+1);
		//Up
		if(isValid(x-1,y))
			dfs(x-1,y);
		//Down
		if(isValid(x+1,y))
			dfs(x+1,y);
	*/

//Iterative DFS
void dfs(){

	s.emplace(1,1);
	while(!s.empty()){
		int x = s.top().fi;
		int y = s.top().se;
		s.pop();
		if(visited[x][y]) continue;
		visited[x][y] = 1;
		cout<<x<<" "<<y<<nl;
		// rep(i,1,3){
		// 	rep(j,1,3) cout<<visited[i][j]<<" ";
		// 	cout<<nl;
		// }
		f(i,4){
			if(isValid(x + dx[i], y+dy[i])){
				s.emplace(x + dx[i], y + dy[i]);
				cerr<<x+dx[i]<<" "<<y+dy[i]<<nl;
			}
		}
	}
}

void Solve(){
    cin>>r>>c;
    //dfs();
    //recurdfs(1,1);
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
	Test case
	3 3
*/
