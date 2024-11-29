#ifndef PAGE_MON_HOC_H
#define PAGE_MON_HOC_H

#include "Page.h"
#include <SFML/Graphics.hpp>
#include "Components.h"

// Lớp cơ sở cho môn học
class BaseScreenMonHoc : public BaseScreen {
public:
    static int showBaseMonHoc(sf::RenderWindow& window);
    static void drawMainMenu2(sf::RenderWindow& window) ; 
};

// Lớp cho màn hình nhập môn học
class ScreenMonHoc : public BaseScreenMonHoc {
public:
    static int showSubject(sf::RenderWindow& window);
    static int addSubject(sf::RenderWindow& window) ; 
    static int InSubject(sf :: RenderWindow& window , MonHoc& selectedMH ) ; 
    static int  fixSubject(sf :: RenderWindow& window, MonHoc& selectedMH) ; 
};  

#endif // PAGE_MON_HOC_H
