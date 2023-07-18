
#include <iostream>
#include <string>
#include <math.h> 

using namespace std;

bool checkPossibility(vector<int>& nums) {
    
    int n = nums.size();
    int found = -1;
    for (int i = 0; i < n-1; i++) {
        if (nums[i] > nums[i+1]) {
            if (found > -1) return false;
            found = i;
        }
    }
    
    if (found <= 0 || found == n-2) return true;
    
    if (nums[found-1] <= nums[found+2]) { 
        if (nums[found-1] <= nums[found+1] || nums[found] <= nums[found+2]) return true;
    }
    
    return false;
}

int main() 
{
    return 0;
}