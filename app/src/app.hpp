#pragma once

#include "command.hpp"
#include "rover.hpp"
#include <iostream>

namespace rover::cli
{

class Application
{
  public:
    auto run() noexcept -> void
    {
        _help();
        std::string input;
        RawCommand raw_command;
        while (_is_running)
        {
            std::cout << "> ";
            std::cin >> input;
            rover::CommandToken token = raw_command.get_command(input);
            switch (token)
            {
            case rover::CommandToken::Left: {
                _rover.rotate_left();
                std::cout << _rover << '\n';
                break;
            }
            case rover::CommandToken::Right: {
                _rover.rotate_right();
                std::cout << _rover << '\n';
                break;
            }
            case rover::CommandToken::Move: {
                _rover.move();
                std::cout << _rover << '\n';
                break;
            }
            case rover::CommandToken::Help: {
                _help();
                break;
            }
            case rover::CommandToken::Quit: {
                _is_running = false;
                break;
            }
            case rover::CommandToken::Unknown:
                _help();
                break;
            }
        }
    }

  private:
    static auto _help() noexcept -> void
    {

        const std::string msg = R"(
Command the robot with:
  L - turn left
  R - turn right
  M - move forward
  ? - this message
  Q - quit
)";

        std::cout << msg << '\n';
    }

  private:
    Rover _rover;
    bool _is_running{true};
};

}; // namespace rover::cli
