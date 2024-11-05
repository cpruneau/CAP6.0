// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__ParticlePair
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
#include "ParticlePairHistos.hpp"
#include "ParticlePairDerivedHistos.hpp"
#include "ParticlePairAnalyzer.hpp"
#include "ParticlePairCalculator.hpp"
#include "ParticlePairBfCalculator.hpp"
#include "ParticlePairBfHistos.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLParticlePairHistos(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePairHistos(Long_t size, void *p);
   static void delete_CAPcLcLParticlePairHistos(void *p);
   static void deleteArray_CAPcLcLParticlePairHistos(void *p);
   static void destruct_CAPcLcLParticlePairHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePairHistos*)
   {
      ::CAP::ParticlePairHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePairHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePairHistos", ::CAP::ParticlePairHistos::Class_Version(), "ParticlePairHistos.hpp", 23,
                  typeid(::CAP::ParticlePairHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePairHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePairHistos) );
      instance.SetNew(&new_CAPcLcLParticlePairHistos);
      instance.SetNewArray(&newArray_CAPcLcLParticlePairHistos);
      instance.SetDelete(&delete_CAPcLcLParticlePairHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePairHistos);
      instance.SetDestructor(&destruct_CAPcLcLParticlePairHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePairHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePairHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePairHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticlePairDerivedHistos(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePairDerivedHistos(Long_t size, void *p);
   static void delete_CAPcLcLParticlePairDerivedHistos(void *p);
   static void deleteArray_CAPcLcLParticlePairDerivedHistos(void *p);
   static void destruct_CAPcLcLParticlePairDerivedHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePairDerivedHistos*)
   {
      ::CAP::ParticlePairDerivedHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePairDerivedHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePairDerivedHistos", ::CAP::ParticlePairDerivedHistos::Class_Version(), "ParticlePairDerivedHistos.hpp", 27,
                  typeid(::CAP::ParticlePairDerivedHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePairDerivedHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePairDerivedHistos) );
      instance.SetNew(&new_CAPcLcLParticlePairDerivedHistos);
      instance.SetNewArray(&newArray_CAPcLcLParticlePairDerivedHistos);
      instance.SetDelete(&delete_CAPcLcLParticlePairDerivedHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePairDerivedHistos);
      instance.SetDestructor(&destruct_CAPcLcLParticlePairDerivedHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePairDerivedHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePairDerivedHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePairDerivedHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticlePairAnalyzer(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePairAnalyzer(Long_t size, void *p);
   static void delete_CAPcLcLParticlePairAnalyzer(void *p);
   static void deleteArray_CAPcLcLParticlePairAnalyzer(void *p);
   static void destruct_CAPcLcLParticlePairAnalyzer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePairAnalyzer*)
   {
      ::CAP::ParticlePairAnalyzer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePairAnalyzer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePairAnalyzer", ::CAP::ParticlePairAnalyzer::Class_Version(), "ParticlePairAnalyzer.hpp", 54,
                  typeid(::CAP::ParticlePairAnalyzer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePairAnalyzer::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePairAnalyzer) );
      instance.SetNew(&new_CAPcLcLParticlePairAnalyzer);
      instance.SetNewArray(&newArray_CAPcLcLParticlePairAnalyzer);
      instance.SetDelete(&delete_CAPcLcLParticlePairAnalyzer);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePairAnalyzer);
      instance.SetDestructor(&destruct_CAPcLcLParticlePairAnalyzer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePairAnalyzer*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePairAnalyzer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePairAnalyzer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticlePairCalculator(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePairCalculator(Long_t size, void *p);
   static void delete_CAPcLcLParticlePairCalculator(void *p);
   static void deleteArray_CAPcLcLParticlePairCalculator(void *p);
   static void destruct_CAPcLcLParticlePairCalculator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePairCalculator*)
   {
      ::CAP::ParticlePairCalculator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePairCalculator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePairCalculator", ::CAP::ParticlePairCalculator::Class_Version(), "ParticlePairCalculator.hpp", 54,
                  typeid(::CAP::ParticlePairCalculator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePairCalculator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePairCalculator) );
      instance.SetNew(&new_CAPcLcLParticlePairCalculator);
      instance.SetNewArray(&newArray_CAPcLcLParticlePairCalculator);
      instance.SetDelete(&delete_CAPcLcLParticlePairCalculator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePairCalculator);
      instance.SetDestructor(&destruct_CAPcLcLParticlePairCalculator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePairCalculator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePairCalculator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePairCalculator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticlePairBfCalculator(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePairBfCalculator(Long_t size, void *p);
   static void delete_CAPcLcLParticlePairBfCalculator(void *p);
   static void deleteArray_CAPcLcLParticlePairBfCalculator(void *p);
   static void destruct_CAPcLcLParticlePairBfCalculator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePairBfCalculator*)
   {
      ::CAP::ParticlePairBfCalculator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePairBfCalculator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePairBfCalculator", ::CAP::ParticlePairBfCalculator::Class_Version(), "ParticlePairBfCalculator.hpp", 19,
                  typeid(::CAP::ParticlePairBfCalculator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePairBfCalculator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePairBfCalculator) );
      instance.SetNew(&new_CAPcLcLParticlePairBfCalculator);
      instance.SetNewArray(&newArray_CAPcLcLParticlePairBfCalculator);
      instance.SetDelete(&delete_CAPcLcLParticlePairBfCalculator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePairBfCalculator);
      instance.SetDestructor(&destruct_CAPcLcLParticlePairBfCalculator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePairBfCalculator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePairBfCalculator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePairBfCalculator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticlePairBfHistos(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePairBfHistos(Long_t size, void *p);
   static void delete_CAPcLcLParticlePairBfHistos(void *p);
   static void deleteArray_CAPcLcLParticlePairBfHistos(void *p);
   static void destruct_CAPcLcLParticlePairBfHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePairBfHistos*)
   {
      ::CAP::ParticlePairBfHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePairBfHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePairBfHistos", ::CAP::ParticlePairBfHistos::Class_Version(), "ParticlePairBfHistos.hpp", 28,
                  typeid(::CAP::ParticlePairBfHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePairBfHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePairBfHistos) );
      instance.SetNew(&new_CAPcLcLParticlePairBfHistos);
      instance.SetNewArray(&newArray_CAPcLcLParticlePairBfHistos);
      instance.SetDelete(&delete_CAPcLcLParticlePairBfHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePairBfHistos);
      instance.SetDestructor(&destruct_CAPcLcLParticlePairBfHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePairBfHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePairBfHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePairBfHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePairHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePairHistos::Class_Name()
{
   return "CAP::ParticlePairHistos";
}

//______________________________________________________________________________
const char *ParticlePairHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePairHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePairHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePairHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePairDerivedHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePairDerivedHistos::Class_Name()
{
   return "CAP::ParticlePairDerivedHistos";
}

//______________________________________________________________________________
const char *ParticlePairDerivedHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairDerivedHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePairDerivedHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairDerivedHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePairDerivedHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairDerivedHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePairDerivedHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairDerivedHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePairAnalyzer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePairAnalyzer::Class_Name()
{
   return "CAP::ParticlePairAnalyzer";
}

//______________________________________________________________________________
const char *ParticlePairAnalyzer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairAnalyzer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePairAnalyzer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairAnalyzer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePairAnalyzer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairAnalyzer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePairAnalyzer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairAnalyzer*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePairCalculator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePairCalculator::Class_Name()
{
   return "CAP::ParticlePairCalculator";
}

//______________________________________________________________________________
const char *ParticlePairCalculator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairCalculator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePairCalculator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairCalculator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePairCalculator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairCalculator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePairCalculator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairCalculator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePairBfCalculator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePairBfCalculator::Class_Name()
{
   return "CAP::ParticlePairBfCalculator";
}

//______________________________________________________________________________
const char *ParticlePairBfCalculator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairBfCalculator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePairBfCalculator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairBfCalculator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePairBfCalculator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairBfCalculator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePairBfCalculator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairBfCalculator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePairBfHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePairBfHistos::Class_Name()
{
   return "CAP::ParticlePairBfHistos";
}

//______________________________________________________________________________
const char *ParticlePairBfHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairBfHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePairBfHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairBfHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePairBfHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairBfHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePairBfHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePairBfHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void ParticlePairHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePairHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePairHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePairHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePairHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairHistos : new ::CAP::ParticlePairHistos;
   }
   static void *newArray_CAPcLcLParticlePairHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairHistos[nElements] : new ::CAP::ParticlePairHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePairHistos(void *p) {
      delete (static_cast<::CAP::ParticlePairHistos*>(p));
   }
   static void deleteArray_CAPcLcLParticlePairHistos(void *p) {
      delete [] (static_cast<::CAP::ParticlePairHistos*>(p));
   }
   static void destruct_CAPcLcLParticlePairHistos(void *p) {
      typedef ::CAP::ParticlePairHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePairHistos

namespace CAP {
//______________________________________________________________________________
void ParticlePairDerivedHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePairDerivedHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePairDerivedHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePairDerivedHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePairDerivedHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairDerivedHistos : new ::CAP::ParticlePairDerivedHistos;
   }
   static void *newArray_CAPcLcLParticlePairDerivedHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairDerivedHistos[nElements] : new ::CAP::ParticlePairDerivedHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePairDerivedHistos(void *p) {
      delete (static_cast<::CAP::ParticlePairDerivedHistos*>(p));
   }
   static void deleteArray_CAPcLcLParticlePairDerivedHistos(void *p) {
      delete [] (static_cast<::CAP::ParticlePairDerivedHistos*>(p));
   }
   static void destruct_CAPcLcLParticlePairDerivedHistos(void *p) {
      typedef ::CAP::ParticlePairDerivedHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePairDerivedHistos

namespace CAP {
//______________________________________________________________________________
void ParticlePairAnalyzer::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePairAnalyzer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePairAnalyzer::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePairAnalyzer::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePairAnalyzer(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairAnalyzer : new ::CAP::ParticlePairAnalyzer;
   }
   static void *newArray_CAPcLcLParticlePairAnalyzer(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairAnalyzer[nElements] : new ::CAP::ParticlePairAnalyzer[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePairAnalyzer(void *p) {
      delete (static_cast<::CAP::ParticlePairAnalyzer*>(p));
   }
   static void deleteArray_CAPcLcLParticlePairAnalyzer(void *p) {
      delete [] (static_cast<::CAP::ParticlePairAnalyzer*>(p));
   }
   static void destruct_CAPcLcLParticlePairAnalyzer(void *p) {
      typedef ::CAP::ParticlePairAnalyzer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePairAnalyzer

namespace CAP {
//______________________________________________________________________________
void ParticlePairCalculator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePairCalculator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePairCalculator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePairCalculator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePairCalculator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairCalculator : new ::CAP::ParticlePairCalculator;
   }
   static void *newArray_CAPcLcLParticlePairCalculator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairCalculator[nElements] : new ::CAP::ParticlePairCalculator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePairCalculator(void *p) {
      delete (static_cast<::CAP::ParticlePairCalculator*>(p));
   }
   static void deleteArray_CAPcLcLParticlePairCalculator(void *p) {
      delete [] (static_cast<::CAP::ParticlePairCalculator*>(p));
   }
   static void destruct_CAPcLcLParticlePairCalculator(void *p) {
      typedef ::CAP::ParticlePairCalculator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePairCalculator

namespace CAP {
//______________________________________________________________________________
void ParticlePairBfCalculator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePairBfCalculator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePairBfCalculator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePairBfCalculator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePairBfCalculator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairBfCalculator : new ::CAP::ParticlePairBfCalculator;
   }
   static void *newArray_CAPcLcLParticlePairBfCalculator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairBfCalculator[nElements] : new ::CAP::ParticlePairBfCalculator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePairBfCalculator(void *p) {
      delete (static_cast<::CAP::ParticlePairBfCalculator*>(p));
   }
   static void deleteArray_CAPcLcLParticlePairBfCalculator(void *p) {
      delete [] (static_cast<::CAP::ParticlePairBfCalculator*>(p));
   }
   static void destruct_CAPcLcLParticlePairBfCalculator(void *p) {
      typedef ::CAP::ParticlePairBfCalculator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePairBfCalculator

namespace CAP {
//______________________________________________________________________________
void ParticlePairBfHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePairBfHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePairBfHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePairBfHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePairBfHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairBfHistos : new ::CAP::ParticlePairBfHistos;
   }
   static void *newArray_CAPcLcLParticlePairBfHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePairBfHistos[nElements] : new ::CAP::ParticlePairBfHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePairBfHistos(void *p) {
      delete (static_cast<::CAP::ParticlePairBfHistos*>(p));
   }
   static void deleteArray_CAPcLcLParticlePairBfHistos(void *p) {
      delete [] (static_cast<::CAP::ParticlePairBfHistos*>(p));
   }
   static void destruct_CAPcLcLParticlePairBfHistos(void *p) {
      typedef ::CAP::ParticlePairBfHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePairBfHistos

namespace {
  void TriggerDictionaryInitialization_libParticlePair_Impl() {
    static const char* headers[] = {
"ParticlePairHistos.hpp",
"ParticlePairDerivedHistos.hpp",
"ParticlePairAnalyzer.hpp",
"ParticlePairCalculator.hpp",
"ParticlePairBfCalculator.hpp",
"ParticlePairBfHistos.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/ParticlePair/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libParticlePair dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePairHistos.hpp")))  ParticlePairHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePairDerivedHistos.hpp")))  ParticlePairDerivedHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePairAnalyzer.hpp")))  ParticlePairAnalyzer;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePairCalculator.hpp")))  ParticlePairCalculator;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePairBfCalculator.hpp")))  ParticlePairBfCalculator;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePairBfHistos.hpp")))  ParticlePairBfHistos;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libParticlePair dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "ParticlePairHistos.hpp"
#include "ParticlePairDerivedHistos.hpp"
#include "ParticlePairAnalyzer.hpp"
#include "ParticlePairCalculator.hpp"
#include "ParticlePairBfCalculator.hpp"
#include "ParticlePairBfHistos.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::ParticlePairAnalyzer", payloadCode, "@",
"CAP::ParticlePairBfCalculator", payloadCode, "@",
"CAP::ParticlePairBfHistos", payloadCode, "@",
"CAP::ParticlePairCalculator", payloadCode, "@",
"CAP::ParticlePairDerivedHistos", payloadCode, "@",
"CAP::ParticlePairHistos", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libParticlePair",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libParticlePair_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libParticlePair_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libParticlePair() {
  TriggerDictionaryInitialization_libParticlePair_Impl();
}
