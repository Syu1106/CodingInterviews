# vector 
- 数组反转 reverse(res.begin(),res.end());
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
