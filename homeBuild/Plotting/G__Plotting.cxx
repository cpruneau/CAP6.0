// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Plotting
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
#include "CanvasGroup.hpp"
#include "CanvasConfiguration.hpp"
#include "DataGraph.hpp"
#include "FunctionGroup.hpp"
#include "GraphConfiguration.hpp"
#include "Plotter.hpp"
#include "LegendConfiguration.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLCanvasConfiguration(void *p = nullptr);
   static void *newArray_CAPcLcLCanvasConfiguration(Long_t size, void *p);
   static void delete_CAPcLcLCanvasConfiguration(void *p);
   static void deleteArray_CAPcLcLCanvasConfiguration(void *p);
   static void destruct_CAPcLcLCanvasConfiguration(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::CanvasConfiguration*)
   {
      ::CAP::CanvasConfiguration *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::CanvasConfiguration >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::CanvasConfiguration", ::CAP::CanvasConfiguration::Class_Version(), "CanvasConfiguration.hpp", 22,
                  typeid(::CAP::CanvasConfiguration), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::CanvasConfiguration::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::CanvasConfiguration) );
      instance.SetNew(&new_CAPcLcLCanvasConfiguration);
      instance.SetNewArray(&newArray_CAPcLcLCanvasConfiguration);
      instance.SetDelete(&delete_CAPcLcLCanvasConfiguration);
      instance.SetDeleteArray(&deleteArray_CAPcLcLCanvasConfiguration);
      instance.SetDestructor(&destruct_CAPcLcLCanvasConfiguration);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::CanvasConfiguration*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::CanvasConfiguration*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::CanvasConfiguration*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLCanvasGroup(void *p = nullptr);
   static void *newArray_CAPcLcLCanvasGroup(Long_t size, void *p);
   static void delete_CAPcLcLCanvasGroup(void *p);
   static void deleteArray_CAPcLcLCanvasGroup(void *p);
   static void destruct_CAPcLcLCanvasGroup(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::CanvasGroup*)
   {
      ::CAP::CanvasGroup *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::CanvasGroup >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::CanvasGroup", ::CAP::CanvasGroup::Class_Version(), "CanvasGroup.hpp", 22,
                  typeid(::CAP::CanvasGroup), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::CanvasGroup::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::CanvasGroup) );
      instance.SetNew(&new_CAPcLcLCanvasGroup);
      instance.SetNewArray(&newArray_CAPcLcLCanvasGroup);
      instance.SetDelete(&delete_CAPcLcLCanvasGroup);
      instance.SetDeleteArray(&deleteArray_CAPcLcLCanvasGroup);
      instance.SetDestructor(&destruct_CAPcLcLCanvasGroup);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::CanvasGroup*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::CanvasGroup*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::CanvasGroup*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLGraphConfiguration(void *p = nullptr);
   static void *newArray_CAPcLcLGraphConfiguration(Long_t size, void *p);
   static void delete_CAPcLcLGraphConfiguration(void *p);
   static void deleteArray_CAPcLcLGraphConfiguration(void *p);
   static void destruct_CAPcLcLGraphConfiguration(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::GraphConfiguration*)
   {
      ::CAP::GraphConfiguration *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::GraphConfiguration >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::GraphConfiguration", ::CAP::GraphConfiguration::Class_Version(), "GraphConfiguration.hpp", 32,
                  typeid(::CAP::GraphConfiguration), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::GraphConfiguration::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::GraphConfiguration) );
      instance.SetNew(&new_CAPcLcLGraphConfiguration);
      instance.SetNewArray(&newArray_CAPcLcLGraphConfiguration);
      instance.SetDelete(&delete_CAPcLcLGraphConfiguration);
      instance.SetDeleteArray(&deleteArray_CAPcLcLGraphConfiguration);
      instance.SetDestructor(&destruct_CAPcLcLGraphConfiguration);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::GraphConfiguration*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::GraphConfiguration*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::GraphConfiguration*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_CAPcLcLDataGraph(void *p);
   static void deleteArray_CAPcLcLDataGraph(void *p);
   static void destruct_CAPcLcLDataGraph(void *p);
   static void directoryAutoAdd_CAPcLcLDataGraph(void *obj, TDirectory *dir);
   static Long64_t merge_CAPcLcLDataGraph(void *obj, TCollection *coll,TFileMergeInfo *info);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::DataGraph*)
   {
      ::CAP::DataGraph *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::DataGraph >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::DataGraph", ::CAP::DataGraph::Class_Version(), "DataGraph.hpp", 34,
                  typeid(::CAP::DataGraph), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::DataGraph::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::DataGraph) );
      instance.SetDelete(&delete_CAPcLcLDataGraph);
      instance.SetDeleteArray(&deleteArray_CAPcLcLDataGraph);
      instance.SetDestructor(&destruct_CAPcLcLDataGraph);
      instance.SetDirectoryAutoAdd(&directoryAutoAdd_CAPcLcLDataGraph);
      instance.SetMerge(&merge_CAPcLcLDataGraph);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::DataGraph*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::DataGraph*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::DataGraph*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLFunctionGroup(void *p = nullptr);
   static void *newArray_CAPcLcLFunctionGroup(Long_t size, void *p);
   static void delete_CAPcLcLFunctionGroup(void *p);
   static void deleteArray_CAPcLcLFunctionGroup(void *p);
   static void destruct_CAPcLcLFunctionGroup(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::FunctionGroup*)
   {
      ::CAP::FunctionGroup *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::FunctionGroup >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::FunctionGroup", ::CAP::FunctionGroup::Class_Version(), "FunctionGroup.hpp", 41,
                  typeid(::CAP::FunctionGroup), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::FunctionGroup::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::FunctionGroup) );
      instance.SetNew(&new_CAPcLcLFunctionGroup);
      instance.SetNewArray(&newArray_CAPcLcLFunctionGroup);
      instance.SetDelete(&delete_CAPcLcLFunctionGroup);
      instance.SetDeleteArray(&deleteArray_CAPcLcLFunctionGroup);
      instance.SetDestructor(&destruct_CAPcLcLFunctionGroup);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::FunctionGroup*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::FunctionGroup*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::FunctionGroup*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLLegendConfiguration(void *p = nullptr);
   static void *newArray_CAPcLcLLegendConfiguration(Long_t size, void *p);
   static void delete_CAPcLcLLegendConfiguration(void *p);
   static void deleteArray_CAPcLcLLegendConfiguration(void *p);
   static void destruct_CAPcLcLLegendConfiguration(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::LegendConfiguration*)
   {
      ::CAP::LegendConfiguration *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::LegendConfiguration >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::LegendConfiguration", ::CAP::LegendConfiguration::Class_Version(), "LegendConfiguration.hpp", 28,
                  typeid(::CAP::LegendConfiguration), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::LegendConfiguration::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::LegendConfiguration) );
      instance.SetNew(&new_CAPcLcLLegendConfiguration);
      instance.SetNewArray(&newArray_CAPcLcLLegendConfiguration);
      instance.SetDelete(&delete_CAPcLcLLegendConfiguration);
      instance.SetDeleteArray(&deleteArray_CAPcLcLLegendConfiguration);
      instance.SetDestructor(&destruct_CAPcLcLLegendConfiguration);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::LegendConfiguration*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::LegendConfiguration*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::LegendConfiguration*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLPlotter(void *p = nullptr);
   static void *newArray_CAPcLcLPlotter(Long_t size, void *p);
   static void delete_CAPcLcLPlotter(void *p);
   static void deleteArray_CAPcLcLPlotter(void *p);
   static void destruct_CAPcLcLPlotter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Plotter*)
   {
      ::CAP::Plotter *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Plotter >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Plotter", ::CAP::Plotter::Class_Version(), "Plotter.hpp", 32,
                  typeid(::CAP::Plotter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::Plotter::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Plotter) );
      instance.SetNew(&new_CAPcLcLPlotter);
      instance.SetNewArray(&newArray_CAPcLcLPlotter);
      instance.SetDelete(&delete_CAPcLcLPlotter);
      instance.SetDeleteArray(&deleteArray_CAPcLcLPlotter);
      instance.SetDestructor(&destruct_CAPcLcLPlotter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Plotter*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Plotter*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Plotter*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr CanvasConfiguration::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *CanvasConfiguration::Class_Name()
{
   return "CAP::CanvasConfiguration";
}

//______________________________________________________________________________
const char *CanvasConfiguration::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::CanvasConfiguration*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int CanvasConfiguration::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::CanvasConfiguration*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CanvasConfiguration::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::CanvasConfiguration*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CanvasConfiguration::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::CanvasConfiguration*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr CanvasGroup::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *CanvasGroup::Class_Name()
{
   return "CAP::CanvasGroup";
}

//______________________________________________________________________________
const char *CanvasGroup::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::CanvasGroup*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int CanvasGroup::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::CanvasGroup*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CanvasGroup::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::CanvasGroup*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CanvasGroup::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::CanvasGroup*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr GraphConfiguration::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *GraphConfiguration::Class_Name()
{
   return "CAP::GraphConfiguration";
}

//______________________________________________________________________________
const char *GraphConfiguration::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::GraphConfiguration*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int GraphConfiguration::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::GraphConfiguration*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GraphConfiguration::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::GraphConfiguration*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GraphConfiguration::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::GraphConfiguration*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr DataGraph::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *DataGraph::Class_Name()
{
   return "CAP::DataGraph";
}

//______________________________________________________________________________
const char *DataGraph::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::DataGraph*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int DataGraph::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::DataGraph*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *DataGraph::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::DataGraph*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *DataGraph::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::DataGraph*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr FunctionGroup::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *FunctionGroup::Class_Name()
{
   return "CAP::FunctionGroup";
}

//______________________________________________________________________________
const char *FunctionGroup::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::FunctionGroup*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int FunctionGroup::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::FunctionGroup*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *FunctionGroup::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::FunctionGroup*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *FunctionGroup::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::FunctionGroup*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr LegendConfiguration::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *LegendConfiguration::Class_Name()
{
   return "CAP::LegendConfiguration";
}

//______________________________________________________________________________
const char *LegendConfiguration::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::LegendConfiguration*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int LegendConfiguration::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::LegendConfiguration*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *LegendConfiguration::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::LegendConfiguration*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *LegendConfiguration::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::LegendConfiguration*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr Plotter::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Plotter::Class_Name()
{
   return "CAP::Plotter";
}

//______________________________________________________________________________
const char *Plotter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Plotter*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Plotter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Plotter*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Plotter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Plotter*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Plotter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Plotter*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void CanvasConfiguration::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::CanvasConfiguration.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::CanvasConfiguration::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::CanvasConfiguration::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLCanvasConfiguration(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::CanvasConfiguration : new ::CAP::CanvasConfiguration;
   }
   static void *newArray_CAPcLcLCanvasConfiguration(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::CanvasConfiguration[nElements] : new ::CAP::CanvasConfiguration[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLCanvasConfiguration(void *p) {
      delete (static_cast<::CAP::CanvasConfiguration*>(p));
   }
   static void deleteArray_CAPcLcLCanvasConfiguration(void *p) {
      delete [] (static_cast<::CAP::CanvasConfiguration*>(p));
   }
   static void destruct_CAPcLcLCanvasConfiguration(void *p) {
      typedef ::CAP::CanvasConfiguration current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::CanvasConfiguration

namespace CAP {
//______________________________________________________________________________
void CanvasGroup::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::CanvasGroup.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::CanvasGroup::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::CanvasGroup::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLCanvasGroup(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::CanvasGroup : new ::CAP::CanvasGroup;
   }
   static void *newArray_CAPcLcLCanvasGroup(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::CanvasGroup[nElements] : new ::CAP::CanvasGroup[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLCanvasGroup(void *p) {
      delete (static_cast<::CAP::CanvasGroup*>(p));
   }
   static void deleteArray_CAPcLcLCanvasGroup(void *p) {
      delete [] (static_cast<::CAP::CanvasGroup*>(p));
   }
   static void destruct_CAPcLcLCanvasGroup(void *p) {
      typedef ::CAP::CanvasGroup current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::CanvasGroup

namespace CAP {
//______________________________________________________________________________
void GraphConfiguration::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::GraphConfiguration.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::GraphConfiguration::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::GraphConfiguration::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLGraphConfiguration(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::GraphConfiguration : new ::CAP::GraphConfiguration;
   }
   static void *newArray_CAPcLcLGraphConfiguration(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::GraphConfiguration[nElements] : new ::CAP::GraphConfiguration[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLGraphConfiguration(void *p) {
      delete (static_cast<::CAP::GraphConfiguration*>(p));
   }
   static void deleteArray_CAPcLcLGraphConfiguration(void *p) {
      delete [] (static_cast<::CAP::GraphConfiguration*>(p));
   }
   static void destruct_CAPcLcLGraphConfiguration(void *p) {
      typedef ::CAP::GraphConfiguration current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::GraphConfiguration

namespace CAP {
//______________________________________________________________________________
void DataGraph::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::DataGraph.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::DataGraph::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::DataGraph::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrapper around operator delete
   static void delete_CAPcLcLDataGraph(void *p) {
      delete (static_cast<::CAP::DataGraph*>(p));
   }
   static void deleteArray_CAPcLcLDataGraph(void *p) {
      delete [] (static_cast<::CAP::DataGraph*>(p));
   }
   static void destruct_CAPcLcLDataGraph(void *p) {
      typedef ::CAP::DataGraph current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
   // Wrapper around the directory auto add.
   static void directoryAutoAdd_CAPcLcLDataGraph(void *p, TDirectory *dir) {
      ((::CAP::DataGraph*)p)->DirectoryAutoAdd(dir);
   }
   // Wrapper around the merge function.
   static Long64_t  merge_CAPcLcLDataGraph(void *obj,TCollection *coll,TFileMergeInfo *) {
      return ((::CAP::DataGraph*)obj)->Merge(coll);
   }
} // end of namespace ROOT for class ::CAP::DataGraph

namespace CAP {
//______________________________________________________________________________
void FunctionGroup::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::FunctionGroup.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::FunctionGroup::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::FunctionGroup::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLFunctionGroup(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::FunctionGroup : new ::CAP::FunctionGroup;
   }
   static void *newArray_CAPcLcLFunctionGroup(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::FunctionGroup[nElements] : new ::CAP::FunctionGroup[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLFunctionGroup(void *p) {
      delete (static_cast<::CAP::FunctionGroup*>(p));
   }
   static void deleteArray_CAPcLcLFunctionGroup(void *p) {
      delete [] (static_cast<::CAP::FunctionGroup*>(p));
   }
   static void destruct_CAPcLcLFunctionGroup(void *p) {
      typedef ::CAP::FunctionGroup current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::FunctionGroup

namespace CAP {
//______________________________________________________________________________
void LegendConfiguration::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::LegendConfiguration.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::LegendConfiguration::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::LegendConfiguration::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLLegendConfiguration(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::LegendConfiguration : new ::CAP::LegendConfiguration;
   }
   static void *newArray_CAPcLcLLegendConfiguration(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::LegendConfiguration[nElements] : new ::CAP::LegendConfiguration[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLLegendConfiguration(void *p) {
      delete (static_cast<::CAP::LegendConfiguration*>(p));
   }
   static void deleteArray_CAPcLcLLegendConfiguration(void *p) {
      delete [] (static_cast<::CAP::LegendConfiguration*>(p));
   }
   static void destruct_CAPcLcLLegendConfiguration(void *p) {
      typedef ::CAP::LegendConfiguration current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::LegendConfiguration

namespace CAP {
//______________________________________________________________________________
void Plotter::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Plotter.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Plotter::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Plotter::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLPlotter(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Plotter : new ::CAP::Plotter;
   }
   static void *newArray_CAPcLcLPlotter(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Plotter[nElements] : new ::CAP::Plotter[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLPlotter(void *p) {
      delete (static_cast<::CAP::Plotter*>(p));
   }
   static void deleteArray_CAPcLcLPlotter(void *p) {
      delete [] (static_cast<::CAP::Plotter*>(p));
   }
   static void destruct_CAPcLcLPlotter(void *p) {
      typedef ::CAP::Plotter current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Plotter

namespace {
  void TriggerDictionaryInitialization_libPlotting_Impl() {
    static const char* headers[] = {
"CanvasGroup.hpp",
"CanvasConfiguration.hpp",
"DataGraph.hpp",
"FunctionGroup.hpp",
"GraphConfiguration.hpp",
"Plotter.hpp",
"LegendConfiguration.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/Plotting/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libPlotting dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$CanvasConfiguration.hpp")))  __attribute__((annotate("$clingAutoload$CanvasGroup.hpp")))  CanvasConfiguration;}
namespace CAP{class __attribute__((annotate("$clingAutoload$CanvasGroup.hpp")))  CanvasGroup;}
namespace CAP{class __attribute__((annotate("$clingAutoload$GraphConfiguration.hpp")))  __attribute__((annotate("$clingAutoload$DataGraph.hpp")))  GraphConfiguration;}
namespace CAP{class __attribute__((annotate("$clingAutoload$DataGraph.hpp")))  DataGraph;}
namespace CAP{class __attribute__((annotate("$clingAutoload$FunctionGroup.hpp")))  FunctionGroup;}
namespace CAP{class __attribute__((annotate("$clingAutoload$LegendConfiguration.hpp")))  __attribute__((annotate("$clingAutoload$Plotter.hpp")))  LegendConfiguration;}
namespace CAP{class __attribute__((annotate("$clingAutoload$Plotter.hpp")))  Plotter;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libPlotting dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "CanvasGroup.hpp"
#include "CanvasConfiguration.hpp"
#include "DataGraph.hpp"
#include "FunctionGroup.hpp"
#include "GraphConfiguration.hpp"
#include "Plotter.hpp"
#include "LegendConfiguration.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::CanvasConfiguration", payloadCode, "@",
"CAP::CanvasGroup", payloadCode, "@",
"CAP::DataGraph", payloadCode, "@",
"CAP::FunctionGroup", payloadCode, "@",
"CAP::GraphConfiguration", payloadCode, "@",
"CAP::LegendConfiguration", payloadCode, "@",
"CAP::Plotter", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libPlotting",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libPlotting_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libPlotting_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libPlotting() {
  TriggerDictionaryInitialization_libPlotting_Impl();
}
