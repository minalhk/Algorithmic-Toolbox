#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  
  vector<int>v(n+1,0);
  v[0]=0;
  v[1]=1;

  for(int i=2;i<=n;i++){
    v[i]=v[i-1]+1;
    if(i%2==0  && v[i]>v[i/2]+1){
      v[i]=v[i/2]+1;
    }
    if(i%3==0 && v[i]>v[i/3]+1){
      v[i]=v[i/3]+1;
    }
  }

  for(int i=n;i>0;){
    sequence.push_back(i);
    if(v[i-1]==v[i]-1)
      i--;
    else if(v[i/2]==v[i]-1)
      i/=2;
    else if(v[i/3]==v[i]-1)
      i/=3;
  }


  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
