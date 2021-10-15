# Data structure problem set Chinese version in PTA.

## 7-1 最大子列和问题 (20 分)
给定K个整数组成的序列 { N<sub>1</sub>, N<sub>2</sub>, ..., N<sub>K</sub> }，“连续子列”被定义为 { N<sub>i</sub>, N<sub>i+1</sub>, ..., N<sub>j</sub> }，其中 1≤i≤j≤K 。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列 { -2, 11, -4, 13, -5, -2 }，其连续子列 { 11, -4, 13 } 有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和。本题旨在测试各种不同的算法在各种数据情况下的表现。各组测试数据特点如下：

- 数据1：与样例等价，测试基本正确性；
- 数据2：10<sup>2</sup> 个随机整数；
- 数据3：10<sup>3</sup> 个随机整数；
- 数据4：10<sup>4</sup> 个随机整数；
- 数据5：10<sup>5</sup> 个随机整数；

***输入格式:***  
输入第1行给出正整数 K (≤100000)；第2行给出K个整数，其间以空格分隔。

***输出格式:***  
在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

***输入样例:***

    6  
    -2 11 -4 13 -5 -2

***输出样例:***

    20

## 7-2 一元多项式的乘法与加法运算 (20 分)
设计函数分别求两个一元多项式的乘积与和。

***输入格式:***  
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。

***输出格式:***  
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

***输入样例:***

    4 3 4 -5 2  6 1  -2 0
    3 5 20  -7 4  3 1

***输出样例:***

    15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
    5 20 -4 4 -5 2 9 1 -2 0

## 7-3 树的同构 (25 分)
给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。例如图1给出的两棵树就是同构的，因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。而图2就不是同构的。

<div align="center">

![7-3 图1](/img/7-3-fig-1.jpg "7-3 图1")      
图1 
  
![7-3 图2](/img/7-3-fig-2.jpg "7-3 图2")      
图2 
</div> 


现给定两棵树，请你判断它们是否是同构的。  

***输入格式:***  
输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N−1编号）；随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。

***输出格式:***  
如果两棵树是同构的，输出“Yes”，否则输出“No”。

***输入样例1（对应图1）：***

    8
    A 1 2
    B 3 4
    C 5 -
    D - -
    E 6 -
    G 7 -
    F - -
    H - -
    8
    G - 4
    B 7 6
    F - -
    A 5 1
    H - -
    C 0 -
    D - -
    E 2 -

***输出样例1:***
    
    Yes

***输入样例2（对应图2）：***

    8
    B 5 7
    F - -
    A 0 3
    C 6 -
    H - -
    D - -
    G 4 -
    E 1 -
    8
    D 6 -
    B 5 -
    E - -
    H - -
    C 0 2
    G - 3
    F - -
    A 1 4

***输出样例2:***

    No

## 7-4 是否同一棵二叉搜索树 (25 分)
给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

***输入格式:***  
输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。随后L行，每行给出N个插入的元素，属于L个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

***输出格式:***  
对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

***输入样例:***

    4 2
    3 1 4 2
    3 4 1 2
    3 2 4 1
    2 1
    2 1
    1 2
    0

***输出样例:***

    Yes
    No
    No

## 7-5 堆中的路径 (25 分)
将一系列给定数字插入一个初始为空的小顶堆`H[]`。随后对任意给定的下标`i`，打印从`H[i]`到根结点的路径。

***输入格式:***  
每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、以及需要打印的路径条数。下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。最后一行给出M个下标。

***输出格式:***  
对输入中给出的每个下标`i`，在一行中输出从`H[i]`到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。

***输入样例:***

    5 3
    46 23 26 24 10
    5 4 3

***输出样例:***

    24 23 10
    46 23 10
    26 10

## 7-6 列出连通集 (25 分)
给定一个有*N*个顶点和*E*条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到*N*−1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

***输入格式:***  
输入第1行给出2个整数*N*(0<*N*≤10)和*E*，分别是图的顶点数和边数。随后*E*行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。

***输出格式:***  
按照"{ v1 v2... vk}"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

***输入样例:***

    8 6
    0 7
    0 1
    2 0
    4 1
    2 4
    3 5

***输出样例:***

    { 0 1 4 2 7 }
    { 3 5 }
    { 6 }
    { 0 1 2 7 4 }
    { 3 5 }
    { 6 }

