
#include"DataUtils.h"
#include"globals.h"
#include<vector>
#include"FileNFoder.h"
#include"BuiltClasses.h"
#include <iomanip>  // Để sử dụng std::setw
#include <sstream>
// 

void Data::getlop( fsys::path filepath) {
    csvFile lopList(filepath);
    // Đọc nội dung file CSV
    lopList.readFile(); 

    // Kiểm tra nếu file không tồn tại hoặc có lỗi mở file
    if (lopList.cnt.empty()) {
        std::cerr << "Failed to load data from file: " << filepath.generic_string() << std::endl;
        return; // Không tiếp tục nếu không đọc được dữ liệu
    }

    for (size_t i = 1; i < lopList.cnt.size(); ++i) {
        LopSV lop;
        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (lopList.cnt[i].size() < 2) {
            std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu thiếu dữ liệu
        }

        // Đọc và gán giá trị cho các trường trong LopSV
        lop.MALOP = lopList.cnt[i][0];    // Cột 0 là MALOP
        lop.TENLOP = lopList.cnt[i][1];    // Cột 1 là TENLOP
        lop.FIRST = nullptr;               // Khởi tạo danh sách sinh viên trống

        try {
            // Nếu cần thực hiện thao tác nào khác, có thể bổ sung ở đây.
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid data format at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu dữ liệu không đúng định dạng
        }

        // Thêm lớp sinh viên vào danh sách DS_LOPSV
        DS_LOPSV::getInstance().ThemLopSV(lop);
         
    }
}

// void Data::getlop( fsys::path filepath) {
//     csvFile lopList(filepath);
//     // Đọc nội dung file CSV
//     lopList.readFile(); 

//     // Kiểm tra nếu file không tồn tại hoặc có lỗi mở file
//     if (lopList.cnt.empty()) {
//         std::cerr << "Failed to load data from file: " << filepath.generic_string() << std::endl;
//         return; // Không tiếp tục nếu không đọc được dữ liệu
//     }

//     for (size_t i = 1; i < lopList.cnt.size(); ++i) {
//         LopSV lop;
//         // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
//         if (lopList.cnt[i].size() < 2) {
//             std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
//             continue; // Bỏ qua dòng nếu thiếu dữ liệu
//         }

//         // Đọc và gán giá trị cho các trường trong LopSV
//         lop.MALOP = lopList.cnt[i][0];    // Cột 0 là MALOP
//         lop.TENLOP = lopList.cnt[i][1];    // Cột 1 là TENLOP
//         lop.FIRST = nullptr;               // Khởi tạo danh sách sinh viên trống

//         try {
//             // Nếu cần thực hiện thao tác nào khác, có thể bổ sung ở đây.
//         } catch (const std::invalid_argument& e) {
//             std::cerr << "Invalid data format at line " << i + 1 << ". Skipping...\n";
//             continue; // Bỏ qua dòng nếu dữ liệu không đúng định dạng
//         }

//         // Thêm lớp sinh viên vào danh sách DS_LOPSV
//         DS_LOPSV::getInstance().ThemLopSV(lop);
//         // Tạo và lưu file CSV cho lớp (trống) trong thư mục D:\du an\SFML\SFML\data\Classes ; 
//         fsys::path classDir = "D:\\du an\\SFML\\SFML\\data\\Classes\\";  // Đường dẫn đến thư mục chứa lớp
//         fsys::path studentFile = classDir / (lop.MALOP + ".csv");  // Tên file là MALOP.csv
//          // dùng hàm lấy vị trí trong mang tuyen tinh  mang lop  
//          // lay vij tri xong gan vao 
//         /*temp = KTMaLop(ds,a,ds.n);
// 		if(temp != 0)
// 		{
// 			if(temp == -1)
// 			{
// 				vitri = 0;	
// 			}else{
// 				vitri = temp;
// 			}
//             arrfile[i] = studentFile 
//             */
//     }
// }




void Data::displaylop(fsys::path filepath , sf::Font& font) {
      if (!fsys::exists(filepath)) {
        std::cerr << "Không tìm thấy file: " << filepath.string() << std::endl;
        return;
    }
    
    // Tạo đối tượng csvFile để đọc dữ liệu
    csvFile lopList(filepath);
    lopList.readFile(); 

    // Đảm bảo rằng dữ liệu đã được đọc vào
    if (lopList.cnt.empty()) {
        std::cout << "File trống hoặc chưa được đọc!" << std::endl;
        return;
    }

    float yPosition = 334.f;

    // Duyệt qua từng dòng dữ liệu đã đọc từ file CSV
    for (size_t i = 1; i < lopList.cnt.size(); ++i) {  // Bỏ qua dòng tiêu đề (nếu có)
        const auto& row = lopList.cnt[i];

        // Kiểm tra xem dòng có đủ dữ liệu không
        if (row.size() < 2) {  // Giả sử chỉ có MALOP và TENLOP
            std::cerr << "Dòng không hợp lệ trong dữ liệu CSV: " << i + 1 << std::endl;
            continue;
        }

        // Đọc các trường từ dòng CSV (MALOP, TENLOP)
        std::string MALOP = row[0];
        std::string TENLOP = row[1];

        // Tạo chuỗi thông tin lớp
        Text ma(217.f, yPosition, 539.f, 54.f,  MALOP, font, sf::Color::Red, 15); 
        Text lop(756.f, yPosition, 539.f, 54.f, TENLOP, font, sf::Color::Red, 15); 

        // Thêm vào các vector
        classList.push_back(ma);
        classList.push_back(lop);

        // Tạo nút cho lớp
        float buttonWidth = std::max(150.f, static_cast<float>(MALOP.size() * 10));  // Thay đổi chiều rộng nút dựa trên độ dài chuỗi
        Button button(217.f, yPosition, buttonWidth, 58.f, MALOP, font, sf::Color::Red, 15);
        Buttonclass.push_back(button);
        Buttonclass.push_back(button);

        //yPosition = (static_cast<int>(yPosition) + 100) % 422 + 422;
        yPosition = (static_cast<int>(yPosition) + 100) ;
        if (yPosition > 800)
            yPosition = 334.f;
    }
}



