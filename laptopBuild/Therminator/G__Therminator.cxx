// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Therminator
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "TherminatorGenerator.hpp"
#include "Chemistry.hpp"
#include "Entropy.hpp"
#include "Viscosity.hpp"
#include "Pressure.hpp"
#include "SoundVelocity.hpp"
#include "Temperature.hpp"
#include "Energy.hpp"
#include "Thermodynamics.hpp"
#include "Model.hpp"
#include "Model_BWA.hpp"
#include "Model_BlastWave.hpp"
#include "Model_Lhyquid2DBI.hpp"
#include "Model_Lhyquid3D.hpp"
#include "Model_KrakowSFO.hpp"
#include "Model_HadronGas.hpp"
#include "Hypersurface.hpp"
#include "Hypersurface_Lhyquid2D.hpp"
#include "Hypersurface_Lhyquid3D.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_Temperature(void *p = nullptr);
   static void *newArray_Temperature(Long_t size, void *p);
   static void delete_Temperature(void *p);
   static void deleteArray_Temperature(void *p);
   static void destruct_Temperature(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Temperature*)
   {
      ::Temperature *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Temperature >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Temperature", ::Temperature::Class_Version(), "Temperature.hpp", 35,
                  typeid(::Temperature), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Temperature::Dictionary, isa_proxy, 4,
                  sizeof(::Temperature) );
      instance.SetNew(&new_Temperature);
      instance.SetNewArray(&newArray_Temperature);
      instance.SetDelete(&delete_Temperature);
      instance.SetDeleteArray(&deleteArray_Temperature);
      instance.SetDestructor(&destruct_Temperature);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Temperature*)
   {
      return GenerateInitInstanceLocal(static_cast<::Temperature*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Temperature*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Chemistry(void *p = nullptr);
   static void *newArray_Chemistry(Long_t size, void *p);
   static void delete_Chemistry(void *p);
   static void deleteArray_Chemistry(void *p);
   static void destruct_Chemistry(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Chemistry*)
   {
      ::Chemistry *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Chemistry >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Chemistry", ::Chemistry::Class_Version(), "Chemistry.hpp", 38,
                  typeid(::Chemistry), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Chemistry::Dictionary, isa_proxy, 4,
                  sizeof(::Chemistry) );
      instance.SetNew(&new_Chemistry);
      instance.SetNewArray(&newArray_Chemistry);
      instance.SetDelete(&delete_Chemistry);
      instance.SetDeleteArray(&deleteArray_Chemistry);
      instance.SetDestructor(&destruct_Chemistry);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Chemistry*)
   {
      return GenerateInitInstanceLocal(static_cast<::Chemistry*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Chemistry*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Energy(void *p = nullptr);
   static void *newArray_Energy(Long_t size, void *p);
   static void delete_Energy(void *p);
   static void deleteArray_Energy(void *p);
   static void destruct_Energy(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Energy*)
   {
      ::Energy *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Energy >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Energy", ::Energy::Class_Version(), "Energy.hpp", 35,
                  typeid(::Energy), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Energy::Dictionary, isa_proxy, 4,
                  sizeof(::Energy) );
      instance.SetNew(&new_Energy);
      instance.SetNewArray(&newArray_Energy);
      instance.SetDelete(&delete_Energy);
      instance.SetDeleteArray(&deleteArray_Energy);
      instance.SetDestructor(&destruct_Energy);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Energy*)
   {
      return GenerateInitInstanceLocal(static_cast<::Energy*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Energy*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Entropy(void *p = nullptr);
   static void *newArray_Entropy(Long_t size, void *p);
   static void delete_Entropy(void *p);
   static void deleteArray_Entropy(void *p);
   static void destruct_Entropy(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Entropy*)
   {
      ::Entropy *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Entropy >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Entropy", ::Entropy::Class_Version(), "Entropy.hpp", 35,
                  typeid(::Entropy), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Entropy::Dictionary, isa_proxy, 4,
                  sizeof(::Entropy) );
      instance.SetNew(&new_Entropy);
      instance.SetNewArray(&newArray_Entropy);
      instance.SetDelete(&delete_Entropy);
      instance.SetDeleteArray(&deleteArray_Entropy);
      instance.SetDestructor(&destruct_Entropy);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Entropy*)
   {
      return GenerateInitInstanceLocal(static_cast<::Entropy*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Entropy*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Pressure(void *p = nullptr);
   static void *newArray_Pressure(Long_t size, void *p);
   static void delete_Pressure(void *p);
   static void deleteArray_Pressure(void *p);
   static void destruct_Pressure(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Pressure*)
   {
      ::Pressure *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Pressure >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Pressure", ::Pressure::Class_Version(), "Pressure.hpp", 35,
                  typeid(::Pressure), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Pressure::Dictionary, isa_proxy, 4,
                  sizeof(::Pressure) );
      instance.SetNew(&new_Pressure);
      instance.SetNewArray(&newArray_Pressure);
      instance.SetDelete(&delete_Pressure);
      instance.SetDeleteArray(&deleteArray_Pressure);
      instance.SetDestructor(&destruct_Pressure);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Pressure*)
   {
      return GenerateInitInstanceLocal(static_cast<::Pressure*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Pressure*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_SoundVelocity(void *p = nullptr);
   static void *newArray_SoundVelocity(Long_t size, void *p);
   static void delete_SoundVelocity(void *p);
   static void deleteArray_SoundVelocity(void *p);
   static void destruct_SoundVelocity(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SoundVelocity*)
   {
      ::SoundVelocity *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::SoundVelocity >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("SoundVelocity", ::SoundVelocity::Class_Version(), "SoundVelocity.hpp", 35,
                  typeid(::SoundVelocity), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::SoundVelocity::Dictionary, isa_proxy, 4,
                  sizeof(::SoundVelocity) );
      instance.SetNew(&new_SoundVelocity);
      instance.SetNewArray(&newArray_SoundVelocity);
      instance.SetDelete(&delete_SoundVelocity);
      instance.SetDeleteArray(&deleteArray_SoundVelocity);
      instance.SetDestructor(&destruct_SoundVelocity);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SoundVelocity*)
   {
      return GenerateInitInstanceLocal(static_cast<::SoundVelocity*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::SoundVelocity*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Viscosity(void *p = nullptr);
   static void *newArray_Viscosity(Long_t size, void *p);
   static void delete_Viscosity(void *p);
   static void deleteArray_Viscosity(void *p);
   static void destruct_Viscosity(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Viscosity*)
   {
      ::Viscosity *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Viscosity >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Viscosity", ::Viscosity::Class_Version(), "Viscosity.hpp", 40,
                  typeid(::Viscosity), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Viscosity::Dictionary, isa_proxy, 4,
                  sizeof(::Viscosity) );
      instance.SetNew(&new_Viscosity);
      instance.SetNewArray(&newArray_Viscosity);
      instance.SetDelete(&delete_Viscosity);
      instance.SetDeleteArray(&deleteArray_Viscosity);
      instance.SetDestructor(&destruct_Viscosity);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Viscosity*)
   {
      return GenerateInitInstanceLocal(static_cast<::Viscosity*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Viscosity*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Thermodynamics(void *p = nullptr);
   static void *newArray_Thermodynamics(Long_t size, void *p);
   static void delete_Thermodynamics(void *p);
   static void deleteArray_Thermodynamics(void *p);
   static void destruct_Thermodynamics(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Thermodynamics*)
   {
      ::Thermodynamics *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Thermodynamics >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Thermodynamics", ::Thermodynamics::Class_Version(), "Thermodynamics.hpp", 40,
                  typeid(::Thermodynamics), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Thermodynamics::Dictionary, isa_proxy, 4,
                  sizeof(::Thermodynamics) );
      instance.SetNew(&new_Thermodynamics);
      instance.SetNewArray(&newArray_Thermodynamics);
      instance.SetDelete(&delete_Thermodynamics);
      instance.SetDeleteArray(&deleteArray_Thermodynamics);
      instance.SetDestructor(&destruct_Thermodynamics);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Thermodynamics*)
   {
      return GenerateInitInstanceLocal(static_cast<::Thermodynamics*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Thermodynamics*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Hypersurface(void *p = nullptr);
   static void *newArray_Hypersurface(Long_t size, void *p);
   static void delete_Hypersurface(void *p);
   static void deleteArray_Hypersurface(void *p);
   static void destruct_Hypersurface(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Hypersurface*)
   {
      ::Hypersurface *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Hypersurface >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Hypersurface", ::Hypersurface::Class_Version(), "Hypersurface.hpp", 44,
                  typeid(::Hypersurface), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Hypersurface::Dictionary, isa_proxy, 4,
                  sizeof(::Hypersurface) );
      instance.SetNew(&new_Hypersurface);
      instance.SetNewArray(&newArray_Hypersurface);
      instance.SetDelete(&delete_Hypersurface);
      instance.SetDeleteArray(&deleteArray_Hypersurface);
      instance.SetDestructor(&destruct_Hypersurface);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Hypersurface*)
   {
      return GenerateInitInstanceLocal(static_cast<::Hypersurface*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Hypersurface*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Model(void *p = nullptr);
   static void *newArray_Model(Long_t size, void *p);
   static void delete_Model(void *p);
   static void deleteArray_Model(void *p);
   static void destruct_Model(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Model*)
   {
      ::Model *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Model >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Model", ::Model::Class_Version(), "Model.hpp", 47,
                  typeid(::Model), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Model::Dictionary, isa_proxy, 4,
                  sizeof(::Model) );
      instance.SetNew(&new_Model);
      instance.SetNewArray(&newArray_Model);
      instance.SetDelete(&delete_Model);
      instance.SetDeleteArray(&deleteArray_Model);
      instance.SetDestructor(&destruct_Model);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Model*)
   {
      return GenerateInitInstanceLocal(static_cast<::Model*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Model*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLTherminatorGenerator(void *p = nullptr);
   static void *newArray_CAPcLcLTherminatorGenerator(Long_t size, void *p);
   static void delete_CAPcLcLTherminatorGenerator(void *p);
   static void deleteArray_CAPcLcLTherminatorGenerator(void *p);
   static void destruct_CAPcLcLTherminatorGenerator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::TherminatorGenerator*)
   {
      ::CAP::TherminatorGenerator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::TherminatorGenerator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::TherminatorGenerator", ::CAP::TherminatorGenerator::Class_Version(), "TherminatorGenerator.hpp", 20,
                  typeid(::CAP::TherminatorGenerator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::TherminatorGenerator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::TherminatorGenerator) );
      instance.SetNew(&new_CAPcLcLTherminatorGenerator);
      instance.SetNewArray(&newArray_CAPcLcLTherminatorGenerator);
      instance.SetDelete(&delete_CAPcLcLTherminatorGenerator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLTherminatorGenerator);
      instance.SetDestructor(&destruct_CAPcLcLTherminatorGenerator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::TherminatorGenerator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::TherminatorGenerator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::TherminatorGenerator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Model_BWA(void *p = nullptr);
   static void *newArray_Model_BWA(Long_t size, void *p);
   static void delete_Model_BWA(void *p);
   static void deleteArray_Model_BWA(void *p);
   static void destruct_Model_BWA(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Model_BWA*)
   {
      ::Model_BWA *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Model_BWA >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Model_BWA", ::Model_BWA::Class_Version(), "Model_BWA.hpp", 35,
                  typeid(::Model_BWA), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Model_BWA::Dictionary, isa_proxy, 4,
                  sizeof(::Model_BWA) );
      instance.SetNew(&new_Model_BWA);
      instance.SetNewArray(&newArray_Model_BWA);
      instance.SetDelete(&delete_Model_BWA);
      instance.SetDeleteArray(&deleteArray_Model_BWA);
      instance.SetDestructor(&destruct_Model_BWA);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Model_BWA*)
   {
      return GenerateInitInstanceLocal(static_cast<::Model_BWA*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Model_BWA*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Model_BlastWave(void *p = nullptr);
   static void *newArray_Model_BlastWave(Long_t size, void *p);
   static void delete_Model_BlastWave(void *p);
   static void deleteArray_Model_BlastWave(void *p);
   static void destruct_Model_BlastWave(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Model_BlastWave*)
   {
      ::Model_BlastWave *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Model_BlastWave >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Model_BlastWave", ::Model_BlastWave::Class_Version(), "Model_BlastWave.hpp", 35,
                  typeid(::Model_BlastWave), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Model_BlastWave::Dictionary, isa_proxy, 4,
                  sizeof(::Model_BlastWave) );
      instance.SetNew(&new_Model_BlastWave);
      instance.SetNewArray(&newArray_Model_BlastWave);
      instance.SetDelete(&delete_Model_BlastWave);
      instance.SetDeleteArray(&deleteArray_Model_BlastWave);
      instance.SetDestructor(&destruct_Model_BlastWave);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Model_BlastWave*)
   {
      return GenerateInitInstanceLocal(static_cast<::Model_BlastWave*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Model_BlastWave*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Model_Lhyquid2DBI(void *p = nullptr);
   static void *newArray_Model_Lhyquid2DBI(Long_t size, void *p);
   static void delete_Model_Lhyquid2DBI(void *p);
   static void deleteArray_Model_Lhyquid2DBI(void *p);
   static void destruct_Model_Lhyquid2DBI(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Model_Lhyquid2DBI*)
   {
      ::Model_Lhyquid2DBI *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Model_Lhyquid2DBI >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Model_Lhyquid2DBI", ::Model_Lhyquid2DBI::Class_Version(), "Model_Lhyquid2DBI.hpp", 34,
                  typeid(::Model_Lhyquid2DBI), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Model_Lhyquid2DBI::Dictionary, isa_proxy, 4,
                  sizeof(::Model_Lhyquid2DBI) );
      instance.SetNew(&new_Model_Lhyquid2DBI);
      instance.SetNewArray(&newArray_Model_Lhyquid2DBI);
      instance.SetDelete(&delete_Model_Lhyquid2DBI);
      instance.SetDeleteArray(&deleteArray_Model_Lhyquid2DBI);
      instance.SetDestructor(&destruct_Model_Lhyquid2DBI);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Model_Lhyquid2DBI*)
   {
      return GenerateInitInstanceLocal(static_cast<::Model_Lhyquid2DBI*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Model_Lhyquid2DBI*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_Hypersurface_Lhyquid3D(void *p);
   static void deleteArray_Hypersurface_Lhyquid3D(void *p);
   static void destruct_Hypersurface_Lhyquid3D(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Hypersurface_Lhyquid3D*)
   {
      ::Hypersurface_Lhyquid3D *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Hypersurface_Lhyquid3D >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Hypersurface_Lhyquid3D", ::Hypersurface_Lhyquid3D::Class_Version(), "Hypersurface_Lhyquid3D.hpp", 33,
                  typeid(::Hypersurface_Lhyquid3D), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Hypersurface_Lhyquid3D::Dictionary, isa_proxy, 4,
                  sizeof(::Hypersurface_Lhyquid3D) );
      instance.SetDelete(&delete_Hypersurface_Lhyquid3D);
      instance.SetDeleteArray(&deleteArray_Hypersurface_Lhyquid3D);
      instance.SetDestructor(&destruct_Hypersurface_Lhyquid3D);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Hypersurface_Lhyquid3D*)
   {
      return GenerateInitInstanceLocal(static_cast<::Hypersurface_Lhyquid3D*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Hypersurface_Lhyquid3D*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Model_Lhyquid3D(void *p = nullptr);
   static void *newArray_Model_Lhyquid3D(Long_t size, void *p);
   static void delete_Model_Lhyquid3D(void *p);
   static void deleteArray_Model_Lhyquid3D(void *p);
   static void destruct_Model_Lhyquid3D(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Model_Lhyquid3D*)
   {
      ::Model_Lhyquid3D *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Model_Lhyquid3D >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Model_Lhyquid3D", ::Model_Lhyquid3D::Class_Version(), "Model_Lhyquid3D.hpp", 35,
                  typeid(::Model_Lhyquid3D), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Model_Lhyquid3D::Dictionary, isa_proxy, 4,
                  sizeof(::Model_Lhyquid3D) );
      instance.SetNew(&new_Model_Lhyquid3D);
      instance.SetNewArray(&newArray_Model_Lhyquid3D);
      instance.SetDelete(&delete_Model_Lhyquid3D);
      instance.SetDeleteArray(&deleteArray_Model_Lhyquid3D);
      instance.SetDestructor(&destruct_Model_Lhyquid3D);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Model_Lhyquid3D*)
   {
      return GenerateInitInstanceLocal(static_cast<::Model_Lhyquid3D*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Model_Lhyquid3D*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Model_KrakowSFO(void *p = nullptr);
   static void *newArray_Model_KrakowSFO(Long_t size, void *p);
   static void delete_Model_KrakowSFO(void *p);
   static void deleteArray_Model_KrakowSFO(void *p);
   static void destruct_Model_KrakowSFO(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Model_KrakowSFO*)
   {
      ::Model_KrakowSFO *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Model_KrakowSFO >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Model_KrakowSFO", ::Model_KrakowSFO::Class_Version(), "Model_KrakowSFO.hpp", 33,
                  typeid(::Model_KrakowSFO), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Model_KrakowSFO::Dictionary, isa_proxy, 4,
                  sizeof(::Model_KrakowSFO) );
      instance.SetNew(&new_Model_KrakowSFO);
      instance.SetNewArray(&newArray_Model_KrakowSFO);
      instance.SetDelete(&delete_Model_KrakowSFO);
      instance.SetDeleteArray(&deleteArray_Model_KrakowSFO);
      instance.SetDestructor(&destruct_Model_KrakowSFO);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Model_KrakowSFO*)
   {
      return GenerateInitInstanceLocal(static_cast<::Model_KrakowSFO*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Model_KrakowSFO*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Model_HadronGas(void *p = nullptr);
   static void *newArray_Model_HadronGas(Long_t size, void *p);
   static void delete_Model_HadronGas(void *p);
   static void deleteArray_Model_HadronGas(void *p);
   static void destruct_Model_HadronGas(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Model_HadronGas*)
   {
      ::Model_HadronGas *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Model_HadronGas >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Model_HadronGas", ::Model_HadronGas::Class_Version(), "Model_HadronGas.hpp", 13,
                  typeid(::Model_HadronGas), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Model_HadronGas::Dictionary, isa_proxy, 4,
                  sizeof(::Model_HadronGas) );
      instance.SetNew(&new_Model_HadronGas);
      instance.SetNewArray(&newArray_Model_HadronGas);
      instance.SetDelete(&delete_Model_HadronGas);
      instance.SetDeleteArray(&deleteArray_Model_HadronGas);
      instance.SetDestructor(&destruct_Model_HadronGas);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Model_HadronGas*)
   {
      return GenerateInitInstanceLocal(static_cast<::Model_HadronGas*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Model_HadronGas*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_Hypersurface_Lhyquid2D(void *p);
   static void deleteArray_Hypersurface_Lhyquid2D(void *p);
   static void destruct_Hypersurface_Lhyquid2D(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Hypersurface_Lhyquid2D*)
   {
      ::Hypersurface_Lhyquid2D *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Hypersurface_Lhyquid2D >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("Hypersurface_Lhyquid2D", ::Hypersurface_Lhyquid2D::Class_Version(), "Hypersurface_Lhyquid2D.hpp", 35,
                  typeid(::Hypersurface_Lhyquid2D), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Hypersurface_Lhyquid2D::Dictionary, isa_proxy, 4,
                  sizeof(::Hypersurface_Lhyquid2D) );
      instance.SetDelete(&delete_Hypersurface_Lhyquid2D);
      instance.SetDeleteArray(&deleteArray_Hypersurface_Lhyquid2D);
      instance.SetDestructor(&destruct_Hypersurface_Lhyquid2D);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Hypersurface_Lhyquid2D*)
   {
      return GenerateInitInstanceLocal(static_cast<::Hypersurface_Lhyquid2D*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::Hypersurface_Lhyquid2D*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr Temperature::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Temperature::Class_Name()
{
   return "Temperature";
}

//______________________________________________________________________________
const char *Temperature::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Temperature*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Temperature::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Temperature*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Temperature::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Temperature*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Temperature::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Temperature*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Chemistry::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Chemistry::Class_Name()
{
   return "Chemistry";
}

//______________________________________________________________________________
const char *Chemistry::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Chemistry*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Chemistry::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Chemistry*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Chemistry::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Chemistry*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Chemistry::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Chemistry*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Energy::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Energy::Class_Name()
{
   return "Energy";
}

//______________________________________________________________________________
const char *Energy::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Energy*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Energy::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Energy*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Energy::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Energy*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Energy::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Energy*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Entropy::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Entropy::Class_Name()
{
   return "Entropy";
}

//______________________________________________________________________________
const char *Entropy::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Entropy*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Entropy::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Entropy*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Entropy::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Entropy*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Entropy::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Entropy*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Pressure::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Pressure::Class_Name()
{
   return "Pressure";
}

//______________________________________________________________________________
const char *Pressure::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Pressure*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Pressure::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Pressure*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Pressure::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Pressure*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Pressure::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Pressure*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr SoundVelocity::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *SoundVelocity::Class_Name()
{
   return "SoundVelocity";
}

//______________________________________________________________________________
const char *SoundVelocity::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SoundVelocity*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int SoundVelocity::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::SoundVelocity*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SoundVelocity::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SoundVelocity*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SoundVelocity::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::SoundVelocity*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Viscosity::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Viscosity::Class_Name()
{
   return "Viscosity";
}

//______________________________________________________________________________
const char *Viscosity::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Viscosity*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Viscosity::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Viscosity*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Viscosity::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Viscosity*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Viscosity::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Viscosity*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Thermodynamics::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Thermodynamics::Class_Name()
{
   return "Thermodynamics";
}

//______________________________________________________________________________
const char *Thermodynamics::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Thermodynamics*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Thermodynamics::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Thermodynamics*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Thermodynamics::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Thermodynamics*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Thermodynamics::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Thermodynamics*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Hypersurface::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Hypersurface::Class_Name()
{
   return "Hypersurface";
}

//______________________________________________________________________________
const char *Hypersurface::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Hypersurface*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Hypersurface::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Hypersurface*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Hypersurface::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Hypersurface*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Hypersurface::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Hypersurface*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Model::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Model::Class_Name()
{
   return "Model";
}

//______________________________________________________________________________
const char *Model::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Model::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Model::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Model::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model*)nullptr)->GetClass(); }
   return fgIsA;
}

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr TherminatorGenerator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TherminatorGenerator::Class_Name()
{
   return "CAP::TherminatorGenerator";
}

//______________________________________________________________________________
const char *TherminatorGenerator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::TherminatorGenerator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TherminatorGenerator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::TherminatorGenerator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TherminatorGenerator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::TherminatorGenerator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TherminatorGenerator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::TherminatorGenerator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
//______________________________________________________________________________
atomic_TClass_ptr Model_BWA::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Model_BWA::Class_Name()
{
   return "Model_BWA";
}

//______________________________________________________________________________
const char *Model_BWA::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model_BWA*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Model_BWA::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model_BWA*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Model_BWA::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model_BWA*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Model_BWA::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model_BWA*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Model_BlastWave::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Model_BlastWave::Class_Name()
{
   return "Model_BlastWave";
}

//______________________________________________________________________________
const char *Model_BlastWave::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model_BlastWave*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Model_BlastWave::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model_BlastWave*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Model_BlastWave::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model_BlastWave*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Model_BlastWave::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model_BlastWave*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Model_Lhyquid2DBI::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Model_Lhyquid2DBI::Class_Name()
{
   return "Model_Lhyquid2DBI";
}

//______________________________________________________________________________
const char *Model_Lhyquid2DBI::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model_Lhyquid2DBI*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Model_Lhyquid2DBI::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model_Lhyquid2DBI*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Model_Lhyquid2DBI::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model_Lhyquid2DBI*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Model_Lhyquid2DBI::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model_Lhyquid2DBI*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Hypersurface_Lhyquid3D::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Hypersurface_Lhyquid3D::Class_Name()
{
   return "Hypersurface_Lhyquid3D";
}

//______________________________________________________________________________
const char *Hypersurface_Lhyquid3D::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Hypersurface_Lhyquid3D*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Hypersurface_Lhyquid3D::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Hypersurface_Lhyquid3D*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Hypersurface_Lhyquid3D::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Hypersurface_Lhyquid3D*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Hypersurface_Lhyquid3D::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Hypersurface_Lhyquid3D*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Model_Lhyquid3D::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Model_Lhyquid3D::Class_Name()
{
   return "Model_Lhyquid3D";
}

//______________________________________________________________________________
const char *Model_Lhyquid3D::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model_Lhyquid3D*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Model_Lhyquid3D::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model_Lhyquid3D*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Model_Lhyquid3D::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model_Lhyquid3D*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Model_Lhyquid3D::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model_Lhyquid3D*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Model_KrakowSFO::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Model_KrakowSFO::Class_Name()
{
   return "Model_KrakowSFO";
}

//______________________________________________________________________________
const char *Model_KrakowSFO::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model_KrakowSFO*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Model_KrakowSFO::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model_KrakowSFO*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Model_KrakowSFO::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model_KrakowSFO*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Model_KrakowSFO::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model_KrakowSFO*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Model_HadronGas::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Model_HadronGas::Class_Name()
{
   return "Model_HadronGas";
}

//______________________________________________________________________________
const char *Model_HadronGas::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model_HadronGas*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Model_HadronGas::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Model_HadronGas*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Model_HadronGas::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model_HadronGas*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Model_HadronGas::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Model_HadronGas*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Hypersurface_Lhyquid2D::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Hypersurface_Lhyquid2D::Class_Name()
{
   return "Hypersurface_Lhyquid2D";
}

//______________________________________________________________________________
const char *Hypersurface_Lhyquid2D::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Hypersurface_Lhyquid2D*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Hypersurface_Lhyquid2D::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Hypersurface_Lhyquid2D*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Hypersurface_Lhyquid2D::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Hypersurface_Lhyquid2D*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Hypersurface_Lhyquid2D::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Hypersurface_Lhyquid2D*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void Temperature::Streamer(TBuffer &R__b)
{
   // Stream an object of class Temperature.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Temperature::Class(),this);
   } else {
      R__b.WriteClassBuffer(Temperature::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Temperature(void *p) {
      return  p ? new(p) ::Temperature : new ::Temperature;
   }
   static void *newArray_Temperature(Long_t nElements, void *p) {
      return p ? new(p) ::Temperature[nElements] : new ::Temperature[nElements];
   }
   // Wrapper around operator delete
   static void delete_Temperature(void *p) {
      delete (static_cast<::Temperature*>(p));
   }
   static void deleteArray_Temperature(void *p) {
      delete [] (static_cast<::Temperature*>(p));
   }
   static void destruct_Temperature(void *p) {
      typedef ::Temperature current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Temperature

//______________________________________________________________________________
void Chemistry::Streamer(TBuffer &R__b)
{
   // Stream an object of class Chemistry.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Chemistry::Class(),this);
   } else {
      R__b.WriteClassBuffer(Chemistry::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Chemistry(void *p) {
      return  p ? new(p) ::Chemistry : new ::Chemistry;
   }
   static void *newArray_Chemistry(Long_t nElements, void *p) {
      return p ? new(p) ::Chemistry[nElements] : new ::Chemistry[nElements];
   }
   // Wrapper around operator delete
   static void delete_Chemistry(void *p) {
      delete (static_cast<::Chemistry*>(p));
   }
   static void deleteArray_Chemistry(void *p) {
      delete [] (static_cast<::Chemistry*>(p));
   }
   static void destruct_Chemistry(void *p) {
      typedef ::Chemistry current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Chemistry

//______________________________________________________________________________
void Energy::Streamer(TBuffer &R__b)
{
   // Stream an object of class Energy.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Energy::Class(),this);
   } else {
      R__b.WriteClassBuffer(Energy::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Energy(void *p) {
      return  p ? new(p) ::Energy : new ::Energy;
   }
   static void *newArray_Energy(Long_t nElements, void *p) {
      return p ? new(p) ::Energy[nElements] : new ::Energy[nElements];
   }
   // Wrapper around operator delete
   static void delete_Energy(void *p) {
      delete (static_cast<::Energy*>(p));
   }
   static void deleteArray_Energy(void *p) {
      delete [] (static_cast<::Energy*>(p));
   }
   static void destruct_Energy(void *p) {
      typedef ::Energy current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Energy

//______________________________________________________________________________
void Entropy::Streamer(TBuffer &R__b)
{
   // Stream an object of class Entropy.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Entropy::Class(),this);
   } else {
      R__b.WriteClassBuffer(Entropy::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Entropy(void *p) {
      return  p ? new(p) ::Entropy : new ::Entropy;
   }
   static void *newArray_Entropy(Long_t nElements, void *p) {
      return p ? new(p) ::Entropy[nElements] : new ::Entropy[nElements];
   }
   // Wrapper around operator delete
   static void delete_Entropy(void *p) {
      delete (static_cast<::Entropy*>(p));
   }
   static void deleteArray_Entropy(void *p) {
      delete [] (static_cast<::Entropy*>(p));
   }
   static void destruct_Entropy(void *p) {
      typedef ::Entropy current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Entropy

//______________________________________________________________________________
void Pressure::Streamer(TBuffer &R__b)
{
   // Stream an object of class Pressure.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Pressure::Class(),this);
   } else {
      R__b.WriteClassBuffer(Pressure::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Pressure(void *p) {
      return  p ? new(p) ::Pressure : new ::Pressure;
   }
   static void *newArray_Pressure(Long_t nElements, void *p) {
      return p ? new(p) ::Pressure[nElements] : new ::Pressure[nElements];
   }
   // Wrapper around operator delete
   static void delete_Pressure(void *p) {
      delete (static_cast<::Pressure*>(p));
   }
   static void deleteArray_Pressure(void *p) {
      delete [] (static_cast<::Pressure*>(p));
   }
   static void destruct_Pressure(void *p) {
      typedef ::Pressure current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Pressure

//______________________________________________________________________________
void SoundVelocity::Streamer(TBuffer &R__b)
{
   // Stream an object of class SoundVelocity.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(SoundVelocity::Class(),this);
   } else {
      R__b.WriteClassBuffer(SoundVelocity::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_SoundVelocity(void *p) {
      return  p ? new(p) ::SoundVelocity : new ::SoundVelocity;
   }
   static void *newArray_SoundVelocity(Long_t nElements, void *p) {
      return p ? new(p) ::SoundVelocity[nElements] : new ::SoundVelocity[nElements];
   }
   // Wrapper around operator delete
   static void delete_SoundVelocity(void *p) {
      delete (static_cast<::SoundVelocity*>(p));
   }
   static void deleteArray_SoundVelocity(void *p) {
      delete [] (static_cast<::SoundVelocity*>(p));
   }
   static void destruct_SoundVelocity(void *p) {
      typedef ::SoundVelocity current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::SoundVelocity

//______________________________________________________________________________
void Viscosity::Streamer(TBuffer &R__b)
{
   // Stream an object of class Viscosity.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Viscosity::Class(),this);
   } else {
      R__b.WriteClassBuffer(Viscosity::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Viscosity(void *p) {
      return  p ? new(p) ::Viscosity : new ::Viscosity;
   }
   static void *newArray_Viscosity(Long_t nElements, void *p) {
      return p ? new(p) ::Viscosity[nElements] : new ::Viscosity[nElements];
   }
   // Wrapper around operator delete
   static void delete_Viscosity(void *p) {
      delete (static_cast<::Viscosity*>(p));
   }
   static void deleteArray_Viscosity(void *p) {
      delete [] (static_cast<::Viscosity*>(p));
   }
   static void destruct_Viscosity(void *p) {
      typedef ::Viscosity current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Viscosity

//______________________________________________________________________________
void Thermodynamics::Streamer(TBuffer &R__b)
{
   // Stream an object of class Thermodynamics.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Thermodynamics::Class(),this);
   } else {
      R__b.WriteClassBuffer(Thermodynamics::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Thermodynamics(void *p) {
      return  p ? new(p) ::Thermodynamics : new ::Thermodynamics;
   }
   static void *newArray_Thermodynamics(Long_t nElements, void *p) {
      return p ? new(p) ::Thermodynamics[nElements] : new ::Thermodynamics[nElements];
   }
   // Wrapper around operator delete
   static void delete_Thermodynamics(void *p) {
      delete (static_cast<::Thermodynamics*>(p));
   }
   static void deleteArray_Thermodynamics(void *p) {
      delete [] (static_cast<::Thermodynamics*>(p));
   }
   static void destruct_Thermodynamics(void *p) {
      typedef ::Thermodynamics current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Thermodynamics

//______________________________________________________________________________
void Hypersurface::Streamer(TBuffer &R__b)
{
   // Stream an object of class Hypersurface.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Hypersurface::Class(),this);
   } else {
      R__b.WriteClassBuffer(Hypersurface::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Hypersurface(void *p) {
      return  p ? new(p) ::Hypersurface : new ::Hypersurface;
   }
   static void *newArray_Hypersurface(Long_t nElements, void *p) {
      return p ? new(p) ::Hypersurface[nElements] : new ::Hypersurface[nElements];
   }
   // Wrapper around operator delete
   static void delete_Hypersurface(void *p) {
      delete (static_cast<::Hypersurface*>(p));
   }
   static void deleteArray_Hypersurface(void *p) {
      delete [] (static_cast<::Hypersurface*>(p));
   }
   static void destruct_Hypersurface(void *p) {
      typedef ::Hypersurface current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Hypersurface

//______________________________________________________________________________
void Model::Streamer(TBuffer &R__b)
{
   // Stream an object of class Model.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Model::Class(),this);
   } else {
      R__b.WriteClassBuffer(Model::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Model(void *p) {
      return  p ? new(p) ::Model : new ::Model;
   }
   static void *newArray_Model(Long_t nElements, void *p) {
      return p ? new(p) ::Model[nElements] : new ::Model[nElements];
   }
   // Wrapper around operator delete
   static void delete_Model(void *p) {
      delete (static_cast<::Model*>(p));
   }
   static void deleteArray_Model(void *p) {
      delete [] (static_cast<::Model*>(p));
   }
   static void destruct_Model(void *p) {
      typedef ::Model current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Model

namespace CAP {
//______________________________________________________________________________
void TherminatorGenerator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::TherminatorGenerator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::TherminatorGenerator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::TherminatorGenerator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLTherminatorGenerator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::TherminatorGenerator : new ::CAP::TherminatorGenerator;
   }
   static void *newArray_CAPcLcLTherminatorGenerator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::TherminatorGenerator[nElements] : new ::CAP::TherminatorGenerator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLTherminatorGenerator(void *p) {
      delete (static_cast<::CAP::TherminatorGenerator*>(p));
   }
   static void deleteArray_CAPcLcLTherminatorGenerator(void *p) {
      delete [] (static_cast<::CAP::TherminatorGenerator*>(p));
   }
   static void destruct_CAPcLcLTherminatorGenerator(void *p) {
      typedef ::CAP::TherminatorGenerator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::TherminatorGenerator

//______________________________________________________________________________
void Model_BWA::Streamer(TBuffer &R__b)
{
   // Stream an object of class Model_BWA.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Model_BWA::Class(),this);
   } else {
      R__b.WriteClassBuffer(Model_BWA::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Model_BWA(void *p) {
      return  p ? new(p) ::Model_BWA : new ::Model_BWA;
   }
   static void *newArray_Model_BWA(Long_t nElements, void *p) {
      return p ? new(p) ::Model_BWA[nElements] : new ::Model_BWA[nElements];
   }
   // Wrapper around operator delete
   static void delete_Model_BWA(void *p) {
      delete (static_cast<::Model_BWA*>(p));
   }
   static void deleteArray_Model_BWA(void *p) {
      delete [] (static_cast<::Model_BWA*>(p));
   }
   static void destruct_Model_BWA(void *p) {
      typedef ::Model_BWA current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Model_BWA

//______________________________________________________________________________
void Model_BlastWave::Streamer(TBuffer &R__b)
{
   // Stream an object of class Model_BlastWave.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Model_BlastWave::Class(),this);
   } else {
      R__b.WriteClassBuffer(Model_BlastWave::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Model_BlastWave(void *p) {
      return  p ? new(p) ::Model_BlastWave : new ::Model_BlastWave;
   }
   static void *newArray_Model_BlastWave(Long_t nElements, void *p) {
      return p ? new(p) ::Model_BlastWave[nElements] : new ::Model_BlastWave[nElements];
   }
   // Wrapper around operator delete
   static void delete_Model_BlastWave(void *p) {
      delete (static_cast<::Model_BlastWave*>(p));
   }
   static void deleteArray_Model_BlastWave(void *p) {
      delete [] (static_cast<::Model_BlastWave*>(p));
   }
   static void destruct_Model_BlastWave(void *p) {
      typedef ::Model_BlastWave current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Model_BlastWave

//______________________________________________________________________________
void Model_Lhyquid2DBI::Streamer(TBuffer &R__b)
{
   // Stream an object of class Model_Lhyquid2DBI.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Model_Lhyquid2DBI::Class(),this);
   } else {
      R__b.WriteClassBuffer(Model_Lhyquid2DBI::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Model_Lhyquid2DBI(void *p) {
      return  p ? new(p) ::Model_Lhyquid2DBI : new ::Model_Lhyquid2DBI;
   }
   static void *newArray_Model_Lhyquid2DBI(Long_t nElements, void *p) {
      return p ? new(p) ::Model_Lhyquid2DBI[nElements] : new ::Model_Lhyquid2DBI[nElements];
   }
   // Wrapper around operator delete
   static void delete_Model_Lhyquid2DBI(void *p) {
      delete (static_cast<::Model_Lhyquid2DBI*>(p));
   }
   static void deleteArray_Model_Lhyquid2DBI(void *p) {
      delete [] (static_cast<::Model_Lhyquid2DBI*>(p));
   }
   static void destruct_Model_Lhyquid2DBI(void *p) {
      typedef ::Model_Lhyquid2DBI current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Model_Lhyquid2DBI

//______________________________________________________________________________
void Hypersurface_Lhyquid3D::Streamer(TBuffer &R__b)
{
   // Stream an object of class Hypersurface_Lhyquid3D.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Hypersurface_Lhyquid3D::Class(),this);
   } else {
      R__b.WriteClassBuffer(Hypersurface_Lhyquid3D::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_Hypersurface_Lhyquid3D(void *p) {
      delete (static_cast<::Hypersurface_Lhyquid3D*>(p));
   }
   static void deleteArray_Hypersurface_Lhyquid3D(void *p) {
      delete [] (static_cast<::Hypersurface_Lhyquid3D*>(p));
   }
   static void destruct_Hypersurface_Lhyquid3D(void *p) {
      typedef ::Hypersurface_Lhyquid3D current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Hypersurface_Lhyquid3D

//______________________________________________________________________________
void Model_Lhyquid3D::Streamer(TBuffer &R__b)
{
   // Stream an object of class Model_Lhyquid3D.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Model_Lhyquid3D::Class(),this);
   } else {
      R__b.WriteClassBuffer(Model_Lhyquid3D::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Model_Lhyquid3D(void *p) {
      return  p ? new(p) ::Model_Lhyquid3D : new ::Model_Lhyquid3D;
   }
   static void *newArray_Model_Lhyquid3D(Long_t nElements, void *p) {
      return p ? new(p) ::Model_Lhyquid3D[nElements] : new ::Model_Lhyquid3D[nElements];
   }
   // Wrapper around operator delete
   static void delete_Model_Lhyquid3D(void *p) {
      delete (static_cast<::Model_Lhyquid3D*>(p));
   }
   static void deleteArray_Model_Lhyquid3D(void *p) {
      delete [] (static_cast<::Model_Lhyquid3D*>(p));
   }
   static void destruct_Model_Lhyquid3D(void *p) {
      typedef ::Model_Lhyquid3D current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Model_Lhyquid3D

//______________________________________________________________________________
void Model_KrakowSFO::Streamer(TBuffer &R__b)
{
   // Stream an object of class Model_KrakowSFO.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Model_KrakowSFO::Class(),this);
   } else {
      R__b.WriteClassBuffer(Model_KrakowSFO::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Model_KrakowSFO(void *p) {
      return  p ? new(p) ::Model_KrakowSFO : new ::Model_KrakowSFO;
   }
   static void *newArray_Model_KrakowSFO(Long_t nElements, void *p) {
      return p ? new(p) ::Model_KrakowSFO[nElements] : new ::Model_KrakowSFO[nElements];
   }
   // Wrapper around operator delete
   static void delete_Model_KrakowSFO(void *p) {
      delete (static_cast<::Model_KrakowSFO*>(p));
   }
   static void deleteArray_Model_KrakowSFO(void *p) {
      delete [] (static_cast<::Model_KrakowSFO*>(p));
   }
   static void destruct_Model_KrakowSFO(void *p) {
      typedef ::Model_KrakowSFO current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Model_KrakowSFO

//______________________________________________________________________________
void Model_HadronGas::Streamer(TBuffer &R__b)
{
   // Stream an object of class Model_HadronGas.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Model_HadronGas::Class(),this);
   } else {
      R__b.WriteClassBuffer(Model_HadronGas::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Model_HadronGas(void *p) {
      return  p ? new(p) ::Model_HadronGas : new ::Model_HadronGas;
   }
   static void *newArray_Model_HadronGas(Long_t nElements, void *p) {
      return p ? new(p) ::Model_HadronGas[nElements] : new ::Model_HadronGas[nElements];
   }
   // Wrapper around operator delete
   static void delete_Model_HadronGas(void *p) {
      delete (static_cast<::Model_HadronGas*>(p));
   }
   static void deleteArray_Model_HadronGas(void *p) {
      delete [] (static_cast<::Model_HadronGas*>(p));
   }
   static void destruct_Model_HadronGas(void *p) {
      typedef ::Model_HadronGas current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Model_HadronGas

//______________________________________________________________________________
void Hypersurface_Lhyquid2D::Streamer(TBuffer &R__b)
{
   // Stream an object of class Hypersurface_Lhyquid2D.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Hypersurface_Lhyquid2D::Class(),this);
   } else {
      R__b.WriteClassBuffer(Hypersurface_Lhyquid2D::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_Hypersurface_Lhyquid2D(void *p) {
      delete (static_cast<::Hypersurface_Lhyquid2D*>(p));
   }
   static void deleteArray_Hypersurface_Lhyquid2D(void *p) {
      delete [] (static_cast<::Hypersurface_Lhyquid2D*>(p));
   }
   static void destruct_Hypersurface_Lhyquid2D(void *p) {
      typedef ::Hypersurface_Lhyquid2D current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::Hypersurface_Lhyquid2D

namespace {
  void TriggerDictionaryInitialization_libTherminator_Impl() {
    static const char* headers[] = {
"TherminatorGenerator.hpp",
"Chemistry.hpp",
"Entropy.hpp",
"Viscosity.hpp",
"Pressure.hpp",
"SoundVelocity.hpp",
"Temperature.hpp",
"Energy.hpp",
"Thermodynamics.hpp",
"Model.hpp",
"Model_BWA.hpp",
"Model_BlastWave.hpp",
"Model_Lhyquid2DBI.hpp",
"Model_Lhyquid3D.hpp",
"Model_KrakowSFO.hpp",
"Model_HadronGas.hpp",
"Hypersurface.hpp",
"Hypersurface_Lhyquid2D.hpp",
"Hypersurface_Lhyquid3D.hpp",
nullptr
    };
    static const char* includePaths[] = {
"/opt/homebrew/Cellar/root/6.32.06/include/root",
"/Users/aa7526/Documents/GitHub/CAP6.0/src",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/Base",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/Math",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/Xml",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/ParticleDb",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/Particles",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/SubSample",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/CAPPythia",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/Global",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/Jets",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/Spherocity",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/ParticleSingle",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/ParticlePair",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/ParticlePair3D",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/NuDyn",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/PtPt",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/Plotting",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/Therminator",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/Performance",
"/Users/aa7526/Documents/GitHub/CAP6.0/src/Exec",
"/include",
"/Users/aa7526/opt/fastjet-3.4.3/include",
"/Users/aa7526/opt/Pythia/pythia8307/include",
"/Users/aa7526/opt/Pythia/pythia8307/include/Pythia8",
"/opt/homebrew/Cellar/root/6.32.06/include/root",
"/Users/aa7526/Documents/GitHub/CAP6.0/laptop/Therminator/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libTherminator dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$Temperature.hpp")))  __attribute__((annotate("$clingAutoload$TherminatorGenerator.hpp")))  Temperature;
class __attribute__((annotate("$clingAutoload$Chemistry.hpp")))  __attribute__((annotate("$clingAutoload$TherminatorGenerator.hpp")))  Chemistry;
class __attribute__((annotate("$clingAutoload$Energy.hpp")))  __attribute__((annotate("$clingAutoload$TherminatorGenerator.hpp")))  Energy;
class __attribute__((annotate("$clingAutoload$Entropy.hpp")))  __attribute__((annotate("$clingAutoload$TherminatorGenerator.hpp")))  Entropy;
class __attribute__((annotate("$clingAutoload$Pressure.hpp")))  __attribute__((annotate("$clingAutoload$TherminatorGenerator.hpp")))  Pressure;
class __attribute__((annotate("$clingAutoload$SoundVelocity.hpp")))  __attribute__((annotate("$clingAutoload$TherminatorGenerator.hpp")))  SoundVelocity;
class __attribute__((annotate("$clingAutoload$Viscosity.hpp")))  __attribute__((annotate("$clingAutoload$TherminatorGenerator.hpp")))  Viscosity;
class __attribute__((annotate("$clingAutoload$Thermodynamics.hpp")))  __attribute__((annotate("$clingAutoload$TherminatorGenerator.hpp")))  Thermodynamics;
class __attribute__((annotate("$clingAutoload$Hypersurface.hpp")))  __attribute__((annotate("$clingAutoload$TherminatorGenerator.hpp")))  Hypersurface;
class __attribute__((annotate("$clingAutoload$Model.hpp")))  __attribute__((annotate("$clingAutoload$TherminatorGenerator.hpp")))  Model;
namespace CAP{class __attribute__((annotate("$clingAutoload$TherminatorGenerator.hpp")))  TherminatorGenerator;}
class __attribute__((annotate("$clingAutoload$Model_BWA.hpp")))  Model_BWA;
class __attribute__((annotate("$clingAutoload$Model_BlastWave.hpp")))  Model_BlastWave;
class __attribute__((annotate("$clingAutoload$Model_Lhyquid2DBI.hpp")))  Model_Lhyquid2DBI;
class __attribute__((annotate("$clingAutoload$Hypersurface_Lhyquid3D.hpp")))  __attribute__((annotate("$clingAutoload$Model_Lhyquid3D.hpp")))  Hypersurface_Lhyquid3D;
class __attribute__((annotate("$clingAutoload$Model_Lhyquid3D.hpp")))  Model_Lhyquid3D;
class __attribute__((annotate("$clingAutoload$Model_KrakowSFO.hpp")))  Model_KrakowSFO;
class __attribute__((annotate("$clingAutoload$Model_HadronGas.hpp")))  Model_HadronGas;
class __attribute__((annotate("$clingAutoload$Hypersurface_Lhyquid2D.hpp")))  Hypersurface_Lhyquid2D;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libTherminator dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TherminatorGenerator.hpp"
#include "Chemistry.hpp"
#include "Entropy.hpp"
#include "Viscosity.hpp"
#include "Pressure.hpp"
#include "SoundVelocity.hpp"
#include "Temperature.hpp"
#include "Energy.hpp"
#include "Thermodynamics.hpp"
#include "Model.hpp"
#include "Model_BWA.hpp"
#include "Model_BlastWave.hpp"
#include "Model_Lhyquid2DBI.hpp"
#include "Model_Lhyquid3D.hpp"
#include "Model_KrakowSFO.hpp"
#include "Model_HadronGas.hpp"
#include "Hypersurface.hpp"
#include "Hypersurface_Lhyquid2D.hpp"
#include "Hypersurface_Lhyquid3D.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::TherminatorGenerator", payloadCode, "@",
"Chemistry", payloadCode, "@",
"Energy", payloadCode, "@",
"Entropy", payloadCode, "@",
"Hypersurface", payloadCode, "@",
"Hypersurface_Lhyquid2D", payloadCode, "@",
"Hypersurface_Lhyquid3D", payloadCode, "@",
"Model", payloadCode, "@",
"Model_BWA", payloadCode, "@",
"Model_BlastWave", payloadCode, "@",
"Model_HadronGas", payloadCode, "@",
"Model_KrakowSFO", payloadCode, "@",
"Model_Lhyquid2DBI", payloadCode, "@",
"Model_Lhyquid3D", payloadCode, "@",
"Pressure", payloadCode, "@",
"SoundVelocity", payloadCode, "@",
"Temperature", payloadCode, "@",
"Thermodynamics", payloadCode, "@",
"Viscosity", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libTherminator",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libTherminator_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libTherminator_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libTherminator() {
  TriggerDictionaryInitialization_libTherminator_Impl();
}
