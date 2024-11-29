#pragma once
#include <SFML/Graphics.hpp>
using namespace std ; 


// tạo ra các ô nhập liệu
class InputField {
private:
    sf::RectangleShape shape; // tạo ra hình chữ nhật  
    sf::Text text; // văn bản bên trong do người dùng nhập vào 
    sf::Text cursor;
    // Biến này cho biết trường nhập liệu có đang được chọn hay không
    bool selected;
    
    sf::Clock clock; // tạo hiệu ứng nhấp nháy 
    bool showCursor;    //When selected, if the text cursor "|" is shown
    bool nextField;     //Automatically choose the next field

public:
    string input;
    InputField(float x, float y, float width, float height, sf::Font& font);

    InputField(float x, float y, float width, float height, sf::Font& font, string defaultText);

    void setSelected(bool isSelected);// trạng thái trường nhập liệu giữa được chọn và không được chọn.

    bool isSelected();//Phương thức này trả về trạng thái hiện tại của trường nhập liệu (được chọn hoặc không).

    bool chooseNextField();
    void processInput(sf::Event& event);//Xử lý đầu vào từ bàn phím 

    std::string getInput();// trả chuỗi hiện tại 

    bool contains(const sf::Vector2i& mousePos);//có nằm trong khu vực của trường nhập liệu hay không

    void handleMouseClick(const sf::Vector2i& mousePos);// kiểm tra xem vị trí chuột tại thời điểm nhấp có nằm trong vùng của trường nhập liệu hay không, và nếu có, nó sẽ cập nhật trạng thái trường nhập liệu là đã được chọn (selected).

    void draw(sf::RenderWindow& window); // vẽ trường nhập liệu lên

    void setText(std::string content);

    void textCursor(std::string input);
    // Trả về vị trí hiện tại của con trỏ dựa trên độ dài của chuỗi văn bản đã nhập.
    sf::Vector2f getCursorPos() {
        return text.findCharacterPos(input.length());
    }
     void setText1(const std::string& newText) {
        input = newText;
        text.setString(input); // Cập nhật văn bản hiển thị
    }
     void updateCursor() {
        if (selected) {
            if (clock.getElapsedTime().asSeconds() >= 0.7f) {
                showCursor = !showCursor;
                clock.restart();
            }
            cursor.setString(showCursor ? "|" : "");
        } else {
            cursor.setString("");
        }
        cursor.setPosition(text.getPosition().x + text.getGlobalBounds().width, text.getPosition().y);
    }
};

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;

public:
    Button(){}

    Button(float x, float y, float width, float height, const std::string& buttonText, sf::Font& font, const sf::Color& fillColor , unsigned int size);

    void draw(sf::RenderWindow& window);

    bool isClicked(const sf::Vector2i& mousePos);

    Button& operator=(const Button& rhs) {
        if (this == &rhs) return *this;
        this->shape = rhs.shape;
        this->text = rhs.text;

        return *this;
    }
     // Các phương thức khác
    std::string getText() const; // Hàm lấy chuỗi từ button
};

class Circle {
private:
    sf::CircleShape circle;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Circle(float x, float y, float radius, const std::string& pathToImg, const sf::Color& fillColor);

    bool isClicked(const sf::Vector2i& mousePos);

    void draw(sf::RenderWindow& window);
};
class Text {
private:
    sf::Text text;
    sf::Font font;
    sf::RectangleShape shape;

public:
    Text() {}

    Text(float x, float y,  float width , float height ,const std::string& content, sf::Font& font, const sf::Color& color, unsigned int size);

    std::string getContent();

    void setString(const std::string& str);

    void setPosition(float x, float y);

    void setColor(const sf::Color& color);

    void setSize(unsigned int size);

    void draw(sf::RenderWindow& window);

    Text& operator=(const Text& rhs) {
        if (this == &rhs) return *this;
        this->text = rhs.text;
        this->font = rhs.font;
        return *this;
    }
};

// class StudentButton {
// private:
//     sf::RectangleShape shape;
//     sf::Text studentId, firstName, lastName, gender, phoneNumber, seeMore;

// public:
//     Student studentData;

//     StudentButton() {}
//     StudentButton(float x, float y, const Student& info, sf::Font& font) {
//         shape.setSize(sf::Vector2f(300, 150)); // Kích thước nút
//         shape.setPosition(x, y);
//         shape.setFillColor(sf::Color::LightGray);

//         // Thiết lập văn bản cho các trường thông tin
//         studentId.setFont(font);
//         studentId.setString("Mã SV: " + info.id);
//         studentId.setPosition(x + 10, y + 10);

//         firstName.setFont(font);
//         firstName.setString("Họ: " + info.firstName);
//         firstName.setPosition(x + 10, y + 40);

//         lastName.setFont(font);
//         lastName.setString("Tên: " + info.lastName);
//         lastName.setPosition(x + 10, y + 70);

//         gender.setFont(font);
//         gender.setString("Phái: " + info.gender);
//         gender.setPosition(x + 10, y + 100);

