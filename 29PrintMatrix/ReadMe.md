# 题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字  
```
示例：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
```
# 方法：模拟打印顺序
```
1.用top,bottom,left,right标记上下左右的边界
2.循环打印顺序：
left-->right,top++
top-->bottom,right--
right-->left,bottom++
bottom-->top,left++
3.循环退出条件：top<bottom || left>right        
```
# 代码：
```
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(matrix.size()==0)
    {
        return {};
    }
    int t=0,b=matrix.size()-1,l=0,r=matrix[0].size()-1,i=0;//top,bottom,left,right
    vector<int>res;
    int size=matrix.size()*matrix[0].size();
    while(res.size()<size)
    {
        for(i=l;i<=r;i++)
        {
            res.push_back(matrix[t][i]);           
        }
        t++;
        if(t>b) break;
        for(i=t;i<=b;i++)
        {
            res.push_back(matrix[i][r]);
        }
        r--;
        if(l>r) break;
        for(i=r;i>=l;i--)
        {
            res.push_back(matrix[b][i]);
        }
        b--;
        if(t>b) break;
        for(i=b;i>=t;i--)
        {
            res.push_back(matrix[i][l]);
        }
        l++;
        if(l>r) break;

    }
    return res;
}
```
