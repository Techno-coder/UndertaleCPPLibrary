#ifndef PROJECT_PROJECTILE_H
#define PROJECT_PROJECTILE_H

#include <SFML/Graphics/Sprite.hpp>
#include <vector>

namespace ug {
    class Projectile;

    class ProjectileInstance {
        ProjectileInstance(Projectile &projectile);
        friend Projectile;

        Projectile* projectile;
    public:
        Projectile& getProjectile();
    };

    class Projectile {
    protected:

        /**
         * @warning The position of the sprite should be relative to the bullet board not to the screen
         */
        sf::Sprite sprite;
    public:

        /**
         * Called when the projectile collides with the players soul
         */
        virtual void onCollide() = 0; //TODO input some variables here? maybe? IDK possibly input a projectile instance

        /**
         * Called every 60th of a second
         * @param projectile The projectile instance
         */
        virtual void onUpdate(ProjectileInstance& projectile) = 0; //TODO ditto

        sf::Sprite &getSprite();

        /**
         * Creates a projectile instance from this projectile
         * @return A projectile instance
         */
        ProjectileInstance createInstance();
    };

    class ProjectileSpawner {
    public:
        virtual std::vector<ProjectileInstance> getInitialProjectiles();
        virtual std::vector<ProjectileInstance> getNewProjectiles();
        virtual void onUpdate();
    };
}

#endif //PROJECT_PROJECTILE_H
