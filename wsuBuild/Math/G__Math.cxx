// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Math
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
#include "Complex.hpp"
#include "Vector3.hpp"
#include "VectorLorentz.hpp"
#include "VectorField.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static TClass *CAPcLcLMathcLcLComplexlEfloatgR_Dictionary();
   static void CAPcLcLMathcLcLComplexlEfloatgR_TClassManip(TClass*);
   static void *new_CAPcLcLMathcLcLComplexlEfloatgR(void *p = nullptr);
   static void *newArray_CAPcLcLMathcLcLComplexlEfloatgR(Long_t size, void *p);
   static void delete_CAPcLcLMathcLcLComplexlEfloatgR(void *p);
   static void deleteArray_CAPcLcLMathcLcLComplexlEfloatgR(void *p);
   static void destruct_CAPcLcLMathcLcLComplexlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Math::Complex<float>*)
   {
      ::CAP::Math::Complex<float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Math::Complex<float> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Math::Complex<float>", ::CAP::Math::Complex<float>::Class_Version(), "Complex.hpp", 17,
                  typeid(::CAP::Math::Complex<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLMathcLcLComplexlEfloatgR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Math::Complex<float>) );
      instance.SetNew(&new_CAPcLcLMathcLcLComplexlEfloatgR);
      instance.SetNewArray(&newArray_CAPcLcLMathcLcLComplexlEfloatgR);
      instance.SetDelete(&delete_CAPcLcLMathcLcLComplexlEfloatgR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLMathcLcLComplexlEfloatgR);
      instance.SetDestructor(&destruct_CAPcLcLMathcLcLComplexlEfloatgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Math::Complex<float>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Math::Complex<float>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Math::Complex<float>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLMathcLcLComplexlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Math::Complex<float>*>(nullptr))->GetClass();
      CAPcLcLMathcLcLComplexlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLMathcLcLComplexlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLMathcLcLComplexlEdoublegR_Dictionary();
   static void CAPcLcLMathcLcLComplexlEdoublegR_TClassManip(TClass*);
   static void *new_CAPcLcLMathcLcLComplexlEdoublegR(void *p = nullptr);
   static void *newArray_CAPcLcLMathcLcLComplexlEdoublegR(Long_t size, void *p);
   static void delete_CAPcLcLMathcLcLComplexlEdoublegR(void *p);
   static void deleteArray_CAPcLcLMathcLcLComplexlEdoublegR(void *p);
   static void destruct_CAPcLcLMathcLcLComplexlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Math::Complex<double>*)
   {
      ::CAP::Math::Complex<double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Math::Complex<double> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Math::Complex<double>", ::CAP::Math::Complex<double>::Class_Version(), "Complex.hpp", 17,
                  typeid(::CAP::Math::Complex<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLMathcLcLComplexlEdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Math::Complex<double>) );
      instance.SetNew(&new_CAPcLcLMathcLcLComplexlEdoublegR);
      instance.SetNewArray(&newArray_CAPcLcLMathcLcLComplexlEdoublegR);
      instance.SetDelete(&delete_CAPcLcLMathcLcLComplexlEdoublegR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLMathcLcLComplexlEdoublegR);
      instance.SetDestructor(&destruct_CAPcLcLMathcLcLComplexlEdoublegR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Math::Complex<double>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Math::Complex<double>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Math::Complex<double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLMathcLcLComplexlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Math::Complex<double>*>(nullptr))->GetClass();
      CAPcLcLMathcLcLComplexlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLMathcLcLComplexlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLMathcLcLVector3lEfloatgR_Dictionary();
   static void CAPcLcLMathcLcLVector3lEfloatgR_TClassManip(TClass*);
   static void *new_CAPcLcLMathcLcLVector3lEfloatgR(void *p = nullptr);
   static void *newArray_CAPcLcLMathcLcLVector3lEfloatgR(Long_t size, void *p);
   static void delete_CAPcLcLMathcLcLVector3lEfloatgR(void *p);
   static void deleteArray_CAPcLcLMathcLcLVector3lEfloatgR(void *p);
   static void destruct_CAPcLcLMathcLcLVector3lEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Math::Vector3<float>*)
   {
      ::CAP::Math::Vector3<float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Math::Vector3<float> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Math::Vector3<float>", ::CAP::Math::Vector3<float>::Class_Version(), "Vector3.hpp", 28,
                  typeid(::CAP::Math::Vector3<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLMathcLcLVector3lEfloatgR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Math::Vector3<float>) );
      instance.SetNew(&new_CAPcLcLMathcLcLVector3lEfloatgR);
      instance.SetNewArray(&newArray_CAPcLcLMathcLcLVector3lEfloatgR);
      instance.SetDelete(&delete_CAPcLcLMathcLcLVector3lEfloatgR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLMathcLcLVector3lEfloatgR);
      instance.SetDestructor(&destruct_CAPcLcLMathcLcLVector3lEfloatgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Math::Vector3<float>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Math::Vector3<float>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Math::Vector3<float>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLMathcLcLVector3lEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Math::Vector3<float>*>(nullptr))->GetClass();
      CAPcLcLMathcLcLVector3lEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLMathcLcLVector3lEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLMathcLcLVector3lEdoublegR_Dictionary();
   static void CAPcLcLMathcLcLVector3lEdoublegR_TClassManip(TClass*);
   static void *new_CAPcLcLMathcLcLVector3lEdoublegR(void *p = nullptr);
   static void *newArray_CAPcLcLMathcLcLVector3lEdoublegR(Long_t size, void *p);
   static void delete_CAPcLcLMathcLcLVector3lEdoublegR(void *p);
   static void deleteArray_CAPcLcLMathcLcLVector3lEdoublegR(void *p);
   static void destruct_CAPcLcLMathcLcLVector3lEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Math::Vector3<double>*)
   {
      ::CAP::Math::Vector3<double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Math::Vector3<double> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Math::Vector3<double>", ::CAP::Math::Vector3<double>::Class_Version(), "Vector3.hpp", 28,
                  typeid(::CAP::Math::Vector3<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLMathcLcLVector3lEdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Math::Vector3<double>) );
      instance.SetNew(&new_CAPcLcLMathcLcLVector3lEdoublegR);
      instance.SetNewArray(&newArray_CAPcLcLMathcLcLVector3lEdoublegR);
      instance.SetDelete(&delete_CAPcLcLMathcLcLVector3lEdoublegR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLMathcLcLVector3lEdoublegR);
      instance.SetDestructor(&destruct_CAPcLcLMathcLcLVector3lEdoublegR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Math::Vector3<double>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Math::Vector3<double>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Math::Vector3<double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLMathcLcLVector3lEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Math::Vector3<double>*>(nullptr))->GetClass();
      CAPcLcLMathcLcLVector3lEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLMathcLcLVector3lEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLMathcLcLVector3lElongsPdoublegR_Dictionary();
   static void CAPcLcLMathcLcLVector3lElongsPdoublegR_TClassManip(TClass*);
   static void *new_CAPcLcLMathcLcLVector3lElongsPdoublegR(void *p = nullptr);
   static void *newArray_CAPcLcLMathcLcLVector3lElongsPdoublegR(Long_t size, void *p);
   static void delete_CAPcLcLMathcLcLVector3lElongsPdoublegR(void *p);
   static void deleteArray_CAPcLcLMathcLcLVector3lElongsPdoublegR(void *p);
   static void destruct_CAPcLcLMathcLcLVector3lElongsPdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Math::Vector3<long double>*)
   {
      ::CAP::Math::Vector3<long double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Math::Vector3<long double> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Math::Vector3<long double>", ::CAP::Math::Vector3<long double>::Class_Version(), "Vector3.hpp", 28,
                  typeid(::CAP::Math::Vector3<long double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLMathcLcLVector3lElongsPdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Math::Vector3<long double>) );
      instance.SetNew(&new_CAPcLcLMathcLcLVector3lElongsPdoublegR);
      instance.SetNewArray(&newArray_CAPcLcLMathcLcLVector3lElongsPdoublegR);
      instance.SetDelete(&delete_CAPcLcLMathcLcLVector3lElongsPdoublegR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLMathcLcLVector3lElongsPdoublegR);
      instance.SetDestructor(&destruct_CAPcLcLMathcLcLVector3lElongsPdoublegR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Math::Vector3<long double>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Math::Vector3<long double>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Math::Vector3<long double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLMathcLcLVector3lElongsPdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Math::Vector3<long double>*>(nullptr))->GetClass();
      CAPcLcLMathcLcLVector3lElongsPdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLMathcLcLVector3lElongsPdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLMathcLcLVectorLorentzlEfloatgR_Dictionary();
   static void CAPcLcLMathcLcLVectorLorentzlEfloatgR_TClassManip(TClass*);
   static void *new_CAPcLcLMathcLcLVectorLorentzlEfloatgR(void *p = nullptr);
   static void *newArray_CAPcLcLMathcLcLVectorLorentzlEfloatgR(Long_t size, void *p);
   static void delete_CAPcLcLMathcLcLVectorLorentzlEfloatgR(void *p);
   static void deleteArray_CAPcLcLMathcLcLVectorLorentzlEfloatgR(void *p);
   static void destruct_CAPcLcLMathcLcLVectorLorentzlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Math::VectorLorentz<float>*)
   {
      ::CAP::Math::VectorLorentz<float> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Math::VectorLorentz<float> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Math::VectorLorentz<float>", ::CAP::Math::VectorLorentz<float>::Class_Version(), "VectorLorentz.hpp", 38,
                  typeid(::CAP::Math::VectorLorentz<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLMathcLcLVectorLorentzlEfloatgR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Math::VectorLorentz<float>) );
      instance.SetNew(&new_CAPcLcLMathcLcLVectorLorentzlEfloatgR);
      instance.SetNewArray(&newArray_CAPcLcLMathcLcLVectorLorentzlEfloatgR);
      instance.SetDelete(&delete_CAPcLcLMathcLcLVectorLorentzlEfloatgR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLMathcLcLVectorLorentzlEfloatgR);
      instance.SetDestructor(&destruct_CAPcLcLMathcLcLVectorLorentzlEfloatgR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Math::VectorLorentz<float>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Math::VectorLorentz<float>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Math::VectorLorentz<float>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLMathcLcLVectorLorentzlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Math::VectorLorentz<float>*>(nullptr))->GetClass();
      CAPcLcLMathcLcLVectorLorentzlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLMathcLcLVectorLorentzlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLMathcLcLVectorLorentzlEdoublegR_Dictionary();
   static void CAPcLcLMathcLcLVectorLorentzlEdoublegR_TClassManip(TClass*);
   static void *new_CAPcLcLMathcLcLVectorLorentzlEdoublegR(void *p = nullptr);
   static void *newArray_CAPcLcLMathcLcLVectorLorentzlEdoublegR(Long_t size, void *p);
   static void delete_CAPcLcLMathcLcLVectorLorentzlEdoublegR(void *p);
   static void deleteArray_CAPcLcLMathcLcLVectorLorentzlEdoublegR(void *p);
   static void destruct_CAPcLcLMathcLcLVectorLorentzlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Math::VectorLorentz<double>*)
   {
      ::CAP::Math::VectorLorentz<double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Math::VectorLorentz<double> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Math::VectorLorentz<double>", ::CAP::Math::VectorLorentz<double>::Class_Version(), "VectorLorentz.hpp", 38,
                  typeid(::CAP::Math::VectorLorentz<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLMathcLcLVectorLorentzlEdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Math::VectorLorentz<double>) );
      instance.SetNew(&new_CAPcLcLMathcLcLVectorLorentzlEdoublegR);
      instance.SetNewArray(&newArray_CAPcLcLMathcLcLVectorLorentzlEdoublegR);
      instance.SetDelete(&delete_CAPcLcLMathcLcLVectorLorentzlEdoublegR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLMathcLcLVectorLorentzlEdoublegR);
      instance.SetDestructor(&destruct_CAPcLcLMathcLcLVectorLorentzlEdoublegR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Math::VectorLorentz<double>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Math::VectorLorentz<double>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Math::VectorLorentz<double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLMathcLcLVectorLorentzlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Math::VectorLorentz<double>*>(nullptr))->GetClass();
      CAPcLcLMathcLcLVectorLorentzlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLMathcLcLVectorLorentzlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR_Dictionary();
   static void CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR_TClassManip(TClass*);
   static void *new_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR(void *p = nullptr);
   static void *newArray_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR(Long_t size, void *p);
   static void delete_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR(void *p);
   static void deleteArray_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR(void *p);
   static void destruct_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Math::VectorLorentz<long double>*)
   {
      ::CAP::Math::VectorLorentz<long double> *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Math::VectorLorentz<long double> >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Math::VectorLorentz<long double>", ::CAP::Math::VectorLorentz<long double>::Class_Version(), "VectorLorentz.hpp", 38,
                  typeid(::CAP::Math::VectorLorentz<long double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Math::VectorLorentz<long double>) );
      instance.SetNew(&new_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR);
      instance.SetNewArray(&newArray_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR);
      instance.SetDelete(&delete_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR);
      instance.SetDeleteArray(&deleteArray_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR);
      instance.SetDestructor(&destruct_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Math::VectorLorentz<long double>*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Math::VectorLorentz<long double>*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Math::VectorLorentz<long double>*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal(static_cast<const ::CAP::Math::VectorLorentz<long double>*>(nullptr))->GetClass();
      CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLVectorField(void *p = nullptr);
   static void *newArray_CAPcLcLVectorField(Long_t size, void *p);
   static void delete_CAPcLcLVectorField(void *p);
   static void deleteArray_CAPcLcLVectorField(void *p);
   static void destruct_CAPcLcLVectorField(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::VectorField*)
   {
      ::CAP::VectorField *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::VectorField >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::VectorField", ::CAP::VectorField::Class_Version(), "VectorField.hpp", 38,
                  typeid(::CAP::VectorField), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::VectorField::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::VectorField) );
      instance.SetNew(&new_CAPcLcLVectorField);
      instance.SetNewArray(&newArray_CAPcLcLVectorField);
      instance.SetDelete(&delete_CAPcLcLVectorField);
      instance.SetDeleteArray(&deleteArray_CAPcLcLVectorField);
      instance.SetDestructor(&destruct_CAPcLcLVectorField);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::VectorField*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::VectorField*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::VectorField*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> atomic_TClass_ptr Complex<float>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *Complex<float>::Class_Name()
{
   return "CAP::Math::Complex<float>";
}