bool Data::addlophoc(fsys::path filepath, sf::Font& font, std::vector<std::string>& newRow) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);
    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Thêm một dòng dữ liệu mới vào bộ nhớ (cnt)
    bool rowAdded = file.addRow();  // Thêm một hàng mới (hàng trống)
    
    // Kiểm tra nếu việc thêm hàng thành công
    if (!rowAdded) {
        std::cerr << "Không thể thêm dữ liệu vào bộ nhớ." << std::endl;
        return false;  // Không thể thêm hàng vào bộ nhớ
    }

    // Cập nhật dữ liệu trong hàng mới
    file.cnt[file.cnt.size() - 1] = newRow;

    // Ghi lại dữ liệu vào tệp CSV
    if (file.writeFile()) {
        std::cout << "Dữ liệu đã được thêm vào tệp CSV thành công!" << std::endl;
        return true;  // Dữ liệu đã được thêm và ghi vào tệp thành công
    } else {
        std::cerr << "Không thể ghi dữ liệu vào tệp CSV." << std::endl;
        return false;  // Không thể ghi dữ liệu vào tệp
    }
}
LopSV Data::displayclassInfo(int j) {
    // Lấy các đối tượng Text từ subjectList dựa trên chỉ số j
    LopSV a ; 
    Text ma = classList[j * 4];    // MAMH
    Text ten = classList[j * 4 + 1];  // TENMH


    // In thông tin ra màn hình (hoặc có thể làm gì đó với chúng)
    a.MALOP = ten.getContent() ; 
    a.TENLOP = ten.getContent() ;
   
    cout << 1 ; 
    return a ; 
}
void Data::deletelophoc(fsys::path filepath, string& malop) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);

    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Tìm và xóa dòng chứa mã môn học
    for (std::size_t i = 0; i < file.cnt.size(); ++i) {
        if (!file.cnt[i].empty() && file.cnt[i][0] == malop) { // Giả sử mã môn học nằm ở cột đầu tiên
            file.deleteRow(i);       // Xóa dòng chứa mã môn học
            file.writeFile();         // Ghi nội dung mới vào file
            std::cout << "Xóa lop học có mã " << malop << " thành công.\n";
            return;
        }
    }

    std::cerr << "Không tìm thấy lop học có mã " << malop << ".\n";
}
void Data::updatelophoc(fsys::path filepath, const std::string& malophocUpdate, const std::vector<std::string>& newRow) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);
    
    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Duyệt qua tất cả các hàng trong cnt để tìm môn học cần cập nhật
    bool found = false;
    for (auto& row : file.cnt) {  // Sử dụng file.cnt thay vì cnt
        // Giả sử MAMH nằm ở vị trí 0 trong mỗi hàng
        if (row.size() > 0 && row[0] == malophocUpdate) {
            // Cập nhật thông tin môn học từ newRow
            if (newRow.size() == row.size()) {
                row = newRow;  // Thay thế toàn bộ hàng bằng newRow
                found = true;
            } else {
                std::cerr << "Dữ liệu trong newRow không phù hợp với số lượng cột trong file.\n";
                return;  // Thoát khỏi hàm nếu số lượng cột không khớp
            }
            break;
        }
    }

    // Nếu không tìm thấy môn học, in ra thông báo lỗi
    if (!found) {
        std::cerr << "MALOP " << malophocUpdate << " không tìm thấy.\n";
        return;  // Thoát khỏi hàm nếu không tìm thấy môn học
    }

    // Ghi lại dữ liệu đã cập nhật vào file
    if (!file.writeFile()) {
        std::cerr << "Ghi tệp không thành công.\n";
        return;  // Thoát khỏi hàm nếu ghi file không thành công
    }

    std::cout << "Môn học đã được cập nhật thành công.\n";
}




