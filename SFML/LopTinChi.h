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
// ham lien quan den tinh chi 
     LopTinChi* newTC(LopTinChi& tc) {
        LopTinChi* p = new LopTinChi(tc);
        // *p = tc;
        return p;
    }

   void addTC(TinhchiList& dsTC, LopTinChi& tc) {
    if (dsTC.n >= MAX_LTC) {
        cout << "Danh sách lớp tín chỉ đã đầy.\n"; 
        return;  // Danh sách đầy, không thể thêm
    }

    // Cập nhật MALOPTC cho lớp tín chỉ
    tc.MALOPTC = (dsTC.n == 0) ? 1 : dsTC.Nodes[dsTC.n - 1]->MALOPTC + 1;

    // Thêm lớp tín chỉ vào danh sách
    dsTC.Nodes[dsTC.n] = newTC(tc);  // Thêm lớp tín chỉ vào vị trí n

    // Tăng số lượng lớp tín chỉ
    dsTC.n++;

    // In thông tin lớp đã thêm vào
    cout << "Đã thêm lớp tín chỉ thành công: MALOPTC = " << tc.MALOPTC
         << ", MAMH = " << tc.MAMH ; 
       
}
void removeTC(TinhchiList& dsTC , int index) {
    if (index < 0 || index >= dsTC.n) {
        cout << "Chỉ số không hợp lệ.\n";
        return;  // Kiểm tra chỉ số hợp lệ
    }

    // Xóa lớp tín chỉ tại chỉ số index
    delete dsTC.Nodes[index];

    // Di chuyển các phần tử sau vị trí index lên một vị trí trước đó
    for (int i = index; i < dsTC.n - 1; i++) {
        dsTC.Nodes[i] = dsTC.Nodes[i + 1];
    }

    // Gán nullptr cho phần tử cuối cùng
    dsTC.Nodes[n - 1] = nullptr;

    // Giảm số lượng lớp tín chỉ
    --dsTC.n;
    
    cout << "Lớp tín chỉ đã được xóa thành công.\n";
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
        // Kiểm tra các điều kiện lọc
        if (list.Nodes[i]->NienKhoa == nienKhoa && list.Nodes[i]->HocKy == hocKy && list.Nodes[i]->Nhom == nhom && list.Nodes[i]->MAMH == maMon) {
            return i; // Trả về chỉ số lớp tín chỉ nếu tìm thấy
        }
    }
    // Nếu không tìm thấy lớp tín chỉ thỏa mãn các điều kiện
    std::cout << "Không tìm thấy lớp tín chỉ với thông tin đã nhập.\n";
    return 0 ; // Trả về -1 nếu không tìm thấy lớp tín chỉ
}
int findTC(TinhchiList& dsTC , int ma) {  // Tìm lớp theo `MALOPTC`
        for (int i = 0; i < dsTC.n; i++) {
            if (dsTC.Nodes[i]->MALOPTC == ma) {
                return i;
            }
        }
        return -1;  // Không tìm thấy
    }
void updateTC(TinhchiList& dsTC , LopTinChi& newTC) {
    int index = findTC( dsTC, newTC.MALOPTC);  // Tìm lớp tín chỉ theo MALOPTC
    if (index != -1) {  // Kiểm tra nếu lớp tín chỉ được tìm thấy
        LopTinChi* tc = Nodes[index];
        // ko gan lại vi khong can thiet thay the con trô 
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

// ham dang ky 
void themdk(TinhchiList& dsTC , int& malop ,  DangKy &dangKy){
    int index = findTC(dsTC, malop);
    if (index == -1) {
        std::cout << "Lớp tín chỉ không tồn tại.\n";
        return;
    }

    // Lấy lớp tín chỉ từ danh sách TinhchiList
    LopTinChi* tc = dsTC.Nodes[index];  

    // Thêm đăng ký vào danh sách đăng ký của lớp tín chỉ
    tc->Dssvdk.addDK(dangKy);  // Sử dụng hàm addDK đã định nghĩa để thêm đăng ký

    std::cout << "Đã thêm đăng ký thành công cho lớp tín chỉ: MALOPTC = " << malop << "\n";
    }
// Hàm xóa đăng ký từ lớp tín chỉ trong TinhchiList
void removedk(TinhchiList& dsTC, int malop, string masv)
{
    // Tìm lớp tín chỉ có MALOPTC là malop
    int index = findTC(dsTC, malop);
    if (index == -1) {
        std::cout << "Lớp tín chỉ không tồn tại.\n";
        return;
    }

    // Lấy lớp tín chỉ từ danh sách TinhchiList
    LopTinChi* tc = dsTC.Nodes[index];

    // Xóa đăng ký từ danh sách đăng ký của lớp tín chỉ
    tc->Dssvdk.removeDK(masv);  // Gọi hàm xóa đăng ký đã định nghĩa để xóa đăng ký

    std::cout << "Đã xóa đăng ký thành công cho lớp tín chỉ: MALOPTC = " << malop << "\n";
}
};

#endif // LOPTINCHI_H
