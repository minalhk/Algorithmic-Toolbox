#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    
    int n = numbers.size();
    int max_index=-1;
    for (int i = 0; i < n; ++i)
    {
    	if((max_index==-1)||(numbers[i]>numbers[max_index]))
    		max_index=i;
    }
    int max_index2=-1;
    for (int i = 0; i < n; ++i)
    {
    	if ((i!=max_index) && ((max_index2==-1) || numbers[i]>numbers[max_index2]))
    	{
    		max_index2=i;
    	}
    }

    return ((long long)(numbers[max_index]))*numbers[max_index2];
    
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