// mon hoc 
bool Data::isNumber( std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c) && c != '-') {  // '-' for negative numbers
            return false;
        }
    }
    return true;
}
void Data::getmonhoc(fsys::path filepath) {
    // Kiểm tra nếu tệp có tồn tại
    std::ifstream file(filepath.generic_string());
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath.generic_string() << std::endl;
        return;
    }

    // Đọc nội dung file CSV
    csvFile monhocList(filepath);
    monhocList.readFile();

    // Kiểm tra nếu file không chứa dữ liệu
    if (monhocList.cnt.empty()) {
        std::cerr << "Failed to load data from file: " << filepath.generic_string() << std::endl;
        return;
    }

    // Duyệt qua từng dòng dữ liệu trong tệp CSV
    for (size_t i = 1; i < monhocList.cnt.size(); ++i) {
        MonHoc mh;

        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (monhocList.cnt[i].size() < 4) {
            std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu thiếu dữ liệu
        }

        // Đọc và gán giá trị cho các trường trong MonHoc
        mh.MAMH = monhocList.cnt[i][0]; // Cột 0 là MAMH
        mh.TENMH = monhocList.cnt[i][1]; // Cột 1 là TENMH

        // Kiểm tra giá trị Số tín chỉ lý thuyết và thực hành có phải là số hợp lệ không
        if (Data::isNumber(monhocList.cnt[i][2])) {
            mh.STCLT = std::stoi(monhocList.cnt[i][2]); // Cột 2 là Số tín chỉ lý thuyết
        } else {
            std::cerr << "Invalid number format in STCLT at line " << i + 1 << ". Skipping...\n";
            continue;
        }

        if (Data::isNumber(monhocList.cnt[i][3])) {
            mh.STCTH = std::stoi(monhocList.cnt[i][3]); // Cột 3 là Số tín chỉ thực hành
        } else {
            std::cerr << "Invalid number format in STCTH at line " << i + 1 << ". Skipping...\n";
            continue;
        }

        // Thêm môn học vào cây AVL
        AVLTreeMH::getInstance().Insert(AVLTreeMH::getInstance().root, mh);
    }

    // Đóng tệp sau khi xử lý
    file.close();
}


void Data::displaymonhoc(fsys::path filepath, sf::Font& font) {
    if (!fsys::exists(filepath)) {
        std::cerr << "Không tìm thấy file: " << filepath.string() << std::endl;
        return;
    }

    csvFile monhocList(filepath);
    monhocList.readFile();

    if (monhocList.cnt.empty()) {
        std::cout << "File rỗng hoặc chưa đọc được!" << std::endl;
        return;
    }

    float yPosition = 422.f;

    for (size_t i = 1; i < monhocList.cnt.size(); ++i) {
        const auto& row = monhocList.cnt[i];

        if (row.size() < 4) {
            std::cerr << "Dòng không hợp lệ trong dữ liệu CSV tại dòng: " << i + 1 << std::endl;
            continue;
        }

        std::string MAMH = row[0];
        std::string TENMH = row[1];
        int STCLT = 0;
        int STCTH = 0;

        try {
            STCLT = std::stoi(row[2]);
            STCTH = std::stoi(row[3]);
        } catch (const std::exception& e) {
            std::cerr << "Lỗi tại dòng " << i + 1 << ": " << e.what() << std::endl;
            continue;
        }

        Text ma(68.f, yPosition, 234.f, 35.f, MAMH, font, sf::Color::Red, 15);
        Text ten(302.f, yPosition, 422.f, 35.f, TENMH, font, sf::Color::Red, 15);
        Text lt(724.f, yPosition, 260.f, 35.f, std::to_string(STCLT), font, sf::Color::Red, 15);
        Text th(984.f, yPosition, 296.f, 35.f, std::to_string(STCTH), font, sf::Color::Red, 15);

        subjectList.push_back(ma);
        subjectList.push_back(ten);
        subjectList.push_back(lt);
        subjectList.push_back(th);

        float buttonWidth = std::max(150.f, static_cast<float>(MAMH.size() * 10));  // Thay đổi chiều rộng nút dựa trên độ dài chuỗi
        Button button(68.f, yPosition, buttonWidth, 58.f, MAMH , font, sf::Color::Red, 15);
        buttonsubject.push_back(button);
        buttonsubject.push_back(button);
        buttonsubject.push_back(button);
        buttonsubject.push_back(button);

        //yPosition = (static_cast<int>(yPosition) + 100) % 422 + 422;
        yPosition = (static_cast<int>(yPosition) + 100) ;
        if (yPosition > 800)
            yPosition = 422.f;
    }
}






bool Data::addmonhoc(fsys::path filepath, sf::Font& font, std::vector<std::string>& newRow) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);
    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Thêm một dòng dữ liệu mới vào bộ nhớ (cnt)
    bool rowAdded = file.addRow();  // Thêm một hàng mới (hàng trống)
    
    // Kiểm tra nếu việc thêm hàng thành công
    if (!rowAdded) {
        std::cerr << "Không thể thêm dữ liệu vào bộ nhớ." << std::endl;
        return false;  // Không thể thêm hàng vào bộ nhớ
    }

    // Cập nhật dữ liệu trong hàng mới
    file.cnt[file.cnt.size() - 1] = newRow;

    // Ghi lại dữ liệu vào tệp CSV
    if (file.writeFile()) {
        std::cout << "Dữ liệu đã được thêm vào tệp CSV thành công!" << std::endl;
        return true;  // Dữ liệu đã được thêm và ghi vào tệp thành công
    } else {
        std::cerr << "Không thể ghi dữ liệu vào tệp CSV." << std::endl;
        return false;  // Không thể ghi dữ liệu vào tệp
    }
}



