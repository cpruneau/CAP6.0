// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Exec
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
#include "TaskCreator.hpp"
#include "RunAnalysis.hpp"
#include "RunSubSampleSum.hpp"
#include "RunClosureAnalysis.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLTaskCreator(void *p = nullptr);
   static void *newArray_CAPcLcLTaskCreator(Long_t size, void *p);
   static void delete_CAPcLcLTaskCreator(void *p);
   static void deleteArray_CAPcLcLTaskCreator(void *p);
   static void destruct_CAPcLcLTaskCreator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::TaskCreator*)
   {
      ::CAP::TaskCreator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::TaskCreator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::TaskCreator", ::CAP::TaskCreator::Class_Version(), "TaskCreator.hpp", 19,
                  typeid(::CAP::TaskCreator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::TaskCreator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::TaskCreator) );
      instance.SetNew(&new_CAPcLcLTaskCreator);
      instance.SetNewArray(&newArray_CAPcLcLTaskCreator);
      instance.SetDelete(&delete_CAPcLcLTaskCreator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLTaskCreator);
      instance.SetDestructor(&destruct_CAPcLcLTaskCreator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::TaskCreator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::TaskCreator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::TaskCreator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLRunAnalysis(void *p = nullptr);
   static void *newArray_CAPcLcLRunAnalysis(Long_t size, void *p);
   static void delete_CAPcLcLRunAnalysis(void *p);
   static void deleteArray_CAPcLcLRunAnalysis(void *p);
   static void destruct_CAPcLcLRunAnalysis(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::RunAnalysis*)
   {
      ::CAP::RunAnalysis *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::RunAnalysis >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::RunAnalysis", ::CAP::RunAnalysis::Class_Version(), "RunAnalysis.hpp", 19,
                  typeid(::CAP::RunAnalysis), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::RunAnalysis::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::RunAnalysis) );
      instance.SetNew(&new_CAPcLcLRunAnalysis);
      instance.SetNewArray(&newArray_CAPcLcLRunAnalysis);
      instance.SetDelete(&delete_CAPcLcLRunAnalysis);
      instance.SetDeleteArray(&deleteArray_CAPcLcLRunAnalysis);
      instance.SetDestructor(&destruct_CAPcLcLRunAnalysis);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::RunAnalysis*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::RunAnalysis*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::RunAnalysis*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLRunSubSampleSum(void *p = nullptr);
   static void *newArray_CAPcLcLRunSubSampleSum(Long_t size, void *p);
   static void delete_CAPcLcLRunSubSampleSum(void *p);
   static void deleteArray_CAPcLcLRunSubSampleSum(void *p);
   static void destruct_CAPcLcLRunSubSampleSum(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::RunSubSampleSum*)
   {
      ::CAP::RunSubSampleSum *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::RunSubSampleSum >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::RunSubSampleSum", ::CAP::RunSubSampleSum::Class_Version(), "RunSubSampleSum.hpp", 19,
                  typeid(::CAP::RunSubSampleSum), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::RunSubSampleSum::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::RunSubSampleSum) );
      instance.SetNew(&new_CAPcLcLRunSubSampleSum);
      instance.SetNewArray(&newArray_CAPcLcLRunSubSampleSum);
      instance.SetDelete(&delete_CAPcLcLRunSubSampleSum);
      instance.SetDeleteArray(&deleteArray_CAPcLcLRunSubSampleSum);
      instance.SetDestructor(&destruct_CAPcLcLRunSubSampleSum);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::RunSubSampleSum*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::RunSubSampleSum*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::RunSubSampleSum*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLRunClosureAnalysis(void *p = nullptr);
   static void *newArray_CAPcLcLRunClosureAnalysis(Long_t size, void *p);
   static void delete_CAPcLcLRunClosureAnalysis(void *p);
   static void deleteArray_CAPcLcLRunClosureAnalysis(void *p);
   static void destruct_CAPcLcLRunClosureAnalysis(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::RunClosureAnalysis*)
   {
      ::CAP::RunClosureAnalysis *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::RunClosureAnalysis >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::RunClosureAnalysis", ::CAP::RunClosureAnalysis::Class_Version(), "RunClosureAnalysis.hpp", 19,
                  typeid(::CAP::RunClosureAnalysis), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::RunClosureAnalysis::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::RunClosureAnalysis) );
      instance.SetNew(&new_CAPcLcLRunClosureAnalysis);
      instance.SetNewArray(&newArray_CAPcLcLRunClosureAnalysis);
      instance.SetDelete(&delete_CAPcLcLRunClosureAnalysis);
      instance.SetDeleteArray(&deleteArray_CAPcLcLRunClosureAnalysis);
      instance.SetDestructor(&destruct_CAPcLcLRunClosureAnalysis);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::RunClosureAnalysis*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::RunClosureAnalysis*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::RunClosureAnalysis*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr TaskCreator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TaskCreator::Class_Name()
{
   return "CAP::TaskCreator";
}

//______________________________________________________________________________
const char *TaskCreator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::TaskCreator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TaskCreator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::TaskCreator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TaskCreator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::TaskCreator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TaskCreator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::TaskCreator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr RunAnalysis::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *RunAnalysis::Class_Name()
{
   return "CAP::RunAnalysis";
}

