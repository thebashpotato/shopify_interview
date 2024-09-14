#include "../src/command.hpp"
#include "../src/rover.hpp"
#include <gtest/gtest.h>

using namespace rover;

TEST(RoverTestSuite, CommandTestInvalid)
{
    const RawCommand raw;

    const auto token = raw.get_command("p");

    ASSERT_EQ(token, CommandToken::Unknown);
}

TEST(RoverTestSuite, CommandTestValid)
{
    const RawCommand raw;
    const auto token0 = raw.get_command("l");
    const auto token1 = raw.get_command("r");
    const auto token2 = raw.get_command("m");
    const auto token3 = raw.get_command("?");
    const auto token4 = raw.get_command("q");

    ASSERT_EQ(token0, CommandToken::Left);
    ASSERT_EQ(token1, CommandToken::Right);
    ASSERT_EQ(token2, CommandToken::Move);
    ASSERT_EQ(token3, CommandToken::Help);
    ASSERT_EQ(token4, CommandToken::Quit);
}

TEST(RoverTestSuite, TestRotationLeft)
{
    Rover rover;
    ASSERT_EQ(rover.direction(), Rover::Direction::North);

    rover.rotate_left();
    ASSERT_EQ(rover.direction(), Rover::Direction::West);

    rover.rotate_left();
    ASSERT_EQ(rover.direction(), Rover::Direction::South);

    rover.rotate_left();
    ASSERT_EQ(rover.direction(), Rover::Direction::East);

    rover.rotate_left();
    ASSERT_EQ(rover.direction(), Rover::Direction::North);
}

TEST(RoverTestSuite, TestRotationRight)
{
    Rover rover;
    ASSERT_EQ(rover.direction(), Rover::Direction::North);

    rover.rotate_right();
    ASSERT_EQ(rover.direction(), Rover::Direction::East);

    rover.rotate_right();
    ASSERT_EQ(rover.direction(), Rover::Direction::South);

    rover.rotate_right();
    ASSERT_EQ(rover.direction(), Rover::Direction::West);

    rover.rotate_right();
    ASSERT_EQ(rover.direction(), Rover::Direction::North);
}

TEST(RoverTestSuite, TestMovement)
{
    Rover rover;
    ASSERT_EQ(rover.coord().x, 0);
    ASSERT_EQ(rover.coord().y, 0);

    rover.move();
    ASSERT_EQ(rover.coord().x, 0);
    ASSERT_EQ(rover.coord().y, 1);
}
