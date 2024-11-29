#ifndef LOP_H
#define LOP_H

#include "SinhVien.h" // Bao gồm header SinhVien.h
#include <string>
#include <iostream>
#include"Properties.h"

// const int MAXLOPSV = 10000;  // Số lượng lớp sinh viên tối đa


// Lớp LopSV đại diện cho một lớp với mã lớp, tên lớp, và danh sách sinh viên
class LopSV {
public:
    std::string MALOP;    // Mã lớp
    std::string TENLOP;   // Tên lớp
    //PTRSV FIRST; // Danh sách sinh viên trong lớp
    LinkedListSV* FIRST ; 

    // Constructor
    LopSV(const std::string& malop = "", const std::string& tenlop = "")
        : MALOP(malop), TENLOP(tenlop) {
        FIRST = new LinkedListSV(); // Khởi tạo đối tượng LinkedListSV
    }

    // Destructor để giải phóng bộ nhớ
    ~LopSV() {
        delete FIRST; // Giải phóng đối tượng LinkedListSV khi Lop bị hủy
    }

};

// Singleton Pattern: Lớp DS_LOPSV quản lý danh sách các lớp sinh viên
class DS_LOPSV {
public:
    int n;                         // Số lượng lớp hiện có
    LopSV nodes[MAXLOPSV];         // Mảng các lớp sinh viên

    // Constructor private để ngăn không cho tạo thể hiện bên ngoài
    DS_LOPSV() : n(0) {}

public:
    // Phương thức lấy thể hiện duy nhất của DS_LOPSV
    static DS_LOPSV& getInstance() {
        static DS_LOPSV instance;
        return instance;
    }

    void ThemLopSV(LopSV lop) ; 
       

    // Xóa lớp khỏi danh sách lớp
    void XoaLopSV(const std::string& malop) ; 
       

   int TimLop(const std::string& malop) ; 
   void HienThiDanhSachLop() ; 

   // kiem tra ma lop int KTMaLop(ListLop ds, char c[], int demkhongdoi)
};

#endif // LOP_H
// // DS_LOPSV& ds = DS_LOPSV::getInstance();
// LopSV lop1("L01", "Lớp 1");
// ds.ThemLopSV(lop1);
 

