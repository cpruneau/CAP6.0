// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__ParticleDb
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
#include "ParticleType.hpp"
#include "ParticleDb.hpp"
#include "ParticleDbParser.hpp"
#include "ParticleDbParser_CS.hpp"
#include "ParticleDbTask.hpp"
#include "ParticleDecayMode.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLParticleDb(void *p = nullptr);
   static void *newArray_CAPcLcLParticleDb(Long_t size, void *p);
   static void delete_CAPcLcLParticleDb(void *p);
   static void deleteArray_CAPcLcLParticleDb(void *p);
   static void destruct_CAPcLcLParticleDb(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleDb*)
   {
      ::CAP::ParticleDb *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleDb >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleDb", ::CAP::ParticleDb::Class_Version(), "ParticleDb.hpp", 24,
                  typeid(::CAP::ParticleDb), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleDb::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleDb) );
      instance.SetNew(&new_CAPcLcLParticleDb);
      instance.SetNewArray(&newArray_CAPcLcLParticleDb);
      instance.SetDelete(&delete_CAPcLcLParticleDb);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleDb);
      instance.SetDestructor(&destruct_CAPcLcLParticleDb);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleDb*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleDb*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleDb*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticleDecayMode(void *p = nullptr);
   static void *newArray_CAPcLcLParticleDecayMode(Long_t size, void *p);
   static void delete_CAPcLcLParticleDecayMode(void *p);
   static void deleteArray_CAPcLcLParticleDecayMode(void *p);
   static void destruct_CAPcLcLParticleDecayMode(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleDecayMode*)
   {
      ::CAP::ParticleDecayMode *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleDecayMode >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleDecayMode", ::CAP::ParticleDecayMode::Class_Version(), "ParticleDecayMode.hpp", 32,
                  typeid(::CAP::ParticleDecayMode), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleDecayMode::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleDecayMode) );
      instance.SetNew(&new_CAPcLcLParticleDecayMode);
      instance.SetNewArray(&newArray_CAPcLcLParticleDecayMode);
      instance.SetDelete(&delete_CAPcLcLParticleDecayMode);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleDecayMode);
      instance.SetDestructor(&destruct_CAPcLcLParticleDecayMode);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleDecayMode*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleDecayMode*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleDecayMode*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticleType(void *p = nullptr);
   static void *newArray_CAPcLcLParticleType(Long_t size, void *p);
   static void delete_CAPcLcLParticleType(void *p);
   static void deleteArray_CAPcLcLParticleType(void *p);
   static void destruct_CAPcLcLParticleType(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleType*)
   {
      ::CAP::ParticleType *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleType >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleType", ::CAP::ParticleType::Class_Version(), "ParticleType.hpp", 32,
                  typeid(::CAP::ParticleType), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleType::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleType) );
      instance.SetNew(&new_CAPcLcLParticleType);
      instance.SetNewArray(&newArray_CAPcLcLParticleType);
      instance.SetDelete(&delete_CAPcLcLParticleType);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleType);
      instance.SetDestructor(&destruct_CAPcLcLParticleType);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleType*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleType*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleType*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticleDbParser(void *p = nullptr);
   static void *newArray_CAPcLcLParticleDbParser(Long_t size, void *p);
   static void delete_CAPcLcLParticleDbParser(void *p);
   static void deleteArray_CAPcLcLParticleDbParser(void *p);
   static void destruct_CAPcLcLParticleDbParser(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleDbParser*)
   {
      ::CAP::ParticleDbParser *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleDbParser >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleDbParser", ::CAP::ParticleDbParser::Class_Version(), "ParticleDbParser.hpp", 20,
                  typeid(::CAP::ParticleDbParser), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleDbParser::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleDbParser) );
      instance.SetNew(&new_CAPcLcLParticleDbParser);
      instance.SetNewArray(&newArray_CAPcLcLParticleDbParser);
      instance.SetDelete(&delete_CAPcLcLParticleDbParser);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleDbParser);
      instance.SetDestructor(&destruct_CAPcLcLParticleDbParser);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleDbParser*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleDbParser*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleDbParser*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticleDbParser_CS(void *p = nullptr);
   static void *newArray_CAPcLcLParticleDbParser_CS(Long_t size, void *p);
   static void delete_CAPcLcLParticleDbParser_CS(void *p);
   static void deleteArray_CAPcLcLParticleDbParser_CS(void *p);
   static void destruct_CAPcLcLParticleDbParser_CS(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleDbParser_CS*)
   {
      ::CAP::ParticleDbParser_CS *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleDbParser_CS >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleDbParser_CS", ::CAP::ParticleDbParser_CS::Class_Version(), "ParticleDbParser_CS.hpp", 21,
                  typeid(::CAP::ParticleDbParser_CS), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleDbParser_CS::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleDbParser_CS) );
      instance.SetNew(&new_CAPcLcLParticleDbParser_CS);
      instance.SetNewArray(&newArray_CAPcLcLParticleDbParser_CS);
      instance.SetDelete(&delete_CAPcLcLParticleDbParser_CS);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleDbParser_CS);
      instance.SetDestructor(&destruct_CAPcLcLParticleDbParser_CS);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleDbParser_CS*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleDbParser_CS*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleDbParser_CS*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLManagerlECAPcLcLParticleDbgR_Dictionary();
   static void CAPcLcLManagerlECAPcLcLParticleDbgR_TClassManip(TClass*);
   static void *new_CAPcLcLManagerlECAPcLcLParticleDbgR(void *p = nullptr);
   static void *newArray_CAPcLcLManagerlECAPcLcLParticleDbgR(Long_t size, void *p);
   static void delete_CAPcLcLManagerlECAPcLcLParticleDbgR(void *p);
   static void deleteArray_CAPcLcLManagerlECAPcLcLParticleDbgR(void *p);
   static void destruct_CAPcLcLManagerlECAPcLcLParticleDbgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Manager<CAP::ParticleDb>*)
   {
      ::CAP::Manager<CAP::ParticleDb> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Manager<CAP::ParticleDb> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Manager<CAP::ParticleDb>", ::CAP::Manager<CAP::ParticleDb>::Class_Version(), "Manager.hpp", 33,
                  typeid(::CAP::Manager<CAP::ParticleDb>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLManagerlECAPcLcLParticleDbgR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Manager<CAP::ParticleDb>) );
      instance.SetNew(&new_CAPcLcLManagerlECAPcLcLParticleDbgR);
      instance.SetNewArray(&newArray_CAPcLcLManagerlECAPcLcLParticleDbgR);
      instance.SetDelete(&delete_CAPcLcLManagerlECAPcLcLParticleDbgR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLManagerlECAPcLcLParticleDbgR);
      instance.SetDestructor(&destruct_CAPcLcLManagerlECAPcLcLParticleDbgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Manager<CAP::ParticleDb>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Manager<CAP::ParticleDb>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Manager<CAP::ParticleDb>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLManagerlECAPcLcLParticleDbgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Manager<CAP::ParticleDb>*>(nullptr))->GetClass();
      CAPcLcLManagerlECAPcLcLParticleDbgR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLManagerlECAPcLcLParticleDbgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParticleDbTask(void *p = nullptr);
   static void *newArray_CAPcLcLParticleDbTask(Long_t size, void *p);
   static void delete_CAPcLcLParticleDbTask(void *p);
   static void deleteArray_CAPcLcLParticleDbTask(void *p);
   static void destruct_CAPcLcLParticleDbTask(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ParticleDbTask*)
   {
      ::CAP::ParticleDbTask *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ParticleDbTask >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ParticleDbTask", ::CAP::ParticleDbTask::Class_Version(), "ParticleDbTask.hpp", 36,
                  typeid(::CAP::ParticleDbTask), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ParticleDbTask::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ParticleDbTask) );
      instance.SetNew(&new_CAPcLcLParticleDbTask);
      instance.SetNewArray(&newArray_CAPcLcLParticleDbTask);
      instance.SetDelete(&delete_CAPcLcLParticleDbTask);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParticleDbTask);
      instance.SetDestructor(&destruct_CAPcLcLParticleDbTask);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ParticleDbTask*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ParticleDbTask*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ParticleDbTask*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleDb::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleDb::Class_Name()
{
   return "CAP::ParticleDb";
}

