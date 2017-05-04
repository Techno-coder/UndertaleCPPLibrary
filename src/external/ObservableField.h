#ifndef PROJECT_OBSERVABLEFIELD_H
#define PROJECT_OBSERVABLEFIELD_H

#include <vector>
#include <functional>
#include <map>

template <typename T>
class ObservableField;

template <typename T>
class FieldObserver {
    const unsigned long ID;
    const std::function<void(T, T)> callback;

    inline unsigned long& nextID() {
        static unsigned long id = 0;
        return id;
    };

    std::vector<ObservableField<T>*> fields;
    friend ObservableField<T>;
public:
    FieldObserver(const std::function<void(T, T)> &callback) : ID(nextID()++), callback(callback) {}
    ~FieldObserver() {
        for(auto field : fields) {
            field->unregisterObserver(*this);
        }
    }
};

template <typename T>
class ObservableField {
    T internal;

    std::map<unsigned long, FieldObserver<T>> listeners;
public:
    T getValue() {
        return internal;
    };
    void setValue(T value, bool triggerListeners) {
        if(triggerListeners) {
            for(auto mapValue : listeners) {
                mapValue.second.callback(internal, value);
            }
        }
        internal = value;
    }
    void setValue(T value) { setValue(value, false); }

    void registerObserver(FieldObserver<T> &observer) {
        observer.fields.push_back(this);
        listeners.emplace(std::pair<unsigned long, FieldObserver<T>>(observer.ID, observer));
    };
    void unregisterObserver(const FieldObserver<T> &observer) {
        printf("Unregisted stuff\n");
        listeners.erase(observer.ID);
    };
};

#endif //PROJECT_OBSERVABLEFIELD_H
