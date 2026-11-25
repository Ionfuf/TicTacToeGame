#include "score_manager.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>

ScoreManager::ScoreManager(const std::string& filename) : _filename(filename) {}

void ScoreManager::SaveMatch(const std::string& winnerName, int totalMoves) {
    std::ofstream outFile(_filename, std::ios::app);
    if (!outFile.is_open()) {
        std::cerr << "Eroare la deschiderea fisierului de scoruri!\n";
        return;
    }
    outFile << winnerName << ";" << totalMoves << "\n";
}

std::vector<MatchRecord> ScoreManager::LoadMatches() const {
    std::vector<MatchRecord> records;
    std::ifstream inFile(_filename);
    if (!inFile.is_open()) {
        return records;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::size_t sep = line.find(';');
        if (sep != std::string::npos) {
            std::string name = line.substr(0, sep);
            int moves = std::stoi(line.substr(sep + 1));
            records.push_back({name, moves});
        }
    }
    return records;
}

void ScoreManager::DisplayStatistics() const {
    std::vector<MatchRecord> records = LoadMatches();
    if (records.empty()) {
        std::cout << "\n[Statistici] Nu exista meciuri salvate inca.\n\n";
        return;
    }

    int xWins = std::count_if(records.begin(), records.end(), [](const MatchRecord& r) {
        return r.winnerName.find("Jucator X") != std::string::npos;
    });

    int draws = std::count_if(records.begin(), records.end(), [](const MatchRecord& r) {
        return r.winnerName == "Remiza";
    });

    int totalMovesSum = std::accumulate(records.begin(), records.end(), 0, [](int acc, const MatchRecord& r) {
        return acc + r.totalMoves;
    });

    double avgMoves = static_cast<double>(totalMovesSum) / records.size();

    std::cout << "\n=== STATISTICI JOC (" << records.size() << " partide) ===\n";
    std::cout << "Victorii Jucator X : " << xWins << "\n";
    std::cout << "Victorii O / Bot   : " << (static_cast<int>(records.size()) - xWins - draws) << "\n";
    std::cout << "Remize             : " << draws << "\n";
    std::cout << "Media de mutari    : " << avgMoves << "\n";
    std::cout << "===================================\n\n";
}
