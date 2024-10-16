#include <iostream>

using namespace std;

int main() {
    int a;
    cin >> a;
    cin.ignore(); // 忽略输入后的换行符

    int all[26] = { 0 }; // 初始化字符计数数组

    for (int i = 0; i < a; i++) { // 循环应从0到a-1
        const int x = 256; // 設定最大行長
        char line[x];
        cin.getline(line, x); // 讀取一整行文字

        for (int k = 0; line[k] != '\0'; k++) { // 直至字符串結束
            if (line[k] >= 'A' && line[k] <= 'Z') // 使用字符常量
                all[line[k] - 'A']++;
            else if (line[k] >= 'a' && line[k] <= 'z')
                all[line[k] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) 
    {
        int max = 0;
        for (int i = 0; i < 26; i++)
        {
            if (all[i] >= max)
                max = all[i];
        }
        if (max == 0)
            break;
        for (int i = 0; i < 26; i++)
        {
            if (all[i] == max)
            {
                char ch = static_cast<char>(i + 65);
                cout << ch << " " << all[i] << endl;
                all[i] = 0;
            }
        }
    }
}
