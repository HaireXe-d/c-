#include <iostream>
#include <windows.h> // 用于控制台颜色和延时
#include <string>

// 定义控制台文本颜色代码
namespace ConsoleColor {
    const int RED = 12;
    const int CYAN = 11;
    const int YELLOW = 14;
    const int GREEN = 10;
    const int BLUE = 9;
    const int MAGENTA = 13;
    const int WHITE = 15;
}

// 设置控制台文本颜色
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// 在控制台中央打印文本
void printCentered(const std::string& text) {
    // 假设控制台宽度为80字符，这是一个常见的默认值
    const int CONSOLE_WIDTH = 80;
    int padding = (CONSOLE_WIDTH - text.length()) / 2;
    if (padding < 0) padding = 0;

    std::cout << std::string(padding, ' ') << text << std::endl;
}

int main() {
    // 设置控制台窗口标题
    system("title 太原科技大学 - 字符印象");

    // 清屏（Windows命令）
    system("cls");

    std::cout << "\n\n";

    // 打印太原科技大学的字符画LOGO (TYUST - Taiyuan University of Science and Technology)
    setColor(ConsoleColor::CYAN);
    printCentered(R"(  _______ ______    ___  _______   )");
    printCentered(R"( |__   __|  _ \ \  / / |/ /_   _|  )");
    printCentered(R"(    | |  | |_) \ \/ /| ' /  | |    )");
    printCentered(R"(    | |  |  _ < \  / |  <   | |    )");
    printCentered(R"(    |_|  |_| \_\ \/  |_|\_\ |_|    )");

    std::cout << "\n";

    // 显示校训，并循环改变颜色
    int colors[] = { ConsoleColor::RED, ConsoleColor::YELLOW, ConsoleColor::GREEN,
                    ConsoleColor::CYAN, ConsoleColor::BLUE, ConsoleColor::MAGENTA };
    int colorCount = sizeof(colors) / sizeof(colors[0]);

    std::cout << "\n";

    // 循环显示不同颜色的校训
    for (int i = 0; i < 10; ++i) { // 循环10次后退出
        setColor(colors[i % colorCount]);
        printCentered("负重奋进、笃行求实");

        // 延时500毫秒
        Sleep(500);

        // 如果不是最后一次循环，则清除上一行校训
        if (i < 9) {
            std::cout << "\033[1A"; // 光标上移一行
            std::cout << "\033[2K"; // 清除当前行
        }
    }

    // 恢复默认颜色并显示结束信息
    setColor(ConsoleColor::WHITE);
    std::cout << "\n\n";
    printCentered("我太原科技大学！");
    
    std::cout << "\n\n";

    // 等待用户按键退出
    system("pause");

    return 0;
}