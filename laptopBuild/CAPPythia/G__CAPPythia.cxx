// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__CAPPythia
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
#include "PythiaEventGenerator.hpp"
#include "PythiaEventReader.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLPythiaEventGenerator(void *p = nullptr);
   static void *newArray_CAPcLcLPythiaEventGenerator(Long_t size, void *p);
   static void delete_CAPcLcLPythiaEventGenerator(void *p);
   static void deleteArray_CAPcLcLPythiaEventGenerator(void *p);
   static void destruct_CAPcLcLPythiaEventGenerator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::PythiaEventGenerator*)
   {
      ::CAP::PythiaEventGenerator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::PythiaEventGenerator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::PythiaEventGenerator", ::CAP::PythiaEventGenerator::Class_Version(), "PythiaEventGenerator.hpp", 20,
                  typeid(::CAP::PythiaEventGenerator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::PythiaEventGenerator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::PythiaEventGenerator) );
      instance.SetNew(&new_CAPcLcLPythiaEventGenerator);
      instance.SetNewArray(&newArray_CAPcLcLPythiaEventGenerator);
      instance.SetDelete(&delete_CAPcLcLPythiaEventGenerator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLPythiaEventGenerator);
      instance.SetDestructor(&destruct_CAPcLcLPythiaEventGenerator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::PythiaEventGenerator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::PythiaEventGenerator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::PythiaEventGenerator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLPythiaEventReader(void *p = nullptr);
   static void *newArray_CAPcLcLPythiaEventReader(Long_t size, void *p);
   static void delete_CAPcLcLPythiaEventReader(void *p);
   static void deleteArray_CAPcLcLPythiaEventReader(void *p);
   static void destruct_CAPcLcLPythiaEventReader(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::PythiaEventReader*)
   {
      ::CAP::PythiaEventReader *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::PythiaEventReader >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::PythiaEventReader", ::CAP::PythiaEventReader::Class_Version(), "PythiaEventReader.hpp", 25,
                  typeid(::CAP::PythiaEventReader), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::PythiaEventReader::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::PythiaEventReader) );
      instance.SetNew(&new_CAPcLcLPythiaEventReader);
      instance.SetNewArray(&newArray_CAPcLcLPythiaEventReader);
      instance.SetDelete(&delete_CAPcLcLPythiaEventReader);
      instance.SetDeleteArray(&deleteArray_CAPcLcLPythiaEventReader);
      instance.SetDestructor(&destruct_CAPcLcLPythiaEventReader);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::PythiaEventReader*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::PythiaEventReader*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::PythiaEventReader*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr PythiaEventGenerator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PythiaEventGenerator::Class_Name()
{
   return "CAP::PythiaEventGenerator";
}

//______________________________________________________________________________
const char *PythiaEventGenerator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PythiaEventGenerator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PythiaEventGenerator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PythiaEventGenerator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PythiaEventGenerator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PythiaEventGenerator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PythiaEventGenerator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PythiaEventGenerator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr PythiaEventReader::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PythiaEventReader::Class_Name()
{
   return "CAP::PythiaEventReader";
}

//______________________________________________________________________________
const char *PythiaEventReader::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PythiaEventReader*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PythiaEventReader::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PythiaEventReader*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PythiaEventReader::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PythiaEventReader*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PythiaEventReader::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PythiaEventReader*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void PythiaEventGenerator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::PythiaEventGenerator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::PythiaEventGenerator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::PythiaEventGenerator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLPythiaEventGenerator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PythiaEventGenerator : new ::CAP::PythiaEventGenerator;
   }
   static void *newArray_CAPcLcLPythiaEventGenerator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PythiaEventGenerator[nElements] : new ::CAP::PythiaEventGenerator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLPythiaEventGenerator(void *p) {
      delete (static_cast<::CAP::PythiaEventGenerator*>(p));
   }
   static void deleteArray_CAPcLcLPythiaEventGenerator(void *p) {
      delete [] (static_cast<::CAP::PythiaEventGenerator*>(p));
   }
   static void destruct_CAPcLcLPythiaEventGenerator(void *p) {
      typedef ::CAP::PythiaEventGenerator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::PythiaEventGenerator

namespace CAP {
//______________________________________________________________________________
void PythiaEventReader::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::PythiaEventReader.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::PythiaEventReader::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::PythiaEventReader::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLPythiaEventReader(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PythiaEventReader : new ::CAP::PythiaEventReader;
   }
   static void *newArray_CAPcLcLPythiaEventReader(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PythiaEventReader[nElements] : new ::CAP::PythiaEventReader[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLPythiaEventReader(void *p) {
      delete (static_cast<::CAP::PythiaEventReader*>(p));
   }
   static void deleteArray_CAPcLcLPythiaEventReader(void *p) {
      delete [] (static_cast<::CAP::PythiaEventReader*>(p));
   }
   static void destruct_CAPcLcLPythiaEventReader(void *p) {
      typedef ::CAP::PythiaEventReader current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::PythiaEventReader

namespace {
  void TriggerDictionaryInitialization_libCAPPythia_Impl() {
    static const char* headers[] = {
"PythiaEventGenerator.hpp",
"PythiaEventReader.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP6.0/laptop/CAPPythia/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libCAPPythia dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$PythiaEventGenerator.hpp")))  PythiaEventGenerator;}
namespace CAP{class __attribute__((annotate("$clingAutoload$PythiaEventReader.hpp")))  PythiaEventReader;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libCAPPythia dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "PythiaEventGenerator.hpp"
#include "PythiaEventReader.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::PythiaEventGenerator", payloadCode, "@",
"CAP::PythiaEventReader", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libCAPPythia",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libCAPPythia_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libCAPPythia_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libCAPPythia() {
  TriggerDictionaryInitialization_libCAPPythia_Impl();
}