## 7-9 旅游规划 (25 分)
有了一张自驾旅游路线图，你会知道城市间的高速公路长度、以及该公路要收取的过路费。现在需要你写一个程序，帮助前来咨询的游客找一条出发地和目的地之间的最短路径。如果有若干条路径都是最短的，那么需要输出最便宜的一条路径。

***输入格式:***  
输入数据的第1行给出4个正整数N、M、S、D，其中N（2≤N≤500）是城市的个数，顺便假设城市的编号为0~(N−1)；M是高速公路的条数；S是出发地的城市编号；D是目的地的城市编号。
随后的M行中，每行给出一条高速公路的信息，
分别是：城市1、城市2、高速公路长度、收费额，中间用空格分开，数字均为整数且不超过500。输入保证解的存在。

***输出格式:***  
在一行里输出路径的长度和收费总额，数字间以空格分隔，输出结尾不能有多余空格。

***输入样例:***  

    4 5 0 3  
    0 1 1 20  
    1 3 2 30  
    0 3 4 10  
    0 2 2 20   
    2 3 1 20  

***输出样例:***  

    3 40

## 7-10 公路村村通 (30 分)
现有村落间道路的统计数据表中，列出了有可能建设成标准公路的若干条道路的成本，
求使每个村落都有公路连通所需要的最低成本。

***输入格式:***  
输入数据包括城镇数目正整数N(≤1000)和候选道路数目M(≤3N)；
随后的M行对应M条道路，每行给出3个正整数，分别是该条道路直接连通的两个城镇的编号以及该道路改建的预算成本。
为简单起见，城镇从1到N编号。

***输出格式:***  
输出村村通需要的最低成本。如果输入数据不足以保证畅通，则输出−1，表示需要建设更多公路。

***输入样例:*** 

    6 15  
    1 2 5  
    1 3 3  
    1 4 7  
    1 5 4  
    1 6 2  
    2 3 4  
    2 4 6  
    2 5 2  
    2 6 6  
    3 4 6  
    3 5 1  
    3 6 1  
    4 5 10  
    4 6 8  
    5 6 3  

***输出样例:***  

    12


## 7-11 关键活动 (30 分)
假定一个工程项目由一组子任务构成，子任务之间有的可以并行执行，有的必须在完成了其它一些子任务后才能执行。
“任务调度”包括一组子任务、以及每个子任务可以执行所依赖的子任务集。比如完成一个专业的所有课程学习和毕业设计可以看成一个本科生要完成的一项工程，各门课程可以看成是子任务。有些课程可以同时开设，比如英语和C程序设计，它们没有必须先修哪门的约束；有些课程则不可以同时开设，因为它们有先后的依赖关系，比如C程序设计和数据结构两门课，必须先学习前者。但是需要注意的是，对一组子任务，并不是任意的任务调度都是一个可行的方案。比如方案中存在“子任务A依赖于子任务B，子任务B依赖于子任务C，子任务C又依赖于子任务A”，那么这三个任务哪个都不能先执行，这就是一个不可行的方案。任务调度问题中，如果还给出了完成每个子任务需要的时间，则我们可以算出完成整个工程需要的最短时间。在这些子任务中，有些任务即使推迟几天完成，也不会影响全局的工期；但是有些任务必须准时完成，否则整个项目的工期就要因此延误，这种任务就叫“关键活动”。  
请编写程序判定一个给定的工程项目的任务调度是否可行；如果该调度方案可行，则计算完成整个工程项目需要的最短时间，并输出所有的关键活动。

***输入格式:***  
输入第1行给出两个正整数N(≤100)和M，其中N是任务交接点（即衔接相互依赖的两个子任务的节点，
例如：若任务2要在任务1完成后才开始，则两任务之间必有一个交接点）的数量。交接点按1~N编号，M是子任务的数量，依次编号为1~M。随后M行，每行给出了3个正整数，分别是该任务开始和完成涉及的交接点编号以及该任务所需的时间，整数间用空格分隔。

***输出格式:***  
如果任务调度不可行，则输出0；否则第1行输出完成整个工程项目需要的时间，
第2行开始输出所有关键活动，每个关键活动占一行，按格式“V->W”输出，其中V和W为该任务开始和完成涉及的交接点编号。关键活动输出的顺序规则是：任务开始的交接点编号小者优先，起点编号相同时，与输入时任务的顺序相反。

***输入样例:***  

    7 8  
    1 2 4  
    1 3 3  
    2 4 5  
    3 4 3  
    4 5 1  
    4 6 6  
    5 7 5  
    6 7 2  

