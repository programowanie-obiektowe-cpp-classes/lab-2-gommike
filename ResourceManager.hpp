#pragma once

#include "Resource.hpp"

class ResourceManager
{
private: 
    Resource *resource;

public:
    ResourceManager(){} // Konstruktor domyślny klasy ResourceManager

    ~ResourceManager(){} // Destruktor klasy ResourceManager

    double get() { return resource->get(); }



    ResourceManager(const ResourceManager& other) : resource(other.resource){} // Konstruktor kopiujący

    
    ResourceManager& operator=(const ResourceManager& other) //Kopiujący Operator przypisania
    {
        if (this != &other) {
            resource = other.resource;
        }
        return *this;

    }

    
    ResourceManager(ResourceManager&& other) : resource(nullptr) // Konstruktor przenoszący
    { 
        resource = other.resource;
        other.resource = nullptr;
    }     

    
    ResourceManager& operator=(ResourceManager&& other)  // Operator przypisania przenoszącego
    {
        if (this != &other) {
            resource       = other.resource;
            other.resource = nullptr;
        }
        return *this;
    }
};
