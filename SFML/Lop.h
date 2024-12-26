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
    DanhSachSV FIRST ; 

    // Constructor
    LopSV(const std::string& malop = "", const std::string& tenlop = "")
        : MALOP(malop), TENLOP(tenlop), FIRST() {  // Khởi tạo DanhSachSV
    }

    // Destructor (Nếu cần thiết, có thể không cần nếu DanhSachSV tự quản lý bộ nhớ)
    ~LopSV() {
        // Không cần phải giải phóng FIRST nếu DanhSachSV tự quản lý bộ nhớ
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
// các ham lien quan den lop  
   // hien thi danh sach lop ;
    void HienThiDanhSachLop() ; 
    // tim chi so lop qua ma sinh vien
    int TimChiSoLopQuaMaSV(DS_LOPSV& dsLop,string maSV) ; 
    // kiem tra ma lop 
    int KTMaLop(DS_LOPSV& ds, string malop, int demkhongdoi) ;
    // kiem tra ma lop va ten lop 
    bool KTMaLopVaTenLop(DS_LOPSV& dsLop,  std::string& malop,  std::string& tenlop) ;
    // kiem tra lop co sinh vien hay khong  
    bool KiemTraLopCoSinhVien(DS_LOPSV& dsLop,  std::string& maLop) ; 
    // sua lop
    void SuaLop(string malop, LopSV& lopMoi) ; 
    // xóa lớp 
    void XoaLop(DS_LOPSV& dsLop ,  std::string& malop) ;
    // kiem tra lop co rong hay khong
    bool isEmpty(DS_LOPSV& dsLop) ;
    // tim vi tri chen lop
    int TimViTriChenLop(DS_LOPSV& dsLop,string malop) ;
    // ham them lop 
    void ThemLop(DS_LOPSV& dsLop , LopSV lop) ; 
// ham lien quan den sinh vien 
    // them sinh vien
    void themSV(DS_LOPSV& dsLop , string& malop , SinhVien& sv) ;
    // xoa sinh vien    
    void deleteSV(DS_LOPSV& dsLop, string& malop, string& masv) ;
    // sua sinh vien
    void SuaSinhVien(DS_LOPSV& dsLop,  string& malop,  string& masv,  SinhVien& thongTinMoi) ;
    // in danh sach sinh vien
    void In34(DS_LOPSV& dsLop, const std::string& malop) ; 
    // tim vi tri chen sinh vien    
    PTRSV FindSV( DS_LOPSV& dsLOP,string masv) ; 
    bool KiemTraSinhVienTonTai(DS_LOPSV& dsLop,  std::string& maLop,  std::string& maSV) ;
};

#endif // LOP_H


