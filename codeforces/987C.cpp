#include <bits/stdc++.h>
 
using namespace std;
 
const long long int inf = 10000000000;
 
const int MAX = 3002;
 
long long int lista[MAX];
long long int custo[MAX];
long long int dp[MAX][4];
 
long long int c, a, ans;
 
int n;
 
long long int bruto(int i, int ant, int rest){
    if(rest == 0)
        return 0;
    if(i == n+1)
        return inf;
 
    if(lista[i] > lista[ant]){
        if(dp[i][rest] == inf)
            dp[i][rest] = bruto(i + 1, i, rest - 1) + custo[i];
 
        c = bruto(i + 1, ant, rest);
 
        return min(dp[i][rest], c);
    } else
        return bruto( i + 1, ant, rest);
}
 
void prep(){
    for(int i = 0; i < n+2; i++)
        for(int j = 0; j < 4; j++)
            dp[i][j] = inf;
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 1; i < n+1; i++){
        cin >> a;
        lista[i] = a;
	}
	for(int i = 1; i < n+1; i++){
        cin >> a;
        custo[i] = a;
	}
	prep();
 
	ans = bruto(1, 0, 3);
 
	if(ans < inf)
        cout << ans;
    else
        cout << -1;
 
    cout << endl;
}