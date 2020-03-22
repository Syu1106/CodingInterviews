# 题目描述
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"], ["s","f","c","s"], ["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。  
## 示例：
```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
```
# 解题思路
```
(DFS 深度优先)
1.对于每一个字符，对它周围的四个方向进行搜索，判断是否有符合路线的字母
2.搜索的每条路径时，已经搜索过的字符进行标记，避免重复搜索
3.搜索完毕后，标记的字符变回原来的字符
4.递归结束的条件：①与要求路径不符，②路径搜索完成
5.空间复杂度O(1),时间复杂度O(n^2)
```
# 代码
```
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int i=0,j=0;
        if(board.size()==0||word.size()==0) return 0;
        for(i=0;i<board.size();i++)
            for(j=0;j<board[0].size();j++)
            {
                if(search(board, word,i,j))   return true;          
            }
            return false;
    }
    bool search(vector<vector<char>>& board, string word,int i,int j)
    {
        if(word.size()==0) return true;
        else
        {            
            char a=board[i][j];
            board[i][j]='0'; 
            if(a==word[0])
            {
                if(word.size()>1)
                {
                    if(i-1>-1&&board[i-1][j]!='0')
                    {
                        if(search(board,word.substr(1),i-1,j))//上
                        return true;
                    }                     
                    if(i+1<board.size()&&board[i+1][j]!='0') 
                    {
                        if(search(board,word.substr(1),i+1,j))//下
                        return true;
                    }
                    if(j-1>-1&&board[i][j-1]!='0') 
                    {
                        if(search(board,word.substr(1),i,j-1))//左
                        return true;                 
                    }
                    if(j+1<board[0].size()&&board[i][j+1]!='0') 
                    {
                        if(search(board,word.substr(1),i,j+1))//右 
                        return true;
                    } 
                }
                else
                return true;
            }
            board[i][j]=a;
            return 0;
        }       
    }
};
```
# 参考
- [截取一部分字符](https://blog.csdn.net/ezhou_liukai/article/details/13779091)
```
 s.substr(pos, n)    //截取s中从pos开始（包括0）的n个字符的子串，并返回
 s.substr(pos)    //截取s中从从pos开始（包括0）到末尾的所有字符的子串，并返回
```