MonHoc Data::displaySubjectInfo(int j) {
    // Lấy các đối tượng Text từ subjectList dựa trên chỉ số j
    MonHoc mh ; 
    Text ma = subjectList[j * 4];    // MAMH
    Text ten = subjectList[j * 4 + 1];  // TENMH
    Text lt = subjectList[j * 4 + 2];   // STCLT
    Text th = subjectList[j * 4 + 3];   // STCTH

    // In thông tin ra màn hình (hoặc có thể làm gì đó với chúng)
    mh.MAMH = ma.getContent() ; 
    mh.TENMH = ten.getContent() ;
    mh.STCLT = std::stoi(lt.getContent()) ;
    mh.STCTH = std::stoi(th.getContent()) ;
    cout << 1 ; 
    return mh ; 
}




void Data::deletemonhoc(fsys::path filepath, string& mamh) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);

    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Tìm và xóa dòng chứa mã môn học
    for (std::size_t i = 0; i < file.cnt.size(); ++i) {
        if (!file.cnt[i].empty() && file.cnt[i][0] == mamh) { // Giả sử mã môn học nằm ở cột đầu tiên
            file.deleteRow(i);       // Xóa dòng chứa mã môn học
            file.writeFile();         // Ghi nội dung mới vào file
            std::cout << "Xóa môn học có mã " << mamh << " thành công.\n";
            return;
        }
    }

    std::cerr << "Không tìm thấy môn học có mã " << mamh << ".\n";
}
void Data::updateMonHoc(fsys::path filepath, const std::string& mamhToUpdate, const std::vector<std::string>& newRow) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);
    
    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Duyệt qua tất cả các hàng trong cnt để tìm môn học cần cập nhật
    bool found = false;
    for (auto& row : file.cnt) {  // Sử dụng file.cnt thay vì cnt
        // Giả sử MAMH nằm ở vị trí 0 trong mỗi hàng
        if (row.size() > 0 && row[0] == mamhToUpdate) {
            // Cập nhật thông tin môn học từ newRow
            if (newRow.size() == row.size()) {
                row = newRow;  // Thay thế toàn bộ hàng bằng newRow
                found = true;
            } else {
                std::cerr << "Dữ liệu trong newRow không phù hợp với số lượng cột trong file.\n";
                return;  // Thoát khỏi hàm nếu số lượng cột không khớp
            }
            break;
        }
    }

    // Nếu không tìm thấy môn học, in ra thông báo lỗi
    if (!found) {
        std::cerr << "MAMH " << mamhToUpdate << " không tìm thấy.\n";
        return;  // Thoát khỏi hàm nếu không tìm thấy môn học
    }

    // Ghi lại dữ liệu đã cập nhật vào file
    if (!file.writeFile()) {
        std::cerr << "Ghi tệp không thành công.\n";
        return;  // Thoát khỏi hàm nếu ghi file không thành công
    }

    std::cout << "Môn học đã được cập nhật thành công.\n";
}

// 

// hiển thị thông báo 
bool Data::confirm(std::string content)
{
     sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return false ; // Return error if font can't be loaded
    }
    //PopUp.png
    sf::RenderWindow windowNext(sf::VideoMode(636, 301), "Notification", sf::Style::Close | sf::Style::Titlebar);
    windowNext.setPosition(sf::Vector2i(500, 400));

//     sf::Font fontNext;
//     if (!fontNext.loadFromFile("TextFont/arial.ttf"))
//         std::cout << "Could not load the font" << std::endl;

//     sf::Texture textureNext;
//     if (!textureNext.loadFromFile("Assets/PopUp.png"))
//         std::cout << "Could not load the popup image" << std::endl;
    std::cout << "Generate popup sucess" << std::endl;
//     sf::Sprite background(textureNext);
    Button yesBtn(310.f, 241.f, 60, 45, "Yes", font , sf :: Color :: Red, 15 );
    Button noBtn(230.f, 241.f, 60, 45, "No", font , sf :: Color :: Red, 15 );
    Text text(140.f, 95.f ,  60 , 45  , content, font ,  sf :: Color :: Red, 15);


    while (windowNext.isOpen()) {
        sf::Event event;

        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                if (yesBtn.isClicked(mousePos)) {
                    windowNext.close();
                    return true;
                }
                if (noBtn.isClicked(mousePos)) {
                    windowNext.close();
                    return false;
                }
            }

        }

        windowNext.clear(sf::Color::White);
     //    windowNext.draw(background);
        text.draw(windowNext);
        yesBtn.draw(windowNext);
        noBtn.draw(windowNext);

        windowNext.display();

        
    }
    return false;
}

