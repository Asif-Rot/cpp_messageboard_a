#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"
using namespace ariel;

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

ariel::Board board;

TEST_CASE("Good board code") {
    CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, "abcd"));
    board.post(100, 200, Direction::Horizontal, "abcd");
    CHECK(board.read(100, 200, Direction::Horizontal, 4) == string("abcd"));
    CHECK(board.read(100, 200, Direction::Vertical, 1) == string("a"));
    CHECK(board.read(100, 201, Direction::Vertical, 1) == string("b"));
    CHECK(board.read(100, 202, Direction::Vertical, 1) == string("c"));
    CHECK(board.read(100, 203, Direction::Vertical, 1) == string("d"));

    CHECK_NOTHROW(board.post(98, 205, Direction::Vertical, "xyz"));
    board.post(98, 205, Direction::Vertical, "xyz");
    CHECK(board.read(98, 205, Direction::Vertical, 3) == string("xyz"));
    CHECK(board.read(98, 205, Direction::Horizontal, 1) == string("x"));
    CHECK(board.read(99, 205, Direction::Horizontal, 1) == string("y"));
    CHECK(board.read(100, 205, Direction::Horizontal, 1) == string("z"));

}

TEST_CASE("check printed _") {
    board.post(100, 200, Direction::Horizontal, "abc");
    CHECK(board.read(100, 199, Direction::Horizontal, 4) == string("_abc_"));
    CHECK(board.read(99, 200, Direction::Vertical, 3) == string("_a_"));
    CHECK(board.read(100, 201, Direction::Vertical, 2) == string("b_"));
    CHECK(board.read(98, 202, Direction::Vertical, 3) == string("__c"));
}

TEST_CASE("Bad board code") {
    board.post(90, 200, Direction::Horizontal, "abc");
    CHECK_FALSE(board.read(90, 200, Direction::Horizontal, 4) == "abcd");
    CHECK_FALSE(board.read(90, 200, Direction::Horizontal, 3) == string("ajk"));
    CHECK_FALSE(board.read(90, 200, Direction::Vertical, 1) == string("b"));
}

TEST_CASE("override string") {
    board.post(100, 200, Direction::Horizontal, "abc");
    board.post(99, 201, Direction::Vertical, "xyz");
    CHECK(board.read(100, 200, Direction::Horizontal, 3) != "abc");
    CHECK(board.read(100, 200, Direction::Horizontal, 3) == "ayc");
}

