#ifndef STACK_H
#define STACK_H

// Cấu trúc một Node (Mắt xích) trong Danh sách liên kết
struct Node {
    char data;      // Dữ liệu của Node (lưu trữ 1 ký tự toán tử/toán hạng, ví dụ: '+', 'A', '('...)
    Node* next;     // Con trỏ trỏ đến Node tiếp theo nằm bên dưới nó trong ngăn xếp
    
    // Constructor (Hàm khởi tạo) để tạo nhanh một Node mới với dữ liệu d
    Node(char d) : data(d), next(nullptr) {}
};

// Lớp Stack (Ngăn xếp) hoạt động theo nguyên tắc LIFO (Last In, First Out - Vào sau ra trước)
class LinkedListStack {
private:
    Node* head;     // Con trỏ head đóng vai trò là Đỉnh (Top) của Stack
    
public:
    // Constructor: Khởi tạo Stack rỗng (head ban đầu chưa trỏ vào đâu cả)
    LinkedListStack() : head(nullptr) {}
    
    // Hàm PUSH: Thêm một phần tử vào ĐỈNH của Stack
    void push(char x) {
        Node* newNode = new Node(x); // Tạo ra một Node mới chứa ký tự x
        newNode->next = head;        // Móc Node mới này lên trên đỉnh hiện tại của Stack
        head = newNode;              // Cập nhật đỉnh Stack (head) chính là Node mới vừa thêm
    }
    
    // Hàm POP: Lấy và Xóa phần tử đang nằm trên ĐỈNH của Stack
    void pop() {
        if (head) {                  // Phải kiểm tra Stack có phần tử thì mới xóa được
            Node* temp = head;       // Giữ tạm địa chỉ của Node trên đỉnh
            head = head->next;       // Dời đỉnh Stack (head) xuống Node liền kề bên dưới nó
            delete temp;             // Tiêu hủy Node đỉnh cũ để giải phóng bộ nhớ RAM
        }
    }
    
    // Hàm TOP: Chỉ lấy ra xem giá trị trên ĐỈNH Stack (không xóa nó đi)
    char top() {
        if (head) return head->data; // Nếu Stack có phần tử, trả về dữ liệu của đỉnh
        return '\0';                 // Nếu rỗng, trả về ký tự rỗng (null character)
    }
    
    // Hàm ISEMPTY: Kiểm tra Stack có đang rỗng hay không
    bool isEmpty() {
        return head == nullptr;      // Nếu đỉnh (head) là nullptr nghĩa là không có phần tử nào
    }
    
    // Destructor (Hàm hủy): Tự động chạy khi Stack không còn được sử dụng
    ~LinkedListStack() {
        while (!isEmpty()) pop();    // Tránh rò rỉ bộ nhớ (Memory Leak) bằng cách pop toàn bộ Node
    }
};

#endif
