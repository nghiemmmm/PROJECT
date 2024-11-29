#ifndef SINHVIEN_H
#define SINHVIEN_H
#include<iostream>
#include<string>
using namespace std ; 
// Lớp SinhVien đại diện cho thông tin sinh viên
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
};

// Node chứa thông tin sinh viên và con trỏ tới sinh viên tiếp theo trong danh sách
class NodeSV {
public:
    SinhVien sv;      // Thông tin sinh viên
    NodeSV* next;     // Con trỏ tới sinh viên tiếp theo

    // Constructor
    NodeSV(const SinhVien& sinhvien) : sv(sinhvien), next(nullptr) {}
};
typedef NodeSV* PTRSV; 
// Iterator duyệt qua danh sách sinh viên
// class LinkedListSVIterator {
// private:
//     NodeSV* current;
// public:
//     LinkedListSVIterator(NodeSV* start) : current(start) {}

//     bool hasNext() const {
//         return current != nullptr;
//     }

//     NodeSV* next() {
//         if (hasNext()) {
//             NodeSV* node = current;
//             current = current->next;
//             return node;
//         }
//         return nullptr;
//     }
// };
// class LinkedListSVFactory {
// public:
//     static PTRSV createList() {
//         return new LinkedListSV();
//     }
// };

// Lớp LinkedListSV đại diện cho danh sách liên kết của sinh viên trong một lớp
class LinkedListSV {
public:
    PTRSV head;     // Con trỏ tới sinh viên đầu tiên trong danh sách

    // Constructor
    LinkedListSV() : head(nullptr) {}


   PTRSV TimSinhVien(const std::string& masv) ; 

    // Thêm sinh viên vào danh sách
   void ThemSinhVien( const SinhVien &sv) ;

    // chen cuoi sinh vien void InsertTail_SV(ListSV *&Head, SinhVien sv)

    // tim sinh vien ListSV* FindSV(ListLop &dsLOP, char c[]) 

    // Xóa sinh viên khỏi danh sách theo mã sinh viên 
    void xoaSinhVien(const std::string& masv) ;
       

    // ttim ma sinh vien 
    //ListSV* FindMaSV(ListSV *Head, char c[])
    
    // // Tạo iterator để duyệt danh sách sinh viên
    // LinkedListSVIterator getIterator() {
    //     return LinkedListSVIterator(head);
    // }
};
// Con trỏ tới NodeSV


#endif // SINHVIEN_H
