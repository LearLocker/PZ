// PZ_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <map>
#include <string>

constexpr int MIN = 1;
constexpr int MAX = 20;

void printVector(std::vector<int>& vector) {
    std::cout << "Vector is:" << std::endl;
    for (auto i : vector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

namespace FirstAssigment {
    void assigment() {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<int> distr(MIN, MAX);

        int count = distr(eng);

        std::vector<int> vect;
        for (int i = 0; i < count; ++i)
            vect.push_back(distr(eng));

        std::vector<int> vect_sec(vect);

        printVector(vect);

        vect.erase(remove_if(vect.begin(), vect.end(), [](int x) { return (x % 5) == 0; }), vect.end());

        printVector(vect);
    }
}

namespace SecondAssigment {
    void assigment() {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<int> distr(MIN, MAX);

        int count = distr(eng);

        std::vector<int> vect;
        for (int i = 0; i < count; ++i)
            vect.push_back(distr(eng));

        printVector(vect);

        std::vector<int>::iterator it;
        std::vector<int>::iterator back_it;

        it = vect.begin();
        back_it = vect.end() - 1;

        std::cout << "Vector size is " << vect.size() << std::endl;
        std::cout << "Sum of element is " << std::endl;

        int i = vect.size() / 2;
        while (i > 0)
        {
            std::cout << *it + *back_it << " " << std::endl;
            ++it;
            --back_it;
            --i;
        }

        if (vect.size() % 2 != 0) {
            std::cout << *it + *it << std::endl;
        }
    }
}

namespace ThirdAssigment {
    void wordsCount(std::string& text, std::set<char>& separators) {
        int words_count = 0;
        std::vector<std::string> words;

        int currIndex = 0, i = 0;
        int startIndex = 0, endIndex = 0;
        int length = text.length();
        for (int i = 0; i < length; i++)
        {
            if (separators.find(text[i]) != separators.end()) {
                endIndex = i;
                if (endIndex - startIndex > 0) {
                    std::string subStr = "";
                    subStr.append(text, startIndex, endIndex - startIndex);
                    words.push_back(subStr);
                    currIndex += 1;
                    startIndex = endIndex + 1;
                    words_count++;
                }
            }
        }

        std::cout << "Amount of words is " << words.size() << std::endl;
    }

    void assigment() {
        std::string text = "Random words, set.with - different separators";
        std::set<char> separators = { ' ', '.', ',', '-' };

        std::cout << "Text is: '" << text << "'" << std::endl;
        wordsCount(text, separators);
    }
}

namespace ForthAssigment {
    static const std::string buildings[] = { "school", "shop", "cafe", "theater" };

    struct Point {
        int x;
        int y;

        Point(int _x, int _y) : x(_x), y(_y) {}

        bool operator<(const Point& r) const
        {
            double abs_cur = sqrt(x * x + y * y);
            double abs_rgh = sqrt(r.x * r.x + r.y * r.y);
            return abs_cur < abs_rgh; // keep the same order
        }
    };

    void assigment() {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<int> distr(MIN, MAX);
        std::uniform_int_distribution<int> building_distr(0, 3);

        std::multimap<Point, std::string> block;

        int count = distr(eng);

        for (int i = 0; i < count; ++i) {
            Point x(distr(eng), distr(eng));
            int building_index = building_distr(eng);
            block.insert(std::make_pair(x, buildings[building_index]));
        }

        for (const auto& pair : block) {
            const Point pnt = pair.first;

            std::cout << pair.second << " at (" << pnt.x << ", " << pnt.y << ")" << std::endl;
        }
    }
}

int main()
{
    std::size_t assigment{};
    char exit;

    do {
        system("cls");
        std::cout << "Choose the assigment between 1,2,3 or 4" << std::endl;
        std::cin >> assigment;

        switch (assigment) {
        case 1: FirstAssigment::assigment(); break;
        case 2: SecondAssigment::assigment(); break;
        case 3: ThirdAssigment::assigment(); break;
        case 4: ForthAssigment::assigment(); break;
        default: std::cout << "Uknown assigment number" << std::endl; break;
        }

        std::cout << "Try again? (y-yes, other-exit)" << std::endl;
        std::cin >> exit;
    } while (exit == 'y' || exit == 'Y');
    
}
