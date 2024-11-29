#ifndef PAGE_DANG_KY_H
#define PAGE_DANG_KY_H

#include "Page.h"
#include <SFML/Graphics.hpp>
#include "Components.h"

// Lớp cơ sở cho màn hình lớp tín chỉ
class screenDangKy : public BaseScreen {
public:
    // Hàm hiển thị màn hình lớp tín chỉ
    static int showDK(sf::RenderWindow& window);
    //static void drawMainMenu3(sf::RenderWindow& window) ;
};
#endif 