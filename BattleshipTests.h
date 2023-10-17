// BattleshipTests.h
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
        testGridInitialization();
        testStraightShipPlacement();
        testHorizontalStraightShipPlacement();
        testLShapedShipPlacement();
        testStealthShipPlacement();
    }

private:
    static void testGridInitialization() {
        Grid grid;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                assert(grid.Getcell(i, j) == ' ');
            }
        }
    }

    static void testStraightShipPlacement() {
        Grid grid;
        StraightShip straightShip(2, 3, 3, true);
        assert(grid.placeShip(straightShip));
        for (int i = 2; i < 5; ++i) {
            assert(grid.Getcell(i, 3) == '|');
        }
    }

    static void testHorizontalStraightShipPlacement() {
        Grid grid;
        StraightShip horizontalShip(5, 1, 4, false);
        assert(grid.placeShip(horizontalShip));
        for (int j = 1; j < 5; ++j) {
            assert(grid.Getcell(5, j) == '-');
        }
    }

    static void testLShapedShipPlacement() {
    Grid grid;
    LShapedShip lShapedShip(7, 7, 3, true); // Update this line
    assert(grid.placeLShip(lShapedShip));
    assert(grid.Getcell(7, 7) == '|');
    assert(grid.Getcell(8, 7) == '|');
    assert(grid.Getcell(9, 7) == '|');
    assert(grid.Getcell(9, 8) == '|');
}


    static void testStealthShipPlacement() {
        Grid grid;
        StealthShip stealthShip(0, 9, 3, true);
        assert(grid.placeStealthShip(stealthShip));
        for (int i = 0; i < 3; ++i) {
            assert(grid.Getcell(i, 9) == 'S');
        }
    }

    /*static void testGameOver() {
        Grid grid;
        // Place and sink all ships to simulate a game over
        StraightShip ship1(0, 0, 1, true);
        StraightShip ship2(0, 1, 1, true);
        grid.placeShip(ship1);
        grid.placeShip(ship2);
        grid.checkHit(0, 0);
        grid.checkHit(0, 1);
        assert(grid.isGameOver());
    }*/
};

#endif // BATTLESHIP_TESTS_H
