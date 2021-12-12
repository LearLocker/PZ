// PZ_8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <random>
#include "Figure.h"

constexpr int MIN = 5;
constexpr int MAX = 50;

struct delete_ptr { // Helper function to ease cleanup of container
    template <typename P>
    void operator () (P p) {
        delete p;
    }
};

void fillFigures(std::vector<CFigure*>& figures) {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> distr(MIN, MAX);
    std::uniform_int_distribution<int> uni(1, 3);

    int trianCount = uni(eng);
    int circCount  = uni(eng);
    int sqrtCount  = uni(eng);

    for (int n = 0; n < trianCount; ++n) {
        figures.push_back(new CTriangle(distr(eng), distr(eng)));
    }
    for (int n = 0; n < circCount; ++n) {
        figures.push_back(new CCircle(distr(eng)));
    }
    for (int n = 0; n < sqrtCount; ++n) {
        figures.push_back(new CSquare(distr(eng)));
    }
}

int main()
{
    std::vector<CFigure*> figures;

    fillFigures(figures);

    for (auto figure : figures) {
        figure->CalculusArea();
        figure->PrintArea();
    }

    std::for_each(figures.begin(), figures.end(), delete_ptr());
    figures.clear();

    system("pause");
    system("cls");
}