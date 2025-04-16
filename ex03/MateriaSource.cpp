#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    initInvetory();
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = src;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    std::cout << "MateriaSource copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        deleteInvetory();
        copyInventory(rhs);
    }
    return *this;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource destructor called" << std::endl;
    deleteInvetory();
}

void MateriaSource::learnMateria(AMateria* m)
{
    int i = 0;
    if (!m)
        return;
    while (i < 4 && _inventory[i])
        i++;
    if (i < 4)
        _inventory[i] = m->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (i >= 0 && i < 4 && _inventory[i] && _inventory[i]->getType() == type)
            return (_inventory[i]->clone());
    }
    return 0;
}

void MateriaSource::initInvetory(void)
{
    for (int i = 0; i < 4 && _inventory[i]; ++i)
        _inventory[i] = NULL;
}

void MateriaSource::deleteInvetory(void)
{
    for (int i = 0;  i < 4 && _inventory[i]; i++)
    {
        delete _inventory[i];
        _inventory[i] = NULL;
    }
}

void MateriaSource::copyInventory(const MateriaSource& src)
{
    for (int i = 0; i < 4 && src._inventory[i]; i++)
        _inventory[i] = src._inventory[i]->clone();
}

AMateria* MateriaSource::getInventory(int i)
{
    if (i >= 0 && i < 4)
        return (_inventory[i]);
    return NULL;
}
