#ifndef PAGE_LOP_HOC_H
#define PAGE_LOP_HOC_H

#include <SFML/Graphics.hpp>
#include "Page.h"
#include "FileNFoder.h"
#include"globals.h"
#include"DataUtils.h"

// Lớp cơ sở cho màn hình lớp học
class BaseScreenLopHoc : public BaseScreen { 
public:

     static int showBaseLop(sf::RenderWindow& window);
     static void drawMainMenu1(sf::RenderWindow& window) ; 
};

class ScreenLopHoc : public BaseScreenLopHoc {
// private : 
//     Data* d = NULL ; 
public:
    // ScreenLopHoc(Data* d) {
	// 	this->d = d;
	// }



    static int showClass(sf::RenderWindow& window);
    static int addClass(sf::RenderWindow& window);
    static int InClass(sf::RenderWindow& window , LopSV& selectedlop) ; 
    static int fixClass(sf :: RenderWindow& window, LopSV& selectedlop) ; 


    static int addStudent(sf::RenderWindow& window);
    static int showStudent(sf::RenderWindow& window );
    static int InStudent(sf::RenderWindow& window , SinhVien& a) ; 
    static int fixStudent(sf :: RenderWindow& window,  SinhVien& a) ; 
};

// class ScreenLopHoc_NhapSV : public BaseScreenLopHoc {
// public:
    
// };

// class ScreenLopHoc_InDS1 : public BaseScreenLopHoc {
// public:
//     static int showPage4(sf::RenderWindow& window);
// };

// class ScreenLopHoc_InDS2 : public BaseScreenLopHoc {
// public:
//     static int showPage5(sf::RenderWindow& window);
// };

#endif // BASE_SCREEN_LOP_HOC_H