void Data::popup(std::string content)
{
      sf::Font font;
    if (!font.loadFromFile("Font/arial.ttf")) {
        return ; // Return error if font can't be loaded
    }
    //PopUp.png
    sf::RenderWindow windowNext(sf::VideoMode(636, 301), "Notification", sf::Style::Close | sf::Style::Titlebar);
    windowNext.setPosition(sf::Vector2i(500, 400));

//     sf::Font fontNext;
//     if (!fontNext.loadFromFile("TextFont/arial.ttf"))
//         std::cout << "Could not load the font" << std::endl;

//     sf::Texture textureNext;
//     if (!textureNext.loadFromFile("Assets/PopUp.png"))
//         std::cout << "Could not load the popup image" << std::endl;
    std::cout << "Generate popup sucess" << std::endl;
//     sf::Sprite background(textureNext);
    Button okBtn(246.f, 241.f, 143, 45, "OKAY", font , sf :: Color ::  Red , 15);
    Text text(100, 95, 60 , 40  , content, font , sf :: Color ::  Red , 15);
    
    
    while (windowNext.isOpen()) {
        sf::Event event;

        while (windowNext.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                windowNext.close();  // Close 
            else if (event.type == sf::Event::KeyPressed) {
                if (event.text.unicode == '\r') windowNext.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(windowNext);

                if (okBtn.isClicked(mousePos))
                    windowNext.close();
            }

        }

        windowNext.clear(sf::Color::White);
     //    windowNext.draw(background);
        text.draw(windowNext);
        okBtn.draw(windowNext);

        windowNext.display();
    }
}


// hoc sinh 
bool Data::addstudent(fsys::path filepath, sf::Font& font, std::vector<std::string>& newRow) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);
    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Thêm một dòng dữ liệu mới vào bộ nhớ (cnt)
    bool rowAdded = file.addRow();  // Thêm một hàng mới (hàng trống)
    
    // Kiểm tra nếu việc thêm hàng thành công
    if (!rowAdded) {
        std::cerr << "Không thể thêm dữ liệu vào bộ nhớ." << std::endl;
        return false;  // Không thể thêm hàng vào bộ nhớ
    }

    // Cập nhật dữ liệu trong hàng mới
    file.cnt[file.cnt.size() - 1] = newRow;

    // Ghi lại dữ liệu vào tệp CSV
    if (file.writeFile()) {
        std::cout << "Dữ liệu đã được thêm vào tệp CSV thành công!" << std::endl;
        return true;  // Dữ liệu đã được thêm và ghi vào tệp thành công
    } else {
        std::cerr << "Không thể ghi dữ liệu vào tệp CSV." << std::endl;
        return false;  // Không thể ghi dữ liệu vào tệp
    }
}


LinkedListSV Data::getstudent(fsys::path filepath) {
    // Kiểm tra nếu tệp có tồn tại
    std::ifstream file(filepath.generic_string());
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath.generic_string() << std::endl;
        //return;
    }

    // Đọc nội dung file CSV
    csvFile studentList(filepath);
    studentList.readFile();

    // Kiểm tra nếu file không chứa dữ liệu
    if (studentList.cnt.empty()) {
        std::cerr << "Failed to load data from file: " << filepath.generic_string() << std::endl;
        //return;
    }

    LinkedListSV sinhvien ; 
    // Duyệt qua từng dòng dữ liệu trong tệp CSV
    for (size_t i = 1; i < studentList.cnt.size(); ++i) {
        SinhVien sv;

        // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
        if (studentList.cnt[i].size() < 4) {
            std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
            continue; // Bỏ qua dòng nếu thiếu dữ liệu
        }

        // Đọc và gán giá trị cho các trường trong MonHoc
        sv.MASV = studentList.cnt[i][0]; // Cột 0 là MAMH
        sv.HO = studentList.cnt[i][1]; // Cột 1 là TENMH
        sv.TEN = studentList.cnt[i][2];
        sv.PHAI = studentList.cnt[i][3];
        sv.SODT = studentList.cnt[i][4];

        sinhvien.ThemSinhVien(sv) ; 

          // Gán danh sách sinh viên vừa tạo cho lớp `lop`
          // duyẹt tu dau đen cuoi loi coi lop nao còn trong gan 
        //lop.FIRST = sinhvien;
    // Đóng tệp sau khi xử lý
    file.close();
}
return sinhvien ; 
}
void Data::deletstudent(fsys::path filepath, string& masv) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);

    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Tìm và xóa dòng chứa mã môn học
    for (std::size_t i = 0; i < file.cnt.size(); ++i) {
        if (!file.cnt[i].empty() && file.cnt[i][0] == masv) { // Giả sử mã môn học nằm ở cột đầu tiên
            file.deleteRow(i);       // Xóa dòng chứa mã môn học
            file.writeFile();         // Ghi nội dung mới vào file
            std::cout << "Xóa sinh vien  có mã " << masv << " thành công.\n";
            return;
        }
    }

    std::cerr << "Không tìm thấy sinh vien có mã " << masv << ".\n";
}

