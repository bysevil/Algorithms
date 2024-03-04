void swap(int* a, int* b){
    *b ^= *a;
    *a ^= *b;
    *b ^= *a;
}

void AdjustDown(int* nums, int parent, int numsSize){
    int child = parent * 2 + 1;
    while(child < numsSize){
        if(child+1 < numsSize && nums[child] < nums[child+1])
            child++;
        if(nums[child] > nums[parent]){
            swap(nums+child,nums+parent);
            parent = child;
            child = parent * 2 + 1;
        }
        else
            break;
    }
}


void HeapSort(int* nums, int numsSize){
    for(int i = numsSize-1; i >= 0; i--)
        AdjustDown(nums,i,numsSize);
    
    for(int i = numsSize - 1; i > 0; i--){
        swap(nums,nums+i);
        AdjustDown(nums,0,i);
    }
}

