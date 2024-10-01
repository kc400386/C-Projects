/**********************************************************
 File: Character.h
 Class: COP 3003, Fall 2022
 Author: Caleb Blackburn
 Purpose: declaring the character class
**********************************************************/

//HEADER GUARD
#ifndef SOLDER_EXAMPLE_CHARACTER_H
#define SOLDER_EXAMPLE_CHARACTER_H


class Character {

public:

    //Constructors--------------------

    Character(); // default constructor

    Character(int level, int starting_hp); //property

    //Accessors--------------------

    int get_level();
    void set_level(int value);

    int get_starting_hp();
    void set_starting_hp(int value);

    int get_hp();

    //Methods--------------------

    void set_full_health();
    void heal(int hp);
    void damage_taken(int damage);

private:

    int level;
    int starting_hp;     //starting health
    int hp;              // current health

};

#endif //SOLDER_EXAMPLE_CHARACTER_H
