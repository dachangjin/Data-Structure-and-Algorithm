//
//  main.m
//  SortAlgorithm
//
//  Created by wangwei on 2019/5/31.
//  Copyright © 2019 WW. All rights reserved.
//

#import <Foundation/Foundation.h>

void bubbleSort(NSMutableArray<NSNumber *> *array);
void insertionSort(NSMutableArray<NSNumber *> *array);
void selectionSort(NSMutableArray<NSNumber *> *array);
void mergeSort(NSMutableArray<NSNumber *> *array);
void quickSort(NSMutableArray<NSNumber *> *array);
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
    }
    NSMutableArray *array = [NSMutableArray array];
    for (int i = 0; i < 1000; i ++) {
        [array addObject:[NSNumber numberWithInt:arc4random() % 1000]];
    }
    
    //    bubbleSort(array);
    //    insertionSort(array);
    //    selectionSort(array);
    //    mergeSort(array);
    quickSort(array);
    return 0;
}
/*
 冒泡排序：
 时间复杂度O(n^2)、原地排序算法、稳定
 最好时间复杂度O(n):已经是排好序的数组,只需要一次遍历，没有需要冒泡的元素
 最坏时间复杂度O(n^2):倒序数组，需要冒泡n次
 
 */
void bubbleSort(NSMutableArray<NSNumber *> *array)
{
    NSUInteger count = array.count;
    for (NSUInteger i = count - 1;i >= 0;i --) {
        BOOL bubbled = NO;
        for (NSUInteger j = 0; j < i; j ++) {
            if ([array[j] intValue] > [array[j + 1] intValue]) {
                bubbled = YES;
                NSNumber *temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        if (!bubbled) return;
    }
}

/*
 插入排序
 时间复杂度O(n^2)、原地排序算法、稳定
 最好时间复杂度O(n):已经是排好序的数组,每次插入不需要移动元素
 最坏时间复杂度O(n^2):倒序数组，每次插入需要移动元素到最前位置
 */
void insertionSort(NSMutableArray<NSNumber *> *array)
{
    NSUInteger count = array.count;
    for (NSInteger i = 1; i < count; i ++) {
        NSNumber *value = array[i];
        NSInteger j = i - 1;
        for (; j >= 0;j--) {
            if ([value intValue] < [array[j] intValue]) {
                //将元素向后移动
                array[j + 1] = array[j];
            }else{
                break;
            }
        }
        //替换元素
        array[j + 1] = value;
    }
}


/*
 选择排序
 时间复杂度O(n^2)、原地排序算法、不稳定（交换时有可能将前面的相同的元素交换到后面）
 最好时间复杂度O(n^2)
 最坏时间复杂度O(n^2)
 */
void selectionSort(NSMutableArray<NSNumber *> *array)
{
    NSUInteger count = array.count;
    for (NSUInteger i = 0; i < count; i ++) {
        int min = [array[i] intValue];
        NSUInteger minIndex = i;
        for (NSUInteger j = i; j < count; j ++) {
            if ([array[j] intValue] < min) {
                min = [array[j] intValue];
                minIndex = j;
            }
        }
        NSNumber *temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

void merge(NSMutableArray<NSNumber *> *array,NSUInteger p,NSUInteger q,NSUInteger r)
{
    NSMutableArray *tempArray = [NSMutableArray arrayWithCapacity:r - p];
    NSUInteger tempQ = q + 1;
    NSUInteger tempP = p;
    while (tempP <= q && tempQ <= r) {
        if ([array[tempP] intValue] <= [array[tempQ] intValue]) {
            [tempArray addObject:array[tempP]];
            tempP++;
        }else{
            [tempArray addObject:array[tempQ]];
            tempQ++;
        }
    }
    if (tempP == q+1) {
        for (NSUInteger i = tempQ; i <= r; i ++) {
            [tempArray addObject:array[i]];
        }
    }else{
        for (NSUInteger i = tempP; i <= q; i ++) {
            [tempArray addObject:array[i]];
        }
    }
    for (NSUInteger i = p; i <= r; i ++) {
        array[i] = [tempArray firstObject];
        [tempArray removeObjectAtIndex:0];
    }
}


void mergeSort_(NSMutableArray<NSNumber *> *array,NSUInteger p,NSUInteger r)
{
    if (p >= r) return;
    NSUInteger q = (p + r) / 2;
    mergeSort_(array, p, q);
    mergeSort_(array, q + 1, r);
    merge(array, p, q, r);
}

/*
 归并排序
 时间复杂度O(nlogn)、非原地排序算法，合并时需要用到临时数组、稳定
 最好时间复杂度O(nlogn)
 最坏时间复杂度O(nlogn)
 */
void mergeSort(NSMutableArray<NSNumber *> *array)
{
    mergeSort_(array, 0, array.count - 1);
}

NSInteger getPartition(NSMutableArray<NSNumber *> *array,NSInteger start,NSInteger end)
{
    if (start >= end) return end;
    int partitionValue = [array[end] intValue];
    NSInteger littleEnd = start;
    for (NSInteger i = start; i < end; i ++) {
        if ([array[i] intValue] < partitionValue) {
            NSNumber *temp = array[littleEnd];
            array[littleEnd] = array[i];
            array[i] = temp;
            littleEnd ++;
        }
    }
    NSNumber *temp = array[littleEnd];
    array[littleEnd] = array[end];
    array[end] = temp;
    return littleEnd;
}

void quickSort_(NSMutableArray<NSNumber *> *array,NSInteger p,NSInteger r)
{
    if (p >= r) return;
    NSInteger partition = getPartition(array,p,r);
    quickSort_(array, p, partition-1);
    quickSort_(array, partition + 1, r);
}

/*
 快速排序
 时间复杂度O(nlogn)、原地排序算法、不稳定
 最好时间复杂度O(nlogn)
 最坏时间复杂度O(n^2)根据partitionValue决定，若每次partitionValue取的最大值，则会退化为n^2
 */
void quickSort(NSMutableArray<NSNumber *> *array)
{
    quickSort_(array, 0, array.count - 1);
}



