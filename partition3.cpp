#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
  //write your code here
	int sum=0;
	for(int i=0;i<A.size();i++){
		sum+=A[i];
	}
	if(sum%3!=0)
		return 0;

	int m=sum/3;
	int n=A.size();
	vector<vector<int>>v(n+1,vector<int>(m+1));
	v[0][0]=1;

	for(int i=1;i<=m;i++)
		v[0][i]=0;

	for(int i=1;i<=n;i++){
		int ele=A[i-1];
		for(int j=0;j<ele;j++)
			v[i][j]=v[i-1][j];
		for(int j=ele;j<=m;j++){
			if(v[i-1][j]==1 || v[i-1][j-ele]==1)
				v[i][j]=1;
		}
	}
	if(v[n][m]==1)
		return 1;

  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
