// 简单计算器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//此程序来自算法笔记p249
//第七章

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
using   namespace std;

struct node
{
    double num;   //操作数
    char op;    //操作符
    bool flag;  //
};

string  str;
stack<node> s;  //
queue<node> q;  //
map<char, int> op;  //

void    Change()    //
{
    double num;
    node temp;
    for (int i = 0; i < str.length();)  //注意这里不要i++，因为i++在程序体中。
    {
        if (str[i] >= '0' && str[i] <= '9')     //
        {
            temp.flag = true;
            temp.num = str[i++] - '0';      //
            while (i < str.length() && str[i] >= '0' && str[i] <= '9')
            {
                temp.num = temp.num * 10 + (str[i] - '0');      //
                i++;
            }
            q.push(temp);       //
        }
        else   //
        {
            temp.flag = false;     //
            //
            //
            while (!s.empty() && op[str[i]] <= op[s.top().op])
            {
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

double Cal()
{
    double  temp1, temp2;
    node cur, temp;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur.flag == true)
        {
            s.push(cur);
        }
        else
        {
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;
            if (cur.op == '+')temp.num = temp1 + temp2;
            else if (cur.op == '-')temp.num = temp1 - temp2;
            else if (cur.op == '*')temp.num = temp1 * temp2;
            else temp.num = temp1 / temp2;
            s.push(temp);
        }
    }
    return s.top().num;
}

int main()
{
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while (getline(cin, str), str != "0")
    {
        for (string::iterator it = str.end()-1; it != str.begin(); it--)
        {
            if (*it == ' ') str.erase(it);
        }
        while (!s.empty()) s.pop();
        Change();
        printf("%.2f\n", Cal());
    }
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
