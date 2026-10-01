#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// 打印主菜单，单独封装可以简化 main 函数逻辑
void showMenu()
{
    cout << "******************************" << endl;
    cout << "*****  个人备忘录管理系统  *****" << endl;
    cout << "*****  1. 新增备忘记录    *****" << endl;
    cout << "*****  2. 查看全部备忘    *****" << endl;
    cout << "*****  3. 按标题查询备忘  *****" << endl;
    cout << "*****  4. 修改备忘内容    *****" << endl;
    cout << "*****  5. 删除备忘记录    *****" << endl;
    cout << "*****  6. 按日期筛选备忘  *****" << endl;
    cout << "*****  7. 备忘数据统计    *****" << endl;
    cout << "*****  0. 退出系统        *****" << endl;
    cout << "******************************" << endl;
    cout << "请选择功能：";
}

// 用于暂停界面，避免多处重复书写
void pauseScreen()
{
    cout << "\n按回车键继续...";
    cin.get();
}

// Note 类表示一条备忘数据，成员变量私有化，体现封装思想
class Note
{
private:
    string title;      // 备忘标题
    string date;       // 备忘日期，格式建议为 yyyy-MM-dd
    string content;    // 备忘详细内容

public:
    // 无参构造函数，保证动态对象数组创建时可以默认初始化
    Note()
    {
        title = "";
        date = "";
        content = "";
    }

    // 带参构造函数，便于直接创建一条完整备忘
    Note(string t, string d, string c)
    {
        title = t;
        date = d;
        content = c;
    }

    // 取值函数：外部不能直接访问私有成员，只能通过接口读取
    string getTitle() const
    {
        return title;
    }

    string getDate() const
    {
        return date;
    }

    string getContent() const
    {
        return content;
    }

    // 修改函数：只开放修改详情内容的接口，避免随意修改全部数据
    void editContent(const string& newContent)
    {
        content = newContent;
    }

    // 输入单条备忘信息，使用 getline 支持中文和空格输入
    void inputNote()
    {
        cout << "请输入备忘标题：";
        getline(cin, title);

        cout << "请输入备忘日期（格式 yyyy-MM-dd）：";
        getline(cin, date);

        cout << "请输入备忘详情：";
        getline(cin, content);
    }

    // 格式化显示单条备忘信息
    void showNote(int index) const
    {
        cout << left << setw(6) << index
            << setw(20) << title
            << setw(15) << date
            << content << endl;
    }
};

// MemoManager 类负责管理全部备忘，内部使用动态对象数组存储数据
class MemoManager
{
private:
    Note* memoArr;     // 动态对象数组指针
    int capacity;      // 当前数组最大容量
    int size;          // 当前实际存储数量

public:
    // 构造函数：默认开辟 5 个 Note 对象的动态数组
    MemoManager(int initCapacity = 5)
    {
        capacity = initCapacity;
        size = 0;
        memoArr = new Note[capacity];
    }

    // 析构函数：程序结束时释放动态数组，防止内存泄漏
    ~MemoManager()
    {
        delete[] memoArr;
        memoArr = nullptr;
    }

    // 动态扩容函数：每次容量不足时增加 5 条存储空间
    void expandArray()
    {
        int newCapacity = capacity + 5;
        Note* newArr = new Note[newCapacity];

        // 将原数组中的有效数据复制到新数组
        for (int i = 0; i < size; i++)
        {
            newArr[i] = memoArr[i];
        }

        // 释放旧数组，并让指针指向新数组
        delete[] memoArr;
        memoArr = newArr;
        capacity = newCapacity;

        cout << "数组容量不足，已自动扩容到 " << capacity << " 条。" << endl;
    }

    // 新增备忘记录
    void addNote()
    {
        if (size == capacity)
        {
            expandArray();
        }

        memoArr[size].inputNote();
        size++;

        cout << "新增备忘成功！" << endl;
    }

    // 查看全部备忘
    void showAllNote() const
    {
        if (size == 0)
        {
            cout << "当前没有备忘记录。" << endl;
            return;
        }

        cout << left << setw(6) << "序号"
            << setw(20) << "标题"
            << setw(15) << "日期"
            << "详情" << endl;
        cout << "------------------------------------------------------------" << endl;

        for (int i = 0; i < size; i++)
        {
            memoArr[i].showNote(i + 1);
        }
    }

