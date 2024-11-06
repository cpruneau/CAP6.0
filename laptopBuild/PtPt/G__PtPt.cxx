// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__PtPt
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
#include "PtPtHistos.hpp"
#include "PtPtDerivedHistos.hpp"
#include "PtPtAnalyzer.hpp"
#include "PtPtCalculator.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLPtPtHistos(void *p = nullptr);
   static void *newArray_CAPcLcLPtPtHistos(Long_t size, void *p);
   static void delete_CAPcLcLPtPtHistos(void *p);
   static void deleteArray_CAPcLcLPtPtHistos(void *p);
   static void destruct_CAPcLcLPtPtHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::PtPtHistos*)
   {
      ::CAP::PtPtHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::PtPtHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::PtPtHistos", ::CAP::PtPtHistos::Class_Version(), "PtPtHistos.hpp", 23,
                  typeid(::CAP::PtPtHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::PtPtHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::PtPtHistos) );
      instance.SetNew(&new_CAPcLcLPtPtHistos);
      instance.SetNewArray(&newArray_CAPcLcLPtPtHistos);
      instance.SetDelete(&delete_CAPcLcLPtPtHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLPtPtHistos);
      instance.SetDestructor(&destruct_CAPcLcLPtPtHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::PtPtHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::PtPtHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::PtPtHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLPtPtDerivedHistos(void *p = nullptr);
   static void *newArray_CAPcLcLPtPtDerivedHistos(Long_t size, void *p);
   static void delete_CAPcLcLPtPtDerivedHistos(void *p);
   static void deleteArray_CAPcLcLPtPtDerivedHistos(void *p);
   static void destruct_CAPcLcLPtPtDerivedHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::PtPtDerivedHistos*)
   {
      ::CAP::PtPtDerivedHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::PtPtDerivedHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::PtPtDerivedHistos", ::CAP::PtPtDerivedHistos::Class_Version(), "PtPtDerivedHistos.hpp", 21,
                  typeid(::CAP::PtPtDerivedHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::PtPtDerivedHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::PtPtDerivedHistos) );
      instance.SetNew(&new_CAPcLcLPtPtDerivedHistos);
      instance.SetNewArray(&newArray_CAPcLcLPtPtDerivedHistos);
      instance.SetDelete(&delete_CAPcLcLPtPtDerivedHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLPtPtDerivedHistos);
      instance.SetDestructor(&destruct_CAPcLcLPtPtDerivedHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::PtPtDerivedHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::PtPtDerivedHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::PtPtDerivedHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLPtPtAnalyzer(void *p = nullptr);
   static void *newArray_CAPcLcLPtPtAnalyzer(Long_t size, void *p);
   static void delete_CAPcLcLPtPtAnalyzer(void *p);
   static void deleteArray_CAPcLcLPtPtAnalyzer(void *p);
   static void destruct_CAPcLcLPtPtAnalyzer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::PtPtAnalyzer*)
   {
      ::CAP::PtPtAnalyzer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::PtPtAnalyzer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::PtPtAnalyzer", ::CAP::PtPtAnalyzer::Class_Version(), "PtPtAnalyzer.hpp", 26,
                  typeid(::CAP::PtPtAnalyzer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::PtPtAnalyzer::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::PtPtAnalyzer) );
      instance.SetNew(&new_CAPcLcLPtPtAnalyzer);
      instance.SetNewArray(&newArray_CAPcLcLPtPtAnalyzer);
      instance.SetDelete(&delete_CAPcLcLPtPtAnalyzer);
      instance.SetDeleteArray(&deleteArray_CAPcLcLPtPtAnalyzer);
      instance.SetDestructor(&destruct_CAPcLcLPtPtAnalyzer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::PtPtAnalyzer*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::PtPtAnalyzer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::PtPtAnalyzer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLPtPtCalculator(void *p = nullptr);
   static void *newArray_CAPcLcLPtPtCalculator(Long_t size, void *p);
   static void delete_CAPcLcLPtPtCalculator(void *p);
   static void deleteArray_CAPcLcLPtPtCalculator(void *p);
   static void destruct_CAPcLcLPtPtCalculator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::PtPtCalculator*)
   {
      ::CAP::PtPtCalculator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::PtPtCalculator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::PtPtCalculator", ::CAP::PtPtCalculator::Class_Version(), "PtPtCalculator.hpp", 18,
                  typeid(::CAP::PtPtCalculator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::PtPtCalculator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::PtPtCalculator) );
      instance.SetNew(&new_CAPcLcLPtPtCalculator);
      instance.SetNewArray(&newArray_CAPcLcLPtPtCalculator);
      instance.SetDelete(&delete_CAPcLcLPtPtCalculator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLPtPtCalculator);
      instance.SetDestructor(&destruct_CAPcLcLPtPtCalculator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::PtPtCalculator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::PtPtCalculator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::PtPtCalculator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr PtPtHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PtPtHistos::Class_Name()
{
   return "CAP::PtPtHistos";
}

//______________________________________________________________________________
const char *PtPtHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PtPtHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PtPtHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PtPtHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr PtPtDerivedHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PtPtDerivedHistos::Class_Name()
{
   return "CAP::PtPtDerivedHistos";
}

//______________________________________________________________________________
const char *PtPtDerivedHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtDerivedHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PtPtDerivedHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtDerivedHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PtPtDerivedHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtDerivedHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PtPtDerivedHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtDerivedHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr PtPtAnalyzer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PtPtAnalyzer::Class_Name()
{
   return "CAP::PtPtAnalyzer";
}

//______________________________________________________________________________
const char *PtPtAnalyzer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtAnalyzer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PtPtAnalyzer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtAnalyzer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PtPtAnalyzer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtAnalyzer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PtPtAnalyzer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtAnalyzer*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr PtPtCalculator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PtPtCalculator::Class_Name()
{
   return "CAP::PtPtCalculator";
}

//______________________________________________________________________________
const char *PtPtCalculator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtCalculator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PtPtCalculator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtCalculator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PtPtCalculator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtCalculator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PtPtCalculator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PtPtCalculator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void PtPtHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::PtPtHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::PtPtHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::PtPtHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLPtPtHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PtPtHistos : new ::CAP::PtPtHistos;
   }
   static void *newArray_CAPcLcLPtPtHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PtPtHistos[nElements] : new ::CAP::PtPtHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLPtPtHistos(void *p) {
      delete (static_cast<::CAP::PtPtHistos*>(p));
   }
   static void deleteArray_CAPcLcLPtPtHistos(void *p) {
      delete [] (static_cast<::CAP::PtPtHistos*>(p));
   }
   static void destruct_CAPcLcLPtPtHistos(void *p) {
      typedef ::CAP::PtPtHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::PtPtHistos

namespace CAP {
//______________________________________________________________________________
void PtPtDerivedHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::PtPtDerivedHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::PtPtDerivedHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::PtPtDerivedHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLPtPtDerivedHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PtPtDerivedHistos : new ::CAP::PtPtDerivedHistos;
   }
   static void *newArray_CAPcLcLPtPtDerivedHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PtPtDerivedHistos[nElements] : new ::CAP::PtPtDerivedHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLPtPtDerivedHistos(void *p) {
      delete (static_cast<::CAP::PtPtDerivedHistos*>(p));
   }
   static void deleteArray_CAPcLcLPtPtDerivedHistos(void *p) {
      delete [] (static_cast<::CAP::PtPtDerivedHistos*>(p));
   }
   static void destruct_CAPcLcLPtPtDerivedHistos(void *p) {
      typedef ::CAP::PtPtDerivedHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::PtPtDerivedHistos

namespace CAP {
//______________________________________________________________________________
void PtPtAnalyzer::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::PtPtAnalyzer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::PtPtAnalyzer::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::PtPtAnalyzer::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLPtPtAnalyzer(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PtPtAnalyzer : new ::CAP::PtPtAnalyzer;
   }
   static void *newArray_CAPcLcLPtPtAnalyzer(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PtPtAnalyzer[nElements] : new ::CAP::PtPtAnalyzer[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLPtPtAnalyzer(void *p) {
      delete (static_cast<::CAP::PtPtAnalyzer*>(p));
   }
   static void deleteArray_CAPcLcLPtPtAnalyzer(void *p) {
      delete [] (static_cast<::CAP::PtPtAnalyzer*>(p));
   }
   static void destruct_CAPcLcLPtPtAnalyzer(void *p) {
      typedef ::CAP::PtPtAnalyzer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::PtPtAnalyzer

namespace CAP {
//______________________________________________________________________________
void PtPtCalculator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::PtPtCalculator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::PtPtCalculator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::PtPtCalculator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLPtPtCalculator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PtPtCalculator : new ::CAP::PtPtCalculator;
   }
   static void *newArray_CAPcLcLPtPtCalculator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PtPtCalculator[nElements] : new ::CAP::PtPtCalculator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLPtPtCalculator(void *p) {
      delete (static_cast<::CAP::PtPtCalculator*>(p));
   }
   static void deleteArray_CAPcLcLPtPtCalculator(void *p) {
      delete [] (static_cast<::CAP::PtPtCalculator*>(p));
   }
   static void destruct_CAPcLcLPtPtCalculator(void *p) {
      typedef ::CAP::PtPtCalculator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::PtPtCalculator

namespace {
  void TriggerDictionaryInitialization_libPtPt_Impl() {
    static const char* headers[] = {
"PtPtHistos.hpp",
"PtPtDerivedHistos.hpp",
"PtPtAnalyzer.hpp",
"PtPtCalculator.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP6.0/laptop/PtPt/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libPtPt dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$PtPtHistos.hpp")))  PtPtHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$PtPtDerivedHistos.hpp")))  PtPtDerivedHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$PtPtAnalyzer.hpp")))  PtPtAnalyzer;}
namespace CAP{class __attribute__((annotate("$clingAutoload$PtPtCalculator.hpp")))  PtPtCalculator;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libPtPt dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "PtPtHistos.hpp"
#include "PtPtDerivedHistos.hpp"
#include "PtPtAnalyzer.hpp"
#include "PtPtCalculator.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::PtPtAnalyzer", payloadCode, "@",
"CAP::PtPtCalculator", payloadCode, "@",
"CAP::PtPtDerivedHistos", payloadCode, "@",
"CAP::PtPtHistos", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libPtPt",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libPtPt_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libPtPt_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libPtPt() {
  TriggerDictionaryInitialization_libPtPt_Impl();
}
