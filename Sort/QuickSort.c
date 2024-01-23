void Swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* nums, int left, int right){
	int key = left;
	while (left < right){
		while (left < right && nums[right] >= nums[key])
		    right--;
		while (left < right && nums[left] <= nums[key])
			left++;
		Swap(nums + left, nums + right);
	}
	Swap(nums + key, nums + left);
    return left;
}
// 快速排序挖坑法
int PartSort2(int* nums, int left, int right){
	int key = left;
    while(left < right){
        while(left < right && nums[right] >= nums[key])
            right--;
        Swap(nums+right,nums+key);
        key = right;
        while(left < right && nums[left] <= nums[key])
            left++;
        Swap(nums+left,nums+key);
        key = left;
    }
    return key;
}

// 快速排序前后指针法
int PartSort3(int* nums, int left, int right){
    int key = left;
    int prev = left;
    int cur = left + 1;
    while(cur <= right){
        if(nums[cur] < nums[key] && ++prev < cur)
            Swap(nums+prev,nums+cur);
        cur++;
    }
    Swap(nums+prev,nums+key);
    return prev;
}


void QuickSort(int* a, int begin, int end){
	if (begin >= end)
		return;

	int key = PartSort2(a, begin, end - 1);

	QuickSort(a, begin, key);
	QuickSort(a, key + 1, end);
}
// 快速排序 非递归实现
void QuickSortNonR(int* nums, int left, int right){
    Stack* s = StackInit();
    StackPush(s,left);
    StackPush(s,right);

    while(!StackEmpty(s)){
        int end = StackPop(s);
        int begin = StackPop(s);

        int key = PartSort(nums,begin,end-1);

        if(begin < key - 1){
            StackPush(s,begin);
            StackPush(s,key);
        }
        if(key + 1 < end - 1){
            StackPush(s,key + 1);
            StackPush(s,end);
        }
    }
}
// 随机选key和三路划分优化最差情况
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void MidKey(int* nums, int left, int right){
	int mid = left + rand() % (right - left);
	if(nums[left] < nums[mid]){
		if(nums[mid] < nums[right])//left < mid < right
			swap(nums+left,nums+mid);
		if(nums[right] > nums[left])
			swap(nums+left,nums+mid);//left < right < mid
			
	}
	if(nums[left] > nums[mid]){
		if(nums[mid] > nums[right])
			swap(nums+left,nums+mid);//right < mid < left
		if(nums[left] > nums[right])
			swap(nums+left,nums+right);//mid < right < left
	}
}

void QuickSort(int* nums,int begin,int end){
    if(begin >= end - 1)
        return;
    MidKey(nums,begin,end-1);

    int key = nums[begin];
    int left = begin, right = end - 1;
    int cur = left + 1;
    while(cur <= right){
        if(nums[cur] < key){
            swap(nums+cur, nums+left);
            left++;
            cur++;
        }
        else if(nums[cur] > key){
            swap(nums+cur,nums+right);
            right--;
        }else{
            cur++;
        }
    }
    QuickSort(nums,begin,left);
    QuickSort(nums,right+1,end);
} 

int* sortArray(int* nums, int numsSize, int* returnSize) {
    QuickSort(nums,0,numsSize);
    *returnSize = numsSize;
    return nums;
}