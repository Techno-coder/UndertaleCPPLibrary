#ifndef PROJECT_ACTCOMMAND_H
#define PROJECT_ACTCOMMAND_H

#include <string>
#include "enemies/Enemy.h"

class Enemy;

namespace ug {

    /**
     * Inherit this class to create your own Act option
     */
    class ActCommand {
        /**
         * @todo Consider allowing actID to be changed
         * @todo Consider moving the actID out of this class into the enemy
         */
        const std::string actID;

        /**
         * @todo Consider allowing the display name of the act to be changed
         */
        const std::string actName;
    public:
        /**
         * Non overrideable constructor
         * If no actID is provided the actName is used
         * @param actID The id of this act command (useful if there are multiple acts with the same name)
         * @param actName The name of the act shown on the act selection menu
         */
        ActCommand(const std::string& actID, const std::string& actName);
        ActCommand(const std::string& actName);

        /**
         * Getter for ActID
         * @return The ActID for this act command
         */
        const std::string& getActID() const;

        /**
         * Getter for ActName
         * @return The ActName for this act command
         */
        const std::string& getActName() const;

        /**
         * Called when this act is selected from the menu
         */
        virtual void handle(Enemy& enemy) = 0;
    };
}

#endif //PROJECT_ACTCOMMAND_H
