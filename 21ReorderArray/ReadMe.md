# 题目描述：调整数组顺序使奇数位于偶数前面
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
# 方法一：辅助数组
```
遍历原数组两次，第一次找出所有奇数，存在新数组，第二次找出所有偶数，接着存在新数组,注意返回新数组res 
时间复杂度O(2N),空间复杂度O(N)
```
# 方法二：标记第一个偶数的位置
```
1.找到第一个偶数，记位置t  
2.当找到奇数时，与num[t]互换，并使t=t+1  
3.i=nums.size()-1时停止
时间复杂度O(N),空间复杂度O(1)
```
# 方法三：双指针
```
1.i从头开始，j从尾开始  
2.当i指向偶数，j指向奇数时，奇数跟偶数互换  
3.i==j时停止  
时间复杂度O(N/2),空间复杂度O(1)  
```
# 代码1 辅助数组
```
 vector<int> exchange(vector<int>& nums) {
        vector<int>res;
        int i=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
            {
                res.push_back(nums[i]);
            }
        }
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                res.push_back(nums[i]);
            }
        }
        
      
        return res;
    }
```
# 代码2 标记第一个偶数的位置
```
vector<int> exchange(vector<int>& nums) {
        int t=0,i=0,f=0,temp=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0&&f==0)
            {
                t=i;
                f=f+1;
            }
            else if(nums[i]%2!=0)
            {
                temp=nums[i];
                nums[i]=nums[t];
                nums[t]=temp;
                t=t+1;
            }
        }
        return nums;
    }
```
# 代码3 双指针
```
vector<int> exchange(vector<int>& nums) {
        int i=0,j=nums.size()-1,temp=0;
        while(i<j)
        {
            if(nums[i]%2==0&&nums[j]%2!=0)
            {
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
                i++;
                j--;
            }
            else if(nums[i]%2!=0)
            {
                i++;
            }
            else if(nums[j]%2==0)
            {
                j--;
            }
        }
      
        return nums;
    }
```
