#ifndef LOPTINCHI_H
#define LOPTINCHI_H

#include "DangKy.h"
#include <string>
#include <iostream>
#include"Properties.h"



// const int MAX_LTC = 10000;



class LopTinChi {
public:
    int  MALOPTC;
    std::string MAMH;
    std::string NienKhoa;
    int HocKy;
    int Nhom;
    int soSvMin;
    int soSvMax;
    bool HuyLop;
    listDK Dssvdk ;
    
    // Constructor mặc định
    LopTinChi() 
        : MALOPTC(0), MAMH(""), NienKhoa(""), HocKy(0), 
          Nhom(0), soSvMin(0), soSvMax(0), HuyLop(false) {}

    LopTinChi(int maloptc, const std::string& mamh, const std::string& nienkhoa, 
          int hocky, int nhom, int sosvmin, int sosvmax, bool huylop)
    : MALOPTC(maloptc), MAMH(mamh), NienKhoa(nienkhoa),
      HocKy(hocky), Nhom(nhom), soSvMin(sosvmin),
      soSvMax(sosvmax), HuyLop(huylop) {}

};

class TinhchiList {
public:
    int n = 0; // Số lượng lớp hiện có
    LopTinChi* Nodes[MAX_LTC]; // Mảng con trỏ tới các lớp tín chỉ
    
    TinhchiList() {} // Constructor

    static TinhchiList& getInstance() {
        static TinhchiList instance;
        return instance;
    }


     LopTinChi* newTC(LopTinChi& tc) {
        LopTinChi* p = new LopTinChi(tc);
        // *p = tc;
        return p;
    }

    void addTC(LopTinChi& tc) {
        if (n >= MAX_LTC) {
            return;  // Danh sách đầy, không thể thêm
        }
        Nodes[n] = newTC(tc);
        n++;
    }
    /*
    int MALOPTC = ( TinhchiList::getInstance().n == 0 ) ? TinhchiList::getInstance().Nodes[TinhchiList::getInstance().n - 1 ] -> MALOPTC + 1 
    */
   /*
   kiem tra trung voi nhom nam trc 
   sinh vien nam truoc cos the hoc chung 
   // Hàm kiểm tra trùng lịch
bool kiemTraTrungLich(const LopTinChi &ltc, const List_LTC &listLTC) {
    for (int i = 0; i < listLTC.n; i++) {
        LopTinChi* existingLTC = listLTC.nodes[i];
        if (existingLTC->MAMH == ltc.MAMH &&
            existingLTC->NienKhoa == ltc.NienKhoa &&
            existingLTC->Hocky == ltc.Hocky &&
            existingLTC->Nhom == ltc.Nhom) {
            return false; // Trùng lịch
        }
    }
    return true; // Không trùng lịch
}
   */
  

    int findTC(int ma) {  // Tìm lớp theo `MALOPTC`
        for (int i = 0; i < n; i++) {
            if (Nodes[i]->MALOPTC == ma) {
                return i;
            }
        }
        return -1;  // Không tìm thấy
    }

    void removeTC(int index) {
        if (index < 0 || index >= n) {
            return;  // Kiểm tra chỉ số hợp lệ
        }
        delete Nodes[index];
        for (int i = index; i < n - 1; i++) {
            Nodes[i] = Nodes[i + 1];
        }
        Nodes[--n] = nullptr;
    }

