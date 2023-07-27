#include <stdio.h>
#include <vector>

using namespace std;

void findMedianPosition (
    int target
    ,vector<int>& arr1, int begin1, int end1, int& found1
    ,vector<int>& arr2, int begin2, int end2, int& found2) {

    //printf("\ntarget=%d, arr1={%d,%d}, arr2 = {%d,%d}", target, begin1, end1, begin2, end2);
    
    if (end1 < 0) {
        
        found1 = -1;
        found2 = target;
        return;
        
    } else if (end2 < 0) {
        
        found1 = target;
        found2 = -1;
        
        return;
    }
    else if (begin1 > end1) {
        
        int count1 = end1+1;
        found1 = -1;
        found2 = target - count1;
        
        return;
        
    } else if (begin2 > end2) {

        int count2 = end2+1;
        found1 = target - count2;
        found2 = -1;

        return;
    }
    
    int count1 = end1 - begin1 + 1;
    int count2 = end2 - begin2 + 1;
    
    int mid1 = begin1 + count1/2;
    int mid2 = begin2 + count2/2;
    
    if (arr1[mid1] >= arr2[mid2]) {
        
        int pivot = mid1 + mid2 + 1;
        
        if (target >= pivot) {
            findMedianPosition(target, arr1, mid1, end1, found1, arr2, mid2+1, end2, found2);
        } else {
            findMedianPosition(target, arr1, 0, mid1-1, found1, arr2, 0, end2, found2);
        }
        
    } else {
        
        int pivot = mid1 + mid2 + 1;
        
        if (target >= pivot) {
            findMedianPosition(target, arr1, mid1+1, end1, found1, arr2, mid2, end2, found2);
        } else {
            findMedianPosition(target, arr1, 0, end1, found1, arr2, 0, mid2-1, found2);
        }
    }
    
    return;
}

float calculateMedianOfArrays(vector<int>& arr1, int n1, vector<int>& arr2, int n2){
    
    int posMid = (n1+n2)/2;
    int posMid2 = -1;
    if ( (n1+n2) % 2 == 0) {
        posMid2 = posMid-1;
    }
    
    int valueMid = -1;
    int valueMid2 = -1;

    if (n1 == 0) {
        valueMid = arr2[posMid];
        if (posMid2 > -1) 
            valueMid2 = arr2[posMid2];
    }
    else if (n2 == 0) {
        valueMid = arr1[posMid];
        if (posMid2 > -1) 
            valueMid2 = arr1[posMid2];
    }
    else if (arr1[0] < arr2[0] && arr1[n1-1] < arr2[0]){
        
        if (posMid < n1) 
            valueMid = arr1[posMid];   
        else
            valueMid = arr2[posMid-n1];

        if (posMid2 > -1) {
            if (posMid2 < n1)
                valueMid2 = arr1[posMid2];   
            else
                valueMid2 = arr2[posMid2-n1];
        }
    } 
    else if (arr1[0] > arr2[n2-1] && arr1[n1-1] > arr2[n2-1]) {
        
        if (posMid < n2)
            valueMid = arr2[posMid];   
        else 
            valueMid = arr1[posMid-n2];

        if (posMid2 > -1) {
            if (posMid2 < n2)
                valueMid2 = arr2[posMid2];   
            else 
                valueMid2 = arr1[posMid2-n2];
        }
    }
    else {
        
        int found1 = -1;
        int found2 = -1;
        
        findMedianPosition(posMid, arr1, 0, n1-1, found1, arr2, 0, n2-1, found2);
        
        if (found1 > -1) 
            valueMid = arr1[found1];
        else if (found2 > -1) 
            valueMid = arr2[found2];

        if (posMid2 > -1) {
            found1 = -1;
            found2 = -1;
            findMedianPosition(posMid2, arr1, 0, n1-1, found1, arr2, 0, n2-1, found2);
            if (found1 > -1) 
                valueMid2 = arr1[found1];
            else if (found2 > -1) 
                valueMid2 = arr2[found2];
        }
        
        printf("\nfound1 = %d, found2 = %d",found1, found2);   
    }
    
    if (valueMid2 < 0) return valueMid;
    return (valueMid + valueMid2) / 2.0;
}

int main()
{
    //printf("a");
    //return 1;
    
    vector<int> arr1 = {5,3};
    int n1 = arr1.size();
    
    vector<int> arr2 = {};
    int n2 = arr2.size();
    
    float median = calculateMedianOfArrays(arr1, n1, arr2, n2);
    printf("\nMEDIAN = %.2f",median);
    
    return 0;
}