SinhVien Data::displayStudentInfo(int j ,  vector<Text> StudentList ) {
    // Lấy các đối tượng Text từ subjectList dựa trên chỉ số j
    SinhVien a ; 
    Text ma = StudentList[j * 4];    // MAMH
    Text ho = StudentList[j * 4 + 1];  // TENMH
    Text ten = StudentList[j * 4 + 2];   // STCLT
    Text phai = StudentList[j * 4 + 3];   // STCTH
    Text sdt = subjectList[j * 4 + 4];  
    // In thông tin ra màn hình (hoặc có thể làm gì đó với chúng)
    a.MASV = ma.getContent() ; 
    a.HO = ten.getContent() ;
    a.TEN = phai.getContent() ;
    a.SODT = sdt.getContent() ;
   
    cout << 1 ; 
    return a ; 
}
std::pair<std::vector<Text>, std::vector<Button>> Data::displaystudent(fsys::path filepath, sf::Font& font) {
    if (!fsys::exists(filepath)) {
        std::cerr << "Không tìm thấy file: " << filepath.string() << std::endl;
    }
    vector<Text> StudentList ; 
    vector<Button> StudentButton  ;
    csvFile studentList(filepath);
    studentList.readFile();

    if (studentList.cnt.empty()) {
        std::cout << "File rỗng hoặc chưa đọc được!" << std::endl;
        //return;
    }

    float yPosition = 410.f;

    for (size_t i = 1; i < studentList.cnt.size(); ++i) {
        const auto& row = studentList.cnt[i];

        if (row.size() < 4) {
            std::cerr << "Dòng không hợp lệ trong dữ liệu CSV tại dòng: " << i + 1 << std::endl;
            continue;
        }

        std::string MASV = row[0];
        std::string HO = row[1];
        std::string TEN = row[2];   // Tên
        std::string PHAI = row[3]; // Phái
        std::string SODT= row[4] ; // Số điện thoại

        Text ma(9.f, yPosition, 272.f, 50.f, MASV, font, sf::Color::Red, 15);
        Text ho(273.f, yPosition, 272.f, 50.f, HO, font, sf::Color::Red, 15);
        Text ten(544.f, yPosition, 272.f, 50.f, TEN, font, sf::Color::Red, 15);
        Text phai(815.f, yPosition, 272.f, 50.f, PHAI, font, sf::Color::Red, 15);
        Text sodt(1092.f, yPosition, 272.f, 50.f, SODT, font, sf::Color::Red, 15);
        StudentList.push_back(ma);
        StudentList.push_back(ho);
        StudentList.push_back(ten);
        StudentList.push_back(phai);
        StudentList.push_back(sodt);

        float buttonWidth = std::max(150.f, static_cast<float>(MASV.size() * 10));  // Thay đổi chiều rộng nút dựa trên độ dài chuỗi
        Button button(68.f, yPosition, buttonWidth, 58.f, MASV, font, sf::Color::Red, 15);
        StudentButton.push_back(button);
        StudentButton.push_back(button);
        StudentButton.push_back(button);
        StudentButton.push_back(button);
        StudentButton.push_back(button);

        //yPosition = (static_cast<int>(yPosition) + 100) % 422 + 422;
        yPosition = (static_cast<int>(yPosition) + 100) ;
        if (yPosition > 800)
            yPosition = 410.f;
    }
     return {StudentList, StudentButton};
}
static void updatestudent(fsys::path filepath, const std::string& masvToUpdate, const std::vector<std::string>& newRow){
     // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);
    
    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Duyệt qua tất cả các hàng trong cnt để tìm môn học cần cập nhật
    bool found = false;
    for (auto& row : file.cnt) {  // Sử dụng file.cnt thay vì cnt
        // Giả sử MAMH nằm ở vị trí 0 trong mỗi hàng
        if (row.size() > 0 && row[0] == masvToUpdate) {
            // Cập nhật thông tin môn học từ newRow
            if (newRow.size() == row.size()) {
                row = newRow;  // Thay thế toàn bộ hàng bằng newRow
                found = true;
            } else {
                std::cerr << "Dữ liệu trong newRow không phù hợp với số lượng cột trong file.\n";
                return;  // Thoát khỏi hàm nếu số lượng cột không khớp
            }
            break;
        }
    }

    // Nếu không tìm thấy môn học, in ra thông báo lỗi
    if (!found) {
        std::cerr << "MASV " << masvToUpdate << " không tìm thấy.\n";
        return;  // Thoát khỏi hàm nếu không tìm thấy môn học
    }

    // Ghi lại dữ liệu đã cập nhật vào file
    if (!file.writeFile()) {
        std::cerr << "Ghi tệp không thành công.\n";
        return;  // Thoát khỏi hàm nếu ghi file không thành công
    }

    std::cout << "sinh vien  đã được cập nhật thành công.\n";
}


// // lop tin chi 
// void Data::gettc(fsys::path filepath) {
//     // Kiểm tra nếu tệp có tồn tại
//     std::ifstream file(filepath.generic_string());
//     if (!file.is_open()) {
//         std::cerr << "Failed to open file: " << filepath.generic_string() << std::endl;
//         return;
//     }

