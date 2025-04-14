#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& src)
{
    std::cout << "Ice copy constructor called" << std::endl;
    *this = src;
}

Ice& Ice::operator=(const Ice& rhs)
{
    std::cout << "Ice copy assignment operator called" << std::endl;
        // copy members here
    return *this;
}

Ice::~Ice(void)
{
    std::cout << "Ice destructor called" << std::endl;
}
