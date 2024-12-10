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
public :
    PTRSV head; // Con trỏ tới node đầu tiên
public :
    // Constructor
    DanhSachSV() : head(nullptr) {}

    // Destructor để giải phóng bộ nhớ
    ~DanhSachSV() {
        PTRSV curr = head;
        while (curr != nullptr) {
            PTRSV temp = curr;
            curr = curr->next;
            delete temp;
        }
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
    // in danh sach sinh vien 
    void In() {
    PTRSV p =  head ;
    while (p != NULL) {
        cout << p->sv.MASV << " " ;
        p = p->next;
    }
    cout << endl;
}
 // in danh sach sinh vien 
    void In2(string ma) {
    PTRSV p =  head ;
    while (p != NULL && p->sv.MASV == ma ) {
             cout << p->sv.MASV << " " ;
             cout << "da thay " ; 
        p = p->next;
    }
    cout << endl;
}

void SuaSinhVien( SinhVien& thongTinMoi) {
    PTRSV p = head;
    // Duyệt danh sách để tìm sinh viên có MASV tương ứng
    while (p != nullptr) {
        if (p->sv.MASV == thongTinMoi.MASV) {
            // Cập nhật thông tin sinh viên
            p->sv = thongTinMoi;
            std::cout << "Sinh vien " << thongTinMoi.MASV << " da duoc cap nhat!" << std::endl;
            return;
        }
        p = p->next;
    }

    // Nếu không tìm thấy sinh viên
    std::cout << "Khong tim thay sinh vien co ma " << thongTinMoi.MASV << "!" << std::endl;
}

    // Method to delete a node by value
    // xoa sinh vien trong danh sach 
    void deleteSV(SinhVien& sv ) {
        PTRSV curr = head;
        PTRSV prev = nullptr;

        // If head needs to be removed
        if (head && head->sv.MASV == sv.MASV) {
            PTRSV temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Search for the node to delete
        while (curr && curr->sv.MASV != sv.MASV) {
            prev = curr;
            curr = curr->next;
        }

        // If node is found
        if (curr) {
            prev->next = curr->next;
            delete curr;
        }
    }
    SinhVien findStudentByMASV(string masv) {
        PTRSV p = head;
        while (p != nullptr) {
            if (p->sv.MASV == masv) {
                return p->sv;  // Trả về sinh viên tìm thấy
            }
            p = p->next;
        }
        return SinhVien();  // Trả về đối tượng SinhVien mặc định nếu không tìm thấy
    }
    PTRSV findStudentByMASV1( string masv) {
    PTRSV p = head;
    while (p != nullptr) {
        if (p->sv.MASV == masv) {
            return p;  // Trả về con trỏ đến sinh viên tìm thấy
        }
        p = p->next;
    }
    return nullptr;  // Trả về nullptr nếu không tìm thấy
}
 PTRSV In3() {
    PTRSV p =  head ;
    while (p != NULL) {
       cout << p ->sv.HO ; 
        p = p->next;
    }
    cout << endl;
}

// Hàm kiểm tra danh sách có rỗng hay không
bool isEmpty(){
    return head == nullptr;
}
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
    // // Method to convert the linked list to string for easy display
    // string toString() {
    //     string s = "";
    //     for (Node *iter = head; iter; iter = iter->next) {
    //         s += to_string(iter->data) + " --> ";
    //     }
    //     return s;
    // }

    // // Overload the << operator to print the list easily
    // friend ostream &operator<<(ostream &output, Linklist &list) {
    //     output << list.toString();
    //     return output;
    // }
    PTRSV TimSinhVien(const std::string& masv) ; 

    // Thêm sinh viên vào danh sách
   void ThemSinhVien( const SinhVien &sv) ;

    // chen cuoi sinh vien void InsertTail_SV(ListSV *&Head, SinhVien sv)

    // tim sinh vien ListSV* FindSV(ListLop &dsLOP, char c[]) 

    // Xóa sinh viên khỏi danh sách theo mã sinh viên 
    void xoaSinhVien(const std::string& masv) ;
       
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
