#include<stdio.h>
// 选择排序
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void SelectSort(int* nums, int NumsSize){
    for(int i = 0; i < NumsSize; i++){
        int max = NumsSize-i-1;
        int min = i;
        for(int j = i; j < NumsSize - i; j++){
            if(nums[j] < nums[min])
                min = j;
            if(nums[j] > nums[max])
                max = j;
        }
        if(nums[max] == nums[min])
            break;
        swap(nums+min,nums+i);
        if(nums+i == nums+max)
            max = min;
        swap(nums+max,nums+NumsSize-i-1);
    }
}
