#ifndef PROJECT_ATTACKSEQUENCE_H
#define PROJECT_ATTACKSEQUENCE_H

namespace ug {
    /**
     * A base class for a FightEntity
     * This class can be inherited to add other fields
     */
    class FightEntity {
    public:
        /**
         * The name of the sprite
         */
        std::string spriteName = "UNDEFINED";

        /**
         * The x position of the entity starting from the left of the bullet board
         */
        int xPosition = 0;

        /**
         * The y position of the entity starting from the top of the bullet board
         */
        int yPosition = 0;

        /**
         * The rotation of the entity clockwise
         */
        int rotation = 0;

    };

    class EntityBoard {
        std::vector<std::unique_ptr<FightEntity>> entities;
    public:
        /**
         * Add a FightEntity object to the bullet board via a unique pointer
         * A unique pointer is used to avoid unintended memory leaks
         * @param entity The entity
         */
        void addEnemyEntity(const std::unique_ptr<FightEntity>& entity);
    };

    class AttackSequence {
    public:
        /**
         * Get the next board of FightEntitys
         * @param centiseconds The amount of hundredths of a second since the start of the enemies turn
         * @return An EntityBoard
         */
        virtual EntityBoard& getNextEnemyEntityBoard(int centiseconds) = 0;
    };
}


#endif //PROJECT_ATTACKSEQUENCE_H
