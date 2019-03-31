#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(
            VideoMode(1920, 1080), "Tic-Tac-Toe"); //, Style::Fullscreen);
    RectangleShape bar1(Vector2f(300, 80));
    RectangleShape bar2(Vector2f(300, 80));
    bar1.setPosition(
            window.getSize().x / 2 - bar1.getSize().x / 2,
            window.getSize().y / 2 - bar1.getSize().y / 2 - 150);
    bar2.setPosition(
            window.getSize().x / 2 - bar2.getSize().x / 2,
            window.getSize().y / 2 - bar2.getSize().y / 2);

    Font font;
    font.loadFromFile("arial.ttf");
    Text text1("Start game", font, 30);
    Text text2("Exit", font, 30);
    text1.setStyle(Text::Bold);
    text1.setFillColor(Color::Black);
    text2.setStyle(Text::Bold);
    text2.setFillColor(Color::Black);
    text1.setPosition(
            window.getSize().x / 2 - bar1.getSize().x / 4,
            window.getSize().y / 2 - bar1.getSize().y / 4 - 150);
    text2.setPosition(
            window.getSize().x / 2 - bar2.getSize().x / 4 + 40,
            window.getSize().y / 2 - bar2.getSize().y / 4);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if ((event.type == Event::Closed)
                || (event.type == Event::KeyPressed
                    && event.key.code == Keyboard::Escape)) {
                window.close();
            }
        }
        window.clear(Color::White);
        bar1.setFillColor(Color::Cyan);
        bar1.setOutlineThickness(5);
        bar1.setOutlineColor(Color::Black);
        bar2.setFillColor(Color::Cyan);
        bar2.setOutlineThickness(5);
        bar2.setOutlineColor(Color::Black);
        window.draw(bar1);
        window.draw(bar2);
        window.draw(text1);
        window.draw(text2);
        bool onMenu = 1;
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(782, 332, 304, 90)
                       .contains(Mouse::getPosition(window))) {
            onMenu = 0;
        }
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(782, 475, 304, 90)
                       .contains(Mouse::getPosition(window))) {
            window.close();
        }
        window.display();
    }
    return 0;
}