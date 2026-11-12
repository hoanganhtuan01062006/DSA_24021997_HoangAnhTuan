#include <iostream>
#include <string>
using namespace std;

// Cấu trúc 1 Node chứa cặp Key-Value
struct Node {
    int key;
    string value;
    Node* next;
    
    // Constructor khởi tạo nhanh
    Node(int k, string v) { 
        key = k;
        value = v;
        next = nullptr;
    }
};

class STLinkedList {
private:
    Node* head;

public:
    STLinkedList() {
        head = nullptr;
    }

    // Thêm cặp Key-Value hoặc Cập nhật nếu Key đã tồn tại
    void put(int k, string v) {
        Node* current = head;
        // 1. Duyệt tìm xem Key đã có chưa
        while (current != nullptr) {
            if (current->key == k) {
                current->value = v; // Cập nhật Value
                return;
            }
            current = current->next;
        }
        
        // 2. Nếu Key chưa có, thêm Node mới vào ĐẦU danh sách
        Node* newNode = new Node(k, v);
        newNode->next = head;
        head = newNode;
    }

    // Tìm Value theo Key
    string get(int k) {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == k) {
                return current->value;
            }
            current = current->next;
        }
        return "NULL"; // Trả về "NULL" nếu không tìm thấy
    }
};

int main() {
    STLinkedList st;
    st.put(1, "Mot");
    st.put(2, "Hai");
    st.put(1, "Mot - Da cap nhat"); // Test ghi đè

    cout << "Gia tri cua Key 1 (Linked List): " << st.get(1) << endl;
    cout << "Gia tri cua Key 3 (Linked List): " << st.get(3) << endl;
    return 0;
}