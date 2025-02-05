// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Jets
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
#include "JetHistos.hpp"
#include "JetSingleHistos.hpp"
#include "JetPairHistos.hpp"
#include "JetAnalyzer.hpp"
#include "JetHistosDerived.hpp"
#include "JetSingleHistosDerived.hpp"
#include "JetPairHistosDerived.hpp"
#include "JetCalculator.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLJetHistos(void *p = nullptr);
   static void *newArray_CAPcLcLJetHistos(Long_t size, void *p);
   static void delete_CAPcLcLJetHistos(void *p);
   static void deleteArray_CAPcLcLJetHistos(void *p);
   static void destruct_CAPcLcLJetHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::JetHistos*)
   {
      ::CAP::JetHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::JetHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::JetHistos", ::CAP::JetHistos::Class_Version(), "JetHistos.hpp", 29,
                  typeid(::CAP::JetHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::JetHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::JetHistos) );
      instance.SetNew(&new_CAPcLcLJetHistos);
      instance.SetNewArray(&newArray_CAPcLcLJetHistos);
      instance.SetDelete(&delete_CAPcLcLJetHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLJetHistos);
      instance.SetDestructor(&destruct_CAPcLcLJetHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::JetHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::JetHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::JetHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLJetSingleHistos(void *p = nullptr);
   static void *newArray_CAPcLcLJetSingleHistos(Long_t size, void *p);
   static void delete_CAPcLcLJetSingleHistos(void *p);
   static void deleteArray_CAPcLcLJetSingleHistos(void *p);
   static void destruct_CAPcLcLJetSingleHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::JetSingleHistos*)
   {
      ::CAP::JetSingleHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::JetSingleHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::JetSingleHistos", ::CAP::JetSingleHistos::Class_Version(), "JetSingleHistos.hpp", 27,
                  typeid(::CAP::JetSingleHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::JetSingleHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::JetSingleHistos) );
      instance.SetNew(&new_CAPcLcLJetSingleHistos);
      instance.SetNewArray(&newArray_CAPcLcLJetSingleHistos);
      instance.SetDelete(&delete_CAPcLcLJetSingleHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLJetSingleHistos);
      instance.SetDestructor(&destruct_CAPcLcLJetSingleHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::JetSingleHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::JetSingleHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::JetSingleHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLJetPairHistos(void *p = nullptr);
   static void *newArray_CAPcLcLJetPairHistos(Long_t size, void *p);
   static void delete_CAPcLcLJetPairHistos(void *p);
   static void deleteArray_CAPcLcLJetPairHistos(void *p);
   static void destruct_CAPcLcLJetPairHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::JetPairHistos*)
   {
      ::CAP::JetPairHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::JetPairHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::JetPairHistos", ::CAP::JetPairHistos::Class_Version(), "JetPairHistos.hpp", 25,
                  typeid(::CAP::JetPairHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::JetPairHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::JetPairHistos) );
      instance.SetNew(&new_CAPcLcLJetPairHistos);
      instance.SetNewArray(&newArray_CAPcLcLJetPairHistos);
      instance.SetDelete(&delete_CAPcLcLJetPairHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLJetPairHistos);
      instance.SetDestructor(&destruct_CAPcLcLJetPairHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::JetPairHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::JetPairHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::JetPairHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLJetAnalyzer(void *p = nullptr);
   static void *newArray_CAPcLcLJetAnalyzer(Long_t size, void *p);
   static void delete_CAPcLcLJetAnalyzer(void *p);
   static void deleteArray_CAPcLcLJetAnalyzer(void *p);
   static void destruct_CAPcLcLJetAnalyzer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::JetAnalyzer*)
   {
      ::CAP::JetAnalyzer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::JetAnalyzer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::JetAnalyzer", ::CAP::JetAnalyzer::Class_Version(), "JetAnalyzer.hpp", 19,
                  typeid(::CAP::JetAnalyzer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::JetAnalyzer::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::JetAnalyzer) );
      instance.SetNew(&new_CAPcLcLJetAnalyzer);
      instance.SetNewArray(&newArray_CAPcLcLJetAnalyzer);
      instance.SetDelete(&delete_CAPcLcLJetAnalyzer);
      instance.SetDeleteArray(&deleteArray_CAPcLcLJetAnalyzer);
      instance.SetDestructor(&destruct_CAPcLcLJetAnalyzer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::JetAnalyzer*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::JetAnalyzer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::JetAnalyzer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLJetHistosDerived(void *p = nullptr);
   static void *newArray_CAPcLcLJetHistosDerived(Long_t size, void *p);
   static void delete_CAPcLcLJetHistosDerived(void *p);
   static void deleteArray_CAPcLcLJetHistosDerived(void *p);
   static void destruct_CAPcLcLJetHistosDerived(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::JetHistosDerived*)
   {
      ::CAP::JetHistosDerived *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::JetHistosDerived >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::JetHistosDerived", ::CAP::JetHistosDerived::Class_Version(), "JetHistosDerived.hpp", 27,
                  typeid(::CAP::JetHistosDerived), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::JetHistosDerived::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::JetHistosDerived) );
      instance.SetNew(&new_CAPcLcLJetHistosDerived);
      instance.SetNewArray(&newArray_CAPcLcLJetHistosDerived);
      instance.SetDelete(&delete_CAPcLcLJetHistosDerived);
      instance.SetDeleteArray(&deleteArray_CAPcLcLJetHistosDerived);
      instance.SetDestructor(&destruct_CAPcLcLJetHistosDerived);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::JetHistosDerived*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::JetHistosDerived*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::JetHistosDerived*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLJetSingleHistosDerived(void *p = nullptr);
   static void *newArray_CAPcLcLJetSingleHistosDerived(Long_t size, void *p);
   static void delete_CAPcLcLJetSingleHistosDerived(void *p);
   static void deleteArray_CAPcLcLJetSingleHistosDerived(void *p);
   static void destruct_CAPcLcLJetSingleHistosDerived(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::JetSingleHistosDerived*)
   {
      ::CAP::JetSingleHistosDerived *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::JetSingleHistosDerived >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::JetSingleHistosDerived", ::CAP::JetSingleHistosDerived::Class_Version(), "JetSingleHistosDerived.hpp", 26,
                  typeid(::CAP::JetSingleHistosDerived), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::JetSingleHistosDerived::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::JetSingleHistosDerived) );
      instance.SetNew(&new_CAPcLcLJetSingleHistosDerived);
      instance.SetNewArray(&newArray_CAPcLcLJetSingleHistosDerived);
      instance.SetDelete(&delete_CAPcLcLJetSingleHistosDerived);
      instance.SetDeleteArray(&deleteArray_CAPcLcLJetSingleHistosDerived);
      instance.SetDestructor(&destruct_CAPcLcLJetSingleHistosDerived);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::JetSingleHistosDerived*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::JetSingleHistosDerived*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::JetSingleHistosDerived*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLJetPairHistosDerived(void *p = nullptr);
   static void *newArray_CAPcLcLJetPairHistosDerived(Long_t size, void *p);
   static void delete_CAPcLcLJetPairHistosDerived(void *p);
   static void deleteArray_CAPcLcLJetPairHistosDerived(void *p);
   static void destruct_CAPcLcLJetPairHistosDerived(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::JetPairHistosDerived*)
   {
      ::CAP::JetPairHistosDerived *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::JetPairHistosDerived >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::JetPairHistosDerived", ::CAP::JetPairHistosDerived::Class_Version(), "JetPairHistosDerived.hpp", 24,
                  typeid(::CAP::JetPairHistosDerived), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::JetPairHistosDerived::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::JetPairHistosDerived) );
      instance.SetNew(&new_CAPcLcLJetPairHistosDerived);
      instance.SetNewArray(&newArray_CAPcLcLJetPairHistosDerived);
      instance.SetDelete(&delete_CAPcLcLJetPairHistosDerived);
      instance.SetDeleteArray(&deleteArray_CAPcLcLJetPairHistosDerived);
      instance.SetDestructor(&destruct_CAPcLcLJetPairHistosDerived);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::JetPairHistosDerived*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::JetPairHistosDerived*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::JetPairHistosDerived*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLJetCalculator(void *p = nullptr);
   static void *newArray_CAPcLcLJetCalculator(Long_t size, void *p);
   static void delete_CAPcLcLJetCalculator(void *p);
   static void deleteArray_CAPcLcLJetCalculator(void *p);
   static void destruct_CAPcLcLJetCalculator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::JetCalculator*)
   {
      ::CAP::JetCalculator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::JetCalculator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::JetCalculator", ::CAP::JetCalculator::Class_Version(), "JetCalculator.hpp", 19,
                  typeid(::CAP::JetCalculator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::JetCalculator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::JetCalculator) );
      instance.SetNew(&new_CAPcLcLJetCalculator);
      instance.SetNewArray(&newArray_CAPcLcLJetCalculator);
      instance.SetDelete(&delete_CAPcLcLJetCalculator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLJetCalculator);
      instance.SetDestructor(&destruct_CAPcLcLJetCalculator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::JetCalculator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::JetCalculator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::JetCalculator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr JetHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *JetHistos::Class_Name()
{
   return "CAP::JetHistos";
}

//______________________________________________________________________________
const char *JetHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int JetHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr JetSingleHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *JetSingleHistos::Class_Name()
{
   return "CAP::JetSingleHistos";
}

//______________________________________________________________________________
const char *JetSingleHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetSingleHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int JetSingleHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetSingleHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetSingleHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetSingleHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetSingleHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetSingleHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr JetPairHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *JetPairHistos::Class_Name()
{
   return "CAP::JetPairHistos";
}

//______________________________________________________________________________
const char *JetPairHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetPairHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int JetPairHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetPairHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetPairHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetPairHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetPairHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetPairHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr JetAnalyzer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *JetAnalyzer::Class_Name()
{
   return "CAP::JetAnalyzer";
}

//______________________________________________________________________________
const char *JetAnalyzer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetAnalyzer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int JetAnalyzer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetAnalyzer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetAnalyzer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetAnalyzer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetAnalyzer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetAnalyzer*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr JetHistosDerived::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *JetHistosDerived::Class_Name()
{
   return "CAP::JetHistosDerived";
}

//______________________________________________________________________________
const char *JetHistosDerived::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetHistosDerived*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int JetHistosDerived::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetHistosDerived*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetHistosDerived::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetHistosDerived*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetHistosDerived::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetHistosDerived*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr JetSingleHistosDerived::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *JetSingleHistosDerived::Class_Name()
{
   return "CAP::JetSingleHistosDerived";
}

//______________________________________________________________________________
const char *JetSingleHistosDerived::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetSingleHistosDerived*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int JetSingleHistosDerived::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetSingleHistosDerived*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetSingleHistosDerived::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetSingleHistosDerived*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetSingleHistosDerived::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetSingleHistosDerived*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr JetPairHistosDerived::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *JetPairHistosDerived::Class_Name()
{
   return "CAP::JetPairHistosDerived";
}

//______________________________________________________________________________
const char *JetPairHistosDerived::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetPairHistosDerived*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int JetPairHistosDerived::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetPairHistosDerived*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetPairHistosDerived::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetPairHistosDerived*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetPairHistosDerived::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetPairHistosDerived*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr JetCalculator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *JetCalculator::Class_Name()
{
   return "CAP::JetCalculator";
}

//______________________________________________________________________________
const char *JetCalculator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetCalculator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int JetCalculator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetCalculator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetCalculator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetCalculator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetCalculator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetCalculator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void JetHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::JetHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::JetHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::JetHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLJetHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetHistos : new ::CAP::JetHistos;
   }
   static void *newArray_CAPcLcLJetHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetHistos[nElements] : new ::CAP::JetHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLJetHistos(void *p) {
      delete (static_cast<::CAP::JetHistos*>(p));
   }
   static void deleteArray_CAPcLcLJetHistos(void *p) {
      delete [] (static_cast<::CAP::JetHistos*>(p));
   }
   static void destruct_CAPcLcLJetHistos(void *p) {
      typedef ::CAP::JetHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::JetHistos

namespace CAP {
//______________________________________________________________________________
void JetSingleHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::JetSingleHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::JetSingleHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::JetSingleHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLJetSingleHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetSingleHistos : new ::CAP::JetSingleHistos;
   }
   static void *newArray_CAPcLcLJetSingleHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetSingleHistos[nElements] : new ::CAP::JetSingleHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLJetSingleHistos(void *p) {
      delete (static_cast<::CAP::JetSingleHistos*>(p));
   }
   static void deleteArray_CAPcLcLJetSingleHistos(void *p) {
      delete [] (static_cast<::CAP::JetSingleHistos*>(p));
   }
   static void destruct_CAPcLcLJetSingleHistos(void *p) {
      typedef ::CAP::JetSingleHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::JetSingleHistos

namespace CAP {
//______________________________________________________________________________
void JetPairHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::JetPairHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::JetPairHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::JetPairHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLJetPairHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetPairHistos : new ::CAP::JetPairHistos;
   }
   static void *newArray_CAPcLcLJetPairHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetPairHistos[nElements] : new ::CAP::JetPairHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLJetPairHistos(void *p) {
      delete (static_cast<::CAP::JetPairHistos*>(p));
   }
   static void deleteArray_CAPcLcLJetPairHistos(void *p) {
      delete [] (static_cast<::CAP::JetPairHistos*>(p));
   }
   static void destruct_CAPcLcLJetPairHistos(void *p) {
      typedef ::CAP::JetPairHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::JetPairHistos

namespace CAP {
//______________________________________________________________________________
void JetAnalyzer::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::JetAnalyzer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::JetAnalyzer::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::JetAnalyzer::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLJetAnalyzer(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetAnalyzer : new ::CAP::JetAnalyzer;
   }
   static void *newArray_CAPcLcLJetAnalyzer(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetAnalyzer[nElements] : new ::CAP::JetAnalyzer[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLJetAnalyzer(void *p) {
      delete (static_cast<::CAP::JetAnalyzer*>(p));
   }
   static void deleteArray_CAPcLcLJetAnalyzer(void *p) {
      delete [] (static_cast<::CAP::JetAnalyzer*>(p));
   }
   static void destruct_CAPcLcLJetAnalyzer(void *p) {
      typedef ::CAP::JetAnalyzer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::JetAnalyzer

namespace CAP {
//______________________________________________________________________________
void JetHistosDerived::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::JetHistosDerived.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::JetHistosDerived::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::JetHistosDerived::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLJetHistosDerived(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetHistosDerived : new ::CAP::JetHistosDerived;
   }
   static void *newArray_CAPcLcLJetHistosDerived(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetHistosDerived[nElements] : new ::CAP::JetHistosDerived[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLJetHistosDerived(void *p) {
      delete (static_cast<::CAP::JetHistosDerived*>(p));
   }
   static void deleteArray_CAPcLcLJetHistosDerived(void *p) {
      delete [] (static_cast<::CAP::JetHistosDerived*>(p));
   }
   static void destruct_CAPcLcLJetHistosDerived(void *p) {
      typedef ::CAP::JetHistosDerived current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::JetHistosDerived

namespace CAP {
//______________________________________________________________________________
void JetSingleHistosDerived::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::JetSingleHistosDerived.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::JetSingleHistosDerived::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::JetSingleHistosDerived::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLJetSingleHistosDerived(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetSingleHistosDerived : new ::CAP::JetSingleHistosDerived;
   }
   static void *newArray_CAPcLcLJetSingleHistosDerived(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetSingleHistosDerived[nElements] : new ::CAP::JetSingleHistosDerived[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLJetSingleHistosDerived(void *p) {
      delete (static_cast<::CAP::JetSingleHistosDerived*>(p));
   }
   static void deleteArray_CAPcLcLJetSingleHistosDerived(void *p) {
      delete [] (static_cast<::CAP::JetSingleHistosDerived*>(p));
   }
   static void destruct_CAPcLcLJetSingleHistosDerived(void *p) {
      typedef ::CAP::JetSingleHistosDerived current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::JetSingleHistosDerived

namespace CAP {
//______________________________________________________________________________
void JetPairHistosDerived::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::JetPairHistosDerived.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::JetPairHistosDerived::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::JetPairHistosDerived::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLJetPairHistosDerived(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetPairHistosDerived : new ::CAP::JetPairHistosDerived;
   }
   static void *newArray_CAPcLcLJetPairHistosDerived(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetPairHistosDerived[nElements] : new ::CAP::JetPairHistosDerived[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLJetPairHistosDerived(void *p) {
      delete (static_cast<::CAP::JetPairHistosDerived*>(p));
   }
   static void deleteArray_CAPcLcLJetPairHistosDerived(void *p) {
      delete [] (static_cast<::CAP::JetPairHistosDerived*>(p));
   }
   static void destruct_CAPcLcLJetPairHistosDerived(void *p) {
      typedef ::CAP::JetPairHistosDerived current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::JetPairHistosDerived

namespace CAP {
//______________________________________________________________________________
void JetCalculator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::JetCalculator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::JetCalculator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::JetCalculator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLJetCalculator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetCalculator : new ::CAP::JetCalculator;
   }
   static void *newArray_CAPcLcLJetCalculator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetCalculator[nElements] : new ::CAP::JetCalculator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLJetCalculator(void *p) {
      delete (static_cast<::CAP::JetCalculator*>(p));
   }
   static void deleteArray_CAPcLcLJetCalculator(void *p) {
      delete [] (static_cast<::CAP::JetCalculator*>(p));
   }
   static void destruct_CAPcLcLJetCalculator(void *p) {
      typedef ::CAP::JetCalculator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::JetCalculator

namespace {
  void TriggerDictionaryInitialization_libJets_Impl() {
    static const char* headers[] = {
"JetHistos.hpp",
"JetSingleHistos.hpp",
"JetPairHistos.hpp",
"JetAnalyzer.hpp",
"JetHistosDerived.hpp",
"JetSingleHistosDerived.hpp",
"JetPairHistosDerived.hpp",
"JetCalculator.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Jets/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libJets dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$JetHistos.hpp")))  JetHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$JetSingleHistos.hpp")))  JetSingleHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$JetPairHistos.hpp")))  JetPairHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$JetAnalyzer.hpp")))  JetAnalyzer;}
namespace CAP{class __attribute__((annotate("$clingAutoload$JetHistosDerived.hpp")))  JetHistosDerived;}
namespace CAP{class __attribute__((annotate("$clingAutoload$JetSingleHistosDerived.hpp")))  JetSingleHistosDerived;}
namespace CAP{class __attribute__((annotate("$clingAutoload$JetPairHistosDerived.hpp")))  JetPairHistosDerived;}
namespace CAP{class __attribute__((annotate("$clingAutoload$JetCalculator.hpp")))  JetCalculator;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libJets dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "JetHistos.hpp"
#include "JetSingleHistos.hpp"
#include "JetPairHistos.hpp"
#include "JetAnalyzer.hpp"
#include "JetHistosDerived.hpp"
#include "JetSingleHistosDerived.hpp"
#include "JetPairHistosDerived.hpp"
#include "JetCalculator.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::JetAnalyzer", payloadCode, "@",
"CAP::JetCalculator", payloadCode, "@",
"CAP::JetHistos", payloadCode, "@",
"CAP::JetHistosDerived", payloadCode, "@",
"CAP::JetPairHistos", payloadCode, "@",
"CAP::JetPairHistosDerived", payloadCode, "@",
"CAP::JetSingleHistos", payloadCode, "@",
"CAP::JetSingleHistosDerived", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libJets",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libJets_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libJets_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libJets() {
  TriggerDictionaryInitialization_libJets_Impl();
}
