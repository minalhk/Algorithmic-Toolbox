#include <iostream>
long gcd_naive(long a, long b) {
  if(b==0)
    return a;
  a=a%b;
  return gcd_naive(b,a);
}

long long lcm_naive(int a, int b) {
  return ((long long)a*b)/gcd_naive(a,b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
