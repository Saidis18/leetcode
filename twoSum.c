/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 /*
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    void aux(int index, int* result){
        if (index < numsSize){
            bool found = false;
            for (int i = index + 1; i < numsSize; i++){
                if(nums[index] + nums[i] == target){
                    result[0] = index;
                    result[1] = i;
                    found = true;
                    break;
                }
            }
            if(!found){
                aux(index + 1, result);
            }
        }
    }
    int *result = malloc(sizeof(int)*2);
    *returnSize = sizeof(result)/sizeof(int);
    aux(0, result);
    return result;
}
*/

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int **values_and_indices = (int**)malloc(sizeof(int*) * numsSize);
    for(int i = 0; i < numsSize; i++){
        values_and_indices[i] = (int*)malloc(sizeof(int)*2);
        values_and_indices[i][0] = nums[i];
        values_and_indices[i][1] = i;
    }

    int cmp(const void *a, const void *b){
        int x = (*(const int**)a)[0];
        int y = (*(const int**)b)[0];
        return x - y;
    }

    qsort(values_and_indices, numsSize, sizeof(int*), cmp);

    int start = 0;
    int end = numsSize-1;
    int sum = values_and_indices[start][0] + values_and_indices[end][0];
    while(sum != target){
        if(sum > target){
            end--;
        }else{
            start++;
        }
        sum = values_and_indices[start][0] + values_and_indices[end][0];
    }

    int *result = malloc(sizeof(int)*2);
    result[0] = values_and_indices[start][1];
    result[1] = values_and_indices[end][1];

    for(int i = 0; i < numsSize; i++){
        free(values_and_indices[i]);
    }
    free(values_and_indices);

    *returnSize = sizeof(result)/sizeof(int);
    return result;
}

int main(){
    return 0;
}