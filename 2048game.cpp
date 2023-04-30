#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <thread>
#include <chrono>
#include <fstream>
using namespace std;

void moveup(int board[4][4])
{
    int i, j, indexleft, indexright;
    for (j = 0; j < 4; j++)
    {
        indexleft = 0;
        indexright = j;
        for (i = 1; i < 4; i++)
        {
            if (board[i][j] != 0)
            {
                if (board[i - 1][j] == 0 || board[i - 1][j] == board[i][j])
                {
                    if (board[indexleft][indexright] == board[i][j])
                    {
                        board[indexleft][indexright] *= 2;
                        board[i][j] = 0;
                    }
                    else
                    {
                        if (board[indexleft][indexright] == 0)
                        {
                            board[indexleft][indexright] = board[i][j];
                            board[i][j] = 0;
                        }
                        else
                        {
                            indexleft++;
                            board[indexleft][indexright] = board[i][j];
                            board[i][j] = 0;
                        }
                    }
                }
                else
                {
                    indexleft++;
                }
            }
        }
    }
}

void movedown(int board[4][4])
{
    int i, j, indexleft, indexright;
    for (j = 0; j < 4; j++)
    {
        indexleft = 3;
        indexright = j;
        for (i = 2; i >= 0; i--)
        {
            if (board[i][j] != 0)
            {
                if (board[i + 1][j] == 0 || board[i + 1][j] == board[i][j])
                {
                    if (board[indexleft][indexright] == board[i][j])
                    {
                        board[indexleft][indexright] *= 2;
                        board[i][j] = 0;
                    }
                    else
                    {
                        if (board[indexleft][indexright] == 0)
                        {
                            board[indexleft][indexright] = board[i][j];
                            board[i][j] = 0;
                        }
                        else
                        {
                            indexleft--;
                            board[indexleft][indexright] = board[i][j];
                            board[i][j] = 0;
                        }
                    }
                }
                else
                {
                    indexleft--;
                }
            }
        }
    }
}

void moveleft(int board[4][4])
{
    int i, j, indexleft, indexright;
    for (i = 0; i < 4; i++)
    {
        indexleft = i;
        indexright = 0;
        for (j = 1; j < 4; j++)
        {
            if (board[i][j] != 0)
            {
                if (board[i][j - 1] == 0 || board[i][j - 1] == board[i][j])
                {
                    if (board[indexleft][indexright] == board[i][j])
                    {
                        board[indexleft][indexright] *= 2;
                        board[i][j] = 0;
                    }
                    else
                    {
                        if (board[indexleft][indexright] == 0)
                        {
                            board[indexleft][indexright] = board[i][j];
                            board[i][j] = 0;
                        }
                        else
                        {
                            indexright++;
                            board[indexleft][indexright] = board[i][j];
                            board[i][j] = 0;
                        }
                    }
                }
                else
                {
                    indexright++;
                }
            }
        }
    }
}

void moveright(int board[4][4])
{
    int i, j, indexleft, indexright;
    for (i = 0; i < 4; i++)
    {
        indexleft = i;
        indexright = 3;
        for (j = 2; j >= 0; j--)
        {
            if (board[i][j] != 0)
            {
                if (board[i][j + 1] == 0 || board[i][j + 1] == board[i][j])
                {
                    if (board[indexleft][indexright] == board[i][j])
                    {
                        board[indexleft][indexright] *= 2;
                        board[i][j] = 0;
                    }
                    else
                    {
                        if (board[indexleft][indexright] == 0)
                        {
                            board[indexleft][indexright] = board[i][j];
                            board[i][j] = 0;
                        }
                        else
                        {
                            board[indexleft][--indexright] = board[i][j];
                            board[i][j] = 0;
                        }
                    }
                }
                else
                {
                    indexright--;
                }
            }
        }
    }
}

void addblock(int board[4][4])
{
    int indexleft, indexright;
    srand(time(0));
    while (1)
    {
        indexleft = rand() % 4;
        indexright = rand() % 4;
        if (board[indexleft][indexright] == 0)
        {
            int power = indexleft % 2 + 1;
            board[indexleft][indexright] = pow(2, power);
            break;
        }
    }
}

