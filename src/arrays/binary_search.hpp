#include <vector>
#include <cmath>

using namespace std;

int binary_search(vector<int>& nums, int target) {
    int start = 0;
    int middle = floor((nums.size() - 1) / 2);
    int last = nums.size() - 1;
    
    while(true){
        if(target != nums[middle] && middle == start){
            if(target < nums[0]) return 0;
            if(target > nums[last]) return last + 1;
            if(target < nums[last]) return last;

            return last;
        }
        
        if(target == nums[middle]) break;
        
        if(target > nums[middle]) start = middle;
        if(target < nums[middle]) last = middle;
        
        middle = floor((last - start) / 2) + start;
    }
    
    return middle;
}