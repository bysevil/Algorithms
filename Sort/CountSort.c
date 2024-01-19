/*///////////////////////////////////////////////////////
 *
 *         ------计数排序------
 * 1. 统计出每个数出现的次数,映射到计数数组
 * 2. 从小至大遍历计数数组
 * 3. 这个数有几个，则在排序数组里添加几个这个数，为0时不添加    
 * 4. 排序数组即为排序后的数组
 *        
 * 适用: 适合范围集中的数据，只能适用整型排序
 * 空间复杂度: O(N+Range)
 * 时间复杂度: O(Range)
/*////////////////////////////////////////////////////////

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

int main(){
    int nums[] = {1001,1003,1009,1008,1005,1009,1001};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    CountSort(nums,numsSize);

    //打印排序后数组
    for(int i = 0; i < numsSize; i++){
        printf("%d ",nums[i]);
    }
    printf("\n");

    return 0;
}