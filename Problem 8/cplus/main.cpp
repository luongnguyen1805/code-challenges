#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int breakInteger(int n) {
    
    if (n <= 3) 
    {
        return n == 3 ? 2 : 1;
    }
    
    int k = 3;
    int d = n/k;

    int r = n - (d*k);
    
    if (r == 1) {
        d -= 1;
        r = n - (d*k);
    }
    
    return pow(k,d) * (r > 1 ? r : 1);
}

int main()
{
    int n = 50;
    
    printf("\nBEST = %f",(
        (n>3)
        ?pow(3,n/3-((n%3)&1)) * pow(2,(n+n%3)%3)
        :n-1)
        );
    printf("\MYSELF **! = %d",breakInteger(n));

    return 0;
}
