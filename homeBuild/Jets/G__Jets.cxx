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
#include "JetFilter.hpp"
#include "JetFilterCreator.hpp"

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
         instance("CAP::JetHistos", ::CAP::JetHistos::Class_Version(), "JetHistos.hpp", 16,
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
         instance("CAP::JetSingleHistos", ::CAP::JetSingleHistos::Class_Version(), "JetSingleHistos.hpp", 15,
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
         instance("CAP::JetPairHistos", ::CAP::JetPairHistos::Class_Version(), "JetPairHistos.hpp", 13,
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
   static TClass *CAPcLcLManagerlECAPcLcLJetFiltergR_Dictionary();
   static void CAPcLcLManagerlECAPcLcLJetFiltergR_TClassManip(TClass*);
   static void *new_CAPcLcLManagerlECAPcLcLJetFiltergR(void *p = nullptr);
   static void *newArray_CAPcLcLManagerlECAPcLcLJetFiltergR(Long_t size, void *p);
   static void delete_CAPcLcLManagerlECAPcLcLJetFiltergR(void *p);
   static void deleteArray_CAPcLcLManagerlECAPcLcLJetFiltergR(void *p);
   static void destruct_CAPcLcLManagerlECAPcLcLJetFiltergR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Manager<CAP::JetFilter>*)
   {
      ::CAP::Manager<CAP::JetFilter> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Manager<CAP::JetFilter> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Manager<CAP::JetFilter>", ::CAP::Manager<CAP::JetFilter>::Class_Version(), "Manager.hpp", 33,
                  typeid(::CAP::Manager<CAP::JetFilter>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLManagerlECAPcLcLJetFiltergR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Manager<CAP::JetFilter>) );
      instance.SetNew(&new_CAPcLcLManagerlECAPcLcLJetFiltergR);
      instance.SetNewArray(&newArray_CAPcLcLManagerlECAPcLcLJetFiltergR);
      instance.SetDelete(&delete_CAPcLcLManagerlECAPcLcLJetFiltergR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLManagerlECAPcLcLJetFiltergR);
      instance.SetDestructor(&destruct_CAPcLcLManagerlECAPcLcLJetFiltergR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Manager<CAP::JetFilter>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Manager<CAP::JetFilter>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Manager<CAP::JetFilter>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLManagerlECAPcLcLJetFiltergR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Manager<CAP::JetFilter>*>(nullptr))->GetClass();
      CAPcLcLManagerlECAPcLcLJetFiltergR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLManagerlECAPcLcLJetFiltergR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLFilterlEfastjetcLcLPseudoJetgR_Dictionary();
   static void CAPcLcLFilterlEfastjetcLcLPseudoJetgR_TClassManip(TClass*);
   static void *new_CAPcLcLFilterlEfastjetcLcLPseudoJetgR(void *p = nullptr);
   static void *newArray_CAPcLcLFilterlEfastjetcLcLPseudoJetgR(Long_t size, void *p);
   static void delete_CAPcLcLFilterlEfastjetcLcLPseudoJetgR(void *p);
   static void deleteArray_CAPcLcLFilterlEfastjetcLcLPseudoJetgR(void *p);
   static void destruct_CAPcLcLFilterlEfastjetcLcLPseudoJetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Filter<fastjet::PseudoJet>*)
   {
      ::CAP::Filter<fastjet::PseudoJet> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CAP::Filter<fastjet::PseudoJet>));
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Filter<fastjet::PseudoJet>", "Filter.hpp", 34,
                  typeid(::CAP::Filter<fastjet::PseudoJet>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLFilterlEfastjetcLcLPseudoJetgR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Filter<fastjet::PseudoJet>) );
      instance.SetNew(&new_CAPcLcLFilterlEfastjetcLcLPseudoJetgR);
      instance.SetNewArray(&newArray_CAPcLcLFilterlEfastjetcLcLPseudoJetgR);
      instance.SetDelete(&delete_CAPcLcLFilterlEfastjetcLcLPseudoJetgR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLFilterlEfastjetcLcLPseudoJetgR);
      instance.SetDestructor(&destruct_CAPcLcLFilterlEfastjetcLcLPseudoJetgR);

      instance.AdoptAlternate(::ROOT::AddClassAlternate("CAP::Filter<fastjet::PseudoJet>","CAP::Filter<PseudoJet>"));
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Filter<fastjet::PseudoJet>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Filter<fastjet::PseudoJet>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Filter<fastjet::PseudoJet>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLFilterlEfastjetcLcLPseudoJetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Filter<fastjet::PseudoJet>*>(nullptr))->GetClass();
      CAPcLcLFilterlEfastjetcLcLPseudoJetgR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLFilterlEfastjetcLcLPseudoJetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLJetFilter(void *p = nullptr);
   static void *newArray_CAPcLcLJetFilter(Long_t size, void *p);
   static void delete_CAPcLcLJetFilter(void *p);
   static void deleteArray_CAPcLcLJetFilter(void *p);
   static void destruct_CAPcLcLJetFilter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::JetFilter*)
   {
      ::CAP::JetFilter *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::JetFilter >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::JetFilter", ::CAP::JetFilter::Class_Version(), "JetFilter.hpp", 21,
                  typeid(::CAP::JetFilter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::JetFilter::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::JetFilter) );
      instance.SetNew(&new_CAPcLcLJetFilter);
      instance.SetNewArray(&newArray_CAPcLcLJetFilter);
      instance.SetDelete(&delete_CAPcLcLJetFilter);
      instance.SetDeleteArray(&deleteArray_CAPcLcLJetFilter);
      instance.SetDestructor(&destruct_CAPcLcLJetFilter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::JetFilter*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::JetFilter*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::JetFilter*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
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
         instance("CAP::JetAnalyzer", ::CAP::JetAnalyzer::Class_Version(), "JetAnalyzer.hpp", 21,
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
   static void *new_CAPcLcLJetFilterCreator(void *p = nullptr);
   static void *newArray_CAPcLcLJetFilterCreator(Long_t size, void *p);
   static void delete_CAPcLcLJetFilterCreator(void *p);
   static void deleteArray_CAPcLcLJetFilterCreator(void *p);
   static void destruct_CAPcLcLJetFilterCreator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::JetFilterCreator*)
   {
      ::CAP::JetFilterCreator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::JetFilterCreator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::JetFilterCreator", ::CAP::JetFilterCreator::Class_Version(), "JetFilterCreator.hpp", 19,
                  typeid(::CAP::JetFilterCreator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::JetFilterCreator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::JetFilterCreator) );
      instance.SetNew(&new_CAPcLcLJetFilterCreator);
      instance.SetNewArray(&newArray_CAPcLcLJetFilterCreator);
      instance.SetDelete(&delete_CAPcLcLJetFilterCreator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLJetFilterCreator);
      instance.SetDestructor(&destruct_CAPcLcLJetFilterCreator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::JetFilterCreator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::JetFilterCreator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::JetFilterCreator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
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
template <> atomic_TClass_ptr Manager<CAP::JetFilter>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *Manager<CAP::JetFilter>::Class_Name()
{
   return "CAP::Manager<CAP::JetFilter>";
}

//______________________________________________________________________________
template <> const char *Manager<CAP::JetFilter>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::JetFilter>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int Manager<CAP::JetFilter>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::JetFilter>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *Manager<CAP::JetFilter>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::JetFilter>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *Manager<CAP::JetFilter>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::JetFilter>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr JetFilter::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *JetFilter::Class_Name()
{
   return "CAP::JetFilter";
}

//______________________________________________________________________________
const char *JetFilter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetFilter*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int JetFilter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetFilter*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetFilter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetFilter*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetFilter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetFilter*)nullptr)->GetClass(); }
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
atomic_TClass_ptr JetFilterCreator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *JetFilterCreator::Class_Name()
{
   return "CAP::JetFilterCreator";
}