//         phoneNumber.setFont(font);
//         phoneNumber.setString("SĐT: " + info.phoneNumber);
//         phoneNumber.setPosition(x + 10, y + 130);
//     }

//     void update(const Student& info) {
//         // Cập nhật thông tin sinh viên
//         studentData = info;
//         studentId.setString("Mã SV: " + info.id);
//         firstName.setString("Họ: " + info.firstName);
//         lastName.setString("Tên: " + info.lastName);
//         gender.setString("Phái: " + info.gender);
//         phoneNumber.setString("SĐT: " + info.phoneNumber);
//     }

//     void draw(sf::RenderWindow& window) {
//         window.draw(shape);
//         window.draw(studentId);
//         window.draw(firstName);
//         window.draw(lastName);
//         window.draw(gender);
//         window.draw(phoneNumber);
//         window.draw(seeMore);
//     }

//     bool isClicked(const sf::Vector2i& mousePos) {
//         return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
//     }
// };

// class StudentInput {
// public:
//     sf::Text labels[5]; // Nhãn cho từng trường
//     sf::RectangleShape inputBoxes[5]; // Ô nhập liệu
//     sf::Text inputTexts[5]; // Văn bản trong ô nhập liệu
//     int activeInputIndex = -1; // Chỉ số ô đang nhập liệu

//     StudentInput(sf::Font& font) {
//         std::string labelNames[] = {"Mã Sinh Viên:", "Họ:", "Tên:", "Phái:", "SĐT:"};
//         for (int i = 0; i < 5; i++) {
//             labels[i].setFont(font);
//             labels[i].setString(labelNames[i]);
//             labels[i].setPosition(50, 50 + i * 50);

//             inputBoxes[i].setSize(sf::Vector2f(200, 30));
//             inputBoxes[i].setPosition(200, 50 + i * 50);
//             inputBoxes[i].setFillColor(sf::Color::White);

//             inputTexts[i].setFont(font);
//             inputTexts[i].setString("");
//             inputTexts[i].setPosition(205, 50 + i * 50);
//             inputTexts[i].setFillColor(sf::Color::Black);
//         }
//     }

//     void draw(sf::RenderWindow& window) {
//         for (const auto& label : labels) {
//             window.draw(label);
//         }
//         for (const auto& box : inputBoxes) {
//             window.draw(box);
//         }
//         for (const auto& text : inputTexts) {
//             window.draw(text);
//         }
//     }

//     void handleInput(sf::Event& event) {
//         for (size_t i = 0; i < 5; i++) {
//             if (event.type == sf::Event::MouseButtonPressed) {
//                 if (inputBoxes[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition()))) {
//                     activeInputIndex = i; // Đánh dấu ô đang nhập liệu
//                 }
//             }

//             if (event.type == sf::Event::TextEntered && activeInputIndex == i) {
//                 if (event.text.unicode < 128) {
//                     if (event.text.unicode == '\b') { // Xóa ký tự nếu nhấn phím Backspace
//                         std::string currentText = inputTexts[i].getString();
//                         if (!currentText.empty())
//                             inputTexts[i].setString(currentText.substr(0, currentText.size() - 1));
//                     } else {
//                         inputTexts[i].setString(inputTexts[i].getString() + static_cast<char>(event.text.unicode));
//                     }
//                 }
//             }
//         }
//     }
// };

// class AllStudentsMenu {
// public:
//     sf::Text title;
//     std::vector<StudentButton> studentButtons;

//     AllStudentsMenu(float x, float y, sf::Font& font) {
//         title.setFont(font);
//         title.setString("Danh Sách Sinh Viên");
//         title.setPosition(x, y);
//     }

//     void draw(sf::RenderWindow& window) {
//         window.draw(title);
//         for (auto& button : studentButtons) {
//             button.draw(window);
//         }
//     }

//     void addStudent(const Student& student, sf::Font& font) {
//         StudentButton button(50, 100 + studentButtons.size() * 160, student, font);
//         studentButtons.push_back(button);
//     }
// }
class EditableText {
private:
    sf::Text text;
    sf::RectangleShape background;
    bool isEditing = false;
    InputField* inputField; // Trường nhập liệu
    sf::Clock clock;        // Đồng hồ cho con trỏ nhấp nháy

public:
    EditableText(float x, float y, const std::string& initialText, sf::Font& font, InputField* inputField) {
        text.setFont(font);
        text.setString(initialText);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x, y);

        // Nền màu trắng
        background.setSize(sf::Vector2f(text.getLocalBounds().width + 10, text.getLocalBounds().height + 10));
        background.setFillColor(sf::Color::White);
        background.setPosition(x - 5, y - 5);

