// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Performance
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
#include "MeasurementSimulator.hpp"
#include "ParticleSimulator.hpp"
#include "PerformanceAnalyzer.hpp"
#include "ParticlePerformanceHistos.hpp"
#include "ClosureCalculator.hpp"
#include "ClosureIterator.hpp"
#include "EventPlaneRandomizerTask.hpp"
#include "EventVertexRandomizerTask.hpp"
#include "ResolutionFunction.hpp"
#include "EfficiencyFunction.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLParticleSimulator(void *p = nullptr);
   static void *newArray_CAPcLcLParticleSimulator(Long_t size, void *p);
   static void delete_CAPcLcLParticleSimulator(void *p);
   static void deleteArray_CAPcLcLParticleSimulator(void *p);
   static void destruct_CAPcLcLParticleSimulator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleSimulator*)
   {
      ::CAP::ParticleSimulator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleSimulator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleSimulator", ::CAP::ParticleSimulator::Class_Version(), "ParticleSimulator.hpp", 31,
                  typeid(::CAP::ParticleSimulator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleSimulator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleSimulator) );
      instance.SetNew(&new_CAPcLcLParticleSimulator);
      instance.SetNewArray(&newArray_CAPcLcLParticleSimulator);
      instance.SetDelete(&delete_CAPcLcLParticleSimulator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleSimulator);
      instance.SetDestructor(&destruct_CAPcLcLParticleSimulator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleSimulator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleSimulator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleSimulator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLMeasurementSimulator(void *p = nullptr);
   static void *newArray_CAPcLcLMeasurementSimulator(Long_t size, void *p);
   static void delete_CAPcLcLMeasurementSimulator(void *p);
   static void deleteArray_CAPcLcLMeasurementSimulator(void *p);
   static void destruct_CAPcLcLMeasurementSimulator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::MeasurementSimulator*)
   {
      ::CAP::MeasurementSimulator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::MeasurementSimulator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::MeasurementSimulator", ::CAP::MeasurementSimulator::Class_Version(), "MeasurementSimulator.hpp", 38,
                  typeid(::CAP::MeasurementSimulator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::MeasurementSimulator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::MeasurementSimulator) );
      instance.SetNew(&new_CAPcLcLMeasurementSimulator);
      instance.SetNewArray(&newArray_CAPcLcLMeasurementSimulator);
      instance.SetDelete(&delete_CAPcLcLMeasurementSimulator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLMeasurementSimulator);
      instance.SetDestructor(&destruct_CAPcLcLMeasurementSimulator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::MeasurementSimulator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::MeasurementSimulator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::MeasurementSimulator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticlePerformanceHistos(void *p = nullptr);
   static void *newArray_CAPcLcLParticlePerformanceHistos(Long_t size, void *p);
   static void delete_CAPcLcLParticlePerformanceHistos(void *p);
   static void deleteArray_CAPcLcLParticlePerformanceHistos(void *p);
   static void destruct_CAPcLcLParticlePerformanceHistos(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticlePerformanceHistos*)
   {
      ::CAP::ParticlePerformanceHistos *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticlePerformanceHistos >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticlePerformanceHistos", ::CAP::ParticlePerformanceHistos::Class_Version(), "ParticlePerformanceHistos.hpp", 22,
                  typeid(::CAP::ParticlePerformanceHistos), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticlePerformanceHistos::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticlePerformanceHistos) );
      instance.SetNew(&new_CAPcLcLParticlePerformanceHistos);
      instance.SetNewArray(&newArray_CAPcLcLParticlePerformanceHistos);
      instance.SetDelete(&delete_CAPcLcLParticlePerformanceHistos);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticlePerformanceHistos);
      instance.SetDestructor(&destruct_CAPcLcLParticlePerformanceHistos);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticlePerformanceHistos*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticlePerformanceHistos*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticlePerformanceHistos*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLPerformanceAnalyzer(void *p = nullptr);
   static void *newArray_CAPcLcLPerformanceAnalyzer(Long_t size, void *p);
   static void delete_CAPcLcLPerformanceAnalyzer(void *p);
   static void deleteArray_CAPcLcLPerformanceAnalyzer(void *p);
   static void destruct_CAPcLcLPerformanceAnalyzer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::PerformanceAnalyzer*)
   {
      ::CAP::PerformanceAnalyzer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::PerformanceAnalyzer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::PerformanceAnalyzer", ::CAP::PerformanceAnalyzer::Class_Version(), "PerformanceAnalyzer.hpp", 59,
                  typeid(::CAP::PerformanceAnalyzer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::PerformanceAnalyzer::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::PerformanceAnalyzer) );
      instance.SetNew(&new_CAPcLcLPerformanceAnalyzer);
      instance.SetNewArray(&newArray_CAPcLcLPerformanceAnalyzer);
      instance.SetDelete(&delete_CAPcLcLPerformanceAnalyzer);
      instance.SetDeleteArray(&deleteArray_CAPcLcLPerformanceAnalyzer);
      instance.SetDestructor(&destruct_CAPcLcLPerformanceAnalyzer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::PerformanceAnalyzer*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::PerformanceAnalyzer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::PerformanceAnalyzer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLClosureCalculator(void *p = nullptr);
   static void *newArray_CAPcLcLClosureCalculator(Long_t size, void *p);
   static void delete_CAPcLcLClosureCalculator(void *p);
   static void deleteArray_CAPcLcLClosureCalculator(void *p);
   static void destruct_CAPcLcLClosureCalculator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ClosureCalculator*)
   {
      ::CAP::ClosureCalculator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ClosureCalculator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ClosureCalculator", ::CAP::ClosureCalculator::Class_Version(), "ClosureCalculator.hpp", 20,
                  typeid(::CAP::ClosureCalculator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ClosureCalculator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ClosureCalculator) );
      instance.SetNew(&new_CAPcLcLClosureCalculator);
      instance.SetNewArray(&newArray_CAPcLcLClosureCalculator);
      instance.SetDelete(&delete_CAPcLcLClosureCalculator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLClosureCalculator);
      instance.SetDestructor(&destruct_CAPcLcLClosureCalculator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ClosureCalculator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ClosureCalculator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ClosureCalculator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLClosureIterator(void *p = nullptr);
   static void *newArray_CAPcLcLClosureIterator(Long_t size, void *p);
   static void delete_CAPcLcLClosureIterator(void *p);
   static void deleteArray_CAPcLcLClosureIterator(void *p);
   static void destruct_CAPcLcLClosureIterator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ClosureIterator*)
   {
      ::CAP::ClosureIterator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ClosureIterator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ClosureIterator", ::CAP::ClosureIterator::Class_Version(), "ClosureIterator.hpp", 22,
                  typeid(::CAP::ClosureIterator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ClosureIterator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ClosureIterator) );
      instance.SetNew(&new_CAPcLcLClosureIterator);
      instance.SetNewArray(&newArray_CAPcLcLClosureIterator);
      instance.SetDelete(&delete_CAPcLcLClosureIterator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLClosureIterator);
      instance.SetDestructor(&destruct_CAPcLcLClosureIterator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ClosureIterator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ClosureIterator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ClosureIterator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLEventPlaneRandomizerTask(void *p = nullptr);
   static void *newArray_CAPcLcLEventPlaneRandomizerTask(Long_t size, void *p);
   static void delete_CAPcLcLEventPlaneRandomizerTask(void *p);
   static void deleteArray_CAPcLcLEventPlaneRandomizerTask(void *p);
   static void destruct_CAPcLcLEventPlaneRandomizerTask(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::EventPlaneRandomizerTask*)
   {
      ::CAP::EventPlaneRandomizerTask *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::EventPlaneRandomizerTask >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::EventPlaneRandomizerTask", ::CAP::EventPlaneRandomizerTask::Class_Version(), "EventPlaneRandomizerTask.hpp", 24,
                  typeid(::CAP::EventPlaneRandomizerTask), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::EventPlaneRandomizerTask::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::EventPlaneRandomizerTask) );
      instance.SetNew(&new_CAPcLcLEventPlaneRandomizerTask);
      instance.SetNewArray(&newArray_CAPcLcLEventPlaneRandomizerTask);
      instance.SetDelete(&delete_CAPcLcLEventPlaneRandomizerTask);
      instance.SetDeleteArray(&deleteArray_CAPcLcLEventPlaneRandomizerTask);
      instance.SetDestructor(&destruct_CAPcLcLEventPlaneRandomizerTask);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::EventPlaneRandomizerTask*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::EventPlaneRandomizerTask*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::EventPlaneRandomizerTask*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLEventVertexRandomizerTask(void *p = nullptr);
   static void *newArray_CAPcLcLEventVertexRandomizerTask(Long_t size, void *p);
   static void delete_CAPcLcLEventVertexRandomizerTask(void *p);
   static void deleteArray_CAPcLcLEventVertexRandomizerTask(void *p);
   static void destruct_CAPcLcLEventVertexRandomizerTask(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::EventVertexRandomizerTask*)
   {
      ::CAP::EventVertexRandomizerTask *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::EventVertexRandomizerTask >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::EventVertexRandomizerTask", ::CAP::EventVertexRandomizerTask::Class_Version(), "EventVertexRandomizerTask.hpp", 29,
                  typeid(::CAP::EventVertexRandomizerTask), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::EventVertexRandomizerTask::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::EventVertexRandomizerTask) );
      instance.SetNew(&new_CAPcLcLEventVertexRandomizerTask);
      instance.SetNewArray(&newArray_CAPcLcLEventVertexRandomizerTask);
      instance.SetDelete(&delete_CAPcLcLEventVertexRandomizerTask);
      instance.SetDeleteArray(&deleteArray_CAPcLcLEventVertexRandomizerTask);
      instance.SetDestructor(&destruct_CAPcLcLEventVertexRandomizerTask);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::EventVertexRandomizerTask*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::EventVertexRandomizerTask*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::EventVertexRandomizerTask*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLResolutionFunction_Dictionary();
   static void CAPcLcLResolutionFunction_TClassManip(TClass*);
   static void delete_CAPcLcLResolutionFunction(void *p);
   static void deleteArray_CAPcLcLResolutionFunction(void *p);
   static void destruct_CAPcLcLResolutionFunction(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ResolutionFunction*)
   {
      ::CAP::ResolutionFunction *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CAP::ResolutionFunction));
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ResolutionFunction", "ResolutionFunction.hpp", 19,
                  typeid(::CAP::ResolutionFunction), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLResolutionFunction_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ResolutionFunction) );
      instance.SetDelete(&delete_CAPcLcLResolutionFunction);
      instance.SetDeleteArray(&deleteArray_CAPcLcLResolutionFunction);
      instance.SetDestructor(&destruct_CAPcLcLResolutionFunction);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ResolutionFunction*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ResolutionFunction*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ResolutionFunction*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLResolutionFunction_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::ResolutionFunction*>(nullptr))->GetClass();
      CAPcLcLResolutionFunction_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLResolutionFunction_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLEfficiencyFunction_Dictionary();
   static void CAPcLcLEfficiencyFunction_TClassManip(TClass*);
   static void delete_CAPcLcLEfficiencyFunction(void *p);
   static void deleteArray_CAPcLcLEfficiencyFunction(void *p);
   static void destruct_CAPcLcLEfficiencyFunction(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::EfficiencyFunction*)
   {
      ::CAP::EfficiencyFunction *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CAP::EfficiencyFunction));
      static ::ROOT::TGenericClassInfo 
         instance("CAP::EfficiencyFunction", "EfficiencyFunction.hpp", 18,
                  typeid(::CAP::EfficiencyFunction), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLEfficiencyFunction_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::EfficiencyFunction) );
      instance.SetDelete(&delete_CAPcLcLEfficiencyFunction);
      instance.SetDeleteArray(&deleteArray_CAPcLcLEfficiencyFunction);
      instance.SetDestructor(&destruct_CAPcLcLEfficiencyFunction);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::EfficiencyFunction*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::EfficiencyFunction*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::EfficiencyFunction*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLEfficiencyFunction_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::EfficiencyFunction*>(nullptr))->GetClass();
      CAPcLcLEfficiencyFunction_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLEfficiencyFunction_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleSimulator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleSimulator::Class_Name()
{
   return "CAP::ParticleSimulator";
}

