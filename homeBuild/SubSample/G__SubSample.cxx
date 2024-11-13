// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__SubSample
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
#include "SubSampleStatCalculator.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLSubSampleStatCalculator(void *p = nullptr);
   static void *newArray_CAPcLcLSubSampleStatCalculator(Long_t size, void *p);
   static void delete_CAPcLcLSubSampleStatCalculator(void *p);
   static void deleteArray_CAPcLcLSubSampleStatCalculator(void *p);
   static void destruct_CAPcLcLSubSampleStatCalculator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::SubSampleStatCalculator*)
   {
      ::CAP::SubSampleStatCalculator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::SubSampleStatCalculator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::SubSampleStatCalculator", ::CAP::SubSampleStatCalculator::Class_Version(), "SubSampleStatCalculator.hpp", 21,
                  typeid(::CAP::SubSampleStatCalculator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::SubSampleStatCalculator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::SubSampleStatCalculator) );
      instance.SetNew(&new_CAPcLcLSubSampleStatCalculator);
      instance.SetNewArray(&newArray_CAPcLcLSubSampleStatCalculator);
      instance.SetDelete(&delete_CAPcLcLSubSampleStatCalculator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLSubSampleStatCalculator);
      instance.SetDestructor(&destruct_CAPcLcLSubSampleStatCalculator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::SubSampleStatCalculator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::SubSampleStatCalculator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::SubSampleStatCalculator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr SubSampleStatCalculator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *SubSampleStatCalculator::Class_Name()
{
   return "CAP::SubSampleStatCalculator";
}

//______________________________________________________________________________
const char *SubSampleStatCalculator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::SubSampleStatCalculator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int SubSampleStatCalculator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::SubSampleStatCalculator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SubSampleStatCalculator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::SubSampleStatCalculator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SubSampleStatCalculator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::SubSampleStatCalculator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void SubSampleStatCalculator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::SubSampleStatCalculator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::SubSampleStatCalculator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::SubSampleStatCalculator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLSubSampleStatCalculator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::SubSampleStatCalculator : new ::CAP::SubSampleStatCalculator;
   }
   static void *newArray_CAPcLcLSubSampleStatCalculator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::SubSampleStatCalculator[nElements] : new ::CAP::SubSampleStatCalculator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLSubSampleStatCalculator(void *p) {
      delete (static_cast<::CAP::SubSampleStatCalculator*>(p));
   }
   static void deleteArray_CAPcLcLSubSampleStatCalculator(void *p) {
      delete [] (static_cast<::CAP::SubSampleStatCalculator*>(p));
   }
   static void destruct_CAPcLcLSubSampleStatCalculator(void *p) {
      typedef ::CAP::SubSampleStatCalculator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::SubSampleStatCalculator

namespace {
  void TriggerDictionaryInitialization_libSubSample_Impl() {
    static const char* headers[] = {
"SubSampleStatCalculator.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/SubSample/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libSubSample dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$SubSampleStatCalculator.hpp")))  SubSampleStatCalculator;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libSubSample dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "SubSampleStatCalculator.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::SubSampleStatCalculator", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libSubSample",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libSubSample_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libSubSample_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libSubSample() {
  TriggerDictionaryInitialization_libSubSample_Impl();
}
