#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource resource;

public:
    ResourceManager() : resource()
    {
        // Konstruktor domyślny klasy ResourceManager, inicjalizuje obiekt typu Resource
    }

    double get() { return resource.get(); }

    // 5 dobrze zdefiniowanych metod specjalnych klasy ResourceManager
    // Możesz dodać odpowiednie konstruktory kopiujące, przenoszące, destruktory, itp.

    // Destruktor
    ~ResourceManager()
    {
        // Destruktor klasy ResourceManager
    }

    // Konstruktor kopiujący
    ResourceManager(const ResourceManager& other) : resource(other.resource)
    {
        // Implementacja konstruktora kopiującego
    }

    // Operator przypisania
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource = other.resource;
            // Implementacja operatora przypisania
        }
        return *this;
    }

    // Konstruktor przenoszący
    ResourceManager(ResourceManager&& other) noexcept : resource(std::move(other.resource))
    {
        // Implementacja konstruktora przenoszącego
    }

    // Operator przypisania przenoszącego
    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            resource = std::move(other.resource);
            // Implementacja operatora przypisania przenoszącego
        }
        return *this;
    }
};
