//
// Created by adl on 2020/11/9.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int __patition(int *pInt, int l, int r);

void Swap(int *p, int *q) {
    int buf;
    buf = *p;
    *p = *q;
    *q = buf;
    return;
}

void swap(int *p, int *q) {
    int buf;
    buf = *p;
    *p = *q;
    *q = buf;
    return;
}

void QuickSort(int *a, int low, int high) {
    int i = low;
    int j = high;
    int key = a[low];
    if (low >= high) //如果low >= high说明排序结束了
        return;
    while (low < high) //该while循环结束一次表示比较了一轮
    {
        while (low < high && key <= a[high]) {
            --high; //向前寻找
        }
        if (key > a[high]) {
            Swap(&a[low], &a[high]);
            ++low;
        }
        while (low < high && key >= a[low]) {
            ++low; //向后寻找
        }
        if (key < a[low]) {
            Swap(&a[low], &a[high]);
            --high;
        }
    }
    QuickSort(a, i, low - 1); //用同样的方式对分出来的左边的部分进行同上的做法
    QuickSort(a, low + 1, j); //用同样的方式对分出来的右边的部分进行同上的做法
}

void Qsort(int *arr, int left, int right) {
    if (left > right)
        return;
    /*如果左边>右边那就返回因为这一小部分排完了*/

    int i = left, j = right, pivot = arr[left];
    while (i < j) {
        /*找到比哨兵小的*/
        while (i < j && arr[j] >= pivot)j--;
        /*让它和*/
//        printf(":%d %d\n",i,j);
        arr[i] = arr[j];
        /*找到比哨兵大的*/
        while (i < j && arr[i] <= pivot)i++;
//        printf("%d %d:\n",i,j);
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    Qsort(arr, left, j - 1);
    Qsort(arr, i + 1, right);
}


int __partition2(int arr[], int l, int r) {
    swap(&arr[l], &arr[rand() % (r - l + 1) + l]);
    int v = arr[l];
/*放到左边*/
    int i = l + 1, j = r;
    while (1) {
        while (i <= r && arr[i] < v) i++;/*找到左边第一个比哨兵大的值*/
        while (j >= l + 1 && arr[j] > v) j--;/*找到右边第一个比哨兵小的值*/

        if (i > j) break;
        /*交换大小*/
        swap(&arr[i++], &arr[j--]);
    }
/*交换哨兵和中间的值*/
    swap(&arr[l], &arr[j]);
    return j;
}

int __partition(int arr[], int l, int r) {
    swap(&arr[l], &arr[rand() % (r - l + 1) + l]);/*交换随机的哨兵和最左边的*/
    int v = arr[l];/*现在的最左边的值（哨兵）*/

    int j = l;

    for (int i = l + 1; i <= r; ++i) {
        /* 从左边第二个开始，若第i个小于哨兵，交换第i个和第j+1个*/
        if (arr[i] < v) {
            swap(&arr[++j], &arr[i]);
        }
    }
    swap(&arr[l], &arr[j]);
    return j;
}

void __quickSort(int arr[], int l, int r) {
    if (l >= r) return;
    srand(time(NULL));
    int p = __partition2(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

int main(int argc, char *argv[]) {
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    __quickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}