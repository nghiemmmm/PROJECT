#ifndef PAGE_NHAP_DIEM_H
#define PAGE_NHAP_DIEM_H

#include "Page.h"
#include <SFML/Graphics.hpp>
#include "Components.h"

class ScreenDiem : public BaseScreen {
public:
    static int showDK(sf::RenderWindow& window); 
    static int showDiem(sf::RenderWindow& window);
    static int showPage15(sf::RenderWindow& window);
    static int showPage16(sf::RenderWindow& window);
    static int showPage17(sf::RenderWindow& window);
};


#endif // BASE_SCREEN_NHAP_DIEM_H