//______________________________________________________________________________
const char *ParticleSimulator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSimulator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleSimulator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSimulator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleSimulator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSimulator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleSimulator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleSimulator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr MeasurementSimulator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *MeasurementSimulator::Class_Name()
{
   return "CAP::MeasurementSimulator";
}

//______________________________________________________________________________
const char *MeasurementSimulator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::MeasurementSimulator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int MeasurementSimulator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::MeasurementSimulator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MeasurementSimulator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::MeasurementSimulator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MeasurementSimulator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::MeasurementSimulator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticlePerformanceHistos::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticlePerformanceHistos::Class_Name()
{
   return "CAP::ParticlePerformanceHistos";
}

//______________________________________________________________________________
const char *ParticlePerformanceHistos::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePerformanceHistos*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticlePerformanceHistos::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePerformanceHistos*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticlePerformanceHistos::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePerformanceHistos*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticlePerformanceHistos::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticlePerformanceHistos*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr PerformanceAnalyzer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PerformanceAnalyzer::Class_Name()
{
   return "CAP::PerformanceAnalyzer";
}

//______________________________________________________________________________
const char *PerformanceAnalyzer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PerformanceAnalyzer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PerformanceAnalyzer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PerformanceAnalyzer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PerformanceAnalyzer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PerformanceAnalyzer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PerformanceAnalyzer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PerformanceAnalyzer*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ClosureCalculator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ClosureCalculator::Class_Name()
{
   return "CAP::ClosureCalculator";
}

