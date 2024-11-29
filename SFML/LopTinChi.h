#ifndef LOPTINCHI_H
#define LOPTINCHI_H

#include "DangKy.h"
// #include "SinhVien.h"
// #include "MonHoc.h"

#include <string>
#include <fstream>

const int MAX_LTC = 10000;

class NodeDK;
typedef NodeDK* PTRDK;

class LopTinChi {
public:
    int MALOPTC;
    std::string MAMH;
    std::string NienKhoa;
    int HocKy;
    int Nhom;
    int soSvMin;
    int soSvMax;
    bool HuyLop;
    PTRDK Dssvdk ; 

    
    int getMALOPTC() const { return MALOPTC; }
    const std::string& getMAMH() const { return MAMH; }
    const std::string& getNienKhoa() const { return NienKhoa; }
    int getHocKy() const { return HocKy; }
    int getNhom() const { return Nhom; }
    int getSoSvMin() const { return soSvMin; }
    int getSoSvMax() const { return soSvMax; }
    bool isHuyLop() const { return HuyLop; }
    PTRDK getDssvdk() const { return Dssvdk; }

    void setHuyLop(bool huyLop) { HuyLop = huyLop; }
    void setDssvdk(PTRDK dssvdk) { Dssvdk = dssvdk; }
};

class LopTinChiManager {
public:
    int n = 0; // Số lượng lớp hiện có
    LopTinChi* Nodes[MAX_LTC]; // Mảng con trỏ tới các lớp tín chỉ
    
    LopTinChiManager() {} // Constructor

    static LopTinChiManager& getInstance() {
        static LopTinChiManager instance;
        return instance;
    }

    LopTinChi* createLopTinChi(int malop, const std::string& mamh, const std::string& nienKhoa, int hocKy, int nhom, int soSvMin, int soSvMax) {
        if (n >= MAX_LTC) return nullptr;
        // LopTinChi* lop = new LopTinChi(malop, mamh, nienKhoa, hocKy, nhom, soSvMin, soSvMax);
        // Nodes[n++] = lop;
        // return lop;
    }

    LopTinChi* timLopTinChi(int malop) {
        for (int i = 0; i < n; ++i) {
            if (Nodes[i]->getMALOPTC() == malop)
                return Nodes[i];
        }
        return nullptr;
    }

    void xoaLopTinChi(int malop) {
        for (int i = 0; i < n; ++i) {
            if (Nodes[i]->getMALOPTC() == malop) {
                delete Nodes[i];
                for (int j = i; j < n - 1; ++j) {
                    Nodes[j] = Nodes[j + 1];
                }
                Nodes[--n] = nullptr;
                break;
            }
        }
    }

    LopTinChi* begin() { return (n > 0) ? Nodes[0] : nullptr; }
    LopTinChi* end() { return (n > 0) ? Nodes[n] : nullptr; }

    bool isEmpty(LopTinChiManager& list) {
        return (list.n == 0);
    }

    bool isFull(LopTinChiManager& list) {
        return (list.n >= MAX_LTC);
    }

    // LopTinChi* newLopTC(const LopTinChi& loptc) {
    //     // LopTinChi* p = new LopTinChi(loptc.MALOPTC, loptc.MAMH, loptc.NienKhoa, loptc.HocKy, loptc.Nhom, loptc.soSvMin, loptc.soSvMax);
    //     // return p;
    // }

    void addlopTC(LopTinChiManager& list, const LopTinChi& loptc) {
        if (isFull(list))
            return;
        list.Nodes[list.n] = new LopTinChi(loptc);
        list.n++;
    }

    int findPlane(LopTinChiManager& list, const std::string& MALOPTC) {
        for (int i = 0; i < list.n; i++) {
            if (list.Nodes[i]->getMALOPTC() == stoi(MALOPTC))
                return i;
        }
        return -1;
    }

    void removeLopTC(LopTinChiManager& list, int index) {
        delete list.Nodes[index];
        for (int i = index; i < list.n - 1; i++) {
            list.Nodes[i] = list.Nodes[i + 1];
        }
        list.n--;
    }

    void deleteLopTC(LopTinChiManager& LopTinchi) {
        for (int i = 0; i < LopTinchi.n; i++) {
            delete LopTinchi.Nodes[i];
        }
        LopTinchi.n = 0;
    }

};

#endif // LOPTINCHI_H
