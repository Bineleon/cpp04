#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iomanip>

void printHeader(const std::string& str)
{
	int size = 50;
	int totalPad = size - str.size();
	(totalPad < 0) ? totalPad = 0 : totalPad;
	int lPad = totalPad / 2;
	int rPad = totalPad - lPad;

	std::cout << std::endl << SMGREEN;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << std::setfill(' ') << std::setw(lPad + str.size()) << str << std::setw(rPad) << "" << std::endl;
	std::cout << std::setfill('=') << std::setw(size) << "" << std::endl;
	std::cout << RESET << std::endl;
}

int main(void)
{
    {
        printHeader("Test : Basic");
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    {
        printHeader("Test : MateriaSource inventory capacity");
        IMateriaSource* src = new MateriaSource();
        for (int i = 0; i < 6; i++)
        {
            std::cout << SMYELLOW << "Learning new Materia at index : " << i << RESET << std::endl;
            if (i % 2 == 0)
            src->learnMateria(new Ice());
            else
            src->learnMateria(new Cure());
        }
        for (int i = 0; i < 6; i++)
        {
            AMateria *m = dynamic_cast<MateriaSource*>(src)->getInventory(i);
            if (m)
            std::cout << SMYELLOW << "At index : " << i << ", Materia : " << m->getType() << RESET << std::endl;
            else
                std::cout << SMRED << "Invetory full capacity reached : Nothing there" << RESET << std::endl;
            }
        printHeader("Test : Materia Creation");
        for (int i = 0; i < 5; i++)
        {
            AMateria *m;
            if (i == 4)
            m = src->createMateria("blob");
            else if (i % 2 == 0)
            m = src->createMateria("ice");
            else
            m = src->createMateria("cure");
            if (m)
                std::cout << SMYELLOW << "New Materia \"" << m->getType() << "\" created" << RESET << std::endl;
            else
                std::cout << SMRED << "Error: Trying to create unknown materia" << RESET << std::endl;
        }
        printHeader("Test : Character using materia");
        ICharacter* me = new Character("me");
        ICharacter* bob = new Character("bob");
        for (int i = 0; i < 6; i++)
        {
            AMateria *m2;
            if (i == 5)
            m2 = src->createMateria("blob");
            else if (i % 2 == 0)
            m2 = src->createMateria("ice");
            else
            m2 = src->createMateria("cure");
            if (m2)
            {
                std::cout << SMYELLOW << "New Materia \"" << m2->getType() << "\" created" << RESET << std::endl;
                me->equip(m2);
            }
            else
                std::cout << SMRED << "Error: Trying to create unknown materia" << RESET << std::endl;
        }
        std::cout << SMYELLOW << "me use 0 on Bob" << RESET << std::endl;
        me->use(0, *bob);
        std::cout << SMYELLOW << "me use 1 on Bob" << RESET << std::endl;
        me->use(1, *bob);
        std::cout << SMYELLOW << "me use 6 on Bob" << RESET << std::endl;
        me->use(6, *bob);
        printHeader("Test : Character unequiping");
        std::cout << SMYELLOW << "me unequip 0..." << RESET << std::endl;
        me->unequip(0);
        std::cout << SMYELLOW << "Using 0...(should work)" << RESET << std::endl;
        me->use(0, *bob);
        std::cout << SMYELLOW << "Using 3...(should not work)" << RESET << std::endl;
        me->use(3, *bob);
        me->unequip(6);


        printHeader("Test : Copy and assignations");
        Character* clone = new Character(*dynamic_cast<Character*>(me));
        clone->use(1, *bob);

        std::cout << "\nICI\n";
        delete bob;
        delete me;
        delete src;
    }
    return 0;
}
