#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& src)
{
    std::cout << "Cure copy constructor called" << std::endl;
    *this = src;
}

Cure& Cure::operator=(const Cure& rhs)
{
    std::cout << "Cure copy assignment operator called" << std::endl;
        // copy members here
    return *this;
}

Cure::~Cure(void)
{
    std::cout << "Cure destructor called" << std::endl;
}

void Cure::use(ICharacter& target)
{
	std::cout << "Ice : \"* shoots an ice bolt at " << target.getName() << " *\"\n";
}