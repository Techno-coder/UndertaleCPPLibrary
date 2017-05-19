#ifndef TECHNOCODER_RESOURCES_H
#define TECHNOCODER_RESOURCES_H

template <typename T>
class Resources {
protected:
    class ResourceItem {
        const short ID;
    protected:
        ResourceItem(Resources<T>* const resources) : ID(resources->nextID++), resources(resources) {}
        Resources<T>* const resources;
    public:
        virtual ~ResourceItem() {};

        const short getID() const {
            return ID;
        }

        const operator T&() const {
            return resources->resourceHolder[getID()];
        }
    };
public:
    virtual ~Resources() {}

    short nextID = 0;
    std::map<short, T> resourceHolder;
};

#endif
