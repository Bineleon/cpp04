#include "Character.hpp"

Character::Character(void)
{
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character& src)
{
    std::cout << "Character copy constructor called" << std::endl;
    *this = src;
}

Character& Character::operator=(const Character& rhs)
{
    std::cout << "Character copy assignment operator called" << std::endl;
        // copy members here
    return *this;
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
}

std::string const & Character::getName() const
{
	
}