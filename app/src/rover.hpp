#pragma once

#include <iostream>

namespace rover
{

struct Point
{
    int x{};
    int y{};
};

class Rover
{
  public:
    enum class Direction
    {
        North,
        West,
        East,
        South,
    };

    Rover() : _curr_coord({0, 0}), _curr_direction(Direction::North)
    {
        std::cout << "Hello! Robot coming online." << '\n';
    }

    ~Rover()
    {
        std::cout << "Robot shutting down." << '\n';
    }

    Rover(const Rover &) = default;
    Rover(Rover &&) = delete;
    auto operator=(const Rover &) -> Rover & = default;
    auto operator=(Rover &&) -> Rover & = delete;

  public:
    auto move() noexcept -> void
    {
        switch (_curr_direction)
        {
        case Direction::North:
            _curr_coord.y += 1;
            break;
        case Direction::West:
            _curr_coord.x -= 1;
            break;
        case Direction::East:
            _curr_coord.x += 1;
            break;
        case Direction::South:
            _curr_coord.y -= 1;
            break;
        }
    }

    auto rotate_left() noexcept -> void
    {
        switch (_curr_direction)
        {
        case Direction::North:
            _curr_direction = Direction::West;
            break;
        case Direction::West:
            _curr_direction = Direction::South;
            break;
        case Direction::East:
            _curr_direction = Direction::North;
            break;
        case Direction::South:
            _curr_direction = Direction::East;
            break;
        }
    }

    auto rotate_right() noexcept -> void
    {
        switch (_curr_direction)
        {
        case Direction::North:
            _curr_direction = Direction::East;
            break;
        case Direction::West:
            _curr_direction = Direction::North;
            break;
        case Direction::East:
            _curr_direction = Direction::South;
            break;
        case Direction::South:
            _curr_direction = Direction::West;
            break;
        }
    }

    [[nodiscard]] auto direction() const noexcept -> const Direction &
    {
        return _curr_direction;
    }

    [[nodiscard]] auto coord() const noexcept -> const Point &
    {
        return _curr_coord;
    }

  public:
    friend auto operator<<(std::ostream &os, const Rover &rover) -> std::ostream &
    {
        os << "Robot at (" << rover._curr_coord.x << "," << rover._curr_coord.y << ")" << " facing "
           << rover._to_string();
        return os;
    }

  private:
    [[nodiscard]] auto _to_string() const noexcept -> std::string
    {
        std::string str;
        switch (_curr_direction)
        {
        case Direction::North:
            str.append("North");
            break;

        case Direction::West:
            str.append("West");
            break;

        case Direction::East:
            str.append("East");
            break;

        case Direction::South:
            str.append("South");
            break;
        }
        return str;
    }

  private:
    Point _curr_coord;
    Direction _curr_direction{};
};

} // namespace rover
