#include<iostream>
using namespace std;

class person
{
public:
       person()
       {
        cout << "无参构造函数" << endl;
       }

       person(int age, int height)
       {
           m_age = age;
           m_height = new int(height); 
           cout << "有参构造函数" << endl;
       }

       person(const person& p)
       {
           m_age = p.m_age;
           m_height = new int(*p.m_height);
           cout << "拷贝构造函数" << endl;
          
       }

       ~person()
       {
           cout << "析构函数" << endl;
           if (m_height != NULL);
           {
               delete m_height;
           }
       }
public:
    int m_age;
    int* m_height;
};


void test01()
{
    person p;
    person p1(18, 175);
    person p2(p1);
    cout << "p1年龄" << p1.m_age << "身高" << *p1.m_height << endl;
    cout << "p2年龄" << p2.m_age << "身高" << *p2.m_height << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;

}