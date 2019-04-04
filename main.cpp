#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

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
            this_thread::sleep_for(chrono::milliseconds(100));
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
    // menu();
    dif = 1;
    vector<vector<bool>> usr(4, vector<bool>(4, 0)), pc(4, vector<bool>(4, 0));
    Image pimage;
    pimage.loadFromFile("pole.png");
    Texture ptexture;
    ptexture.loadFromImage(pimage);
    Sprite pole;
    pole.setTexture(ptexture);
    pole.setPosition(460, 35);
    /*X********************************************************************************************************************************/
    Image ximage;
    ximage.loadFromFile("x.png");
    Texture xtexture;
    xtexture.loadFromImage(ximage);
    Sprite x11;
    x11.setTexture(xtexture);
    x11.setPosition(505, 70);
    Sprite x12;
    x12.setTexture(xtexture);
    x12.setPosition(835, 70);
    Sprite x13;
    x13.setTexture(xtexture);
    x13.setPosition(1165, 70);
    Sprite x21;
    x21.setTexture(xtexture);
    x21.setPosition(505, 395);
    Sprite x22;
    x22.setTexture(xtexture);
    x22.setPosition(835, 395);
    Sprite x23;
    x23.setTexture(xtexture);
    x23.setPosition(1165, 395);
    Sprite x31;
    x31.setTexture(xtexture);
    x31.setPosition(505, 720);
    Sprite x32;
    x32.setTexture(xtexture);
    x32.setPosition(835, 720);
    Sprite x33;
    x33.setTexture(xtexture);
    x33.setPosition(1165, 720);
    /*O********************************************************************************************************************************/
    Image oimage;
    oimage.loadFromFile("o.png");
    Texture otexture;
    otexture.loadFromImage(oimage);
    Sprite o11;
    o11.setTexture(otexture);
    o11.setPosition(503, 72);
    Sprite o12;
    o12.setTexture(otexture);
    o12.setPosition(833, 72);
    Sprite o13;
    o13.setTexture(otexture);
    o13.setPosition(1163, 72);
    Sprite o21;
    o21.setTexture(otexture);
    o21.setPosition(503, 397);
    Sprite o22;
    o22.setTexture(otexture);
    o22.setPosition(833, 397);
    Sprite o23;
    o23.setTexture(otexture);
    o23.setPosition(1163, 397);
    Sprite o31;
    o31.setTexture(otexture);
    o31.setPosition(503, 733);
    Sprite o32;
    o32.setTexture(otexture);
    o32.setPosition(833, 733);
    Sprite o33;
    o33.setTexture(otexture);
    o33.setPosition(1163, 733);
    /*PROGRAM************************************!!!!!!!!!!!!!!!!!!!!!!!!!!!ON_WORKING!!!!!!!!!!!!!!!!!!!!**********************/
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
        window.draw(pole);
        if (xOn == 0) {
            if (dif == 1) {
                pc[1][1] = 1;
                if (pc[1][1]) {
                    window.draw(x11);
                } else if (usr[1][1]) {
                    window.draw(o11);
                }
                if (pc[1][2]) {
                    window.draw(x12);
                } else if (usr[1][2]) {
                    window.draw(o12);
                }
                if (pc[1][3]) {
                    window.draw(x13);
                } else if (usr[1][3]) {
                    window.draw(o13);
                }
                if (pc[2][1]) {
                    window.draw(x21);
                } else if (usr[2][1]) {
                    window.draw(o21);
                }
                if (pc[2][2]) {
                    window.draw(x22);
                } else if (usr[2][2]) {
                    window.draw(o22);
                }
                if (pc[2][3]) {
                    window.draw(x23);
                } else if (usr[2][3]) {
                    window.draw(o23);
                }
                if (pc[3][1]) {
                    window.draw(x31);
                } else if (usr[3][1]) {
                    window.draw(o31);
                }
                if (pc[3][2]) {
                    window.draw(x32);
                } else if (usr[3][2]) {
                    window.draw(o32);
                }
                if (pc[3][3]) {
                    window.draw(x33);
                } else if (usr[3][3]) {
                    window.draw(o33);
                }
                window.display();
                cout << Mouse::getPosition().x << " " << Mouse::getPosition().y
                     << endl;
                while (!Mouse::isButtonPressed(Mouse::Left)) {
                    /**********************************!!!!!!!!!!!!!!!!!!!NEEED_FIX!!!!!!!!!!!!!*************/
                    if (IntRect(800, 60, 325, 285)
                                .contains(Mouse::getPosition(window))
                        && !usr[1][2] && !pc[1][2]) {
                        this_thread::sleep_for(chrono::milliseconds(100));
                        usr[1][2] = 1;
                    }
                }
                if (!usr[1][2] && !usr[1][3]) {
                    pc[1][2] = 1;
                } else {
                    pc[2][1] = 1;
                }
            }
        } else {
        }
        /*PROGRAM************************************!!!!!!!!!!!!!!!!!!!!!!!!!!!ON_WORKING!!!!!!!!!!!!!!!!!!!!**********************/
        window.display();
    }
    return 0;
}