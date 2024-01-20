#include<stdlib.h>
#include<stdio.h>

//求数组中最大值
int maxnums(int* nums,int numsSize){
    int max = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(nums[i] > max) max = nums[i];
    }
    return max;
}

//求数组中最小值
int minnums(int* nums,int numsSize){
    int min = nums[0];
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < min) min = nums[i];
    }
    return min;
}

// 计数排序
void CountSort(int* nums,int numsSize){
    //确定计数数组大小
    int min = minnums(nums,numsSize);
    int max = maxnums(nums,numsSize);
    int span = max - min + 1;

    //创建计数数组
    int* count = (int*)calloc(span,sizeof(int));

    //计数
    for(int i = 0; i < numsSize; i++){
        count[nums[i]-min]++;
    }

    //排序
    for(int i = 0,j = 0; i < span; i++){
        while(count[i]--){
            nums[j++] = i + min;
        }
    }
    
    //释放空间
    free(count);
}