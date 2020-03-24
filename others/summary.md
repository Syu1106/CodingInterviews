# vector 
- 成员变量不能直接调用vector的构造函数声明并初始化 声明只能vector<int>a;
- 成员变量声明并初始化 vector<int>a=vector<int>(100,0);vector<vector<int>> a=vector<vector<int>>(3,vector<int>(4,100));
- 初始化 a=vector<int> (100,0);a=vector<vector<int>>(3,vector<int>(4,100));
- 函数内声明并初始化 vector<int>a(100,0);//将a的100个元素初始化为0 
- 反转 reverse(res.begin(),res.end());
# 数组
- 声明 int a[100];
- 初始化 memset(a,0,sizeof(int)*100);
# 链表
- 节点构造  
```
 struct ListNode {  
      int val;  
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  ListNode* temp=nullptr; 
```
# 指针
- [指针初始化 int *p=nullptr](https://zhuanlan.zhihu.com/p/79883965)  
    C++中不能将void *类型的指针隐式转换成其他指针类型,NULL定义为(void*)0  
    nullptr并非整型类别，甚至也不是指针类型，但是能转换成任意指针类型。nullptr的实际类型是std:nullptr_t
# 栈
- 基础用法
```
stack<int> st;
st.push()//压入元素
st.top()//栈顶值
st.pop()//弹出元素

```
# String
- [截取一部分字符](https://blog.csdn.net/ezhou_liukai/article/details/13779091)
```
 s.substr(pos, n)    //截取s中从pos开始（包括0）的n个字符的子串，并返回
 s.substr(pos)    //截取s中从从pos开始（包括0）到末尾的所有字符的子串，并返回
```
# 方法
- [快速幂与矩阵快速幂](https://blog.csdn.net/FlushHip/article/details/80068888)
