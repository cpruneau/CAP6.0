// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Spherocity
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
#include "SpherocityHistos.hpp"
#include "SpherocityAnalyzer.hpp"
#include "SpherocityCalculator.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLSpherocityHistos(void *p = nullptr);
   static void *newArray_CAPcLcLSpherocityHistos(Long_t size, void *p);
   static void delete_CAPcLcLSpherocityHistos(void *p);
   static void deleteArray_CAPcLcLSpherocityHistos(void *p);
   static void destruct_CAPcLcLSpherocityHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::SpherocityHistos*)
   {
      ::CAP::SpherocityHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::SpherocityHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::SpherocityHistos", ::CAP::SpherocityHistos::Class_Version(), "SpherocityHistos.hpp", 20,
                  typeid(::CAP::SpherocityHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::SpherocityHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::SpherocityHistos) );
      instance.SetNew(&new_CAPcLcLSpherocityHistos);
      instance.SetNewArray(&newArray_CAPcLcLSpherocityHistos);
      instance.SetDelete(&delete_CAPcLcLSpherocityHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLSpherocityHistos);
      instance.SetDestructor(&destruct_CAPcLcLSpherocityHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::SpherocityHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::SpherocityHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::SpherocityHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLSpherocityAnalyzer(void *p = nullptr);
   static void *newArray_CAPcLcLSpherocityAnalyzer(Long_t size, void *p);
   static void delete_CAPcLcLSpherocityAnalyzer(void *p);
   static void deleteArray_CAPcLcLSpherocityAnalyzer(void *p);
   static void destruct_CAPcLcLSpherocityAnalyzer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::SpherocityAnalyzer*)
   {
      ::CAP::SpherocityAnalyzer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::SpherocityAnalyzer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::SpherocityAnalyzer", ::CAP::SpherocityAnalyzer::Class_Version(), "SpherocityAnalyzer.hpp", 24,
                  typeid(::CAP::SpherocityAnalyzer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::SpherocityAnalyzer::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::SpherocityAnalyzer) );
      instance.SetNew(&new_CAPcLcLSpherocityAnalyzer);
      instance.SetNewArray(&newArray_CAPcLcLSpherocityAnalyzer);
      instance.SetDelete(&delete_CAPcLcLSpherocityAnalyzer);
      instance.SetDeleteArray(&deleteArray_CAPcLcLSpherocityAnalyzer);
      instance.SetDestructor(&destruct_CAPcLcLSpherocityAnalyzer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::SpherocityAnalyzer*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::SpherocityAnalyzer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::SpherocityAnalyzer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLSpherocityCalculator(void *p = nullptr);
   static void *newArray_CAPcLcLSpherocityCalculator(Long_t size, void *p);
   static void delete_CAPcLcLSpherocityCalculator(void *p);
   static void deleteArray_CAPcLcLSpherocityCalculator(void *p);
   static void destruct_CAPcLcLSpherocityCalculator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::SpherocityCalculator*)
   {
      ::CAP::SpherocityCalculator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::SpherocityCalculator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::SpherocityCalculator", ::CAP::SpherocityCalculator::Class_Version(), "SpherocityCalculator.hpp", 23,
                  typeid(::CAP::SpherocityCalculator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::SpherocityCalculator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::SpherocityCalculator) );
      instance.SetNew(&new_CAPcLcLSpherocityCalculator);
      instance.SetNewArray(&newArray_CAPcLcLSpherocityCalculator);
      instance.SetDelete(&delete_CAPcLcLSpherocityCalculator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLSpherocityCalculator);
      instance.SetDestructor(&destruct_CAPcLcLSpherocityCalculator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::SpherocityCalculator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::SpherocityCalculator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::SpherocityCalculator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr SpherocityHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *SpherocityHistos::Class_Name()
{
   return "CAP::SpherocityHistos";
}

//______________________________________________________________________________
const char *SpherocityHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::SpherocityHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int SpherocityHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::SpherocityHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SpherocityHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::SpherocityHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SpherocityHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::SpherocityHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr SpherocityAnalyzer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *SpherocityAnalyzer::Class_Name()
{
   return "CAP::SpherocityAnalyzer";
}

//______________________________________________________________________________
const char *SpherocityAnalyzer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::SpherocityAnalyzer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int SpherocityAnalyzer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::SpherocityAnalyzer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SpherocityAnalyzer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::SpherocityAnalyzer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SpherocityAnalyzer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::SpherocityAnalyzer*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr SpherocityCalculator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *SpherocityCalculator::Class_Name()
{
   return "CAP::SpherocityCalculator";
}

//______________________________________________________________________________
const char *SpherocityCalculator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::SpherocityCalculator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int SpherocityCalculator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::SpherocityCalculator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SpherocityCalculator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::SpherocityCalculator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SpherocityCalculator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::SpherocityCalculator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void SpherocityHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::SpherocityHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::SpherocityHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::SpherocityHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLSpherocityHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::SpherocityHistos : new ::CAP::SpherocityHistos;
   }
   static void *newArray_CAPcLcLSpherocityHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::SpherocityHistos[nElements] : new ::CAP::SpherocityHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLSpherocityHistos(void *p) {
      delete (static_cast<::CAP::SpherocityHistos*>(p));
   }
   static void deleteArray_CAPcLcLSpherocityHistos(void *p) {
      delete [] (static_cast<::CAP::SpherocityHistos*>(p));
   }
   static void destruct_CAPcLcLSpherocityHistos(void *p) {
      typedef ::CAP::SpherocityHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::SpherocityHistos

namespace CAP {
//______________________________________________________________________________
void SpherocityAnalyzer::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::SpherocityAnalyzer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::SpherocityAnalyzer::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::SpherocityAnalyzer::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLSpherocityAnalyzer(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::SpherocityAnalyzer : new ::CAP::SpherocityAnalyzer;
   }
   static void *newArray_CAPcLcLSpherocityAnalyzer(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::SpherocityAnalyzer[nElements] : new ::CAP::SpherocityAnalyzer[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLSpherocityAnalyzer(void *p) {
      delete (static_cast<::CAP::SpherocityAnalyzer*>(p));
   }
   static void deleteArray_CAPcLcLSpherocityAnalyzer(void *p) {
      delete [] (static_cast<::CAP::SpherocityAnalyzer*>(p));
   }
   static void destruct_CAPcLcLSpherocityAnalyzer(void *p) {
      typedef ::CAP::SpherocityAnalyzer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::SpherocityAnalyzer

namespace CAP {
//______________________________________________________________________________
void SpherocityCalculator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::SpherocityCalculator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::SpherocityCalculator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::SpherocityCalculator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLSpherocityCalculator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::SpherocityCalculator : new ::CAP::SpherocityCalculator;
   }
   static void *newArray_CAPcLcLSpherocityCalculator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::SpherocityCalculator[nElements] : new ::CAP::SpherocityCalculator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLSpherocityCalculator(void *p) {
      delete (static_cast<::CAP::SpherocityCalculator*>(p));
   }
   static void deleteArray_CAPcLcLSpherocityCalculator(void *p) {
      delete [] (static_cast<::CAP::SpherocityCalculator*>(p));
   }
   static void destruct_CAPcLcLSpherocityCalculator(void *p) {
      typedef ::CAP::SpherocityCalculator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::SpherocityCalculator

namespace ROOT {
   static TClass *vectorlETH2mUgR_Dictionary();
   static void vectorlETH2mUgR_TClassManip(TClass*);
   static void *new_vectorlETH2mUgR(void *p = nullptr);
   static void *newArray_vectorlETH2mUgR(Long_t size, void *p);
   static void delete_vectorlETH2mUgR(void *p);
   static void deleteArray_vectorlETH2mUgR(void *p);
   static void destruct_vectorlETH2mUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TH2*>*)
   {
      vector<TH2*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TH2*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TH2*>", -2, "vector", 383,
                  typeid(vector<TH2*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETH2mUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TH2*>) );
      instance.SetNew(&new_vectorlETH2mUgR);
      instance.SetNewArray(&newArray_vectorlETH2mUgR);
      instance.SetDelete(&delete_vectorlETH2mUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETH2mUgR);
      instance.SetDestructor(&destruct_vectorlETH2mUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TH2*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TH2*>","std::__1::vector<TH2*, std::__1::allocator<TH2*>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TH2*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETH2mUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TH2*>*>(nullptr))->GetClass();
      vectorlETH2mUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETH2mUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETH2mUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TH2*> : new vector<TH2*>;
   }
   static void *newArray_vectorlETH2mUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TH2*>[nElements] : new vector<TH2*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETH2mUgR(void *p) {
      delete (static_cast<vector<TH2*>*>(p));
   }
   static void deleteArray_vectorlETH2mUgR(void *p) {
      delete [] (static_cast<vector<TH2*>*>(p));
   }
   static void destruct_vectorlETH2mUgR(void *p) {
      typedef vector<TH2*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TH2*>

namespace ROOT {
   static TClass *vectorlETH1mUgR_Dictionary();
   static void vectorlETH1mUgR_TClassManip(TClass*);
   static void *new_vectorlETH1mUgR(void *p = nullptr);
   static void *newArray_vectorlETH1mUgR(Long_t size, void *p);
   static void delete_vectorlETH1mUgR(void *p);
   static void deleteArray_vectorlETH1mUgR(void *p);
   static void destruct_vectorlETH1mUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TH1*>*)
   {
      vector<TH1*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TH1*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TH1*>", -2, "vector", 383,
                  typeid(vector<TH1*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETH1mUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TH1*>) );
      instance.SetNew(&new_vectorlETH1mUgR);
      instance.SetNewArray(&newArray_vectorlETH1mUgR);
      instance.SetDelete(&delete_vectorlETH1mUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETH1mUgR);
      instance.SetDestructor(&destruct_vectorlETH1mUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TH1*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<TH1*>","std::__1::vector<TH1*, std::__1::allocator<TH1*>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<TH1*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETH1mUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<TH1*>*>(nullptr))->GetClass();
      vectorlETH1mUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETH1mUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETH1mUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TH1*> : new vector<TH1*>;
   }
   static void *newArray_vectorlETH1mUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<TH1*>[nElements] : new vector<TH1*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETH1mUgR(void *p) {
      delete (static_cast<vector<TH1*>*>(p));
   }
   static void deleteArray_vectorlETH1mUgR(void *p) {
      delete [] (static_cast<vector<TH1*>*>(p));
   }
   static void destruct_vectorlETH1mUgR(void *p) {
      typedef vector<TH1*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<TH1*>

namespace ROOT {
   static TClass *vectorlECAPcLcLParticleFiltermUgR_Dictionary();
   static void vectorlECAPcLcLParticleFiltermUgR_TClassManip(TClass*);
   static void *new_vectorlECAPcLcLParticleFiltermUgR(void *p = nullptr);
   static void *newArray_vectorlECAPcLcLParticleFiltermUgR(Long_t size, void *p);
   static void delete_vectorlECAPcLcLParticleFiltermUgR(void *p);
   static void deleteArray_vectorlECAPcLcLParticleFiltermUgR(void *p);
   static void destruct_vectorlECAPcLcLParticleFiltermUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CAP::ParticleFilter*>*)
   {
      vector<CAP::ParticleFilter*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CAP::ParticleFilter*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<CAP::ParticleFilter*>", -2, "vector", 383,
                  typeid(vector<CAP::ParticleFilter*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlECAPcLcLParticleFiltermUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<CAP::ParticleFilter*>) );
      instance.SetNew(&new_vectorlECAPcLcLParticleFiltermUgR);
      instance.SetNewArray(&newArray_vectorlECAPcLcLParticleFiltermUgR);
      instance.SetDelete(&delete_vectorlECAPcLcLParticleFiltermUgR);
      instance.SetDeleteArray(&deleteArray_vectorlECAPcLcLParticleFiltermUgR);
      instance.SetDestructor(&destruct_vectorlECAPcLcLParticleFiltermUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CAP::ParticleFilter*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<CAP::ParticleFilter*>","std::__1::vector<CAP::ParticleFilter*, std::__1::allocator<CAP::ParticleFilter*>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<CAP::ParticleFilter*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECAPcLcLParticleFiltermUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<CAP::ParticleFilter*>*>(nullptr))->GetClass();
      vectorlECAPcLcLParticleFiltermUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECAPcLcLParticleFiltermUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECAPcLcLParticleFiltermUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::ParticleFilter*> : new vector<CAP::ParticleFilter*>;
   }
   static void *newArray_vectorlECAPcLcLParticleFiltermUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::ParticleFilter*>[nElements] : new vector<CAP::ParticleFilter*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECAPcLcLParticleFiltermUgR(void *p) {
      delete (static_cast<vector<CAP::ParticleFilter*>*>(p));
   }
   static void deleteArray_vectorlECAPcLcLParticleFiltermUgR(void *p) {
      delete [] (static_cast<vector<CAP::ParticleFilter*>*>(p));
   }
   static void destruct_vectorlECAPcLcLParticleFiltermUgR(void *p) {
      typedef vector<CAP::ParticleFilter*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<CAP::ParticleFilter*>

namespace {
  void TriggerDictionaryInitialization_libSpherocity_Impl() {
    static const char* headers[] = {
"SpherocityHistos.hpp",
"SpherocityAnalyzer.hpp",
"SpherocityCalculator.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP6.0/laptop/Spherocity/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libSpherocity dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$SpherocityHistos.hpp")))  SpherocityHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$SpherocityAnalyzer.hpp")))  SpherocityAnalyzer;}
namespace CAP{class __attribute__((annotate("$clingAutoload$SpherocityCalculator.hpp")))  SpherocityCalculator;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libSpherocity dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "SpherocityHistos.hpp"
#include "SpherocityAnalyzer.hpp"
#include "SpherocityCalculator.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::SpherocityAnalyzer", payloadCode, "@",
"CAP::SpherocityCalculator", payloadCode, "@",
"CAP::SpherocityHistos", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libSpherocity",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libSpherocity_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libSpherocity_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libSpherocity() {
  TriggerDictionaryInitialization_libSpherocity_Impl();
}
