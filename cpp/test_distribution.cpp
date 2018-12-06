#include <iostream>
#include <map>
#include "genzipf.h"
#include <string>
#include <random>

using namespace std;

void test_geometric() {
    cout << "Geometric distribution" << endl;
    std::random_device rd;
    std::mt19937 gen(rd());

    std::geometric_distribution<> d; // same as std::negative_binomial_distribution<> d(1, 0.5);

    std::map<int, int> hist;
    for(int n=0; n<10000; ++n) {
        ++hist[d(gen)];
    }
    for(auto p : hist) {
        std::cout << p.first <<
                ' ' << std::string(p.second/100, '*') << '\n';
    }
}

void test_genzipf() {
    cout << "Zip'f distribution" << endl;
    GenZipf* g = new GenZipf(0.5, 20);
    map<int, int> hist;
    for(int n=0; n<10000; ++n) {
        ++hist[g->get()];
    }
    for(auto p : hist) {
        cout << p.first <<
                ' ' << string(p.second/100, '*') << '\n';
    }
}

int main() {
    test_geometric();
    test_genzipf();
}
