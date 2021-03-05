//
// Created by adl on 2020/11/9.
//

#include <cstdlib>
#include <iostream>
#include "myBsearch.h"


int mybsearch1(int arr[], int b, int e, int key) {
    /*left = 0 ,right=num.size-1*/
    /*找不到返回-1*/
    while (b <= e) {/*退出条件是b=e+1*/
        int mid = (b + e) / 2;
        if (arr[mid] > key) {
            e = mid - 1;
            continue;
        } else if (arr[mid] < key) {
            b = mid + 1;
            continue;
        } else {
            return mid;
        }
    }
    return -1;
}

int left_bound(int nums[], int l, int r, int target) {
    /*若不存在则返回大于它的那个节点的位置*/
    /*若存在则返回它的值最左边的值*/
    /*left = 0 ,right=num.size*/
    int left = l ,right=r;
    /*退出条件必然为退出的index上的值>=target */
    while (left < right) { // 注意 跳出时left==right
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            /* 如果right=(l+r)/2,
             * 则之后while比较的时候r>=l*/
            right = mid;
        } else if (nums[mid] < target) {
            /*如果mid比target小，那我们要想的最左边的target肯定比mid大，所以跳过mid*/
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid; // 注意
            /* 同样如果right=(l+r)/2,
            * 则之后while比较的时候r>=l*/
            /*
             * 3. 为什么 left = mid + 1，right = mid ？和之前的算法不一样？
             答：这个很好解释，
             因为我们的「搜索区间」是 [left, right) 左闭右开，
             所以当 nums[mid] 被检测之后，
             下一步的搜索区间应该去掉 mid 分割成两个区间，
             即 [left, mid) 或 [mid + 1, right)。

             我的思考，退出的条件之一即找不到的时候需要返回比它大的那个index的值，
             那么这意味着，right若急于去跳过mid,若mid=left=right 则返回的是那个最终结束位置的index-1;

             */

        }
    }
    // target 比所有数都大
    if (left == r ) return -1;
    // 类似之前算法的处理方式
    return nums[left] == target ? left : -1;

    return left;
}

int right_bound(int nums[], int l,int r,int target) {

    int left = l, right = r;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            left = mid + 1; // 注意
        } else if (nums[mid] < target) {
            left = mid + 1;//-->
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    return left - 1; // 注意
    while (left < right) {
        // ...
    }
    if (left == 0) return -1;
    return nums[left-1] == target ? (left-1) : -1;
}

int main() {
    int arr[] = {1, 2, 2, 3, 5, 7};
//    int index = mybsearch1(arr, 0, 3, 2);
    int index = right_bound(arr, 0, 3, 2);
    std::cout << index << std::endl;

}