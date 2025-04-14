#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = src;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
        // copy members here
    return *this;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource destructor called" << std::endl;
}
