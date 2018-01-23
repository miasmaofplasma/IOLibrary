//
// Created by ryan on 1/22/18.
//

#ifndef OCEANIO_CLIENT_ANY_H
#define OCEANIO_CLIENT_ANY_H

#include <bits/unique_ptr.h>
#include <memory>
#include <type_traits>
#include <typeinfo>
#include <iostream>

class any
{
public:
   struct AnyConcept
   {
       virtual ~AnyConcept(){}
   public:
       virtual AnyConcept* clone() = 0;
       virtual const std::type_info& type() = 0;
       virtual size_t  size() = 0;
   };

    template <typename T> struct AnyModel : AnyConcept
    {

        AnyModel(const T& t): object(t){

        }
        virtual ~AnyModel(){}
        T get()
        {
            return object;
        }

    public:
        AnyModel* clone() override
        {
            return new AnyModel<T>(object);
        }

        const std::type_info& type() override
        {
            return typeid(object);
        }

        size_t size() override {
            return sizeof(T);
        }


    protected:
        T object;
    };

    std::unique_ptr<AnyConcept> object;

public:

    any() : object{nullptr}{};

    template<typename T>
    any(const T& any) : object{new AnyModel<T>(any)} {
        static_assert(std::is_integral<T>::value || std::is_floating_point<T>::value || std::is_same<T,std::string>::value, "bad type");
    }

    //copy constructors
    any(const any& other): object{std::unique_ptr<AnyConcept>(other.object.get()->clone())} {}

    any& operator=(const any& other)
    {
        object = std::unique_ptr<AnyConcept>(other.object.get()->clone());
    }

    any(any&& other) : object{std::move(other.object)}
    {
    }

    any&operator=(any&& other)
    {
        object = std::move(other.object);
        return *this;
    }
    template <typename T>
    any& operator=(const T& new_type)
    {
        object = std::unique_ptr<AnyConcept>(new AnyModel<T>(new_type));
    }

    template <typename T>
    T get()
    {
        AnyModel<T>* val = dynamic_cast<AnyModel<T>*>(object.get());
        if(val != nullptr)
        {
            return val->get();
        }
        else return T();
    }

    template <typename T>
    T get(bool& successful)
    {
        AnyModel<T>* val = dynamic_cast<AnyModel<T>*>((T)object.get());
        if(val != nullptr)
        {
            successful = true;
            return val->get();
        }
        else
        {
            successful = false;
            return T();
        }
    }

    size_t size()
    {
        if(object.get() != nullptr)
        {
            return object.get()->size();
        }
        else return 0;
    }


    const std::type_info& type()
    {
       if(object.get() != nullptr)
       {
           return object.get()->type();
       }
        else
       {
           throw std::bad_typeid();
       }

    }

    bool has_value(){
        return object.get() != nullptr;
    }


};
#endif //OCEANIO_CLIENT_ANY_H
