// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__ParticleSingle
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
#include "ParticleSingleHistos.hpp"
#include "ParticleSingleDerivedHistos.hpp"
#include "ParticleSingleAnalyzer.hpp"
#include "ParticleSingleCalculator.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLParticleSingleHistos(void *p = nullptr);
   static void *newArray_CAPcLcLParticleSingleHistos(Long_t size, void *p);
   static void delete_CAPcLcLParticleSingleHistos(void *p);
   static void deleteArray_CAPcLcLParticleSingleHistos(void *p);
   static void destruct_CAPcLcLParticleSingleHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleSingleHistos*)
   {
      ::CAP::ParticleSingleHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleSingleHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleSingleHistos", ::CAP::ParticleSingleHistos::Class_Version(), "ParticleSingleHistos.hpp", 24,
                  typeid(::CAP::ParticleSingleHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleSingleHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleSingleHistos) );
      instance.SetNew(&new_CAPcLcLParticleSingleHistos);
      instance.SetNewArray(&newArray_CAPcLcLParticleSingleHistos);
      instance.SetDelete(&delete_CAPcLcLParticleSingleHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleSingleHistos);
      instance.SetDestructor(&destruct_CAPcLcLParticleSingleHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleSingleHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleSingleHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleSingleHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticleSingleDerivedHistos(void *p = nullptr);
   static void *newArray_CAPcLcLParticleSingleDerivedHistos(Long_t size, void *p);
   static void delete_CAPcLcLParticleSingleDerivedHistos(void *p);
   static void deleteArray_CAPcLcLParticleSingleDerivedHistos(void *p);
   static void destruct_CAPcLcLParticleSingleDerivedHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleSingleDerivedHistos*)
   {
      ::CAP::ParticleSingleDerivedHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleSingleDerivedHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleSingleDerivedHistos", ::CAP::ParticleSingleDerivedHistos::Class_Version(), "ParticleSingleDerivedHistos.hpp", 19,
                  typeid(::CAP::ParticleSingleDerivedHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleSingleDerivedHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleSingleDerivedHistos) );
      instance.SetNew(&new_CAPcLcLParticleSingleDerivedHistos);
      instance.SetNewArray(&newArray_CAPcLcLParticleSingleDerivedHistos);
      instance.SetDelete(&delete_CAPcLcLParticleSingleDerivedHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleSingleDerivedHistos);
      instance.SetDestructor(&destruct_CAPcLcLParticleSingleDerivedHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleSingleDerivedHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleSingleDerivedHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleSingleDerivedHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticleSingleAnalyzer(void *p = nullptr);
   static void *newArray_CAPcLcLParticleSingleAnalyzer(Long_t size, void *p);
   static void delete_CAPcLcLParticleSingleAnalyzer(void *p);
   static void deleteArray_CAPcLcLParticleSingleAnalyzer(void *p);
   static void destruct_CAPcLcLParticleSingleAnalyzer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleSingleAnalyzer*)
   {
      ::CAP::ParticleSingleAnalyzer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleSingleAnalyzer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleSingleAnalyzer", ::CAP::ParticleSingleAnalyzer::Class_Version(), "ParticleSingleAnalyzer.hpp", 59,
                  typeid(::CAP::ParticleSingleAnalyzer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleSingleAnalyzer::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleSingleAnalyzer) );
      instance.SetNew(&new_CAPcLcLParticleSingleAnalyzer);
      instance.SetNewArray(&newArray_CAPcLcLParticleSingleAnalyzer);
      instance.SetDelete(&delete_CAPcLcLParticleSingleAnalyzer);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleSingleAnalyzer);
      instance.SetDestructor(&destruct_CAPcLcLParticleSingleAnalyzer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleSingleAnalyzer*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleSingleAnalyzer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleSingleAnalyzer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticleSingleCalculator(void *p = nullptr);
   static void *newArray_CAPcLcLParticleSingleCalculator(Long_t size, void *p);
   static void delete_CAPcLcLParticleSingleCalculator(void *p);
   static void deleteArray_CAPcLcLParticleSingleCalculator(void *p);
   static void destruct_CAPcLcLParticleSingleCalculator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleSingleCalculator*)
   {
      ::CAP::ParticleSingleCalculator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleSingleCalculator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleSingleCalculator", ::CAP::ParticleSingleCalculator::Class_Version(), "ParticleSingleCalculator.hpp", 58,
                  typeid(::CAP::ParticleSingleCalculator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleSingleCalculator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleSingleCalculator) );
      instance.SetNew(&new_CAPcLcLParticleSingleCalculator);
      instance.SetNewArray(&newArray_CAPcLcLParticleSingleCalculator);
      instance.SetDelete(&delete_CAPcLcLParticleSingleCalculator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleSingleCalculator);
      instance.SetDestructor(&destruct_CAPcLcLParticleSingleCalculator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleSingleCalculator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleSingleCalculator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleSingleCalculator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleSingleHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleSingleHistos::Class_Name()
{
   return "CAP::ParticleSingleHistos";
}

//______________________________________________________________________________
const char *ParticleSingleHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleSingleHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleSingleHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleSingleHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleSingleDerivedHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleSingleDerivedHistos::Class_Name()
{
   return "CAP::ParticleSingleDerivedHistos";
}

//______________________________________________________________________________
const char *ParticleSingleDerivedHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleDerivedHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleSingleDerivedHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleDerivedHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleSingleDerivedHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleDerivedHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleSingleDerivedHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleDerivedHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleSingleAnalyzer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleSingleAnalyzer::Class_Name()
{
   return "CAP::ParticleSingleAnalyzer";
}

//______________________________________________________________________________
const char *ParticleSingleAnalyzer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleAnalyzer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleSingleAnalyzer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleAnalyzer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleSingleAnalyzer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleAnalyzer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleSingleAnalyzer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleAnalyzer*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleSingleCalculator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleSingleCalculator::Class_Name()
{
   return "CAP::ParticleSingleCalculator";
}

//______________________________________________________________________________
const char *ParticleSingleCalculator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleCalculator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleSingleCalculator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleCalculator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleSingleCalculator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleCalculator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleSingleCalculator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSingleCalculator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void ParticleSingleHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleSingleHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleSingleHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleSingleHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleSingleHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleSingleHistos : new ::CAP::ParticleSingleHistos;
   }
   static void *newArray_CAPcLcLParticleSingleHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleSingleHistos[nElements] : new ::CAP::ParticleSingleHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleSingleHistos(void *p) {
      delete (static_cast<::CAP::ParticleSingleHistos*>(p));
   }
   static void deleteArray_CAPcLcLParticleSingleHistos(void *p) {
      delete [] (static_cast<::CAP::ParticleSingleHistos*>(p));
   }
   static void destruct_CAPcLcLParticleSingleHistos(void *p) {
      typedef ::CAP::ParticleSingleHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleSingleHistos

namespace CAP {
//______________________________________________________________________________
void ParticleSingleDerivedHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleSingleDerivedHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleSingleDerivedHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleSingleDerivedHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleSingleDerivedHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleSingleDerivedHistos : new ::CAP::ParticleSingleDerivedHistos;
   }
   static void *newArray_CAPcLcLParticleSingleDerivedHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleSingleDerivedHistos[nElements] : new ::CAP::ParticleSingleDerivedHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleSingleDerivedHistos(void *p) {
      delete (static_cast<::CAP::ParticleSingleDerivedHistos*>(p));
   }
   static void deleteArray_CAPcLcLParticleSingleDerivedHistos(void *p) {
      delete [] (static_cast<::CAP::ParticleSingleDerivedHistos*>(p));
   }
   static void destruct_CAPcLcLParticleSingleDerivedHistos(void *p) {
      typedef ::CAP::ParticleSingleDerivedHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleSingleDerivedHistos

namespace CAP {
//______________________________________________________________________________
void ParticleSingleAnalyzer::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleSingleAnalyzer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleSingleAnalyzer::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleSingleAnalyzer::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleSingleAnalyzer(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleSingleAnalyzer : new ::CAP::ParticleSingleAnalyzer;
   }
   static void *newArray_CAPcLcLParticleSingleAnalyzer(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleSingleAnalyzer[nElements] : new ::CAP::ParticleSingleAnalyzer[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleSingleAnalyzer(void *p) {
      delete (static_cast<::CAP::ParticleSingleAnalyzer*>(p));
   }
   static void deleteArray_CAPcLcLParticleSingleAnalyzer(void *p) {
      delete [] (static_cast<::CAP::ParticleSingleAnalyzer*>(p));
   }
   static void destruct_CAPcLcLParticleSingleAnalyzer(void *p) {
      typedef ::CAP::ParticleSingleAnalyzer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleSingleAnalyzer

namespace CAP {
//______________________________________________________________________________
void ParticleSingleCalculator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleSingleCalculator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleSingleCalculator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleSingleCalculator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleSingleCalculator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleSingleCalculator : new ::CAP::ParticleSingleCalculator;
   }
   static void *newArray_CAPcLcLParticleSingleCalculator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleSingleCalculator[nElements] : new ::CAP::ParticleSingleCalculator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleSingleCalculator(void *p) {
      delete (static_cast<::CAP::ParticleSingleCalculator*>(p));
   }
   static void deleteArray_CAPcLcLParticleSingleCalculator(void *p) {
      delete [] (static_cast<::CAP::ParticleSingleCalculator*>(p));
   }
   static void destruct_CAPcLcLParticleSingleCalculator(void *p) {
      typedef ::CAP::ParticleSingleCalculator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleSingleCalculator

namespace {
  void TriggerDictionaryInitialization_libParticleSingle_Impl() {
    static const char* headers[] = {
"ParticleSingleHistos.hpp",
"ParticleSingleDerivedHistos.hpp",
"ParticleSingleAnalyzer.hpp",
"ParticleSingleCalculator.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP6.0/laptop/ParticleSingle/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libParticleSingle dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleSingleHistos.hpp")))  ParticleSingleHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleSingleDerivedHistos.hpp")))  ParticleSingleDerivedHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleSingleAnalyzer.hpp")))  ParticleSingleAnalyzer;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleSingleCalculator.hpp")))  ParticleSingleCalculator;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libParticleSingle dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "ParticleSingleHistos.hpp"
#include "ParticleSingleDerivedHistos.hpp"
#include "ParticleSingleAnalyzer.hpp"
#include "ParticleSingleCalculator.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::ParticleSingleAnalyzer", payloadCode, "@",
"CAP::ParticleSingleCalculator", payloadCode, "@",
"CAP::ParticleSingleDerivedHistos", payloadCode, "@",
"CAP::ParticleSingleHistos", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libParticleSingle",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libParticleSingle_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libParticleSingle_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libParticleSingle() {
  TriggerDictionaryInitialization_libParticleSingle_Impl();
}
