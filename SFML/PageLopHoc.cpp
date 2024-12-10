
// BaseScreenLopHoc.cpp
#include "PageLopHoc.h"
#include"FileNFoder.h" 
#include"DataUtils.h"

fsys::path classPath = "D:\\du an\\SFML\\SFML\\data\\Courses\\course.csv";
fsys::path student1 = "D:\\du an\\SFML\\SFML\\data\\Classes\\23CTT1.csv";
fsys::path classDir = "D:\\du an\\SFML\\SFML\\data\\Classes";

// DS_LOPSV& listclass3 =  DS_LOPSV::getInstance() ;
int BaseScreenLopHoc::showBaseLop(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Handle error if font cannot be loaded
    }
    // sf::Texture texture;
    //  if (!texture.loadFromFile("nen.jpg"))
    //     std::cout << "Could not load the Login image" << std::endl;

    // // sf::Sprite background(texture);
    
    Text lop(0.f, 181.f, 206.f , 35.f ,  "Lop" , font , sf :: Color :: Red ,25) ;
   
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                // Kiểm tra người dùng có dùng chuột hay không
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);  // Lấy vị trí con trỏ chuột trong cửa sổ
            }
            }
    }
         // Vẽ lại màn hình
        window.clear(sf::Color::White);
        // Vẽ menu chính
        BaseScreen::drawMainMenu(window); 
        // Vẽ các yếu tố lớp học
        lop.draw(window);
        window.display();  // Cập nhật màn hình
    return 0;  // Return value when completed
} 
void BaseScreenLopHoc::drawMainMenu1(sf::RenderWindow& window) {
    // Khởi tạo font
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return; // Xử lý lỗi nếu không thể tải font
    }

    // Tạo các yếu tố giao diện
    Text lop(0.f, 181.f, 206.f , 35.f ,"Lop", font , sf :: Color :: Red ,25) ;

    // Vẽ các thành phần lên cửa sổ
    window.clear(sf::Color::White);
        BaseScreen::drawMainMenu(window);
        lop.draw(window);

}
int ScreenLopHoc::showClass(sf::RenderWindow& window) {
     DS_LOPSV::getInstance().nodes[0].FIRST.In() ; 
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về -1 nếu không tải được font
    }
     // Xóa dữ liệu cũ trong các vector trước khi thêm dữ liệu mới
    classList.clear();
    Buttonclass.clear();
    // Khởi tạo các nút điều hướng
    Button nextPageBtn(901.f, 833.f, 92.f, 62.f, "Next", font, sf::Color::Red, 15);
    Button prevPageBtn(606.f, 833.f, 92.f, 62.f, "Prev", font, sf::Color::Red, 15);
    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color(255, 182, 193), 15 ) ; 
    // Khởi tạo các nhãn
    Text ma(217.f , 281.f , 539.f , 46.f , "MA LOP " , font , sf :: Color :: Red , 15) ; 
    Text lop(756.f , 281.f , 539.f , 46.f , "TEN LOP " , font , sf :: Color :: Red , 15) ; 
    // Tạo đối tượng sf::Text để hiển thị số trang
    sf::Text pageText;
    pageText.setFont(font);
    pageText.setCharacterSize(20);
    pageText.setFillColor(sf::Color::Black);
    pageText.setPosition(750.f, 833.f);
    cout << 1 ; 
    Data::displaylop(font) ;
    int displayFrom = 0;
    int itemsPerPage = 10;
    while (window.isOpen()) {
        sf::Event event;
        int displayLimit = std::min(displayFrom + itemsPerPage, static_cast<int>(classList.size()));
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + itemsPerPage < static_cast<int>(classList.size())) {
                        displayFrom += itemsPerPage; // Chuyển sang trang tiếp theo
                    }
                }
                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - itemsPerPage >= 0) {
                        displayFrom -= itemsPerPage; // Quay lại trang trước
                    }
                }
                if (them.isClicked(mousePos)) {
                    addClass(window) ; 
                }
                if(thoat.isClicked(mousePos)){
                    return 0 ; 
                }
                // Kiểm tra nếu một trong các nút môn học trong buttonsubject được nhấn
                for (int i = displayFrom; i < displayLimit && i < Buttonclass.size(); i++) {
                        if (Buttonclass[i].isClicked(mousePos)) {
                            cout << 12 ; 
                            string ma = Buttonclass[i].getText() ; 
                            int vitri ; 
                            int temp = DS_LOPSV::getInstance().KTMaLop(DS_LOPSV::getInstance(),ma,DS_LOPSV::getInstance().n);
                                if(temp != 0){
                                    if(temp == -1)
                                 {
                                    vitri = 0;	
                                }else{
                                     vitri = temp;
                                }
                                } 
                            LopSV selectedLop = DS_LOPSV::getInstance().nodes[vitri] ; 
                            InClass(window,selectedLop); 
                             return 2 ; 
                        }
                        }
            }
        }
        //Tính số trang hiện tại và tổng số trang
        int currentPage = (displayFrom / itemsPerPage) + 1;
        int totalPages = (classList.size() + itemsPerPage - 1) / itemsPerPage;
        // Cập nhật nội dung văn bản hiển thị số trang
        pageText.setString("Page " + std::to_string(currentPage) + " / " + std::to_string(totalPages));
        window.clear(sf::Color::White);
        // Vẽ menu chính  
        BaseScreenLopHoc::drawMainMenu1(window);
         for (int i = displayFrom; i < displayLimit; i++){
            if (classList.size() <= i && Buttonclass.size() <= i)
                break;
            classList[i].draw(window);
            Buttonclass[i].draw(window) ; 
    }
        nextPageBtn.draw(window);
        prevPageBtn.draw(window);
        window.draw(pageText);
        ma.draw(window); 
        lop.draw(window) ;
        window.display();
    }
    return 0;
}