void disp(int board[4][4])
{
    cout << "\n\n\n\n\n";
    int i, j;
    for (i = 0; i < 4; i++)
    {
        cout << "\t\t\t\t-----------------\n\t\t\t\t";
        for (j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                cout << "|   ";
            }
            else
            {
                cout << "| " << board[i][j] << " ";
            }
        }
        cout << "|" << endl;
    }
    cout << "\t\t\t\t-----------------\n";
}

int check(int temp[4][4], int board[4][4])
{
    bool c = 1;
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (temp[i][j] != board[i][j])
            {
                c = 0;
                break;
            }
        }
        if (c == 0)
        {
            break;
        }
    }
    return c;
}

int checkover(int board[4][4], int targetNumber)
{
    int c = 0, d = 0, i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (board[i][j] == 0)
            {
                c = 1;
                break;
            }

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[i + 1][j] == board[i][j] || board[i][j + 1] == board[i][j])
            {
                d = 1;
                break;
            }

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (board[i][j] == targetNumber)
                return 2;

    if (c || d)
        return 1;
    else
        return 0;
}

void botplay(int board[4][4])
{
    int i = rand() % 4;
    switch (i)
    {
    case 0:
        moveup(board);
        break;
    case 1:
        movedown(board);
        break;
    case 2:
        moveleft(board);
        break;
    case 3:
        moveright(board);
        break;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int diff()
{
    int d, targetNumber;
    while (1)
    {
        cout << "\n\t\tChoose the difficulty: \n1 - Easy, 2 - Medium, 3 - Hard\n";
        cin >> d;
        if (d == 1)
        {
            targetNumber = 32;
            break;
        }
        if (d == 2)
        {
            targetNumber = 512;
            break;
        }
        if (d == 3)
        {
            targetNumber = 1024;
            break;
        }
        else
        {
            cout << "\n\t\tWrong number, try again: \n";
        }
    }
    return targetNumber;
}

void save_best_time(int bestTime)
{
    std::ofstream outputFile("besttime.txt");
    outputFile << bestTime;
    outputFile.close();
}

int main()
{
    cout << "\n\n\n\n\t\t\t2048\n\n\n\t\tEnter any key to continue\n\n\t\tPress B if you want a bot to play\n\n\nControls: W - up, S - down, A - left, D - right\n";
    char game = getchar();
    std::ifstream inputFile("besttime.txt");
    int bestTime;
    inputFile >> bestTime;
    std::cout << "Best time so far is " << bestTime << " seconds\n";
    int targetNumber = diff();
    auto start = std::chrono::high_resolution_clock::now();
    int a, b, c, d, i, j;
    bool gamewon = true;
    int board[4][4] = {0}, temp[4][4] = {0};
    srand(time(0));
    a = rand() % 4;
    b = rand() % 4;
    while (1)
    {
        c = rand() % 4;
        d = rand() % 4;
        if (c != a && d != b)
            break;
    }
    board[a][b] = 2;
    board[c][d] = 4;
    disp(board);

    int ch;
    while (1)
    {
        for (i = 0; i < 4; i++)
            for (j = 0; j < 4; j++)
                temp[i][j] = board[i][j];

        if (game == 'b')
        {
            botplay(board);
        }
        else
        {
            char ch = getchar();
            if (ch == 'w')
            {
                moveup(board);
            }
            else if (ch == 's')
            {
                movedown(board);
            }
            else if (ch == 'a')
            {
                moveleft(board);
            }
            else if (ch == 'd')
            {
                moveright(board);
            }
            else if (ch == 'e')
            {
                cout << "\n\t\t\tGAME OVER\n";
                break;
            }
            cout << "\n\t\t\tPress E to stop the game\n";
        }

        if (!check(temp, board))
            addblock(board);
        disp(board);

        if (!checkover(board, targetNumber))
        {
            cout << "\n\n\t\t\tYOU LOST!\n\n\n";
            getchar();
            gamewon = false;
            break;
        }
        else if (checkover(board, targetNumber) == 2)
        {
            cout << "\n\n\t\t\tYOU WON!\n\n\n";
            getchar();
            break;
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::seconds>(stop - start);
    if (gamewon)
    {
        cout << "Your time: " << duration.count() << " seconds\n";
        if (duration.count() < bestTime)
        {
            bestTime = duration.count();
            cout << "\n\nYour new best time: " << bestTime << " seconds\n";
        }
        else
        {
            cout << "The best time so far is " << bestTime << " seconds\n";
        }
        save_best_time(bestTime);
    }
    return 0;
}