# 题目描述
## Fibonacci数列
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：  
F(0) = 0,   F(1) = 1  
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.  
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。  
## 青蛙跳台阶
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。  
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。  
示例 1：  
输入：n = 2  
输出：2  
示例 2：  
输入：n = 7  
输出：21  
# 解题思路
## 斐波拉契数列的解法
### 解法一 递归
会重复计算多次而超时
### 解法二 记忆法递归
开辟一个o(n)的空间存结果，避免重复计算
### 解法三 动态规划
### 解法四 矩阵快速幂
## 青蛙跳台阶的解法
假设f(n)为n阶台阶的跳法总数，倒推前一步就有 f(n)=f(n-2)+f(n-1) 与斐波拉契数列公式一样，初始值f(0)=1,f(1)=1
# 代码1 递归
```
class Solution {
public:
    int numWays(int n) {
    int f0=1,f1=1,fn=-1;
    int i=0;
    if(n==0) return f0;
    else if(n==1) return f1;
    else{
    return (numWays(n-2)+numWays(n-1));
    }
    }
};
```
# 代码2 记忆递归
```
class Solution {
public:
    vector<int>a=vector<int>(101,0);
    int numWays(int n) {
    a[0]=1;
    a[1]=1;
    if(a[n]!=0) return a[n];
    else
    {
        a[n]=(numWays(n-1)+numWays(n-2))%1000000007;
        return a[n];    
    }    
    }
};
```
# 代码3 动态规划
```
class Solution {
public:
    int numWays(int n) {
    int f0=1,f1=1,fn=-1;
    int i=0;
    if(n==0) return f0;
    else if(n==1) return f1;
    else{

        for(i=2;i<=n;i++)
        {
            fn=(f0+f1)%(1000000007);
            f0=f1;
            f1=fn;

        }
    return fn;
    }
    }
};
```
# 代码4 未写完
# 参考
1.成员变量不能直接调用vector的构造函数声明并初始化 声明只能vector<int>a;
```
成员变量声明并初始化 vector<int>a=vector<int>(100,0);vector<vector<int>> a=vector<vector<int>>(3,vector<int>(4,100));
初始化 a=vector<int> (100,0);a=vector<vector<int>>(3,vector<int>(4,100));
函数内声明并初始化 vector<int>a(100,0);//将a的100个元素初始化为0 
```
2.- [快速幂与矩阵快速幂](https://blog.csdn.net/FlushHip/article/details/80068888)
