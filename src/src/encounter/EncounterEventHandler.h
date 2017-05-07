#ifndef PROJECT_ENCOUNTEREVENTHANDLER_H
#define PROJECT_ENCOUNTEREVENTHANDLER_H

#include "states/EncounterState.h"

namespace ug {
    class EncounterState;

    class EncounterEventHandler {
    protected:
        void exitDefendState(EncounterState &encounterState);
        void setArenaSize(float width, float height, EncounterState &encounterState);
    public:
        virtual /**
         * Called when the player begins the encounter (the first time they enter the ActionSelectState)
         */
        void onBegin(EncounterState &encounterState) {};

        /**
         * Called when the player enters the Defend state
         */
        virtual void onDefendBegin(EncounterState &encounterState) {};
        /**
         * Called when the player exits the Defend state
         */
        virtual void onDefendEnd(EncounterState &encounterState) {};
        /**
         * Called every 60th of a second while in the Defend state
         */
        virtual void onDefendUpdate(EncounterState &encounterState) {};
    };
}



#endif //PROJECT_ENCOUNTEREVENTHANDLER_H
