#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H

#include"Player.h"

class Fighter : public Player{
protected:
    const uint attackDamage=100;
    const uint healPower=0;
    const uint maxHP=400;

    /**
     * Attack damage 100
     * Heal power 0
     * Max HP 400
     * Goal Priorities -> {ATTACK,TO_ENEMY,CHEST} in decreasing order
     * Class abbreviation -> "fi" or "FI"
     * Can move to adjacent up, down, left or right square
     * Can attack to adjacent up, down, left or right square
     *
     */
public:
    int getAttackDamage() const;

    int getHealPower() const;

    int getMaxHP() const;
    Fighter(uint id, int x, int y, Team team);
    /**
	 * For each subclass of Player there are different priority lists defined
	 * that controls the next action to take for that Player. It is given in the
	 * header of the subclasses.
	 *
	 * @return the goal priority list for the Player
	 */
    std::vector<Goal> getGoalPriorityList();
    /**
     * @return the class abbreviation of player, if the player is on the barbarian
     * team, the abbreviation will consist of uppercase characters, otherwise it
     * will consist of lowercase characters.
     *
     */

    const std::string getClassAbbreviation() const;
    /**
	 * @Important The coordinates may not be on the board.
	 *
	 * @return the coordinates that the unit is able to attack given the position
	 * of the unit. Empty vector if the unit cannot attack.
	 */
    std::vector<Coordinate> getAttackableCoordinates();

    /**
     * @Important The coordinates may not be on the board.
     *
     * @return the coordinates the unit is able to move given the position of the
     * unit. Empty vector if the unit cannot move.
     */
    std::vector<Coordinate> getMoveableCoordinates();

    /**
     *
     * @return the coordinates the unit is able to heal allies given the position of the
     * unit. Empty vector if none available.
     */
    std::vector<Coordinate> getHealableCoordinates();

};

#endif
