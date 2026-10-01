#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <fstream>
#include <iomanip>
using namespace std;

struct Card
{
    string suit;   // 花色
    string rank;   // 点数
};

const vector<string> SUITS = { "黑桃", "红桃", "梅花", "方块" };
const vector<string> RANKS = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

void showMenu()
{
    cout << "*******************************" << endl;
    cout << "***** 1.初始化一副扑克牌  *****" << endl;
    cout << "***** 2.显示当前牌组      *****" << endl;
    cout << "***** 3.洗牌              *****" << endl;
    cout << "***** 4.发牌              *****" << endl;
    cout << "***** 5.保存发牌结果      *****" << endl;
    cout << "***** 0.退出程序          *****" << endl;
    cout << "*******************************" << endl;
    cout << "请选择功能：";
}

void initDeck(vector<Card>& deck)
{
    deck.clear();
    for (const string& s : SUITS)
    {
        for (const string& r : RANKS)
        {
            deck.push_back({ s, r });
        }
    }
}

string cardToString(const Card& card)
{
    return card.suit + card.rank;
}

void showDeck(const vector<Card>& deck)
{
    if (deck.empty())
    {
        cout << "当前牌组为空，请先初始化。" << endl;
        return;
    }
    cout << "当前牌组共有 " << deck.size() << " 张牌：" << endl;
    for (size_t i = 0; i < deck.size(); ++i)
    {
        cout << setw(8) << cardToString(deck[i]);
        if ((i + 1) % 13 == 0)
            cout << endl;
    }
    cout << endl;
}

void shuffleDeck(vector<Card>& deck)
{
    if (deck.empty())
    {
        cout << "牌组为空，无法洗牌。" << endl;
        return;
    }
    random_device rd;
    mt19937 gen(rd());
    for (int i = (int)deck.size() - 1; i > 0; --i)
    {
        uniform_int_distribution<int> dis(0, i);
        int j = dis(gen);
        swap(deck[i], deck[j]);
    }
    cout << "洗牌完成。" << endl;
}

bool dealCards(vector<Card>& deck, vector<vector<Card>>& players, int playerCount, int cardsPerPlayer)
{
    if (playerCount <= 0 || cardsPerPlayer <= 0)
    {
        cout << "玩家人数和每人发牌数必须大于 0。" << endl;
        return false;
    }
    if ((int)deck.size() < playerCount * cardsPerPlayer)
    {
        cout << "剩余牌数不足，无法完成发牌。" << endl;
        return false;
    }
    players.clear();
    players.resize(playerCount);
    for (int round = 0; round < cardsPerPlayer; ++round)
    {
        for (int p = 0; p < playerCount; ++p)
        {
            players[p].push_back(deck.back());
            deck.pop_back();
        }
    }
    return true;
}

void showDealResult(const vector<vector<Card>>& players, const vector<Card>& deck)
{
    if (players.empty())
    {
        cout << "暂无发牌结果。" << endl;
        return;
    }
    for (size_t i = 0; i < players.size(); ++i)
    {
        cout << "玩家" << i + 1 << "：";
        for (const Card& card : players[i])
            cout << cardToString(card) << " ";
        cout << endl;
    }
    cout << "剩余牌数：" << deck.size() << endl;
}

void saveResultToFile(const vector<vector<Card>>& players, const vector<Card>& deck)
{
    if (players.empty())
    {
        cout << "暂无发牌结果，无法保存。" << endl;
        return;
    }
    ofstream ofs("deal_result.txt", ios::out);
    if (!ofs.is_open())
    {
        cout << "文件打开失败！" << endl;
        return;
    }
    for (size_t i = 0; i < players.size(); ++i)
    {
        ofs << "玩家" << i + 1 << "：";
        for (const Card& card : players[i])
            ofs << cardToString(card) << " ";
        ofs << endl;
    }
    ofs << "剩余牌数：" << deck.size() << endl;
    ofs.close();
    cout << "发牌结果已保存到 deal_result.txt。" << endl;
}

int main()
{
    vector<Card> deck;
    vector<vector<Card>> players;
    int select = 0;

    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1:
            initDeck(deck);
            players.clear();
            cout << "初始化完成，一副牌共 52 张。" << endl;
            break;
        case 2:
            showDeck(deck);
            break;
        case 3:
            shuffleDeck(deck);
            break;
        case 4:
        {
            int playerCount, cardsPerPlayer;
            cout << "请输入玩家人数：";
            cin >> playerCount;
            cout << "请输入每名玩家发牌张数：";
            cin >> cardsPerPlayer;
            if (dealCards(deck, players, playerCount, cardsPerPlayer))
            {
                cout << "发牌成功！" << endl;
                showDealResult(players, deck);
            }
            break;
        }
        case 5:
            saveResultToFile(players, deck);
            break;
        case 0:
            cout << "感谢使用扑克牌洗牌和发牌程序，再见！" << endl;
            return 0;
        default:
            cout << "输入有误，请重新输入。" << endl;
            break;
        }
        cout << endl;
    }
}
