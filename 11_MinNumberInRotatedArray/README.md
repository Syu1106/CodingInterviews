# 题目描述:  
面试题11：旋转数组的最小数字  
题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
# 本题考点：
  
   二分查找的用法
  
# 解题思路:

  1). index1、index2、indexmid分别表示数组的头、中间、末尾，不断比较i1跟im来移动i1跟i2缩小数组的范围，直到数组只剩下两个元素
  
  2). 进入循环的条件：头大于等于尾
  
  3). 如果i1与i2与im相等，则无法用二分查找，用此时的i1与i2做顺序查找
  
  4). 如果数组本来是增序，则不进入循环输出im=i1，数组只有1个元素则进入3  
  
  几个例子 12345 34512 3451222 313  412223  21222 22212 133  
  循环条件 r-l>1(三个数字)  
  1.当num[d]>num[r]:数组旋转了，且最小值在[d+1,r]  
  2.当num[d]<num[r]:数组没有旋转，或者旋转了超过一半的数，最小值在[l,d]  
  3.当num[d]==num[r]:不好判断，边界挪一次可以r=r-1进行下次判断  
  比较min(num[l],num[r])  
  ```
   int minArray(vector<int>& numbers) {
        int r=0,l=0,d=0;
        if(numbers.size()==0)
        return 0;
        r=numbers.size()-1;
        l=0;
        d=(r+l)/2;
        while(l<r-1)
        {
            if(numbers[r]==numbers[d])
            {
                r=r-1;
            }
            else if(numbers[r]<numbers[d])
            {
                l=d+1;
            }  
            else if(numbers[r]>numbers[d])
            {
                r=d;
            }
            d=(r+l)/2;                  
        }
        return min(numbers[l],numbers[r]);


    }
  ```
# 代码

[C++](MinNumberInRotatedArray.cpp)

# 参考：
- [vector基本用法](https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html):**作为形参时要用vector< type >&obj**

