#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void): _floor(NULL),  _name("NoName")
{
    std::cout << "Character default constructor called" << std::endl;
    initInvetory();
}

Character::Character(std::string const &name): _floor(NULL), _name(name)
{
    std::cout << "Character constructor called with name : " << name << std::endl;
    initInvetory();
}

Character::Character(const Character& src)
{
    std::cout << "Character copy constructor called" << std::endl;
    *this = src;
}

Character& Character::operator=(const Character& rhs)
{
    std::cout << "Character copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _name = rhs._name;
        cleanFloor();
        copyFloor(rhs._floor);
        deleteInvetory();
        copyInventory(rhs);
    }
    return *this;
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
    // cleanFloor();
    deleteInvetory();
}

void Character::initInvetory(void)
{
    for (int i = 0; i < 4 && _inventory[i]; ++i)
        _inventory[i] = NULL;
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    int i = 0;
    if (!m)
        return;
    while (i < 4 && _inventory[i])
        i++;
    if (i < 4)
        _inventory[i] = m;
}

void Character::unequip(int idx)
{
    if (idx < 4 && idx >= 0 && _inventory[idx])
    {
        std::cout << SMGREEN << "Dropped Materia \"" << _inventory[idx]->getType() << "\" at index : " << idx << RESET << std::endl;
        addToFloor(_inventory[idx]);
        shiftTabLeft(idx);
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 4 && idx >= 0 && _inventory[idx])
        _inventory[idx]->use(target);
}

void Character::addToFloor(AMateria* m)
{
    t_floor* newNode = new t_floor;

    newNode->ptr = m;
    newNode->next = _floor;
    _floor = newNode;
}

void Character::shiftTabLeft(int idx)
{
    for (int i = idx; i < 3; i++)
        _inventory[i] = _inventory[i + 1];
    _inventory[3] = NULL;
}

void Character::deleteInvetory(void)
{
    for (int i = 0; i < 4 && _inventory[i] ; i++)
    {
        delete _inventory[i];
        _inventory[i] = NULL;
    }
}

void Character::cleanFloor(void)
{
    t_floor* tmp;

    while (_floor)
    {
        tmp = _floor;
        _floor = _floor->next;
        delete tmp->ptr;
        delete tmp;
    }
}

void Character::copyFloor(t_floor* src)
{
    while (src)
    {
        AMateria *copy = src->ptr->clone();
        addToFloor(copy);
        src = src->next;
    }
}

void Character::copyInventory(const Character& src)
{
    for (int i = 0; i < 4 && src._inventory[i]; i++)
        _inventory[i] = src._inventory[i]->clone();
}
