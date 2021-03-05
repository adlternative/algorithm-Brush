//
// Created by adl on 2020/10/27.
//

#include<bits/stdc++.h>

using namespace std;

//class Solution {
//public:
//    int max = 0;
//    int cur_index = 0;
//    int cnt = 0;
//    void update(){
//        if (cnt >max)
//            max =cnt ;
//    }
//    int longestMountain(vector<int> &A) {
//
//        if(!A.size()){
//            return max;
//        }
//        while (true) {
//            cnt = 0;
//            /*递增序列长度*/
//            while (cur_index + 1 != A.size() && A[cur_index] < A[cur_index + 1]) {
//                cur_index++;
//                cnt++;
//            }
//            if (cur_index + 1 == A.size()) {
//                /*end and update*/
//                update();
//                break;
//            }
//
//            /* 不相等则加上结尾的cur_index*/
//            if(A[cur_index] != A[cur_index + 1])
//                cnt++;
//            else {
//                /* 相等则继续去循环*/
//                update();
//                cur_index++;
//                continue;
//            }
//
//            while (cur_index + 1 != A.size() && A[cur_index] > A[cur_index + 1]) {
//                cur_index++;
//                cnt++;
//            }
//            if (cnt >= max) {
//                max = cnt;
//            }
//            if (cur_index + 1 == A.size()) {
//                break;
//            }
//
//        }
//        return max;
//
//    }
//};

//class Solution {
//
//public:
//    int max = 0;
//    int cur = 1;
//    int last;
//    int cnt = 0;
//    int flag = 0;/*0没有上坡 1 说明有上坡了 */
//    int longestMountain(vector<int> &A) {
//        if (A.size() < 3) {
//            return 0;
//        }
//        last = A[0];
//        while (true) {
//
//            if (cur == A.size()) {
//
//                if (cnt > max) {
//                    max = cnt;
//                }
//                return max;
//            }
//
//            if (A[cur] > last) {        /*新元素>旧元素*/
//                /*0 1 2*/
//                /*2 1 2*/
//                if (flag == 0) {
//                    /*1 2 */
//                    /*1 1 2*/
//                    flag = 1;
//                    cnt += 2;
//                } else {
//                    if(A[cur-2]>last){
//                        if (cnt > max) {
//                            max = cnt;
//                            cnt = 0;
//                            flag = 0;
//                        }
//                        flag = 1;
//                        cnt += 2;
//                    }else{
//                        cnt += 1;
//                    }
//                }
//
//            } else if (A[cur] == last) {    /*新元素＝旧元素*/
//                if (cnt > max) {
//                    max = cnt;
//                    cnt = 0;
//                    flag = 0;
//                }
//            } else {    /*新元素<旧元素*/
//                if (flag) {   /*有上坡*/
//                    cnt++;
//                }
//            }
//            last = A[cur];
//            cur++;
//        }
//    }
//};


class Solution {
public:

    int longestMountain(vector<int> &A) {
        int maxlen = 0;
        int i = 1;

        if (A.size() < 3) {
            return 0;
        }
        while (i < A.size()) {
            int inc = 0, dec = 0;
            while (i < A.size() && A[i - 1] < A[i]) {
                i++;
                inc++;
            }
            while (i < A.size() && A[i - 1] > A[i]) {
                i++;
                dec++;
            }
            if (inc && dec) {
                maxlen = max(maxlen, inc + dec + 1);
            }
            while (i < A.size() && A[i - 1] == A[i]) i++;
        }
        return maxlen;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
//    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    vector<int> v{2,2,2};
    vector<int> v{2, 1, 4, 7, 3, 2, 5};
    auto i = s.longestMountain(v);
    std::cout << i << std::endl;

    return 0;
}