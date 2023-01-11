/**********************************************************
 File: solder_example
 Class: COP 3003, Fall 2022
 Author: Caleb Blackburn
 Purpose: lab for a solder npc
**********************************************************/
#include <iostream> // console i/0
#include <cstdlib>  // random number
#include <ctime>     // random seed
#include "Character.h" // character class

//  hp will change and stay changed until return to function then will unchange

// constants and types
//*********************************************************

const int BASE_DAMAGE = 10;
const int HIT_CHANCE = 20;
const int START_LVL_DIE = 6;
const int STARTING_HP_DIE = 20;
const int ENCOUNTER_DIE = 20;

enum solder_stance {

    HOMING,
    PATROLLING,
    ATTACKING,
    DEFENDING,
    RETREATING

}; // end solder stance

//*********************************************************

// function prototypes and declarations
//*********************************************************

void entity_creation( Character * entity);
// this function heals the solder if not a full health and send them back out whe full
solder_stance homing(Character &solder);
// this function checks if an enemy appears and sends them to either fight,defend, or run
solder_stance patrolling(Character solder,Character *& enemy); // !!!originally only enemy had &
//this function tells the solder how to fight a weaker enemy
//and sends them to either heal or continue patrolling depending on the result of that fight
solder_stance attacking(Character &solder,Character *& enemy);
// this function tells the solder how to defend from an enemy of even power
// and sends them to either heal or continue patrolling depending on the result of that fight
solder_stance defending(Character &solder,Character *& enemy);
// this function has the solder run from a powerful enemy
//and sends them to either heal or continue patrolling depending on the result of that fight
solder_stance retreating(Character &solder,Character *& enemy);
// this function determines whether an attack hits or not.
bool attack_hit();
// this function determines how combat plays out
void combat(int extra_dmg, Character & solder, Character * enemy);


//*********************************************************

// function definitions are everything bellow this
//*********************************************************



int main() {

    // makes random numbers
    std::srand(std::time(NULL));

    Character solder;

    entity_creation(&solder);

    std::cout << "A solder of level " << solder.get_level() << " has been recruited and they ";
    std::cout << solder.get_hp() << " hp" << std::endl;

    Character * enemy = nullptr;

    solder_stance solder_stance = HOMING;

    do {
        switch(solder_stance) {

            case HOMING:

                solder_stance = homing(solder);

                break;

            case PATROLLING:

                solder_stance = patrolling(solder, enemy); // neither had & originally

                break;

            case ATTACKING:

                solder_stance = attacking(solder, enemy);

                break;

            case DEFENDING:


                solder_stance = defending(solder, enemy);

                break;

            case RETREATING:

                solder_stance = retreating(solder, enemy);

        } // end switch solder_stance

    } while (solder.get_hp() > 0); // end solder loop

    std::cout << "The solder has fallen and shall be remembered...." << std::endl;

    return 0;

} // end main

/**
 *
 * @param solder
 * @return a solder_stance to link to the next function
 */
solder_stance homing(Character &solder) {

    if (solder.get_hp() >= solder.get_level() * solder.get_starting_hp()) {

        std::cout << "Solder is at full health commencing patrol." << std::endl;
        solder.set_full_health();
        return PATROLLING;

    } // end full health check

    else {

        std::cout << "Solder is missing hp, returning to base." << std::endl;
        std::cout << "Solder is healing to full." << std::endl;
        solder.set_full_health();
        return HOMING;

    } // end heal check

} // end homing

/**
 *
 * @param solder
 * @param enemy
 * @return a solder_stance to link to the next stance
 */
solder_stance patrolling(Character solder,Character *& enemy) {

    int enemy_encounter = std::rand() % ENCOUNTER_DIE + 1;

    if (enemy_encounter > 10) {

        enemy = new Character();
        entity_creation(enemy);

        std::cout << "Solder has found a level " << enemy->get_level()
                  << " enemy with " << enemy->get_hp() << " hp." << std::endl;

        if (solder.get_level() > enemy->get_level() + 2) {

            //attacking(solder, enemy);

            return ATTACKING;

        } // end attacking check

        else if (enemy->get_level() > solder.get_level() + 2) {

            //retreating(solder, enemy);

            return RETREATING;

        } // end retreating check

        else {

            //defending(solder, enemy);

            return DEFENDING;

        } // end defending check


    }   // end enemy encounter

    else {

        std::cout << "No enemy's spotted resuming patrol." << std::endl;

    } // end else no enemy

    return PATROLLING;

} // end patrolling

/**
 *
 * @param solder
 * @param enemy
 * @return a solder_stance to link to the next stance
 */
