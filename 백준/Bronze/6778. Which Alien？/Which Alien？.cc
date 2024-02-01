#include <iostream>

void identifyAlien(int antennas, int eyes) {
    if (antennas >= 3 && eyes <= 4) {
        std::cout << "TroyMartian\n";
    }
    if (antennas <= 6 && eyes >= 2) {
        std::cout << "VladSaturnian\n";
    }
    if (antennas <= 2 && eyes <= 3) {
        std::cout << "GraemeMercurian\n";
    }
}

int main() {
    int antennas, eyes;

    // Read input
    std::cin >> antennas >> eyes;

    // Identify matching aliens
    identifyAlien(antennas, eyes);

    return 0;
}