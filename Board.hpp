#include <iostream>
#include <vector>
#include <stdexcept>
#include "Direction.hpp"

namespace ariel {
    class Board {
        std::vector<std::vector<char>> showboard {};
        unsigned int full;
        public:
            Board();
            void post(unsigned int row, unsigned int col, Direction d, std::string message);
            std::string read(unsigned int row, unsigned int col, Direction d, unsigned int length);
            void show();
    };
};