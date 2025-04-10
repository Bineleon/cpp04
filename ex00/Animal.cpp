#include "Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& src)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal& Animal::operator=(const Animal& rhs)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
        // copy members here
    return *this;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}
