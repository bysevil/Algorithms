// 希尔排序
void swap(int* a, int* b){
    *b ^= *a;
    *a ^= *b;
    *b ^= *a;
}

void shellSort(int* nums, int numsSize){
    int gep = numsSize;
    while(gep > 1){
        gep = gep / 3 + 1;
        for(int i = 1; i < numsSize; i++){
            for(int j = i-gep; j >= 0; j -= gep){
                if(nums[j+gep] < nums[j])
                    swap(nums+j+gep,nums+j);
                else
                    break;
            }
        }
    }
}