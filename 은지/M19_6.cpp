#include <iostream>

struct Train {
    int win;
    char name[7];
};

int main() {
    Train train[7] = {
    {15, "summer"},
    {33, "cloe"},
    {24, "summer"},
    {28, "niki"},
    {32, "jenny"},
    {20, "summer"},
    {40, "coco"}
    };

    Train love;
    std::cin >> love.name >> love.win;


    for (int i = 0; i < 7; i++) {
        int cnt = 0;
        if (love.win == train[i].win) {
            for (int i = 0; i < 7; i++) {
                if (train->name[i] == love.name[i]) {
                    cnt++;
                }
            }
        }

        if (cnt == 7) {
            std::cout << i;
            return 0;
        }
    }


}
