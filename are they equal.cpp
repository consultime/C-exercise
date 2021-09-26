// are they equal.cpp : 该文件为抄录算法笔记，并非我手写。
//

#include <iostream>
#include<string>
using namespace std;
int n;
string  deal(string s, int& e) // e为指数
{
    int k = 0; //s的下标
    while (s.length() > 0 && s[0] == '0')
    {
        s.erase(s.begin()); //去掉s的前导零；
    }
    if (s[0] =='.') //去掉前导零后是小数点，说明s是小于1的小数
    {
        s.erase(s.begin());     //去掉小数点
        while (s.length() > 0 && s[0] == '0')
        {
            s.erase(s.begin()); //去掉小数点后非零位前的所有零
            e--;    //每去掉一个0，指数e减1；
        }
        
    }
    else            //去掉前导零后不是小数点，则找到后面的小数点删除
    {
        while (k < s.length() && s[k] != '.') //寻找小数点
        {
            k++;
            e++;   //只要不碰到小数点就让指数e++
        }
        if (k < s.length()) //while结束后k<s.length(),说明碰到了小数点
        {
            s.erase(s.begin() + k);//把小数点删除
        }
    }
    if (s.length() == 0)
    {
        e = 0; //如果去除前导零后s的长度变为0，说明这个数是0
    }
    int num = 0;
    k = 0;
    string res;
    while (num < n) //只要精度没到n，即须保留几位小数
    {
        if (k < s.length()) res += s[k++]; //只要还有数字，就加到res末尾
        else res += '0'; //否则res末尾添加0
        num++;  //精度加1
    }
    return res;
  
}

int main()
{
    string s1, s2, s3, s4;
    cin >> n >> s1 >> s2;//可直接存入string，无需考虑数字如何转换成字符串
    int e1 = 0, e2 = 0; //e1,e2为s1与s2的指数
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);
    if (s3 == s4 && e1 == e2)//主体相同且指数相同
    {
        cout << "YES 0." << s3 << "*10^" << e1 << endl;
    }
    else
    {
        cout << "NO 0." << s3 << "*10^" << e1 << " 0." << "*10^" << e2 << endl;
    }
    return 0;
}