    void bubbleSortTC() {  // Sắp xếp các lớp theo `MALOPTC` tăng dần
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (Nodes[j]->MALOPTC > Nodes[j + 1]->MALOPTC) {
                    std::swap(Nodes[j], Nodes[j + 1]);
                }
            }
        }
    }

    void deleteAllTC() {
        for (int i = 0; i < n; i++) {
            delete Nodes[i];
            Nodes[i] = nullptr;
        }
        n = 0;
    }

    bool isEmpty() const {
        return n == 0;
    }
    void printTinhchiList(TinhchiList& list) {
    if (list.isEmpty()) {
        std::cout << "Danh sách lớp tín chỉ trống.\n";
        return;
    }

    for (int i = 0; i < list.n; ++i) {
        LopTinChi* tc = list.Nodes[i];
        std::cout << "MALOPTC: " << tc->MALOPTC << "\n"
                  << "MAMH: " << tc->MAMH << "\n"
                  << "NienKhoa: " << tc->NienKhoa << "\n"
                  << "HocKy: " << tc->HocKy << "\n"
                  << "Nhom: " << tc->Nhom << "\n"
                  << "MinSV: " << tc->soSvMin << "\n"
                  << "MaxSV: " << tc->soSvMax << "\n"
                  << "HuyLop: " << (tc->HuyLop ? "Yes" : "No") << "\n"
                  << "-----------------------\n";
    }
}
void printTinhchiList1(TinhchiList& list,  std::string& nienKhoa, int hocKy, int nhom, std::string& maMon) {
    if (list.isEmpty()) {
        std::cout << "Danh sách lớp tín chỉ trống.\n";
        return;
    }

    for (int i = 0; i < list.n; ++i) {
        LopTinChi* tc = list.Nodes[i];

        // Kiểm tra các điều kiện lọc
        if (tc->NienKhoa == nienKhoa && tc->HocKy == hocKy && tc->Nhom == nhom && tc->MAMH == maMon) {

            // In thông tin lớp tín chỉ
            std::cout << "MALOPTC: " << tc->MALOPTC << "\n"
                      << "MAMH: " << tc->MAMH << "\n"
                      << "NienKhoa: " << tc->NienKhoa << "\n"
                      << "HocKy: " << tc->HocKy << "\n"
                      << "Nhom: " << tc->Nhom << "\n"
                      << "MinSV: " << tc->soSvMin << "\n"
                      << "MaxSV: " << tc->soSvMax << "\n"
                      << "HuyLop: " << (tc->HuyLop ? "Yes" : "No") << "\n"
                      << "-----------------------\n";
        }else{
            cout << "khong tim thay " ; 
        }
    }
    }
int KTLOPTC(TinhchiList& list, std::string& nienKhoa, int hocKy, int nhom, std::string& maMon) {
    // Kiểm tra xem danh sách lớp tín chỉ có rỗng không
    if (list.isEmpty()) {
        std::cout << "Danh sách lớp tín chỉ trống.\n";
        return -1; // Trả về -1 nếu danh sách rỗng
    }

    // Duyệt qua danh sách lớp tín chỉ
    for (int i = 0; i < list.n; ++i) {
        LopTinChi* tc = list.Nodes[i];  // Lấy lớp tín chỉ tại vị trí i

        // Kiểm tra các điều kiện lọc
        if (tc->NienKhoa == nienKhoa && tc->HocKy == hocKy && tc->Nhom == nhom && tc->MAMH == maMon) {
            return i; // Trả về chỉ số lớp tín chỉ nếu tìm thấy
        }
    }

    // Nếu không tìm thấy lớp tín chỉ thỏa mãn các điều kiện
    std::cout << "Không tìm thấy lớp tín chỉ với thông tin đã nhập.\n";
    return 0 ; // Trả về -1 nếu không tìm thấy lớp tín chỉ
}


void updateTC(LopTinChi& newTC) {
    int index = findTC(newTC.MALOPTC);  // Tìm lớp tín chỉ theo MALOPTC
    if (index != -1) {  // Kiểm tra nếu lớp tín chỉ được tìm thấy
        LopTinChi* tc = Nodes[index];
        
        // Cập nhật thông tin của lớp tín chỉ từ đối tượng mới
        tc->MAMH = newTC.MAMH;
        tc->NienKhoa = newTC.NienKhoa;
        tc->HocKy = newTC.HocKy;
        tc->Nhom = newTC.Nhom;
        tc->soSvMin = newTC.soSvMin;
        tc->soSvMax = newTC.soSvMax;
        tc->HuyLop = newTC.HuyLop;

        std::cout << "Cập nhật lớp tín chỉ thành công.\n";
    } else {
        std::cout << "Lớp tín chỉ không tồn tại.\n";
    }
}
int findTCByNienKhoaHocKy(string nienKhoa, int hocKy) {
    for (int i = 0; i < n; i++) {
        if (Nodes[i]->NienKhoa == nienKhoa && Nodes[i]->HocKy == hocKy) {
            return i;  // Trả về chỉ số nếu tìm thấy
        }
    }
    return -1;  // Không tìm thấy
}
};

#endif // LOPTINCHI_H
