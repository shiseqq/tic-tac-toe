#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main()
{
    RenderWindow window(
            VideoMode(1920, 1080), "Tic-Tac-Toe"); //, Style::Fullscreen);
    RectangleShape bar(Vector2f(300, 80));
    bar.setPosition(
            window.getSize().x / 2 - bar.getSize().x / 2,
            window.getSize().y / 2 - bar.getSize().y / 2 - 150);
    Font font;
    font.loadFromFile("arial.ttf");
    Text text("Start game", font, 30);
    text.setStyle(Text::Bold);
    text.setFillColor(Color::Black);
    text.setPosition(
            window.getSize().x / 2 - bar.getSize().x / 4,
            window.getSize().y / 2 - bar.getSize().y / 4 - 150);
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
        bar.setFillColor(Color::Cyan);
        bar.setOutlineThickness(5);
        bar.setOutlineColor(Color::Black);
        window.draw(bar);
        window.draw(text);
        window.display();
    }
    return 0;
}