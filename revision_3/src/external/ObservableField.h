#ifndef PROJECT_OBSERVABLEFIELD_H
#define PROJECT_OBSERVABLEFIELD_H

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

    friend ObservableField<T>;
public:
    FieldObserver(const std::function<void(T, T)> &callback) : ID(nextID()++), callback(callback) {}
    FieldObserver& operator()(T oldValue, T newValue) {
        callback(oldValue, newValue);
        return *this;
    }
    FieldObserver& operator()(T newValue) { return operator()(T(), newValue); }
};

template <typename T>
class ObservableField {
    T internal;

    std::map<unsigned long, FieldObserver<T>*> listeners;
    friend FieldObserver<T>;
public:
    ObservableField() {};
    ObservableField(T value) : internal(value) {}

    T getValue() const {
        return internal;
    };
    void setValue(const T &value, bool triggerListeners = true) {
        if(triggerListeners) {
            for(auto mapValue : listeners) {
                mapValue.second->callback(internal, value);
            }
        }
        internal = value;
    }

    void operator=(const T &value) {
        setValue(value);
    }
    operator T() const {
        return getValue();
    }

    void registerObserver(FieldObserver<T> *const observer) {
        listeners[observer->ID] = observer;
    };
    void unregisterObserver(FieldObserver<T> *const observer) {
        listeners.erase(observer->ID);
    };
};

#endif //PROJECT_OBSERVABLEFIELD_H