//______________________________________________________________________________
const char *RunAnalysis::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::RunAnalysis*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int RunAnalysis::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::RunAnalysis*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RunAnalysis::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::RunAnalysis*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RunAnalysis::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::RunAnalysis*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr RunSubSampleSum::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *RunSubSampleSum::Class_Name()
{
   return "CAP::RunSubSampleSum";
}

//______________________________________________________________________________
const char *RunSubSampleSum::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::RunSubSampleSum*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int RunSubSampleSum::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::RunSubSampleSum*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RunSubSampleSum::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::RunSubSampleSum*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RunSubSampleSum::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::RunSubSampleSum*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr RunClosureAnalysis::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *RunClosureAnalysis::Class_Name()
{
   return "CAP::RunClosureAnalysis";
}

//______________________________________________________________________________
const char *RunClosureAnalysis::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::RunClosureAnalysis*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int RunClosureAnalysis::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::RunClosureAnalysis*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *RunClosureAnalysis::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::RunClosureAnalysis*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *RunClosureAnalysis::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::RunClosureAnalysis*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void TaskCreator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::TaskCreator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::TaskCreator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::TaskCreator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLTaskCreator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::TaskCreator : new ::CAP::TaskCreator;
   }
   static void *newArray_CAPcLcLTaskCreator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::TaskCreator[nElements] : new ::CAP::TaskCreator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLTaskCreator(void *p) {
      delete (static_cast<::CAP::TaskCreator*>(p));
   }
   static void deleteArray_CAPcLcLTaskCreator(void *p) {
      delete [] (static_cast<::CAP::TaskCreator*>(p));
   }
   static void destruct_CAPcLcLTaskCreator(void *p) {
      typedef ::CAP::TaskCreator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::TaskCreator

namespace CAP {
//______________________________________________________________________________
void RunAnalysis::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::RunAnalysis.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::RunAnalysis::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::RunAnalysis::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLRunAnalysis(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::RunAnalysis : new ::CAP::RunAnalysis;
   }
   static void *newArray_CAPcLcLRunAnalysis(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::RunAnalysis[nElements] : new ::CAP::RunAnalysis[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLRunAnalysis(void *p) {
      delete (static_cast<::CAP::RunAnalysis*>(p));
   }
   static void deleteArray_CAPcLcLRunAnalysis(void *p) {
      delete [] (static_cast<::CAP::RunAnalysis*>(p));
   }
   static void destruct_CAPcLcLRunAnalysis(void *p) {
      typedef ::CAP::RunAnalysis current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::RunAnalysis

namespace CAP {
//______________________________________________________________________________
void RunSubSampleSum::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::RunSubSampleSum.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::RunSubSampleSum::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::RunSubSampleSum::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLRunSubSampleSum(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::RunSubSampleSum : new ::CAP::RunSubSampleSum;
   }
   static void *newArray_CAPcLcLRunSubSampleSum(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::RunSubSampleSum[nElements] : new ::CAP::RunSubSampleSum[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLRunSubSampleSum(void *p) {
      delete (static_cast<::CAP::RunSubSampleSum*>(p));
   }
   static void deleteArray_CAPcLcLRunSubSampleSum(void *p) {
      delete [] (static_cast<::CAP::RunSubSampleSum*>(p));
   }
   static void destruct_CAPcLcLRunSubSampleSum(void *p) {
      typedef ::CAP::RunSubSampleSum current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::RunSubSampleSum

namespace CAP {
//______________________________________________________________________________
void RunClosureAnalysis::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::RunClosureAnalysis.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::RunClosureAnalysis::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::RunClosureAnalysis::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLRunClosureAnalysis(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::RunClosureAnalysis : new ::CAP::RunClosureAnalysis;
   }
   static void *newArray_CAPcLcLRunClosureAnalysis(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::RunClosureAnalysis[nElements] : new ::CAP::RunClosureAnalysis[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLRunClosureAnalysis(void *p) {
      delete (static_cast<::CAP::RunClosureAnalysis*>(p));
   }
   static void deleteArray_CAPcLcLRunClosureAnalysis(void *p) {
      delete [] (static_cast<::CAP::RunClosureAnalysis*>(p));
   }
   static void destruct_CAPcLcLRunClosureAnalysis(void *p) {
      typedef ::CAP::RunClosureAnalysis current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::RunClosureAnalysis

namespace {
  void TriggerDictionaryInitialization_libExec_Impl() {
    static const char* headers[] = {
"TaskCreator.hpp",
"RunAnalysis.hpp",
"RunSubSampleSum.hpp",
"RunClosureAnalysis.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Exec/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libExec dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$TaskCreator.hpp")))  TaskCreator;}
namespace CAP{class __attribute__((annotate("$clingAutoload$RunAnalysis.hpp")))  RunAnalysis;}
namespace CAP{class __attribute__((annotate("$clingAutoload$RunSubSampleSum.hpp")))  RunSubSampleSum;}
namespace CAP{class __attribute__((annotate("$clingAutoload$RunClosureAnalysis.hpp")))  RunClosureAnalysis;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libExec dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "TaskCreator.hpp"
#include "RunAnalysis.hpp"
#include "RunSubSampleSum.hpp"
#include "RunClosureAnalysis.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::RunAnalysis", payloadCode, "@",
"CAP::RunClosureAnalysis", payloadCode, "@",
"CAP::RunSubSampleSum", payloadCode, "@",
"CAP::TaskCreator", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libExec",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libExec_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libExec_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libExec() {
  TriggerDictionaryInitialization_libExec_Impl();
}
