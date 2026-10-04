#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const int MAX = 100;

struct Note
{
    char title[30];
    char date[15];
    char content[150];
};

Note notes[MAX];
int noteCount = 0;   

void printMenu()
{
    cout << "\n============== 个人备忘录管理系统 ==============\n";
    cout << "  [1] 新增备忘        [2] 查看全部        [3] 查询备忘\n";
    cout << "  [4] 修改备忘        [5] 删除备忘        [6] 日期筛选\n";
    cout << "  [7] 数据统计        [0] 退出系统\n";
    cout << "==============================================\n";
}

void addNote()
{
    if (noteCount >= MAX)
    {
        cout << "系统空间已满！\n";
        return;
    }

    cout << "请输入标题：";
    cin.ignore();
    cin.getline(notes[noteCount].title, 30);

    cout << "请输入日期：";
    cin.getline(notes[noteCount].date, 15);

    cout << "请输入内容：";
    cin.getline(notes[noteCount].content, 150);

    noteCount++;
    cout << "? 添加成功！\n";
}

void showAll()
{
    if (noteCount == 0)
    {
        cout << "暂无备忘记录。\n";
        return;
    }

    cout << left << setw(6) << "序号"
        << setw(20) << "标题"
        << setw(15) << "日期"
        << "内容\n";
    cout << "-----------------------------------------------\n";

    for (int i = 0; i < noteCount; i++)
    {
        cout << left << setw(6) << i + 1
            << setw(20) << notes[i].title
            << setw(15) << notes[i].date
            << notes[i].content << endl;
    }
}

void searchNote()
{
    char key[30];
    cout << "请输入要查询的标题：";
    cin.ignore();
    cin.getline(key, 30);

    for (int i = 0; i < noteCount; i++)
    {
        if (strcmp(notes[i].title, key) == 0)
        {
            cout << "查询结果：\n";
            cout << notes[i].date << " | " << notes[i].content << endl;
            return;
        }
    }
    cout << "未找到该备忘。\n";
}

void modifyNote()
{
    char key[30];
    cout << "请输入要修改的标题：";
    cin.ignore();
    cin.getline(key, 30);

    for (int i = 0; i < noteCount; i++)
    {
        if (strcmp(notes[i].title, key) == 0)
        {
            cout << "请输入新内容：";
            cin.getline(notes[i].content, 150);
            cout << "修改成功！\n";
            return;
        }
    }
    cout << "未找到该备忘。\n";
}

void deleteNote()
{
    char key[30];
    cout << "请输入要删除的标题：";
    cin.ignore();
    cin.getline(key, 30);

    for (int i = 0; i < noteCount; i++)
    {
        if (strcmp(notes[i].title, key) == 0)
        {
            for (int j = i; j < noteCount - 1; j++)
            {
                notes[j] = notes[j + 1];
            }
            noteCount--;
            cout << "删除成功！\n";
            return;
        }
    }
    cout << "未找到该备忘。\n";
}

void filterByDate()
{
    char d[15];
    cout << "请输入日期：";
    cin.ignore();
    cin.getline(d, 15);

    bool flag = false;
    for (int i = 0; i < noteCount; i++)
    {
        if (strcmp(notes[i].date, d) == 0)
        {
            cout << notes[i].title << " | " << notes[i].content << endl;
            flag = true;
        }
    }

    if (!flag)
        cout << "该日期没有备忘。\n";
}

void statistics()
{
    cout << "当前备忘总数：" << noteCount << endl;
    cout << "剩余可用空间：" << MAX - noteCount << endl;
}

void run()
{
    int choice;
    while (true)
    {
        printMenu();
        cout << "请输入菜单编号：";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1: addNote(); break;
        case 2: showAll(); break;
        case 3: searchNote(); break;
        case 4: modifyNote(); break;
        case 5: deleteNote(); break;
        case 6: filterByDate(); break;
        case 7: statistics(); break;
        case 0: cout << "感谢使用，再见！\n"; return;
        default: cout << "输入无效，请重新选择。\n";
        }
    }
}

int main()
{
    run();
    system("pause");
    return 0;
}