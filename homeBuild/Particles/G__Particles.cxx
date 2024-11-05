// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Particles
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
#include "Event.hpp"
#include "EventAccountant.hpp"
#include "EventFilter.hpp"
#include "EventCountHistos.hpp"
#include "EventTask.hpp"
#include "EventIterator.hpp"
#include "Particle.hpp"
#include "ParticleDecayer.hpp"
#include "ParticleDecayerTask.hpp"
#include "ParticleFilter.hpp"
#include "ParticlePairFilter.hpp"
#include "RootChainManager.hpp"
#include "FilterCreator.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *CAPcLcLFactorylECAPcLcLParticlegR_Dictionary();
   static void CAPcLcLFactorylECAPcLcLParticlegR_TClassManip(TClass*);
   static void *new_CAPcLcLFactorylECAPcLcLParticlegR(void *p = nullptr);
   static void *newArray_CAPcLcLFactorylECAPcLcLParticlegR(Long_t size, void *p);
   static void delete_CAPcLcLFactorylECAPcLcLParticlegR(void *p);
   static void deleteArray_CAPcLcLFactorylECAPcLcLParticlegR(void *p);
   static void destruct_CAPcLcLFactorylECAPcLcLParticlegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Factory<CAP::Particle>*)
   {
      ::CAP::Factory<CAP::Particle> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Factory<CAP::Particle> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Factory<CAP::Particle>", ::CAP::Factory<CAP::Particle>::Class_Version(), "Factory.hpp", 32,
                  typeid(::CAP::Factory<CAP::Particle>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLFactorylECAPcLcLParticlegR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Factory<CAP::Particle>) );
      instance.SetNew(&new_CAPcLcLFactorylECAPcLcLParticlegR);
      instance.SetNewArray(&newArray_CAPcLcLFactorylECAPcLcLParticlegR);
      instance.SetDelete(&delete_CAPcLcLFactorylECAPcLcLParticlegR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLFactorylECAPcLcLParticlegR);
      instance.SetDestructor(&destruct_CAPcLcLFactorylECAPcLcLParticlegR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Factory<CAP::Particle>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Factory<CAP::Particle>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Factory<CAP::Particle>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLFactorylECAPcLcLParticlegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Factory<CAP::Particle>*>(nullptr))->GetClass();
      CAPcLcLFactorylECAPcLcLParticlegR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLFactorylECAPcLcLParticlegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticle(void *p = nullptr);
   static void *newArray_CAPcLcLParticle(Long_t size, void *p);
   static void delete_CAPcLcLParticle(void *p);
   static void deleteArray_CAPcLcLParticle(void *p);
   static void destruct_CAPcLcLParticle(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Particle*)
   {
      ::CAP::Particle *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Particle >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Particle", ::CAP::Particle::Class_Version(), "Particle.hpp", 49,
                  typeid(::CAP::Particle), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::Particle::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Particle) );
      instance.SetNew(&new_CAPcLcLParticle);
      instance.SetNewArray(&newArray_CAPcLcLParticle);
      instance.SetDelete(&delete_CAPcLcLParticle);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticle);
      instance.SetDestructor(&destruct_CAPcLcLParticle);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Particle*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Particle*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Particle*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLManagerlECAPcLcLEventgR_Dictionary();
   static void CAPcLcLManagerlECAPcLcLEventgR_TClassManip(TClass*);
   static void *new_CAPcLcLManagerlECAPcLcLEventgR(void *p = nullptr);
   static void *newArray_CAPcLcLManagerlECAPcLcLEventgR(Long_t size, void *p);
   static void delete_CAPcLcLManagerlECAPcLcLEventgR(void *p);
   static void deleteArray_CAPcLcLManagerlECAPcLcLEventgR(void *p);
   static void destruct_CAPcLcLManagerlECAPcLcLEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Manager<CAP::Event>*)
   {
      ::CAP::Manager<CAP::Event> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Manager<CAP::Event> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Manager<CAP::Event>", ::CAP::Manager<CAP::Event>::Class_Version(), "Manager.hpp", 33,
                  typeid(::CAP::Manager<CAP::Event>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLManagerlECAPcLcLEventgR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Manager<CAP::Event>) );
      instance.SetNew(&new_CAPcLcLManagerlECAPcLcLEventgR);
      instance.SetNewArray(&newArray_CAPcLcLManagerlECAPcLcLEventgR);
      instance.SetDelete(&delete_CAPcLcLManagerlECAPcLcLEventgR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLManagerlECAPcLcLEventgR);
      instance.SetDestructor(&destruct_CAPcLcLManagerlECAPcLcLEventgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Manager<CAP::Event>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Manager<CAP::Event>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Manager<CAP::Event>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLManagerlECAPcLcLEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Manager<CAP::Event>*>(nullptr))->GetClass();
      CAPcLcLManagerlECAPcLcLEventgR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLManagerlECAPcLcLEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLManagerlECAPcLcLEventFiltergR_Dictionary();
   static void CAPcLcLManagerlECAPcLcLEventFiltergR_TClassManip(TClass*);
   static void *new_CAPcLcLManagerlECAPcLcLEventFiltergR(void *p = nullptr);
   static void *newArray_CAPcLcLManagerlECAPcLcLEventFiltergR(Long_t size, void *p);
   static void delete_CAPcLcLManagerlECAPcLcLEventFiltergR(void *p);
   static void deleteArray_CAPcLcLManagerlECAPcLcLEventFiltergR(void *p);
   static void destruct_CAPcLcLManagerlECAPcLcLEventFiltergR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Manager<CAP::EventFilter>*)
   {
      ::CAP::Manager<CAP::EventFilter> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Manager<CAP::EventFilter> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Manager<CAP::EventFilter>", ::CAP::Manager<CAP::EventFilter>::Class_Version(), "Manager.hpp", 33,
                  typeid(::CAP::Manager<CAP::EventFilter>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLManagerlECAPcLcLEventFiltergR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Manager<CAP::EventFilter>) );
      instance.SetNew(&new_CAPcLcLManagerlECAPcLcLEventFiltergR);
      instance.SetNewArray(&newArray_CAPcLcLManagerlECAPcLcLEventFiltergR);
      instance.SetDelete(&delete_CAPcLcLManagerlECAPcLcLEventFiltergR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLManagerlECAPcLcLEventFiltergR);
      instance.SetDestructor(&destruct_CAPcLcLManagerlECAPcLcLEventFiltergR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Manager<CAP::EventFilter>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Manager<CAP::EventFilter>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Manager<CAP::EventFilter>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLManagerlECAPcLcLEventFiltergR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Manager<CAP::EventFilter>*>(nullptr))->GetClass();
      CAPcLcLManagerlECAPcLcLEventFiltergR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLManagerlECAPcLcLEventFiltergR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLManagerlECAPcLcLParticleFiltergR_Dictionary();
   static void CAPcLcLManagerlECAPcLcLParticleFiltergR_TClassManip(TClass*);
   static void *new_CAPcLcLManagerlECAPcLcLParticleFiltergR(void *p = nullptr);
   static void *newArray_CAPcLcLManagerlECAPcLcLParticleFiltergR(Long_t size, void *p);
   static void delete_CAPcLcLManagerlECAPcLcLParticleFiltergR(void *p);
   static void deleteArray_CAPcLcLManagerlECAPcLcLParticleFiltergR(void *p);
   static void destruct_CAPcLcLManagerlECAPcLcLParticleFiltergR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Manager<CAP::ParticleFilter>*)
   {
      ::CAP::Manager<CAP::ParticleFilter> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Manager<CAP::ParticleFilter> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Manager<CAP::ParticleFilter>", ::CAP::Manager<CAP::ParticleFilter>::Class_Version(), "Manager.hpp", 33,
                  typeid(::CAP::Manager<CAP::ParticleFilter>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLManagerlECAPcLcLParticleFiltergR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Manager<CAP::ParticleFilter>) );
      instance.SetNew(&new_CAPcLcLManagerlECAPcLcLParticleFiltergR);
      instance.SetNewArray(&newArray_CAPcLcLManagerlECAPcLcLParticleFiltergR);
      instance.SetDelete(&delete_CAPcLcLManagerlECAPcLcLParticleFiltergR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLManagerlECAPcLcLParticleFiltergR);
      instance.SetDestructor(&destruct_CAPcLcLManagerlECAPcLcLParticleFiltergR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Manager<CAP::ParticleFilter>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Manager<CAP::ParticleFilter>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Manager<CAP::ParticleFilter>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLManagerlECAPcLcLParticleFiltergR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Manager<CAP::ParticleFilter>*>(nullptr))->GetClass();
      CAPcLcLManagerlECAPcLcLParticleFiltergR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLManagerlECAPcLcLParticleFiltergR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void delete_CAPcLcLEvent(void *p);
   static void deleteArray_CAPcLcLEvent(void *p);
   static void destruct_CAPcLcLEvent(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Event*)
   {
      ::CAP::Event *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Event >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Event", ::CAP::Event::Class_Version(), "Event.hpp", 29,
                  typeid(::CAP::Event), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::Event::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Event) );
      instance.SetDelete(&delete_CAPcLcLEvent);
      instance.SetDeleteArray(&deleteArray_CAPcLcLEvent);
      instance.SetDestructor(&destruct_CAPcLcLEvent);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Event*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Event*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Event*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLEventAccountant(void *p = nullptr);
   static void *newArray_CAPcLcLEventAccountant(Long_t size, void *p);
   static void delete_CAPcLcLEventAccountant(void *p);
   static void deleteArray_CAPcLcLEventAccountant(void *p);
   static void destruct_CAPcLcLEventAccountant(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::EventAccountant*)
   {
      ::CAP::EventAccountant *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::EventAccountant >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::EventAccountant", ::CAP::EventAccountant::Class_Version(), "EventAccountant.hpp", 20,
                  typeid(::CAP::EventAccountant), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::EventAccountant::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::EventAccountant) );
      instance.SetNew(&new_CAPcLcLEventAccountant);
      instance.SetNewArray(&newArray_CAPcLcLEventAccountant);
      instance.SetDelete(&delete_CAPcLcLEventAccountant);
      instance.SetDeleteArray(&deleteArray_CAPcLcLEventAccountant);
      instance.SetDestructor(&destruct_CAPcLcLEventAccountant);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::EventAccountant*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::EventAccountant*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::EventAccountant*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLFilterlECAPcLcLEventgR_Dictionary();
   static void CAPcLcLFilterlECAPcLcLEventgR_TClassManip(TClass*);
   static void *new_CAPcLcLFilterlECAPcLcLEventgR(void *p = nullptr);
   static void *newArray_CAPcLcLFilterlECAPcLcLEventgR(Long_t size, void *p);
   static void delete_CAPcLcLFilterlECAPcLcLEventgR(void *p);
   static void deleteArray_CAPcLcLFilterlECAPcLcLEventgR(void *p);
   static void destruct_CAPcLcLFilterlECAPcLcLEventgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Filter<CAP::Event>*)
   {
      ::CAP::Filter<CAP::Event> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CAP::Filter<CAP::Event>));
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Filter<CAP::Event>", "Filter.hpp", 34,
                  typeid(::CAP::Filter<CAP::Event>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLFilterlECAPcLcLEventgR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Filter<CAP::Event>) );
      instance.SetNew(&new_CAPcLcLFilterlECAPcLcLEventgR);
      instance.SetNewArray(&newArray_CAPcLcLFilterlECAPcLcLEventgR);
      instance.SetDelete(&delete_CAPcLcLFilterlECAPcLcLEventgR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLFilterlECAPcLcLEventgR);
      instance.SetDestructor(&destruct_CAPcLcLFilterlECAPcLcLEventgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Filter<CAP::Event>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Filter<CAP::Event>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Filter<CAP::Event>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLFilterlECAPcLcLEventgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Filter<CAP::Event>*>(nullptr))->GetClass();
      CAPcLcLFilterlECAPcLcLEventgR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLFilterlECAPcLcLEventgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLFilterlECAPcLcLParticlegR_Dictionary();
   static void CAPcLcLFilterlECAPcLcLParticlegR_TClassManip(TClass*);
   static void *new_CAPcLcLFilterlECAPcLcLParticlegR(void *p = nullptr);
   static void *newArray_CAPcLcLFilterlECAPcLcLParticlegR(Long_t size, void *p);
   static void delete_CAPcLcLFilterlECAPcLcLParticlegR(void *p);
   static void deleteArray_CAPcLcLFilterlECAPcLcLParticlegR(void *p);
   static void destruct_CAPcLcLFilterlECAPcLcLParticlegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Filter<CAP::Particle>*)
   {
      ::CAP::Filter<CAP::Particle> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CAP::Filter<CAP::Particle>));
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Filter<CAP::Particle>", "Filter.hpp", 34,
                  typeid(::CAP::Filter<CAP::Particle>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLFilterlECAPcLcLParticlegR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Filter<CAP::Particle>) );
      instance.SetNew(&new_CAPcLcLFilterlECAPcLcLParticlegR);
      instance.SetNewArray(&newArray_CAPcLcLFilterlECAPcLcLParticlegR);
      instance.SetDelete(&delete_CAPcLcLFilterlECAPcLcLParticlegR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLFilterlECAPcLcLParticlegR);
      instance.SetDestructor(&destruct_CAPcLcLFilterlECAPcLcLParticlegR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Filter<CAP::Particle>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Filter<CAP::Particle>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Filter<CAP::Particle>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLFilterlECAPcLcLParticlegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Filter<CAP::Particle>*>(nullptr))->GetClass();
      CAPcLcLFilterlECAPcLcLParticlegR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLFilterlECAPcLcLParticlegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLEventFilter(void *p = nullptr);
   static void *newArray_CAPcLcLEventFilter(Long_t size, void *p);
   static void delete_CAPcLcLEventFilter(void *p);
   static void deleteArray_CAPcLcLEventFilter(void *p);
   static void destruct_CAPcLcLEventFilter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::EventFilter*)
   {
      ::CAP::EventFilter *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::EventFilter >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::EventFilter", ::CAP::EventFilter::Class_Version(), "EventFilter.hpp", 20,
                  typeid(::CAP::EventFilter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::EventFilter::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::EventFilter) );
      instance.SetNew(&new_CAPcLcLEventFilter);
      instance.SetNewArray(&newArray_CAPcLcLEventFilter);
      instance.SetDelete(&delete_CAPcLcLEventFilter);
      instance.SetDeleteArray(&deleteArray_CAPcLcLEventFilter);
      instance.SetDestructor(&destruct_CAPcLcLEventFilter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::EventFilter*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::EventFilter*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::EventFilter*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticleFilter(void *p = nullptr);
   static void *newArray_CAPcLcLParticleFilter(Long_t size, void *p);
   static void delete_CAPcLcLParticleFilter(void *p);
   static void deleteArray_CAPcLcLParticleFilter(void *p);
   static void destruct_CAPcLcLParticleFilter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleFilter*)
   {
      ::CAP::ParticleFilter *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleFilter >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleFilter", ::CAP::ParticleFilter::Class_Version(), "ParticleFilter.hpp", 20,
                  typeid(::CAP::ParticleFilter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleFilter::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleFilter) );
      instance.SetNew(&new_CAPcLcLParticleFilter);
      instance.SetNewArray(&newArray_CAPcLcLParticleFilter);
      instance.SetDelete(&delete_CAPcLcLParticleFilter);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleFilter);
      instance.SetDestructor(&destruct_CAPcLcLParticleFilter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleFilter*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleFilter*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleFilter*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLEventCountHistos(void *p = nullptr);
   static void *newArray_CAPcLcLEventCountHistos(Long_t size, void *p);
   static void delete_CAPcLcLEventCountHistos(void *p);
   static void deleteArray_CAPcLcLEventCountHistos(void *p);
   static void destruct_CAPcLcLEventCountHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::EventCountHistos*)
   {
      ::CAP::EventCountHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::EventCountHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::EventCountHistos", ::CAP::EventCountHistos::Class_Version(), "EventCountHistos.hpp", 22,
                  typeid(::CAP::EventCountHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::EventCountHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::EventCountHistos) );
      instance.SetNew(&new_CAPcLcLEventCountHistos);
      instance.SetNewArray(&newArray_CAPcLcLEventCountHistos);
      instance.SetDelete(&delete_CAPcLcLEventCountHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLEventCountHistos);
      instance.SetDestructor(&destruct_CAPcLcLEventCountHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::EventCountHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::EventCountHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::EventCountHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLEventTask(void *p = nullptr);
   static void *newArray_CAPcLcLEventTask(Long_t size, void *p);
   static void delete_CAPcLcLEventTask(void *p);
   static void deleteArray_CAPcLcLEventTask(void *p);
   static void destruct_CAPcLcLEventTask(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::EventTask*)
   {
      ::CAP::EventTask *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::EventTask >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::EventTask", ::CAP::EventTask::Class_Version(), "EventTask.hpp", 27,
                  typeid(::CAP::EventTask), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::EventTask::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::EventTask) );
      instance.SetNew(&new_CAPcLcLEventTask);
      instance.SetNewArray(&newArray_CAPcLcLEventTask);
      instance.SetDelete(&delete_CAPcLcLEventTask);
      instance.SetDeleteArray(&deleteArray_CAPcLcLEventTask);
      instance.SetDestructor(&destruct_CAPcLcLEventTask);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::EventTask*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::EventTask*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::EventTask*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLEventIterator(void *p = nullptr);
   static void *newArray_CAPcLcLEventIterator(Long_t size, void *p);
   static void delete_CAPcLcLEventIterator(void *p);
   static void deleteArray_CAPcLcLEventIterator(void *p);
   static void destruct_CAPcLcLEventIterator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::EventIterator*)
   {
      ::CAP::EventIterator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::EventIterator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::EventIterator", ::CAP::EventIterator::Class_Version(), "EventIterator.hpp", 26,
                  typeid(::CAP::EventIterator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::EventIterator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::EventIterator) );
      instance.SetNew(&new_CAPcLcLEventIterator);
      instance.SetNewArray(&newArray_CAPcLcLEventIterator);
      instance.SetDelete(&delete_CAPcLcLEventIterator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLEventIterator);
      instance.SetDestructor(&destruct_CAPcLcLEventIterator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::EventIterator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::EventIterator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::EventIterator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticleDecayer(void *p = nullptr);
   static void *newArray_CAPcLcLParticleDecayer(Long_t size, void *p);
   static void delete_CAPcLcLParticleDecayer(void *p);
   static void deleteArray_CAPcLcLParticleDecayer(void *p);
   static void destruct_CAPcLcLParticleDecayer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleDecayer*)
   {
      ::CAP::ParticleDecayer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleDecayer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleDecayer", ::CAP::ParticleDecayer::Class_Version(), "ParticleDecayer.hpp", 24,
                  typeid(::CAP::ParticleDecayer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleDecayer::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleDecayer) );
      instance.SetNew(&new_CAPcLcLParticleDecayer);
      instance.SetNewArray(&newArray_CAPcLcLParticleDecayer);
      instance.SetDelete(&delete_CAPcLcLParticleDecayer);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleDecayer);
      instance.SetDestructor(&destruct_CAPcLcLParticleDecayer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleDecayer*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleDecayer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleDecayer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticleDecayerTask(void *p = nullptr);
   static void *newArray_CAPcLcLParticleDecayerTask(Long_t size, void *p);
   static void delete_CAPcLcLParticleDecayerTask(void *p);
   static void deleteArray_CAPcLcLParticleDecayerTask(void *p);
   static void destruct_CAPcLcLParticleDecayerTask(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleDecayerTask*)
   {
      ::CAP::ParticleDecayerTask *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleDecayerTask >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleDecayerTask", ::CAP::ParticleDecayerTask::Class_Version(), "ParticleDecayerTask.hpp", 30,
                  typeid(::CAP::ParticleDecayerTask), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleDecayerTask::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleDecayerTask) );
      instance.SetNew(&new_CAPcLcLParticleDecayerTask);
      instance.SetNewArray(&newArray_CAPcLcLParticleDecayerTask);
      instance.SetDelete(&delete_CAPcLcLParticleDecayerTask);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleDecayerTask);
      instance.SetDestructor(&destruct_CAPcLcLParticleDecayerTask);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleDecayerTask*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleDecayerTask*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleDecayerTask*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticlePairFilter(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePairFilter(Long_t size, void *p);
   static void delete_CAPcLcLParticlePairFilter(void *p);
   static void deleteArray_CAPcLcLParticlePairFilter(void *p);
   static void destruct_CAPcLcLParticlePairFilter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePairFilter*)
   {
      ::CAP::ParticlePairFilter *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePairFilter >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePairFilter", ::CAP::ParticlePairFilter::Class_Version(), "ParticlePairFilter.hpp", 23,
                  typeid(::CAP::ParticlePairFilter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePairFilter::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePairFilter) );
      instance.SetNew(&new_CAPcLcLParticlePairFilter);
      instance.SetNewArray(&newArray_CAPcLcLParticlePairFilter);
      instance.SetDelete(&delete_CAPcLcLParticlePairFilter);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePairFilter);
      instance.SetDestructor(&destruct_CAPcLcLParticlePairFilter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePairFilter*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePairFilter*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePairFilter*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLRootChainManager(void *p = nullptr);
   static void *newArray_CAPcLcLRootChainManager(Long_t size, void *p);
   static void delete_CAPcLcLRootChainManager(void *p);
   static void deleteArray_CAPcLcLRootChainManager(void *p);
   static void destruct_CAPcLcLRootChainManager(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::RootChainManager*)
   {
      ::CAP::RootChainManager *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::RootChainManager >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::RootChainManager", ::CAP::RootChainManager::Class_Version(), "RootChainManager.hpp", 22,
                  typeid(::CAP::RootChainManager), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::RootChainManager::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::RootChainManager) );
      instance.SetNew(&new_CAPcLcLRootChainManager);
      instance.SetNewArray(&newArray_CAPcLcLRootChainManager);
      instance.SetDelete(&delete_CAPcLcLRootChainManager);
      instance.SetDeleteArray(&deleteArray_CAPcLcLRootChainManager);
      instance.SetDestructor(&destruct_CAPcLcLRootChainManager);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::RootChainManager*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::RootChainManager*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::RootChainManager*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLFilterCreator(void *p = nullptr);
   static void *newArray_CAPcLcLFilterCreator(Long_t size, void *p);
   static void delete_CAPcLcLFilterCreator(void *p);
   static void deleteArray_CAPcLcLFilterCreator(void *p);
   static void destruct_CAPcLcLFilterCreator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::FilterCreator*)
   {
      ::CAP::FilterCreator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::FilterCreator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::FilterCreator", ::CAP::FilterCreator::Class_Version(), "FilterCreator.hpp", 23,
                  typeid(::CAP::FilterCreator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::FilterCreator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::FilterCreator) );
      instance.SetNew(&new_CAPcLcLFilterCreator);
      instance.SetNewArray(&newArray_CAPcLcLFilterCreator);
      instance.SetDelete(&delete_CAPcLcLFilterCreator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLFilterCreator);
      instance.SetDestructor(&destruct_CAPcLcLFilterCreator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::FilterCreator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::FilterCreator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::FilterCreator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
template <> atomic_TClass_ptr Factory<CAP::Particle>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *Factory<CAP::Particle>::Class_Name()
{
   return "CAP::Factory<CAP::Particle>";
}

//______________________________________________________________________________
template <> const char *Factory<CAP::Particle>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Factory<CAP::Particle>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int Factory<CAP::Particle>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Factory<CAP::Particle>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *Factory<CAP::Particle>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Factory<CAP::Particle>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *Factory<CAP::Particle>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Factory<CAP::Particle>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr Particle::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Particle::Class_Name()
{
   return "CAP::Particle";
}

//______________________________________________________________________________
const char *Particle::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Particle*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Particle::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Particle*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Particle::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Particle*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Particle::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Particle*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
template <> atomic_TClass_ptr Manager<CAP::Event>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *Manager<CAP::Event>::Class_Name()
{
   return "CAP::Manager<CAP::Event>";
}

//______________________________________________________________________________
template <> const char *Manager<CAP::Event>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::Event>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int Manager<CAP::Event>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::Event>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *Manager<CAP::Event>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::Event>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *Manager<CAP::Event>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::Event>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
template <> atomic_TClass_ptr Manager<CAP::EventFilter>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *Manager<CAP::EventFilter>::Class_Name()
{
   return "CAP::Manager<CAP::EventFilter>";
}

//______________________________________________________________________________
template <> const char *Manager<CAP::EventFilter>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::EventFilter>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int Manager<CAP::EventFilter>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::EventFilter>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *Manager<CAP::EventFilter>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::EventFilter>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *Manager<CAP::EventFilter>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::EventFilter>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
template <> atomic_TClass_ptr Manager<CAP::ParticleFilter>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *Manager<CAP::ParticleFilter>::Class_Name()
{
   return "CAP::Manager<CAP::ParticleFilter>";
}

//______________________________________________________________________________
template <> const char *Manager<CAP::ParticleFilter>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::ParticleFilter>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int Manager<CAP::ParticleFilter>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::ParticleFilter>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *Manager<CAP::ParticleFilter>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::ParticleFilter>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *Manager<CAP::ParticleFilter>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::ParticleFilter>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr Event::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Event::Class_Name()
{
   return "CAP::Event";
}

//______________________________________________________________________________
const char *Event::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Event*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Event::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Event*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Event::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Event*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Event::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Event*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr EventAccountant::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *EventAccountant::Class_Name()
{
   return "CAP::EventAccountant";
}

//______________________________________________________________________________
const char *EventAccountant::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventAccountant*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int EventAccountant::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventAccountant*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventAccountant::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventAccountant*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventAccountant::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventAccountant*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr EventFilter::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *EventFilter::Class_Name()
{
   return "CAP::EventFilter";
}

//______________________________________________________________________________
const char *EventFilter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventFilter*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int EventFilter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventFilter*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventFilter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventFilter*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventFilter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventFilter*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleFilter::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleFilter::Class_Name()
{
   return "CAP::ParticleFilter";
}

//______________________________________________________________________________
const char *ParticleFilter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleFilter*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleFilter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleFilter*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleFilter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleFilter*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleFilter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleFilter*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr EventCountHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *EventCountHistos::Class_Name()
{
   return "CAP::EventCountHistos";
}

//______________________________________________________________________________
const char *EventCountHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventCountHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int EventCountHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventCountHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventCountHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventCountHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventCountHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventCountHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr EventTask::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *EventTask::Class_Name()
{
   return "CAP::EventTask";
}

//______________________________________________________________________________
const char *EventTask::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventTask*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int EventTask::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventTask*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventTask::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventTask*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventTask::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventTask*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr EventIterator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *EventIterator::Class_Name()
{
   return "CAP::EventIterator";
}

//______________________________________________________________________________
const char *EventIterator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventIterator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int EventIterator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventIterator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventIterator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventIterator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventIterator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventIterator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleDecayer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleDecayer::Class_Name()
{
   return "CAP::ParticleDecayer";
}

//______________________________________________________________________________
const char *ParticleDecayer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDecayer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleDecayer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDecayer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleDecayer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDecayer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleDecayer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDecayer*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleDecayerTask::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleDecayerTask::Class_Name()
{
   return "CAP::ParticleDecayerTask";
}

//______________________________________________________________________________
const char *ParticleDecayerTask::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDecayerTask*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleDecayerTask::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDecayerTask*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleDecayerTask::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDecayerTask*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleDecayerTask::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDecayerTask*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePairFilter::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePairFilter::Class_Name()
{
   return "CAP::ParticlePairFilter";
}

//______________________________________________________________________________
const char *ParticlePairFilter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairFilter*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePairFilter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairFilter*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePairFilter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairFilter*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePairFilter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairFilter*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr RootChainManager::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *RootChainManager::Class_Name()
{
   return "CAP::RootChainManager";
}

//______________________________________________________________________________
const char *RootChainManager::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::RootChainManager*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int RootChainManager::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::RootChainManager*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RootChainManager::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::RootChainManager*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RootChainManager::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::RootChainManager*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr FilterCreator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *FilterCreator::Class_Name()
{
   return "CAP::FilterCreator";
}

//______________________________________________________________________________
const char *FilterCreator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::FilterCreator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int FilterCreator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::FilterCreator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *FilterCreator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::FilterCreator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *FilterCreator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::FilterCreator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
template <> void Factory<CAP::Particle>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Factory<CAP::Particle>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Factory<CAP::Particle>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Factory<CAP::Particle>::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLFactorylECAPcLcLParticlegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Factory<CAP::Particle> : new ::CAP::Factory<CAP::Particle>;
   }
   static void *newArray_CAPcLcLFactorylECAPcLcLParticlegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Factory<CAP::Particle>[nElements] : new ::CAP::Factory<CAP::Particle>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLFactorylECAPcLcLParticlegR(void *p) {
      delete (static_cast<::CAP::Factory<CAP::Particle>*>(p));
   }
   static void deleteArray_CAPcLcLFactorylECAPcLcLParticlegR(void *p) {
      delete [] (static_cast<::CAP::Factory<CAP::Particle>*>(p));
   }
   static void destruct_CAPcLcLFactorylECAPcLcLParticlegR(void *p) {
      typedef ::CAP::Factory<CAP::Particle> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Factory<CAP::Particle>

namespace CAP {
//______________________________________________________________________________
void Particle::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Particle.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Particle::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Particle::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticle(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Particle : new ::CAP::Particle;
   }
   static void *newArray_CAPcLcLParticle(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Particle[nElements] : new ::CAP::Particle[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticle(void *p) {
      delete (static_cast<::CAP::Particle*>(p));
   }
   static void deleteArray_CAPcLcLParticle(void *p) {
      delete [] (static_cast<::CAP::Particle*>(p));
   }
   static void destruct_CAPcLcLParticle(void *p) {
      typedef ::CAP::Particle current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Particle

namespace CAP {
//______________________________________________________________________________
template <> void Manager<CAP::Event>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Manager<CAP::Event>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Manager<CAP::Event>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Manager<CAP::Event>::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLManagerlECAPcLcLEventgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Manager<CAP::Event> : new ::CAP::Manager<CAP::Event>;
   }
   static void *newArray_CAPcLcLManagerlECAPcLcLEventgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Manager<CAP::Event>[nElements] : new ::CAP::Manager<CAP::Event>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLManagerlECAPcLcLEventgR(void *p) {
      delete (static_cast<::CAP::Manager<CAP::Event>*>(p));
   }
   static void deleteArray_CAPcLcLManagerlECAPcLcLEventgR(void *p) {
      delete [] (static_cast<::CAP::Manager<CAP::Event>*>(p));
   }
   static void destruct_CAPcLcLManagerlECAPcLcLEventgR(void *p) {
      typedef ::CAP::Manager<CAP::Event> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Manager<CAP::Event>

namespace CAP {
//______________________________________________________________________________
template <> void Manager<CAP::EventFilter>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Manager<CAP::EventFilter>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Manager<CAP::EventFilter>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Manager<CAP::EventFilter>::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLManagerlECAPcLcLEventFiltergR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Manager<CAP::EventFilter> : new ::CAP::Manager<CAP::EventFilter>;
   }
   static void *newArray_CAPcLcLManagerlECAPcLcLEventFiltergR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Manager<CAP::EventFilter>[nElements] : new ::CAP::Manager<CAP::EventFilter>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLManagerlECAPcLcLEventFiltergR(void *p) {
      delete (static_cast<::CAP::Manager<CAP::EventFilter>*>(p));
   }
   static void deleteArray_CAPcLcLManagerlECAPcLcLEventFiltergR(void *p) {
      delete [] (static_cast<::CAP::Manager<CAP::EventFilter>*>(p));
   }
   static void destruct_CAPcLcLManagerlECAPcLcLEventFiltergR(void *p) {
      typedef ::CAP::Manager<CAP::EventFilter> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Manager<CAP::EventFilter>

namespace CAP {
//______________________________________________________________________________
template <> void Manager<CAP::ParticleFilter>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Manager<CAP::ParticleFilter>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Manager<CAP::ParticleFilter>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Manager<CAP::ParticleFilter>::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLManagerlECAPcLcLParticleFiltergR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Manager<CAP::ParticleFilter> : new ::CAP::Manager<CAP::ParticleFilter>;
   }
   static void *newArray_CAPcLcLManagerlECAPcLcLParticleFiltergR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Manager<CAP::ParticleFilter>[nElements] : new ::CAP::Manager<CAP::ParticleFilter>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLManagerlECAPcLcLParticleFiltergR(void *p) {
      delete (static_cast<::CAP::Manager<CAP::ParticleFilter>*>(p));
   }
   static void deleteArray_CAPcLcLManagerlECAPcLcLParticleFiltergR(void *p) {
      delete [] (static_cast<::CAP::Manager<CAP::ParticleFilter>*>(p));
   }
   static void destruct_CAPcLcLManagerlECAPcLcLParticleFiltergR(void *p) {
      typedef ::CAP::Manager<CAP::ParticleFilter> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Manager<CAP::ParticleFilter>

namespace CAP {
//______________________________________________________________________________
void Event::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Event.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Event::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Event::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrapper around operator delete
   static void delete_CAPcLcLEvent(void *p) {
      delete (static_cast<::CAP::Event*>(p));
   }
   static void deleteArray_CAPcLcLEvent(void *p) {
      delete [] (static_cast<::CAP::Event*>(p));
   }
   static void destruct_CAPcLcLEvent(void *p) {
      typedef ::CAP::Event current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Event

namespace CAP {
//______________________________________________________________________________
void EventAccountant::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::EventAccountant.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::EventAccountant::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::EventAccountant::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLEventAccountant(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventAccountant : new ::CAP::EventAccountant;
   }
   static void *newArray_CAPcLcLEventAccountant(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventAccountant[nElements] : new ::CAP::EventAccountant[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLEventAccountant(void *p) {
      delete (static_cast<::CAP::EventAccountant*>(p));
   }
   static void deleteArray_CAPcLcLEventAccountant(void *p) {
      delete [] (static_cast<::CAP::EventAccountant*>(p));
   }
   static void destruct_CAPcLcLEventAccountant(void *p) {
      typedef ::CAP::EventAccountant current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::EventAccountant

namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLFilterlECAPcLcLEventgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Filter<CAP::Event> : new ::CAP::Filter<CAP::Event>;
   }
   static void *newArray_CAPcLcLFilterlECAPcLcLEventgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Filter<CAP::Event>[nElements] : new ::CAP::Filter<CAP::Event>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLFilterlECAPcLcLEventgR(void *p) {
      delete (static_cast<::CAP::Filter<CAP::Event>*>(p));
   }
   static void deleteArray_CAPcLcLFilterlECAPcLcLEventgR(void *p) {
      delete [] (static_cast<::CAP::Filter<CAP::Event>*>(p));
   }
   static void destruct_CAPcLcLFilterlECAPcLcLEventgR(void *p) {
      typedef ::CAP::Filter<CAP::Event> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Filter<CAP::Event>

namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLFilterlECAPcLcLParticlegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Filter<CAP::Particle> : new ::CAP::Filter<CAP::Particle>;
   }
   static void *newArray_CAPcLcLFilterlECAPcLcLParticlegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Filter<CAP::Particle>[nElements] : new ::CAP::Filter<CAP::Particle>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLFilterlECAPcLcLParticlegR(void *p) {
      delete (static_cast<::CAP::Filter<CAP::Particle>*>(p));
   }
   static void deleteArray_CAPcLcLFilterlECAPcLcLParticlegR(void *p) {
      delete [] (static_cast<::CAP::Filter<CAP::Particle>*>(p));
   }
   static void destruct_CAPcLcLFilterlECAPcLcLParticlegR(void *p) {
      typedef ::CAP::Filter<CAP::Particle> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Filter<CAP::Particle>

namespace CAP {
//______________________________________________________________________________
void EventFilter::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::EventFilter.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::EventFilter::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::EventFilter::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLEventFilter(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventFilter : new ::CAP::EventFilter;
   }
   static void *newArray_CAPcLcLEventFilter(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventFilter[nElements] : new ::CAP::EventFilter[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLEventFilter(void *p) {
      delete (static_cast<::CAP::EventFilter*>(p));
   }
   static void deleteArray_CAPcLcLEventFilter(void *p) {
      delete [] (static_cast<::CAP::EventFilter*>(p));
   }
   static void destruct_CAPcLcLEventFilter(void *p) {
      typedef ::CAP::EventFilter current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::EventFilter

namespace CAP {
//______________________________________________________________________________
void ParticleFilter::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleFilter.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleFilter::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleFilter::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleFilter(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleFilter : new ::CAP::ParticleFilter;
   }
   static void *newArray_CAPcLcLParticleFilter(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleFilter[nElements] : new ::CAP::ParticleFilter[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleFilter(void *p) {
      delete (static_cast<::CAP::ParticleFilter*>(p));
   }
   static void deleteArray_CAPcLcLParticleFilter(void *p) {
      delete [] (static_cast<::CAP::ParticleFilter*>(p));
   }
   static void destruct_CAPcLcLParticleFilter(void *p) {
      typedef ::CAP::ParticleFilter current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleFilter

namespace CAP {
//______________________________________________________________________________
void EventCountHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::EventCountHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::EventCountHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::EventCountHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLEventCountHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventCountHistos : new ::CAP::EventCountHistos;
   }
   static void *newArray_CAPcLcLEventCountHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventCountHistos[nElements] : new ::CAP::EventCountHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLEventCountHistos(void *p) {
      delete (static_cast<::CAP::EventCountHistos*>(p));
   }
   static void deleteArray_CAPcLcLEventCountHistos(void *p) {
      delete [] (static_cast<::CAP::EventCountHistos*>(p));
   }
   static void destruct_CAPcLcLEventCountHistos(void *p) {
      typedef ::CAP::EventCountHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::EventCountHistos

namespace CAP {
//______________________________________________________________________________
void EventTask::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::EventTask.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::EventTask::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::EventTask::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLEventTask(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventTask : new ::CAP::EventTask;
   }
   static void *newArray_CAPcLcLEventTask(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventTask[nElements] : new ::CAP::EventTask[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLEventTask(void *p) {
      delete (static_cast<::CAP::EventTask*>(p));
   }
   static void deleteArray_CAPcLcLEventTask(void *p) {
      delete [] (static_cast<::CAP::EventTask*>(p));
   }
   static void destruct_CAPcLcLEventTask(void *p) {
      typedef ::CAP::EventTask current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::EventTask

namespace CAP {
//______________________________________________________________________________
void EventIterator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::EventIterator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::EventIterator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::EventIterator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLEventIterator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventIterator : new ::CAP::EventIterator;
   }
   static void *newArray_CAPcLcLEventIterator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventIterator[nElements] : new ::CAP::EventIterator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLEventIterator(void *p) {
      delete (static_cast<::CAP::EventIterator*>(p));
   }
   static void deleteArray_CAPcLcLEventIterator(void *p) {
      delete [] (static_cast<::CAP::EventIterator*>(p));
   }
   static void destruct_CAPcLcLEventIterator(void *p) {
      typedef ::CAP::EventIterator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::EventIterator

namespace CAP {
//______________________________________________________________________________
void ParticleDecayer::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleDecayer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleDecayer::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleDecayer::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleDecayer(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDecayer : new ::CAP::ParticleDecayer;
   }
   static void *newArray_CAPcLcLParticleDecayer(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDecayer[nElements] : new ::CAP::ParticleDecayer[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleDecayer(void *p) {
      delete (static_cast<::CAP::ParticleDecayer*>(p));
   }
   static void deleteArray_CAPcLcLParticleDecayer(void *p) {
      delete [] (static_cast<::CAP::ParticleDecayer*>(p));
   }
   static void destruct_CAPcLcLParticleDecayer(void *p) {
      typedef ::CAP::ParticleDecayer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleDecayer

namespace CAP {
//______________________________________________________________________________
void ParticleDecayerTask::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleDecayerTask.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleDecayerTask::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleDecayerTask::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleDecayerTask(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDecayerTask : new ::CAP::ParticleDecayerTask;
   }
   static void *newArray_CAPcLcLParticleDecayerTask(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDecayerTask[nElements] : new ::CAP::ParticleDecayerTask[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleDecayerTask(void *p) {
      delete (static_cast<::CAP::ParticleDecayerTask*>(p));
   }
   static void deleteArray_CAPcLcLParticleDecayerTask(void *p) {
      delete [] (static_cast<::CAP::ParticleDecayerTask*>(p));
   }
   static void destruct_CAPcLcLParticleDecayerTask(void *p) {
      typedef ::CAP::ParticleDecayerTask current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleDecayerTask

namespace CAP {
//______________________________________________________________________________
void ParticlePairFilter::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePairFilter.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePairFilter::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePairFilter::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePairFilter(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairFilter : new ::CAP::ParticlePairFilter;
   }
   static void *newArray_CAPcLcLParticlePairFilter(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairFilter[nElements] : new ::CAP::ParticlePairFilter[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePairFilter(void *p) {
      delete (static_cast<::CAP::ParticlePairFilter*>(p));
   }
   static void deleteArray_CAPcLcLParticlePairFilter(void *p) {
      delete [] (static_cast<::CAP::ParticlePairFilter*>(p));
   }
   static void destruct_CAPcLcLParticlePairFilter(void *p) {
      typedef ::CAP::ParticlePairFilter current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePairFilter

namespace CAP {
//______________________________________________________________________________
void RootChainManager::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::RootChainManager.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::RootChainManager::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::RootChainManager::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLRootChainManager(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::RootChainManager : new ::CAP::RootChainManager;
   }
   static void *newArray_CAPcLcLRootChainManager(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::RootChainManager[nElements] : new ::CAP::RootChainManager[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLRootChainManager(void *p) {
      delete (static_cast<::CAP::RootChainManager*>(p));
   }
   static void deleteArray_CAPcLcLRootChainManager(void *p) {
      delete [] (static_cast<::CAP::RootChainManager*>(p));
   }
   static void destruct_CAPcLcLRootChainManager(void *p) {
      typedef ::CAP::RootChainManager current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::RootChainManager

namespace CAP {
//______________________________________________________________________________
void FilterCreator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::FilterCreator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::FilterCreator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::FilterCreator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLFilterCreator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::FilterCreator : new ::CAP::FilterCreator;
   }
   static void *newArray_CAPcLcLFilterCreator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::FilterCreator[nElements] : new ::CAP::FilterCreator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLFilterCreator(void *p) {
      delete (static_cast<::CAP::FilterCreator*>(p));
   }
   static void deleteArray_CAPcLcLFilterCreator(void *p) {
      delete [] (static_cast<::CAP::FilterCreator*>(p));
   }
   static void destruct_CAPcLcLFilterCreator(void *p) {
      typedef ::CAP::FilterCreator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::FilterCreator

namespace ROOT {
   static TClass *vectorlEboolgR_Dictionary();
   static void vectorlEboolgR_TClassManip(TClass*);
   static void *new_vectorlEboolgR(void *p = nullptr);
   static void *newArray_vectorlEboolgR(Long_t size, void *p);
   static void delete_vectorlEboolgR(void *p);
   static void deleteArray_vectorlEboolgR(void *p);
   static void destruct_vectorlEboolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<bool>*)
   {
      vector<bool> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<bool>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<bool>", -2, "vector", 1813,
                  typeid(vector<bool>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEboolgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<bool>) );
      instance.SetNew(&new_vectorlEboolgR);
      instance.SetNewArray(&newArray_vectorlEboolgR);
      instance.SetDelete(&delete_vectorlEboolgR);
      instance.SetDeleteArray(&deleteArray_vectorlEboolgR);
      instance.SetDestructor(&destruct_vectorlEboolgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<bool> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<bool>","std::__1::vector<bool, std::__1::allocator<bool>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<bool>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEboolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<bool>*>(nullptr))->GetClass();
      vectorlEboolgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEboolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEboolgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<bool> : new vector<bool>;
   }
   static void *newArray_vectorlEboolgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<bool>[nElements] : new vector<bool>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEboolgR(void *p) {
      delete (static_cast<vector<bool>*>(p));
   }
   static void deleteArray_vectorlEboolgR(void *p) {
      delete [] (static_cast<vector<bool>*>(p));
   }
   static void destruct_vectorlEboolgR(void *p) {
      typedef vector<bool> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<bool>

namespace ROOT {
   static TClass *vectorlETStringgR_Dictionary();
   static void vectorlETStringgR_TClassManip(TClass*);
   static void *new_vectorlETStringgR(void *p = nullptr);
   static void *newArray_vectorlETStringgR(Long_t size, void *p);
   static void delete_vectorlETStringgR(void *p);
   static void deleteArray_vectorlETStringgR(void *p);
   static void destruct_vectorlETStringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TString>*)
   {
      vector<TString> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TString>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TString>", -2, "vector", 387,
                  typeid(vector<TString>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETStringgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TString>) );
      instance.SetNew(&new_vectorlETStringgR);
      instance.SetNewArray(&newArray_vectorlETStringgR);
      instance.SetDelete(&delete_vectorlETStringgR);
      instance.SetDeleteArray(&deleteArray_vectorlETStringgR);
      instance.SetDestructor(&destruct_vectorlETStringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TString> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TString>","std::__1::vector<TString, std::__1::allocator<TString>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TString>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETStringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TString>*>(nullptr))->GetClass();
      vectorlETStringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETStringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETStringgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TString> : new vector<TString>;
   }
   static void *newArray_vectorlETStringgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TString>[nElements] : new vector<TString>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETStringgR(void *p) {
      delete (static_cast<vector<TString>*>(p));
   }
   static void deleteArray_vectorlETStringgR(void *p) {
      delete [] (static_cast<vector<TString>*>(p));
   }
   static void destruct_vectorlETStringgR(void *p) {
      typedef vector<TString> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TString>

namespace ROOT {
   static TClass *vectorlECAPcLcLParticleFiltermUgR_Dictionary();
   static void vectorlECAPcLcLParticleFiltermUgR_TClassManip(TClass*);
   static void *new_vectorlECAPcLcLParticleFiltermUgR(void *p = nullptr);
   static void *newArray_vectorlECAPcLcLParticleFiltermUgR(Long_t size, void *p);
   static void delete_vectorlECAPcLcLParticleFiltermUgR(void *p);
   static void deleteArray_vectorlECAPcLcLParticleFiltermUgR(void *p);
   static void destruct_vectorlECAPcLcLParticleFiltermUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CAP::ParticleFilter*>*)
   {
      vector<CAP::ParticleFilter*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CAP::ParticleFilter*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<CAP::ParticleFilter*>", -2, "vector", 387,
                  typeid(vector<CAP::ParticleFilter*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlECAPcLcLParticleFiltermUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<CAP::ParticleFilter*>) );
      instance.SetNew(&new_vectorlECAPcLcLParticleFiltermUgR);
      instance.SetNewArray(&newArray_vectorlECAPcLcLParticleFiltermUgR);
      instance.SetDelete(&delete_vectorlECAPcLcLParticleFiltermUgR);
      instance.SetDeleteArray(&deleteArray_vectorlECAPcLcLParticleFiltermUgR);
      instance.SetDestructor(&destruct_vectorlECAPcLcLParticleFiltermUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CAP::ParticleFilter*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<CAP::ParticleFilter*>","std::__1::vector<CAP::ParticleFilter*, std::__1::allocator<CAP::ParticleFilter*>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<CAP::ParticleFilter*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECAPcLcLParticleFiltermUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<CAP::ParticleFilter*>*>(nullptr))->GetClass();
      vectorlECAPcLcLParticleFiltermUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECAPcLcLParticleFiltermUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECAPcLcLParticleFiltermUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::ParticleFilter*> : new vector<CAP::ParticleFilter*>;
   }
   static void *newArray_vectorlECAPcLcLParticleFiltermUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::ParticleFilter*>[nElements] : new vector<CAP::ParticleFilter*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECAPcLcLParticleFiltermUgR(void *p) {
      delete (static_cast<vector<CAP::ParticleFilter*>*>(p));
   }
   static void deleteArray_vectorlECAPcLcLParticleFiltermUgR(void *p) {
      delete [] (static_cast<vector<CAP::ParticleFilter*>*>(p));
   }
   static void destruct_vectorlECAPcLcLParticleFiltermUgR(void *p) {
      typedef vector<CAP::ParticleFilter*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<CAP::ParticleFilter*>

namespace ROOT {
   static TClass *vectorlECAPcLcLParticlemUgR_Dictionary();
   static void vectorlECAPcLcLParticlemUgR_TClassManip(TClass*);
   static void *new_vectorlECAPcLcLParticlemUgR(void *p = nullptr);
   static void *newArray_vectorlECAPcLcLParticlemUgR(Long_t size, void *p);
   static void delete_vectorlECAPcLcLParticlemUgR(void *p);
   static void deleteArray_vectorlECAPcLcLParticlemUgR(void *p);
   static void destruct_vectorlECAPcLcLParticlemUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CAP::Particle*>*)
   {
      vector<CAP::Particle*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CAP::Particle*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<CAP::Particle*>", -2, "vector", 387,
                  typeid(vector<CAP::Particle*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlECAPcLcLParticlemUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<CAP::Particle*>) );
      instance.SetNew(&new_vectorlECAPcLcLParticlemUgR);
      instance.SetNewArray(&newArray_vectorlECAPcLcLParticlemUgR);
      instance.SetDelete(&delete_vectorlECAPcLcLParticlemUgR);
      instance.SetDeleteArray(&deleteArray_vectorlECAPcLcLParticlemUgR);
      instance.SetDestructor(&destruct_vectorlECAPcLcLParticlemUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CAP::Particle*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<CAP::Particle*>","std::__1::vector<CAP::Particle*, std::__1::allocator<CAP::Particle*>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<CAP::Particle*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECAPcLcLParticlemUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<CAP::Particle*>*>(nullptr))->GetClass();
      vectorlECAPcLcLParticlemUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECAPcLcLParticlemUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECAPcLcLParticlemUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::Particle*> : new vector<CAP::Particle*>;
   }
   static void *newArray_vectorlECAPcLcLParticlemUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::Particle*>[nElements] : new vector<CAP::Particle*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECAPcLcLParticlemUgR(void *p) {
      delete (static_cast<vector<CAP::Particle*>*>(p));
   }
   static void deleteArray_vectorlECAPcLcLParticlemUgR(void *p) {
      delete [] (static_cast<vector<CAP::Particle*>*>(p));
   }
   static void destruct_vectorlECAPcLcLParticlemUgR(void *p) {
      typedef vector<CAP::Particle*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<CAP::Particle*>

namespace ROOT {
   static TClass *vectorlECAPcLcLEventFiltermUgR_Dictionary();
   static void vectorlECAPcLcLEventFiltermUgR_TClassManip(TClass*);
   static void *new_vectorlECAPcLcLEventFiltermUgR(void *p = nullptr);
   static void *newArray_vectorlECAPcLcLEventFiltermUgR(Long_t size, void *p);
   static void delete_vectorlECAPcLcLEventFiltermUgR(void *p);
   static void deleteArray_vectorlECAPcLcLEventFiltermUgR(void *p);
   static void destruct_vectorlECAPcLcLEventFiltermUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CAP::EventFilter*>*)
   {
      vector<CAP::EventFilter*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CAP::EventFilter*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<CAP::EventFilter*>", -2, "vector", 387,
                  typeid(vector<CAP::EventFilter*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlECAPcLcLEventFiltermUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<CAP::EventFilter*>) );
      instance.SetNew(&new_vectorlECAPcLcLEventFiltermUgR);
      instance.SetNewArray(&newArray_vectorlECAPcLcLEventFiltermUgR);
      instance.SetDelete(&delete_vectorlECAPcLcLEventFiltermUgR);
      instance.SetDeleteArray(&deleteArray_vectorlECAPcLcLEventFiltermUgR);
      instance.SetDestructor(&destruct_vectorlECAPcLcLEventFiltermUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CAP::EventFilter*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<CAP::EventFilter*>","std::__1::vector<CAP::EventFilter*, std::__1::allocator<CAP::EventFilter*>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<CAP::EventFilter*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECAPcLcLEventFiltermUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<CAP::EventFilter*>*>(nullptr))->GetClass();
      vectorlECAPcLcLEventFiltermUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECAPcLcLEventFiltermUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECAPcLcLEventFiltermUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::EventFilter*> : new vector<CAP::EventFilter*>;
   }
   static void *newArray_vectorlECAPcLcLEventFiltermUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::EventFilter*>[nElements] : new vector<CAP::EventFilter*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECAPcLcLEventFiltermUgR(void *p) {
      delete (static_cast<vector<CAP::EventFilter*>*>(p));
   }
   static void deleteArray_vectorlECAPcLcLEventFiltermUgR(void *p) {
      delete [] (static_cast<vector<CAP::EventFilter*>*>(p));
   }
   static void destruct_vectorlECAPcLcLEventFiltermUgR(void *p) {
      typedef vector<CAP::EventFilter*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<CAP::EventFilter*>

namespace ROOT {
   static TClass *vectorlECAPcLcLEventmUgR_Dictionary();
   static void vectorlECAPcLcLEventmUgR_TClassManip(TClass*);
   static void *new_vectorlECAPcLcLEventmUgR(void *p = nullptr);
   static void *newArray_vectorlECAPcLcLEventmUgR(Long_t size, void *p);
   static void delete_vectorlECAPcLcLEventmUgR(void *p);
   static void deleteArray_vectorlECAPcLcLEventmUgR(void *p);
   static void destruct_vectorlECAPcLcLEventmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CAP::Event*>*)
   {
      vector<CAP::Event*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CAP::Event*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<CAP::Event*>", -2, "vector", 387,
                  typeid(vector<CAP::Event*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlECAPcLcLEventmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<CAP::Event*>) );
      instance.SetNew(&new_vectorlECAPcLcLEventmUgR);
      instance.SetNewArray(&newArray_vectorlECAPcLcLEventmUgR);
      instance.SetDelete(&delete_vectorlECAPcLcLEventmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlECAPcLcLEventmUgR);
      instance.SetDestructor(&destruct_vectorlECAPcLcLEventmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CAP::Event*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<CAP::Event*>","std::__1::vector<CAP::Event*, std::__1::allocator<CAP::Event*>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<CAP::Event*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECAPcLcLEventmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<CAP::Event*>*>(nullptr))->GetClass();
      vectorlECAPcLcLEventmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECAPcLcLEventmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECAPcLcLEventmUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::Event*> : new vector<CAP::Event*>;
   }
   static void *newArray_vectorlECAPcLcLEventmUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::Event*>[nElements] : new vector<CAP::Event*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECAPcLcLEventmUgR(void *p) {
      delete (static_cast<vector<CAP::Event*>*>(p));
   }
   static void deleteArray_vectorlECAPcLcLEventmUgR(void *p) {
      delete [] (static_cast<vector<CAP::Event*>*>(p));
   }
   static void destruct_vectorlECAPcLcLEventmUgR(void *p) {
      typedef vector<CAP::Event*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<CAP::Event*>

namespace ROOT {
   static TClass *vectorlECAPcLcLConditionmUgR_Dictionary();
   static void vectorlECAPcLcLConditionmUgR_TClassManip(TClass*);
   static void *new_vectorlECAPcLcLConditionmUgR(void *p = nullptr);
   static void *newArray_vectorlECAPcLcLConditionmUgR(Long_t size, void *p);
   static void delete_vectorlECAPcLcLConditionmUgR(void *p);
   static void deleteArray_vectorlECAPcLcLConditionmUgR(void *p);
   static void destruct_vectorlECAPcLcLConditionmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CAP::Condition*>*)
   {
      vector<CAP::Condition*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CAP::Condition*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<CAP::Condition*>", -2, "vector", 387,
                  typeid(vector<CAP::Condition*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlECAPcLcLConditionmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<CAP::Condition*>) );
      instance.SetNew(&new_vectorlECAPcLcLConditionmUgR);
      instance.SetNewArray(&newArray_vectorlECAPcLcLConditionmUgR);
      instance.SetDelete(&delete_vectorlECAPcLcLConditionmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlECAPcLcLConditionmUgR);
      instance.SetDestructor(&destruct_vectorlECAPcLcLConditionmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CAP::Condition*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<CAP::Condition*>","std::__1::vector<CAP::Condition*, std::__1::allocator<CAP::Condition*>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<CAP::Condition*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECAPcLcLConditionmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<CAP::Condition*>*>(nullptr))->GetClass();
      vectorlECAPcLcLConditionmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECAPcLcLConditionmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECAPcLcLConditionmUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::Condition*> : new vector<CAP::Condition*>;
   }
   static void *newArray_vectorlECAPcLcLConditionmUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::Condition*>[nElements] : new vector<CAP::Condition*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECAPcLcLConditionmUgR(void *p) {
      delete (static_cast<vector<CAP::Condition*>*>(p));
   }
   static void deleteArray_vectorlECAPcLcLConditionmUgR(void *p) {
      delete [] (static_cast<vector<CAP::Condition*>*>(p));
   }
   static void destruct_vectorlECAPcLcLConditionmUgR(void *p) {
      typedef vector<CAP::Condition*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<CAP::Condition*>

namespace {
  void TriggerDictionaryInitialization_libParticles_Impl() {
    static const char* headers[] = {
"Event.hpp",
"EventAccountant.hpp",
"EventFilter.hpp",
"EventCountHistos.hpp",
"EventTask.hpp",
"EventIterator.hpp",
"Particle.hpp",
"ParticleDecayer.hpp",
"ParticleDecayerTask.hpp",
"ParticleFilter.hpp",
"ParticlePairFilter.hpp",
"RootChainManager.hpp",
"FilterCreator.hpp",
nullptr
    };
    static const char* includePaths[] = {
"/Users/aa7526/opt/root_install/include",
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
"/Users/aa7526/opt/root_install/include/",
"/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Particles/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libParticles dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$Particle.hpp")))  __attribute__((annotate("$clingAutoload$Event.hpp")))  Particle;}
namespace CAP{template <class Object> class __attribute__((annotate("$clingAutoload$Factory.hpp")))  __attribute__((annotate("$clingAutoload$Event.hpp")))  Factory;
}
namespace CAP{class __attribute__((annotate("$clingAutoload$Event.hpp")))  Event;}
namespace CAP{template <class Event> class __attribute__((annotate("$clingAutoload$Event.hpp")))  Manager;
}
namespace CAP{class __attribute__((annotate("$clingAutoload$EventFilter.hpp")))  EventFilter;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleFilter.hpp")))  __attribute__((annotate("$clingAutoload$EventCountHistos.hpp")))  ParticleFilter;}
namespace CAP{class __attribute__((annotate("$clingAutoload$EventAccountant.hpp")))  EventAccountant;}
namespace CAP{template <class T> class __attribute__((annotate("$clingAutoload$Filter.hpp")))  __attribute__((annotate("$clingAutoload$EventFilter.hpp")))  Filter;
}
namespace CAP{class __attribute__((annotate("$clingAutoload$EventCountHistos.hpp")))  EventCountHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$EventTask.hpp")))  EventTask;}
namespace CAP{class __attribute__((annotate("$clingAutoload$EventIterator.hpp")))  EventIterator;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleDecayer.hpp")))  ParticleDecayer;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleDecayerTask.hpp")))  ParticleDecayerTask;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePairFilter.hpp")))  ParticlePairFilter;}
namespace CAP{class __attribute__((annotate("$clingAutoload$RootChainManager.hpp")))  RootChainManager;}
namespace CAP{class __attribute__((annotate("$clingAutoload$FilterCreator.hpp")))  FilterCreator;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libParticles dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "Event.hpp"
#include "EventAccountant.hpp"
#include "EventFilter.hpp"
#include "EventCountHistos.hpp"
#include "EventTask.hpp"
#include "EventIterator.hpp"
#include "Particle.hpp"
#include "ParticleDecayer.hpp"
#include "ParticleDecayerTask.hpp"
#include "ParticleFilter.hpp"
#include "ParticlePairFilter.hpp"
#include "RootChainManager.hpp"
#include "FilterCreator.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::Event", payloadCode, "@",
"CAP::EventAccountant", payloadCode, "@",
"CAP::EventCountHistos", payloadCode, "@",
"CAP::EventFilter", payloadCode, "@",
"CAP::EventIterator", payloadCode, "@",
"CAP::EventTask", payloadCode, "@",
"CAP::Factory<CAP::Particle>", payloadCode, "@",
"CAP::Filter<CAP::Event>", payloadCode, "@",
"CAP::Filter<CAP::Particle>", payloadCode, "@",
"CAP::FilterCreator", payloadCode, "@",
"CAP::Manager<CAP::Event>", payloadCode, "@",
"CAP::Manager<CAP::EventFilter>", payloadCode, "@",
"CAP::Manager<CAP::ParticleFilter>", payloadCode, "@",
"CAP::Particle", payloadCode, "@",
"CAP::ParticleDecayer", payloadCode, "@",
"CAP::ParticleDecayerTask", payloadCode, "@",
"CAP::ParticleFilter", payloadCode, "@",
"CAP::ParticlePairFilter", payloadCode, "@",
"CAP::RootChainManager", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libParticles",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libParticles_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libParticles_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libParticles() {
  TriggerDictionaryInitialization_libParticles_Impl();
}
