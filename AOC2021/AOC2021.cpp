// AOC2021.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

typedef int(*DayFunction) (std::ifstream& input);

int day1(std::ifstream& input);
int day2(std::ifstream& input);
int day3(std::ifstream& input);
int day4(std::ifstream& input);
int day5(std::ifstream& input);
int day6(std::ifstream& input);
int day7(std::ifstream& input);
int day8(std::ifstream& input);
int day9(std::ifstream& input);
int day10(std::ifstream& input);
int day11(std::ifstream& input);
int day12(std::ifstream& input);
int day13(std::ifstream& input);
int day14(std::ifstream& input);
int day15(std::ifstream& input);
int day16(std::ifstream& input);
int day17(std::ifstream& input);
int day18(std::ifstream& input);
int day19(std::ifstream& input);
int day20(std::ifstream& input);
int day21(std::ifstream& input);
int day22(std::ifstream& input);
int day23(std::ifstream& input);
int day24(std::ifstream& input);
int day25(std::ifstream& input);

int main()
{
    DayFunction functions[] = {
        day1,
        day2,
        day3
    };

    int day;
    std::cout << "Welcome to Wellwick's Advent of Code 2021!\n";
    std::cout << "Please specify which day we are running: ";
    std::cin >> day;
    std::cout << "\n";
    
    // Make sure day is between 1 and 25
    if (day <= 0 || day > 25) {
        std::cout << "That day is beyond the scope of this AOC!\n";
        exit(1);
    }

    std::string filename = "input" + std::to_string(day) + ".txt";
    std::ifstream MyFile(filename);
    std::cout << filename;

    functions[day - 1](MyFile);

    MyFile.close();
}

int day3(std::ifstream& input) {
    // I happen to know the input length is 12, so I'm doing this manually
    // It's lazy, but fast for coding this
    int zeros[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int ones[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    std::string readIn;
    while (std::getline(input, readIn)) {
        for (int i = 0; i < readIn.length(); i++) {
            if (readIn[i] == '0') {
                zeros[i]++;
            }
            else {
                ones[i]++;
            }
        }
    }

    std::cout << (1 << 3) << "\n";

    int gamma = 0, epsilon = 0;
    for (int i = 0; i < 12; i++) {
        // Value at this level is 1 bit shifted by how far into the binary
        // digits we are!
        int value = 1 << (11 - i);
        if (zeros[i] > ones[i]) {
            epsilon += value;
        }
        else {
            gamma += value;
        }
    }

    std::cout << "Step one: " << epsilon * gamma << "\n";
    //std::cout << "Step two: " << x * aim_y << "\n";

    return 0;
}

void day2_move(std::string move, int &x, int &y, int &aim_y) {
    size_t space_index = move.find(' ');
    int dist = std::stoi(move.substr(space_index + 1));
    std::string direction = move.substr(0, space_index);
    if (direction == "forward") {
        x += dist;
        aim_y += dist * y;
    }
    else if (direction == "up") {
        y -= dist;
    }
    else if (direction == "down") {
        y += dist;
    }
}

int day2(std::ifstream& input) {
    // In this case y as depth for stage one and "aim"
    int x = 0, y = 0, aim_y = 0;
    std::string readIn;
    while (std::getline(input, readIn)) {
        day2_move(readIn, x, y, aim_y);
    }

    std::cout << "Step one: " << x * y << "\n";
    std::cout << "Step two: " << x * aim_y << "\n";

    return 0;
}

int day1_sum_at_index(std::vector<int>& values, int index) {
    return values[index] + values[index + 1] + values[index + 2];
};

int day1(std::ifstream& input) {
    std::string readIn;
    std::vector<int> values;
    while (std::getline(input, readIn)) {
        int val = std::stoi(readIn);
        values.emplace_back(val);
    }

    int previous = 0;
    int count_increase = -1;
    for (int value : values) {
        if (value > previous) {
            count_increase++;
        }
        previous = value;
    }

    std::cout << "Step one: " << count_increase << "\n";

    int count_window_increase = 0;
    for (int i = 0; i < values.size()-3; i++) {
        if (day1_sum_at_index(values, i) < day1_sum_at_index(values, i + 1)) {
            count_window_increase++;
        }
    }

    std::cout << "Step two: " << count_window_increase << "\n";

    return 0;
}
