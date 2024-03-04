#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 归并排序递归实现
void _MergeSort(int* nums, int left, int right, int* tmp){
    if(left >= right - 1)
        return;
    int mid = (left & right) + ((left ^ right) >> 1);
    _MergeSort(nums,left,mid,tmp);
    _MergeSort(nums,mid,right,tmp);
    
    int begin1 = left, end1 = mid;
    int begin2 = mid, end2 = right;
    int i = 0;
    while(begin1 < end1 && begin2 < end2){
        tmp[i++] = nums[begin1] < nums[begin2] ? nums[begin1++] : nums[begin2++];
    }
    while(begin1 < end1)
        tmp[i++] = nums[begin1++];
    while(begin2 < end2)
        tmp[i++] = nums[begin2++];
    
    memcpy(nums+left,tmp,i * sizeof(int));
}

void MergeSort(int* nums, int numsSize){
    int* tmp = malloc(sizeof(int) * numsSize);
    _MergeSort(nums,0,numsSize,tmp);
    free(tmp);
}

// 归并排序非递归实现
void MergeSortNonR(int* nums, int numsSize){
    int* tmp = malloc(sizeof(int) * numsSize);
    int gep = 1;
    while(gep < numsSize){
        for(int i = 0; i < numsSize; i += 2 * gep){
            int begin1 = i, end1 = i + gep;
            int begin2 = i + gep, end2 = i + 2 * gep;
            if(end1 >= numsSize)
                break;
            if(end2 > numsSize)
                end2 = numsSize;
            
            int j = 0;
            while(begin1 < end1 && begin2 < end2)
                tmp[j++] = nums[begin1] < nums[begin2] ? 
                    nums[begin1++] : nums[begin2++];
            while(begin1 < end1)
                tmp[j++] = nums[begin1++];
            while(begin2 < end2)
                tmp[j++] = nums[begin2++];
            memcpy(nums+i,tmp,j * sizeof(int));
        }
        gep *= 2;
    }
    free(tmp);
}

int main(){
    int nums[] = { 5,2,1,0};
    MergeSortNonR(nums, sizeof(nums)/sizeof(nums[0]));
    return 0;
}