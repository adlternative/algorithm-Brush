//
// Created by adl on 2020/12/5.
//

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else if (target == nums[mid]) {
                return mid;
            }
        }
        return -1;
    }
};

int binarySearch(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1; // 注意
    //若从这里退出就意味着left>right,也就是说不会出现left==right且退出的情况
    //让我们思考一下找不到的情况，比如我们想找到1 2 4中的3,那么mid=1->接着nums[1]<3,left=2==(right)
    //mid=2->left(3)>mid(2),退出!
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1; // 注意,这里将left越过mid
        else if (nums[mid] > target)
            right = mid - 1; // 注意,这里将right越到mid之前
    }
    return -1;
}

int binarySearch2(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1; // 注意
    //若从这里退出就意味着left==right,因为left,right为(4,5)的时候mid==4,
    // (left=mid+1)==5,left==mid或者right=mid-1=4,出while循环的条件必然是left==right
    //或者left,right=4,6还是一样,mid=5,left=6或right=4

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1; // 注意,这里将left越过mid
        else if (nums[mid] > target)
            right = mid - 1; // 注意,这里将right越到mid之前
    }
    return nums[left] == target ? left : -1;
}

int left_bound1(vector<int> &nums, int target) {

    /*
     *
     * 比如对于有序数组 nums = [2,3,5,7], target = 1，算法会返回 0，
     * 含义是：nums 中小于 1 的元素有 0 个。
    　＊再比如说 nums = [2,3,5,7], target = 8，算法会返回 4，
     ＊含义是：nums 中小于 8 的元素有 4 个。
     * */
    if (nums.size() == 0) return -1;
    int left = 0;
    int right = nums.size(); // 注意
    //结束条件是left==right,结束的时候搜索空间是[left,left)为空，

    while (left < right) { // 注意
        int mid = (left + right) / 2;

        /*
         * 为什么 left = mid + 1，right = mid ？和之前的算法不一样？
            答：这个很好解释，因为我们的「搜索区间」是 [left, right) 左闭右开，
            所以当 nums[mid] 被检测之后，下一步的搜索区间应该去掉 mid 分割成两个区间，
            即 [left, mid) 或 [mid + 1, right)。

            我们想想如果nums[mid]必然不是target,所以搜索[left, mid)和[mid + 1, right)
         * */

        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid; // 注意
        }
    }
    return left;
//    if (left == nums.size()) return -1;
    // 类似之前算法的处理方式
//    return nums[left] == target ? left : -1;;
}

int left_bound2(vector<int> &nums, int target) {
    /*说实话这种求左边界这样的写法很别扭*/
    if (nums.size() == 0) return -1;
    int left = 0;
    int right = nums.size() - 1; // 注意
    //结束条件是left==right,结束的时候搜索空间是[left,left)为空，

    while (left <= right) { // 注意
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            right = mid - 1;//mid持续减小，这会一直持续到num[mid]<target,接着会left>right
        } else if (nums[mid] < target) {
            // 搜索区间变为 [mid+1, right]
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1; // 注意
        }
    }
    if (left >= nums.size() || nums[left] != target)
        return -1;
    return left;
}

int right_bound1(vector<int> &nums, int target) {
    if (nums.size() == 0) return -1;
    int left = 0, right = nums.size();
    /*出去的时候还是left==right*/
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            left = mid + 1; // 注意
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }

    return right - 1; // 注意
}

int right_bound2(vector<int> &nums, int target) {
    if (nums.size() == 0) return -1;
    int left = 0, right = nums.size() - 1;
    /*出去的时候还是left==right*/
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            left = mid + 1; // 注意
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    // 这里改为检查 right 越界的情况，见下图
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums{-1, 0, 3, 4, 5, 9, 12};
    int pos = s.search(nums, -1);
    std::cout << pos << std::endl;

//    int pos = s.search(nums, 2);
//    std::cout << pos << std::endl;

    return 0;
}