int ScreenLopHoc::InClass(sf::RenderWindow& window , LopSV& selectedLop  ){
    cout << 1 ; 
    cout << "o day " ; 
    cout <<DS_LOPSV::getInstance().nodes[0].MALOP ;  
    cout << "den day " ; 
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về -1 nếu không tải được font
    }
      // Các thành phần giao diện
    Text title(541.f, 225.f, 618.f, 39.f, "THONG TIN LOP HOC", font, sf::Color::Red, 15);
    Text malop(371.f, 315.f, 158.f, 47.f, "MA LOP", font, sf::Color::Red, 12);
    Text tenlop(371.f, 384.f, 158.f, 47.f, "TEN LOP", font, sf::Color::Red, 12);
    
    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color::Red, 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color::Red, 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color::Red, 15 ) ; 
    Text Malop(541.f, 315.f, 618.f, 47.f,selectedLop.MALOP , font , sf :: Color :: Red , 15);
    Text Tenlop(541.f, 384.f, 618.f, 47.f,selectedLop.TENLOP ,  font , sf :: Color :: Red , 15);
     while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                // Kiểm tra các nút được nhấn
                if (sua.isClicked(mousePos)) {
                    fixClass(window,selectedLop);
                    Data::popup("THAY DOI THANH CONG ") ; 
                    break ; 
                }
                if (thoat.isClicked(mousePos)) {
                   return 1 ; 
                }
                 if (xoa.isClicked(mousePos)) {
                        if(Data::confirm("BAN CO CHAC CHAN XOA LOP NAY KHONG ")){
                           DS_LOPSV::getInstance().XoaLopSV(selectedLop.MALOP) ; 
                             // xoa trong trong file 
                            Data::deletemonhoc(classPath ,selectedLop.MALOP ) ; 
                            Data::popup("DA XOA LOP THANH CONG ") ; 
                        }
                 }
        }
        // Vẽ các thành phần lên màn hình
        window.clear(sf::Color::White);
        // Vẽ menu chính
        BaseScreenLopHoc::drawMainMenu1(window);
        // Vẽ các yếu tố lớp học
        title.draw(window);
        malop.draw(window);
        tenlop.draw(window);
        Malop.draw(window);
        Tenlop.draw(window);
        them.draw(window);
        xoa.draw(window);
        thoat.draw(window);
        sua.draw(window);
        window.display();
    }
    }
    return 0;
}
int ScreenLopHoc::addClass(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về -1 nếu không tải được font
    }
    // Các thành phần giao diện
    Text title(541.f, 225.f, 618.f, 39.f, "THONG TIN LOP HOC", font, sf::Color::Red, 15);
    Text malop(371.f, 315.f, 158.f, 47.f, "MA LOP", font, sf::Color::Red, 12);
    Text tenlop(371.f, 384.f, 158.f, 47.f, "TEN LOP", font, sf::Color::Red, 12);
    InputField Malop(541.f, 315.f, 618.f, 47.f, font);
    InputField Tenlop(541.f, 384.f, 618.f, 47.f, font);
    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color::Red, 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color::Red, 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color::Red, 15 ) ; 
    Malop.setSelected(true);
    while (window.isOpen()) {
        sf::Event event;
        if (Malop.isSelected()) Malop.textCursor(Malop.getInput());
        if (Tenlop.isSelected()) Tenlop.textCursor(Tenlop.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Đóng cửa sổ
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                Malop.handleMouseClick(mousePos);
                Tenlop.handleMouseClick(mousePos);
                
                if(thoat.isClicked(mousePos)){
                    return 2 ; 
                }
                // Kiểm tra nếu nhấn nút SAVE
                if (ghi.isClicked(mousePos)) {
                    std::string malopInput = Malop.getInput();
                    std::string tenlopInput = Tenlop.getInput();
                    // Kiểm tra độ dài tên môn học
                    if (malopInput.length() > 15) {
                        Data::popup(" Ma lop không được quá 15 ký tự!");
                        continue;  // Quay lại nhập lại mà không tiến hành thêm
                    }
                      // Kiểm tra độ dài tên môn học
                    if (tenlopInput.length() > 15) {
                        Data::popup("Tên lop  không được quá 15 ký tự!");
                        continue;  // Quay lại nhập lại mà không tiến hành thêm
                    }
                     if (!malopInput.empty() && !tenlopInput.empty() ) {
                        DS_LOPSV::getInstance().ThemLopSV(LopSV(malopInput, tenlopInput)); 
                        // Tạo một vector chứa các giá trị cần thêm vào CSV
                        std::vector<std::string> newRow = {malopInput, tenlopInput}; 
                    if (Data::addlophoc(classPath, font, newRow)) {
                        std::cout << "thanh cong " << std::endl;
                    } else {
                        std::cerr << "not load" << std::endl;
                     }
                 int vitri ; 
                 int temp = DS_LOPSV::getInstance().KTMaLop(DS_LOPSV::getInstance(),malopInput,DS_LOPSV::getInstance().n);
                                if(temp != 0){
                                    if(temp == -1)
                                 {
                                    vitri = 0;	
                                }else{
                                     vitri = temp;
                                }
                                } 
                fsys::path studentFile = classDir / (tenlopInput + ".csv");  // Tên file là MALOP.csv
                csvFile SVFile(studentFile); // Tạo đối tượng csvFile
                if (SVFile.isCreate()) {
                    std::cout << "Tệp CSV lớp đã được tạo: " << studentFile << std::endl;
                    // Khởi tạo tiêu đề cột (ví dụ: MASV, HO, TEN, PHAI, SODT)
                    SVFile.cnt.push_back({"MASV", "HO", "TEN", "PHAI", "SODT"});
                    SVFile.writeFile();
                } else {
                    std::cout << "Tệp CSV lớp đã tồn tại: " << studentFile << std::endl;
                }
                    }
                }
            }
            // Xử lý nhập liệu cho các input field
            Malop.processInput(event);
            if (Malop.chooseNextField()) {
                Tenlop.setSelected(true);
            }
            Tenlop.processInput(event);
            if (Tenlop.chooseNextField()) {
            }
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        Malop.setSelected(Malop.isSelected() && !ghi.isClicked(mousePos));
        Tenlop.setSelected(Tenlop.isSelected() && !ghi.isClicked(mousePos));
        window.clear(sf::Color::White);
         // Vẽ menu chính
         BaseScreenLopHoc::drawMainMenu1(window) ; 
        title.draw(window);
        malop.draw(window);
        tenlop.draw(window);
        Malop.draw(window);
        Tenlop.draw(window);
        window.display();
    }
    }
        return 0 ; 
    }
