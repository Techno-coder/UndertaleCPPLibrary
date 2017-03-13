#ifndef PROJECT_CORERESOURCES_H
#define PROJECT_CORERESOURCES_H

namespace ug {

    /**
     * Class encapsulating the loading of essential resources needed by the game
     */
    class CoreResources {
        static bool loaded;
    public:
        static void load();
    };
}

#endif //PROJECT_CORERESOURCES_H