//     // Đọc nội dung file CSV
//     csvFile monhocList(filepath);
//     monhocList.readFile();

//     // Kiểm tra nếu file không chứa dữ liệu
//     if (monhocList.cnt.empty()) {
//         std::cerr << "Failed to load data from file: " << filepath.generic_string() << std::endl;
//         return;
//     }

//     // Duyệt qua từng dòng dữ liệu trong tệp CSV
//     for (size_t i = 1; i < monhocList.cnt.size(); ++i) {
//         LopTinChi tc;

//         // Kiểm tra độ dài mỗi dòng trong CSV để đảm bảo có đủ số lượng cột
//         if (monhocList.cnt[i].size() < 4) {
//             std::cerr << "Invalid data at line " << i + 1 << ". Skipping...\n";
//             continue; // Bỏ qua dòng nếu thiếu dữ liệu
//         }

//         // Đọc và gán giá trị cho các trường trong MonHoc
//         tc.MALOPTC = monhocList.cnt[i][0]; // Cột 0 là MAMH
//         tc.MAMH = monhocList.cnt[i][1]; // Cột 1 là TENMH
//         tc.NienKhoa = monhocList.cnt[i][1]; // Cột 1 là TENMH
//         tc.HocKy = monhocList.cnt[i][1]; // Cột 1 là TENMH
//         tc.Nhom = monhocList.cnt[i][1]; // Cột 1 là TENMH
//         tc.soSVMin = monhocList.cnt[i][1]; 
//         tc.soSVMax = monhocList.cnt[i][1]; 
    

//         // Thêm môn học vào cây AVL
//         AVLTreeMH::getInstance().Insert(AVLTreeMH::getInstance().root, mh);
//     }

//     // Đóng tệp sau khi xử lý
//     file.close();
// }


void Data::displaytc(fsys::path filepath, sf::Font& font) {
    if (!fsys::exists(filepath)) {
        std::cerr << "Không tìm thấy file: " << filepath.string() << std::endl;
        return;
    }

    csvFile monhocList(filepath);
    monhocList.readFile();

    if (monhocList.cnt.empty()) {
        std::cout << "File rỗng hoặc chưa đọc được!" << std::endl;
        return;
    }

    float yPosition = 290.f;

    for (size_t i = 1; i < monhocList.cnt.size(); ++i) {
        const auto& row = monhocList.cnt[i];

        if (row.size() < 7) {
            std::cerr << "Dòng không hợp lệ trong dữ liệu CSV tại dòng: " << i + 1 << std::endl;
            continue;
        }

        // Lấy dữ liệu từng cột và kiểm tra sự tồn tại
        std::string MALOPTC = row[0];
        std::string MAMH = row[1];
        std::string NienKhoa = row[2];
        std::string HocKy = row[3];
        std::string Nhom = row[4];
        std::string soSVMin = row[5];
        std::string soSVMax = row[6];

        // Kiểm tra các cột bổ sung nếu tồn tại trong hàng
        std::string TENMH = (row.size() > 7) ? row[7] : "";  // nếu có cột 7, lấy TENMH
        std::string STCLT = (row.size() > 8) ? row[8] : "0"; // nếu có cột 8, lấy STCLT
        std::string STCTH = (row.size() > 9) ? row[9] : "0"; // nếu có cột 9, lấy STCTH

        // Tạo các đối tượng Text cho từng cột
        Text a(29.f, yPosition, 165.f, 41.f, MALOPTC, font, sf::Color::Red, 15);
        Text b(194.f, yPosition, 165.f, 41.f, NienKhoa, font, sf::Color::Red, 15);
        Text c(359.f, yPosition, 165.f, 41.f, HocKy, font, sf::Color::Red, 15);
        Text d(524.f, yPosition, 165.f, 41.f, MAMH, font, sf::Color::Red, 15);
        Text e(689.f, yPosition, 165.f, 41.f, Nhom, font, sf::Color::Red, 15);
        Text f(852.f, yPosition, 165.f, 41.f, soSVMin, font, sf::Color::Red, 15);
        Text g(1019.f, yPosition, 165.f, 41.f, soSVMax, font, sf::Color::Red, 15);
        Text h(1184.f, yPosition, 165.f, 41.f, " ", font, sf::Color::Red, 15);

        // Đẩy vào danh sách đối tượng hiển thị
        TCList.push_back(a);
        TCList.push_back(b);
        TCList.push_back(c);
        TCList.push_back(d);
        TCList.push_back(e);
        TCList.push_back(f);
        TCList.push_back(g);
        TCList.push_back(h);

        // Tạo button hiển thị thông tin lớp và môn học
        float buttonWidth = std::max(150.f, static_cast<float>(MALOPTC.size() * 10));
        Button button(68.f, yPosition, buttonWidth, 58.f,  " ", font, sf::Color::Red, 15);
         buttonTC.push_back(button);
         buttonTC.push_back(button);
         buttonTC.push_back(button);
         buttonTC.push_back(button);
         buttonTC.push_back(button);
         buttonTC.push_back(button);
         buttonTC.push_back(button);
        // Điều chỉnh vị trí Y cho dòng tiếp theo
        yPosition += 100;
        if (yPosition > 800)  // đặt lại yPosition khi vượt quá giới hạn
            yPosition = 422.f;
    }
}



