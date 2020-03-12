# 题目描述
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
```
示例：
输入：head = [1,3,2]
输出：[2,3,1]
```
# 思路一 修改链表结构：
```
1.用pre-前一个节点，cur-当前节点，next-下一个节点
2.当前节点指向前一个节点
3.前一个节点跟当前节点更新（往后挪一个）
```
# 思路二 递归
# 思路三 数组反转
先存数组，再用reverse反转
# 思路四 堆栈
栈的顺序是先进后出
# 代码1 修改链表结构：
```
class Solution {//改变链表结构
vector<int> res;
public:  
    vector<int> reversePrint(ListNode* head) {
    ListNode *next=head;   
    ListNode *cur=head;
    ListNode *pre=nullptr;//空指针？？
    while(cur){
    next=cur->next;
    cur->next=pre;
    pre=cur;
    cur=next;  
    }
    while(pre)
    {
        res.push_back(pre->val);
        pre=pre->next;
    }
    return res;
    }
};
```
# 代码2 递归
```
class Solution {//递归
vector<int> res;
public:
    vector<int> reversePrint(ListNode* head) {
    if(head==NULL) return res;
    reversePrint(head->next);
    res.push_back(head->val);
    return res;
    }
};
```
# 代码3 数组反转
```
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
    vector<int> res;
    int i;
    ListNode* temp=head;
    while(temp)
    {
        res.push_back(temp->val);
        temp=temp->next;
    }  
    reverse(res.begin(),res.end());//数组反转
    return res;
    }
};
```
# 代码4 堆栈
```
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
    stack<int> st;//栈的用法
    vector<int> res;
    int i;
    ListNode* temp=head;
    while(temp)
    {
        st.push(temp->val);
        temp=temp->next;
    }  
    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
    }
};
```
# 参考：
1.节点构造  
```
 struct ListNode {  
      int val;  
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 ListNode* temp=nullptr; 
```
2.[指针初始化nullptr](https://zhuanlan.zhihu.com/p/79883965)  
    C++中不能将void *类型的指针隐式转换成其他指针类型,NULL定义为(void*)0  
    nullptr并非整型类别，甚至也不是指针类型，但是能转换成任意指针类型。nullptr的实际类型是std:nullptr_t  
3.数组反转  
reverse(res.begin(),res.end());  
4.栈的基础用法
```
stack<int> st;
st.push()//压入元素
st.top()//栈顶值
st.pop()//弹出元素
```
