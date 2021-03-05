//
// Created by adl on 2020/11/9.
//

#include <cstdlib>
#include <ctime>
#include "myQsort.h"
// 返回 p, arr[l, p - 1] < arr[p]; arr[p + 1, r] > arr[p];
namespace adl {
    namespace qsort1 {
        template<typename T>
        int __partition(T arr[], int l, int r) {
            T v = arr[l];  // 选取第一个元素为基准值

            int j = l;
            for (int i = l + 1; i <= r; ++i) {
                if (arr[i] < v) {
                    swap(arr[++j], arr[i]);
                }
            }

            swap(arr[l], arr[j]);
            return j;
        }

        template<typename T>
        void __quickSort(T arr[], int l, int r) {
            if (l >= r) return;

            // 经过 __partition 后，[l, p-1] < arr[p]，[p + 1, r] > arr[p]
            T p = __partition(arr, l, r);
            __quickSort(arr, l, p - 1);
            __quickSort(arr, p + 1, r);
        }

        template<typename T>
        void quickSort(T arr[], int n) {
            __quickSort(arr, 0, n - 1);
        }
    }
    namespace qsort2 {
        template<typename T>
        int __partition(T arr[], int l, int r) {
            swap(arr[l], arr[rand() % (r - l + 1) + l]);
            T v = arr[l];

            // arr[l + 1, j] < v; arr[j + 1, i] > v;
            int j = l;
            for (int i = l + 1; i <= r; ++i) {
                if (arr[i] < v) {
                    swap(arr[++j], arr[i]);
                }
            }

            swap(arr[l], arr[j]);
            return j;
        }

// arr[l, r]
        template<typename T>
        void __quickSort(T arr[], int l, int r) {
            if (l >= r) return;
            srand(time(NULL));

            T p = __partition(arr, l, r);
            __quickSort(arr, l, p - 1);
            __quickSort(arr, p + 1, r);
        }

    }
    namespace qsort3 {
        template<typename T>
        int __partition2(T arr[], int l, int r) {
            swap(arr[l], arr[rand() % (r - l + 1) + l]);
            T v = arr[l];

            int i = l + 1, j = r;
            while (true) {
                while (i <= r && arr[i] < v) i++;
                while (j >= l + 1 && arr[j] > v) j--;
                if (i > j) break;
                swap(arr[i++], arr[j--]);
            }

            swap(arr[l], arr[j]);
            return j;
        }
    }
}