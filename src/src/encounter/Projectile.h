#ifndef PROJECT_PROJECTILE_H
#define PROJECT_PROJECTILE_H

#include <SFML/Graphics/Sprite.hpp>
#include <vector>

namespace ug {
    class Projectile;

    class ProjectileInstance {
        ProjectileInstance(const Projectile &projectile);
        friend Projectile;

        const Projectile& projectile;
    public:
        Projectile const& getProjectile();
    };

    class Projectile {
    protected:

        /**
         * @warning The position of the sprite should be relative to the bullet board not to the screen
         */
        sf::Sprite sprite;
    public:
        virtual void onCollide() = 0; //TODO input some variables here? maybe? IDK possibly input a projectile instance
        virtual void onUpdate(ProjectileInstance& projectile) = 0; //TODO ditto

        const sf::Sprite &getSprite() const;
        ProjectileInstance createInstance();
    };

    class ProjectileSpawner {
    public:
        virtual std::vector<ProjectileInstance> getInitialProjectiles();
        virtual std::vector<ProjectileInstance> getNewProjectiles();
    };
}

#endif //PROJECT_PROJECTILE_H
