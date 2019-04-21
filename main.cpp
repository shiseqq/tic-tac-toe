#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>
#include <vector>

using namespace sf;
using namespace std;

RenderWindow window(VideoMode(1920, 1080), "Tic-Tac-Toe", Style::Fullscreen);
bool xOn = 0;
vector<vector<char>> m(3, vector<char>(3, ' '));
int iks, igr, whowin;

void menu()
{
    srand(time(NULL));
    iks = rand() % 3;
    igr = rand() % 3;
    RectangleShape bar1(Vector2f(300, 80));
    RectangleShape bar2(Vector2f(300, 80));
    bar1.setPosition(
            window.getSize().x / 2 - bar1.getSize().x / 2,
            window.getSize().y / 2 - bar1.getSize().y / 2 - 150);
    bar2.setPosition(
            window.getSize().x / 2 - bar2.getSize().x / 2,
            window.getSize().y / 2 - bar2.getSize().y / 2);
    RectangleShape bar3(Vector2f(50, 50));
    bar3.setFillColor(Color::Green);
    bar3.setPosition(1700, 900);
    Font font;
    font.loadFromFile("arial.ttf");
    Text text1("Start game", font, 30);
    Text text2("Exit", font, 30);
    text1.setFillColor(Color::White);
    text2.setFillColor(Color::White);
    text1.setPosition(
            window.getSize().x / 2 - bar1.getSize().x / 4,
            window.getSize().y / 2 - bar1.getSize().y / 4 - 150);
    text2.setPosition(
            window.getSize().x / 2 - bar2.getSize().x / 4 + 40,
            window.getSize().y / 2 - bar2.getSize().y / 4);
    Text text4("Lead?", font, 30);
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
    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            exit(0);
        }
        window.clear(Color::White);
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(782, 332, 304, 90)
                       .contains(Mouse::getPosition(window))) {
            this_thread::sleep_for(chrono::milliseconds(100));
            return;
        }
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(782, 475, 304, 90)
                       .contains(Mouse::getPosition(window))) {
            exit(0);
        }
        bar1.setFillColor(Color::Green);
        bar2.setFillColor(Color::Green);
        window.draw(bar1);
        window.draw(bar2);
        window.draw(text1);
        window.draw(text2);
        window.draw(bar3);
        window.draw(text4);
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

char check(void)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (m[i][0] == m[i][1] && m[i][0] == m[i][2]) {
            return m[i][0];
        }
    }

    for (i = 0; i < 3; i++) {
        if (m[0][i] == m[1][i] && m[0][i] == m[2][i]) {
            return m[0][i];
        }
    }

    if (m[0][0] == m[1][1] && m[1][1] == m[2][2]) {
        return m[0][0];
    }
    if (m[0][2] == m[1][1] && m[1][1] == m[2][0]) {
        return m[0][2];
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (m[i][j] == ' ') {
                return ' ';
            }
            if (i == 2 && j == 2) {
                return '.';
            }
        }
    }
}

void get_computer_move(void)
{
    int i = 0, j = 0;

    for (i = 0; i < 3; i++) {
        if (m[i][0] == m[i][1] && m[i][2] == ' ' && m[i][0] != ' ') {
            if (xOn) {
                m[i][2] = 'O';
            } else
                m[i][2] = 'X';
            return;
        }
    }

    for (i = 0; i < 3; i++) {
        if (m[0][i] == m[1][i] && m[2][i] == ' ' && m[0][i] != ' ') {
            if (xOn) {
                m[2][i] = 'O';
            } else
                m[2][i] = 'X';
            return;
        }
    }

    if (m[0][0] == m[1][1] && m[2][2] == ' ' && m[0][0] != ' ') {
        if (xOn) {
            m[2][2] = 'O';
        } else
            m[2][2] = 'X';
        return;
    }
    if (m[0][2] == m[1][1] && m[2][0] == ' ' && m[0][2] != ' ') {
        if (xOn) {
            m[2][0] = 'O';
        } else
            m[2][0] = 'X';
        return;
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (m[i][j] == ' ')
                break;
        }
        if (m[i][j] == ' ')
            break;
    }
    if (xOn == 0) {
        m[i][j] = 'X';
    } else
        m[i][j] = 'O';
}