int  ScreenLopHoc::fixClass(sf :: RenderWindow& window, LopSV& selectedlophoc){
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1 ; // Trả về lỗi nếu không tải được font
    }
      // Các thành phần giao diện
    Text title(541.f, 225.f, 618.f, 39.f, "THONG TIN LOP HOC", font, sf::Color::Red, 15);
    Text malop(371.f, 315.f, 158.f, 47.f, "MA LOP", font, sf::Color::Red, 12);
    Text tenlop(371.f, 584.f, 158.f, 47.f, "TEN LOP", font, sf::Color::Red, 12); 
    InputField lop(514.f , 784.f , 618.f , 47.f  , font ) ; 
    Text Malop(541.f, 315.f, 618.f, 47.f, selectedlophoc.MALOP,  font , sf :: Color :: Red , 15);
    EditableText Tenlop(541.f,  784.f, selectedlophoc.TENLOP ,  font  , &lop);
    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color::Red, 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color::Red, 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color::Red, 15 ) ; 

    // ma.setSelected(true);
    while (window.isOpen()) {
        sf::Event event;
        // if (ma.isSelected()) ma.textCursor(ma.getInput());
        if (lop.isSelected()) lop.textCursor(lop.getInput());

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Đóng cửa sổ
            }
            Tenlop.update(event) ; 
             if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                // ma.handleMouseClick(mousePos);
                Tenlop.handleMouseClick(mousePos);
                if(thoat.isClicked(mousePos)){
                    return  3 ; 
                }
                // Kiểm tra nếu nhấn nút SAVE
                if (ghi.isClicked(mousePos)) {
                    std::string tenlopInput = Tenlop.getText();
                     // Kiểm tra dữ liệu nhập vào bằng cách in ra console
                       
                        std::cout << "ten lop : " << tenlopInput << std::endl;
                    
                    // Kiểm tra thay đổi ở các trường
                    if (tenlopInput != selectedlophoc.TENLOP ) {
                        // Tạo một vector chứa các giá trị cần thêm vào CSV
                        std::vector<std::string> newRow = {tenlopInput,tenlopInput};
                        Data::updateMonHoc(classPath,selectedlophoc.MALOP , newRow);
                         LopSV selectedLop = {selectedlophoc.MALOP, tenlopInput };
                        DS_LOPSV::getInstance().SuaLop(selectedLop.MALOP , selectedLop ) ; 
                    }
                }
            }
            lop.updateCursor() ; 
            // lop.processInput(event);
            // if (lop.chooseNextField()) {
            // }
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        // ma.setSelected(ma.isSelected() && !ghi.isClicked(mousePos));
        lop.setSelected(lop.isSelected() && !ghi.isClicked(mousePos));
        window.clear(sf::Color::White);
         // Vẽ menu chính
        BaseScreenLopHoc::drawMainMenu1(window) ; 
        // Vẽ các yếu tố lớp học
        title.draw(window);
        malop.draw(window);
        tenlop.draw(window);
        Malop.draw(window);
        Tenlop.draw(window);
        window.display();
    }
    }
    return 0 ;
 } 