//______________________________________________________________________________
const char *ParticleDb::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDb*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleDb::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDb*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleDb::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDb*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleDb::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDb*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleDecayMode::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleDecayMode::Class_Name()
{
   return "CAP::ParticleDecayMode";
}

//______________________________________________________________________________
const char *ParticleDecayMode::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDecayMode*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleDecayMode::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDecayMode*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleDecayMode::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDecayMode*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleDecayMode::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDecayMode*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleType::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleType::Class_Name()
{
   return "CAP::ParticleType";
}

//______________________________________________________________________________
const char *ParticleType::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleType*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleType::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleType*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleType::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleType*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleType::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleType*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleDbParser::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleDbParser::Class_Name()
{
   return "CAP::ParticleDbParser";
}

//______________________________________________________________________________
const char *ParticleDbParser::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDbParser*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleDbParser::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDbParser*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleDbParser::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDbParser*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleDbParser::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDbParser*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleDbParser_CS::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleDbParser_CS::Class_Name()
{
   return "CAP::ParticleDbParser_CS";
}

//______________________________________________________________________________
const char *ParticleDbParser_CS::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDbParser_CS*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleDbParser_CS::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDbParser_CS*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleDbParser_CS::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDbParser_CS*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleDbParser_CS::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDbParser_CS*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
template <> atomic_TClass_ptr Manager<CAP::ParticleDb>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *Manager<CAP::ParticleDb>::Class_Name()
{
   return "CAP::Manager<CAP::ParticleDb>";
}

