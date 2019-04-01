#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <thread>

using namespace sf;
using namespace std;

RenderWindow
        window(VideoMode(1920, 1080), "Tic-Tac-Toe"); //, Style::Fullscreen);

bool xOn = 0;
int dif = 0;

void difficulty()
{
    RectangleShape bar(Vector2f(300, 80));
    bar.setFillColor(Color::Cyan);
    bar.setOutlineThickness(5);
    bar.setOutlineColor(Color::Black);
    bar.setPosition(
            window.getSize().x / 2 - bar.getSize().x / 2,
            window.getSize().y / 2 - bar.getSize().y / 2 - 200);
    RectangleShape bar1(Vector2f(300, 80));
    bar1.setFillColor(Color::Cyan);
    bar1.setOutlineThickness(5);
    bar1.setOutlineColor(Color::Black);
    bar1.setPosition(
            window.getSize().x / 2 - bar1.getSize().x / 2,
            window.getSize().y / 2 - bar1.getSize().y / 2 - 50);
    RectangleShape bar2(Vector2f(300, 80));
    bar2.setFillColor(Color::Cyan);
    bar2.setOutlineThickness(5);
    bar2.setOutlineColor(Color::Black);
    bar2.setPosition(
            window.getSize().x / 2 - bar2.getSize().x / 2,
            window.getSize().y / 2 - bar2.getSize().y / 2 + 100);
    RectangleShape bar3(Vector2f(50, 50));
    bar3.setFillColor(Color::Cyan);
    bar3.setOutlineThickness(5);
    bar3.setOutlineColor(Color::Black);
    bar3.setPosition(1700, 900);
    Font font;
    font.loadFromFile("arial.ttf");
    Text text("Choose difficulty", font, 45);
    text.setStyle(Text::Bold);
    text.setFillColor(Color::Black);
    text.setPosition(200, window.getSize().y / 2 - 450);
    Text text1("Two thought,\ntwo decided", font, 30);
    text1.setStyle(Text::Bold);
    text1.setFillColor(Color::Black);
    text1.setPosition(
            window.getSize().x / 2 - bar.getSize().x / 2 + 65,
            window.getSize().y / 2 - bar.getSize().y / 2 - 200);
    Text text2("Freebie", font, 30);
    text2.setStyle(Text::Bold);
    text2.setFillColor(Color::Black);
    text2.setPosition(
            window.getSize().x / 2 - bar1.getSize().x / 2 + 95,
            window.getSize().y / 2 - bar1.getSize().y / 2 - 30);
    Text text3("2200 rating", font, 30);
    text3.setStyle(Text::Bold);
    text3.setFillColor(Color::Black);
    text3.setPosition(
            window.getSize().x / 2 - bar2.getSize().x / 2 + 75,
            window.getSize().y / 2 - bar2.getSize().y / 2 + 110);
    Text text4("Lead?", font, 30);
    text4.setStyle(Text::Bold);
    text4.setFillColor(Color::Black);
    text4.setPosition(1600, 900);
    Image ximage;
    ximage.loadFromFile("i1.png");
    ximage.createMaskFromColor(Color::White);
    Texture xtexture;
    xtexture.loadFromImage(ximage);
    Sprite xsprite;
    xsprite.setTexture(xtexture);
    xsprite.setPosition(1700, 900);
    while (1) {
        window.clear(Color::White);
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            return;
        }
        window.draw(text);
        window.draw(bar);
        window.draw(text1);
        window.draw(bar1);
        window.draw(text2);
        window.draw(bar2);
        window.draw(text3);
        window.draw(bar3);
        window.draw(text4);
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(782, 280, 304, 90)
                       .contains(Mouse::getPosition(window))) {
            dif = 1;
            return;
        }
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(782, 433, 304, 90)
                       .contains(Mouse::getPosition(window))) {
            dif = 2;
            return;
        }
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(782, 583, 304, 90)
                       .contains(Mouse::getPosition(window))) {
            dif = 3;
            return;
        }
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(1700, 900, 55, 55)
                       .contains(Mouse::getPosition(window))) {
            this_thread::sleep_for(chrono::milliseconds(80));
            xOn = 1 - xOn;
        }
        if (xOn == 1) {
            window.draw(xsprite);
        }
        window.display();
    }
}

void menu()
{
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
    while (1) {
        window.clear(Color::White);
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(782, 332, 304, 90)
                       .contains(Mouse::getPosition(window))) {
            this_thread::sleep_for(chrono::milliseconds(100));
            difficulty();
            if (dif != 0) {
                return;
            }
        }
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(782, 475, 304, 90)
                       .contains(Mouse::getPosition(window))) {
            exit(0);
        }
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
        window.display();
    }
}

int main()
{
    menu();
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
        window.display();
    }
    return 0;
}