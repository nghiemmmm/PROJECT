#include "Page.h"
#include <SFML/Graphics.hpp>
#include"FileNFoder.h" 
#include"DataUtils.h"
#include"BuiltClasses.h"
namespace fsys = std::filesystem;

fsys::path classPath1 = "D:\\du an\\SFML\\SFML\\data\\Courses\\course.csv";
fsys::path subjectPath1 = "D:\\du an\\SFML\\SFML\\subjects.csv";
fsys::path creaditclass1 = "D:\\du an\\SFML\\SFML\\data\\Courses\\creaditclass.csv" ; 
fsys::path student2 = "D:\\du an\\SFML\\SFML\\data\\Classes\\23CTT1.csv";
fsys::path student3 = "D:\\du an\\SFML\\SFML\\data\\Classes\23CTT2.csv" ; 
fsys::path dk2 = "D:\\du an\\SFML\\SFML\\data\\Courses\\dangky.csv" ; 
// TinhchiList& list = TinhchiList::getInstance();
// DS_LOPSV& listclass =  DS_LOPSV::getInstance(); 
int BaseScreen::startWindow(sf::RenderWindow& window) {
      // do lu lieu vao lop san 
    if (DS_LOPSV::getInstance().isEmpty(DS_LOPSV::getInstance())) {
        cout << "lop  đang rỗng!" << endl;
        Data::getlop(classPath1 ,DS_LOPSV::getInstance()) ;
    } else {
        cout << "Cây không rỗng!" << endl;
    }
    // do du lieu vao cay san 
     if (AVLTreeMH::getInstance().isEmpty(AVLTreeMH::getInstance().root)) {
        cout << "Cây đang rỗng!" << endl;
        Data::getmonhoc(subjectPath1);
    } else {
        cout << "Cây không rỗng!" << endl;
    }
    // do du lieu vao lop tin chi 
    if (TinhchiList::getInstance().isEmpty()) {
        cout << "list  đang rỗng!" << endl;
        Data::gettc(creaditclass1) ; 
    } else {
        cout << "list  không rỗng!" << endl;
    }
//    // do sinh vien vao 2 lop dau 
    Data::getstudent(student2 ,DS_LOPSV::getInstance()) ;
//     Data::getstudent1(student3) ;
//     // do du lieu sinh vien dang ki vao 2 lop dau 
    Data::getdk(dk2 ,TinhchiList::getInstance() ) ; 
//     Data::getdk1(dk2) ;
// test lop voi sinh vien 
    // cout << endl ;
    // if( DS_LOPSV::getInstance().nodes[0].FIRST.getHead() == NULL){
    //     cout << "NO RONG " ; 
    // }else{
    //     DS_LOPSV::getInstance().nodes[0].FIRST.In() ; 
    // }
    // DanhSachSV sinhvien ; 
    // SinhVien sv1("SV001", "Nguyen", "An", "Nam", "0123456789");
    // sinhvien.insertSV(sv1) ;
    // DS_LOPSV::getInstance().nodes[0].FIRST.createNode(sv1) ;
    // if( DS_LOPSV::getInstance().nodes[0].FIRST.getHead() == NULL){
    //     cout << "NO RONG " ; 
    // }else{
    //     DS_LOPSV::getInstance().In34(DS_LOPSV::getInstance() , sinhvien ) ; 
    // }
    // cout << DS_LOPSV::getInstance().n ; 
    // // cout << endl ; 
    // SinhVien sv1("SV001", "Nguyen", "An", "Nam", "0123456789");
    // string a = "23CTT2001" ;
    //  DS_LOPSV::getInstance().In34(DS_LOPSV::getInstance() , DS_LOPSV::getInstance().nodes[0].MALOP) ; 
    //  DS_LOPSV::getInstance().SuaSinhVien(DS_LOPSV::getInstance(), DS_LOPSV::getInstance().nodes[0].MALOP , a , sv1 ) ; 
    //  cout << endl ;
    //   DS_LOPSV::getInstance().In34(DS_LOPSV::getInstance() , DS_LOPSV::getInstance().nodes[0].MALOP) ; 
    // DS_LOPSV::getInstance().HienThiDanhSachLop() ; 
// test lop tinh chi 
    // LopTinChi lopTinChi1(1, "MATH102", "2024", 1, 1, 10, 40, false);
    // TinhchiList::getInstance().printTinhchiList(TinhchiList::getInstance()) ; 
    // TinhchiList::getInstance().updateTC(TinhchiList::getInstance(),lopTinChi1) ;
    // TinhchiList::getInstance().printTinhchiList(TinhchiList::getInstance()) ;
    DangKy dangKy2("23CTT2001", 8.5f, true);
    TinhchiList::getInstance().Nodes[0]->Dssvdk.inDanhSach() ;
    TinhchiList::getInstance().removedk(TinhchiList::getInstance() , TinhchiList::getInstance().Nodes[0]->MALOPTC ,dangKy2.MASV) ;
    TinhchiList::getInstance().Nodes[0]->Dssvdk.inDanhSach() ; 

    cout << "den day " ; 
     // Khởi tạo font
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Handle error if font cannot be loaded
    }
    sf::Texture texture;
     if (!texture.loadFromFile("Asets/nen.jpg"))
        std::cout << "Could not load the Login image" << std::endl;

    sf::Sprite background(texture);

    sf::RectangleShape square(sf::Vector2f(1700, 180)); // Tạo ô vuông kích thước `size x size`
    square.setFillColor(sf::Color(220, 220, 220)); // RGB: (220, 220, 220)            // Đặt màu nền trắng
    square.setPosition(0.f, 0.f);  

    Text title(541.f, 31.f, 618.f ,118.f ,  "QUAN LY SINH VIEN", font, sf::Color::Red, 40);
    Text feature(1430.f, 180.f, 270.f , 55.f ,  "TINH NANG", font,sf::Color(255, 182, 193),30);
    Button lopHocBtn(1430.f, 243.f, 270.f, 94.f, "LOP HOC", font,sf::Color(119, 221, 119), 30);
    Button SVBtn(1430.f, 330.f, 270.f, 94.f, "SINH VIEN", font,sf::Color(119, 221, 119) , 30);
     Button monHocBtn(1430.f, 424.f,270.f, 94.f, "MON HOC", font,sf::Color(119, 221, 119) , 30);
    Button lopTinChiBtn(1430.f, 518.f,270.f, 94.f, "LOP TINH CHI", font, sf::Color(119, 221, 119) , 30);
    Button nhapDiemBtn(1430.f, 706.f, 270.f, 94.f, "NHAP DIEM", font,sf::Color(119, 221, 119), 30);
    Button nhapDK(1430.f, 612.f, 270.f, 94.f, "DANG KY ", font, sf::Color(119, 221, 119), 30);
    Button nhapBC(1430.f, 800.f, 270.f, 94.f, "BAO CAO", font, sf::Color(119, 221, 119), 30);


    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color(255, 182, 193), 15 ) ; 
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if ( SVBtn.isClicked(mousePos)) {
                     return 1;
                } else if (lopHocBtn.isClicked(mousePos)) {
                    return 2;  // Course management page
                } else if (monHocBtn.isClicked(mousePos)) {
                    return 3;  // Credit class management page
                } else if (lopTinChiBtn.isClicked(mousePos)) {
                    return 8;  // Input grades page
                }
                else if (nhapDiemBtn.isClicked(mousePos)) {
                    return 12;  // Input grades page
                }
                else if (nhapDK.isClicked(mousePos)) {
                    return 10;  // Input grades page
                }
                else if (nhapBC.isClicked(mousePos)) {
                    return 13;  // Input grades page
                }
                
            }
        }

        // Clear and redraw window
        window.clear(sf::Color::White);
        window.draw(background) ; 
        window.draw(square) ;
        title.draw(window);
        feature.draw(window);
        lopHocBtn.draw(window);
        monHocBtn.draw(window);
        lopTinChiBtn.draw(window);
        nhapDK.draw(window); 
        nhapBC.draw(window); 
        nhapDiemBtn.draw(window); 
        SVBtn.draw(window); 
        window.display();
        
    }

    return 0;  // Return value when completed
}
void BaseScreen::drawMainMenu(sf::RenderWindow& window) {
    // Khởi tạo font
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return; // Xử lý lỗi nếu không thể tải font
    }

    // Tạo các yếu tố giao diện
    Text title(541.f, 31.f, 618.f ,118.f ,  "QUAN LY SINH VIEN", font, sf::Color::Red, 40);
    Text feature(1430.f, 180.f, 270.f , 55.f ,  "TINH NANG", font,sf::Color(255, 182, 193),30);
    Button lopHocBtn(1430.f, 243.f, 270.f, 94.f, "LOP HOC", font,sf::Color(119, 221, 119), 30);
    Button SVBtn(1430.f, 330.f, 270.f, 94.f, "SINH VIEN", font,sf::Color(119, 221, 119) , 30);
     Button monHocBtn(1430.f, 424.f,270.f, 94.f, "MON HOC", font,sf::Color(119, 221, 119) , 30);
    Button lopTinChiBtn(1430.f, 518.f,270.f, 94.f, "LOP TINH CHI", font, sf::Color(119, 221, 119) , 30);
    Button nhapDiemBtn(1430.f, 706.f, 270.f, 94.f, "NHAP DIEM", font,sf::Color(119, 221, 119), 30);
    Button nhapDK(1430.f, 612.f, 270.f, 94.f, "DANG KY ", font, sf::Color(119, 221, 119), 30);
    Button nhapBC(1430.f, 800.f, 270.f, 94.f, "BAO CAO", font, sf::Color(119, 221, 119), 30);


    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color(255, 182, 193), 15 ) ; 
    // Vẽ các thành phần lên cửa sổ
    window.clear(sf::Color::White);
    title.draw(window);
    feature.draw(window);
    lopHocBtn.draw(window);
    monHocBtn.draw(window);
    lopTinChiBtn.draw(window);
    nhapDK.draw(window); 
    nhapBC.draw(window); 
    nhapDiemBtn.draw(window); 
    SVBtn.draw(window); 
    them.draw(window) ; 
    sua.draw(window) ; 
    xoa.draw(window) ; 
    ghi.draw(window) ; 
    thoat.draw(window) ; 
    
}