int ScreenLopHoc::choiseclass(sf::RenderWindow& window ){
    // cout << "o day " ; 
    // cout << DS_LOPSV::getInstance().nodes[0].MALOP ; 

    // if(DS_LOPSV::getInstance().nodes[0].FIRST.head ==  NULL){
    //     cout << "NO RONG " ; 
    // }else{
    //     cout << "KO RONG" ; 
    // }
    // cout << "Địa chỉ listclass3: " << &listclass3 << endl;
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về -1 nếu không tải được font
    }
     // Xóa dữ liệu cũ trong các vector trước khi thêm dữ liệu mới
    classList.clear();
    Buttonclass.clear();

    // Khởi tạo các nút điều hướng
    Button nextPageBtn(901.f, 833.f, 92.f, 62.f, "Next", font, sf::Color::Red, 15);
    Button prevPageBtn(606.f, 833.f, 92.f, 62.f, "Prev", font, sf::Color::Red, 15);

    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color(255, 182, 193), 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color(255, 182, 193), 15 ) ; 

    // Khởi tạo các nhãn
    Text ma(217.f , 281.f , 539.f , 46.f , "MA LOP " , font , sf :: Color :: Red , 15) ; 
    Text lop(756.f , 281.f , 539.f , 46.f , "TEN LOP " , font , sf :: Color :: Red , 15) ; 

    // Tạo đối tượng sf::Text để hiển thị số trang
    sf::Text pageText;
    pageText.setFont(font);
    pageText.setCharacterSize(20);
    pageText.setFillColor(sf::Color::Black);
    pageText.setPosition(750.f, 833.f);
    Data::displaylop(font) ;
    
    int displayFrom = 0;
    int itemsPerPage = 10;

    while (window.isOpen()) {
        sf::Event event;
        int displayLimit = std::min(displayFrom + itemsPerPage, static_cast<int>(classList.size()));
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (nextPageBtn.isClicked(mousePos)) {
                    if (displayFrom + itemsPerPage < static_cast<int>(classList.size())) {
                        displayFrom += itemsPerPage; // Chuyển sang trang tiếp theo
                    }
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - itemsPerPage >= 0) {
                        displayFrom -= itemsPerPage; // Quay lại trang trước
                    }
                }
                if(thoat.isClicked(mousePos)){
                    return 0 ; 
                }
                //Kiểm tra nếu một trong các nút môn học trong buttonsubject được nhấn
                for (int i = displayFrom; i < displayLimit && i < Buttonclass.size(); i++) {
                        if (Buttonclass[i].isClicked(mousePos)) {
                            cout << "den day " ;  
                            // string ma = Buttonclass[i].getText() ; 
                            // showStudent(window , ma , listclass) ;  
                            // // Dừng vòng lặp sau khi tìm thấy môn học được nhấn
                            cout << "den day " ; 
                        return 2 ; 
                        }
                        }
            }
        }
        //Tính số trang hiện tại và tổng số trang
        int currentPage = (displayFrom / itemsPerPage) + 1;
        int totalPages = (classList.size() + itemsPerPage - 1) / itemsPerPage;

        // Cập nhật nội dung văn bản hiển thị số trang
        pageText.setString("Page " + std::to_string(currentPage) + " / " + std::to_string(totalPages));
        window.clear(sf::Color::White);
        // Vẽ menu chính  
        BaseScreenLopHoc::drawMainMenu1(window);
         for (int i = displayFrom; i < displayLimit; i++){
            if (classList.size() <= i && Buttonclass.size() <= i)
                break;
            classList[i].draw(window);
            Buttonclass[i].draw(window) ; 
    }
        //Vẽ các nút và thông tin trang
        nextPageBtn.draw(window);
        prevPageBtn.draw(window);
        window.draw(pageText);
        ma.draw(window); 
        lop.draw(window) ;
        window.display();
    }
    return 0;
} 

