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
// private :      
//      //LinkedListSV sinhvienList ; 
//      DS_LOPSV lopList ; 
//      //LopTinChiManager tinchiList ;
//      // DSDangKy dangkyList ; 
//      // AVLTreeMH monhocList ;
//      friend class ScreenLopHoc ; 
//      friend class ScreenMonHoc ;
//      friend class ScreenLopTinChi ; 
//      friend class ScreenLopHoc ; 


public:



// hiển thị thông báo 
static bool confirm(std::string content) ; 
static void popup(std::string content) ; 
static bool isNumber( std::string& str) ; 



// 
// xu ly lop 
     static void getlop(fsys::path filepath , DS_LOPSV& listclass);
     static void displaylop( sf::Font& font ) ; 
     static void getStudentData(sf::Font& font, const std::string& malop);
     static std::string getClassName(const std::string& malop);
     static bool addlophoc(fsys::path filepath, sf::Font& font, std::vector<std::string>& newRow);
     static LopSV displayclassInfo(int j) ;
     static void deletelophoc(fsys::path filepath, string& malop) ; 
     static void updatelophoc(fsys::path filepath, const std::string& malopUpdate, const std::vector<std::string>& newRow) ; 

     //mon hoc 
     static void  getmonhoc(fsys::path filepath) ;
     static void displaymonhoc(fsys::path filepath ,  sf::Font& font) ; 
     static bool addmonhoc(fsys::path filepath ,  sf::Font& font ,std::vector<std::string>& newRow ) ; 
     static void deletemonhoc(fsys::path filepath, string &mamh) ; 
     static void updateMonHoc(fsys::path filepath, const std::string& mamhToUpdate, const std::vector<std::string>& newRow) ; 
     static MonHoc displaySubjectInfo(int j) ;
     // studennt 
     static void getstudent(fsys::path filepath , DS_LOPSV& listclass ) ; 
     static void getstudent1(fsys::path filepath) ; 
     static bool addstudent(fsys::path filepath, sf::Font& font, std::vector<std::string>& newRow) ; 
     static void deletstudent(fsys::path filepath, string& masv);
     static SinhVien displayStudentInfo(int j ,  vector<Text> StudentList) ;
     static std::pair<std::vector<Text>, std::vector<Button>> displaystudent(DanhSachSV& sv, sf::Font& font);
     static void updatestudent(fsys::path filepath, const std::string& masvToUpdate, const std::vector<std::string>& newRow) ; 


     // lop tinh chi 
     static void  gettc(fsys::path filepath) ;
     static void displaytc(fsys::path filepath ,  sf::Font& font) ; 
     static void displaytc1(TinhchiList& list ,  sf::Font& font) ; 
     static bool add(fsys::path filepath ,  sf::Font& font ,std::vector<std::string>& newRow ) ; 
     static void deleteall(fsys::path filepath, string &key) ; 
     static void update(fsys::path filepath, const std::string& keyToUpdate, const std::vector<std::string>& newRow) ; 
     static LopTinChi displayTCInfo(int j) ;
     //void static fixTC(sf::RenderWindow& window, LopTinChi selectedtc) ;

     static void displaytc2(TinhchiList& list, sf::Font& font, string nienKhoa, int hocKy) ; 
     static void displaytchuy(TinhchiList& list, sf::Font& font, string nienKhoa, int hocKy) ;
     // dang ky 
     static void getdk(fsys::path filepath) ; 
     static void getdk1(fsys::path filepath) ;
     // nhap diem 
     static void displaydiem(listDK& list) ; 
     static string formatFloat(float value) ;



     
};

#endif 