#ifndef DANGKY_H
#define DANGKY_H

#include "SinhVien.h"
#include <iostream>
#include <string>

// Lớp DangKy đại diện cho thông tin đăng ký của sinh viên
class DangKy
{
public:
    std::string MASV; // Mã số sinh viên
    float Diem;       // Điểm của sinh viên
    bool Huy_Dang_Ky; // Trạng thái hủy đăng ký

    DangKy(const std::string &mssv = "", float diem = 0.0f, bool huy = false)
        : MASV(mssv), Diem(diem), Huy_Dang_Ky(huy) {}
};

// NodeDK: Một phần tử của danh sách liên kết đơn
class NodeDK
{
public:
    DangKy sv;    // Thông tin đăng ký của sinh viên
    NodeDK *next; // Con trỏ tới node đăng ký tiếp theo

    NodeDK(const DangKy &dangKy) : sv(dangKy), next(nullptr) {}
};

typedef NodeDK* PTRDK;

// DanhSachDangKy - Quản lý danh sách đăng ký sinh viên
class listDK
{
private :
    PTRDK head; // Con trỏ tới node đầu tiên của danh sách

public:
    // Constructor
    listDK() : head(nullptr) {}
     ~listDK()
    {
        while (head != nullptr)
        {
            PTRDK temp = head;
            head = head->next;
            delete temp;
        }
    }

    PTRDK getHead() {return head;}
    void setHead(PTRDK newhead) {head = newhead;}
    // Thêm đăng ký vào danh sách
    void addDK(DangKy &dangKy);
    bool isEmpty(listDK& list);
    int size(listDK& list);
    // Cập nhật thông tin đăng ký
    void adjustDK(string masv, DangKy &dk) ;
    // Tìm sinh viên theo MASV
    PTRDK findMASV( std::string masv) ;
    // Xóa đăng ký theo mã sinh viên
    void removeDK( std::string mssv); 
    // In danh sách đăng ký sinh viên
    void inDanhSach() ;
     // Lấy danh sách sinh viên chưa hủy đăng ký
    void inDanhSachChuaHuy() const ;
    // Cập nhật trạng thái hủy đăng ký
    void huyDangKy(const std::string &masv);
    PTRDK getAt(int i) ;
    PTRDK findStudentByMASV(std::string& masv);
    bool kiemTraDK(const std::string &masv) ; 
};

#endif // DANGKY_H
