// 冒泡排序
void BubbleSort(int* nums, int numsSize){
    for(int i = numsSize; i > 0;i--){
        for(int j = 1; j < i; j++){
            if(nums[j-1] > nums[j])
                swap(nums+j-1,nums+j);
        }
    }
}

