#pragma once

#include "./utility.hpp"
#include <string>

namespace rover
{

enum class CommandToken
{
    Left,
    Right,
    Move,
    Help,
    Quit,
    Unknown,
};

struct RawCommand
{
  public:
    RawCommand() = default;

  public:
    std::string left{"L"};
    std::string right{"R"};
    std::string move{"M"};
    std::string help{"?"};
    std::string quit{"Q"};

    [[nodiscard]] inline auto get_command(const std::string &input) const noexcept -> CommandToken
    {
        const auto uppercase = to_upper(input);

        if (uppercase == left)
        {
            return CommandToken::Left;
        }
        else if (uppercase == right)
        {
            return CommandToken::Right;
        }
        else if (uppercase == move)
        {
            return CommandToken::Move;
        }
        else if (uppercase == help)
        {
            return CommandToken::Help;
        }
        else if (uppercase == quit)
        {
            return CommandToken::Quit;
        }
        else
        {
            return CommandToken::Unknown;
        }
    }
};

} // namespace rover