//______________________________________________________________________________
template <> const char *Complex<float>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Complex<float>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int Complex<float>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Complex<float>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *Complex<float>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Complex<float>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *Complex<float>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Complex<float>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> atomic_TClass_ptr Complex<double>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *Complex<double>::Class_Name()
{
   return "CAP::Math::Complex<double>";
}

//______________________________________________________________________________
template <> const char *Complex<double>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Complex<double>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int Complex<double>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Complex<double>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *Complex<double>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Complex<double>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *Complex<double>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Complex<double>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> atomic_TClass_ptr Vector3<float>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *Vector3<float>::Class_Name()
{
   return "CAP::Math::Vector3<float>";
}

//______________________________________________________________________________
template <> const char *Vector3<float>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Vector3<float>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int Vector3<float>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Vector3<float>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *Vector3<float>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Vector3<float>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *Vector3<float>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Vector3<float>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> atomic_TClass_ptr Vector3<double>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *Vector3<double>::Class_Name()
{
   return "CAP::Math::Vector3<double>";
}

//______________________________________________________________________________
template <> const char *Vector3<double>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Vector3<double>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int Vector3<double>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Vector3<double>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *Vector3<double>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Vector3<double>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *Vector3<double>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Vector3<double>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> atomic_TClass_ptr Vector3<long double>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *Vector3<long double>::Class_Name()
{
   return "CAP::Math::Vector3<long double>";
}