//______________________________________________________________________________
const char *ClosureCalculator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ClosureCalculator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ClosureCalculator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ClosureCalculator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ClosureCalculator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ClosureCalculator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ClosureCalculator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ClosureCalculator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ClosureIterator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ClosureIterator::Class_Name()
{
   return "CAP::ClosureIterator";
}

//______________________________________________________________________________
const char *ClosureIterator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ClosureIterator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ClosureIterator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ClosureIterator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ClosureIterator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ClosureIterator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ClosureIterator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ClosureIterator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr EventPlaneRandomizerTask::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *EventPlaneRandomizerTask::Class_Name()
{
   return "CAP::EventPlaneRandomizerTask";
}

//______________________________________________________________________________
const char *EventPlaneRandomizerTask::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventPlaneRandomizerTask*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int EventPlaneRandomizerTask::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventPlaneRandomizerTask*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventPlaneRandomizerTask::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventPlaneRandomizerTask*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventPlaneRandomizerTask::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventPlaneRandomizerTask*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr EventVertexRandomizerTask::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *EventVertexRandomizerTask::Class_Name()
{
   return "CAP::EventVertexRandomizerTask";
}

//______________________________________________________________________________
const char *EventVertexRandomizerTask::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventVertexRandomizerTask*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int EventVertexRandomizerTask::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventVertexRandomizerTask*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventVertexRandomizerTask::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventVertexRandomizerTask*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventVertexRandomizerTask::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EventVertexRandomizerTask*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void ParticleSimulator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleSimulator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleSimulator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleSimulator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleSimulator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleSimulator : new ::CAP::ParticleSimulator;
   }
   static void *newArray_CAPcLcLParticleSimulator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleSimulator[nElements] : new ::CAP::ParticleSimulator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleSimulator(void *p) {
      delete (static_cast<::CAP::ParticleSimulator*>(p));
   }
   static void deleteArray_CAPcLcLParticleSimulator(void *p) {
      delete [] (static_cast<::CAP::ParticleSimulator*>(p));
   }
   static void destruct_CAPcLcLParticleSimulator(void *p) {
      typedef ::CAP::ParticleSimulator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleSimulator

namespace CAP {
//______________________________________________________________________________
void MeasurementSimulator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::MeasurementSimulator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::MeasurementSimulator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::MeasurementSimulator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLMeasurementSimulator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::MeasurementSimulator : new ::CAP::MeasurementSimulator;
   }
   static void *newArray_CAPcLcLMeasurementSimulator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::MeasurementSimulator[nElements] : new ::CAP::MeasurementSimulator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLMeasurementSimulator(void *p) {
      delete (static_cast<::CAP::MeasurementSimulator*>(p));
   }
   static void deleteArray_CAPcLcLMeasurementSimulator(void *p) {
      delete [] (static_cast<::CAP::MeasurementSimulator*>(p));
   }
   static void destruct_CAPcLcLMeasurementSimulator(void *p) {
      typedef ::CAP::MeasurementSimulator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::MeasurementSimulator

namespace CAP {
//______________________________________________________________________________
void ParticlePerformanceHistos::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticlePerformanceHistos.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticlePerformanceHistos::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticlePerformanceHistos::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticlePerformanceHistos(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePerformanceHistos : new ::CAP::ParticlePerformanceHistos;
   }
   static void *newArray_CAPcLcLParticlePerformanceHistos(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticlePerformanceHistos[nElements] : new ::CAP::ParticlePerformanceHistos[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticlePerformanceHistos(void *p) {
      delete (static_cast<::CAP::ParticlePerformanceHistos*>(p));
   }
   static void deleteArray_CAPcLcLParticlePerformanceHistos(void *p) {
      delete [] (static_cast<::CAP::ParticlePerformanceHistos*>(p));
   }
   static void destruct_CAPcLcLParticlePerformanceHistos(void *p) {
      typedef ::CAP::ParticlePerformanceHistos current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticlePerformanceHistos

namespace CAP {
//______________________________________________________________________________
void PerformanceAnalyzer::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::PerformanceAnalyzer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::PerformanceAnalyzer::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::PerformanceAnalyzer::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLPerformanceAnalyzer(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PerformanceAnalyzer : new ::CAP::PerformanceAnalyzer;
   }
   static void *newArray_CAPcLcLPerformanceAnalyzer(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PerformanceAnalyzer[nElements] : new ::CAP::PerformanceAnalyzer[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLPerformanceAnalyzer(void *p) {
      delete (static_cast<::CAP::PerformanceAnalyzer*>(p));
   }
   static void deleteArray_CAPcLcLPerformanceAnalyzer(void *p) {
      delete [] (static_cast<::CAP::PerformanceAnalyzer*>(p));
   }
   static void destruct_CAPcLcLPerformanceAnalyzer(void *p) {
      typedef ::CAP::PerformanceAnalyzer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::PerformanceAnalyzer

namespace CAP {
//______________________________________________________________________________
void ClosureCalculator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ClosureCalculator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ClosureCalculator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ClosureCalculator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLClosureCalculator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ClosureCalculator : new ::CAP::ClosureCalculator;
   }
   static void *newArray_CAPcLcLClosureCalculator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ClosureCalculator[nElements] : new ::CAP::ClosureCalculator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLClosureCalculator(void *p) {
      delete (static_cast<::CAP::ClosureCalculator*>(p));
   }
   static void deleteArray_CAPcLcLClosureCalculator(void *p) {
      delete [] (static_cast<::CAP::ClosureCalculator*>(p));
   }
   static void destruct_CAPcLcLClosureCalculator(void *p) {
      typedef ::CAP::ClosureCalculator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ClosureCalculator

namespace CAP {
//______________________________________________________________________________
void ClosureIterator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ClosureIterator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ClosureIterator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ClosureIterator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLClosureIterator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ClosureIterator : new ::CAP::ClosureIterator;
   }
   static void *newArray_CAPcLcLClosureIterator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ClosureIterator[nElements] : new ::CAP::ClosureIterator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLClosureIterator(void *p) {
      delete (static_cast<::CAP::ClosureIterator*>(p));
   }
   static void deleteArray_CAPcLcLClosureIterator(void *p) {
      delete [] (static_cast<::CAP::ClosureIterator*>(p));
   }
   static void destruct_CAPcLcLClosureIterator(void *p) {
      typedef ::CAP::ClosureIterator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ClosureIterator

namespace CAP {
//______________________________________________________________________________
void EventPlaneRandomizerTask::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::EventPlaneRandomizerTask.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::EventPlaneRandomizerTask::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::EventPlaneRandomizerTask::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLEventPlaneRandomizerTask(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventPlaneRandomizerTask : new ::CAP::EventPlaneRandomizerTask;
   }
   static void *newArray_CAPcLcLEventPlaneRandomizerTask(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventPlaneRandomizerTask[nElements] : new ::CAP::EventPlaneRandomizerTask[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLEventPlaneRandomizerTask(void *p) {
      delete (static_cast<::CAP::EventPlaneRandomizerTask*>(p));
   }
   static void deleteArray_CAPcLcLEventPlaneRandomizerTask(void *p) {
      delete [] (static_cast<::CAP::EventPlaneRandomizerTask*>(p));
   }
   static void destruct_CAPcLcLEventPlaneRandomizerTask(void *p) {
      typedef ::CAP::EventPlaneRandomizerTask current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::EventPlaneRandomizerTask

namespace CAP {
//______________________________________________________________________________
void EventVertexRandomizerTask::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::EventVertexRandomizerTask.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::EventVertexRandomizerTask::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::EventVertexRandomizerTask::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLEventVertexRandomizerTask(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventVertexRandomizerTask : new ::CAP::EventVertexRandomizerTask;
   }
   static void *newArray_CAPcLcLEventVertexRandomizerTask(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EventVertexRandomizerTask[nElements] : new ::CAP::EventVertexRandomizerTask[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLEventVertexRandomizerTask(void *p) {
      delete (static_cast<::CAP::EventVertexRandomizerTask*>(p));
   }
   static void deleteArray_CAPcLcLEventVertexRandomizerTask(void *p) {
      delete [] (static_cast<::CAP::EventVertexRandomizerTask*>(p));
   }
   static void destruct_CAPcLcLEventVertexRandomizerTask(void *p) {
      typedef ::CAP::EventVertexRandomizerTask current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::EventVertexRandomizerTask

namespace ROOT {
   // Wrapper around operator delete
   static void delete_CAPcLcLResolutionFunction(void *p) {
      delete (static_cast<::CAP::ResolutionFunction*>(p));
   }
   static void deleteArray_CAPcLcLResolutionFunction(void *p) {
      delete [] (static_cast<::CAP::ResolutionFunction*>(p));
   }
   static void destruct_CAPcLcLResolutionFunction(void *p) {
      typedef ::CAP::ResolutionFunction current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ResolutionFunction

namespace ROOT {
   // Wrapper around operator delete
   static void delete_CAPcLcLEfficiencyFunction(void *p) {
      delete (static_cast<::CAP::EfficiencyFunction*>(p));
   }
   static void deleteArray_CAPcLcLEfficiencyFunction(void *p) {
      delete [] (static_cast<::CAP::EfficiencyFunction*>(p));
   }
   static void destruct_CAPcLcLEfficiencyFunction(void *p) {
      typedef ::CAP::EfficiencyFunction current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::EfficiencyFunction

namespace {
  void TriggerDictionaryInitialization_libPerformance_Impl() {
    static const char* headers[] = {
"MeasurementSimulator.hpp",
"ParticleSimulator.hpp",
"PerformanceAnalyzer.hpp",
"ParticlePerformanceHistos.hpp",
"ClosureCalculator.hpp",
"ClosureIterator.hpp",
"EventPlaneRandomizerTask.hpp",
"EventVertexRandomizerTask.hpp",
"ResolutionFunction.hpp",
"EfficiencyFunction.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP6.0/laptop/Performance/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libPerformance dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleSimulator.hpp")))  __attribute__((annotate("$clingAutoload$MeasurementSimulator.hpp")))  ParticleSimulator;}
namespace CAP{class __attribute__((annotate("$clingAutoload$MeasurementSimulator.hpp")))  MeasurementSimulator;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticlePerformanceHistos.hpp")))  __attribute__((annotate("$clingAutoload$PerformanceAnalyzer.hpp")))  ParticlePerformanceHistos;}
namespace CAP{class __attribute__((annotate("$clingAutoload$PerformanceAnalyzer.hpp")))  PerformanceAnalyzer;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ClosureCalculator.hpp")))  ClosureCalculator;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ClosureIterator.hpp")))  ClosureIterator;}
namespace CAP{class __attribute__((annotate("$clingAutoload$EventPlaneRandomizerTask.hpp")))  EventPlaneRandomizerTask;}
namespace CAP{class __attribute__((annotate("$clingAutoload$EventVertexRandomizerTask.hpp")))  EventVertexRandomizerTask;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ResolutionFunction.hpp")))  ResolutionFunction;}
namespace CAP{class __attribute__((annotate("$clingAutoload$EfficiencyFunction.hpp")))  EfficiencyFunction;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libPerformance dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "MeasurementSimulator.hpp"
#include "ParticleSimulator.hpp"
#include "PerformanceAnalyzer.hpp"
#include "ParticlePerformanceHistos.hpp"
#include "ClosureCalculator.hpp"
#include "ClosureIterator.hpp"
#include "EventPlaneRandomizerTask.hpp"
#include "EventVertexRandomizerTask.hpp"
#include "ResolutionFunction.hpp"
#include "EfficiencyFunction.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::ClosureCalculator", payloadCode, "@",
"CAP::ClosureIterator", payloadCode, "@",
"CAP::EfficiencyFunction", payloadCode, "@",
"CAP::EventPlaneRandomizerTask", payloadCode, "@",
"CAP::EventVertexRandomizerTask", payloadCode, "@",
"CAP::MeasurementSimulator", payloadCode, "@",
"CAP::ParticlePerformanceHistos", payloadCode, "@",
"CAP::ParticleSimulator", payloadCode, "@",
"CAP::PerformanceAnalyzer", payloadCode, "@",
"CAP::ResolutionFunction", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libPerformance",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libPerformance_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libPerformance_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libPerformance() {
  TriggerDictionaryInitialization_libPerformance_Impl();
}
