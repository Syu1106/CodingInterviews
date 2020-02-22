# [数组中重复的数字](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)
# 题目描述：
在一个长度为n的数组里的所有数字都在0~n-1范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。 请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2，3，1，0，2，5，3}，那么对应的输出是重复的数字2或者3
# 方法一：哈希表
题目限制了数字的范围，可以另开一个长度为n的数组存下标出现的次数，nums[i]>1,则i有重复  
时间复杂度O(n)，空间复杂度O(n)
# 方法二：数组内交换
```
1.如果nums[i]==i,不需要交换
2.如果nums[nums[i]]==nums[i],则nums[i]是重复数字
3.否则令nums[nums[i]]与nums[i]交换
时间复杂度O(n)，空间复杂度O(1)
```
# 方法三：排序后查找重复数字

# 代码1：哈希表
```
public:
    int findRepeatNumber(vector<int>& nums) {

        int a[100000]={0};
        int i=0;
        for(i=0;i<nums.size();i++)
        {
            if(a[nums[i]]<1)
            {
                a[nums[i]]++;
            }
            else 
            {
                return nums[i];
            }
        } 
        return -1;
    }
```
# 代码2：数组内交换
```
public:
    int findRepeatNumber(vector<int>& nums) {
        int temp=-1,i=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]!=i)
            {
                if(nums[nums[i]]!=nums[i])
                {
                 //   temp =nums[i];
                 //   nums[i]=nums[nums[i]];   如果先改变nums[i]的值，nums[nums[i]]的索引也会改变
                 //   nums[nums[i]]=temp;
                    temp =nums[nums[i]];
                    nums[nums[i]]=nums[i];
                    nums[i]=temp;
                }
                else
                {
                    return nums[i];
                }
            }
        } 
        return -1;
    }
```
# 代码3：排序后查找重复数字
```

```
# 参考
1.数组初始化  
```
int a[1000]={0};
int a[1000]={1};//数组其实是被初始化成1,0,0,0,0
int a[size];
memset(a,0,sizeof(a));
memset(a,0,sizeof(int)*size);

```
