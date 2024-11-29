// BaseScreenLopHoc.cpp
#include "PageDangKy.h"
#include"FileNFoder.h" 
#include"DataUtils.h"

// int BaseScreenLopHoc::showBaseLop(sf::RenderWindow& window) {
//     sf::Font font;
//     if (!font.loadFromFile("Font/arial.ttf")) {
//         return -1; // Handle error if font cannot be loaded
//     }
//     // sf::Texture texture;
//     //  if (!texture.loadFromFile("nen.jpg"))
//     //     std::cout << "Could not load the Login image" << std::endl;

//     // // sf::Sprite background(texture);
    
//     Text title(667.f, 172.f, 342.f , 45.f ,  "DANG KI TIN CHI" , font , sf :: Color :: Red ,20) ;
//     Text masv(22.f, 242.f, 172.f , 40.f ,  "MA SINH VIEN " , font , sf :: Color :: Red ,15) ;
    
//     Text lop(881.f, 230.f, 149.f , 34.f ,  "NIEN KHOA " , font , sf :: Color :: Red ,15) ;
    
//     Text hocki(880.f, 284.f, 150.f , 34.f ,  "HOC KI " , font , sf :: Color :: Red ,15) ;
//     Text title1(109.f, 341.f, 222.f , 43.f ,  "THONG TIN SINH VIEN " , font , sf :: Color :: Red ,15) ;
//     Text masv1(4.f, 395.f, 146.f , 28.f ,  "MA SINH VIEN " , font , sf :: Color :: Red ,15) ;
//     Text ten(198.f, 395.f, 72.f , 29.f ,  "TEN" , font , sf :: Color :: Red ,15) ;
//      Text ho(120.f, 395.f, 72.f , 29.f ,  "HO" , font , sf :: Color :: Red ,15) ;
//       Text lop(349.f, 395.f, 144.f , 29.f  ,  " LOP  " , font , sf :: Color :: Red ,15) ;
//        Text masv2(4.f, 424.f, 146.f , 28.f ,  "MA SINH VIEN " , font , sf :: Color :: Red ,15) ;
//     Text ten1(198.f, 424.f, 72.f , 29.f ,  "TEN" , font , sf :: Color :: Red ,15) ;
//      Text ho1(120.f, 424.f, 72.f , 29.f ,  "HO" , font , sf :: Color :: Red ,15) ;
//       Text lop1(349.f, 424.f, 144.f , 29.f  ,  " LOP  " , font , sf :: Color :: Red ,15) ;
//       // thong tin dang ki 
//         Text title3(103.f, 574.f, 256.f , 38.f  ,  " THONG TIN DANG KI  " , font , sf :: Color :: Red ,15) ;
//         Text ma1(21.f, 638.f, 123.f , 34.f  ,  " MA SINH VIEN   " , font , sf :: Color :: Red ,15) ;
//         Text matc(21.f, 714.f, 144.f , 29.f  ,  " MA LOP TC   " , font , sf :: Color :: Red ,15) ;

//                 // thong tin tin chi 
//                 Text matc(500.f, 341.f, 290.f , 31.f  ,  " MA LOP TC   " , font , sf :: Color :: Red ,15) ;
//                 Text monhoc(791.f, 714.f, 310.f , 31.f  ,  " MA MON HOC    " , font , sf :: Color :: Red ,15) ;
//                 Text nhom(1101.f, 714.f, 239.f , 31.f  ,  "   NHOM " , font , sf :: Color :: Red ,15) ;
//                 Text sodk(1339.f, 714.f, 198.f , 31.f  ,  " SO SV DANG Ki    " , font , sf :: Color :: Red ,15) ;
//                 Text trong(1539.f, 714.f, 166.f , 31.f  ,  " TRONG " , font , sf :: Color :: Red ,15) ;

