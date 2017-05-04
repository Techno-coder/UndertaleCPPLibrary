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

    std::map<unsigned long, ObservableField<T>*> fields;
    friend ObservableField<T>;
public:
    FieldObserver(const std::function<void(T, T)> &callback) : ID(nextID()++), callback(callback) {}
    FieldObserver& operator()(T oldValue, T newValue) {
        callback(oldValue, newValue);
        return *this;
    }
    FieldObserver& operator()(T newValue) { return operator()(T(), newValue); }
    ~FieldObserver() {
        for(auto field : fields) {
            field.second->listeners.erase(ID);
        }
    }
};

template <typename T>
class ObservableField {
    const unsigned long ID;
    T internal;

    inline unsigned long& nextID() {
        static unsigned long id = 0;
        return id;
    };

    std::map<unsigned long, FieldObserver<T>*> listeners;
    friend FieldObserver<T>;
public:
    ObservableField() : ID(nextID()++) {}
    ObservableField(T value) : ID(nextID()++), internal(value) {}

    T getValue() const {
        return internal;
    };
    void setValue(const T &value, bool triggerListeners) {
        if(triggerListeners) {
            for(auto mapValue : listeners) {
                mapValue.second->callback(internal, value);
            }
        }
        internal = value;
    }
    void setValue(const T &value) { setValue(value, false); }

    void operator=(const T &value) {
        setValue(value);
    }
    operator T() const {
        return getValue();
    }

    void registerObserver(FieldObserver<T> *const observer) {
        observer->fields[ID] = this;
        listeners[observer->ID] = observer;
    };
    void unregisterObserver(FieldObserver<T> *const observer) {
        observer->fields.erase(ID);
        listeners.erase(observer->ID);
    };
};

#endif //PROJECT_OBSERVABLEFIELD_H
