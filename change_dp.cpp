#include <bits/stdc++.h>
using namespace std;
int get_change(int m) {
  //write your code here
	int coins[]={4,3,1};
	int numCoins=0;
	vector<int> minNumCoins(m+1,INT_MAX);
	minNumCoins[0]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<3;j++){
			if(i>=coins[j]){
				numCoins=minNumCoins[i-coins[j]]+1;
				if(numCoins<minNumCoins[i])
					minNumCoins[i]=numCoins;
			}
		}
	}	

  return minNumCoins[m];
}

int main() {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
