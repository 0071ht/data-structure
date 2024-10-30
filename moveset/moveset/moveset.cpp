#include <iostream>
#include <iomanip> // 用於輸出格式
#include <limits>  // 用於數值限制
using namespace std;

int main() {
    int capacity = 4;  // 初始容量
    int size = 0;      // 當前元素數量
    int* array = new int[capacity];  // 動態分配陣列

    while (true) {
        cout << "請輸入一個數字（輸入非數字以結束）：";

        int input;
        if (!(cin >> input)) {
            break;  // 如果不是數字，則結束輸入
        }

        // 檢查是否需要擴容
        if (size >= capacity) {
            int new_capacity;
            if (capacity > 10000) {
                new_capacity = size + (size / 2); // 超過10000時減少擴增大小
            }
            else {
                new_capacity = size * 2; // 正常情況的擴增大小
            }

            // 分配新陣列並複製數據
            int* new_array = new int[new_capacity];
            for (int i = 0; i < size; i++) {
                new_array[i] = array[i];
            }
            delete[] array;  // 釋放舊的陣列
            array = new_array; // 更新指向新的陣列
            capacity = new_capacity; // 更新容量
        }

        // 將輸入的數字存入陣列
        array[size++] = input;

        // 輸出目前的陣列內容
        cout << "當前陣列內容：";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;

        // 輸出陣列容量
        cout << "陣列容量： " << capacity << endl;

        // 判斷記憶體分配情況
        if (capacity > 10000) {
            std::cout << "記憶體分配情況：低" << endl;
        }
        else {
            std::cout << "記憶體分配情況：高" << endl;
        }
    }
    // 清理記憶體
    delete[] array;
    return 0;
}
