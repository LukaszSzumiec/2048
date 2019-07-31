#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Board {
public:
    int **board2;
    char direction;
    bool gameOver;

    Board() {
        direction = 'w';
        gameOver = false;
        board2 = new int *[4];
        for (int i = 0; i < 4; i++) {
            board2[i] = new int[4];
            for (int k = 0; k < 4; k++) {
                board2[i][k] = 0;
            }
        }
    }

    void draw2() {
        for (int i = 0; i < 4; i++) {
            for (int k = 0; k < 4; k++) {
                cout << board2[i][k] << "  ";
            }
            cout << endl;
        }
    }

    void placeNumber2() {
        int i = 0;
        int k = 0;
        int randomCounter = 0;
        do {
            if (randomCounter > 400) {
                cout << "teST";
                gameOver = true;
            }
            i = rand() % 4;
            k = rand() % 4;
            randomCounter++;
        } while (board2[i][k] != 0 && !gameOver);
        if (!gameOver) {
            board2[i][k] = 2;
        } else {
            exit(EXIT_SUCCESS);
        }
    }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "InfiniteRecursion"
    void makeMove() {
        char move;
        try {
            cin >> move;
            if (move < 97) {
                move += 32;
            }
            if (move != 'a' && move != 's' && move != 'd' && move != 'w') {
                throw move;
            }
            direction = move;
        }
        catch (char move) {
            cout << "Move with W S A D" << endl;
            makeMove();
        }
    }
#pragma clang diagnostic pop

    void c(int i, int k, char c) {
        switch (c) {
            case 'a':
                for (k = 3; k > 0; k--) {
                    if (board2[i][k] != 0 && board2[i][k - 1] == 0) {
                        board2[i][k - 1] = board2[i][k];
                        board2[i][k] = 0;
                    }
                }
                break;
            case 's':
                for (i = 0; i < 3; i++) {
                    if (board2[i][k] != 0 && board2[i + 1][k] == 0) {
                        board2[i + 1][k] = board2[i][k];
                        board2[i][k] = 0;
                    }
                }
                break;
            case 'd':
                for (k = 0; k < 3; k++) {
                    if (board2[i][k] != 0 && board2[i][k + 1] == 0) {
                        board2[i][k + 1] = board2[i][k];
                        board2[i][k] = 0;
                    }
                }
                break;
            case 'w':
                for (i = 3; i > 0; i--) {
                    if (board2[i][k] != 0 && board2[i - 1][k] == 0) {
                        board2[i - 1][k] = board2[i][k];
                        board2[i][k] = 0;
                    }
                }
                break;
            default:
                exit(EXIT_FAILURE);
        }
    }

    void sumBoard2() {
        switch (direction) {
            case 'a':
                for (int i = 0; i < 4; i++) {
                    for (int k = 3; k >= 0; k--) {
                        if ((board2[i][k - 1] == board2[i][k]) && board2[i][k - 1] != 0) {
                            board2[i][k - 1] = board2[i][k - 1] + board2[i][k];
                            board2[i][k] = 0;
                            c(i, k, direction);
                            k--;
                        }
                        if (k > 0) {
                            if (board2[i][k] != 0 && board2[i][k - 1] == 0) {
                                board2[i][k - 1] = board2[i][k];
                                board2[i][k] = 0;
                            }
                        }
                    }
                }
                break;
            case 's':
                for (int k = 0; k < 4; k++) {
                    for (int i = 0; i < 3; i++) {
                        if (i < 3) {
                            if ((board2[i][k] == board2[i + 1][k]) && board2[i][k] != 0) {
                                board2[i + 1][k] = board2[i][k] + board2[i + 1][k];
                                board2[i][k] = 0;
                                c(i, k, direction);
                                i++;
                            }
                            if (i < 3) {
                                if (board2[i][k] != 0 && board2[i + 1][k] == 0) {
                                    board2[i + 1][k] = board2[i][k];
                                    board2[i][k] = 0;
                                }
                            }
                        }
                    }
                }
                break;
            case 'd':
                for (int i = 0; i < 4; i++) {
                    for (int k = 0; k < 4; k++) {
                        if (k < 3) {
                            if ((board2[i][k + 1] == board2[i][k]) && board2[i][k] != 0) {
                                board2[i][k + 1] = board2[i][k] + board2[i][k + 1];
                                board2[i][k] = 0;
                                c(i, k, direction);
                                k++;
                            }
                            if (k < 3) {
                                if (board2[i][k] != 0 && board2[i][k + 1] == 0) {
                                    board2[i][k + 1] = board2[i][k];
                                    board2[i][k] = 0;
                                }
                            }
                        }
                    }
                }
                break;
            case 'w':
                for (int k = 0; k < 4; k++) {
                    for (int i = 3; i > -1; i--) {
                        if (i > 0) {
                            if ((board2[i][k] == board2[i - 1][k]) && board2[i][k] != 0) {
                                board2[i - 1][k] = board2[i][k] + board2[i - 1][k];
                                board2[i][k] = 0;
                                c(i, k, direction);
                                i--;
                            }
                            if (i > 0) {
                                if (board2[i][k] != 0 && board2[i - 1][k] == 0) {
                                    board2[i - 1][k] = board2[i][k];
                                    board2[i][k] = 0;
                                }
                            }
                        }
                    }
                }
                break;
        }
    }
};

int main() {
    srand((int)time(0)); // NOLINT(cert-msc32-c)
    auto *board2 = new Board;
    while (!board2->gameOver) {
        board2->placeNumber2();
        board2->draw2();
        board2->makeMove();
        board2->sumBoard2();
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
//        system("clear");
    }
    return 0;
}