bool Data::add(fsys::path filepath, sf::Font& font, std::vector<std::string>& newRow) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);
    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Thêm một dòng dữ liệu mới vào bộ nhớ (cnt)
    bool rowAdded = file.addRow();  // Thêm một hàng mới (hàng trống)
    
    // Kiểm tra nếu việc thêm hàng thành công
    if (!rowAdded) {
        std::cerr << "Không thể thêm dữ liệu vào bộ nhớ." << std::endl;
        return false;  // Không thể thêm hàng vào bộ nhớ
    }

    // Cập nhật dữ liệu trong hàng mới
    file.cnt[file.cnt.size() - 1] = newRow;

    // Ghi lại dữ liệu vào tệp CSV
    if (file.writeFile()) {
        std::cout << "Dữ liệu đã được thêm vào tệp CSV thành công!" << std::endl;
        return true;  // Dữ liệu đã được thêm và ghi vào tệp thành công
    } else {
        std::cerr << "Không thể ghi dữ liệu vào tệp CSV." << std::endl;
        return false;  // Không thể ghi dữ liệu vào tệp
    }
}



LopTinChi Data::displayTCInfo(int j) {
        LopTinChi mh;
        // Lấy các đối tượng Text từ subjectList dựa trên chỉ số j
        Text a = TCList[j * 4];
        Text b = TCList[j * 4 + 1]; // TENMH
        Text c = TCList[j * 4 + 2]; // MAMH
        Text d = TCList[j * 4 + 3]; // STCLT
        Text e = TCList[j * 4 + 4]; // NienKhoa
        Text f = TCList[j * 4 + 5]; // HocKy
        Text g = TCList[j * 4 + 6]; // Nhom
        Text h = TCList[j * 4 + 7]; // huy

        // Gán giá trị cho các thành viên của mh
        mh.MALOPTC = std::stoi(a.getContent());  // Chuyển từ string sang int
        mh.MAMH = b.getContent();  // Giả sử là string
        mh.NienKhoa = c.getContent();  // Giả sử là string
        mh.HocKy = std::stoi(d.getContent()); // Chuyển từ string sang int
        mh.Nhom = std::stoi(e.getContent()); // Chuyển từ string sang int

        // Chuyển từ string sang int
        mh.soSvMin = std::stoi(f.getContent());
        mh.soSvMax = std::stoi(g.getContent());

        // Chuyển từ string sang bool, giả sử chuỗi "true" hoặc "false"
        mh.HuyLop = (h.getContent() == "true");

        std::cout << 1;

        // Trả về đối tượng LopTinChi
return mh;
}




void Data::deleteall(fsys::path filepath, string& key) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);

    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Tìm và xóa dòng chứa mã môn học
    for (std::size_t i = 0; i < file.cnt.size(); ++i) {
        if (!file.cnt[i].empty() && file.cnt[i][0] == key) { // Giả sử mã môn học nằm ở cột đầu tiên
            file.deleteRow(i);       // Xóa dòng chứa mã môn học
            file.writeFile();         // Ghi nội dung mới vào file
            std::cout << "Xóa thanh phan  có mã " << key << " thành công.\n";
            return;
        }
    }

    std::cerr << "Không tìm thấy thanh phan  có mã " << key << ".\n";
}
void Data::update(fsys::path filepath, const std::string& keyToUpdate, const std::vector<std::string>& newRow) {
    // Tạo đối tượng csvFile từ đường dẫn tệp
    csvFile file(filepath);
    
    // Đọc dữ liệu từ tệp CSV hiện có
    file.readFile();

    // Duyệt qua tất cả các hàng trong cnt để tìm môn học cần cập nhật
    bool found = false;
    for (auto& row : file.cnt) {  // Sử dụng file.cnt thay vì cnt
        // Giả sử MAMH nằm ở vị trí 0 trong mỗi hàng
        if (row.size() > 0 && row[0] == keyToUpdate) {
            // Cập nhật thông tin môn học từ newRow
            if (newRow.size() == row.size()) {
                row = newRow;  // Thay thế toàn bộ hàng bằng newRow
                found = true;
            } else {
                std::cerr << "Dữ liệu trong newRow không phù hợp với số lượng cột trong file.\n";
                return;  // Thoát khỏi hàm nếu số lượng cột không khớp
            }
            break;
        }
    }

    // Nếu không tìm thấy môn học, in ra thông báo lỗi
    if (!found) {
        std::cerr << "MAMH " << keyToUpdate << " không tìm thấy.\n";
        return;  // Thoát khỏi hàm nếu không tìm thấy môn học
    }

    // Ghi lại dữ liệu đã cập nhật vào file
    if (!file.writeFile()) {
        std::cerr << "Ghi tệp không thành công.\n";
        return;  // Thoát khỏi hàm nếu ghi file không thành công
    }

    std::cout << "Môn học đã được cập nhật thành công.\n";
}
