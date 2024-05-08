#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

const int screenWidth = 30;
const int screenHeight = 20;
int rocketX = screenWidth / 2;
int rocketY = screenHeight - 1;
int obstackleX = 0;
int obstackleY = 0;
int obstacle2X = 0;
int obstacle2Y = 0;
int obstacle3X = 0;
int obstacle3Y = 0;
int obstacle4X = 0;
int obstacle4Y = 0;
int coins = 0;
int gold = 0;
bool GameOver = false;
int score = 0;
int bestscore = 0;
char skin = '*';
char skin2 = 'O';

void start() {
    system("cls");
    cout << "\033[33m     *                                                         *\n ";
    cout << "                                                      *\n ";
    cout << "                  *                                                           *\n ";
    cout << "  *\n ";
    cout << "                                       *\n";
    cout << "      *                            ROCKET ESCAPE \n";
    cout << "                       *                                              *\n";
    cout << "                                                          *\n ";
    cout << "         *                                                                      *\n ";
    cout << "                             *                   *\n\033[0m";
    cout << "\n--------------------------------------------------------------------------------------\n";
    cout << "         EASY (E)         |           NORMAL (N)             |           HARD (H)\n";
    cout << "--------------------------------------------------------------------------------------\n";
    cout << "       SKINS(S)           |           LOOT (L)               |           EXIT (X)	\n";
    cout << "--------------------------------------------------------------------------------------\n";
    cout << "\n\n\n";
    cout << "\033[34m                           |     SILVER COINS: " << coins << endl;
    cout << "\033[0m";
    cout << "                           |\n";
    cout << "\033[33m                           |     GOLD COINS: " << gold << endl;
    cout << "\033[0m";
    cout << "                           |\n";
    cout << "\033[31m                           |     BEST SCORE:" << bestscore << endl;
    cout << "\033[0m";
}

void skins() {
    system("cls");
    cout << "\033[35m------------------------------------ROCKET-SKINS-------------------------------------------\n\n\033[0m";
    cout << "              1 (*) [ 0 silver ]             2 (@) [ 5 silver ]               3 (^) [ 5 silver ]\n\n ";
    cout << "             4 (+) [ 10 silver ]              5 ($) [ 10 silver ]               6 (#) [ 15 silver ]\n";
    cout << "\033[35m------------------------------------OBSTACLE-SKIN------------------------------------------\n\033[0m";
    cout << "              7 (0) [ 0 gold ]                       8 (|) [ 15 gold ]\n";
    cout << "\n\nDONE (D)\n";
    cout << "\n\n\n\033[34m                       SILVER COINS: " << coins << endl;
    cout << "\033[33m                        GOLD COINS: " << gold << endl;
    cout << "\033[0m";
    string chooseskin;

    while (true) {
        cin >> chooseskin;

        if (chooseskin == "1") {
            skin = '*';
            cout << "PURCHASED\n";
        }
        else if (chooseskin == "7") {
            skin2 = 'O';
            cout << "PURCHASED\n";
        }
        else if (chooseskin == "8") {
            if (gold > 14) {
                gold = gold - 15;
                skin2 = '|';
                cout << "PURCHASED\n";
            }
            else {
                cout << "YOU DON'T HAVE ENOUGH COINS\n ";
                skin = 'O';
            }
        }
        else if (chooseskin == "2") {
            if (coins > 4) {
                coins = coins - 5;
                skin = '@';
                cout << "PURCHASED\n";
            }
            else {
                cout << "YOU DON'T HAVE ENOUGH COINS\n ";
                skin = '*';
            }

        }
        else if (chooseskin == "3") {
            if (coins > 4) {
                coins = coins - 5;
                skin = '^';
                cout << "PURCHASED\n";
            }
            else {
                cout << "YOU DON'T HAVE ENOUGH COINS\n";
                skin = '*';
            }
        }
        else if (chooseskin == "4") {
            if (coins > 9) {
                coins = coins - 10;
                skin = '+';
                cout << "PURCHASED\n";
            }
            else {
                cout << "YOU DON'T HAVE ENOUGH COINS\n";
                skin = '*';
            }
        }
        else if (chooseskin == "5") {
            if (coins > 9) {
                coins = coins - 10;
                skin = '$';
                cout << "PURCHASED\n";
            }
            else {
                cout << "YOU DON'T HAVE ENOUGH COINS\n";
                skin = '*';
            }
        }
        else if (chooseskin == "6") {
            if (coins > 14) {
                coins = coins - 15;
                skin = '#';
                cout << "PURCHASED\n";
            }
            else {
                cout << "YOU DON'T HAVE ENOUGH COINS\n";
                skin = '*';
            }
        }
        else if (chooseskin == "d") {
            break;
        }
        else {
            cout << "CHOOSE AGAIN :(\n";
        }
    }

    start();


}

