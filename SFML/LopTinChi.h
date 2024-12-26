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
    LopTinChi* newTC(LopTinChi& tc) ;
    void addTC(TinhchiList& dsTC, LopTinChi& tc);
    void removeTC(TinhchiList& dsTC , int index);
    void bubbleSortTC();
    void deleteAllTC() ;
    bool isEmpty() const ;
    void printTinhchiList(TinhchiList& list) ;
    void printTinhchiList1(TinhchiList& list,  std::string& nienKhoa, int hocKy, int nhom, std::string& maMon) ;
    int KTLOPTC(TinhchiList& list, std::string& nienKhoa, int hocKy, int nhom, std::string& maMon) ;
    int KTLOPTC1(TinhchiList& list, std::string& nienKhoa, int hocKy) ;
    int findTC(TinhchiList& dsTC , int ma) ;
    void updateTC(TinhchiList& dsTC , LopTinChi& newTC) ;
    bool checkMH(TinhchiList& dsTC, std::string& maMon) ;
// ham lien quan den dang ky 
    void themdk(TinhchiList& dsTC , int& malop ,  DangKy &dangKy);
    void removedk(TinhchiList& dsTC, int malop, string masv);
    bool Ktsvdk(TinhchiList& dsTC, const std::string& masv) ; 
};
#endif // LOPTINCHI_H
