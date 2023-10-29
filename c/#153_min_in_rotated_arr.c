#include <stdio.h>


int findMin(int* nums, int numsSize){
    int left = 0, right = numsSize - 1, mid = 0;

    while (left < right){
        mid = left + (right - left) / 2;

        if(nums[mid] < nums[right]){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }

    return nums[left];
}

int main(void){
    int nums[5] = {3,4,5,1,2};

    printf("the min num: %d\n", findMin(nums, 5)); 
    return 0;
}