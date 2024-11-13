// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__ParticlePair3D
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
#include "ParticlePair3DHistos.hpp"
#include "ParticlePair3DDerivedHistos.hpp"
#include "ParticlePair3DAnalyzer.hpp"
#include "ParticlePair3DCalculator.hpp"
#include "ParticlePair3DBfCalculator.hpp"
#include "ParticlePair3DBfHistos.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLParticlePair3DHistos(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePair3DHistos(Long_t size, void *p);
   static void delete_CAPcLcLParticlePair3DHistos(void *p);
   static void deleteArray_CAPcLcLParticlePair3DHistos(void *p);
   static void destruct_CAPcLcLParticlePair3DHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePair3DHistos*)
   {
      ::CAP::ParticlePair3DHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePair3DHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePair3DHistos", ::CAP::ParticlePair3DHistos::Class_Version(), "ParticlePair3DHistos.hpp", 22,
                  typeid(::CAP::ParticlePair3DHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePair3DHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePair3DHistos) );
      instance.SetNew(&new_CAPcLcLParticlePair3DHistos);
      instance.SetNewArray(&newArray_CAPcLcLParticlePair3DHistos);
      instance.SetDelete(&delete_CAPcLcLParticlePair3DHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePair3DHistos);
      instance.SetDestructor(&destruct_CAPcLcLParticlePair3DHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePair3DHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePair3DHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePair3DHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticlePair3DDerivedHistos(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePair3DDerivedHistos(Long_t size, void *p);
   static void delete_CAPcLcLParticlePair3DDerivedHistos(void *p);
   static void deleteArray_CAPcLcLParticlePair3DDerivedHistos(void *p);
   static void destruct_CAPcLcLParticlePair3DDerivedHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePair3DDerivedHistos*)
   {
      ::CAP::ParticlePair3DDerivedHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePair3DDerivedHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePair3DDerivedHistos", ::CAP::ParticlePair3DDerivedHistos::Class_Version(), "ParticlePair3DDerivedHistos.hpp", 27,
                  typeid(::CAP::ParticlePair3DDerivedHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePair3DDerivedHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePair3DDerivedHistos) );
      instance.SetNew(&new_CAPcLcLParticlePair3DDerivedHistos);
      instance.SetNewArray(&newArray_CAPcLcLParticlePair3DDerivedHistos);
      instance.SetDelete(&delete_CAPcLcLParticlePair3DDerivedHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePair3DDerivedHistos);
      instance.SetDestructor(&destruct_CAPcLcLParticlePair3DDerivedHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePair3DDerivedHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePair3DDerivedHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePair3DDerivedHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticlePair3DAnalyzer(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePair3DAnalyzer(Long_t size, void *p);
   static void delete_CAPcLcLParticlePair3DAnalyzer(void *p);
   static void deleteArray_CAPcLcLParticlePair3DAnalyzer(void *p);
   static void destruct_CAPcLcLParticlePair3DAnalyzer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePair3DAnalyzer*)
   {
      ::CAP::ParticlePair3DAnalyzer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePair3DAnalyzer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePair3DAnalyzer", ::CAP::ParticlePair3DAnalyzer::Class_Version(), "ParticlePair3DAnalyzer.hpp", 20,
                  typeid(::CAP::ParticlePair3DAnalyzer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePair3DAnalyzer::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePair3DAnalyzer) );
      instance.SetNew(&new_CAPcLcLParticlePair3DAnalyzer);
      instance.SetNewArray(&newArray_CAPcLcLParticlePair3DAnalyzer);
      instance.SetDelete(&delete_CAPcLcLParticlePair3DAnalyzer);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePair3DAnalyzer);
      instance.SetDestructor(&destruct_CAPcLcLParticlePair3DAnalyzer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePair3DAnalyzer*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePair3DAnalyzer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePair3DAnalyzer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticlePair3DCalculator(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePair3DCalculator(Long_t size, void *p);
   static void delete_CAPcLcLParticlePair3DCalculator(void *p);
   static void deleteArray_CAPcLcLParticlePair3DCalculator(void *p);
   static void destruct_CAPcLcLParticlePair3DCalculator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePair3DCalculator*)
   {
      ::CAP::ParticlePair3DCalculator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePair3DCalculator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePair3DCalculator", ::CAP::ParticlePair3DCalculator::Class_Version(), "ParticlePair3DCalculator.hpp", 20,
                  typeid(::CAP::ParticlePair3DCalculator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePair3DCalculator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePair3DCalculator) );
      instance.SetNew(&new_CAPcLcLParticlePair3DCalculator);
      instance.SetNewArray(&newArray_CAPcLcLParticlePair3DCalculator);
      instance.SetDelete(&delete_CAPcLcLParticlePair3DCalculator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePair3DCalculator);
      instance.SetDestructor(&destruct_CAPcLcLParticlePair3DCalculator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePair3DCalculator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePair3DCalculator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePair3DCalculator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticlePair3DBfCalculator(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePair3DBfCalculator(Long_t size, void *p);
   static void delete_CAPcLcLParticlePair3DBfCalculator(void *p);
   static void deleteArray_CAPcLcLParticlePair3DBfCalculator(void *p);
   static void destruct_CAPcLcLParticlePair3DBfCalculator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePair3DBfCalculator*)
   {
      ::CAP::ParticlePair3DBfCalculator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePair3DBfCalculator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePair3DBfCalculator", ::CAP::ParticlePair3DBfCalculator::Class_Version(), "ParticlePair3DBfCalculator.hpp", 19,
                  typeid(::CAP::ParticlePair3DBfCalculator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePair3DBfCalculator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePair3DBfCalculator) );
      instance.SetNew(&new_CAPcLcLParticlePair3DBfCalculator);
      instance.SetNewArray(&newArray_CAPcLcLParticlePair3DBfCalculator);
      instance.SetDelete(&delete_CAPcLcLParticlePair3DBfCalculator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePair3DBfCalculator);
      instance.SetDestructor(&destruct_CAPcLcLParticlePair3DBfCalculator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePair3DBfCalculator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePair3DBfCalculator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePair3DBfCalculator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticlePair3DBfHistos(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePair3DBfHistos(Long_t size, void *p);
   static void delete_CAPcLcLParticlePair3DBfHistos(void *p);
   static void deleteArray_CAPcLcLParticlePair3DBfHistos(void *p);
   static void destruct_CAPcLcLParticlePair3DBfHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePair3DBfHistos*)
   {
      ::CAP::ParticlePair3DBfHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePair3DBfHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePair3DBfHistos", ::CAP::ParticlePair3DBfHistos::Class_Version(), "ParticlePair3DBfHistos.hpp", 28,
                  typeid(::CAP::ParticlePair3DBfHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePair3DBfHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePair3DBfHistos) );
      instance.SetNew(&new_CAPcLcLParticlePair3DBfHistos);
      instance.SetNewArray(&newArray_CAPcLcLParticlePair3DBfHistos);
      instance.SetDelete(&delete_CAPcLcLParticlePair3DBfHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePair3DBfHistos);
      instance.SetDestructor(&destruct_CAPcLcLParticlePair3DBfHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePair3DBfHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePair3DBfHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePair3DBfHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePair3DHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePair3DHistos::Class_Name()
{
   return "CAP::ParticlePair3DHistos";
}

//______________________________________________________________________________
const char *ParticlePair3DHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePair3DHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePair3DHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePair3DHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePair3DDerivedHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePair3DDerivedHistos::Class_Name()
{
   return "CAP::ParticlePair3DDerivedHistos";
}

//______________________________________________________________________________
const char *ParticlePair3DDerivedHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DDerivedHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePair3DDerivedHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DDerivedHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePair3DDerivedHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DDerivedHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePair3DDerivedHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DDerivedHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePair3DAnalyzer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePair3DAnalyzer::Class_Name()
{
   return "CAP::ParticlePair3DAnalyzer";
}

//______________________________________________________________________________
const char *ParticlePair3DAnalyzer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DAnalyzer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePair3DAnalyzer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DAnalyzer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePair3DAnalyzer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DAnalyzer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePair3DAnalyzer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DAnalyzer*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePair3DCalculator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePair3DCalculator::Class_Name()
{
   return "CAP::ParticlePair3DCalculator";
}

//______________________________________________________________________________
const char *ParticlePair3DCalculator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DCalculator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePair3DCalculator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DCalculator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePair3DCalculator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DCalculator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePair3DCalculator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DCalculator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePair3DBfCalculator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePair3DBfCalculator::Class_Name()
{
   return "CAP::ParticlePair3DBfCalculator";
}

//______________________________________________________________________________
const char *ParticlePair3DBfCalculator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DBfCalculator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePair3DBfCalculator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DBfCalculator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePair3DBfCalculator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DBfCalculator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePair3DBfCalculator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DBfCalculator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePair3DBfHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePair3DBfHistos::Class_Name()
{
   return "CAP::ParticlePair3DBfHistos";
}

//______________________________________________________________________________
const char *ParticlePair3DBfHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DBfHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePair3DBfHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DBfHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePair3DBfHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DBfHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePair3DBfHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePair3DBfHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void ParticlePair3DHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePair3DHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePair3DHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePair3DHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePair3DHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePair3DHistos : new ::CAP::ParticlePair3DHistos;
   }
   static void *newArray_CAPcLcLParticlePair3DHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePair3DHistos[nElements] : new ::CAP::ParticlePair3DHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePair3DHistos(void *p) {
      delete (static_cast<::CAP::ParticlePair3DHistos*>(p));
   }
   static void deleteArray_CAPcLcLParticlePair3DHistos(void *p) {
      delete [] (static_cast<::CAP::ParticlePair3DHistos*>(p));
   }
   static void destruct_CAPcLcLParticlePair3DHistos(void *p) {
      typedef ::CAP::ParticlePair3DHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePair3DHistos

namespace CAP {
//______________________________________________________________________________
void ParticlePair3DDerivedHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePair3DDerivedHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePair3DDerivedHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePair3DDerivedHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePair3DDerivedHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePair3DDerivedHistos : new ::CAP::ParticlePair3DDerivedHistos;
   }
   static void *newArray_CAPcLcLParticlePair3DDerivedHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePair3DDerivedHistos[nElements] : new ::CAP::ParticlePair3DDerivedHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePair3DDerivedHistos(void *p) {
      delete (static_cast<::CAP::ParticlePair3DDerivedHistos*>(p));
   }
   static void deleteArray_CAPcLcLParticlePair3DDerivedHistos(void *p) {
      delete [] (static_cast<::CAP::ParticlePair3DDerivedHistos*>(p));
   }
   static void destruct_CAPcLcLParticlePair3DDerivedHistos(void *p) {
      typedef ::CAP::ParticlePair3DDerivedHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePair3DDerivedHistos

namespace CAP {
//______________________________________________________________________________
void ParticlePair3DAnalyzer::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePair3DAnalyzer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePair3DAnalyzer::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePair3DAnalyzer::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePair3DAnalyzer(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePair3DAnalyzer : new ::CAP::ParticlePair3DAnalyzer;
   }
   static void *newArray_CAPcLcLParticlePair3DAnalyzer(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePair3DAnalyzer[nElements] : new ::CAP::ParticlePair3DAnalyzer[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePair3DAnalyzer(void *p) {
      delete (static_cast<::CAP::ParticlePair3DAnalyzer*>(p));
   }
   static void deleteArray_CAPcLcLParticlePair3DAnalyzer(void *p) {
      delete [] (static_cast<::CAP::ParticlePair3DAnalyzer*>(p));
   }
   static void destruct_CAPcLcLParticlePair3DAnalyzer(void *p) {
      typedef ::CAP::ParticlePair3DAnalyzer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePair3DAnalyzer

namespace CAP {
//______________________________________________________________________________
void ParticlePair3DCalculator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePair3DCalculator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePair3DCalculator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePair3DCalculator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePair3DCalculator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePair3DCalculator : new ::CAP::ParticlePair3DCalculator;
   }
   static void *newArray_CAPcLcLParticlePair3DCalculator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePair3DCalculator[nElements] : new ::CAP::ParticlePair3DCalculator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePair3DCalculator(void *p) {
      delete (static_cast<::CAP::ParticlePair3DCalculator*>(p));
   }
   static void deleteArray_CAPcLcLParticlePair3DCalculator(void *p) {
      delete [] (static_cast<::CAP::ParticlePair3DCalculator*>(p));
   }
   static void destruct_CAPcLcLParticlePair3DCalculator(void *p) {
      typedef ::CAP::ParticlePair3DCalculator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePair3DCalculator

namespace CAP {
//______________________________________________________________________________
void ParticlePair3DBfCalculator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePair3DBfCalculator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePair3DBfCalculator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePair3DBfCalculator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePair3DBfCalculator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePair3DBfCalculator : new ::CAP::ParticlePair3DBfCalculator;
   }
   static void *newArray_CAPcLcLParticlePair3DBfCalculator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePair3DBfCalculator[nElements] : new ::CAP::ParticlePair3DBfCalculator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePair3DBfCalculator(void *p) {
      delete (static_cast<::CAP::ParticlePair3DBfCalculator*>(p));
   }
   static void deleteArray_CAPcLcLParticlePair3DBfCalculator(void *p) {
      delete [] (static_cast<::CAP::ParticlePair3DBfCalculator*>(p));
   }
   static void destruct_CAPcLcLParticlePair3DBfCalculator(void *p) {
      typedef ::CAP::ParticlePair3DBfCalculator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePair3DBfCalculator

namespace CAP {
//______________________________________________________________________________
void ParticlePair3DBfHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePair3DBfHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePair3DBfHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePair3DBfHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePair3DBfHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePair3DBfHistos : new ::CAP::ParticlePair3DBfHistos;
   }
   static void *newArray_CAPcLcLParticlePair3DBfHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePair3DBfHistos[nElements] : new ::CAP::ParticlePair3DBfHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePair3DBfHistos(void *p) {
      delete (static_cast<::CAP::ParticlePair3DBfHistos*>(p));
   }
   static void deleteArray_CAPcLcLParticlePair3DBfHistos(void *p) {
      delete [] (static_cast<::CAP::ParticlePair3DBfHistos*>(p));
   }
   static void destruct_CAPcLcLParticlePair3DBfHistos(void *p) {
      typedef ::CAP::ParticlePair3DBfHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePair3DBfHistos

namespace {
  void TriggerDictionaryInitialization_libParticlePair3D_Impl() {
    static const char* headers[] = {
"ParticlePair3DHistos.hpp",
"ParticlePair3DDerivedHistos.hpp",
"ParticlePair3DAnalyzer.hpp",
"ParticlePair3DCalculator.hpp",
"ParticlePair3DBfCalculator.hpp",
"ParticlePair3DBfHistos.hpp",
nullptr
    };
    static const char* includePaths[] = {
"/usr/local/Cellar/root/6.32.06/include/root",
"/Users/aa7526/Documents/GitHub/CAP6.1/src",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/Base",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/Math",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/Xml",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/ParticleDb",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/Particles",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/SubSample",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/CAPPythia",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/Global",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/Jets",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/Spherocity",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/ParticleSingle",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/ParticlePair",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/ParticlePair3D",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/NuDyn",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/PtPt",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/Plotting",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/Therminator",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/Performance",
"/Users/aa7526/Documents/GitHub/CAP6.1/src/Exec",
"/include",
"/Users/aa7526/opt/fastjet-3.4.3/include",
"/Users/aa7526/opt/Pythia/pythia8307/include",
"/Users/aa7526/opt/Pythia/pythia8307/include/Pythia8",
"/usr/local/Cellar/root/6.32.06/include/root",
"/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/ParticlePair3D/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libParticlePair3D dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePair3DHistos.hpp")))  ParticlePair3DHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePair3DDerivedHistos.hpp")))  ParticlePair3DDerivedHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePair3DAnalyzer.hpp")))  ParticlePair3DAnalyzer;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePair3DCalculator.hpp")))  ParticlePair3DCalculator;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePair3DBfCalculator.hpp")))  ParticlePair3DBfCalculator;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePair3DBfHistos.hpp")))  ParticlePair3DBfHistos;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libParticlePair3D dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "ParticlePair3DHistos.hpp"
#include "ParticlePair3DDerivedHistos.hpp"
#include "ParticlePair3DAnalyzer.hpp"
#include "ParticlePair3DCalculator.hpp"
#include "ParticlePair3DBfCalculator.hpp"
#include "ParticlePair3DBfHistos.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::ParticlePair3DAnalyzer", payloadCode, "@",
"CAP::ParticlePair3DBfCalculator", payloadCode, "@",
"CAP::ParticlePair3DBfHistos", payloadCode, "@",
"CAP::ParticlePair3DCalculator", payloadCode, "@",
"CAP::ParticlePair3DDerivedHistos", payloadCode, "@",
"CAP::ParticlePair3DHistos", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libParticlePair3D",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libParticlePair3D_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libParticlePair3D_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libParticlePair3D() {
  TriggerDictionaryInitialization_libParticlePair3D_Impl();
}