void matrix()
{
    Image pimage;
    pimage.loadFromFile("pole.png");
    Texture ptexture;
    ptexture.loadFromImage(pimage);
    Sprite pole;
    pole.setTexture(ptexture);
    pole.setPosition(460, 35);
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
    while (1) {
        window.clear(Color::White);
        window.draw(pole);
        if (m[0][0] == 'X') {
            window.draw(x11);
        } else if (m[0][0] == 'O') {
            window.draw(o11);
        }
        if (m[0][1] == 'X') {
            window.draw(x12);
        } else if (m[0][1] == 'O') {
            window.draw(o12);
        }
        if (m[0][2] == 'X') {
            window.draw(x13);
        } else if (m[0][2] == 'O') {
            window.draw(o13);
        }
        if (m[1][0] == 'X') {
            window.draw(x21);
        } else if (m[1][0] == 'O') {
            window.draw(o21);
        }
        if (m[1][1] == 'X') {
            window.draw(x22);
        } else if (m[1][1] == 'O') {
            window.draw(o22);
        }
        if (m[1][2] == 'X') {
            window.draw(x23);
        } else if (m[1][2] == 'O') {
            window.draw(o23);
        }
        if (m[2][0] == 'X') {
            window.draw(x31);
        } else if (m[2][0] == 'O') {
            window.draw(o31);
        }
        if (m[2][1] == 'X') {
            window.draw(x32);
        } else if (m[2][1] == 'O') {
            window.draw(o32);
        }
        if (m[2][2] == 'X') {
            window.draw(x33);
        } else if (m[2][2] == 'O') {
            window.draw(o33);
        }
        window.display();
        return;
    }
}

void fin()
{
    Font font;
    font.loadFromFile("arial.ttf");
    Text t1("LOSE", font, 100);
    t1.setStyle(Text::Bold);
    t1.setFillColor(Color::Black);
    t1.setPosition(858, 300);
    Text t2("WIN", font, 100);
    t2.setStyle(Text::Bold);
    t2.setFillColor(Color::Black);
    t2.setPosition(900, 300);
    Text t3("TIE", font, 100);
    t3.setStyle(Text::Bold);
    t3.setFillColor(Color::Black);
    t3.setPosition(900, 300);
    RectangleShape bar(Vector2f(300, 80));
    bar.setFillColor(Color::Green);
    bar.setPosition(840, 500);
    RectangleShape bar1(Vector2f(300, 80));
    bar1.setFillColor(Color::Green);
    bar1.setPosition(840, 650);
    RectangleShape bar2(Vector2f(300, 80));
    bar2.setFillColor(Color::Green);
    bar2.setPosition(840, 800);
    Text text2("Menu", font, 30);
    Text text3("Exit", font, 30);
    text2.setFillColor(Color::White);
    text3.setFillColor(Color::White);
    text2.setPosition(950, 520);
    text3.setPosition(955, 670);
    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            exit(0);
        }
        window.clear(Color::White);
        if (whowin == 1) {
            window.draw(t1);
        } else if (whowin == 2) {
            window.draw(t2);
        } else
            window.draw(t3);
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(840, 500, 300, 80)
                       .contains(Mouse::getPosition(window))) {
            system("/home/shise/myProj/tic-tac/tic-tac-toe.exe");
            exit(0);
        }
        if (Mouse::isButtonPressed(Mouse::Left)
            && IntRect(840, 650, 300, 80)
                       .contains(Mouse::getPosition(window))) {
            exit(0);
        }
        window.draw(bar);
        window.draw(bar1);
        window.draw(text2);
        window.draw(text3);
        window.display();
    }
}

