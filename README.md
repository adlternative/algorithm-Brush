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
1. 利用最小值肯定在左右中间找，逐渐缩小二分查找区间。最右边数的值作为区分最小数在哪一边的标准。

### 动态规划

`leetcode 17.24`
1. 从一维怎么求最大区间去思考。二维需要先固定上边，再固定左边，然后移动下边和右边，动态规划更新最值。

`leetcode 887` 扔鸡蛋
1. 巧妙解法 抽象出 `鸡蛋数，机会数量` 两个因子计算可以求解的楼层数，而不是死纠 `鸡蛋数, 楼层数` 算最大机会次数。
2. [我不会，蛋我大受震撼](https://leetcode-cn.com/problems/super-egg-drop/solution/ji-dan-diao-luo-by-leetcode-solution-2/)