#pragma once

#include <string>
#include <vector>

struct MatchRecord {
    std::string winnerName;
    int totalMoves;
};

class ScoreManager {
    std::string _filename;

public:
    explicit ScoreManager(const std::string& filename = "scores.txt");
    void SaveMatch(const std::string& winnerName, int totalMoves);
    std::vector<MatchRecord> LoadMatches() const;
    void DisplayStatistics() const;
};
