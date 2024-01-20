// 插入排序
void swap(int* a, int* b){
    *b ^= *a;
    *a ^= *b;
    *b ^= *a;
}

void InsertSort(int* nums, int numsSize){
    for(int i = 1; i < numsSize; i++){
        for(int j = i-1; j >= 0; j--){
            if(nums[j+1] < nums[j])
                swap(nums+j+1,nums+j);
            else
                break;
        }
    }
}