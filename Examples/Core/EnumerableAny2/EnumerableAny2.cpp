#include <Switch/Switch>

using namespace System;
using namespace System::Linq;

namespace Examples {
  class Program {
    class Pet : public object {
    public:
      Pet() {}
      Pet(const string& name, int age, bool vaccinated) : name(name), age(age), vaccinated(vaccinated) {}
      Pet(const Pet& pet) : name(pet.name), age(pet.age), vaccinated(pet.vaccinated) {}
      
      property<int, readonly> Age {
        _get { return this->age; }
      };
      
      property<bool, readonly> IsVaccinated {
        _get { return this->vaccinated; }
      };
      
      property<string, readonly> Name {
        _get { return this->name; }
      };
      
    private:
      string name;
      int age = 0;
      bool vaccinated = false;
    };
    
  public:
    // The main entry point for the application.
    static void Main() {
      // Create an array of Pets.
      Array<Pet> pets = {
        {"Barley", 8, true},
        {"Boots", 4, false},
        {"Whiskers", 1, false}
      };
      
      // Determine whether any pets over age 1 are also unvaccinated.
      bool unvaccinated = pets.Any(_delegate(const Pet& pet) {
        return pet.IsVaccinated == false && pet.Age > 1;
      });
      
      Console::WriteLine("There {0} unvaccinated animals over age one.", unvaccinated ? "are" : "are not any");
    }
  };
}

startup (Examples::Program)

// This code produces the following output:
//
// There are unvaccinated animals over age one.
//
