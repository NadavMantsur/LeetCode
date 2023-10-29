#include <stdio.h>

/*returns the index of the target if it is in nums, otherwise -1*/
int search(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1, mid = 0;

    while (left <= right){ 
        mid = left + (right - left) / 2;

        if (target == nums[mid]){
            return mid;
        }

        /*check if the left section is sorted*/
        if (nums[left] <= nums[mid]){
            if (target >= nums[left] && target < nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        else{
            if (target > nums[mid] && target <= nums[right]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main(void){
    int nums[] = {4,5,6,7,0,1,2};
    int target = 0;
    int nums2[] = {1};
    int target2 = 1;
    /*that case is the reason to not using the condition (left < right) in the 
    while loop*/

    printf("%d\n", search(nums, 7, target));

    return 0;
}