//______________________________________________________________________________
const char *JetFilterCreator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetFilterCreator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int JetFilterCreator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetFilterCreator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *JetFilterCreator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetFilterCreator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *JetFilterCreator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::JetFilterCreator*)nullptr)->GetClass(); }
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
template <> void Manager<CAP::JetFilter>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Manager<CAP::JetFilter>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Manager<CAP::JetFilter>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Manager<CAP::JetFilter>::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLManagerlECAPcLcLJetFiltergR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Manager<CAP::JetFilter> : new ::CAP::Manager<CAP::JetFilter>;
   }
   static void *newArray_CAPcLcLManagerlECAPcLcLJetFiltergR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Manager<CAP::JetFilter>[nElements] : new ::CAP::Manager<CAP::JetFilter>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLManagerlECAPcLcLJetFiltergR(void *p) {
      delete (static_cast<::CAP::Manager<CAP::JetFilter>*>(p));
   }
   static void deleteArray_CAPcLcLManagerlECAPcLcLJetFiltergR(void *p) {
      delete [] (static_cast<::CAP::Manager<CAP::JetFilter>*>(p));
   }
   static void destruct_CAPcLcLManagerlECAPcLcLJetFiltergR(void *p) {
      typedef ::CAP::Manager<CAP::JetFilter> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Manager<CAP::JetFilter>

namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLFilterlEfastjetcLcLPseudoJetgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Filter<fastjet::PseudoJet> : new ::CAP::Filter<fastjet::PseudoJet>;
   }
   static void *newArray_CAPcLcLFilterlEfastjetcLcLPseudoJetgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Filter<fastjet::PseudoJet>[nElements] : new ::CAP::Filter<fastjet::PseudoJet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLFilterlEfastjetcLcLPseudoJetgR(void *p) {
      delete (static_cast<::CAP::Filter<fastjet::PseudoJet>*>(p));
   }
   static void deleteArray_CAPcLcLFilterlEfastjetcLcLPseudoJetgR(void *p) {
      delete [] (static_cast<::CAP::Filter<fastjet::PseudoJet>*>(p));
   }
   static void destruct_CAPcLcLFilterlEfastjetcLcLPseudoJetgR(void *p) {
      typedef ::CAP::Filter<fastjet::PseudoJet> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Filter<fastjet::PseudoJet>

namespace CAP {
//______________________________________________________________________________
void JetFilter::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::JetFilter.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::JetFilter::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::JetFilter::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLJetFilter(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetFilter : new ::CAP::JetFilter;
   }
   static void *newArray_CAPcLcLJetFilter(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetFilter[nElements] : new ::CAP::JetFilter[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLJetFilter(void *p) {
      delete (static_cast<::CAP::JetFilter*>(p));
   }
   static void deleteArray_CAPcLcLJetFilter(void *p) {
      delete [] (static_cast<::CAP::JetFilter*>(p));
   }
   static void destruct_CAPcLcLJetFilter(void *p) {
      typedef ::CAP::JetFilter current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::JetFilter

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
void JetFilterCreator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::JetFilterCreator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::JetFilterCreator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::JetFilterCreator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLJetFilterCreator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetFilterCreator : new ::CAP::JetFilterCreator;
   }
   static void *newArray_CAPcLcLJetFilterCreator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::JetFilterCreator[nElements] : new ::CAP::JetFilterCreator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLJetFilterCreator(void *p) {
      delete (static_cast<::CAP::JetFilterCreator*>(p));
   }
   static void deleteArray_CAPcLcLJetFilterCreator(void *p) {
      delete [] (static_cast<::CAP::JetFilterCreator*>(p));
   }
   static void destruct_CAPcLcLJetFilterCreator(void *p) {
      typedef ::CAP::JetFilterCreator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::JetFilterCreator

namespace ROOT {
   static TClass *vectorlEboolgR_Dictionary();
   static void vectorlEboolgR_TClassManip(TClass*);
   static void *new_vectorlEboolgR(void *p = nullptr);
   static void *newArray_vectorlEboolgR(Long_t size, void *p);
   static void delete_vectorlEboolgR(void *p);
   static void deleteArray_vectorlEboolgR(void *p);
   static void destruct_vectorlEboolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<bool>*)
   {
      vector<bool> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<bool>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<bool>", -2, "vector", 1813,
                  typeid(vector<bool>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEboolgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<bool>) );
      instance.SetNew(&new_vectorlEboolgR);
      instance.SetNewArray(&newArray_vectorlEboolgR);
      instance.SetDelete(&delete_vectorlEboolgR);
      instance.SetDeleteArray(&deleteArray_vectorlEboolgR);
      instance.SetDestructor(&destruct_vectorlEboolgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<bool> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<bool>","std::__1::vector<bool, std::__1::allocator<bool>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<bool>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEboolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<bool>*>(nullptr))->GetClass();
      vectorlEboolgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEboolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEboolgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<bool> : new vector<bool>;
   }
   static void *newArray_vectorlEboolgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<bool>[nElements] : new vector<bool>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEboolgR(void *p) {
      delete (static_cast<vector<bool>*>(p));
   }
   static void deleteArray_vectorlEboolgR(void *p) {
      delete [] (static_cast<vector<bool>*>(p));
   }
   static void destruct_vectorlEboolgR(void *p) {
      typedef vector<bool> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<bool>

namespace ROOT {
   static TClass *vectorlETStringgR_Dictionary();
   static void vectorlETStringgR_TClassManip(TClass*);
   static void *new_vectorlETStringgR(void *p = nullptr);
   static void *newArray_vectorlETStringgR(Long_t size, void *p);
   static void delete_vectorlETStringgR(void *p);
   static void deleteArray_vectorlETStringgR(void *p);
   static void destruct_vectorlETStringgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TString>*)
   {
      vector<TString> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TString>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TString>", -2, "vector", 387,
                  typeid(vector<TString>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETStringgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TString>) );
      instance.SetNew(&new_vectorlETStringgR);
      instance.SetNewArray(&newArray_vectorlETStringgR);
      instance.SetDelete(&delete_vectorlETStringgR);
      instance.SetDeleteArray(&deleteArray_vectorlETStringgR);
      instance.SetDestructor(&destruct_vectorlETStringgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TString> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TString>","std::__1::vector<TString, std::__1::allocator<TString>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TString>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETStringgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TString>*>(nullptr))->GetClass();
      vectorlETStringgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETStringgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETStringgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TString> : new vector<TString>;
   }
   static void *newArray_vectorlETStringgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TString>[nElements] : new vector<TString>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETStringgR(void *p) {
      delete (static_cast<vector<TString>*>(p));
   }
   static void deleteArray_vectorlETStringgR(void *p) {
      delete [] (static_cast<vector<TString>*>(p));
   }
   static void destruct_vectorlETStringgR(void *p) {
      typedef vector<TString> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TString>

namespace ROOT {
   static TClass *vectorlECAPcLcLJetFiltermUgR_Dictionary();
   static void vectorlECAPcLcLJetFiltermUgR_TClassManip(TClass*);
   static void *new_vectorlECAPcLcLJetFiltermUgR(void *p = nullptr);
   static void *newArray_vectorlECAPcLcLJetFiltermUgR(Long_t size, void *p);
   static void delete_vectorlECAPcLcLJetFiltermUgR(void *p);
   static void deleteArray_vectorlECAPcLcLJetFiltermUgR(void *p);
   static void destruct_vectorlECAPcLcLJetFiltermUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CAP::JetFilter*>*)
   {
      vector<CAP::JetFilter*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CAP::JetFilter*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<CAP::JetFilter*>", -2, "vector", 387,
                  typeid(vector<CAP::JetFilter*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlECAPcLcLJetFiltermUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<CAP::JetFilter*>) );
      instance.SetNew(&new_vectorlECAPcLcLJetFiltermUgR);
      instance.SetNewArray(&newArray_vectorlECAPcLcLJetFiltermUgR);
      instance.SetDelete(&delete_vectorlECAPcLcLJetFiltermUgR);
      instance.SetDeleteArray(&deleteArray_vectorlECAPcLcLJetFiltermUgR);
      instance.SetDestructor(&destruct_vectorlECAPcLcLJetFiltermUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CAP::JetFilter*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<CAP::JetFilter*>","std::__1::vector<CAP::JetFilter*, std::__1::allocator<CAP::JetFilter*>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<CAP::JetFilter*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECAPcLcLJetFiltermUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<CAP::JetFilter*>*>(nullptr))->GetClass();
      vectorlECAPcLcLJetFiltermUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECAPcLcLJetFiltermUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECAPcLcLJetFiltermUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::JetFilter*> : new vector<CAP::JetFilter*>;
   }
   static void *newArray_vectorlECAPcLcLJetFiltermUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::JetFilter*>[nElements] : new vector<CAP::JetFilter*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECAPcLcLJetFiltermUgR(void *p) {
      delete (static_cast<vector<CAP::JetFilter*>*>(p));
   }
   static void deleteArray_vectorlECAPcLcLJetFiltermUgR(void *p) {
      delete [] (static_cast<vector<CAP::JetFilter*>*>(p));
   }
   static void destruct_vectorlECAPcLcLJetFiltermUgR(void *p) {
      typedef vector<CAP::JetFilter*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<CAP::JetFilter*>

namespace ROOT {
   static TClass *vectorlECAPcLcLConditionmUgR_Dictionary();
   static void vectorlECAPcLcLConditionmUgR_TClassManip(TClass*);
   static void *new_vectorlECAPcLcLConditionmUgR(void *p = nullptr);
   static void *newArray_vectorlECAPcLcLConditionmUgR(Long_t size, void *p);
   static void delete_vectorlECAPcLcLConditionmUgR(void *p);
   static void deleteArray_vectorlECAPcLcLConditionmUgR(void *p);
   static void destruct_vectorlECAPcLcLConditionmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CAP::Condition*>*)
   {
      vector<CAP::Condition*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CAP::Condition*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<CAP::Condition*>", -2, "vector", 387,
                  typeid(vector<CAP::Condition*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlECAPcLcLConditionmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<CAP::Condition*>) );
      instance.SetNew(&new_vectorlECAPcLcLConditionmUgR);
      instance.SetNewArray(&newArray_vectorlECAPcLcLConditionmUgR);
      instance.SetDelete(&delete_vectorlECAPcLcLConditionmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlECAPcLcLConditionmUgR);
      instance.SetDestructor(&destruct_vectorlECAPcLcLConditionmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CAP::Condition*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<CAP::Condition*>","std::__1::vector<CAP::Condition*, std::__1::allocator<CAP::Condition*>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<CAP::Condition*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECAPcLcLConditionmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<CAP::Condition*>*>(nullptr))->GetClass();
      vectorlECAPcLcLConditionmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECAPcLcLConditionmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECAPcLcLConditionmUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::Condition*> : new vector<CAP::Condition*>;
   }
   static void *newArray_vectorlECAPcLcLConditionmUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::Condition*>[nElements] : new vector<CAP::Condition*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECAPcLcLConditionmUgR(void *p) {
      delete (static_cast<vector<CAP::Condition*>*>(p));
   }
   static void deleteArray_vectorlECAPcLcLConditionmUgR(void *p) {
      delete [] (static_cast<vector<CAP::Condition*>*>(p));
   }
   static void destruct_vectorlECAPcLcLConditionmUgR(void *p) {
      typedef vector<CAP::Condition*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<CAP::Condition*>

namespace {
  void TriggerDictionaryInitialization_libJets_Impl() {
    static const char* headers[] = {
"JetHistos.hpp",
"JetSingleHistos.hpp",
"JetPairHistos.hpp",
"JetAnalyzer.hpp",
"JetFilter.hpp",
"JetFilterCreator.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Jets/",
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
namespace CAP{class __attribute__((annotate("$clingAutoload$JetFilter.hpp")))  __attribute__((annotate("$clingAutoload$JetAnalyzer.hpp")))  JetFilter;}
namespace CAP{template <class Event> class __attribute__((annotate("$clingAutoload$Event.hpp")))  __attribute__((annotate("$clingAutoload$JetAnalyzer.hpp")))  Manager;
}
namespace fastjet{class __attribute__((annotate("$clingAutoload$fastjet/PseudoJet.hh")))  __attribute__((annotate("$clingAutoload$JetHistos.hpp")))  PseudoJet;}
namespace CAP{template <class T> class __attribute__((annotate("$clingAutoload$Filter.hpp")))  __attribute__((annotate("$clingAutoload$JetAnalyzer.hpp")))  Filter;
}
namespace CAP{class __attribute__((annotate("$clingAutoload$JetAnalyzer.hpp")))  JetAnalyzer;}
namespace CAP{class __attribute__((annotate("$clingAutoload$JetFilterCreator.hpp")))  JetFilterCreator;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libJets dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "JetHistos.hpp"
#include "JetSingleHistos.hpp"
#include "JetPairHistos.hpp"
#include "JetAnalyzer.hpp"
#include "JetFilter.hpp"
#include "JetFilterCreator.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::Filter<PseudoJet>", payloadCode, "@",
"CAP::Filter<fastjet::PseudoJet>", payloadCode, "@",
"CAP::JetAnalyzer", payloadCode, "@",
"CAP::JetFilter", payloadCode, "@",
"CAP::JetFilterCreator", payloadCode, "@",
"CAP::JetHistos", payloadCode, "@",
"CAP::JetPairHistos", payloadCode, "@",
"CAP::JetSingleHistos", payloadCode, "@",
"CAP::Manager<CAP::JetFilter>", payloadCode, "@",
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
