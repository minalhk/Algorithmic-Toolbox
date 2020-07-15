#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    int f[60]={0};

    f[0]=0;
    f[1]=1;
    for(int i=2;i<60;i++){
        f[i]=(f[i-1]+f[i-2])%10;
    }

    return f[n%60];
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
