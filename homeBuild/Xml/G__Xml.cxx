// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Xml
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
#include "XmlParser.hpp"
#include "XmlDocument.hpp"
#include "XmlVectorField.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLXmlParser(void *p = nullptr);
   static void *newArray_CAPcLcLXmlParser(Long_t size, void *p);
   static void delete_CAPcLcLXmlParser(void *p);
   static void deleteArray_CAPcLcLXmlParser(void *p);
   static void destruct_CAPcLcLXmlParser(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::XmlParser*)
   {
      ::CAP::XmlParser *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::XmlParser >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::XmlParser", ::CAP::XmlParser::Class_Version(), "XmlParser.hpp", 40,
                  typeid(::CAP::XmlParser), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::XmlParser::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::XmlParser) );
      instance.SetNew(&new_CAPcLcLXmlParser);
      instance.SetNewArray(&newArray_CAPcLcLXmlParser);
      instance.SetDelete(&delete_CAPcLcLXmlParser);
      instance.SetDeleteArray(&deleteArray_CAPcLcLXmlParser);
      instance.SetDestructor(&destruct_CAPcLcLXmlParser);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::XmlParser*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::XmlParser*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::XmlParser*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLXmlDocument(void *p = nullptr);
   static void *newArray_CAPcLcLXmlDocument(Long_t size, void *p);
   static void delete_CAPcLcLXmlDocument(void *p);
   static void deleteArray_CAPcLcLXmlDocument(void *p);
   static void destruct_CAPcLcLXmlDocument(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::XmlDocument*)
   {
      ::CAP::XmlDocument *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::XmlDocument >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::XmlDocument", ::CAP::XmlDocument::Class_Version(), "XmlDocument.hpp", 19,
                  typeid(::CAP::XmlDocument), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::XmlDocument::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::XmlDocument) );
      instance.SetNew(&new_CAPcLcLXmlDocument);
      instance.SetNewArray(&newArray_CAPcLcLXmlDocument);
      instance.SetDelete(&delete_CAPcLcLXmlDocument);
      instance.SetDeleteArray(&deleteArray_CAPcLcLXmlDocument);
      instance.SetDestructor(&destruct_CAPcLcLXmlDocument);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::XmlDocument*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::XmlDocument*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::XmlDocument*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLXmlVectorField(void *p = nullptr);
   static void *newArray_CAPcLcLXmlVectorField(Long_t size, void *p);
   static void delete_CAPcLcLXmlVectorField(void *p);
   static void deleteArray_CAPcLcLXmlVectorField(void *p);
   static void destruct_CAPcLcLXmlVectorField(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::XmlVectorField*)
   {
      ::CAP::XmlVectorField *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::XmlVectorField >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::XmlVectorField", ::CAP::XmlVectorField::Class_Version(), "XmlVectorField.hpp", 20,
                  typeid(::CAP::XmlVectorField), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::XmlVectorField::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::XmlVectorField) );
      instance.SetNew(&new_CAPcLcLXmlVectorField);
      instance.SetNewArray(&newArray_CAPcLcLXmlVectorField);
      instance.SetDelete(&delete_CAPcLcLXmlVectorField);
      instance.SetDeleteArray(&deleteArray_CAPcLcLXmlVectorField);
      instance.SetDestructor(&destruct_CAPcLcLXmlVectorField);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::XmlVectorField*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::XmlVectorField*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::XmlVectorField*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr XmlParser::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *XmlParser::Class_Name()
{
   return "CAP::XmlParser";
}

//______________________________________________________________________________
const char *XmlParser::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::XmlParser*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int XmlParser::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::XmlParser*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *XmlParser::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::XmlParser*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *XmlParser::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::XmlParser*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr XmlDocument::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *XmlDocument::Class_Name()
{
   return "CAP::XmlDocument";
}

//______________________________________________________________________________
const char *XmlDocument::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::XmlDocument*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int XmlDocument::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::XmlDocument*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *XmlDocument::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::XmlDocument*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *XmlDocument::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::XmlDocument*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr XmlVectorField::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *XmlVectorField::Class_Name()
{
   return "CAP::XmlVectorField";
}

//______________________________________________________________________________
const char *XmlVectorField::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::XmlVectorField*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int XmlVectorField::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::XmlVectorField*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *XmlVectorField::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::XmlVectorField*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *XmlVectorField::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::XmlVectorField*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void XmlParser::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::XmlParser.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::XmlParser::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::XmlParser::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLXmlParser(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::XmlParser : new ::CAP::XmlParser;
   }
   static void *newArray_CAPcLcLXmlParser(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::XmlParser[nElements] : new ::CAP::XmlParser[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLXmlParser(void *p) {
      delete (static_cast<::CAP::XmlParser*>(p));
   }
   static void deleteArray_CAPcLcLXmlParser(void *p) {
      delete [] (static_cast<::CAP::XmlParser*>(p));
   }
   static void destruct_CAPcLcLXmlParser(void *p) {
      typedef ::CAP::XmlParser current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::XmlParser

namespace CAP {
//______________________________________________________________________________
void XmlDocument::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::XmlDocument.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::XmlDocument::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::XmlDocument::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLXmlDocument(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::XmlDocument : new ::CAP::XmlDocument;
   }
   static void *newArray_CAPcLcLXmlDocument(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::XmlDocument[nElements] : new ::CAP::XmlDocument[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLXmlDocument(void *p) {
      delete (static_cast<::CAP::XmlDocument*>(p));
   }
   static void deleteArray_CAPcLcLXmlDocument(void *p) {
      delete [] (static_cast<::CAP::XmlDocument*>(p));
   }
   static void destruct_CAPcLcLXmlDocument(void *p) {
      typedef ::CAP::XmlDocument current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::XmlDocument

namespace CAP {
//______________________________________________________________________________
void XmlVectorField::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::XmlVectorField.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::XmlVectorField::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::XmlVectorField::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLXmlVectorField(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::XmlVectorField : new ::CAP::XmlVectorField;
   }
   static void *newArray_CAPcLcLXmlVectorField(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::XmlVectorField[nElements] : new ::CAP::XmlVectorField[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLXmlVectorField(void *p) {
      delete (static_cast<::CAP::XmlVectorField*>(p));
   }
   static void deleteArray_CAPcLcLXmlVectorField(void *p) {
      delete [] (static_cast<::CAP::XmlVectorField*>(p));
   }
   static void destruct_CAPcLcLXmlVectorField(void *p) {
      typedef ::CAP::XmlVectorField current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::XmlVectorField

namespace {
  void TriggerDictionaryInitialization_libXml_Impl() {
    static const char* headers[] = {
"XmlParser.hpp",
"XmlDocument.hpp",
"XmlVectorField.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/Xml/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libXml dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$XmlParser.hpp")))  XmlParser;}
namespace CAP{class __attribute__((annotate("$clingAutoload$XmlDocument.hpp")))  XmlDocument;}
namespace CAP{class __attribute__((annotate("$clingAutoload$XmlVectorField.hpp")))  XmlVectorField;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libXml dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "XmlParser.hpp"
#include "XmlDocument.hpp"
#include "XmlVectorField.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::XmlDocument", payloadCode, "@",
"CAP::XmlParser", payloadCode, "@",
"CAP::XmlVectorField", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libXml",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libXml_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libXml_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libXml() {
  TriggerDictionaryInitialization_libXml_Impl();
}
