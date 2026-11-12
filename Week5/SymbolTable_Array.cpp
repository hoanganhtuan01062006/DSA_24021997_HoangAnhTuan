#include <iostream>
#include <string>
using namespace std;

// Cấu trúc phần tử trong mảng
struct Element {
    int key;
    string value;
};

class STArray {
private:
    Element* arr;
    int capacity;
    int currentSize;

public:
    STArray(int cap = 100) { // Giới hạn kích thước mảng đơn giản
        capacity = cap;
        arr = new Element[capacity];
        currentSize = 0;
    }

    ~STArray() {
        delete[] arr; // Giải phóng bộ nhớ
    }

    // Thêm cặp Key-Value hoặc Cập nhật nếu Key đã tồn tại
    void put(int k, string v) {
        // 1. Duyệt mảng xem Key có chưa
        for (int i = 0; i < currentSize; i++) {
            if (arr[i].key == k) {
                arr[i].value = v; // Cập nhật Value
                return;
            }
        }
        
        // 2. Nếu chưa có, thêm vào CUỐI mảng
        if (currentSize < capacity) {
            arr[currentSize].key = k;
            arr[currentSize].value = v;
            currentSize++;
        } else {
            cout << "Mang da day!" << endl;
        }
    }

    // Tìm Value theo Key
    string get(int k) {
        for (int i = 0; i < currentSize; i++) {
            if (arr[i].key == k) {
                return arr[i].value;
            }
        }
        return "NULL";
    }
};

int main() {
    STArray st(50);
    st.put(10, "Muoi");
    st.put(20, "Hai muoi");
    st.put(20, "Hai muoi - Da cap nhat");

    cout << "Gia tri cua Key 20 (Array): " << st.get(20) << endl;
    cout << "Gia tri cua Key 30 (Array): " << st.get(30) << endl;
    return 0;
}