//______________________________________________________________________________
template <> const char *Vector3<long double>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Vector3<long double>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int Vector3<long double>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Vector3<long double>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *Vector3<long double>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Vector3<long double>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *Vector3<long double>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::Vector3<long double>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> atomic_TClass_ptr VectorLorentz<float>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *VectorLorentz<float>::Class_Name()
{
   return "CAP::Math::VectorLorentz<float>";
}

//______________________________________________________________________________
template <> const char *VectorLorentz<float>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::VectorLorentz<float>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int VectorLorentz<float>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::VectorLorentz<float>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *VectorLorentz<float>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::VectorLorentz<float>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *VectorLorentz<float>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::VectorLorentz<float>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> atomic_TClass_ptr VectorLorentz<double>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *VectorLorentz<double>::Class_Name()
{
   return "CAP::Math::VectorLorentz<double>";
}

//______________________________________________________________________________
template <> const char *VectorLorentz<double>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::VectorLorentz<double>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int VectorLorentz<double>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::VectorLorentz<double>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *VectorLorentz<double>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::VectorLorentz<double>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *VectorLorentz<double>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::VectorLorentz<double>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> atomic_TClass_ptr VectorLorentz<long double>::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
template <> const char *VectorLorentz<long double>::Class_Name()
{
   return "CAP::Math::VectorLorentz<long double>";
}