//______________________________________________________________________________
template <> const char *Manager<CAP::ParticleDb>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::ParticleDb>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int Manager<CAP::ParticleDb>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::ParticleDb>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *Manager<CAP::ParticleDb>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::ParticleDb>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *Manager<CAP::ParticleDb>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Manager<CAP::ParticleDb>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ParticleDbTask::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ParticleDbTask::Class_Name()
{
   return "CAP::ParticleDbTask";
}

//______________________________________________________________________________
const char *ParticleDbTask::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDbTask*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ParticleDbTask::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDbTask*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ParticleDbTask::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDbTask*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ParticleDbTask::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ParticleDbTask*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void ParticleDb::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleDb.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleDb::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleDb::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleDb(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDb : new ::CAP::ParticleDb;
   }
   static void *newArray_CAPcLcLParticleDb(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDb[nElements] : new ::CAP::ParticleDb[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleDb(void *p) {
      delete (static_cast<::CAP::ParticleDb*>(p));
   }
   static void deleteArray_CAPcLcLParticleDb(void *p) {
      delete [] (static_cast<::CAP::ParticleDb*>(p));
   }
   static void destruct_CAPcLcLParticleDb(void *p) {
      typedef ::CAP::ParticleDb current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleDb

namespace CAP {
//______________________________________________________________________________
void ParticleDecayMode::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleDecayMode.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleDecayMode::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleDecayMode::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleDecayMode(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDecayMode : new ::CAP::ParticleDecayMode;
   }
   static void *newArray_CAPcLcLParticleDecayMode(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDecayMode[nElements] : new ::CAP::ParticleDecayMode[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleDecayMode(void *p) {
      delete (static_cast<::CAP::ParticleDecayMode*>(p));
   }
   static void deleteArray_CAPcLcLParticleDecayMode(void *p) {
      delete [] (static_cast<::CAP::ParticleDecayMode*>(p));
   }
   static void destruct_CAPcLcLParticleDecayMode(void *p) {
      typedef ::CAP::ParticleDecayMode current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleDecayMode

namespace CAP {
//______________________________________________________________________________
void ParticleType::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleType.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleType::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleType::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleType(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleType : new ::CAP::ParticleType;
   }
   static void *newArray_CAPcLcLParticleType(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleType[nElements] : new ::CAP::ParticleType[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleType(void *p) {
      delete (static_cast<::CAP::ParticleType*>(p));
   }
   static void deleteArray_CAPcLcLParticleType(void *p) {
      delete [] (static_cast<::CAP::ParticleType*>(p));
   }
   static void destruct_CAPcLcLParticleType(void *p) {
      typedef ::CAP::ParticleType current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleType

namespace CAP {
//______________________________________________________________________________
void ParticleDbParser::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleDbParser.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleDbParser::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleDbParser::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleDbParser(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDbParser : new ::CAP::ParticleDbParser;
   }
   static void *newArray_CAPcLcLParticleDbParser(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDbParser[nElements] : new ::CAP::ParticleDbParser[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleDbParser(void *p) {
      delete (static_cast<::CAP::ParticleDbParser*>(p));
   }
   static void deleteArray_CAPcLcLParticleDbParser(void *p) {
      delete [] (static_cast<::CAP::ParticleDbParser*>(p));
   }
   static void destruct_CAPcLcLParticleDbParser(void *p) {
      typedef ::CAP::ParticleDbParser current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleDbParser

namespace CAP {
//______________________________________________________________________________
void ParticleDbParser_CS::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleDbParser_CS.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleDbParser_CS::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleDbParser_CS::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleDbParser_CS(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDbParser_CS : new ::CAP::ParticleDbParser_CS;
   }
   static void *newArray_CAPcLcLParticleDbParser_CS(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDbParser_CS[nElements] : new ::CAP::ParticleDbParser_CS[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleDbParser_CS(void *p) {
      delete (static_cast<::CAP::ParticleDbParser_CS*>(p));
   }
   static void deleteArray_CAPcLcLParticleDbParser_CS(void *p) {
      delete [] (static_cast<::CAP::ParticleDbParser_CS*>(p));
   }
   static void destruct_CAPcLcLParticleDbParser_CS(void *p) {
      typedef ::CAP::ParticleDbParser_CS current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleDbParser_CS

namespace CAP {
//______________________________________________________________________________
template <> void Manager<CAP::ParticleDb>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Manager<CAP::ParticleDb>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Manager<CAP::ParticleDb>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Manager<CAP::ParticleDb>::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLManagerlECAPcLcLParticleDbgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Manager<CAP::ParticleDb> : new ::CAP::Manager<CAP::ParticleDb>;
   }
   static void *newArray_CAPcLcLManagerlECAPcLcLParticleDbgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Manager<CAP::ParticleDb>[nElements] : new ::CAP::Manager<CAP::ParticleDb>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLManagerlECAPcLcLParticleDbgR(void *p) {
      delete (static_cast<::CAP::Manager<CAP::ParticleDb>*>(p));
   }
   static void deleteArray_CAPcLcLManagerlECAPcLcLParticleDbgR(void *p) {
      delete [] (static_cast<::CAP::Manager<CAP::ParticleDb>*>(p));
   }
   static void destruct_CAPcLcLManagerlECAPcLcLParticleDbgR(void *p) {
      typedef ::CAP::Manager<CAP::ParticleDb> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Manager<CAP::ParticleDb>

namespace CAP {
//______________________________________________________________________________
void ParticleDbTask::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ParticleDbTask.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ParticleDbTask::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ParticleDbTask::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParticleDbTask(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDbTask : new ::CAP::ParticleDbTask;
   }
   static void *newArray_CAPcLcLParticleDbTask(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ParticleDbTask[nElements] : new ::CAP::ParticleDbTask[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParticleDbTask(void *p) {
      delete (static_cast<::CAP::ParticleDbTask*>(p));
   }
   static void deleteArray_CAPcLcLParticleDbTask(void *p) {
      delete [] (static_cast<::CAP::ParticleDbTask*>(p));
   }
   static void destruct_CAPcLcLParticleDbTask(void *p) {
      typedef ::CAP::ParticleDbTask current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ParticleDbTask

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
         instance("vector<bool>", -2, "vector", 2055,
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
         instance("vector<TString>", -2, "vector", 383,
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
   static TClass *vectorlECAPcLcLParticleDbmUgR_Dictionary();
   static void vectorlECAPcLcLParticleDbmUgR_TClassManip(TClass*);
   static void *new_vectorlECAPcLcLParticleDbmUgR(void *p = nullptr);
   static void *newArray_vectorlECAPcLcLParticleDbmUgR(Long_t size, void *p);
   static void delete_vectorlECAPcLcLParticleDbmUgR(void *p);
   static void deleteArray_vectorlECAPcLcLParticleDbmUgR(void *p);
   static void destruct_vectorlECAPcLcLParticleDbmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<CAP::ParticleDb*>*)
   {
      vector<CAP::ParticleDb*> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<CAP::ParticleDb*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<CAP::ParticleDb*>", -2, "vector", 383,
                  typeid(vector<CAP::ParticleDb*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlECAPcLcLParticleDbmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<CAP::ParticleDb*>) );
      instance.SetNew(&new_vectorlECAPcLcLParticleDbmUgR);
      instance.SetNewArray(&newArray_vectorlECAPcLcLParticleDbmUgR);
      instance.SetDelete(&delete_vectorlECAPcLcLParticleDbmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlECAPcLcLParticleDbmUgR);
      instance.SetDestructor(&destruct_vectorlECAPcLcLParticleDbmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<CAP::ParticleDb*> >()));

      instance.AdoptAlternate(::ROOT::AddClassAlternate("vector<CAP::ParticleDb*>","std::__1::vector<CAP::ParticleDb*, std::__1::allocator<CAP::ParticleDb*>>"));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const vector<CAP::ParticleDb*>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlECAPcLcLParticleDbmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const vector<CAP::ParticleDb*>*>(nullptr))->GetClass();
      vectorlECAPcLcLParticleDbmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlECAPcLcLParticleDbmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlECAPcLcLParticleDbmUgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::ParticleDb*> : new vector<CAP::ParticleDb*>;
   }
   static void *newArray_vectorlECAPcLcLParticleDbmUgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) vector<CAP::ParticleDb*>[nElements] : new vector<CAP::ParticleDb*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlECAPcLcLParticleDbmUgR(void *p) {
      delete (static_cast<vector<CAP::ParticleDb*>*>(p));
   }
   static void deleteArray_vectorlECAPcLcLParticleDbmUgR(void *p) {
      delete [] (static_cast<vector<CAP::ParticleDb*>*>(p));
   }
   static void destruct_vectorlECAPcLcLParticleDbmUgR(void *p) {
      typedef vector<CAP::ParticleDb*> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class vector<CAP::ParticleDb*>

namespace {
  void TriggerDictionaryInitialization_libParticleDb_Impl() {
    static const char* headers[] = {
"ParticleType.hpp",
"ParticleDb.hpp",
"ParticleDbParser.hpp",
"ParticleDbParser_CS.hpp",
"ParticleDbTask.hpp",
"ParticleDecayMode.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/ParticleDb/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libParticleDb dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleDb.hpp")))  __attribute__((annotate("$clingAutoload$ParticleType.hpp")))  ParticleDb;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleDecayMode.hpp")))  __attribute__((annotate("$clingAutoload$ParticleType.hpp")))  ParticleDecayMode;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleType.hpp")))  ParticleType;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleDbParser.hpp")))  ParticleDbParser;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleDbParser_CS.hpp")))  ParticleDbParser_CS;}
namespace CAP{template <class Object> class __attribute__((annotate("$clingAutoload$Manager.hpp")))  __attribute__((annotate("$clingAutoload$ParticleDbTask.hpp")))  Manager;
}
namespace CAP{class __attribute__((annotate("$clingAutoload$ParticleDbTask.hpp")))  ParticleDbTask;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libParticleDb dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "ParticleType.hpp"
#include "ParticleDb.hpp"
#include "ParticleDbParser.hpp"
#include "ParticleDbParser_CS.hpp"
#include "ParticleDbTask.hpp"
#include "ParticleDecayMode.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::Manager<CAP::ParticleDb>", payloadCode, "@",
"CAP::ParticleDb", payloadCode, "@",
"CAP::ParticleDbParser", payloadCode, "@",
"CAP::ParticleDbParser_CS", payloadCode, "@",
"CAP::ParticleDbTask", payloadCode, "@",
"CAP::ParticleDecayMode", payloadCode, "@",
"CAP::ParticleType", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libParticleDb",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libParticleDb_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libParticleDb_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libParticleDb() {
  TriggerDictionaryInitialization_libParticleDb_Impl();
}