void screene() {
    system("cls");
    cout << "\033[32m";
    for (int i = 0; i < screenWidth + 2; i++)
        cout << "-";
    cout << endl;

    for (int i = 0; i < screenHeight; i++) {
        for (int j = 0; j < screenWidth; j++) {
            if (j == 0)
                cout << "|";
            if (i == rocketY && j == rocketX)
                cout << skin;
            else if (i == obstackleY && j == obstackleX)
                cout << skin2;
            else if (j == screenWidth - 1)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < screenWidth + 2; i++)
        cout << "-";
    cout << endl;
    cout << "\033[0m";

    cout << "            SCORE: " << score << endl;

}

void screenn() {
    system("cls");
    cout << "\033[32m";
    for (int i = 0; i < screenWidth + 2; i++)
        cout << "-";
    cout << endl;

    for (int i = 0; i < screenHeight; i++) {
        for (int j = 0; j < screenWidth; j++) {
            if (j == 0)
                cout << "|";
            if (i == rocketY && j == rocketX)
                cout << skin;
            else if ((i == obstackleY && j == obstackleX) || (i == obstacle2Y && j == obstacle2X))
                cout << skin2;
            else if (j == screenWidth - 1)
                cout << "|";
            else
                cout << " ";
        }
    }

    for (int i = 0; i < screenWidth + 2; i++)
        cout << "-";
    cout << endl;
    cout << "\033[0m";

    cout << "            SCORE: " << score << endl;

}

void screenh() {
    system("cls");
    cout << "\033[32m";
    for (int i = 0; i < screenWidth + 2; i++)
        cout << "-";
    cout << endl;

    for (int i = 0; i < screenHeight; i++) {
        for (int j = 0; j < screenWidth; j++) {
            if (j == 0)
                cout << "|";
            if (i == rocketY && j == rocketX)
                cout << skin;
            else if ((i == obstackleY && j == obstackleX) || (i == obstacle2Y && j == obstacle2X) || (i == obstacle3Y && j == obstacle3X) || (i == obstacle4Y && j == obstacle4X))
                cout << skin2;
            else if (j == screenWidth - 1)
                cout << "|";
            else
                cout << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < screenWidth + 2; i++)
        cout << "-";
    cout << endl;
    cout << "\033[0m";

    cout << "            SCORE: " << score << endl;

}

void input() {
    if (_kbhit()) {
        char current = _getch();
        if (current == 'a')
            rocketX--;
        if (current == 'd')
            rocketX++;
    }
}

void logicnormal() {
    obstackleY++;
    obstacle2Y++;

    if ((obstackleY == rocketY && obstackleX == rocketX) || (obstacle2Y == rocketY && obstacle2X == rocketX))
        GameOver = true;
    if (obstackleY == screenHeight || obstacle2Y == screenHeight) {
        obstackleY = 0;
        obstackleX = rand() % screenWidth;
        obstacle2Y = 0;
        obstacle2X = rand() % screenWidth;
        score++;
    }
}

void logiceasy() {
    obstackleY++;


    if ((obstackleY == rocketY && obstackleX == rocketX))
        GameOver = true;
    if (obstackleY == screenHeight || obstacle2Y == screenHeight) {
        obstackleY = 0;
        obstackleX = rand() % screenWidth;
        score++;
    }
}

void logichard() {
    obstackleY++;
    obstacle2Y++;
    obstacle3Y++;
    obstacle4Y++;

    if ((obstackleY == rocketY && obstackleX == rocketX) || (obstacle2Y == rocketY && obstacle2X == rocketX) || (obstacle3Y == rocketY && obstacle3X == rocketX) || (obstacle4Y == rocketY && obstacle4X == rocketY))
        GameOver = true;
    if (obstackleY == screenHeight || obstacle2Y == screenHeight || obstacle3Y == screenHeight || obstacle4Y == screenHeight) {
        obstackleY = 0;
        obstackleX = rand() % screenWidth;
        obstacle2Y = 0;
        obstacle2X = rand() % screenWidth;
        obstacle3Y = 0;
        obstacle3X = rand() % screenWidth;
        obstacle4Y = 0;
        obstacle4X = rand() % screenWidth;
        score++;
    }
}

void loot() {
    int random = rand() % 100;

    system("cls");
    cout << "\n"; 

    if (random < 30) {
        if (coins > 5) {
            coins = coins - 5;
            cout << "   YOU LOST 5 SILVER COINS :(\n\n";
        }
        else {
            cout << "   YOU DIDN'T WIN ANY PRIZE :(\n\n";
        }
    }
    else if (random > 30 && random < 60) {
        coins = coins + 5;
        cout << "   YOU HAVE WON 5 SILVER COINS !!!\n\n ";

    }
    else if (random > 60 && random < 80) {
        coins = coins + 15;
        gold = gold + 5;
        cout << "   YOU HAVE WON 15 SILVER COINS AND 5 GOLD !!!\n\n";
  
    }
    else {
        coins = 0;
        gold = 0; 
        if (coins != 0) {
            cout << "   YOU DIDN'T WIN ANY PRIZE :(\n\n";
        }
        else {
            cout << "   YOU LOST ALL YOUR SILVER AND GOLD COINS :(\n\n"; 
        }
        
    }
    cout << "*************************************\n";
    cout << "           SILVER COINS: " << coins << endl;
    cout << "           GOLD COINS: " << gold << endl;
    cout << "*************************************\n"; 
}

int main() { 
    start(); 
    string n;
    srand(time(0));
    while (n != "x") {
        GameOver = false;
        score = 0;
        cin >> n;
        if (n == "s" || n == "S") {
            skins();
        }
        else if (n == "n" || n == "N") {
            while (!GameOver) {
                screenn();
                input();
                logicnormal();
                Sleep(20);
            }
            system("cls");
            cout << "\033[3J";
            cout << "\033[4;40H";
            cout << "\033[31mGAME OVER!\n" << "\033[6;39H" << "YOUR SCORE: " << score << "\033[0m\n";
            cout << "\n\n\n\n";
            if (score > bestscore) {
                bestscore = score;
            }
            if (score > 5 && score < 10) {
                cout << "YOU GAINED 5 SILVER COINS!\n";
                coins += 5;
                cout << "COINS: " << coins << endl;
            }
            if (score > 10 && score < 20) {
                cout << "YOU GAINED 10 SILVER COINS!\n";
                coins += 10;
                cout << "SILVER COINS: " << coins << endl;
            }
            if (score > 20) {
                cout << "YOU GAINED 10 GOLD COINS AND 10 SILVER COINS!\n";
                gold += 10;
                coins += 10;
                cout << "GOLD COINS: " << gold << endl;
                cout << "SILVER COINS: " << coins << endl;
            }
            cout << " REPLAY (R)\n";
            cin >> n;
            start();
        }
        else if (n == "e" || n == "E") {
            while (!GameOver) {
                screene();
                input();
                logiceasy();
                Sleep(20);
            }
            system("cls");
            cout << "\033[3J";
            cout << "\033[4;40H";
            cout << "\033[31mGAME OVER!\n" << "\033[6;39H" << "YOUR SCORE: " << score << "\033[0m\n";
            cout << "\n\n\n\n";
            if (score > bestscore) {
                bestscore = score;
            }
            if (score > 5 && score < 10) {
                cout << "YOU GAINED 3 SILVER COINS!\n";
                coins += 3;
                cout << "SILVER COINS: " << coins << endl;
            }
            if (score > 10 && score < 20) {
                cout << "YOU GAINED 8 COINS!\n";
                coins += 8;
                cout << "SILVER COINS: " << coins << endl;
            }
            if (score > 20) {
                cout << "YOU GAINED 5 GOLD COINS AND 8 SILVER COINS!\n";
                gold += 5;
                coins += 8;
                cout << "GOLD COINS: " << gold << endl;
                cout << "SILVER COINS: " << coins << endl;
            }
            cout << " REPLAY (R)\n";
            cin >> n;
            start();
        }
        else if (n == "h" || n == "H") {
            while (!GameOver) {
                screenh();
                input();
                logichard();
                Sleep(5);
            }
            system("cls");
            cout << "\033[3J";
            cout << "\033[4;40H";
            cout << "\033[31mGAME OVER!\n" << "\033[6;39H" << "YOUR SCORE: " << score << "\033[0m\n";
            cout << "\n\n\n\n";
            if (score > bestscore) {
                bestscore = score;
            }
            if (score > 5 && score < 10) {
                cout << "YOU GAINED 10 SILVER COINS!\n";
                coins += 10;
                cout << "SILVER COINS: " << coins << endl;
            }
            if (score > 10 && score < 20) {
                cout << "YOU GAINED 15 SILVER COINS!\n";
                coins += 15;
                cout << "SILVER COINS: " << coins << endl;
            }
            if (score > 20) {
                cout << "YOU GAINED 15 GOLD COINS AND 20 SILVER COINS!\n";
                gold += 15;
                coins += 20;
                cout << "GOLD COINS: " << gold << endl;
                cout << "SILVER COINS: " << coins << endl;
            }
            cout << " REPLAY (R)\n";
            cin >> n;
            start();
        }
        else if (n == "l" || n == "L") {
            string a;  
            system("cls"); 
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n"; 
            cout << "- - GET FREE SILVER AND GOLD COINS IN A CHANCE YOU CAN LOOSE ALL - - \n"; 
            cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n"; 
            cout << "START (S)                                                 EXIT (X)\n"; 
            cin >> a;      

            while (a != "x") { 
                if (a == "s") {
                    loot();
                    cout << "EXIT (X)                   REPEAT (S)\n";
                    cin >> a;
                    start();
                }
            }
            start(); 
            
        }
    }
    return 0;
}
 