//                 // thong tin tin chi co the huy  
//                  Text title4(815.f , 546.f ,703.f , 28.f , " danh sách tinh chi co the huy "  , , font , sf :: Color :: Red ,15 ) ; 
//         Text matc1(537.f, 585.f, 241.f , 27.f  ,  " MA LOP TC   " , font , sf :: Color :: Red ,15) ;
//         Text Nienkhoa(770.f, 585.f, 241.f , 27.f  ,  " NIEN KHOA " , font , sf :: Color :: Red ,15) ;
//         Text hocki(1015.f, 585.f, 241.f , 27.f  ,  "  HOC KI  " , font , sf :: Color :: Red ,15) ;
//         Text monhoc(1256.f, 585.f, 241.f , 27.f  ,  " MON HOC    " , font , sf :: Color :: Red ,15) ;
//         Text nhom(1501.f, 585.f, 166.f , 31.f  ,  " NHOM  " , font , sf :: Color :: Red ,15) ;

    




//     Button tracuu(501.f, 244.f, 148.f , 40.f ,  "TRA CUU " , font , sf :: Color :: Red ,15) ;
//     Button  tim(1340.f, 237.f, 1176.f , 76.f ,  "TIM " , font , sf :: Color :: Red ,15) ;
//     Button Dk(319.f , 782.f ,155.f , 53.f , "DANG KI  " , font , sf :: Color :: Red , 15  ) ; 
//     Button huy dk (49.f , 782.f, 155.f, 53.f, "HUY DANG KI " , font , sf :: Color :: Red , 15  ) ; 
//     Button exit(1600.f , 225.f ,91.f , 71.f , "EXIT" , font , sf :: Color :: Red  , 15  )  ; 
//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             } else if (event.type == sf::Event::MouseButtonPressed) {
//                 // Kiểm tra người dùng có dùng chuột hay không
//                 sf::Vector2i mousePos = sf::Mouse::getPosition(window);  // Lấy vị trí con trỏ chuột trong cửa sổ
//                 if (.isClicked(mousePos)) {
//                     // nhap lop man stt 2 
//                     //window.close() ; 
//                     return 2 ; 
//                 } else if (.isClicked(mousePos)) {
//                     // nhap sinh vien man 3
//                     window.close() ; 
//                     //return 3 ;  
//                 if (.isClicked(mousePos)) {
//                     // in danh sach man 3 
//                     window.close() ; 
//                     return 4 ; 
//             }}
//         }
//         }
//          Vẽ lại màn hình
//         window.clear(sf::Color::White);
//         // Vẽ menu chính
//         BaseScreen::drawMainMenu(window); 
//         // Vẽ các yếu tố lớp học
//         lop.draw(window);
//         nhapBtn.draw(window);
//         nhapSVBtn.draw(window);
//         InBtn.draw(window);
//         backBtn.draw(window);
//         ContineBtn.draw(window);
//         window.display();  // Cập nhật màn hình
//     return 0;  // Return value when completed
// } 
// }
int ScreenDangKy::showDK(sf::RenderWindow& window) {
   sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }

        sf::RectangleShape square(sf::Vector2f(1700, 169)); // Tạo ô vuông kích thước `size x size`
        square.setFillColor(sf::Color(220, 220, 220)); // RGB: (220, 220, 220)            // Đặt màu nền trắng
        square.setPosition(0.f, 172.f);    
        sf::RectangleShape square1(sf::Vector2f(494, 308)); // Tạo ô vuông kích thước `size x size`
        square1.setFillColor(sf::Color(255, 182, 193)); // RGB: (255, 182, 193)
        square1.setPosition(0.f, 546.f);   
        sf::RectangleShape square2(sf::Vector2f(489, 176)); // Tạo ô vuông kích thước `size x size`
        square2.setFillColor(sf::Color(255, 182, 193)); // RGB: (255, 182, 193)
        square2.setPosition(0.f, 341.f);  
         sf::RectangleShape square3(sf::Vector2f(1206, 155)); // Tạo ô vuông kích thước `size x size`
        square3.setFillColor(sf::Color(255, 182, 193)); // RGB: (255, 182, 193)
        square3.setPosition(505.f, 341.f);    
          sf::RectangleShape square4(sf::Vector2f(1150, 308)); // Tạo ô vuông kích thước `size x size`
        square4.setFillColor(sf::Color(255, 182, 193)); // RGB: (255, 182, 193)
        square4.setPosition(532.f, 546.f);    


        InputField ma(221.f, 247.f , 243.f , 40.f , font  ) ; 
        InputField nienkhoa1(1058.f, 225.f , 31.f , 40.f , font  ) ; 
        InputField hocki3(1058.f, 277.f , 31.f , 40.f , font  ) ;
         InputField ma3(182.f, 636.f , 274.f , 34.f , font  ) ;
         InputField matc3(185.f, 714.f , 274.f , 34.f , font  ) ;
     Text title(667.f, 172.f, 342.f, 45.f, "DANG KI TIN CHI", font, sf::Color::Red, 20);
    Text masv(22.f, 242.f, 172.f, 40.f, "MA SINH VIEN", font, sf::Color::Red, 15);
    Text lop(881.f, 230.f, 149.f, 34.f, "NIEN KHOA", font, sf::Color::Red, 15);
    Text hocki(880.f, 284.f, 150.f, 34.f, "HOC KI", font, sf::Color::Red, 15);
    Text title1(109.f, 341.f, 222.f, 43.f, "THONG TIN SINH VIEN", font, sf::Color::Red, 15);


    Text masv1(4.f, 395.f, 113.f, 29.f, "MA ", font, sf::Color::Red, 15);
    Text ten(194.f, 395.f, 155.f, 29.f, "TEN", font, sf::Color::Red, 15);
    Text ho(118.f, 395.f, 72.f, 29.f, "HO", font, sf::Color::Red, 15);
    Text lop1(349.f, 395.f, 144.f, 29.f, "LOP", font, sf::Color::Red, 15);

    // Sửa tên lop1 thành lop2 để tránh trùng
    Text masv2(4.f, 423.f, 118.f, 29.f, "MA SINH VIEN", font, sf::Color::Red, 15);
    Text ten1(193.f, 423.f, 155.f, 29.f, "TEN", font, sf::Color::Red, 15);
    Text ho1(121.f, 423.f, 72.f, 29.f, "HO", font, sf::Color::Red, 15);
    Text lop2(349.f, 423.f, 144.f, 29.f, "LOP", font, sf::Color::Red, 15); // Đổi tên ở đây

    Text title3(103.f, 574.f, 256.f, 38.f, "THONG TIN DANG KI", font, sf::Color::Red, 15);
    Text ma1(21.f, 638.f, 123.f, 34.f, "MA SINH VIEN", font, sf::Color::Red, 15);
    Text matc(21.f, 714.f, 123.f, 34.f, "MA LOP TC", font, sf::Color::Red, 15);

    Text matc_tinchi(500.f, 341.f, 290.f, 31.f, "MA LOP TC", font, sf::Color::Red, 15);
    Text monhoc(791.f, 341.f, 310.f, 31.f, "MA MON HOC", font, sf::Color::Red, 15);
    Text nhom(1101.f, 341.f, 239.f, 31.f, "NHOM", font, sf::Color::Red, 15);
    Text sodk(1339.f, 341.f, 198.f, 31.f, "SO SV DANG KI", font, sf::Color::Red, 15);
    Text trong(1539.f, 341.f, 166.f, 31.f, "TRONG", font, sf::Color::Red, 15);

    Text title4(815.f, 546.f, 703.f, 28.f, "DANH SACH TIN CHI CO THE HUY", font, sf::Color::Red, 15);
    Text matc1(537.f, 585.f, 230.f, 27.f, "MA LOP TC", font, sf::Color::Red, 15);
    Text nienkhoa(770.f, 585.f, 241.f, 27.f, "NIEN KHOA", font, sf::Color::Red, 15);
    Text hocki1(1015.f, 585.f, 241.f, 27.f, "HOC KI", font, sf::Color::Red, 15); // Đổi tên ở đây
    Text monhoc_tinchi(1256.f, 585.f, 241.f, 27.f, "MON HOC", font, sf::Color::Red, 15);
    Text nhom_tinchi(1501.f, 585.f, 166.f, 27.f, "NHOM", font, sf::Color::Red, 15);

    // Button objects
    Button tracuu(501.f, 244.f, 148.f, 40.f, "TRA CUU", font, sf::Color::Red, 15);
    Button tim(1340.f, 237.f, 111.f, 76.f, "TIM", font, sf::Color::Red, 15);
    Button dk(319.f, 782.f, 155.f, 53.f, "DANG KI", font, sf::Color::Red, 15);
    Button huydk(49.f, 782.f, 155.f, 53.f, "HUY DANG KI", font, sf::Color::Red, 15);
    Button exit(1600.f, 225.f, 91.f, 71.f, "EXIT", font, sf::Color::Red, 15);
    ma.setSelected(true);
    while (window.isOpen()) {
    sf::Event event;
        if (ma.isSelected()) ma.textCursor(ma.getInput());
        if (nienkhoa1.isSelected()) nienkhoa1.textCursor(nienkhoa1.getInput());
        if (hocki3.isSelected()) hocki3.textCursor(hocki3.getInput());
        if (ma3.isSelected()) ma3.textCursor(ma3.getInput());
        if (matc3.isSelected()) matc3.textCursor(matc3.getInput());
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Lấy vị trí chuột
            if (tracuu.isClicked(mousePos)) {
                return 2; // Nhập lớp
            } else if (tim.isClicked(mousePos)) {
                return 3; // Nhập sinh viên
            } else if (dk.isClicked(mousePos)) {
                return 4; // In danh sách
            } else if (huydk.isClicked(mousePos)) {
                return 5; // Hủy đăng ký
            } else if (exit.isClicked(mousePos)) {
                window.close();
            }
        }
    }
      // Xử lý nhập liệu theo logic
        ma.processInput(event);
        if (ma.chooseNextField()) {
            nienkhoa1.setSelected(true);
            ma.setSelected(false);
        }

        nienkhoa1.processInput(event);
        if (nienkhoa1.chooseNextField()) {
            hocki3.setSelected(true);
            nienkhoa1.setSelected(false);
        }

        hocki3.processInput(event);
        if (hocki3.chooseNextField()) {
            ma3.setSelected(true);
            hocki3.setSelected(false);
        }

        ma3.processInput(event);
        if (ma3.chooseNextField()) {
            matc3.setSelected(true);
            ma3.setSelected(false);
        }

        matc3.processInput(event);
        if (matc3.chooseNextField()) {
            // Xử lý logic kết thúc (nếu cần)
        }


        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    // ma.setSelected(ma.isClicked(mousePos) && !ghi.isClicked(mousePos));
    // nienkhoa1.setSelected(nienkhoa1.isClicked(mousePos) && !ghi.isClicked(mousePos));
    // hocki1.setSelected(hocki1.isClicked(mousePos) && !ghi.isClicked(mousePos));
    // ma1.setSelected(ma1.isClicked(mousePos) && !ghi.isClicked(mousePos));
    // matc3.setSelected(matc3.isClicked(mousePos) && !ghi.isClicked(mousePos));

    // Vẽ lại màn hình
    window.clear(sf::Color::White);
    window.draw(square); 
    window.draw(square1);
     window.draw(square2);
      window.draw(square3);
       window.draw(square4);
    // Vẽ các đối tượng Text
    title.draw(window);
    masv.draw(window);
    lop.draw(window);
    hocki.draw(window);
    title1.draw(window);
    masv1.draw(window);
    ten.draw(window);
    ho.draw(window);
    lop2.draw(window);

    title3.draw(window);
    ma1.draw(window);
    matc.draw(window);
    lop1.draw(window) ; 

    matc_tinchi.draw(window);
    monhoc.draw(window);
    nhom.draw(window);
    sodk.draw(window);
    trong.draw(window);

    title4.draw(window);
    matc1.draw(window);
    nienkhoa.draw(window);
    hocki1.draw(window); // Dùng đúng tên biến đã đổi
    monhoc_tinchi.draw(window);
    nhom_tinchi.draw(window);

    // Vẽ các nút bấm (Buttons)
    tracuu.draw(window);
    tim.draw(window);
    dk.draw(window);
    huydk.draw(window);
    exit.draw(window);


    
    masv2.draw(window) ; 
    ten1.draw(window) ; 
    ho1.draw(window) ; 

        ma.draw(window) ; 
        nienkhoa1.draw(window) ; 
        ma3.draw(window) ; 
        matc3.draw(window) ; 
        hocki3.draw(window) ;

    // Hiển thị cửa sổ
    window.display();
    }
    return 0;
}
