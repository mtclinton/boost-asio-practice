#include <iostream>

#include "boost/asio/io_context.hpp"


int main() {
    boost::asio::io_context io_context;
    io_context.run();

    std::cout << "Hello, World!" << std::endl;

    return 0;
}