#include <bits/stdc++.h>

using namespace std;

int minimum(int a,int b,int c){
	return (a<b)?(a<c?a:c):(b<c?b:c);
}
int edit_distance(const string &str1, const string &str2) {
  //write your code here
	int m=str1.length();
	int n=str2.length();
	vector<vector<int>>v(m+1, vector<int>(n+1));
	for(int i=0;i<=m;i++){
		v[i][0]=i;
	}
	for(int i=0;i<=n;i++){
		v[0][i]=i;
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(str1[i-1]!=str2[j-1]){
				v[i][j]=minimum(v[i][j-1]+1, v[i-1][j]+1, v[i-1][j-1]+1);
			}
			else{
				v[i][j]=minimum(v[i][j-1]+1, v[i-1][j]+1, v[i-1][j-1]);
			}
		}
	}

  return v[m][n];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
