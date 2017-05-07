#ifndef PROJECT_PROJECTILE_H
#define PROJECT_PROJECTILE_H

#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <functional>

namespace ug {
    class EncounterState;
    class Projectile;

    typedef std::function<void(ug::EncounterState &state, Projectile& projectile)> ProjectileEventHandler;

    class Projectile {
    protected:
        sf::Sprite sprite;

        ProjectileEventHandler onCollide = [](ug::EncounterState &state, Projectile& projectile){};
        ProjectileEventHandler onUpdate = [](ug::EncounterState &state, Projectile& projectile){};
    public:
        /**
         * Called when the projectile collides with the players soul
         * @return A modifiable reference to the event handler
         */
        void collide(ug::EncounterState &state);
        void setOnCollide(const ProjectileEventHandler &onCollide);

        /**
         * Called every 60th of a second
         * @return A modifiable reference to the event handler
         */
        void update(ug::EncounterState &state); //TODO ditto
        void setOnUpdate(const ProjectileEventHandler &onUpdate);

        /**
         * @warning The position of the sprite should be relative to the center of the bullet board not to the screen
         */
        sf::Sprite& getSprite();

        /**
         * Creates a projectile from the projectile specified
         * @return A projectile
         */
        static Projectile clone(Projectile toBeCloned);
    };

    class ProjectileSpawner {
    public:
        std::function<std::vector<Projectile>()> getInitialProjectiles = [](){ return std::vector<Projectile>(); };
        std::function<std::vector<Projectile>()> getNewProjectiles = [](){ return std::vector<Projectile>(); };
        std::function<void()> onUpdate = [](){ return std::vector<Projectile>(); };
    };
}

#endif //PROJECT_PROJECTILE_H
