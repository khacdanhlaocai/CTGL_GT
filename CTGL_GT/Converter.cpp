#include "Converter.h"
#include "Stack.h"
#include <cctype>

// Hàm xác định độ ưu tiên của các toán tử (Precedence)
// Số trả về càng lớn thì độ ưu tiên càng cao
int precedence(char op) {
    if (op == '^') return 5;                  // Dấu mũ ưu tiên cao nhất
    if (op == '*' || op == '/') return 4;     // Nhân, chia ưu tiên thứ hai
    if (op == '+' || op == '-') return 3;     // Cộng, trừ ưu tiên thấp hơn
    if (op == '(') return 2;                  // Dấu mở ngoặc có mức ưu tiên rất thấp (để các toán tử khác có thể nằm đè lên nó trong ngăn xếp)
    return 0;
}

// Hàm chính: Chuyển đổi biểu thức Trung tố (Infix) sang Hậu tố (Postfix)
string infixToPostfix(string infix) {
    LinkedListStack st;                       // Gọi ngăn xếp bằng Danh sách liên kết mà chúng ta vừa tạo
    string postfix = "";                      // Chuỗi lưu kết quả đầu ra
    
    // Duyệt qua từng ký tự của biểu thức đầu vào từ trái sang phải
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        // TRƯỜNG HỢP 1: Nếu là Toán hạng (chữ cái hoặc số)
        if (isalnum(c)) {
            postfix += c;                     // Nối trực tiếp vào kết quả (toán hạng không bao giờ chui vào Stack)
        } 
        // TRƯỜNG HỢP 2: Nếu là dấu Mở ngoặc '('
        else if (c == '(') {
            st.push('(');                     // Đẩy thẳng vào Stack làm "vách ngăn"
        } 
        // TRƯỜNG HỢP 3: Nếu là dấu Đóng ngoặc ')'
        else if (c == ')') {
            // Lấy toàn bộ các toán tử trong Stack ra kết quả cho đến khi đụng "vách ngăn" là dấu '('
            while (!st.isEmpty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            // Vứt bỏ luôn dấu mở ngoặc '(' đi (không đưa vào chuỗi kết quả)
            if (!st.isEmpty() && st.top() == '(') {
                st.pop(); 
            }
        } 
        // TRƯỜNG HỢP 4: Nếu là các Toán tử (+, -, *, /, ^)
        else {
            // So sánh độ ưu tiên: Đẩy các toán tử trên đỉnh Stack ra kết quả nếu chúng có độ ưu tiên LỚN HƠN hoặc BẰNG toán tử đang xét
            while (!st.isEmpty() && precedence(c) <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            // Sau khi dọn đường xong, nhét toán tử đang xét vào Stack
            st.push(c);
        }
    }
    
    // BƯỚC CUỐI CÙNG: Biểu thức đã duyệt xong, lấy toàn bộ toán tử còn đọng trong Stack ra
    while (!st.isEmpty()) {
        // Có thêm lệnh If này để phòng hờ biểu thức lỗi thiếu đóng ngoặc (vẫn còn sót '(' trong Stack)
        if (st.top() != '(') postfix += st.top();
        st.pop();
    }
    
    return postfix;                           // Trả về biểu thức Hậu tố hoàn thiện
}
