# [二维数组的查找](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)
# 题目描述  
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
# 方法一：遍历数组  
时间复杂度O(m*n),空间复杂度O(1)
# 方法二：线性查找  
根据数组从左到右递增，从上到下递增的特性，从右上角开始查找,①target<matrix[i][j],i++；②target>matrix[i][j],j--；  
最差情况需要m+n-1次判断  
时间复杂度O(m+n),空间复杂度O(1)
# 代码一：
```
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int n=0,m=0;
    int i=0,j=0,t=0;
    if(matrix.size()>0 && matrix[0].size()>0)
    {
        n=matrix.size();
        m=matrix[0].size();
    }  
    else return 0;
    for(i=0;i<n;i++)
    {
        if(matrix[i][0]>target)
        break;
        for(j=0;j<m;j++)
        {
            if(target==matrix[i][j])
                return 1;
            else if(target<matrix[i][j])
                break;
        }        
    }
    return 0;

    }
```
# 代码二：
```
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int n=0;
    int i=0,j=0,t=0;
    if(matrix.size()>0 && matrix[0].size()>0)
    {
        n=matrix.size();
        j=matrix[0].size()-1;
    }  
    else return 0;
    while(i<n&&j>-1)
    {
        if(matrix[i][j]>target)
        {
            j--;
        }
        else if(matrix[i][j]<target)
        {
            i++;
        }
        else 
        {
            return 1;
        }
       
    }
    return 0;

    }
```
# 参考：
```
1.二维数组定义 vector<vector<int>> matrix;
2.二维数组大小 行：matirx.size();列：matrinx[0].size()
```
# 注意：
```
1.右上角的下标[0][matirx[0].size()-1]
2.左下角的下标[matrinx[0].size()][0]
```
