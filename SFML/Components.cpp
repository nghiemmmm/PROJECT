#include "Components.h"
#include<iostream>
#include<math.h>
InputField::InputField(float x, float y, float width, float height, sf::Font& font)
{
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::White);
    shape.setOutlineThickness(0.f);
    //shape.setOutlineColor(sf::Color::Black);

    text.setFont(font);
    text.setCharacterSize(int(height * 0.7));
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 5.f, y + 5.f);

    cursor.setFont(font);
    cursor.setCharacterSize(int(height * 0.7));
    cursor.setFillColor(sf::Color::Black);

    nextField = false;
    showCursor = false;
    selected = false;
}

InputField::InputField(float x, float y, float width, float height, sf::Font& font, std::string defaultText)
{  //initiate inputfield which already had text, like in courses's scoreboard in staff view
    // giống như show bang diem 
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::White);
    shape.setOutlineThickness(0.f);
    //shape.setOutlineColor(sf::Color::Black);

    text.setFont(font);
    text.setCharacterSize(int(height * 0.7));
    text.setFillColor(sf::Color::Black);
    text.setPosition(x + 5.f, y + 5.f);

    cursor.setFont(font);
    cursor.setCharacterSize(int(height * 0.7));
    cursor.setFillColor(sf::Color::Black);

    //set default text
    input = defaultText;
    text.setString(input);

    nextField = false;
    showCursor = false;
    selected = false;
}

void InputField::setSelected(bool isSelected)
{
    selected = isSelected;
    //if (selected)
    //    shape.setOutlineColor(sf::Color::Blue);
    //else
    //    shape.setOutlineColor(sf::Color::Black);
}

bool InputField::isSelected(){
    return selected;
}

bool InputField::chooseNextField()
{
    if (nextField) {
        nextField = false;
        return true;
    }
    return false;
}

void InputField::processInput(sf::Event& event)
{
    if (selected) {
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == '\b') { // Handle backspace
                if (!input.empty())
                    input.pop_back();
            }
            else if (event.text.unicode == '\r') {  // Set unselected for ENTER input
                selected = false;
                nextField = true;
            }
            else if (event.text.unicode == '\t') {  // Set unselected for TAB input
                selected = false;
                nextField = true;
            }
            else if (event.text.unicode < 128) {
                input += static_cast<char>(event.text.unicode);
            }
        }
    }
    else text.setString(input);
    setSelected(selected);
}

std::string InputField::getInput(){
    return input;
}

bool InputField::contains(const sf::Vector2i& mousePos){
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

void InputField::handleMouseClick(const sf::Vector2i& mousePos){
    selected = contains(mousePos);
    setSelected(selected);
}

void InputField::draw(sf::RenderWindow& window){
    window.draw(shape);
    window.draw(text);
    window.draw(cursor);
}

void InputField::setText(std::string content){
    text.setString(content);
}


void InputField::textCursor(std::string input){
    text.setString(input);
    cursor.setPosition(getCursorPos());

    if (!showCursor) {
        if (clock.getElapsedTime().asSeconds() >= 0.7f) {
            cursor.setString("|");
            clock.restart();
            showCursor = true;
        }
    }
    else {
        if (clock.getElapsedTime().asSeconds() >= 0.7f) {
            cursor.setString("");
            clock.restart();
            showCursor = false;
        }
    }
}

Button::Button(float x, float y, float width, float height, const std::string& buttonText, sf::Font& font, const sf::Color& fillColor , unsigned int size)
{
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(fillColor);
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(sf::Color::Black);

    text.setFont(font);
    text.setString(buttonText);
    text.setCharacterSize(size); 
    //text.setCharacterSize(int(height / 2 + 5));
    text.setFillColor(sf::Color::White);
    text.setPosition(x + 10.f, y + 10.f);

}

void Button::draw(sf::RenderWindow& window){
    window.draw(shape);
    window.draw(text);
}

bool Button::isClicked(const sf::Vector2i& mousePos){
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}
std::string Button::getText() const {
    return text.getString(); // Lấy chuỗi từ sf::Text
}

Circle::Circle(float x, float y, float radius, const std::string& pathToImg, const sf::Color& fillColor){
    // Initialize circle
    circle.setPosition(x, y);
    circle.setRadius(radius);
    circle.setFillColor(fillColor);
    circle.setOrigin(radius, radius); // Set origin to center
    circle.setOutlineThickness(1.f);
    circle.setOutlineColor(sf::Color::Black);

    // Load texture
    if (!texture.loadFromFile(pathToImg)) {
        std::cout << "Failed to load image";
        throw std::runtime_error("Failed to load image");
    }

    // Initialize sprite with texture
    sprite.setTexture(texture);
    sf::Vector2u textureSize = texture.getSize();
    sprite.setOrigin(textureSize.x / 2.f, textureSize.y / 2.f); // Set origin to center


    sprite.setPosition(x, y);
}

bool Circle::isClicked(const sf::Vector2i& mousePos){
    sf::Vector2f circleCenter = circle.getPosition();
    float circleRadius = circle.getRadius();

    // Calculate distance between mouse position and circle center
    double distance = std::sqrt(std::pow(mousePos.x - circleCenter.x, 2) + std::pow(mousePos.y - circleCenter.y, 2));

    // If distance is less than or equal to circle radius, the mouse is inside the circle
    return (distance <= circleRadius);
}

void Circle::draw(sf::RenderWindow& window){
    window.draw(circle);
    window.draw(sprite);
}

Text::Text(float x, float y,  float width , float height ,const std::string& content, sf::Font& font, const sf::Color& color, unsigned int size){
     // Thiết lập hình chữ nhật
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color(200, 200, 200, 150)); // Màu nền nhẹ với độ trong suốt
    shape.setOutlineThickness(2.f);
    shape.setOutlineColor(sf::Color::Black);

    // Thiết lập văn bản
    text.setFont(font);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::Black); // Màu chữ
    text.setString(content);

    // Lấy giới hạn của văn bản để căn giữa
    sf::FloatRect textBounds = text.getLocalBounds();
    float textX = x + (width - textBounds.width) / 2 - textBounds.left;
    float textY = y + (height - textBounds.height) / 2 - textBounds.top;

    // Đặt vị trí văn bản
    text.setPosition(textX, textY);
}

std::string Text::getContent(){
    return text.getString();
}

void Text::setString(const std::string& str){
    text.setString(str);
}

void Text::setPosition(float x, float y){
    text.setPosition(x, y);
}

void Text::setColor(const sf::Color& color){
    text.setFillColor(color);
}

void Text::setSize(unsigned int size){
    text.setCharacterSize(size);
}

void Text::draw(sf::RenderWindow& window){
    window.draw(text);
}