solder_stance attacking(Character &solder,Character *& enemy) {

    int extra_dmg = 8;
    int healing_factor = 0;

    std::cout << "The solder is in an offensive stance." << std::endl;

    combat(extra_dmg,  solder,  enemy);
    solder.heal(healing_factor);
    std::cout << "The solder has healed " << healing_factor << " and has " << solder.get_hp() << " hp" << std::endl;

    enemy->heal(healing_factor);
    std::cout << "The enemy has healed " << healing_factor << " and has " <<enemy->get_hp() << " hp" << std::endl;

    if (enemy->get_hp() <= 0) {

        std::cout << "The solder has slain the enemy continuing patrol." << std::endl;
        delete enemy;
        return PATROLLING;

    } // end enemy dead check

    else if (solder.get_hp() / 2 < solder.get_level() * solder.get_starting_hp() / 2) {

        std::cout << "The solder is moving to a defensive stance." << std::endl;
        return DEFENDING;

    } // end defensive if

    else {

        std::cout << "The solder is remaining in their current stance." << std::endl;
        return ATTACKING;

    } // end remain in stance check

} // end attacking

/**
 *
 * @param solder
 * @param enemy
 * @return a solder_stance to link to the next stance
 */
solder_stance defending(Character &solder,  Character *& enemy) {

    int extra_dmg = 4;
    int healing_factor = 4;

    std::cout << "The solder is in an defensive stance." << std::endl;

    combat(extra_dmg, solder, enemy);

    solder.heal(healing_factor);
    std::cout << "The solder has healed " << healing_factor << " and has " << solder.get_hp() << " hp" << std::endl;

    enemy->heal(healing_factor);
    std::cout << "The enemy has healed " << healing_factor << " and has " <<enemy->get_hp() << " hp" << std::endl;

    if (enemy->get_hp() <= 0) {

        std::cout << "The solder has slain the enemy continuing patrol." << std::endl;
        delete enemy;
        return PATROLLING;

    } // end enemy dead check

    else if ((solder.get_hp() / 4 < solder.get_level() * solder.get_starting_hp() / 4)) {

        std::cout << "The solder is retreating." << std::endl;
        return RETREATING;

    } // end retreating check

    else {

        std::cout << "The solder is remaining in their current stance." << std::endl;
        return DEFENDING;

    }// end stay in stance check

} // end defending

/**
 *
 * @param solder
 * @param enemy
 * @return a solder_stance to link to the next stance
 */
solder_stance retreating(Character &solder,Character *& enemy) {

    int extra_dmg = 0;
    int healing_factor = 8;

    combat(extra_dmg, solder, enemy);
    solder.heal(healing_factor);
    std::cout << "The solder has healed " << healing_factor << " and has " << solder.get_hp() << " hp" << std::endl;

    enemy->heal(healing_factor);
    std::cout << "The enemy has healed " << healing_factor << " and has " <<enemy->get_hp() << " hp" << std::endl;

    if (enemy->get_hp() <= 0) {

        std::cout << "The solder has slain the enemy ar great cost, solder is retreating." << std::endl;
        delete enemy;
        return HOMING;

    } // end enemy dead check

    else if (solder.get_hp() / 2 < solder.get_level() * solder.get_starting_hp() / 2) {

        std::cout << "The solder is moving to a defensive stance." << std::endl;
        return DEFENDING;

    } // end defensive if

    else {

        std::cout << "The solder is remaining in their current stance." << std::endl;
        return RETREATING;

    } // end remain in stance

} // end retreating

/**
 *
 * @param entity
 */
void entity_creation( Character * entity) {

    int level =  std::rand() % START_LVL_DIE + 1;
    int starting_hp = std::rand() % STARTING_HP_DIE + 1;
    entity->set_level(level);
    entity->set_starting_hp(starting_hp);
    entity->set_full_health();

} // end entity creation

/**
 *
 * @return
 */
bool attack_hit() {

    int hit_chance = std::rand() % HIT_CHANCE + 1;

    if (hit_chance > 9 ) {

        return true;

    } // end check if hit

    else {

        return false;

    } // end check if miss

} // end bool attack hit

void combat(int extra_dmg, Character &solder, Character * enemy) {

    int damage_dealt = BASE_DAMAGE + extra_dmg;

    if (attack_hit() == true) {

        enemy->damage_taken(damage_dealt);
        std::cout << "The solder has hit the enemy dealing " << damage_dealt << ". ";
        std::cout << "The enemy has " << enemy->get_hp() << " hp remaining." << std::endl;

    } //end solder hit

    else {

        std::cout << "The solder has missed, the enemy takes 0 damage!" << std::endl;

    } // end solder miss

    if (attack_hit()) {

        solder.damage_taken(BASE_DAMAGE);
        std::cout << "The enemy has hit the solder dealing " << BASE_DAMAGE << ". ";
        std::cout << "The solder has " << solder.get_hp() << " hp remaining." << std::endl;

    } //end enemy hit

    else {

        std::cout << "The enemy has missed, the solder takes 0 damage!" << std::endl;

    } // end enemy miss

} // end combat