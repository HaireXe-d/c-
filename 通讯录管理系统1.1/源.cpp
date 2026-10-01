#include <iostream>
#include <fstream>
#include <string>
#define MAX 1000

using namespace std;

void showMenu()
{
    cout << "**************************" << endl;
    cout << "*****  1.添加联系人  *****" << endl;
    cout << "*****  2.显示联系人  *****" << endl;
    cout << "*****  3.删除联系人  *****" << endl;
    cout << "*****  4.查找联系人  *****" << endl;
    cout << "*****  5.修改联系人  *****" << endl;
    cout << "*****  6.清空联系人  *****" << endl;
    cout << "*****  0.退出通讯录  *****" << endl;
    cout << "**************************" << endl;
}

struct Person
{
    string m_name;
    int m_sex;     // 1男 2女
    int m_age;
    string m_phone;
    string m_addr;
};

struct Addressbooks
{
    Person personarray[MAX];
    int m_Size;
};

/* ================= 文件操作 ================= */

// 保存通讯录到文件
void saveToFile(Addressbooks* abs)
{
    ofstream ofs("contacts.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "文件打开失败！" << endl;
        return;
    }

    for (int i = 0; i < abs->m_Size; i++)
    {
        ofs << abs->personarray[i].m_name << " "
            << abs->personarray[i].m_sex << " "
            << abs->personarray[i].m_age << " "
            << abs->personarray[i].m_phone << " "
            << abs->personarray[i].m_addr << endl;
    }
    ofs.close();
}

// 从文件加载通讯录
void loadFromFile(Addressbooks* abs)
{
    ifstream ifs("contacts.txt", ios::in);
    if (!ifs.is_open())
    {
        abs->m_Size = 0;
        return;
    }

    abs->m_Size = 0;
    while (ifs >> abs->personarray[abs->m_Size].m_name &&
        ifs >> abs->personarray[abs->m_Size].m_sex &&
        ifs >> abs->personarray[abs->m_Size].m_age &&
        ifs >> abs->personarray[abs->m_Size].m_phone &&
        ifs >> abs->personarray[abs->m_Size].m_addr)
    {
        abs->m_Size++;
        if (abs->m_Size >= MAX)
            break;
    }
    ifs.close();
}

/* ================= 功能函数 ================= */

void addPerson(Addressbooks* abs)
{
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }

    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    abs->personarray[abs->m_Size].m_name = name;

    cout << "请输入性别：" << endl;
    cout << "1 --- 男" << endl;
    cout << "2 --- 女" << endl;
    int sex;
    while (true)
    {
        cin >> sex;
        if (sex == 1 || sex == 2)
        {
            abs->personarray[abs->m_Size].m_sex = sex;
            break;
        }
        cout << "输入错误，请重新输入。" << endl;
    }

    cout << "请输入年龄：" << endl;
    cin >> abs->personarray[abs->m_Size].m_age;

    cout << "请输入电话号码：" << endl;
    cin >> abs->personarray[abs->m_Size].m_phone;

    cout << "请输入住址：" << endl;
    cin >> abs->personarray[abs->m_Size].m_addr;

    abs->m_Size++;
    cout << "添加成功！" << endl;
    system("pause");
    system("cls");
}

void showpeople(Addressbooks* abs)
{
    if (abs->m_Size == 0)
    {
        cout << "通讯录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            cout << "姓名：" << abs->personarray[i].m_name << "\t";
            cout << "性别：" << (abs->personarray[i].m_sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personarray[i].m_age << "\t";
            cout << "电话：" << abs->personarray[i].m_phone << "\t";
            cout << "住址：" << abs->personarray[i].m_addr << endl;
        }
    }
    system("pause");
    system("cls");
}

int isexist(Addressbooks* abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personarray[i].m_name == name)
            return i;
    }
    return -1;
}

void deleteperson(Addressbooks* abs)
{
    cout << "请输入要删除的联系人：" << endl;
    string name;
    cin >> name;

    int ret = isexist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->m_Size - 1; i++)
        {
            abs->personarray[i] = abs->personarray[i + 1];
        }
        abs->m_Size--;
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "未找到该联系人" << endl;
    }
    system("pause");
    system("cls");
}

void findpeople(Addressbooks* abs)
{
    cout << "请输入要查找的联系人：" << endl;
    string name;
    cin >> name;

    int ret = isexist(abs, name);
    if (ret != -1)
    {
        cout << "姓名：" << abs->personarray[ret].m_name << "\t";
        cout << "性别：" << (abs->personarray[ret].m_sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personarray[ret].m_age << "\t";
        cout << "电话：" << abs->personarray[ret].m_phone << "\t";
        cout << "住址：" << abs->personarray[ret].m_addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

void modifypeople(Addressbooks* abs)
{
    cout << "请输入要修改的联系人：" << endl;
    string name;
    cin >> name;

    int ret = isexist(abs, name);
    if (ret != -1)
    {
        cout << "请输入新姓名：" << endl;
        cin >> abs->personarray[ret].m_name;

        cout << "请输入性别（1-男 2-女）：" << endl;
        int sex;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personarray[ret].m_sex = sex;
                break;
            }
            cout << "输入错误，请重新输入。" << endl;
        }

        cout << "请输入年龄：" << endl;
        cin >> abs->personarray[ret].m_age;

        cout << "请输入电话号码：" << endl;
        cin >> abs->personarray[ret].m_phone;

        cout << "请输入住址：" << endl;
        cin >> abs->personarray[ret].m_addr;

        cout << "修改成功！" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

int main()
{
    Addressbooks abs;
    abs.m_Size = 0;

    // 启动时加载文件
    loadFromFile(&abs);

    int select = 0;
    while (true)
    {
        showMenu();
        cin >> select;

        switch (select)
        {
        case 1:
            addPerson(&abs);
            saveToFile(&abs);
            break;
        case 2:
            showpeople(&abs);
            break;
        case 3:
            deleteperson(&abs);
            saveToFile(&abs);
            break;
        case 4:
            findpeople(&abs);
            break;
        case 5:
            modifypeople(&abs);
            saveToFile(&abs);
            break;
        case 6:
            abs.m_Size = 0;
            saveToFile(&abs);
            cout << "通讯录已清空！" << endl;
            system("pause");
            system("cls");
            break;
        case 0:
            saveToFile(&abs);
            cout << "感谢使用，再见！" << endl;
            system("pause");
            return 0;
        default:
            cout << "输入有误，请重新输入！" << endl;
            break;
        }
    }
}