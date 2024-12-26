#ifndef SINHVIEN_H
#define SINHVIEN_H
#include<iostream>
#include<string>
using namespace std ; 
// Cấu trúc SinhVien
class SinhVien {
public:
    std::string MASV; // Mã sinh viên
    std::string HO;   // Họ
    std::string TEN;  // Tên
    std::string PHAI; // Phái
    std::string SODT; // Số điện thoại

    // Constructor
    SinhVien(const std::string& masv = "", const std::string& ho = "", 
             const std::string& ten = "", const std::string& phai = "", 
             const std::string& sodt = "")
        : MASV(masv), HO(ho), TEN(ten), PHAI(phai), SODT(sodt) {}

    // Overload operator << để hiển thị thông tin sinh viên dễ dàng
    friend ostream &operator<<(ostream &output, const SinhVien &sv) {
        output << sv.MASV << " - " << sv.HO << " " << sv.TEN << " - " << sv.PHAI << " - " << sv.SODT;
        return output;
    }
};

// Node chứa thông tin sinh viên
class NodeSV {
public:
    SinhVien sv;  // Thông tin sinh viên
    NodeSV* next; // Con trỏ tới node tiếp theo

    // Constructor
    NodeSV(const SinhVien& sinhvien) : sv(sinhvien), next(nullptr) {}
};
typedef NodeSV* PTRSV;

// Lớp quản lý danh sách liên kết sinh viên
class DanhSachSV {
private :
    PTRSV head; // Con trỏ tới node đầu tiên
public :
    // Constructor
    DanhSachSV() : head(nullptr) {}

    ~DanhSachSV() {
    PTRSV curr = head;
    while (curr != nullptr) {
        PTRSV temp = curr;
        curr = curr->next;
        temp->next = nullptr;  // Đảm bảo không còn liên kết đến đối tượng sau khi xóa
        delete temp;
    }
    head = nullptr;  // Đảm bảo head không còn trỏ đến vùng nhớ đã giải phóng
}
    PTRSV getHead() {return head;}
    void setHead(PTRSV newhead) {head = newhead;}

    // Method to create the first node of the list
    // tao node sinh vien
    void createNode(SinhVien& sv) {
        head = new NodeSV(sv);
    }

    // Method to insert a node at the end
    // chen sinh vien vao 
    virtual void insertSV(SinhVien sv) {
        PTRSV newnode = new NodeSV(sv);
        if (!head) {
            head = newnode;
            return;
        }

        PTRSV tail = head;
        while (tail->next) {
            tail = tail->next;
        }

        tail->next = newnode;
    }
    // ham lien qan sinh vien 
    void In();
    int size(DanhSachSV& list) ;
    void In2(string ma);
    SinhVien findStudentByMASV(string masv) ;
    PTRSV findStudentByMASV1( string masv);
    PTRSV In3();
    bool KTSV(DanhSachSV& list, std::string& maSV); 
    // kiem tra ma sinnh vien them vao co trung hay khong
    bool KTTrung(DanhSachSV& list, std::string& maSV);  
// Hàm kiểm tra danh sách có rỗng hay không
    bool isEmpty();
    void selectionSortSV(SinhVien* dsSinhVien, int soluongsv) ; 

DanhSachSV& operator=(const DanhSachSV& other) {
    if (this != &other) { // Kiểm tra tránh tự gán
        // Xóa danh sách hiện tại
        PTRSV curr = head;
        while (curr != nullptr) {
            PTRSV temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;

        // Sao chép danh sách mới
        PTRSV otherCurr = other.head;
        while (otherCurr != nullptr) {
            insertSV(otherCurr->sv); // Thêm từng sinh viên
            otherCurr = otherCurr->next;
        }
    }
    return *this;
}      
};

// // Sorted class to insert nodes in sorted order
// class Sorted : public DanhSachSV {
// public:
//     // Constructor initializes the sorted linked list
//     Sorted() : DanhSachSV() {}

//     // Method to insert node in sorted order
//     void insertSV(SinhVien sv) override {
//         PTRSV newnode = new NodeSV(sv);

//         // If the list is empty or the value is smaller than the first element
//         if (!head || head->sv.MASV > sv.MASV) {
//             newnode->next = head;
//             head = newnode;
//             return;
//         }

//         // Traverse to find the correct position to insert the node
//         PTRSV curr = head;
//         while (curr->next && curr->next->sv.MASV < sv.MASV) {
//             curr = curr->next;
//         }

//         // Insert the new node in the sorted position
//         newnode->next = curr->next;
//         curr->next = newnode;
//     }
// };

#endif // SINHVIEN_H