//______________________________________________________________________________
template <> const char *VectorLorentz<long double>::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::VectorLorentz<long double>*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
template <> int VectorLorentz<long double>::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::VectorLorentz<long double>*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
template <> TClass *VectorLorentz<long double>::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::VectorLorentz<long double>*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
template <> TClass *VectorLorentz<long double>::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Math::VectorLorentz<long double>*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr VectorField::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *VectorField::Class_Name()
{
   return "CAP::VectorField";
}

//______________________________________________________________________________
const char *VectorField::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::VectorField*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int VectorField::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::VectorField*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *VectorField::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::VectorField*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *VectorField::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::VectorField*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> void Complex<float>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Math::Complex<float>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Math::Complex<float>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Math::Complex<float>::Class(),this);
   }
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLMathcLcLComplexlEfloatgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::Complex<float> : new ::CAP::Math::Complex<float>;
   }
   static void *newArray_CAPcLcLMathcLcLComplexlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::Complex<float>[nElements] : new ::CAP::Math::Complex<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLMathcLcLComplexlEfloatgR(void *p) {
      delete (static_cast<::CAP::Math::Complex<float>*>(p));
   }
   static void deleteArray_CAPcLcLMathcLcLComplexlEfloatgR(void *p) {
      delete [] (static_cast<::CAP::Math::Complex<float>*>(p));
   }
   static void destruct_CAPcLcLMathcLcLComplexlEfloatgR(void *p) {
      typedef ::CAP::Math::Complex<float> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Math::Complex<float>

namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> void Complex<double>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Math::Complex<double>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Math::Complex<double>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Math::Complex<double>::Class(),this);
   }
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLMathcLcLComplexlEdoublegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::Complex<double> : new ::CAP::Math::Complex<double>;
   }
   static void *newArray_CAPcLcLMathcLcLComplexlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::Complex<double>[nElements] : new ::CAP::Math::Complex<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLMathcLcLComplexlEdoublegR(void *p) {
      delete (static_cast<::CAP::Math::Complex<double>*>(p));
   }
   static void deleteArray_CAPcLcLMathcLcLComplexlEdoublegR(void *p) {
      delete [] (static_cast<::CAP::Math::Complex<double>*>(p));
   }
   static void destruct_CAPcLcLMathcLcLComplexlEdoublegR(void *p) {
      typedef ::CAP::Math::Complex<double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Math::Complex<double>

namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> void Vector3<float>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Math::Vector3<float>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Math::Vector3<float>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Math::Vector3<float>::Class(),this);
   }
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLMathcLcLVector3lEfloatgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::Vector3<float> : new ::CAP::Math::Vector3<float>;
   }
   static void *newArray_CAPcLcLMathcLcLVector3lEfloatgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::Vector3<float>[nElements] : new ::CAP::Math::Vector3<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLMathcLcLVector3lEfloatgR(void *p) {
      delete (static_cast<::CAP::Math::Vector3<float>*>(p));
   }
   static void deleteArray_CAPcLcLMathcLcLVector3lEfloatgR(void *p) {
      delete [] (static_cast<::CAP::Math::Vector3<float>*>(p));
   }
   static void destruct_CAPcLcLMathcLcLVector3lEfloatgR(void *p) {
      typedef ::CAP::Math::Vector3<float> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Math::Vector3<float>

namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> void Vector3<double>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Math::Vector3<double>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Math::Vector3<double>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Math::Vector3<double>::Class(),this);
   }
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLMathcLcLVector3lEdoublegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::Vector3<double> : new ::CAP::Math::Vector3<double>;
   }
   static void *newArray_CAPcLcLMathcLcLVector3lEdoublegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::Vector3<double>[nElements] : new ::CAP::Math::Vector3<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLMathcLcLVector3lEdoublegR(void *p) {
      delete (static_cast<::CAP::Math::Vector3<double>*>(p));
   }
   static void deleteArray_CAPcLcLMathcLcLVector3lEdoublegR(void *p) {
      delete [] (static_cast<::CAP::Math::Vector3<double>*>(p));
   }
   static void destruct_CAPcLcLMathcLcLVector3lEdoublegR(void *p) {
      typedef ::CAP::Math::Vector3<double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Math::Vector3<double>

namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> void Vector3<long double>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Math::Vector3<long double>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Math::Vector3<long double>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Math::Vector3<long double>::Class(),this);
   }
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLMathcLcLVector3lElongsPdoublegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::Vector3<long double> : new ::CAP::Math::Vector3<long double>;
   }
   static void *newArray_CAPcLcLMathcLcLVector3lElongsPdoublegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::Vector3<long double>[nElements] : new ::CAP::Math::Vector3<long double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLMathcLcLVector3lElongsPdoublegR(void *p) {
      delete (static_cast<::CAP::Math::Vector3<long double>*>(p));
   }
   static void deleteArray_CAPcLcLMathcLcLVector3lElongsPdoublegR(void *p) {
      delete [] (static_cast<::CAP::Math::Vector3<long double>*>(p));
   }
   static void destruct_CAPcLcLMathcLcLVector3lElongsPdoublegR(void *p) {
      typedef ::CAP::Math::Vector3<long double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Math::Vector3<long double>

namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> void VectorLorentz<float>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Math::VectorLorentz<float>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Math::VectorLorentz<float>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Math::VectorLorentz<float>::Class(),this);
   }
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLMathcLcLVectorLorentzlEfloatgR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::VectorLorentz<float> : new ::CAP::Math::VectorLorentz<float>;
   }
   static void *newArray_CAPcLcLMathcLcLVectorLorentzlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::VectorLorentz<float>[nElements] : new ::CAP::Math::VectorLorentz<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLMathcLcLVectorLorentzlEfloatgR(void *p) {
      delete (static_cast<::CAP::Math::VectorLorentz<float>*>(p));
   }
   static void deleteArray_CAPcLcLMathcLcLVectorLorentzlEfloatgR(void *p) {
      delete [] (static_cast<::CAP::Math::VectorLorentz<float>*>(p));
   }
   static void destruct_CAPcLcLMathcLcLVectorLorentzlEfloatgR(void *p) {
      typedef ::CAP::Math::VectorLorentz<float> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Math::VectorLorentz<float>

namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> void VectorLorentz<double>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Math::VectorLorentz<double>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Math::VectorLorentz<double>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Math::VectorLorentz<double>::Class(),this);
   }
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLMathcLcLVectorLorentzlEdoublegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::VectorLorentz<double> : new ::CAP::Math::VectorLorentz<double>;
   }
   static void *newArray_CAPcLcLMathcLcLVectorLorentzlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::VectorLorentz<double>[nElements] : new ::CAP::Math::VectorLorentz<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLMathcLcLVectorLorentzlEdoublegR(void *p) {
      delete (static_cast<::CAP::Math::VectorLorentz<double>*>(p));
   }
   static void deleteArray_CAPcLcLMathcLcLVectorLorentzlEdoublegR(void *p) {
      delete [] (static_cast<::CAP::Math::VectorLorentz<double>*>(p));
   }
   static void destruct_CAPcLcLMathcLcLVectorLorentzlEdoublegR(void *p) {
      typedef ::CAP::Math::VectorLorentz<double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Math::VectorLorentz<double>

namespace CAP {
   namespace Math {
//______________________________________________________________________________
template <> void VectorLorentz<long double>::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Math::VectorLorentz<long double>.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Math::VectorLorentz<long double>::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Math::VectorLorentz<long double>::Class(),this);
   }
}

} // namespace CAP::Math
} // namespace CAP::Math
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::VectorLorentz<long double> : new ::CAP::Math::VectorLorentz<long double>;
   }
   static void *newArray_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Math::VectorLorentz<long double>[nElements] : new ::CAP::Math::VectorLorentz<long double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR(void *p) {
      delete (static_cast<::CAP::Math::VectorLorentz<long double>*>(p));
   }
   static void deleteArray_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR(void *p) {
      delete [] (static_cast<::CAP::Math::VectorLorentz<long double>*>(p));
   }
   static void destruct_CAPcLcLMathcLcLVectorLorentzlElongsPdoublegR(void *p) {
      typedef ::CAP::Math::VectorLorentz<long double> current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Math::VectorLorentz<long double>

namespace CAP {
//______________________________________________________________________________
void VectorField::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::VectorField.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::VectorField::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::VectorField::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLVectorField(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::VectorField : new ::CAP::VectorField;
   }
   static void *newArray_CAPcLcLVectorField(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::VectorField[nElements] : new ::CAP::VectorField[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLVectorField(void *p) {
      delete (static_cast<::CAP::VectorField*>(p));
   }
   static void deleteArray_CAPcLcLVectorField(void *p) {
      delete [] (static_cast<::CAP::VectorField*>(p));
   }
   static void destruct_CAPcLcLVectorField(void *p) {
      typedef ::CAP::VectorField current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::VectorField

namespace {
  void TriggerDictionaryInitialization_libMath_Impl() {
    static const char* headers[] = {
"Complex.hpp",
"Vector3.hpp",
"VectorLorentz.hpp",
"VectorField.hpp",
nullptr
    };
    static const char* includePaths[] = {
"/opt/homebrew/Cellar/root/6.32.06/include/root",
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
"/Users/aa7526/opt/pythia8312/include",
"/Users/aa7526/opt/pythia8312/include/Pythia8",
"/opt/homebrew/Cellar/root/6.32.06/include/root",
"/Users/aa7526/Documents/GitHub/CAP6.1/wsuBuild/Math/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libMath dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{namespace Math{template <typename T> class __attribute__((annotate("$clingAutoload$Complex.hpp")))  Complex;
}}
namespace CAP{namespace Math{template <typename T> class __attribute__((annotate("$clingAutoload$Vector3.hpp")))  Vector3;
}}
namespace CAP{namespace Math{template <typename T> class __attribute__((annotate("$clingAutoload$VectorLorentz.hpp")))  VectorLorentz;
}}
namespace CAP{class __attribute__((annotate("$clingAutoload$VectorField.hpp")))  VectorField;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libMath dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "Complex.hpp"
#include "Vector3.hpp"
#include "VectorLorentz.hpp"
#include "VectorField.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::Math::Complex<double>", payloadCode, "@",
"CAP::Math::Complex<float>", payloadCode, "@",
"CAP::Math::Vector3<double>", payloadCode, "@",
"CAP::Math::Vector3<float>", payloadCode, "@",
"CAP::Math::Vector3<long double>", payloadCode, "@",
"CAP::Math::VectorLorentz<double>", payloadCode, "@",
"CAP::Math::VectorLorentz<float>", payloadCode, "@",
"CAP::Math::VectorLorentz<long double>", payloadCode, "@",
"CAP::VectorField", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libMath",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libMath_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libMath_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libMath() {
  TriggerDictionaryInitialization_libMath_Impl();
}
