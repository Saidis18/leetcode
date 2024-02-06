#include <stdio.h>

int search_pivot(int* nums, int numsSize){
    if(numsSize <= 1){
        return 0;
    }
    if(nums[0] < nums[numsSize - 1]){
        return 0;
    }
    int start = 0;
    int end = numsSize - 1;
    while(end - start > 1){
        int center = (start + end)/2;
        if(nums[start] < nums[center]){
            start = center;
        }else{
            end = center;
        }
    }
    if(nums[start] > nums[end]){
        return end;
    }else{
        return start;
    }
}


int search(int* nums, int numsSize, int target) {
    if(numsSize == 0){
        return -1;
    }
    if(numsSize == 1){
        if(nums[0] == target){
            return 0;
        }else{
            return -1;
        }
    }

    int pivot = search_pivot(nums, numsSize);

    int start = 0;
    int end = numsSize - 1;
    while(end - start > 1){
        int center = (start + end)/2;
        if(nums[(center + pivot) % numsSize] < target){
            start = center;
        }else{
            end = center;
        }
    }
    if(nums[(start + pivot) % numsSize] == target){
        return (start + pivot) % numsSize;
    }else{
        if(nums[(end + pivot) % numsSize] == target){
            return (end + pivot) % numsSize;
        }else{
            return -1;
        }
    }
}


int main(){
    int array1[] = {7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6};
    int array2[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1};
    int array3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    printf("%d %d %d", search(array1, 12, 6), search(array2, 12, 6), search(array3, 12, 6));
    return 0;
}