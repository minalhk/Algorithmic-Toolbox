#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int count=0;
    int n=stops.size();
    int currRefill=0;
    auto it = stops.insert(stops.begin(), 0);
    it = stops.insert(stops.begin() + n+1, dist);
    
    while(currRefill<=n){
        int lastRefill=currRefill;
        while(currRefill<=n && stops[currRefill+1]-stops[lastRefill]<=tank){
            
            currRefill+=1;

        }
            
        if(currRefill==lastRefill)
            return -1;
        if(currRefill<=n)
            count++;
    }
    return count;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