int ScreenLopHoc::showStudent(sf::RenderWindow& window , string& ma , DS_LOPSV& listclass){
   if(listclass.nodes[0].FIRST.head == NULL){
                                cout << "NO RONG " ; 
                            }else{
                                cout << "KO RONG " ; 
                            }
    SinhVien sv1("123456", "Nguyen", "A", "Nam", "0987654321");
    listclass.nodes[0].FIRST.insertSV(sv1) ; 
//    DS_LOPSV& listclass10 =  DS_LOPSV::getInstance() ;
// cout << "Địa chỉ listclass3: " << &listclass3 << endl;
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    } 
    Text lop(120.f , 201.f ,158.f , 62.f , ma , font , sf :: Color :: Red , 15 ) ;
    InputField inputField(330.f, 210.f, 158.f, 62.f, font);
    // Tạo dropdown với các mục
    std::vector<std::string> items = {"Item 1", "Item 2", "Item 3"};
    Dropdown dropdown(537.f, 201.f, 200.f, 40.f, font, items, &inputField);

    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color(255, 182, 193), 15 ) ;
    // Tạo đối tượng Text để hiển thị thông tin lớp
    //Text lop(362.f, 235.f, 158.f, 62.f, "Lop: " + tenlop, font, sf::Color::Red, 15);
    Button nextPageBtn(901.f, 833.f, 92.f, 62.f, "Next", font, sf :: Color :: Red , 15);
    Button prevPageBtn(606.f, 833.f, 92.f, 62.f, "Prev", font, sf :: Color :: Red , 15 );
    // Button addBtn(1155.f, 221.f, 136.f, 54.f, "ADD", font, sf :: Color :: Red , 15) ;
    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color(255, 182, 193), 15 ) ; 
    int vitri ; 
    int temp = DS_LOPSV::getInstance().KTMaLop(DS_LOPSV::getInstance(),ma,DS_LOPSV::getInstance().n);
        if(temp != 0){
            if(temp == -1)
                {
                vitri = 0;	
            }else{
                vitri = temp;
                }
            } 
            cout << "o day " ; 
    cout << vitri ; 
    // listclass8.nodes[0].FIRST.In() ;
    // arrfile[vitri] = student1 ; 
    if(DS_LOPSV::getInstance().nodes[0].FIRST.head == NULL){
        cout << "NO RONG " ; 
    }
    // cout << listclass3.nodes[0].MALOP ;  
    // cout << &listclass3.nodes[0].FIRST ; 
    // DanhSachSV sv = listclass3.nodes[0].FIRST ; 
    DanhSachSV sv  ;
    if(sv.head == NULL){
        cout << "NO RONG " ; 
    }
   fsys::path studentFile = classDir / (DS_LOPSV::getInstance().nodes[vitri].TENLOP + ".csv"); 
   cout << endl ; 
   cout << 1 ; 
    cout << studentFile ;
    cout << endl ;
    cout << 1 ;  
    std::pair<std::vector<Text>, std::vector<Button>> SV =  Data::displaystudent(sv, font);  
    // std::pair<std::vector<Text>, std::vector<Button>> SV =  Data::displaystudent(student1,  font);  
    std :: vector<Text> StudenList ; 
    std :: vector<Button> ButtonStudent ;
    // Sao chép dữ liệu từ `SV` vào `StudentList` và `ButtonStudent`
    StudenList = SV.first;       // Sao chép toàn bộ vector `Text` từ SV
    ButtonStudent = SV.second;     // Sao chép toàn bộ vector `Button` từ SV
     // Khởi tạo các nhãn
    Text Ma(8.f, 355.f, 272.f, 61.f, "MA SINH VIEN ", font, sf::Color::Red, 15);
    Text ho(273.f, 355.f, 272.f, 61.f, "HO", font, sf::Color::Red, 15);
    Text ten(543.f, 355.f, 272.f, 61.f, "TEN", font, sf::Color::Red, 15);
    Text phai(820.f, 355.f, 272.f, 61.f, "PHAI", font, sf::Color::Red, 15);
    Text sdt(1089.f, 355.f, 272.f, 61.f, "SDT", font, sf::Color::Red, 15);
    // Tạo đối tượng sf::Text để hiển thị số trang
    sf::Text pageText;
    pageText.setFont(font);
    pageText.setCharacterSize(20);
    pageText.setFillColor(sf::Color::Black);
    pageText.setPosition(750.f, 833.f); // Vị trí giữa nút Next và Prev
    // DanhSachSV sv ;
    cout << ButtonStudent.size() ; 
    cout << 1 ; 
    int displayFrom = 0;
    int itemsPerPage = 25;
    inputField.setSelected(true);
    while (window.isOpen()) {
        sf::Event event;
        if (inputField.isSelected()) inputField.textCursor(inputField.getInput());
        int displayLimit = std::min(displayFrom + itemsPerPage, static_cast<int>(StudenList.size()));
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                dropdown.handleClick(sf::Mouse::getPosition(window)); // Xử lý nhấp chuột
                inputField.handleMouseClick(mousePos);
                
                if (nextPageBtn.isClicked(mousePos)) {
                    if (static_cast<std::vector<Text>::size_type>(displayFrom + itemsPerPage) < StudenList.size()) {
                        displayFrom += itemsPerPage; // Chuyển sang trang tiếp theo
                    }
                }

                if (prevPageBtn.isClicked(mousePos)) {
                    if (displayFrom - itemsPerPage >= 0) {
                        displayFrom -= itemsPerPage; // Quay lại trang trước
                    }
                }

                if (them.isClicked(mousePos)) {
                    addStudent(window ,vitri ); 
                }
                if(thoat.isClicked(mousePos)){
                    return 0  ; 
                }
                for (int i = displayFrom; i < displayLimit && i < ButtonStudent.size(); i++) {
                        if (ButtonStudent[i].isClicked(mousePos)) {
                            cout << 1 ; 
                            string ma = ButtonStudent[i].getText() ;
                            cout << ma ; 
                            cout << 12 ;
                             SinhVien selectedsv = DS_LOPSV::getInstance().nodes[vitri].FIRST.findStudentByMASV(ma) ;
                            InStudent(window,selectedsv ,vitri);  // Hiển thị thông tin môn học tương ứng
                            // Dừng vòng lặp sau khi tìm thấy môn học được nhấn
                             break ; 
                        }
                        }
            }
        // Tính số trang hiện tại và tổng số trang
        int currentPage = (displayFrom / itemsPerPage) + 1;
        int totalPages = (StudenList.size() + itemsPerPage - 1) / itemsPerPage;
        // Cập nhật nội dung văn bản hiển thị số trang
        pageText.setString("Page " + std::to_string(currentPage) + " / " + std::to_string(totalPages));
        inputField.processInput(event);// Xử lý nhập liệu cho trường nhập liệu
        }
       window.clear(sf::Color::White);
        // Vẽ menu chính
        BaseScreenLopHoc::drawMainMenu1(window) ; 
            // Hiển thị các sinh viên trong trang hiện tại
            for (int i = displayFrom; i < displayLimit; i++) {
                 if (StudenList.size() <= i && ButtonStudent.size() <= i)
                break;
                    StudenList[i].draw(window);
                ButtonStudent[i].draw(window) ; 
                // StudenList[i].draw(window);
                // ButtonStudent[i].draw(window) ; 
            }
            // Hiển thị các nút và thông tin trang
            nextPageBtn.draw(window);
            prevPageBtn.draw(window);
            window.draw(pageText);
            Ma.draw(window) ; 
            ho.draw(window); 
            ten.draw(window) ; 
            phai.draw(window) ; 
            sdt.draw(window) ; 
            lop.draw(window) ; 

            inputField.draw(window);
            dropdown.draw(window); // Vẽ danh sách thả xuống
            window.display(); // Hiển thị toàn bộ nội dung vừa vẽ lên cửa sổ
                }
    return 0;
    } // Trả về 0 nếu không có lỗi
    int ScreenLopHoc::addStudent(sf::RenderWindow& window , int& vitri ) {
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về lỗi nếu không tải được font
    }
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color(255, 182, 193), 15 ) ; 
     // Tạo các đối tượng Text và InputField
    Text title(366.f, 216.f, 485.f, 122.f, "THONG TIN SINH VIEN", font, sf::Color::Red, 20);
    Text ma(132.f, 390.f, 158.f, 58.f, "MA LOP", font, sf::Color::Red, 20);
    Text ten(132.f, 515.f, 158.f, 58.f, "TEN", font, sf::Color::Red, 20);
    Text ho(694.f, 390.f, 158.f, 58.f, "HO", font, sf::Color::Red, 20);
    Text phai(694.f, 491.f, 158.f, 58.f, "PHAI", font, sf::Color::Red, 20);
    Text sdt(356.f, 619.f, 158.f, 58.f, "SDT", font, sf::Color::Red, 20);

    InputField Ma(356.f, 390.f, 286.f, 58.f, font);
    InputField Ten(356.f, 506.f, 286.f, 58.f, font);
    InputField Ho(964.f, 399.f, 325.f, 58.f, font);
    InputField Phai(964.f, 491.f, 120.f, 58.f, font);
    InputField SDT(694.f, 610.f, 411.f, 58.f, font);

    Button saveBtn(1094.f, 763.f, 134.f, 78.f, "SAVE", font, sf::Color::Red, 15);
    Ma.setSelected(true);
    Ten.setSelected(true);
    Ho.setSelected(true);
    Phai.setSelected(true);
    SDT.setSelected(true);
    while (window.isOpen()) {
        sf::Event event;
        if (Ma.isSelected()) Ma.textCursor(Ma.getInput());
        if (Ten.isSelected()) Ten.textCursor(Ten.getInput());
        if (Ho.isSelected()) Ho.textCursor(Ho.getInput());
        if (Phai.isSelected()) Phai.textCursor(Phai.getInput());
        if (SDT.isSelected()) SDT.textCursor(SDT.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();

            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                Ma.handleMouseClick(mousePos);
                Ten.handleMouseClick(mousePos);
                Ho.handleMouseClick(mousePos);
                Phai.handleMouseClick(mousePos);
                SDT.handleMouseClick(mousePos);

                // Kiểm tra nút "SAVE" được nhấn
                if (saveBtn.isClicked(mousePos)) {
                    std::string maLop = Ma.getInput();
                    std::string tenSV = Ten.getInput();
                    std::string hoSV = Ho.getInput();
                    std::string phaiSV = Phai.getInput();
                    std::string sdtSV = SDT.getInput();

                    if (!maLop.empty() && !tenSV.empty() && !hoSV.empty() && !phaiSV.empty() && !sdtSV.empty()) { 
                        SinhVien a ={maLop,tenSV,hoSV,phaiSV,sdtSV} ; 
                        DS_LOPSV::getInstance().nodes[vitri].FIRST.insertSV(a) ; 
                        // sv.insertSV(a) ; 
                        // sv.In() ; 
                        std::vector<std::string> newRow = { maLop,tenSV,hoSV,phaiSV,sdtSV}; 
                // Gọi hàm addmonhoc để thêm dòng dữ liệu mới vào CSV

                if (Data::addstudent(classPath, font, newRow)) {
                    std::cout << "thanh cong " << std::endl;
                } else {
                    std::cerr << "not load" << std::endl;
        }
                    }
                    Data::popup("THEM SINH VIEN THANH CONG ") ; 
                }
                if(thoat.isClicked(mousePos)){
                    return 5 ; 
                }
            }

            Ma.processInput(event);
            if (Ma.chooseNextField()) {
                Ten.setSelected(true);
            }
            Ten.processInput(event);
            if (Ten.chooseNextField()) {
                Ho.setSelected(true);
            }
            Ho.processInput(event);
            if (Ho.chooseNextField()) {
                Phai.setSelected(true);
            }
            Phai.processInput(event);
            if (Phai.chooseNextField()) {
                SDT.setSelected(true);
            }
            SDT.processInput(event);

            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            // Chuyển đổi trạng thái chọn cho các trường nhập liệu
            Ma.setSelected(Ma.isSelected() && !saveBtn.isClicked(mousePos));
            Ten.setSelected(Ten.isSelected() && !saveBtn.isClicked(mousePos));
            Ho.setSelected(Ho.isSelected() && !saveBtn.isClicked(mousePos));
            Phai.setSelected(Phai.isSelected() && !saveBtn.isClicked(mousePos));
            SDT.setSelected(SDT.isSelected() && !saveBtn.isClicked(mousePos));
        }

        // Vẽ các thành phần lên màn hình
        window.clear(sf::Color::White);
         // Vẽ menu chính
        BaseScreenLopHoc::drawMainMenu1(window) ; 
         //Vẽ các yếu tố lớp học
        title.draw(window);
        ma.draw(window);
        ten.draw(window);
        ho.draw(window);
        phai.draw(window);
        sdt.draw(window);

        Ma.draw(window);
        Ten.draw(window);
        Ho.draw(window);
        Phai.draw(window);
        SDT.draw(window);
        
        saveBtn.draw(window);
        window.display();
    }

    return 0;
}
int ScreenLopHoc::InStudent(sf::RenderWindow& window , SinhVien& selectedsv , int& vitri){
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1; // Trả về -1 nếu không tải được font
    }
      // Các thành phần giao diện
    Text title(366.f, 216.f, 485.f, 122.f, "THONG TIN SINH VIEN", font, sf::Color::Red, 20);
    Text ma(132.f, 390.f, 158.f, 58.f, "MA LOP", font, sf::Color::Red, 20);
    Text ten(132.f, 515.f, 158.f, 58.f, "TEN", font, sf::Color::Red, 20);
    Text ho(694.f, 390.f, 158.f, 58.f, "HO", font, sf::Color::Red, 20);
    Text phai(694.f, 491.f, 158.f, 58.f, "PHAI", font, sf::Color::Red, 20);
    Text sdt(356.f, 619.f, 158.f, 58.f, "SDT", font, sf::Color::Red, 20);

    Text Ma(356.f, 390.f, 286.f, 58.f,selectedsv.MASV, font ,  sf :: Color :: Red , 15);
    Text Ten(356.f, 506.f, 286.f, 58.f, selectedsv.HO ,  font , sf :: Color :: Red , 15)  ;
    Text Ho(964.f, 399.f, 325.f, 58.f,  selectedsv.TEN , font , sf :: Color :: Red , 15);
    Text Phai(964.f, 491.f, 120.f, 58.f, selectedsv.PHAI ,  font , sf :: Color :: Red , 15);
    Text SDT(694.f, 610.f, 411.f, 58.f, selectedsv.SODT ,  font , sf :: Color:: Red , 15 );

    Button SV(1100.f, 739.f, 134.f, 78.f, "DS SINH VIEN ", font, sf::Color::Red, 20);

    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color::Red, 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color::Red, 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color::Red, 15 ) ; 
    fsys::path studentFile = classDir / (DS_LOPSV::getInstance().nodes[vitri].TENLOP + ".csv");
     while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Kiểm tra các nút được nhấn
                if (sua.isClicked(mousePos)) {
                    fixStudent(window , selectedsv , vitri ) ;
                    Data::popup("CHINH SUA THANH CONG") ;
                }
                if (thoat.isClicked(mousePos)) {
                   return 5 ; 
                }

                 if (xoa.isClicked(mousePos)) {
                    if(Data::confirm("BAN CO CHAC CHAN XOA SINH VIEN NAY KHONG ")){
                        DS_LOPSV::getInstance().nodes[vitri].FIRST.deleteSV(selectedsv) ; 
                        Data::deletemonhoc(studentFile ,selectedsv.MASV ) ; 
                        Data::popup("DA XOA THANH CONG ") ;
                        return 1  ;
                 }
        }
        }
        // Vẽ các thành phần lên màn hình
        window.clear(sf::Color::White);

        // Vẽ menu chính
        BaseScreenLopHoc::drawMainMenu1(window);

        // Vẽ các yếu tố lớp học
        title.draw(window);
        Ma.draw(window);
        Ten.draw(window);
        Ho.draw(window);
        Phai.draw(window);
        SDT.draw(window);
        ma.draw(window);
        ho.draw(window);
        ten.draw(window);
        phai.draw(window);
        sdt.draw(window);

        // Vẽ các nút
        them.draw(window);
        xoa.draw(window);
        thoat.draw(window);
        sua.draw(window);

        window.display();
    }
    }
    return 0 ; 
}
int ScreenLopHoc::fixStudent(sf :: RenderWindow& window, SinhVien& selectedsv , int& vitri)  {
    sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return -1  ; // Trả về lỗi nếu không tải được font
    } 
      // Các thành phần giao diện
    Text title(366.f, 216.f, 485.f, 122.f, "THONG TIN SINH VIEN", font, sf::Color::Red, 20);
    Text ma(221.f, 359.f, 158.f, 58.f, "MA LOP", font, sf::Color::Red, 20);
    Text ten(221.f, 463.f, 158.f, 58.f, "TEN", font, sf::Color::Red, 20);
    Text ho(221.f, 549.f, 158.f, 58.f, "HO", font, sf::Color::Red, 20);
    Text phai(221.f, 639.f, 158.f, 58.f, "PHAI", font, sf::Color::Red, 20);
    Text sdt(221.f, 735.f, 158.f, 58.f, "SDT", font, sf::Color::Red, 20);
     // InputField Ma (900.f , 359.f ,286.f, 58.f , font ) ; 
    InputField Ten(900.f , 457.f , 286.f, 58.f  , font ) ; 
    InputField Ho(900.f , 539.f ,325.f, 58.f  , font ) ; 
    InputField Phai(715.f , 627.f ,120.f, 58.f  , font ) ; 
    InputField SDT(922.f , 721.f , 411.f, 58.f  , font ) ; 

    Text Ma1(499.f, 359.f, 286.f, 58.f,selectedsv.MASV , font ,  sf :: Color :: Red , 15);
    EditableText Ten1(499.f, 466.f, selectedsv.HO ,  font , &Ten)  ;
    EditableText Ho1(499.f, 548.f,  selectedsv.TEN , font , &Ho);
    EditableText Phai1(499.f, 628.f, selectedsv.PHAI ,  font , &Phai);
    EditableText SDT1(499.f, 730.f, selectedsv.SODT ,  font , &SDT);
    Button SV(1100.f, 739.f, 134.f, 78.f, "DS SINH VIEN ", font, sf::Color::Red, 20);

    Button them(264.f , 149.f ,  151.f , 28.f , "THEM" , font, sf::Color::Red, 15 ) ; 
    Button xoa(477.f , 149.f ,  151.f , 28.f , "XOA" , font, sf::Color::Red, 15 ) ; 
    Button ghi(944.f , 149.f ,  151.f , 28.f , "GHI" , font, sf::Color::Red, 15 ) ; 
    Button thoat(1202.f , 149.f ,  84.f , 28.f , "THOAT" , font, sf::Color::Red, 15 ) ; 
    Button sua(722.f , 149.f ,  151.f , 28.f , "SUA" , font, sf::Color::Red, 15 ) ; 
     fsys::path studentFile = classDir / (DS_LOPSV::getInstance().nodes[vitri].TENLOP + ".csv");
    // Ma.setSelected(true);
    // Ten.setSelected(true);
    // Ho.setSelected(true);
    // Phai.setSelected(true);
    // SDT.setSelected(true);
    while (window.isOpen()) {
        sf::Event event;
        // if (Ma.isSelected()) Ma.textCursor(Ma.getInput());
        if (Ten.isSelected()) Ten.textCursor(Ten.getInput());
        if (Ho.isSelected()) Ho.textCursor(Ho.getInput());
        if (Phai.isSelected()) Phai.textCursor(Phai.getInput());
        if (SDT.isSelected()) SDT.textCursor(SDT.getInput());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
              // Cập nhật sự kiện cho EditableText
            Ten1.update(event);
            Ho1.update(event);
            Phai1.update(event);
            SDT1.update(event);
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                // Ma.handleMouseClick(mousePos);
                Ten1.handleMouseClick(mousePos);
                Ho1.handleMouseClick(mousePos);
                Phai1.handleMouseClick(mousePos);
                SDT1.handleMouseClick(mousePos);

                // Kiểm tra nút "SAVE" được nhấn
                if (ghi.isClicked(mousePos)) {
                    // std::string maSV = Ma1.getInput();
                    std::string tenSV = Ten1.getText();
                    std::string hoSV = Ho1.getText();
                    std::string phaiSV = Phai1.getText();
                    std::string sdtSV = SDT1.getText();
                    cout << tenSV ; 

                      // Kiểm tra thay đổi ở các trường
                    if (  tenSV != selectedsv.TEN || hoSV != selectedsv.HO || phaiSV != selectedsv.PHAI || sdtSV != selectedsv.SODT) {
                        // Tạo một vector chứa các giá trị cần thêm vào CSV
                        std::vector<std::string> newRow = {selectedsv.MASV, tenSV, hoSV,phaiSV , sdtSV};
                        Data::updateMonHoc(studentFile, selectedsv.MASV, newRow);
                        selectedsv = {selectedsv.MASV, tenSV, hoSV,phaiSV , sdtSV};
                      DS_LOPSV::getInstance().nodes[vitri].FIRST.SuaSinhVien(selectedsv) ; 
                    }
                }
                 if(thoat.isClicked(mousePos)){
                    return 5  ;
                }
            }
            Ten.updateCursor();
            Ho.updateCursor();
            Phai.updateCursor();
            SDT.updateCursor();

            // // Ma.processInput(event);
            // if (Ma.chooseNextField()) {
            //     Ten.setSelected(true);
            // }
            Ten.processInput(event);
            if (Ten.chooseNextField()) {
                Ho.setSelected(true);
            }
            Ho.processInput(event);
            if (Ho.chooseNextField()) {
                Phai.setSelected(true);
            }
            Phai.processInput(event);
            if (Phai.chooseNextField()) {
                SDT.setSelected(true);
            }
            SDT.processInput(event);

            // sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            // Chuyển đổi trạng thái chọn cho các trường nhập liệu
            // Ma.setSelected(Ma.isSelected() && !ghi.isClicked(mousePos));
            // Ten.setSelected(Ten.isSelected() && !ghi.isClicked(mousePos));
            // Ho.setSelected(Ho.isSelected() && !ghi.isClicked(mousePos));
            // Phai.setSelected(Phai.isSelected() && !ghi.isClicked(mousePos));
            // SDT.setSelected(SDT.isSelected() && !ghi.isClicked(mousePos));
        }
        window.clear(sf::Color::White);
         // Vẽ menu chính
        // BaseScreenLopHoc::drawMainMenu1(window) ; 
        // Vẽ các yếu tố lớp học
        title.draw(window);
        ma.draw(window);
        ten.draw(window);
        phai.draw(window);
        sdt.draw(window);
        sdt.draw(window);
        Ma1.draw(window);
        Ten1.draw(window);
        Phai1.draw(window);
        SDT1.draw(window);
        // Ma.draw(window);
        Ten.draw(window);
        Ho.draw(window);
        Phai.draw(window);
        SDT.draw(window);
        window.display();
    }
    return 0   ;
 } 