        this->inputField = inputField;
    }

    // Kiểm tra chuột có nằm trong vùng văn bản hay không
    bool contains(const sf::Vector2i& mousePos) {
        return background.getGlobalBounds().contains(sf::Vector2f(mousePos));
    }

    // Bắt đầu chỉnh sửa
    void startEditing() {
        isEditing = true;
        inputField->setSelected(true);         // Chọn InputField
        inputField->setText1(text.getString()); // Đặt văn bản hiện tại vào InputField
    }

    // Dừng chỉnh sửa
    void stopEditing() {
        isEditing = false;
        inputField->setSelected(false);        // Bỏ chọn InputField
        text.setString(inputField->getInput()); // Lấy văn bản từ InputField
        // Cập nhật kích thước nền
        background.setSize(sf::Vector2f(text.getLocalBounds().width + 10, text.getLocalBounds().height + 10));
    }

    // Vẽ văn bản hoặc InputField
    void draw(sf::RenderWindow& window) {
        if (isEditing) {
            inputField->draw(window); // Vẽ InputField khi chỉnh sửa
        } else {
            window.draw(background); // Vẽ nền
            window.draw(text);       // Vẽ văn bản
        }
    }

    // Xử lý sự kiện nhấp chuột
    void handleMouseClick(const sf::Vector2i& mousePos) {
        if (contains(mousePos)) {
            startEditing(); // Nếu nhấp vào văn bản, bắt đầu chỉnh sửa
        } else if (isEditing) {
            stopEditing(); // Nếu nhấp ra ngoài, dừng chỉnh sửa
        }
    }

    // Cập nhật trạng thái
    void update(sf::Event& event) {
        if (isEditing) {
            inputField->processInput(event); // Xử lý nhập liệu trong InputField
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                stopEditing(); // Dừng chỉnh sửa khi nhấn Enter
            }
        }
    }
     // Lấy văn bản đã chỉnh sửa
    std::string getText() const {
        return text.getString();
    }
    //   // Tăng giá trị trong EditableText
    // void increment() {
    //     // Gọi phương thức tăng của inputField
    //     inputField->increment();
    //     // Cập nhật lại văn bản
    //     text.setString(inputField->getInput());
    //     // Cập nhật lại kích thước nền
    //     background.setSize(sf::Vector2f(text.getLocalBounds().width + 10, text.getLocalBounds().height + 10));
    // }

    // // Giảm giá trị trong EditableText
    // void decrement() {
    //     // Gọi phương thức giảm của inputField
    //     inputField->decrement();
    //     // Cập nhật lại văn bản
    //     text.setString(inputField->getInput());
    //     // Cập nhật lại kích thước nền
    //     background.setSize(sf::Vector2f(text.getLocalBounds().width + 10, text.getLocalBounds().height + 10));
    // }
};
class Dropdown {
private:
    sf::RectangleShape mainBox;
    std::vector<sf::RectangleShape> options;
    std::vector<sf::Text> optionTexts;
    bool isExpanded = false;
    sf::Font font;
    InputField* inputField; // Pointer to InputField
    std::vector<std::string> items;
    std::string selectedOption;

public:
    Dropdown(float x, float y, float width, float height, const sf::Font& font, const std::vector<std::string>& items, InputField* inputField)
        : inputField(inputField), items(items), selectedOption("") {
        this->font = font;

        mainBox.setPosition(x, y);
        mainBox.setSize(sf::Vector2f(width, height));
        mainBox.setFillColor(sf::Color(200, 200, 200)); // Màu nền chính
        mainBox.setOutlineThickness(1);
        mainBox.setOutlineColor(sf::Color::Black);

        // Tạo các tùy chọn
        for (size_t i = 0; i < items.size(); ++i) {
            sf::RectangleShape optionBox;
            optionBox.setSize({width, height});
            optionBox.setPosition(x, y + (i + 1) * height); // Các hộp bên dưới
            optionBox.setFillColor(sf::Color(240, 240, 240)); // Màu nền tùy chọn
            optionBox.setOutlineThickness(1);
            optionBox.setOutlineColor(sf::Color::Black);

            sf::Text optionText;
            optionText.setFont(this->font);
            optionText.setString(items[i]);
            optionText.setCharacterSize(14);
            optionText.setFillColor(sf::Color::Black);
            optionText.setPosition(x + 5.f, y + (i + 1) * height + 5.f); // Căn chỉnh văn bản trong mỗi tùy chọn

            optionTexts.push_back(optionText);
            options.push_back(optionBox);
        }
    }

    // Hàm hiển thị danh sách thả xuống
    void toggleDropdown() {
        isExpanded = !isExpanded;
    }

    // Hàm kiểm tra xem có click vào danh sách thả xuống không
    void handleClick(const sf::Vector2i& mousePos) {
        if (inputField->contains(mousePos)) {
            toggleDropdown(); // Mở dropdown khi click vào trường nhập liệu
        }

        if (isExpanded) {
            for (size_t i = 0; i < options.size(); ++i) {
                if (options[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                    selectedOption = items[i]; // Cập nhật lựa chọn
                    inputField->setText1(selectedOption); // Cập nhật trường nhập liệu với lựa chọn
                    toggleDropdown(); // Đóng dropdown sau khi chọn
                    break;
                }
            }
        }
    }

    // Hàm vẽ
    void draw(sf::RenderWindow& window) {
        window.draw(mainBox);
        if (isExpanded) {
            for (auto& option : options) {
                window.draw(option);
            }
            for (auto& optionText : optionTexts) {
                window.draw(optionText);
            }
        }
    }
};


