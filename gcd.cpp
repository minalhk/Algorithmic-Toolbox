#include <iostream>

int gcd_naive(int a, int b) {
  if(b==0)
    return a;
  a=a%b;
  return gcd_naive(b,a);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}
