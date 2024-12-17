#ifndef DATAUTILS_H
#define DATAUTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp> // Include SFML header for Text
#include"BuiltClasses.h"
#include"Components.h"
#include <filesystem>
#include <utility>
namespace fsys = std::filesystem;
using namespace std;

class Data{
public:
// ham thao tac 
     template <typename T>
    static T min(T a, T b) {
        return (a < b) ? a : b;
    }
    template <typename T>
    static T max(T a, T b) {
        return (a > b) ? a : b;
    }
     static void swap(int& A, int& B) {
	int temp;
	temp = A;
	A = B;
	B = temp;
     }
     // hiển thị thông báo 
     static bool confirm(std::string content) ; 
     static void popup(std::string content) ; 
     static bool isNumber( std::string& str) ; 
     static string formatFloat(float value) ;
     static void SapXepSV(DanhSachSV& ListSV) ; 
     // xu ly nhan du lieu  
     static void getlop(fsys::path filepath , DS_LOPSV& listclass);
     static void getStudentData(sf::Font& font, const std::string& malop);
     static void  getmonhoc(fsys::path filepath) ;
     static void getstudent(fsys::path filepath , DS_LOPSV& listclass ) ; 
     static void getstudent1(fsys::path filepath) ;
     static void  gettc(fsys::path filepath) ;
     static void getdk(fsys::path filepath ,TinhchiList& dsTC ) ; 
     static void getdk1(fsys::path filepath) ;
     // ham hien thi man hinh chinh 
     static void displaylop( sf::Font& font , DS_LOPSV& listlop) ; 
     static void displaymonhoc(fsys::path filepath , sf::Font& font) ;
     static void displaystudent(int vitri, sf::Font& font);
     static void displaydiem(listDK& list) ;
     static void displaytc(fsys::path filepath ,  sf::Font& font) ;
     // hien thi cac ham goi 
     static void displaytc1(TinhchiList& list ,  sf::Font& font) ; 
     static void displaytc2(TinhchiList& list, sf::Font& font, string nienKhoa, int hocKy) ; 
     static void displaytchuy(TinhchiList& list, sf::Font& font, string nienKhoa, int hocKy) ;
     // ham them 
     static bool add(fsys::path filepath ,  sf::Font& font ,std::vector<std::string>& newRow ) ;
     // ham xoa  
     static void deletefile(fsys::path filepath, string &key) ;  
     // ham chinh sua 
     static void update(fsys::path filepath, const std::string& keyToUpdate, const std::vector<std::string>& newRow) ; 
     //void static fixTC(sf::RenderWindow& window, LopTinChi selectedtc) ;
     // bao cao 
     static void diemmhtc(fsys::path filepath ,  sf::Font& font , int vitri) ;
     static void diemtb(fsys::path filepath, sf::Font& font, int vitri) ; 
     static void diemtk(fsys::path filepath, sf::Font& font, int vitri) ;
    static float TinhDiemTrungBinh(const std::vector<int>& dssv, const std::string& masv) ; 
    static void tinhdiemtk(std::vector<std::vector<float>>& MaxDiem, const std::vector<int>& dssvLTC, const std::string& masv, const std::vector<std::string>& dsTenMH, int soluongsv,int soluongmh , int i) ;
};
#endif 