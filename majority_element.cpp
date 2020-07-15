#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a) {
  /*if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here

  return -1;*/
  if(a.size()==1)
    return 1;
  
  sort(a.begin(),a.end());
  int count=1;
  for(int i=0;i<a.size()-1;i++){
    if(a[i]==a[i+1])
      count++;
    else
      count=1;
    
    if(count>(a.size()/2)){
      return 1;
    }
  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a)) << '\n';
}
