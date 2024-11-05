// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__NuDyn
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
#include "NuDynHistos.hpp"
#include "NuDynDerivedHistos.hpp"
#include "NuDynAnalyzer.hpp"
#include "NuDynCalculator.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLNuDynHistos(void *p = nullptr);
   static void *newArray_CAPcLcLNuDynHistos(Long_t size, void *p);
   static void delete_CAPcLcLNuDynHistos(void *p);
   static void deleteArray_CAPcLcLNuDynHistos(void *p);
   static void destruct_CAPcLcLNuDynHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::NuDynHistos*)
   {
      ::CAP::NuDynHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::NuDynHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::NuDynHistos", ::CAP::NuDynHistos::Class_Version(), "NuDynHistos.hpp", 56,
                  typeid(::CAP::NuDynHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::NuDynHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::NuDynHistos) );
      instance.SetNew(&new_CAPcLcLNuDynHistos);
      instance.SetNewArray(&newArray_CAPcLcLNuDynHistos);
      instance.SetDelete(&delete_CAPcLcLNuDynHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLNuDynHistos);
      instance.SetDestructor(&destruct_CAPcLcLNuDynHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::NuDynHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::NuDynHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::NuDynHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLNuDynDerivedHistos(void *p = nullptr);
   static void *newArray_CAPcLcLNuDynDerivedHistos(Long_t size, void *p);
   static void delete_CAPcLcLNuDynDerivedHistos(void *p);
   static void deleteArray_CAPcLcLNuDynDerivedHistos(void *p);
   static void destruct_CAPcLcLNuDynDerivedHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::NuDynDerivedHistos*)
   {
      ::CAP::NuDynDerivedHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::NuDynDerivedHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::NuDynDerivedHistos", ::CAP::NuDynDerivedHistos::Class_Version(), "NuDynDerivedHistos.hpp", 21,
                  typeid(::CAP::NuDynDerivedHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::NuDynDerivedHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::NuDynDerivedHistos) );
      instance.SetNew(&new_CAPcLcLNuDynDerivedHistos);
      instance.SetNewArray(&newArray_CAPcLcLNuDynDerivedHistos);
      instance.SetDelete(&delete_CAPcLcLNuDynDerivedHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLNuDynDerivedHistos);
      instance.SetDestructor(&destruct_CAPcLcLNuDynDerivedHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::NuDynDerivedHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::NuDynDerivedHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::NuDynDerivedHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLNuDynAnalyzer(void *p = nullptr);
   static void *newArray_CAPcLcLNuDynAnalyzer(Long_t size, void *p);
   static void delete_CAPcLcLNuDynAnalyzer(void *p);
   static void deleteArray_CAPcLcLNuDynAnalyzer(void *p);
   static void destruct_CAPcLcLNuDynAnalyzer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::NuDynAnalyzer*)
   {
      ::CAP::NuDynAnalyzer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::NuDynAnalyzer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::NuDynAnalyzer", ::CAP::NuDynAnalyzer::Class_Version(), "NuDynAnalyzer.hpp", 29,
                  typeid(::CAP::NuDynAnalyzer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::NuDynAnalyzer::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::NuDynAnalyzer) );
      instance.SetNew(&new_CAPcLcLNuDynAnalyzer);
      instance.SetNewArray(&newArray_CAPcLcLNuDynAnalyzer);
      instance.SetDelete(&delete_CAPcLcLNuDynAnalyzer);
      instance.SetDeleteArray(&deleteArray_CAPcLcLNuDynAnalyzer);
      instance.SetDestructor(&destruct_CAPcLcLNuDynAnalyzer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::NuDynAnalyzer*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::NuDynAnalyzer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::NuDynAnalyzer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLNuDynCalculator(void *p = nullptr);
   static void *newArray_CAPcLcLNuDynCalculator(Long_t size, void *p);
   static void delete_CAPcLcLNuDynCalculator(void *p);
   static void deleteArray_CAPcLcLNuDynCalculator(void *p);
   static void destruct_CAPcLcLNuDynCalculator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::NuDynCalculator*)
   {
      ::CAP::NuDynCalculator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::NuDynCalculator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::NuDynCalculator", ::CAP::NuDynCalculator::Class_Version(), "NuDynCalculator.hpp", 18,
                  typeid(::CAP::NuDynCalculator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::NuDynCalculator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::NuDynCalculator) );
      instance.SetNew(&new_CAPcLcLNuDynCalculator);
      instance.SetNewArray(&newArray_CAPcLcLNuDynCalculator);
      instance.SetDelete(&delete_CAPcLcLNuDynCalculator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLNuDynCalculator);
      instance.SetDestructor(&destruct_CAPcLcLNuDynCalculator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::NuDynCalculator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::NuDynCalculator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::NuDynCalculator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr NuDynHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *NuDynHistos::Class_Name()
{
   return "CAP::NuDynHistos";
}

//______________________________________________________________________________
const char *NuDynHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int NuDynHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *NuDynHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *NuDynHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr NuDynDerivedHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *NuDynDerivedHistos::Class_Name()
{
   return "CAP::NuDynDerivedHistos";
}

//______________________________________________________________________________
const char *NuDynDerivedHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynDerivedHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int NuDynDerivedHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynDerivedHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *NuDynDerivedHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynDerivedHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *NuDynDerivedHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynDerivedHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr NuDynAnalyzer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *NuDynAnalyzer::Class_Name()
{
   return "CAP::NuDynAnalyzer";
}

//______________________________________________________________________________
const char *NuDynAnalyzer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynAnalyzer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int NuDynAnalyzer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynAnalyzer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *NuDynAnalyzer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynAnalyzer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *NuDynAnalyzer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynAnalyzer*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr NuDynCalculator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *NuDynCalculator::Class_Name()
{
   return "CAP::NuDynCalculator";
}

//______________________________________________________________________________
const char *NuDynCalculator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynCalculator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int NuDynCalculator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynCalculator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *NuDynCalculator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynCalculator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *NuDynCalculator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::NuDynCalculator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void NuDynHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::NuDynHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::NuDynHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::NuDynHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLNuDynHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::NuDynHistos : new ::CAP::NuDynHistos;
   }
   static void *newArray_CAPcLcLNuDynHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::NuDynHistos[nElements] : new ::CAP::NuDynHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLNuDynHistos(void *p) {
      delete (static_cast<::CAP::NuDynHistos*>(p));
   }
   static void deleteArray_CAPcLcLNuDynHistos(void *p) {
      delete [] (static_cast<::CAP::NuDynHistos*>(p));
   }
   static void destruct_CAPcLcLNuDynHistos(void *p) {
      typedef ::CAP::NuDynHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::NuDynHistos

namespace CAP {
//______________________________________________________________________________
void NuDynDerivedHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::NuDynDerivedHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::NuDynDerivedHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::NuDynDerivedHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLNuDynDerivedHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::NuDynDerivedHistos : new ::CAP::NuDynDerivedHistos;
   }
   static void *newArray_CAPcLcLNuDynDerivedHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::NuDynDerivedHistos[nElements] : new ::CAP::NuDynDerivedHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLNuDynDerivedHistos(void *p) {
      delete (static_cast<::CAP::NuDynDerivedHistos*>(p));
   }
   static void deleteArray_CAPcLcLNuDynDerivedHistos(void *p) {
      delete [] (static_cast<::CAP::NuDynDerivedHistos*>(p));
   }
   static void destruct_CAPcLcLNuDynDerivedHistos(void *p) {
      typedef ::CAP::NuDynDerivedHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::NuDynDerivedHistos

namespace CAP {
//______________________________________________________________________________
void NuDynAnalyzer::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::NuDynAnalyzer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::NuDynAnalyzer::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::NuDynAnalyzer::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLNuDynAnalyzer(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::NuDynAnalyzer : new ::CAP::NuDynAnalyzer;
   }
   static void *newArray_CAPcLcLNuDynAnalyzer(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::NuDynAnalyzer[nElements] : new ::CAP::NuDynAnalyzer[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLNuDynAnalyzer(void *p) {
      delete (static_cast<::CAP::NuDynAnalyzer*>(p));
   }
   static void deleteArray_CAPcLcLNuDynAnalyzer(void *p) {
      delete [] (static_cast<::CAP::NuDynAnalyzer*>(p));
   }
   static void destruct_CAPcLcLNuDynAnalyzer(void *p) {
      typedef ::CAP::NuDynAnalyzer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::NuDynAnalyzer

namespace CAP {
//______________________________________________________________________________
void NuDynCalculator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::NuDynCalculator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::NuDynCalculator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::NuDynCalculator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLNuDynCalculator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::NuDynCalculator : new ::CAP::NuDynCalculator;
   }
   static void *newArray_CAPcLcLNuDynCalculator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::NuDynCalculator[nElements] : new ::CAP::NuDynCalculator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLNuDynCalculator(void *p) {
      delete (static_cast<::CAP::NuDynCalculator*>(p));
   }
   static void deleteArray_CAPcLcLNuDynCalculator(void *p) {
      delete [] (static_cast<::CAP::NuDynCalculator*>(p));
   }
   static void destruct_CAPcLcLNuDynCalculator(void *p) {
      typedef ::CAP::NuDynCalculator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::NuDynCalculator

namespace {
  void TriggerDictionaryInitialization_libNuDyn_Impl() {
    static const char* headers[] = {
"NuDynHistos.hpp",
"NuDynDerivedHistos.hpp",
"NuDynAnalyzer.hpp",
"NuDynCalculator.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/NuDyn/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libNuDyn dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$NuDynHistos.hpp")))  NuDynHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$NuDynDerivedHistos.hpp")))  NuDynDerivedHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$NuDynAnalyzer.hpp")))  NuDynAnalyzer;}
namespace CAP{class __attribute__((annotate("$clingAutoload$NuDynCalculator.hpp")))  NuDynCalculator;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libNuDyn dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "NuDynHistos.hpp"
#include "NuDynDerivedHistos.hpp"
#include "NuDynAnalyzer.hpp"
#include "NuDynCalculator.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::NuDynAnalyzer", payloadCode, "@",
"CAP::NuDynCalculator", payloadCode, "@",
"CAP::NuDynDerivedHistos", payloadCode, "@",
"CAP::NuDynHistos", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libNuDyn",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libNuDyn_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libNuDyn_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libNuDyn() {
  TriggerDictionaryInitialization_libNuDyn_Impl();
}
