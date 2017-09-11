/// @file
/// @brief Contains Library Version.
#pragma once

#include "Version.hpp"
#include "Collections/Generic/SortedDictionary.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  namespace System {
    namespace Reflexion {
      class Assembly : public object {
      public:
        Assembly() {}
        Assembly(const string& name, const string& description, const string& configuration, const string& company, const string& product, const string& copyright, const string& trademark, const System::Version version) : configuration(configuration), copyright(copyright), description(description), name(name), product(product), trademark(trademark), version(version) {}
        
        /// @cond
        Assembly(const Assembly& assembly) : company(assembly.company), configuration(assembly.configuration), copyright(assembly.copyright), description(assembly.description), name(assembly.name) {}
        /// @endcond
        
        _property<string, _readonly> Company {
          _get {return this->company;}
        };
        
        _property<string, _readonly> Configuration {
          _get {return this->configuration;}
        };
        
        _property<string, _readonly> Copyright {
          _get {return this->copyright;}
        };
        
        _property<string, _readonly> Description {
          _get {return this->description;}
        };
        
        _property<string, _readonly> Name {
          _get {return this->name;}
        };
        
        _property<string, _readonly> Product {
          _get {return this->product;}
        };
        
        _property<string, _readonly> Trademark {
          _get {return this->trademark;}
        };
        
        _property<System::Version, _readonly> Version {
          _get {return this->version;}
        };
        
        static void AddAssembly(const Assembly& assembly) {assemblies.Add(assembly.name, assembly);}
        
        static bool ContainsAssembly(const string& name) {return assemblies.ContainsKey(name);}
        
        bool Equals(const object& obj) const override {return is<Assembly>(obj) && Equals((const Assembly&)obj);}

        bool Equals(const Assembly& assembly) const {return this->company == assembly.company && this->configuration == assembly.configuration && this->copyright == assembly.copyright && this->description == assembly.description && this->name == assembly.name && this->product == assembly.product && this->trademark == assembly.trademark && this->version == assembly.version;}
        
        static Assembly GetAssembly(const string& name) {return assemblies[name];}
        
        static bool RemoveAssembly(const Assembly& assembly) {return assemblies.Remove(assembly.name);}
        
      private:
        string company;
        string configuration;
        string copyright;
        string description;
        string name;
        string product;
        string trademark;
        System::Version version;
        
        static System::Collections::Generic::SortedDictionary<string, Assembly> assemblies;
      };
    }
  }
  
  /// @brief Get Switch library Version
  /// @return Switch library Version
  const System::Version& GetVersion();
}

using namespace Switch;