***输出样例:***  

    17  
    1->2  
    2->4  
    4->6  
    6->7  

## 7-12 排序 (25 分)
给定N个（长整型范围内的）整数，要求输出从小到大排序后的结果。  
本题旨在测试各种不同的排序算法在各种数据情况下的表现。各组测试数据特点如下：
- 数据1：只有1个元素；
- 数据2：11个不相同的整数，测试基本正确性；
- 数据3：10<sup>3</sup>个随机整数；
- 数据4：10<sup>4</sup>个随机整数；
- 数据5：10<sup>5</sup>个随机整数；
- 数据6：10<sup>5</sup>个顺序整数；
- 数据7：10<sup>5</sup>个逆序整数；
- 数据8：10<sup>5</sup>个基本有序的整数；
- 数据9：10<sup>5</sup>个随机正整数，每个数字不超过1000。

***输入格式:***  
输入第一行给出正整数N（≤10<sup>5</sup>），随后一行给出N个（长整型范围内的）整数，其间以空格分隔。

***输出格式:***  
在一行中输出从小到大排序后的结果，数字间以1个空格分隔，行末不得有多余空格。  

***输入样例:***

    11
    4 981 10 -17 0 -20 29 50 8 43 -5

***输出样例:***

    -20 -17 -5 0 4 8 10 29 43 50 981

## 7-13 统计工龄 (20 分)
给定公司N名员工的工龄，要求按工龄增序输出每个工龄段有多少员工。

***输入格式:***  
输入首先给出正整数N（≤10<sup>5</sup>），即员工总人数；随后给出N个整数，即每个员工的工龄，范围在[0, 50]。

***输出格式:***  
按工龄的递增顺序输出每个工龄的员工个数，格式为：“工龄:人数”。每项占一行。如果人数为0则不输出该项。

***输入样例:***
  
    8
    10 2 0 5 7 2 5 2

***输出样例:***

    0:1
    2:3
    5:2
    7:1
    10:1

## 7-14 电话聊天狂人 (25 分)
给定大量手机用户通话记录，找出其中通话次数最多的聊天狂人。

***输入格式:***  
输入首先给出正整数N（≤10<sup>5</sup>），为通话记录条数。随后N行，每行给出一条通话记录。简单起见，这里只列出拨出方和接收方的11位数字构成的手机号码，其中以空格分隔。

***输出格式:***  
在一行中给出聊天狂人的手机号码及其通话次数，其间以空格分隔。如果这样的人不唯一，则输出狂人中最小的号码及其通话次数，并且附加给出并列狂人的人数。

***输入样例:***  

    4
    13005711862 13588625832
    13505711862 13088625832
    13588625832 18087925832
    15005713862 13588625832

***输出样例:***

    13588625832 3 

## 7-15 QQ帐户的申请与登陆 (25 分)
实现QQ新帐户申请和老帐户登陆的简化版功能。最大挑战是：据说现在的QQ号码已经有10位数了。

***输入格式:***  
输入首先给出一个正整数 *`N`* (≤10<sup>5</sup>)，随后给出 *`N`* 行指令。每行指令的格式为：“命令符（空格）QQ号码（空格）密码”。其中命令符为“N”（代表New）时表示要新申请一个QQ号，后面是新帐户的号码和密码；命令符为“L”（代表Login）时表示是老帐户登陆，后面是登陆信息。QQ号码为一个不超过10位、但大于1000（据说QQ老总的号码是1001）的整数。密码为不小于6位、不超过16位、且不包含空格的字符串。

***输出格式:***  
针对每条指令，给出相应的信息：
1.  若新申请帐户成功，则输出“New: OK”；
2.  若新申请的号码已经存在，则输出“ERROR: Exist”；
3.  若老帐户登陆成功，则输出“Login: OK”；
4.  若老帐户QQ号码不存在，则输出“ERROR: Not Exist”；
5.  若老帐户密码错误，则输出“ERROR: Wrong PW”。

***输入样例:***

    5
    L 1234567890 myQQ@qq.com
    N 1234567890 myQQ@qq.com
    N 1234567890 myQQ@qq.com
    L 1234567890 myQQ@qq
    L 1234567890 myQQ@qq.com

***输出样例:***

    ERROR: Not Exist
    New: OK
    ERROR: Exist
    ERROR: Wrong PW
    Login: OK

-------------------------------
