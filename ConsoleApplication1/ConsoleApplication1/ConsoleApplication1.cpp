#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 二分搜尋函式
template <typename T>
int binary_search(T arr[], int n, T target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;  // 若找不到目標就輸出-1
}

int main() {
    while (true) { 
        char type;  //i=int,s=string
        int n, q;  //n資料數量,q查詢數量

        // 輸入資料型態、資料數量與查詢數量
        cin >> type >> n >> q;

        if (type == 'i') {
            //如果是int的做法
            int data[30];  // 假設最大資料數量為 30
            for (int i = 0; i < n; ++i) {
                cin >> data[i];
            }

            while (q--) {
                int target;
                cin >> target;
                cout << binary_search(data, n, target) << endl;
            }
        }
        else if (type == 's') {
            //如果是string的作法
            string data[30];  // 假設最大資料數量為 30
            for (int i = 0; i < n; ++i) {
                cin >> data[i];
            }

            while (q--) {
                string target;
                cin >> target;
                cout << binary_search(data, n, target) << endl;
            }
        }
    }

    return 0;
}