    // 按标题查找备忘，返回对象指针，查不到返回 nullptr
    Note* findNoteByTitle(const string& title)
    {
        for (Note* p = memoArr; p < memoArr + size; p++)
        {
            if (p->getTitle() == title)
            {
                return p;
            }
        }
        return nullptr;
    }

    // 根据标题查找下标，主要用于删除时进行数组移位
    int findIndexByTitle(const string& title) const
    {
        for (int i = 0; i < size; i++)
        {
            if (memoArr[i].getTitle() == title)
            {
                return i;
            }
        }
        return -1;
    }

    // 按标题查询备忘
    void searchNote()
    {
        string title;
        cout << "请输入要查询的备忘标题：";
        getline(cin, title);

        Note* result = findNoteByTitle(title);
        if (result != nullptr)
        {
            cout << "查询结果如下：" << endl;
            cout << left << setw(6) << "序号"
                << setw(20) << "标题"
                << setw(15) << "日期"
                << "详情" << endl;
            cout << "------------------------------------------------------------" << endl;
            result->showNote(1);
        }
        else
        {
            cout << "未找到该标题对应的备忘。" << endl;
        }
    }

    // 修改备忘内容
    void modifyNote()
    {
        string title;
        cout << "请输入要修改的备忘标题：";
        getline(cin, title);

        Note* result = findNoteByTitle(title);
        if (result != nullptr)
        {
            string newContent;
            cout << "请输入新的备忘详情：";
            getline(cin, newContent);
            result->editContent(newContent);
            cout << "修改成功！" << endl;
        }
        else
        {
            cout << "未找到该标题对应的备忘。" << endl;
        }
    }

    // 删除备忘记录
    void deleteNote()
    {
        string title;
        cout << "请输入要删除的备忘标题：";
        getline(cin, title);

        int index = findIndexByTitle(title);
        if (index != -1)
        {
            // 后续元素依次向前覆盖，实现数组移位删除
            for (int i = index; i < size - 1; i++)
            {
                memoArr[i] = memoArr[i + 1];
            }
            size--;
            cout << "删除成功！" << endl;
        }
        else
        {
            cout << "未找到该标题对应的备忘。" << endl;
        }
    }

    // 按日期筛选备忘
    void filterByDate() const
    {
        string date;
        cout << "请输入要筛选的日期（格式 yyyy-MM-dd）：";
        getline(cin, date);

        bool found = false;
        cout << left << setw(6) << "序号"
            << setw(20) << "标题"
            << setw(15) << "日期"
            << "详情" << endl;
        cout << "------------------------------------------------------------" << endl;

        int number = 1;
        for (int i = 0; i < size; i++)
        {
            if (memoArr[i].getDate() == date)
            {
                memoArr[i].showNote(number++);
                found = true;
            }
        }

        if (!found)
        {
            cout << "该日期没有备忘记录。" << endl;
        }
    }

    // 备忘数据统计
    void showStat() const
    {
        cout << "当前已保存备忘数量：" << size << endl;
        cout << "当前动态数组容量：" << capacity << endl;
        cout << "剩余可直接存储数量：" << capacity - size << endl;
    }
};

int main()
{
    MemoManager manager;
    int select = -1;

    while (true)
    {
        showMenu();
        cin >> select;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "输入有误，请输入数字菜单项！" << endl;
            pauseScreen();
            continue;
        }

        // 清除数字菜单输入后残留的换行，保证后续 getline 正常读取
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (select)
        {
        case 1:
            manager.addNote();
            pauseScreen();
            break;
        case 2:
            manager.showAllNote();
            pauseScreen();
            break;
        case 3:
            manager.searchNote();
            pauseScreen();
            break;
        case 4:
            manager.modifyNote();
            pauseScreen();
            break;
        case 5:
            manager.deleteNote();
            pauseScreen();
            break;
        case 6:
            manager.filterByDate();
            pauseScreen();
            break;
        case 7:
            manager.showStat();
            pauseScreen();
            break;
        case 0:
            cout << "感谢使用个人备忘录管理系统，欢迎下次使用！" << endl;
            return 0;
        default:
            cout << "输入有误，请重新选择！" << endl;
            pauseScreen();
            break;
        }
    }

    return 0;
}
