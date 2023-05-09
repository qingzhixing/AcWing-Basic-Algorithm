# AcWing-Basic-Algorithm
AcWing算法基础课项目,所有题目均以c++实现  
内容正在逐步更新，项目里面还有一些我的小建议，感兴趣的话可以star一下，也许能作为你的参考。
有些题目会提供多个解法，每个都可以看一看。  
review list里面放了我的复习题单或者复习的知识点,可以浏览一下。

> 空了好几个月，现在从头开始写-2023.4.20

## review list

- [ ] [788. 逆序对的数量](https://www.acwing.com/problem/content/790/)
复习ans在什么条件下加多少，为什么当右边放完再放左边时及时左边比已经放了的右边所有值小此时ans不增？

- [ ] [789. 数的范围](https://www.acwing.com/problem/content/description/791/)
复习FindLastLessOrEqualThan(),FindFirstMoreOrEqualThan()实现,哪里(left+right+1)哪里不用

- [ ] [AcWing 800. 数组元素的目标和](https://www.acwing.com/problem/content/802/)
进行该题双指针写法复习，看看如何利用数组单调性进行循环的优化  

- [ ] [AcWing 802. 区间和](https://www.acwing.com/problem/content/804/)
复习整数离散化  

- [ ] [3302. 表达式求值](https://www.acwing.com/problem/content/3305/)
- [ ] [830. 单调栈](https://www.acwing.com/problem/content/832/)  
- [ ] [154. 滑动窗口](https://www.acwing.com/problem/content/156/)
- [ ] [831. KMP字符串](https://www.acwing.com/problem/content/833/)
- [ ] [143. 最大异或对](https://www.acwing.com/problem/content/145/)
复习如何优化暴力内层循环，为何能使用Trie树进行优化  
- [ ] [AcWing 240. 食物链](https://www.acwing.com/problem/content/242/)
如何维护额外信息  
- [ ] [838. 堆排序](https://www.acwing.com/problem/content/840/)
复习MoveDown函数  
- [ ] [841. 字符串哈希](https://www.acwing.com/problem/content/843/)
CalculateRangeHash公式推导以及计算前缀哈希的方式  
- [ ] [845. 八数码](https://www.acwing.com/problem/content/847/)
如何进行搜索  
- [ ] [846. 树的重心](https://www.acwing.com/problem/content/848/)
存储树的方式，如何确定根节点  

> 答案： 无向图存储，根节点默认1  

- [ ] [858. Prim算法求最小生成树](https://www.acwing.com/problem/content/860/)
再写一次  
- [ ] [859. Kruskal算法求最小生成树](https://www.acwing.com/problem/content/861/)
复习如何判断是否有解  
- [ ] [861. 二分图的最大匹配](https://www.acwing.com/problem/content/863/)
复习visited作用，为什么每次左侧节点判断是否匹配前要清空

## debug list

- [ ] **786.第k个数_三路快排review_2023.4.30.cpp**  
进行三路快排分区间递归的debug

- [x] [792. 高精度减法](https://www.acwing.com/problem/content/794/)
代码debug,寻找最后一个样例不打表的做法  

> 答案：2022.6.25问题已找到，greater,less指针没用赋值初始值nullptr导致相等数字判断错误。  

- [ ] [827. 双链表](https://www.acwing.com/problem/content/829/)
debug  

- [x] [849. Dijkstra求最短路 I](https://www.acwing.com/problem/content/851/)
wtf??? DEBUG  

> 重写代码后通过测试
