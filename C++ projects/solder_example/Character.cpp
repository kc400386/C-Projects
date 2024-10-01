/**********************************************************
File: Character.cpp
 Class: COP 3003, Fall 2022
Author: Caleb Blackburn
Purpose: implementing the character class
**********************************************************/

#include "Character.h"

//Constructors--------------------

Character::Character() {

    level = 0;
    starting_hp = 0;
    hp = 0;

} // default constructor

Character::Character(int level, int starting_hp) {

    this->level = level;
    this->starting_hp = starting_hp;
    this->hp = hp;

} //property

//Accessors--------------------

int Character::get_level(){return level;}
void Character::set_level(int value) {level = value;}

int Character::get_starting_hp() {return starting_hp;}
void Character::set_starting_hp(int value) {starting_hp = value;}

int Character::get_hp() {return hp;} // no setter as hp should never be changed


//Methods--------------------
void Character::set_full_health() {

    hp = level * starting_hp;

}

void Character::heal(int hp) {

    this->hp += hp;
    if (this->hp > level * starting_hp) {

        set_full_health();

    }

}

void Character::damage_taken(int damage) {

    hp -= damage;

}