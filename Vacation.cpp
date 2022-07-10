
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
#define sqr(x) ((LL)(x) * (x))
#define endl "\n"
#define pb push_back
#define pp pop_back
#define fi first
#define se second
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define alla(arr, sz) arr, arr + sz
#define setbits(x) __builtin_popcount(x)
#define unsetbits(x) (int)log2(x)-setbits(x)+1
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(unordered_map <T, V> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T> void _print(unordered_set <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T> void _print(multiset <T> v) {cerr << "{ "; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

const int M = 1e9 + 7;
const int P = 1e8 + 10;
// vb isPrime(P, true);

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

ll binMul(ll a ,ll b){ll ans = 0 ;while(b){if (b&1){ans = (ans+  a)%M;}a = (a+a)%M;b>>= 1;}return ans ;}
ll binExp(ll a, ll b, int m) {a %= m;ll ans = 1;while (b) {if (b & 1) ans = binMul(ans,a);a = binMul(a,a);b = b >> 1;}return ans;}
// void sieve(){isPrime[0]=isPrime[1]=false;for(int i = 2; i*i < P; i++){if(isPrime[i]==true){ for(int j = i * i; j < P; j += i)isPrime[j] = false;}}}
ll gcd(ll a, ll b) {if (a == 0) return b; return gcd(b % a, a);}
ll lcm(ll a, ll b) {return ((a * b) / (gcd(a, b)));}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int n;
vector<vector<int>>activity(1e5+1,vector<int>(3,0));
// vector<vector<int>>dp(1e5+1,vector<int>(4,-1));

// int func(int day,int lastActivity){
//     if(day== 0 ){
//         int maxi= 0 ;
//         for(int i= 0 ;i<3;i++){
//             if(i!= lastActivity) maxi = max(maxi, activity[0][i]);
//         }
//         return dp[day][lastActivity]= maxi;
//     }
//     if(dp[day][lastActivity] != -1) return dp[day][lastActivity];
//     int maxi = 0 ;
//     for(int i= 0;i<3;i++){
//         if(i!= lastActivity) maxi = max(maxi , activity[day][i] + func(day-1,i));
//     }
//     return dp[day][lastActivity] = maxi;
// }

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    fastio();

    cin>>n;
    for(int i= 0 ;i<n;i++){
        for(int j= 0;j<3;j++){
            int x;
            cin>>x;
            activity[i][j] = x;
        }
    }
    debug(activity)
    // cout<<func(n-1,3)<<endl;
    vector<int> prev(n+1,0);
    prev[0] = max(activity[0][2],activity[0][1]);
    prev[1] = max(activity[0][2],activity[0][0]);
    prev[2] = max(activity[0][0],activity[0][1]);
    prev[3] = max(activity[0][2],max(activity[0][0],activity[0][1]));
    for(int day = 1;day<n;day++){
        vector<int> temp(n+1,0);
        for(int last = 0;last<4 ;last++){
            temp[last] = 0;
            for(int act = 0 ;act<3;act++){
                if(act!= last){
                    temp[last] = max(activity[day][act]+ prev[act], temp[last]);
                }
            }
        }
        prev = temp;
    }
    cout<<prev[n]<<endl;
    return 0;
}

/* Shlok Jakhotia */