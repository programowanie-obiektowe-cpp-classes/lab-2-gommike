#pragma once

#include "Resource.hpp"

class ResourceManager
{
private: 
	Resource *resource;

public:
     ResourceManager() : resource(new Resource()) {}

	 double get() { return resource->get(); }

	 ResourceManager(const ResourceManager &diff) : resource(new Resource(*diff.resource)) {}  // konstruktor kopiowania

	 ResourceManager& operator=(const ResourceManager& diff)  //zdefiniowanie przypisujacego operatora kopiowania
         {
             if (this != &diff) {
                delete resource;
                 resource = new Resource(*diff.resource);
             }
             return *this;
         }
     ResourceManager(ResourceManager&& diff) : resource(std::move(diff.resource)) {}  //kontruktor przenoszenia

     ResourceManager& operator=(ResourceManager&& diff)
     {
             if (this != &diff) {
                 delete resource;
                 resource = std::move(diff.resource);
             }
             return *this;
     }

      ~ResourceManager() { delete resource; } //destruktor

};
