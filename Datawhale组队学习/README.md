# Datawhale组队学习之编程基础（数据结构）

**任务路线：** 数组->链表->栈->队列->递归->排序->二分查找->哈希表->字符串->二叉树->堆->图->回溯->分治->动态规划

**组队学习周期：** 在16天的时间内（2019-5-10至2019-5-25）完成7个任务（14个子任务）

**完整任务发布页：** [Programming](https://github.com/datawhalechina/Programming)

**打卡要求：序号（32号）+昵称+链接，其中链接内应该包括要求实现的代码以及Leetcode练习题的代码**

## Task1（2天）

**【数组】**

 - 实现一个支持动态扩容的数组
 - 实现一个大小固定的有序数组，支持动态增删改操作
 - 实现两个有序数组合并为一个有序数组
 - 学习哈希表思想（选做），并完成leetcode上的两数之和(1)及Happy Number(202)！(要求全部用哈希思想实现！)（注意：在第四天会进行继续学习）

**练习（Leetcode）：**

1. [Three Sum](https://leetcode-cn.com/problems/3sum/)（求三数之和）

2. [Majority Element](https://leetcode-cn.com/problems/majority-element/)（求众数）

3. [Missing Positive](https://leetcode-cn.com/problems/first-missing-positive/)（求缺失的第一个正数）[作为可选]

**【链表】**

 - 实现单链表、循环链表、双向链表，支持增删操作
 - 实现单链表反转
 - 实现两个有序的链表合并为一个有序链表
 - 实现求链表的中间结点

**练习（Leetcode）：**

1. [Linked List Cycle I](https://leetcode-cn.com/problems/linked-list-cycle/)（环形链表）

2. [Merge k Sorted Lists](https://leetcode-cn.com/problems/merge-k-sorted-lists/)（合并 k 个排序链表）

## Task2（3天）

**【栈】**

 - 用数组实现一个顺序栈

 - 用链表实现一个链式栈

 - 编程模拟实现一个浏览器的前进、后退功能

**练习（Leetcode）：**

1. [Valid Parentheses](https://leetcode-cn.com/problems/valid-parentheses/)（有效的括号）

2. [Longest Valid Parentheses](https://leetcode-cn.com/problems/longest-valid-parentheses/)（最长有效的括号）[作为可选]

3. [Evaluate Reverse Polish Notatio](https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/)（逆波兰表达式求值）

**【队列】**

 - 用数组实现一个顺序队列

 - 用链表实现一个链式队列

 - 实现一个循环队列

**练习（Leetcode）：**

1. [Design Circular Deque](https://leetcode-cn.com/problems/design-circular-deque/)（设计一个双端队列）

2. [Sliding Window Maximum](https://leetcode-cn.com/problems/sliding-window-maximum/)（滑动窗口最大值）

**【递归】**

 - 编程实现斐波那契数列求值 f(n)=f(n-1)+f(n-2)

 - 编程实现求阶乘 n!

 - 编程实现一组数据集合的全排列

**练习（Leetcode）：**

1. [Climbing Stairs](https://leetcode-cn.com/problems/climbing-stairs/)（爬楼梯）

## Task3（2天）

**【排序】**

 - 实现归并排序、快速排序、插入排序、冒泡排序、选择排序、堆排序（选做，完成leetcode上的返回滑动窗口中的最大值(239)，这是上一期第三天的任务进行保留（涉及队列可以对第二天进行整理复习））

 - 编程实现 O(n) 时间复杂度内找到一组数据的第 K 大元素

**练习（Leetcode）：**

1. [Sliding Window Maximum](https://leetcode-cn.com/problems/sliding-window-maximum/)（滑动窗口最大值）

**【二分查找】**

 - 实现一个有序数组的二分查找算法

 - 实现模糊二分查找算法（比如大于等于给定值的第一个元素）

**练习（Leetcode）：**

1. [Sqrt(x)](https://leetcode-cn.com/problems/sqrtx/)（x 的平方根）

## Task4（2天）

**【散列表（哈希表）】**

 - 实现一个基于链表法解决冲突问题的散列表

 - 实现一个 LRU 缓存淘汰算法

**练习（Leetcode）：**

1. [Two Sum](https://leetcode-cn.com/problems/two-sum/)（两数之和）

**【字符串】**

 - 实现一个字符集，只包含 a～z 这 26 个英文字母的 Trie 树

 - 实现朴素的字符串匹配算法

**练习（Leetcode）：**

1. [Reverse String](https://leetcode-cn.com/problems/reverse-string/)（反转字符串）

2. [Reverse Words in a String](https://leetcode-cn.com/problems/reverse-words-in-a-string/)（翻转字符串里的单词）

3. [String to Integer (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/)（字符串转换整数 (atoi)）[作为可选]

## Task5（2天）

**【二叉树】**

 - 实现一个二叉查找树，并且支持插入、删除、查找操作

 - 实现查找二叉查找树中某个节点的后继、前驱节点

 - 实现二叉树前、中、后序以及按层遍历

**练习（Leetcode）：**

1. [Invert Binary Tree](https://leetcode-cn.com/problems/invert-binary-tree/)（翻转二叉树）

2. [Maximum Depth of Binary Tree](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)（二叉树的最大深度）

3. [Validate Binary Search Tree](https://leetcode-cn.com/problems/validate-binary-search-tree/)（验证二叉查找树）[作为可选]

**【堆】**

 - 实现一个小顶堆、大顶堆、优先级队列

 - 实现堆排序

 - 利用优先级队列合并 K 个有序数组

 - 求一组动态数据集合的最大 Top K

 - 第三天堆排序（选做）

**练习（Leetcode）：**

1. [Path Sum](https://leetcode-cn.com/problems/path-sum/)（路径总和）

## Task6（2天）

**【图】**

 - 实现有向图、无向图、有权图、无权图的邻接矩阵和邻接表表示方法

 - 实现图的深度优先搜索、广度优先搜索

 - 实现 Dijkstra 算法、A* 算法

 - 实现拓扑排序的 Kahn 算法、DFS 算法

**练习（Leetcode）：**

1. [Number of Islands](https://leetcode-cn.com/problems/number-of-islands/description/)（岛屿的个数）

2. [Valid Sudoku](https://leetcode-cn.com/problems/valid-sudoku/)（有效的数独）
