// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__BasicEventGen
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
#include "BasicEventGen.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLBasicEventGen(void *p = nullptr);
   static void *newArray_CAPcLcLBasicEventGen(Long_t size, void *p);
   static void delete_CAPcLcLBasicEventGen(void *p);
   static void deleteArray_CAPcLcLBasicEventGen(void *p);
   static void destruct_CAPcLcLBasicEventGen(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::BasicEventGen*)
   {
      ::CAP::BasicEventGen *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::BasicEventGen >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::BasicEventGen", ::CAP::BasicEventGen::Class_Version(), "BasicEventGen.hpp", 19,
                  typeid(::CAP::BasicEventGen), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::BasicEventGen::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::BasicEventGen) );
      instance.SetNew(&new_CAPcLcLBasicEventGen);
      instance.SetNewArray(&newArray_CAPcLcLBasicEventGen);
      instance.SetDelete(&delete_CAPcLcLBasicEventGen);
      instance.SetDeleteArray(&deleteArray_CAPcLcLBasicEventGen);
      instance.SetDestructor(&destruct_CAPcLcLBasicEventGen);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::BasicEventGen*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::BasicEventGen*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::BasicEventGen*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr BasicEventGen::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *BasicEventGen::Class_Name()
{
   return "CAP::BasicEventGen";
}

//______________________________________________________________________________
const char *BasicEventGen::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::BasicEventGen*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int BasicEventGen::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::BasicEventGen*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *BasicEventGen::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::BasicEventGen*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *BasicEventGen::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::BasicEventGen*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void BasicEventGen::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::BasicEventGen.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::BasicEventGen::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::BasicEventGen::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLBasicEventGen(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::BasicEventGen : new ::CAP::BasicEventGen;
   }
   static void *newArray_CAPcLcLBasicEventGen(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::BasicEventGen[nElements] : new ::CAP::BasicEventGen[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLBasicEventGen(void *p) {
      delete (static_cast<::CAP::BasicEventGen*>(p));
   }
   static void deleteArray_CAPcLcLBasicEventGen(void *p) {
      delete [] (static_cast<::CAP::BasicEventGen*>(p));
   }
   static void destruct_CAPcLcLBasicEventGen(void *p) {
      typedef ::CAP::BasicEventGen current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::BasicEventGen

namespace {
  void TriggerDictionaryInitialization_libBasicEventGen_Impl() {
    static const char* headers[] = {
"BasicEventGen.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP7.0/wsu/BasicEventGen/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libBasicEventGen dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$BasicEventGen.hpp")))  BasicEventGen;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libBasicEventGen dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "BasicEventGen.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::BasicEventGen", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libBasicEventGen",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libBasicEventGen_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libBasicEventGen_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libBasicEventGen() {
  TriggerDictionaryInitialization_libBasicEventGen_Impl();
}