int main()
{
    menu();
    this_thread::sleep_for(chrono::milliseconds(100));
    while (window.isOpen()) {
        if (xOn == 0) {
            m[iks][igr] = 'X';
            matrix();
            while (1) {
                if (check() != ' ') {
                    this_thread::sleep_for(chrono::milliseconds(500));
                    if (check() == 'X') {
                        whowin = 1;
                    } else if (check() == 'O') {
                        whowin = 2;
                    } else
                        whowin = 3;
                    fin();
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(480, 60, 304, 285)
                               .contains(Mouse::getPosition(window))
                    && m[0][0] == ' ') {
                    m[0][0] = 'O';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(800, 60, 325, 285)
                               .contains(Mouse::getPosition(window))
                    && m[0][1] == ' ') {
                    m[0][1] = 'O';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(1140, 60, 325, 285)
                               .contains(Mouse::getPosition(window))
                    && m[0][2] == ' ') {
                    m[0][2] = 'O';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(480, 368, 304, 312)
                               .contains(Mouse::getPosition(window))
                    && m[1][0] == ' ') {
                    m[1][0] = 'O';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(800, 368, 325, 312)
                               .contains(Mouse::getPosition(window))
                    && m[1][1] == ' ') {
                    m[1][1] = 'O';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(1140, 368, 300, 312)
                               .contains(Mouse::getPosition(window))
                    && m[1][2] == ' ') {
                    m[1][2] = 'O';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(480, 702, 305, 315)
                               .contains(Mouse::getPosition(window))
                    && m[2][0] == ' ') {
                    m[2][0] = 'O';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(800, 702, 324, 315)
                               .contains(Mouse::getPosition(window))
                    && m[2][1] == ' ') {
                    m[2][1] = 'O';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(1144, 702, 295, 315)
                               .contains(Mouse::getPosition(window))
                    && m[2][2] == ' ') {
                    m[2][2] = 'O';
                    break;
                }
            }
            matrix();
            if (check() != ' ') {
                this_thread::sleep_for(chrono::milliseconds(500));
                if (check() == 'X') {
                    whowin = 1;
                } else if (check() == 'O') {
                    whowin = 2;
                } else
                    whowin = 3;
                fin();
            }
            get_computer_move();
            this_thread::sleep_for(chrono::milliseconds(100));
        } else {
            matrix();
            while (1) {
                if (check() != ' ') {
                    this_thread::sleep_for(chrono::milliseconds(500));
                    if (check() == 'O') {
                        whowin = 1;
                    } else if (check() == 'X') {
                        whowin = 2;
                    } else
                        whowin = 3;
                    fin();
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(480, 60, 304, 285)
                               .contains(Mouse::getPosition(window))
                    && m[0][0] == ' ') {
                    m[0][0] = 'X';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(800, 60, 325, 285)
                               .contains(Mouse::getPosition(window))
                    && m[0][1] == ' ') {
                    m[0][1] = 'X';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(1140, 60, 325, 285)
                               .contains(Mouse::getPosition(window))
                    && m[0][2] == ' ') {
                    m[0][2] = 'X';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(480, 368, 304, 312)
                               .contains(Mouse::getPosition(window))
                    && m[1][0] == ' ') {
                    m[1][0] = 'X';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(800, 368, 325, 312)
                               .contains(Mouse::getPosition(window))
                    && m[1][1] == ' ') {
                    m[1][1] = 'X';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(1140, 368, 300, 312)
                               .contains(Mouse::getPosition(window))
                    && m[1][2] == ' ') {
                    m[1][2] = 'X';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(480, 702, 305, 315)
                               .contains(Mouse::getPosition(window))
                    && m[2][0] == ' ') {
                    m[2][0] = 'X';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(800, 702, 324, 315)
                               .contains(Mouse::getPosition(window))
                    && m[2][1] == ' ') {
                    m[2][1] = 'X';
                    break;
                }
                if (Mouse::isButtonPressed(Mouse::Left)
                    && IntRect(1144, 702, 295, 315)
                               .contains(Mouse::getPosition(window))
                    && m[2][2] == ' ') {
                    m[2][2] = 'X';
                    break;
                }
            }
            matrix();
            if (check() != ' ') {
                this_thread::sleep_for(chrono::milliseconds(500));
                if (check() == 'O') {
                    whowin = 1;
                } else if (check() == 'X') {
                    whowin = 2;
                } else
                    whowin = 3;
                fin();
            }
            get_computer_move();
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
    return 0;
}