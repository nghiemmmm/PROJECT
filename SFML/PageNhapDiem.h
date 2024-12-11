#ifndef PAGE_NHAP_DIEM_H
#define PAGE_NHAP_DIEM_H

#include "Page.h"
#include <SFML/Graphics.hpp>
#include "Components.h"

class ScreenDiem : public BaseScreen {
public:
    static int showDK(sf::RenderWindow& window , string& masv); 
    static int nhapdk(sf::RenderWindow& window);
    static int showDiem(sf::RenderWindow& window);
    static int Indiem(sf::RenderWindow& window  , int& vitri );
    static int baseIn(sf::RenderWindow& window);
    static int baseIn1(sf::RenderWindow& window);
    static int diemMH(sf::RenderWindow& window , int vitri );
    static int diemTB(sf::RenderWindow& window);
    static int diemTK(sf::RenderWindow& window);
    
    
};


#endif // BASE_SCREEN_NHAP_DIEM_H
