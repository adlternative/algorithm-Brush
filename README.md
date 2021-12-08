#### algorithm-Brush

#### 逆波兰，栈
`leetcode 224`
1. 逆波兰法。
   1. 构造逆波兰表达式。中缀转后缀, `(` 入栈，`)` 弹栈到 `(`, `+` 弹栈所有高优先级 `-` 后入栈。
   2. 后缀计算值。 数字入栈，符号弹栈俩元素或单元素，计算值入栈，返回最后栈顶。
2. 栈记录每个值的正负号。由于所有计算都是加减，所以很简单。记录每个数字对应的符号。（注意括号）。

`leetcode 227`
1. 同 224 。没 `(`,`)`,但有 `*`,`/`。我们需要构造优先级，`*`,`/` 优先级相同，`+`,`-` 优先级相同，弹栈弹更高优先级（包括同优先级）。一发过，牛逼。


#### 字典树
`leetcode 677`
1. 构造字典树，每个节点存放值，插入重复元素需要为之前插入的树上所有节点更新值。

### 树的遍历
`leetcode 297`
1. 序列化：层序遍历。反序列化：层序遍历重建。

`leetcode 440`
1. 字典序抽象出十叉树，计算每个前缀数字的节点数，通过数学优化减少遍历。

`leetcode 99`
1. 中序遍歷構造遞增序列，然後尋找一個或者兩個遞減的座標，進行交換。

### 双指针
`leetcode 295`
1. 双指针，左右指针调整中位数，区分奇数偶数。（multimap 重复元素插入和搜索特征）
2. 一个大堆，一个小堆。

`leetcode 135`
1. 算是双指针...有点滑动窗口的感觉。线性扫描。
2. 好像还有一种双向扫描的方法。

#### 二分

`leetcode 1095`
1. “三个二分”，找最大值，搜左边，左边搜不到搜右边。二分注意从大到小还是从小到小，以及边界，以及退出时的判断。

`leetcode 154`
1. 旋转数组找最小数，利用最小值肯定在左右中间找，逐渐缩小二分查找区间。最右边数的值作为区分最小数在哪一边的标准。

`leetcode 154`
1. 俩有序数组找中值，巧借坐标为 `k/2 -1` 的数据进行范围缩放。

`leetcode 72`
1. 二维数组转一维二分。

`leetcode 81`
1. 旋转数组找目标，通过比较最左数，目标数，中间值缩小范围，这里遇到重复则退化为遍历。。。

`leetcode 162`
1. 找极大值。

`leetcode 275`
1. 找 `max(len - x >= f(x) ? f(x) : len -x > f(x-1) ? len - x : none)`

`leetcode 240`
1. 横坐标和纵坐标分别二分排除非目标区域。 (利用 `upper_bound`)

### 动态规划

`leetcode 17.24`
1. 从一维怎么求最大区间去思考。二维需要先固定上边，再固定左边，然后移动下边和右边，动态规划更新最值。

`leetcode 887` 扔鸡蛋
1. 巧妙解法 抽象出 `鸡蛋数，机会数量` 两个因子计算可以求解的楼层数，而不是死纠 `鸡蛋数, 楼层数` 算最大机会次数。
2. [我不会，蛋我大受震撼](https://leetcode-cn.com/problems/super-egg-drop/solution/ji-dan-diao-luo-by-leetcode-solution-2/)

`leetcode 10`
1. 正则表达式，如果当前匹配到 `*` 向左看前一个字符串是否匹配，若匹配，状态如何转移，若不匹配，状态如何转移。（将 `x*`看成一个整体）
`leetcode 44`
1. 和上题类似。匹配到 `*` 等价于 使用 `*` 和不使用 `*` 的两种情况。

`leetcode 516`
区域动态规划，删除某几个字符求最大回文子串长度。根据区间首尾字符是否相同，分为两种情况决定区间长度最大值的计算方式。
`leetcode 1312`
区域动态规划，添加最少的字符数量形成回文子串。根据区间首尾字符是否相同，分为两种情况决定需要添加的字符数量。

`leetcode 115`
一般来说，这种字符串匹配的 dp 问题需要通过 增删一个字符 的逻辑构建 状态转移方程，想到及万岁。

`leetcode 354`
两维 最大升序序列长度，暴力 dp O(N^2), 通过构建递增序列，并二分寻找修改点的方式可以降低到 O(logN)。
需要对其中一维升序排序，另一维降序排序，来迎合两维皆需要升序的需要。

`leetcode 188`

至于状态是什么：1. 天数 i 2. 交易数 j 3. 当前是否有股票（有些难想）用数组 0 | 1 表示。
当然 f(x) 是最大利润。注意要考虑交易数为 0 的情况 所以数组大小应该是 j + 1。

买卖股票, 初始边界状态的建立有些繁琐, (因为那些非正常情况,我们不是清 0 而是置 INT_MIN), 然后注意新的一轮买股票算一笔交易,而不是卖的时候,否则转移方程会出错。




### 滑动窗口

`leetcode 209`
1. 寻找和大于某值的最短区间长度。右扩左缩。

`offer59-I`
1. 選找每個固定長度區間的最大值，反正比較難想的是它的優先隊列彈出範圍外的最大的元素的策略（可以說是延時淘汰）。

### 深度优先搜索

`679.24`
1. 求二十四点，dfs 回溯。


### 优先队列

c++ 优先队列的比较器特征：默认 less<> 大堆顶，自己写的 Cmp 如果是写成 `left < right` 仍然是大堆顶顺序。
中间的存储容器用 vector 或者  deque 均可以，但是 vector 更稳定？

`leetcode 60`
1. 全排列 算 k/(n-m)! and k%(n-m)!, k = k%(n-m)!... 优先队列不过是为了快速取当前应该拿出的值。

`leetcode 692`
1. 根据元素出现的次数和元素的字典序排列决定优先队列的顺序，然后找 `TopK`。
2. nth_element + sort 快速选择。


### 单调队列

`leetcode 862`
1. 构造前缀和，求最短区间和 >= k （可能存在负数）。通过构造单调队列减去那些只会更长的区间，再寻找满足条件的最短区间长。
2. 暴力 O(N^2)。会超时。

### 归并排序

`leetcode 315`
1. 看上去很简单，找右边小于它的数，事实上难的一批。不能用 dp...最后想到的方案是插入排序但会超时，n2log(n)。使用归并排序，复杂度 nlogn, 我写的一直有些bug,,,
元素的坐标和元素绑定在一起可以省去很多麻烦。`inplace_merge(first,mid,end)` 应该是 stl 库自带的归并接口，代表含义是 [first,mid) 已经排序
和 [mid,end)已经排序，将它们合并。


### 設計題

`leetcode 895`
頻率棧，通過倆 hashmap 來分別存放 `{count, vals[]}` 和 `{val, count}`。難以想像的是它在添加元素的時候不是 update `{count, val} -> {count + 1, val}` 而是直接添加 `{count + 1, val}`。
