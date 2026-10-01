#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
using namespace std;

bool haveNumber(vector<int> a, int x)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (a[i] == x)
        {
            return true;
        }
    }
    return false;
}

void sortBalls(vector<int>& a)
{
    int n = (int)a.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void showMenu()
{
    cout << "==============================" << endl;
    cout << "   双色球模拟彩票游戏程序" << endl;
    cout << "==============================" << endl;
    cout << "1. 显示中奖规则" << endl;
    cout << "2. 机选一注号码" << endl;
    cout << "3. 手动输入号码" << endl;
    cout << "4. 模拟开奖" << endl;
    cout << "5. 查看当前号码" << endl;
    cout << "6. 开始对奖" << endl;
    cout << "7. 保存本次结果" << endl;
    cout << "0. 退出程序" << endl;
    cout << "请选择功能：";
}

void showRule()
{
    cout << "\n【双色球基本规则】" << endl;
    cout << "每注号码由 6 个红球和 1 个蓝球组成。" << endl;
    cout << "红球范围：1-33，蓝球范围：1-16。" << endl;
    cout << "红球顺序不限，不能重复。" << endl;
    cout << "一等奖：中 6 个红球 + 1 个蓝球" << endl;
    cout << "二等奖：中 6 个红球 + 0 个蓝球" << endl;
    cout << "三等奖：中 5 个红球 + 1 个蓝球，奖金 3000 元" << endl;
    cout << "四等奖：中 5 个红球，或中 4 个红球 + 1 个蓝球，奖金 200 元" << endl;
    cout << "五等奖：中 4 个红球，或中 3 个红球 + 1 个蓝球，奖金 10 元" << endl;
    cout << "六等奖：只要中 1 个蓝球，奖金 5 元" << endl;
    cout << "福运奖：特别规定期间中 3 个红球，奖金 5 元" << endl;
}

void randomTicket(vector<int>& red, int& blue)
{
    red.clear();
    while ((int)red.size() < 6)
    {
        int x = rand() % 33 + 1;
        if (!haveNumber(red, x))
        {
            red.push_back(x);
        }
    }
    sortBalls(red);
    blue = rand() % 16 + 1;
}

void inputTicket(vector<int>& red, int& blue)
{
    red.clear();
    cout << "\n请输入 6 个红球号码（1-33，不能重复）：" << endl;
    while ((int)red.size() < 6)
    {
        int x;
        cout << "请输入第 " << red.size() + 1 << " 个红球：";
        cin >> x;
        if (x < 1 || x > 33)
        {
            cout << "红球号码范围是 1-33，请重新输入。" << endl;
        }
        else if (haveNumber(red, x))
        {
            cout << "这个红球已经选过，请重新输入。" << endl;
        }
        else
        {
            red.push_back(x);
        }
    }

    sortBalls(red);

    while (true)
    {
        cout << "请输入蓝球号码（1-16）：";
        cin >> blue;
        if (blue >= 1 && blue <= 16)
        {
            break;
        }
        cout << "蓝球号码范围是 1-16，请重新输入。" << endl;
    }
}

void printBalls(vector<int> red, int blue)
{
    cout << "红球：";
    for (int i = 0; i < (int)red.size(); i++)
    {
        cout << setw(2) << setfill('0') << red[i] << " ";
    }
    cout << setfill(' ');
    cout << "  蓝球：" << setw(2) << setfill('0') << blue << setfill(' ') << endl;
}

int countRed(vector<int> userRed, vector<int> winRed)
{
    int count = 0;
    for (int i = 0; i < (int)userRed.size(); i++)
    {
        for (int j = 0; j < (int)winRed.size(); j++)
        {
            if (userRed[i] == winRed[j])
            {
                count++;
            }
        }
    }
    return count;
}

string getPrize(int redCount, bool blueRight)
{
    if (redCount == 6 && blueRight)
    {
        return "一等奖（浮动奖金）";
    }
    else if (redCount == 6 && !blueRight)
    {
        return "二等奖（浮动奖金）";
    }
    else if (redCount == 5 && blueRight)
    {
        return "三等奖，奖金 3000 元";
    }
    else if (redCount == 5 || (redCount == 4 && blueRight))
    {
        return "四等奖，奖金 200 元";
    }
    else if (redCount == 4 || (redCount == 3 && blueRight))
    {
        return "五等奖，奖金 10 元";
    }
    else if (blueRight)
    {
        return "六等奖，奖金 5 元";
    }
    else if (redCount == 3)
    {
        return "福运奖（特别规定期间），奖金 5 元";
    }
    else
    {
        return "未中奖";
    }
}

void showNow(bool hasTicket, bool hasOpen,
    vector<int> userRed, int userBlue,
    vector<int> winRed, int winBlue)
{
    cout << "\n【当前号码】" << endl;
    if (hasTicket)
    {
        cout << "投注号码：";
        printBalls(userRed, userBlue);
    }
    else
    {
        cout << "还没有投注号码。" << endl;
    }

    if (hasOpen)
    {
        cout << "开奖号码：";
        printBalls(winRed, winBlue);
    }
    else
    {
        cout << "还没有模拟开奖。" << endl;
    }
}

void checkPrize(bool hasTicket, bool hasOpen,
    vector<int> userRed, int userBlue,
    vector<int> winRed, int winBlue,
    string& lastResult)
{
    if (!hasTicket)
    {
        cout << "请先机选或手动输入一注号码。" << endl;
        return;
    }
    if (!hasOpen)
    {
        cout << "请先模拟开奖。" << endl;
        return;
    }

    int redCount = countRed(userRed, winRed);
    bool blueRight = (userBlue == winBlue);
    lastResult = getPrize(redCount, blueRight);

    cout << "\n【对奖结果】" << endl;
    cout << "投注号码：";
    printBalls(userRed, userBlue);
    cout << "开奖号码：";
    printBalls(winRed, winBlue);
    cout << "命中红球个数：" << redCount << endl;
    cout << "蓝球是否命中：" << (blueRight ? "是" : "否") << endl;
    cout << "中奖情况：" << lastResult << endl;
}

void saveResult(bool hasTicket, bool hasOpen,
    vector<int> userRed, int userBlue,
    vector<int> winRed, int winBlue,
    string lastResult)
{
    if (!hasTicket || !hasOpen)
    {
        cout << "投注号码或开奖号码不完整，不能保存。" << endl;
        return;
    }

    ofstream fout("lottery_result.txt");
    if (!fout.is_open())
    {
        cout << "文件打开失败，保存失败。" << endl;
        return;
    }

    fout << "双色球模拟彩票游戏结果" << endl;
    fout << "投注红球：";
    for (int i = 0; i < (int)userRed.size(); i++)
    {
        fout << userRed[i] << " ";
    }
    fout << "  投注蓝球：" << userBlue << endl;

    fout << "开奖红球：";
    for (int i = 0; i < (int)winRed.size(); i++)
    {
        fout << winRed[i] << " ";
    }
    fout << "  开奖蓝球：" << winBlue << endl;
    fout << "中奖情况：" << lastResult << endl;
    fout.close();

    cout << "结果已保存到 lottery_result.txt。" << endl;
}

int main()
{
    srand((unsigned int)time(0));

    vector<int> userRed;
    vector<int> winRed;
    int userBlue = 0;
    int winBlue = 0;
    bool hasTicket = false;
    bool hasOpen = false;
    string lastResult = "尚未对奖";

    int choice;
    while (true)
    {
        showMenu();
        cin >> choice;

        if (choice == 1)
        {
            showRule();
        }
        else if (choice == 2)
        {
            randomTicket(userRed, userBlue);
            hasTicket = true;
            lastResult = "尚未对奖";
            cout << "\n机选号码完成：";
            printBalls(userRed, userBlue);
        }
        else if (choice == 3)
        {
            inputTicket(userRed, userBlue);
            hasTicket = true;
            lastResult = "尚未对奖";
            cout << "\n手动选号完成：";
            printBalls(userRed, userBlue);
        }
        else if (choice == 4)
        {
            randomTicket(winRed, winBlue);
            hasOpen = true;
            lastResult = "尚未对奖";
            cout << "\n本期开奖号码：";
            printBalls(winRed, winBlue);
        }
        else if (choice == 5)
        {
            showNow(hasTicket, hasOpen, userRed, userBlue, winRed, winBlue);
        }
        else if (choice == 6)
        {
            checkPrize(hasTicket, hasOpen, userRed, userBlue, winRed, winBlue, lastResult);
        }
        else if (choice == 7)
        {
            saveResult(hasTicket, hasOpen, userRed, userBlue, winRed, winBlue, lastResult);
        }
        else if (choice == 0)
        {
            cout << "感谢使用双色球模拟彩票游戏程序，再见！" << endl;
            break;
        }
        else
        {
            cout << "输入有误，请重新选择。" << endl;
        }
        cout << endl;
    }

    return 0;
}
