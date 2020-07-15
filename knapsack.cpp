#include<bits/stdc++.h>
using namespace std;

int optimal_weight(int W, vector<int> w) {
  //write your code here
  /*int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;*/
	sort(w.begin(),w.end());
	
	int n=w.size();
	
	vector<vector<int>>v(n+1,vector<int>(W+1));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			v[i][j]=v[i-1][j];
			if(w[i-1]<=j){
				int val=v[i-1][j-w[i-1]]+w[i-1];
				if(val>v[i][j])
					v[i][j]=val;
			}
		}
	}
	return v[n][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
