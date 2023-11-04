#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource;

public:
    ResourceManager() : resource(new Resource()) {} // Konstruktor klasy ResourceManager
    ~ResourceManager() { delete resource;  }         // Destruktor klasy ResourceManager

    double get() { return resource->get(); }

    ResourceManager(const ResourceManager& other) : resource(new Resource(*other.resource)) {} // Konstruktor kopiujący

    ResourceManager& operator=(const ResourceManager& other) // Kopiujący Operator przypisania
    {
        if (this != &other) {
            delete resource;
            resource = new Resource(*other.resource);
        }
        return *this;
    }

    ResourceManager(ResourceManager&& other) : resource(std::move(other.resource)) {} // Konstruktor przenoszący
    
    ResourceManager& operator=(ResourceManager&& other)
    {
        if (this != &other) {
            delete resource;
            resource = std::move(other.resource);
        }
        return *this;
    }
};
