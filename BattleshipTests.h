// BattleshipTests.h
// This header file is implemented to create tests to check whether the grid is
// setup correctly, and whether the ships are able to be correctly placed
// the tests are implemented and run in the main.cpp file
#ifndef BATTLESHIP_TESTS_H
#define BATTLESHIP_TESTS_H

#include <cassert>
#include "Grid.h"
#include "StraightShip.h"
#include "LShapedShip.h"
#include "StealthShip.h"

class BattleshipTests {
public:
    static void runAllTests() {
        testGridSetup();
        testStraightShipPlacing();
        testHorizontalStraightShipPlacing();
        testLShapedShipPlacing();
        testStealthShipPlacing();
    }

private:
    static void testGridSetup() {
        Grid grid;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                assert(grid.Getcell(i, j) == ' ');
            }
        }
    }

    static void testStraightShipPlacing() {
        Grid grid;
        StraightShip straightShip(2, 3, 3, true);
        assert(grid.placeShip(straightShip));
        for (int i = 2; i < 5; ++i) {
            assert(grid.Getcell(i, 3) == '|');
        }
    }

    static void testHorizontalStraightShipPlacing() {
        Grid grid;
        StraightShip horizontalShip(5, 1, 4, false);
        assert(grid.placeShip(horizontalShip));
        for (int j = 1; j < 5; ++j) {
            assert(grid.Getcell(5, j) == '-');
        }
    }

    static void testLShapedShipPlacing() {
    Grid grid;
    LShapedShip lShapedShip(7, 7, 3, true);
    assert(grid.placeLShip(lShapedShip));
    assert(grid.Getcell(7, 7) == '|');
    assert(grid.Getcell(8, 7) == '|');
    assert(grid.Getcell(9, 7) == '|');
    assert(grid.Getcell(9, 8) == '|');
}


    static void testStealthShipPlacing() {
        Grid grid;
        StealthShip stealthShip(0, 9, 3, true);
        assert(grid.placeStealthShip(stealthShip));
        for (int i = 0; i < 3; ++i) {
            assert(grid.Getcell(i, 9) == 'S');
        }
    }
};

#endif // BATTLESHIP_TESTS_H
