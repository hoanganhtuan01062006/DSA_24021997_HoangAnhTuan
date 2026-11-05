#include <iostream>

using namespace std;

#define MAX_SIZE 100

// Định nghĩa cấu trúc Priority Queue
struct PriorityQueue {
    int pq[MAX_SIZE];
    int N; // Số lượng phần tử hiện tại
};

// Hàm khởi tạo
void initQueue(PriorityQueue& q) {
    q.N = 0;
}

// Kiểm tra rỗng
bool isEmpty(const PriorityQueue& q) {
    return q.N == 0;
}

// Vươn lên (Thăng tiến)
void swim(PriorityQueue& q, int k) {
    while (k > 0 && q.pq[(k - 1) / 2] < q.pq[k]) {
        swap(q.pq[k], q.pq[(k - 1) / 2]);
        k = (k - 1) / 2;
    }
}

// Chìm xuống (Giáng chức)
void sink(PriorityQueue& q, int k) {
    while (2 * k + 1 < q.N) {
        int j = 2 * k + 1;
        
        // Có con phải và con phải lớn hơn con trái
        if (j < q.N - 1 && q.pq[j] < q.pq[j + 1]) {
            j++; 
        }
        
        // Trật tự đã đúng
        if (q.pq[k] >= q.pq[j]) {
            break;
        }
        
        swap(q.pq[k], q.pq[j]);
        k = j;
    }
}

// Tuyển dụng nhân sự mới (Thêm phần tử)
void insert(PriorityQueue& q, int v) {
    if (q.N >= MAX_SIZE) {
        cout << "Loi: Hang doi da day!" << endl;
        return;
    }
    q.pq[q.N] = v; // Nhét vào cuối
    swim(q, q.N);  // Vươn lên
    q.N++;         // Cập nhật số lượng
}

// Đưa nhân sự xuất sắc nhất ra khỏi hệ thống (Lấy phần tử lớn nhất)
int delMax(PriorityQueue& q) {
    if (isEmpty(q)) {
        cout << "Loi: Hang doi rong!" << endl;
        return -1; // Trả về mã lỗi giả định
    }
    
    int max_val = q.pq[0]; 
    
    swap(q.pq[0], q.pq[q.N - 1]);
    q.N--; 
    
    if (q.N > 0) {
        sink(q, 0); 
    }
    
    return max_val;
}

#ifndef PRIORITYQUEUE_NO_MAIN
int main() {
    PriorityQueue q;
    initQueue(q);

    insert(q, 15);
    insert(q, 45);
    insert(q, 25);
    insert(q, 35);
    insert(q, 5);

    cout << "Cac phan tu lay ra: ";
    while (!isEmpty(q)) {
        cout << delMax(q) << " ";
    }

    return 0;
}
#endif
