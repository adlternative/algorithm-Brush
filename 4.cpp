
// #include <bits/stdc++.h>
// #include <errno.h>
// #include <fcntl.h>
// #include <sys/types.h>
// #include <unistd.h>

// using namespace std;
// class Solution {
// public:
//   double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
//     // nums1.size(); 5
//     // nums2.size(); 5
//     // 1 3 5 7 9 | 2 4 6 8 10 重叠
//     //  寻找中位数
//     // 1 2 3 4 5 6 7 8 9 10  5,6 ->5.5
//     //策略 n%2=0 那么就是n/2 -1 n/2之间 n%2=1 那么就是 s[n/2]
//     //如果合并直接找 O(N)
//     // n/2 估算在哪里出现...如果小于 size1 那么就在左边找 否则在右边
//     // 然后如果n/2大于size1/2...继续缩放
//     int midValue = 0;
//     auto size1 = nums1.size();
//     auto size2 = nums2.size();
//     auto allLen = size1 + size2;
//     bool onlyOne = allLen % 2;
//     int target = onlyOne ? allLen / 2 : allLen / 2 - 1;

//     return midValue;
//   }
// };
// int main(int argc, char const *argv[]) {
//   Solution s;
//   vector<int> v1{1, 3, 5, 7, 9};
//   vector<int> v2{2, 4, 6, 8, 10};
//   int value = s.findMedianSortedArrays(v1, v2);
//   std::cout << value << std::endl;
//   return 0;
// }
