#include "AMateria.hpp"

AMateria::AMateria(void)
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type): _type(type)
{
	std::cout << "AMateria constructor called with type : " << type << std::endl;

}

AMateria::AMateria(const AMateria& src)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = src;
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
    std::cout << "AMateria copy assignment operator called" << std::endl;
        // copy members here
    return *this;
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (_type);
}