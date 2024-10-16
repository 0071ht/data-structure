#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxHeap; // 最大堆，存放較小的一半
    priority_queue<int, vector<int>, greater<int>> minHeap; // 最小堆，存放較大的一半
    int number;

    while (cin >> number) {
        // 將新數字插入到最大堆
        maxHeap.push(number);

        // 將最大的數字從最大堆移到最小堆
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // 確保最大堆的大小總是大於或等於最小堆的大小
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // 輸出中間數
        if (maxHeap.size() > minHeap.size()) {
            cout << maxHeap.top() << endl;
        }
        else {
            cout << (maxHeap.top() + minHeap.top()) / 2 << endl;
        }
    }

    return 0;
}
