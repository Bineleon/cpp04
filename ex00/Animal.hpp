#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    public:
        Animal(void);
        Animal(const Animal& src);
        Animal& operator=(const Animal& rhs);
        ~Animal(void);
		void makeSound(void);

    protected:
		std::string type;

};

#endif
