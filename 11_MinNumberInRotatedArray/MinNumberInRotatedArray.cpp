// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>   
#include<conio.h>
using namespace std;
int MinInOrder(vector<int>&a,int index1,int index2)
    {
        int min1 = a[index1];
            for(int i=index1+1;i<=index2;i++)
            {
                if(min1>=a[i])
                    min1=a[i];
            } 
    return min1;
    }
int min_num(vector<int>&a,int length )
{
    // if(a.empty() || length<1)
    //     cout<<"invalid parameter"<<endl;
    //     return 0;
    int index1=0;
    int index2=length-1;
    int indexmid=index1;
    while(a[index1]>=a[index2])
    {
        if(index2-index1==1)
           {
               indexmid=index2;
               break;
           } 
        indexmid=(index1+index2)/2;
        if(a[index1]==a[indexmid] && a[index2]==a[indexmid])
            return MinInOrder(a,index1,index2);
        if(a[index1]>=a[indexmid])
            index2=indexmid;
        else if(a[index1]<=a[indexmid])
            index1=indexmid;
    }
    return a[indexmid]  ; 
}

//测试代码
void test(vector<int>&a)
{
    cout<<min_num(a,a.size())<<endl;
}
int main()
{
    // 典型输入，单调升序的数组的一个旋转
    vector<int>a={ 3, 4, 5, 1, 2 };
    test(a);

    // 有重复数字，并且重复的数字刚好的最小的数字
    vector<int>a1={ 3, 4, 5, 1, 1, 2 };
    test(a1);
    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    vector<int>a2={ 3, 4, 5, 1, 2, 2 };
    test(a2);
    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    vector<int>a3={ 1, 0, 1, 1, 1 };
    test(a3);
    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    vector<int>a4={ 1, 2, 3, 4, 5 };    
    test(a4);
    // 数组中只有一个数字
    vector<int>a5={2}; 
    test(a5); 
    system("pause");
    return 0;
}
