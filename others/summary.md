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
