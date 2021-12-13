// PZ_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <random>
#include <complex>
#include "Figure.h"
#include "ShapeLogger.h"
#include "Complex.h"

namespace FirstSecondAssigment {
    constexpr int MIN = 5;
    constexpr int MAX = 50;

    static const std::string colors[] = { "gray", "black", "white", "red", "blue", "green", "yellow", "purple", "orange" };

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
        std::uniform_int_distribution<int> tf(1, 3);
        std::uniform_int_distribution<int> tfc(1, 9);

        int totalFigureCount = tfc(eng);
        int typeOfFigure, figColor;

        int sizeOfColors = sizeof(colors) / sizeof(colors[0]);
        std::uniform_int_distribution<int> clr(0, sizeOfColors - 1);

        for (int i = 0; i < totalFigureCount; i++) {
            typeOfFigure = tf(eng);
            figColor = clr(eng);
            switch (typeOfFigure) {
            case 1: {
                CFigure* trn = new CTriangle(distr(eng), distr(eng));
                trn->setColor(colors[figColor]);
                figures.push_back(trn);
                
                break;
            }
            case 2: {
                CFigure* crc = new CCircle(distr(eng));
                crc->setColor(colors[figColor]);
                figures.push_back(crc);
                
                break;
            }
            case 3: {
                CFigure* sqr = new CSquare(distr(eng));
                sqr->setColor(colors[figColor]);
                figures.push_back(sqr);
               
                break;
            }
            }
        }

        std::cout << "Count of triangles is " << CTriangle::trianCount << std::endl;
        std::cout << "Count of circles is " << CCircle::circleCount << std::endl;
        std::cout << "Count of squares is " << CSquare::sqrCount << std::endl;
    }

    void assigment()
    {
        std::vector<CFigure*> figures;
        ShapeLogger* shapeLogger = new ShapeLogger();

        fillFigures(figures);

        for (auto figure : figures) {
            figure->CalculusArea();
            figure->PrintArea();
            shapeLogger->printColor(*figure);
        }

        std::for_each(figures.begin(), figures.end(), delete_ptr());
        figures.clear();

        delete shapeLogger;

        system("pause");
        system("cls");
    }
}

namespace ThirdAssigment {
    int* duplicateArrayValues(int arrToCopy[3], int arrSize, int N) {
        const int size = arrSize * N;
        int* duplArray = new int[size];

        for (int i = 0; i < size; i += arrSize) {
            memcpy(duplArray + i, arrToCopy, (sizeof(arrToCopy[0]) * arrSize));
        }

        return duplArray;
    }

    void assigment() {
        int arr[3] = { 1, 2, 3 };
        int N = 4;
        int arrSize = (sizeof(arr) / sizeof(arr[0]));
        int* duplicated = ThirdAssigment::duplicateArrayValues(arr, arrSize, N);

        for (int i = 0; i < N * arrSize; i++)
            std::cout << duplicated[i] << " ";
        std::cout << std::endl;

        delete[] duplicated;

        system("pause");
        system("cls");
    }
}

namespace FifthAssigment {
    void assigment() {
        Complex n1(3, 2), n2(4, -3);
        std::cout << "First number: " << n1 << std::endl;
        std::cout << "Second number: " << n2 << std::endl;

        Complex result;
        result = n1 + n2;
        std::cout << "Addition is " << result << std::endl;

        Complex n3(2, 2), n4(4, 4);
        std::cout << "First number: " << n3 << std::endl;
        std::cout << "Second number: " << n4 << std::endl;

        std::string equel = n3 == n4 ? "equel" : "not equel";
        std::cout << "Complex numbers are " << equel << std::endl;

        result = n3 * n4;
        std::cout << "Multiplication is " << result << std::endl;

        Complex n5(3, -1);
        std::cout << "First number: " << n5 << std::endl;
        double scalar = 3.5;
        result = n5 * scalar;
        std::cout << "Multiplication by a scalar = " << scalar << " is " << result << std::endl;

        system("pause");
        system("cls");
    }
}

int main()
{
    std::size_t assigment{};

    std::cout << "Choose the assigment between 1,2,3 or 5" << std::endl;
    std::cin >> assigment;

    switch (assigment) {
    case 1:
    case 2: FirstSecondAssigment::assigment(); break;
    case 3: ThirdAssigment::assigment(); break;
    case 5: FifthAssigment::assigment(); break;
    default: std::cout << "Uknown assigment number" << std::endl; break;
    }
}