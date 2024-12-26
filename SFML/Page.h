#ifndef PAGE_H
#define PAGE_H

#include <SFML/Graphics.hpp>
#include "Components.h"
#include <iostream>
#include "globals.h"
#include <fstream> 
// #include <vector> 
#include"vector.h" 
#include<algorithm>
#include"BuiltClasses.h"
using namespace std;
class BaseScreen {
public:
    int type = 0;
	sf::Font font;
	sf::Texture texture;

    BaseScreen() {
		if (!font.loadFromFile("Font/arial.ttf")) {
			cout << "Could not load the font" << endl;
		}
	}

    static int startWindow(sf::RenderWindow& window);
	static void drawMainMenu(sf::RenderWindow& window) ; 
};

#endif 
