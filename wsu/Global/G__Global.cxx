// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Global
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
#include "GlobalHistos.hpp"
#include "GlobalDerivedHistos.hpp"
#include "GlobalAnalyzer.hpp"
#include "GlobalCalculator.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLGlobalHistos(void *p = nullptr);
   static void *newArray_CAPcLcLGlobalHistos(Long_t size, void *p);
   static void delete_CAPcLcLGlobalHistos(void *p);
   static void deleteArray_CAPcLcLGlobalHistos(void *p);
   static void destruct_CAPcLcLGlobalHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::GlobalHistos*)
   {
      ::CAP::GlobalHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::GlobalHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::GlobalHistos", ::CAP::GlobalHistos::Class_Version(), "GlobalHistos.hpp", 37,
                  typeid(::CAP::GlobalHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::GlobalHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::GlobalHistos) );
      instance.SetNew(&new_CAPcLcLGlobalHistos);
      instance.SetNewArray(&newArray_CAPcLcLGlobalHistos);
      instance.SetDelete(&delete_CAPcLcLGlobalHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLGlobalHistos);
      instance.SetDestructor(&destruct_CAPcLcLGlobalHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::GlobalHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::GlobalHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::GlobalHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLGlobalDerivedHistos(void *p = nullptr);
   static void *newArray_CAPcLcLGlobalDerivedHistos(Long_t size, void *p);
   static void delete_CAPcLcLGlobalDerivedHistos(void *p);
   static void deleteArray_CAPcLcLGlobalDerivedHistos(void *p);
   static void destruct_CAPcLcLGlobalDerivedHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::GlobalDerivedHistos*)
   {
      ::CAP::GlobalDerivedHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::GlobalDerivedHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::GlobalDerivedHistos", ::CAP::GlobalDerivedHistos::Class_Version(), "GlobalDerivedHistos.hpp", 21,
                  typeid(::CAP::GlobalDerivedHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::GlobalDerivedHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::GlobalDerivedHistos) );
      instance.SetNew(&new_CAPcLcLGlobalDerivedHistos);
      instance.SetNewArray(&newArray_CAPcLcLGlobalDerivedHistos);
      instance.SetDelete(&delete_CAPcLcLGlobalDerivedHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLGlobalDerivedHistos);
      instance.SetDestructor(&destruct_CAPcLcLGlobalDerivedHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::GlobalDerivedHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::GlobalDerivedHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::GlobalDerivedHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLGlobalAnalyzer(void *p = nullptr);
   static void *newArray_CAPcLcLGlobalAnalyzer(Long_t size, void *p);
   static void delete_CAPcLcLGlobalAnalyzer(void *p);
   static void deleteArray_CAPcLcLGlobalAnalyzer(void *p);
   static void destruct_CAPcLcLGlobalAnalyzer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::GlobalAnalyzer*)
   {
      ::CAP::GlobalAnalyzer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::GlobalAnalyzer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::GlobalAnalyzer", ::CAP::GlobalAnalyzer::Class_Version(), "GlobalAnalyzer.hpp", 31,
                  typeid(::CAP::GlobalAnalyzer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::GlobalAnalyzer::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::GlobalAnalyzer) );
      instance.SetNew(&new_CAPcLcLGlobalAnalyzer);
      instance.SetNewArray(&newArray_CAPcLcLGlobalAnalyzer);
      instance.SetDelete(&delete_CAPcLcLGlobalAnalyzer);
      instance.SetDeleteArray(&deleteArray_CAPcLcLGlobalAnalyzer);
      instance.SetDestructor(&destruct_CAPcLcLGlobalAnalyzer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::GlobalAnalyzer*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::GlobalAnalyzer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::GlobalAnalyzer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLGlobalCalculator(void *p = nullptr);
   static void *newArray_CAPcLcLGlobalCalculator(Long_t size, void *p);
   static void delete_CAPcLcLGlobalCalculator(void *p);
   static void deleteArray_CAPcLcLGlobalCalculator(void *p);
   static void destruct_CAPcLcLGlobalCalculator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::GlobalCalculator*)
   {
      ::CAP::GlobalCalculator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::GlobalCalculator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::GlobalCalculator", ::CAP::GlobalCalculator::Class_Version(), "GlobalCalculator.hpp", 31,
                  typeid(::CAP::GlobalCalculator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::GlobalCalculator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::GlobalCalculator) );
      instance.SetNew(&new_CAPcLcLGlobalCalculator);
      instance.SetNewArray(&newArray_CAPcLcLGlobalCalculator);
      instance.SetDelete(&delete_CAPcLcLGlobalCalculator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLGlobalCalculator);
      instance.SetDestructor(&destruct_CAPcLcLGlobalCalculator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::GlobalCalculator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::GlobalCalculator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::GlobalCalculator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr GlobalHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *GlobalHistos::Class_Name()
{
   return "CAP::GlobalHistos";
}

//______________________________________________________________________________
const char *GlobalHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int GlobalHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GlobalHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GlobalHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr GlobalDerivedHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *GlobalDerivedHistos::Class_Name()
{
   return "CAP::GlobalDerivedHistos";
}

//______________________________________________________________________________
const char *GlobalDerivedHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalDerivedHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int GlobalDerivedHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalDerivedHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GlobalDerivedHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalDerivedHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GlobalDerivedHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalDerivedHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr GlobalAnalyzer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *GlobalAnalyzer::Class_Name()
{
   return "CAP::GlobalAnalyzer";
}

//______________________________________________________________________________
const char *GlobalAnalyzer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalAnalyzer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int GlobalAnalyzer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalAnalyzer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GlobalAnalyzer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalAnalyzer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GlobalAnalyzer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalAnalyzer*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr GlobalCalculator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *GlobalCalculator::Class_Name()
{
   return "CAP::GlobalCalculator";
}

//______________________________________________________________________________
const char *GlobalCalculator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalCalculator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int GlobalCalculator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalCalculator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GlobalCalculator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalCalculator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GlobalCalculator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::GlobalCalculator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void GlobalHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::GlobalHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::GlobalHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::GlobalHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLGlobalHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::GlobalHistos : new ::CAP::GlobalHistos;
   }
   static void *newArray_CAPcLcLGlobalHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::GlobalHistos[nElements] : new ::CAP::GlobalHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLGlobalHistos(void *p) {
      delete (static_cast<::CAP::GlobalHistos*>(p));
   }
   static void deleteArray_CAPcLcLGlobalHistos(void *p) {
      delete [] (static_cast<::CAP::GlobalHistos*>(p));
   }
   static void destruct_CAPcLcLGlobalHistos(void *p) {
      typedef ::CAP::GlobalHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::GlobalHistos

namespace CAP {
//______________________________________________________________________________
void GlobalDerivedHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::GlobalDerivedHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::GlobalDerivedHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::GlobalDerivedHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLGlobalDerivedHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::GlobalDerivedHistos : new ::CAP::GlobalDerivedHistos;
   }
   static void *newArray_CAPcLcLGlobalDerivedHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::GlobalDerivedHistos[nElements] : new ::CAP::GlobalDerivedHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLGlobalDerivedHistos(void *p) {
      delete (static_cast<::CAP::GlobalDerivedHistos*>(p));
   }
   static void deleteArray_CAPcLcLGlobalDerivedHistos(void *p) {
      delete [] (static_cast<::CAP::GlobalDerivedHistos*>(p));
   }
   static void destruct_CAPcLcLGlobalDerivedHistos(void *p) {
      typedef ::CAP::GlobalDerivedHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::GlobalDerivedHistos

namespace CAP {
//______________________________________________________________________________
void GlobalAnalyzer::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::GlobalAnalyzer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::GlobalAnalyzer::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::GlobalAnalyzer::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLGlobalAnalyzer(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::GlobalAnalyzer : new ::CAP::GlobalAnalyzer;
   }
   static void *newArray_CAPcLcLGlobalAnalyzer(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::GlobalAnalyzer[nElements] : new ::CAP::GlobalAnalyzer[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLGlobalAnalyzer(void *p) {
      delete (static_cast<::CAP::GlobalAnalyzer*>(p));
   }
   static void deleteArray_CAPcLcLGlobalAnalyzer(void *p) {
      delete [] (static_cast<::CAP::GlobalAnalyzer*>(p));
   }
   static void destruct_CAPcLcLGlobalAnalyzer(void *p) {
      typedef ::CAP::GlobalAnalyzer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::GlobalAnalyzer

namespace CAP {
//______________________________________________________________________________
void GlobalCalculator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::GlobalCalculator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::GlobalCalculator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::GlobalCalculator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLGlobalCalculator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::GlobalCalculator : new ::CAP::GlobalCalculator;
   }
   static void *newArray_CAPcLcLGlobalCalculator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::GlobalCalculator[nElements] : new ::CAP::GlobalCalculator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLGlobalCalculator(void *p) {
      delete (static_cast<::CAP::GlobalCalculator*>(p));
   }
   static void deleteArray_CAPcLcLGlobalCalculator(void *p) {
      delete [] (static_cast<::CAP::GlobalCalculator*>(p));
   }
   static void destruct_CAPcLcLGlobalCalculator(void *p) {
      typedef ::CAP::GlobalCalculator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::GlobalCalculator

namespace {
  void TriggerDictionaryInitialization_libGlobal_Impl() {
    static const char* headers[] = {
"GlobalHistos.hpp",
"GlobalDerivedHistos.hpp",
"GlobalAnalyzer.hpp",
"GlobalCalculator.hpp",
nullptr
    };
    static const char* includePaths[] = {
"/opt/homebrew/Cellar/root/6.32.06/include/root",
"/Users/aa7526/Documents/GitHub/CAP7.0/src",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/Base",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/Math",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/Xml",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/ParticleDb",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/Particles",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/SubSample",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/CAPPythia",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/Global",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/Jets",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/Spherocity",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/ParticleSingle",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/ParticlePair",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/ParticlePair3D",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/NuDyn",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/PtPt",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/Plotting",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/Therminator",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/Performance",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/Exec",
"/Users/aa7526/Documents/GitHub/CAP7.0/src/BasicEventGen",
"/include",
"/Users/aa7526/opt/fastjet-3.4.3/include",
"/Users/aa7526/opt/pythia8312/include",
"/Users/aa7526/opt/pythia8312/include/Pythia8",
"/opt/homebrew/Cellar/root/6.32.06/include/root",
"/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Global/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libGlobal dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$GlobalHistos.hpp")))  GlobalHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$GlobalDerivedHistos.hpp")))  GlobalDerivedHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$GlobalAnalyzer.hpp")))  GlobalAnalyzer;}
namespace CAP{class __attribute__((annotate("$clingAutoload$GlobalCalculator.hpp")))  GlobalCalculator;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libGlobal dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "GlobalHistos.hpp"
#include "GlobalDerivedHistos.hpp"
#include "GlobalAnalyzer.hpp"
#include "GlobalCalculator.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::GlobalAnalyzer", payloadCode, "@",
"CAP::GlobalCalculator", payloadCode, "@",
"CAP::GlobalDerivedHistos", payloadCode, "@",
"CAP::GlobalHistos", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libGlobal",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libGlobal_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libGlobal_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libGlobal() {
  TriggerDictionaryInitialization_libGlobal_Impl();
}
