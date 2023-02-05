#ifndef OOP_SINGLETON_H
#define OOP_SINGLETON_H


template<typename T>
class Singleton {
private:
    static T *instance;

protected:
    Singleton() = default;
public:
    static T *getInstance() {
        if (!instance)
            instance = new T;

        return instance;
    }
};

template<typename T>
T *Singleton<T>::instance = nullptr;


#endif //OOP_SINGLETON_H
