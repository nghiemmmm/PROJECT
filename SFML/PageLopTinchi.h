#ifndef PAGE_LOP_TIN_CHI_H
#define PAGE_LOP_TIN_CHI_H

#include "Page.h"
#include <SFML/Graphics.hpp>
#include "Components.h"

// Lớp cơ sở cho màn hình lớp tín chỉ
class BaseScreenLopTinChi : public BaseScreen {
public:
    // Hàm hiển thị màn hình lớp tín chỉ
    static int BaseLTC(sf::RenderWindow& window);
    static void drawMainMenu3(sf::RenderWindow& window) ;
};

// Lớp cho màn hình nhập lớp
class ScreenLopTinChi : public BaseScreenLopTinChi {
public:
    // Hàm hiển thị màn hình nhập lớp
    static int addTC(sf::RenderWindow& window);
    static int showTC(sf::RenderWindow& window);
    static int InTC(sf::RenderWindow& window , LopTinChi& selectedTC );
    static int  fixTC(sf::RenderWindow& window, LopTinChi& selectedTC);
};

#endif // BASE_SCREEN_LOP_TIN_CHI_H
//std::stoi(numberCreditInput.getInput())