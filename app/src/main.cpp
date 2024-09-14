#include "app.hpp"
#include <cstdlib>

auto main() -> int
{

    rover::cli::Application app;

    app.run();

    return EXIT_SUCCESS;
}
