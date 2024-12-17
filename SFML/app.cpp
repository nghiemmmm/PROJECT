#include "Page.h"
#include "PageLopHoc.h" // Bao gồm tệp header của các trang lớp học
#include"PageMonHoc.h"
#include"PageLopTinchi.h"
#include"PageNhapDiem.h"
#include "Properties.h"
#include <SFML/Graphics.hpp>

class myApp {
public:
    int page = 0; // Trạng thái trang hiện tại
    bool isRunning = true;

    void run() {
        sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "QUAN LY DIEM SINH VIEN", sf::Style::Close | sf::Style::Resize);
        while (isRunning) {
            switch (page) {
                    case 0:
                    //page = ScreenDiem::showDK(window) ; 
                page = BaseScreen::startWindow(window); 
                
                //page = ScreenMonHoc::showSubject(window); // Gọi hàm tĩnh cho trang khởi động
                //page = ScreenLopHoc::showStudent(window) ; 
                 //page = ScreenMonHoc::addSubject(window) ; 
                break;
             case 1:
                
                //  page = ScreenLopHoc::showStudent(window) ; 
                page = ScreenLopHoc::choiseclass(window) ;
                 break;
            case 2:
                page = ScreenLopHoc::showClass(window) ; 
                break;
            case 3:
                page = ScreenMonHoc::showSubject(window) ;
                break;
            case 4:
                //page = ScreenLopHoc::showStudent(window); // Gọi hàm tĩnh cho trang in danh sách 1
                page = ScreenMonHoc::addSubject(window) ; 
                 break;
             case 5:
                // page = ScreenLopHoc::showStudent(window, ma); // Gọi hàm tĩnh cho trang in danh sách 2
                break;
            case 6:
                // page = ScreenLopHoc::addStudent(window ) ; 
                break ; 
            case 7: 
                // page = ScreenLopHoc::addClass(window) ; 
                // page = ScreenLopHoc::showClass(sf::RenderWindow& window)
                break  ; 
            case 8 :
                page = ScreenLopTinChi::showTC(window) ; 
                break ; 
            case 9 :
                break ; 
            case 10 :
                // page = ScreenDiem::showDK(window) ; 
                page = ScreenDiem::nhapdk(window) ;
                break ;
            case 11 :
                break ; 
            case 12 : 
                page = ScreenDiem::showDiem(window) ; 

                break ; 
            case 13 : 
                page = ScreenDiem::baseIn(window) ;  
                break ; 
            default:
                isRunning = false; // Nếu không có trang nào phù hợp, thoát ứng dụng
                cout << "Exit! \n";
                break;
            }
        }
    }
};
