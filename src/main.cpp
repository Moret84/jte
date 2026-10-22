#include "JTE.hpp"

#include <iostream>

#include <tclap/ArgException.h>

int main(int argc, char ** argv)
{
    try
    {
        JTE J(argc, argv);
        return J.run() ? 0 : 1;
    }
    catch(TCLAP::ArgException &e)
    {
        std::cerr << "Error: " << e.error() << std::endl;
    }
    catch(std::string &s)
    {
        std::cerr << "Error: " << s << std::endl;
    }

    return 1;
}
