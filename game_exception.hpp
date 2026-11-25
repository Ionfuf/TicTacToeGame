#pragma once

#include <stdexcept>
#include <string>

class GameException : public std::runtime_error {
public:
    explicit GameException(const std::string& message)
        : std::runtime_error(message) {}
};

class InvalidMoveException : public GameException {
public:
    explicit InvalidMoveException(const std::string& message)
        : GameException(message) {}
};
