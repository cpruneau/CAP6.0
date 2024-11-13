// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G__Base
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
#include "Timer.hpp"
#include "Counter.hpp"
#include "EnvironmentVariables.hpp"
#include "FileIterator.hpp"
#include "Property.hpp"
#include "Properties.hpp"
#include "PropertiesParser.hpp"
#include "NamedObject.hpp"
#include "Configuration.hpp"
#include "ConfigurationManager.hpp"
#include "Parser.hpp"
#include "Factory.hpp"
#include "Filter.hpp"
#include "Collection.hpp"
#include "Task.hpp"
#include "HistogramGroup.hpp"
#include "HistogramSet.hpp"
#include "HistogramTask.hpp"
#include "TaskAccountant.hpp"
#include "MessageLogger.hpp"
#include "SelectionGenerator.hpp"
#include "DerivedHistoIterator.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "StreamHelpers.hpp"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_CAPcLcLTimer(void *p = nullptr);
   static void *newArray_CAPcLcLTimer(Long_t size, void *p);
   static void delete_CAPcLcLTimer(void *p);
   static void deleteArray_CAPcLcLTimer(void *p);
   static void destruct_CAPcLcLTimer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Timer*)
   {
      ::CAP::Timer *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Timer >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Timer", ::CAP::Timer::Class_Version(), "Timer.hpp", 23,
                  typeid(::CAP::Timer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::Timer::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Timer) );
      instance.SetNew(&new_CAPcLcLTimer);
      instance.SetNewArray(&newArray_CAPcLcLTimer);
      instance.SetDelete(&delete_CAPcLcLTimer);
      instance.SetDeleteArray(&deleteArray_CAPcLcLTimer);
      instance.SetDestructor(&destruct_CAPcLcLTimer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Timer*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Timer*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Timer*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLCounter(void *p = nullptr);
   static void *newArray_CAPcLcLCounter(Long_t size, void *p);
   static void delete_CAPcLcLCounter(void *p);
   static void deleteArray_CAPcLcLCounter(void *p);
   static void destruct_CAPcLcLCounter(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Counter*)
   {
      ::CAP::Counter *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Counter >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Counter", ::CAP::Counter::Class_Version(), "Counter.hpp", 20,
                  typeid(::CAP::Counter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::Counter::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Counter) );
      instance.SetNew(&new_CAPcLcLCounter);
      instance.SetNewArray(&newArray_CAPcLcLCounter);
      instance.SetDelete(&delete_CAPcLcLCounter);
      instance.SetDeleteArray(&deleteArray_CAPcLcLCounter);
      instance.SetDestructor(&destruct_CAPcLcLCounter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Counter*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Counter*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Counter*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLProperty(void *p = nullptr);
   static void *newArray_CAPcLcLProperty(Long_t size, void *p);
   static void delete_CAPcLcLProperty(void *p);
   static void deleteArray_CAPcLcLProperty(void *p);
   static void destruct_CAPcLcLProperty(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Property*)
   {
      ::CAP::Property *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Property >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Property", ::CAP::Property::Class_Version(), "Property.hpp", 20,
                  typeid(::CAP::Property), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::Property::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Property) );
      instance.SetNew(&new_CAPcLcLProperty);
      instance.SetNewArray(&newArray_CAPcLcLProperty);
      instance.SetDelete(&delete_CAPcLcLProperty);
      instance.SetDeleteArray(&deleteArray_CAPcLcLProperty);
      instance.SetDestructor(&destruct_CAPcLcLProperty);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Property*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Property*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Property*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLProperties(void *p = nullptr);
   static void *newArray_CAPcLcLProperties(Long_t size, void *p);
   static void delete_CAPcLcLProperties(void *p);
   static void deleteArray_CAPcLcLProperties(void *p);
   static void destruct_CAPcLcLProperties(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Properties*)
   {
      ::CAP::Properties *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Properties >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Properties", ::CAP::Properties::Class_Version(), "Properties.hpp", 20,
                  typeid(::CAP::Properties), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::Properties::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Properties) );
      instance.SetNew(&new_CAPcLcLProperties);
      instance.SetNewArray(&newArray_CAPcLcLProperties);
      instance.SetDelete(&delete_CAPcLcLProperties);
      instance.SetDeleteArray(&deleteArray_CAPcLcLProperties);
      instance.SetDestructor(&destruct_CAPcLcLProperties);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Properties*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Properties*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Properties*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLEnvironmentVariables(void *p = nullptr);
   static void *newArray_CAPcLcLEnvironmentVariables(Long_t size, void *p);
   static void delete_CAPcLcLEnvironmentVariables(void *p);
   static void deleteArray_CAPcLcLEnvironmentVariables(void *p);
   static void destruct_CAPcLcLEnvironmentVariables(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::EnvironmentVariables*)
   {
      ::CAP::EnvironmentVariables *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::EnvironmentVariables >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::EnvironmentVariables", ::CAP::EnvironmentVariables::Class_Version(), "EnvironmentVariables.hpp", 21,
                  typeid(::CAP::EnvironmentVariables), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::EnvironmentVariables::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::EnvironmentVariables) );
      instance.SetNew(&new_CAPcLcLEnvironmentVariables);
      instance.SetNewArray(&newArray_CAPcLcLEnvironmentVariables);
      instance.SetDelete(&delete_CAPcLcLEnvironmentVariables);
      instance.SetDeleteArray(&deleteArray_CAPcLcLEnvironmentVariables);
      instance.SetDestructor(&destruct_CAPcLcLEnvironmentVariables);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::EnvironmentVariables*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::EnvironmentVariables*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::EnvironmentVariables*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLMessageLogger(void *p = nullptr);
   static void *newArray_CAPcLcLMessageLogger(Long_t size, void *p);
   static void delete_CAPcLcLMessageLogger(void *p);
   static void deleteArray_CAPcLcLMessageLogger(void *p);
   static void destruct_CAPcLcLMessageLogger(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::MessageLogger*)
   {
      ::CAP::MessageLogger *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::MessageLogger >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::MessageLogger", ::CAP::MessageLogger::Class_Version(), "MessageLogger.hpp", 33,
                  typeid(::CAP::MessageLogger), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::MessageLogger::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::MessageLogger) );
      instance.SetNew(&new_CAPcLcLMessageLogger);
      instance.SetNewArray(&newArray_CAPcLcLMessageLogger);
      instance.SetDelete(&delete_CAPcLcLMessageLogger);
      instance.SetDeleteArray(&deleteArray_CAPcLcLMessageLogger);
      instance.SetDestructor(&destruct_CAPcLcLMessageLogger);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::MessageLogger*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::MessageLogger*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::MessageLogger*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLConfiguration(void *p = nullptr);
   static void *newArray_CAPcLcLConfiguration(Long_t size, void *p);
   static void delete_CAPcLcLConfiguration(void *p);
   static void deleteArray_CAPcLcLConfiguration(void *p);
   static void destruct_CAPcLcLConfiguration(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Configuration*)
   {
      ::CAP::Configuration *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Configuration >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Configuration", ::CAP::Configuration::Class_Version(), "Configuration.hpp", 19,
                  typeid(::CAP::Configuration), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::Configuration::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Configuration) );
      instance.SetNew(&new_CAPcLcLConfiguration);
      instance.SetNewArray(&newArray_CAPcLcLConfiguration);
      instance.SetDelete(&delete_CAPcLcLConfiguration);
      instance.SetDeleteArray(&deleteArray_CAPcLcLConfiguration);
      instance.SetDestructor(&destruct_CAPcLcLConfiguration);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Configuration*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Configuration*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Configuration*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLConfigurationManager(void *p = nullptr);
   static void *newArray_CAPcLcLConfigurationManager(Long_t size, void *p);
   static void delete_CAPcLcLConfigurationManager(void *p);
   static void deleteArray_CAPcLcLConfigurationManager(void *p);
   static void destruct_CAPcLcLConfigurationManager(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::ConfigurationManager*)
   {
      ::CAP::ConfigurationManager *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::ConfigurationManager >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::ConfigurationManager", ::CAP::ConfigurationManager::Class_Version(), "ConfigurationManager.hpp", 22,
                  typeid(::CAP::ConfigurationManager), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::ConfigurationManager::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::ConfigurationManager) );
      instance.SetNew(&new_CAPcLcLConfigurationManager);
      instance.SetNewArray(&newArray_CAPcLcLConfigurationManager);
      instance.SetDelete(&delete_CAPcLcLConfigurationManager);
      instance.SetDeleteArray(&deleteArray_CAPcLcLConfigurationManager);
      instance.SetDestructor(&destruct_CAPcLcLConfigurationManager);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::ConfigurationManager*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::ConfigurationManager*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::ConfigurationManager*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLTaskAccountant(void *p = nullptr);
   static void *newArray_CAPcLcLTaskAccountant(Long_t size, void *p);
   static void delete_CAPcLcLTaskAccountant(void *p);
   static void deleteArray_CAPcLcLTaskAccountant(void *p);
   static void destruct_CAPcLcLTaskAccountant(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::TaskAccountant*)
   {
      ::CAP::TaskAccountant *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::TaskAccountant >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::TaskAccountant", ::CAP::TaskAccountant::Class_Version(), "TaskAccountant.hpp", 20,
                  typeid(::CAP::TaskAccountant), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::TaskAccountant::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::TaskAccountant) );
      instance.SetNew(&new_CAPcLcLTaskAccountant);
      instance.SetNewArray(&newArray_CAPcLcLTaskAccountant);
      instance.SetDelete(&delete_CAPcLcLTaskAccountant);
      instance.SetDeleteArray(&deleteArray_CAPcLcLTaskAccountant);
      instance.SetDestructor(&destruct_CAPcLcLTaskAccountant);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::TaskAccountant*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::TaskAccountant*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::TaskAccountant*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLNamedObject(void *p = nullptr);
   static void *newArray_CAPcLcLNamedObject(Long_t size, void *p);
   static void delete_CAPcLcLNamedObject(void *p);
   static void deleteArray_CAPcLcLNamedObject(void *p);
   static void destruct_CAPcLcLNamedObject(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::NamedObject*)
   {
      ::CAP::NamedObject *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::NamedObject >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::NamedObject", ::CAP::NamedObject::Class_Version(), "NamedObject.hpp", 17,
                  typeid(::CAP::NamedObject), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::NamedObject::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::NamedObject) );
      instance.SetNew(&new_CAPcLcLNamedObject);
      instance.SetNewArray(&newArray_CAPcLcLNamedObject);
      instance.SetDelete(&delete_CAPcLcLNamedObject);
      instance.SetDeleteArray(&deleteArray_CAPcLcLNamedObject);
      instance.SetDestructor(&destruct_CAPcLcLNamedObject);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::NamedObject*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::NamedObject*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::NamedObject*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLTask(void *p = nullptr);
   static void *newArray_CAPcLcLTask(Long_t size, void *p);
   static void delete_CAPcLcLTask(void *p);
   static void deleteArray_CAPcLcLTask(void *p);
   static void destruct_CAPcLcLTask(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Task*)
   {
      ::CAP::Task *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Task >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Task", ::CAP::Task::Class_Version(), "Task.hpp", 29,
                  typeid(::CAP::Task), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::Task::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Task) );
      instance.SetNew(&new_CAPcLcLTask);
      instance.SetNewArray(&newArray_CAPcLcLTask);
      instance.SetDelete(&delete_CAPcLcLTask);
      instance.SetDeleteArray(&deleteArray_CAPcLcLTask);
      instance.SetDestructor(&destruct_CAPcLcLTask);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Task*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Task*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Task*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLHistogramTask(void *p = nullptr);
   static void *newArray_CAPcLcLHistogramTask(Long_t size, void *p);
   static void delete_CAPcLcLHistogramTask(void *p);
   static void deleteArray_CAPcLcLHistogramTask(void *p);
   static void destruct_CAPcLcLHistogramTask(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::HistogramTask*)
   {
      ::CAP::HistogramTask *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::HistogramTask >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::HistogramTask", ::CAP::HistogramTask::Class_Version(), "HistogramTask.hpp", 34,
                  typeid(::CAP::HistogramTask), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::HistogramTask::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::HistogramTask) );
      instance.SetNew(&new_CAPcLcLHistogramTask);
      instance.SetNewArray(&newArray_CAPcLcLHistogramTask);
      instance.SetDelete(&delete_CAPcLcLHistogramTask);
      instance.SetDeleteArray(&deleteArray_CAPcLcLHistogramTask);
      instance.SetDestructor(&destruct_CAPcLcLHistogramTask);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::HistogramTask*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::HistogramTask*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::HistogramTask*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLFileIterator(void *p = nullptr);
   static void *newArray_CAPcLcLFileIterator(Long_t size, void *p);
   static void delete_CAPcLcLFileIterator(void *p);
   static void deleteArray_CAPcLcLFileIterator(void *p);
   static void destruct_CAPcLcLFileIterator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::FileIterator*)
   {
      ::CAP::FileIterator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::FileIterator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::FileIterator", ::CAP::FileIterator::Class_Version(), "FileIterator.hpp", 22,
                  typeid(::CAP::FileIterator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::FileIterator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::FileIterator) );
      instance.SetNew(&new_CAPcLcLFileIterator);
      instance.SetNewArray(&newArray_CAPcLcLFileIterator);
      instance.SetDelete(&delete_CAPcLcLFileIterator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLFileIterator);
      instance.SetDestructor(&destruct_CAPcLcLFileIterator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::FileIterator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::FileIterator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::FileIterator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLParser(void *p = nullptr);
   static void *newArray_CAPcLcLParser(Long_t size, void *p);
   static void delete_CAPcLcLParser(void *p);
   static void deleteArray_CAPcLcLParser(void *p);
   static void destruct_CAPcLcLParser(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::Parser*)
   {
      ::CAP::Parser *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::Parser >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::Parser", ::CAP::Parser::Class_Version(), "Parser.hpp", 26,
                  typeid(::CAP::Parser), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::Parser::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::Parser) );
      instance.SetNew(&new_CAPcLcLParser);
      instance.SetNewArray(&newArray_CAPcLcLParser);
      instance.SetDelete(&delete_CAPcLcLParser);
      instance.SetDeleteArray(&deleteArray_CAPcLcLParser);
      instance.SetDestructor(&destruct_CAPcLcLParser);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::Parser*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::Parser*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::Parser*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLPropertiesParser(void *p = nullptr);
   static void *newArray_CAPcLcLPropertiesParser(Long_t size, void *p);
   static void delete_CAPcLcLPropertiesParser(void *p);
   static void deleteArray_CAPcLcLPropertiesParser(void *p);
   static void destruct_CAPcLcLPropertiesParser(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::PropertiesParser*)
   {
      ::CAP::PropertiesParser *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::PropertiesParser >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::PropertiesParser", ::CAP::PropertiesParser::Class_Version(), "PropertiesParser.hpp", 19,
                  typeid(::CAP::PropertiesParser), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::PropertiesParser::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::PropertiesParser) );
      instance.SetNew(&new_CAPcLcLPropertiesParser);
      instance.SetNewArray(&newArray_CAPcLcLPropertiesParser);
      instance.SetDelete(&delete_CAPcLcLPropertiesParser);
      instance.SetDeleteArray(&deleteArray_CAPcLcLPropertiesParser);
      instance.SetDestructor(&destruct_CAPcLcLPropertiesParser);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::PropertiesParser*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::PropertiesParser*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::PropertiesParser*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLHistogramGroup(void *p = nullptr);
   static void *newArray_CAPcLcLHistogramGroup(Long_t size, void *p);
   static void delete_CAPcLcLHistogramGroup(void *p);
   static void deleteArray_CAPcLcLHistogramGroup(void *p);
   static void destruct_CAPcLcLHistogramGroup(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::HistogramGroup*)
   {
      ::CAP::HistogramGroup *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::HistogramGroup >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::HistogramGroup", ::CAP::HistogramGroup::Class_Version(), "HistogramGroup.hpp", 29,
                  typeid(::CAP::HistogramGroup), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::HistogramGroup::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::HistogramGroup) );
      instance.SetNew(&new_CAPcLcLHistogramGroup);
      instance.SetNewArray(&newArray_CAPcLcLHistogramGroup);
      instance.SetDelete(&delete_CAPcLcLHistogramGroup);
      instance.SetDeleteArray(&deleteArray_CAPcLcLHistogramGroup);
      instance.SetDestructor(&destruct_CAPcLcLHistogramGroup);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::HistogramGroup*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::HistogramGroup*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::HistogramGroup*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLHistogramSet(void *p = nullptr);
   static void *newArray_CAPcLcLHistogramSet(Long_t size, void *p);
   static void delete_CAPcLcLHistogramSet(void *p);
   static void deleteArray_CAPcLcLHistogramSet(void *p);
   static void destruct_CAPcLcLHistogramSet(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::HistogramSet*)
   {
      ::CAP::HistogramSet *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::HistogramSet >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::HistogramSet", ::CAP::HistogramSet::Class_Version(), "HistogramSet.hpp", 23,
                  typeid(::CAP::HistogramSet), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::HistogramSet::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::HistogramSet) );
      instance.SetNew(&new_CAPcLcLHistogramSet);
      instance.SetNewArray(&newArray_CAPcLcLHistogramSet);
      instance.SetDelete(&delete_CAPcLcLHistogramSet);
      instance.SetDeleteArray(&deleteArray_CAPcLcLHistogramSet);
      instance.SetDestructor(&destruct_CAPcLcLHistogramSet);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::HistogramSet*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::HistogramSet*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::HistogramSet*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLSelectionGenerator(void *p = nullptr);
   static void *newArray_CAPcLcLSelectionGenerator(Long_t size, void *p);
   static void delete_CAPcLcLSelectionGenerator(void *p);
   static void deleteArray_CAPcLcLSelectionGenerator(void *p);
   static void destruct_CAPcLcLSelectionGenerator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::SelectionGenerator*)
   {
      ::CAP::SelectionGenerator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::SelectionGenerator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::SelectionGenerator", ::CAP::SelectionGenerator::Class_Version(), "SelectionGenerator.hpp", 25,
                  typeid(::CAP::SelectionGenerator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::SelectionGenerator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::SelectionGenerator) );
      instance.SetNew(&new_CAPcLcLSelectionGenerator);
      instance.SetNewArray(&newArray_CAPcLcLSelectionGenerator);
      instance.SetDelete(&delete_CAPcLcLSelectionGenerator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLSelectionGenerator);
      instance.SetDestructor(&destruct_CAPcLcLSelectionGenerator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::SelectionGenerator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::SelectionGenerator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::SelectionGenerator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_CAPcLcLDerivedHistoIterator(void *p = nullptr);
   static void *newArray_CAPcLcLDerivedHistoIterator(Long_t size, void *p);
   static void delete_CAPcLcLDerivedHistoIterator(void *p);
   static void deleteArray_CAPcLcLDerivedHistoIterator(void *p);
   static void destruct_CAPcLcLDerivedHistoIterator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CAP::DerivedHistoIterator*)
   {
      ::CAP::DerivedHistoIterator *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CAP::DerivedHistoIterator >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("CAP::DerivedHistoIterator", ::CAP::DerivedHistoIterator::Class_Version(), "DerivedHistoIterator.hpp", 19,
                  typeid(::CAP::DerivedHistoIterator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CAP::DerivedHistoIterator::Dictionary, isa_proxy, 4,
                  sizeof(::CAP::DerivedHistoIterator) );
      instance.SetNew(&new_CAPcLcLDerivedHistoIterator);
      instance.SetNewArray(&newArray_CAPcLcLDerivedHistoIterator);
      instance.SetDelete(&delete_CAPcLcLDerivedHistoIterator);
      instance.SetDeleteArray(&deleteArray_CAPcLcLDerivedHistoIterator);
      instance.SetDestructor(&destruct_CAPcLcLDerivedHistoIterator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CAP::DerivedHistoIterator*)
   {
      return GenerateInitInstanceLocal(static_cast<::CAP::DerivedHistoIterator*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::CAP::DerivedHistoIterator*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr Timer::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Timer::Class_Name()
{
   return "CAP::Timer";
}

//______________________________________________________________________________
const char *Timer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Timer*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Timer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Timer*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Timer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Timer*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Timer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Timer*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr Counter::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Counter::Class_Name()
{
   return "CAP::Counter";
}

//______________________________________________________________________________
const char *Counter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Counter*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Counter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Counter*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Counter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Counter*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Counter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Counter*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr Property::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Property::Class_Name()
{
   return "CAP::Property";
}

//______________________________________________________________________________
const char *Property::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Property*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Property::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Property*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Property::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Property*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Property::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Property*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr Properties::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Properties::Class_Name()
{
   return "CAP::Properties";
}

//______________________________________________________________________________
const char *Properties::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Properties*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Properties::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Properties*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Properties::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Properties*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Properties::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Properties*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr EnvironmentVariables::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *EnvironmentVariables::Class_Name()
{
   return "CAP::EnvironmentVariables";
}

//______________________________________________________________________________
const char *EnvironmentVariables::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EnvironmentVariables*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int EnvironmentVariables::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::EnvironmentVariables*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EnvironmentVariables::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EnvironmentVariables*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EnvironmentVariables::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::EnvironmentVariables*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr MessageLogger::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *MessageLogger::Class_Name()
{
   return "CAP::MessageLogger";
}

//______________________________________________________________________________
const char *MessageLogger::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::MessageLogger*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int MessageLogger::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::MessageLogger*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *MessageLogger::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::MessageLogger*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *MessageLogger::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::MessageLogger*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr Configuration::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Configuration::Class_Name()
{
   return "CAP::Configuration";
}

//______________________________________________________________________________
const char *Configuration::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Configuration*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Configuration::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Configuration*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Configuration::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Configuration*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Configuration::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Configuration*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr ConfigurationManager::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *ConfigurationManager::Class_Name()
{
   return "CAP::ConfigurationManager";
}

//______________________________________________________________________________
const char *ConfigurationManager::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ConfigurationManager*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int ConfigurationManager::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::ConfigurationManager*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *ConfigurationManager::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ConfigurationManager*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *ConfigurationManager::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::ConfigurationManager*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr TaskAccountant::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TaskAccountant::Class_Name()
{
   return "CAP::TaskAccountant";
}

//______________________________________________________________________________
const char *TaskAccountant::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::TaskAccountant*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TaskAccountant::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::TaskAccountant*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TaskAccountant::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::TaskAccountant*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TaskAccountant::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::TaskAccountant*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr NamedObject::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *NamedObject::Class_Name()
{
   return "CAP::NamedObject";
}

//______________________________________________________________________________
const char *NamedObject::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::NamedObject*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int NamedObject::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::NamedObject*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *NamedObject::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::NamedObject*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *NamedObject::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::NamedObject*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr Task::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Task::Class_Name()
{
   return "CAP::Task";
}

//______________________________________________________________________________
const char *Task::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Task*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Task::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Task*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Task::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Task*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Task::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Task*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr HistogramTask::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *HistogramTask::Class_Name()
{
   return "CAP::HistogramTask";
}

//______________________________________________________________________________
const char *HistogramTask::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::HistogramTask*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int HistogramTask::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::HistogramTask*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HistogramTask::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::HistogramTask*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HistogramTask::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::HistogramTask*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr FileIterator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *FileIterator::Class_Name()
{
   return "CAP::FileIterator";
}

//______________________________________________________________________________
const char *FileIterator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::FileIterator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int FileIterator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::FileIterator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *FileIterator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::FileIterator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *FileIterator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::FileIterator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr Parser::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *Parser::Class_Name()
{
   return "CAP::Parser";
}

//______________________________________________________________________________
const char *Parser::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Parser*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int Parser::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::Parser*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Parser::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Parser*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Parser::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::Parser*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr PropertiesParser::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *PropertiesParser::Class_Name()
{
   return "CAP::PropertiesParser";
}

//______________________________________________________________________________
const char *PropertiesParser::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PropertiesParser*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int PropertiesParser::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::PropertiesParser*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *PropertiesParser::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PropertiesParser*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *PropertiesParser::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::PropertiesParser*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr HistogramGroup::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *HistogramGroup::Class_Name()
{
   return "CAP::HistogramGroup";
}

//______________________________________________________________________________
const char *HistogramGroup::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::HistogramGroup*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int HistogramGroup::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::HistogramGroup*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HistogramGroup::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::HistogramGroup*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HistogramGroup::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::HistogramGroup*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr HistogramSet::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *HistogramSet::Class_Name()
{
   return "CAP::HistogramSet";
}

//______________________________________________________________________________
const char *HistogramSet::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::HistogramSet*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int HistogramSet::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::HistogramSet*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HistogramSet::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::HistogramSet*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HistogramSet::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::HistogramSet*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr SelectionGenerator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *SelectionGenerator::Class_Name()
{
   return "CAP::SelectionGenerator";
}

//______________________________________________________________________________
const char *SelectionGenerator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::SelectionGenerator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int SelectionGenerator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::SelectionGenerator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *SelectionGenerator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::SelectionGenerator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *SelectionGenerator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::SelectionGenerator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
atomic_TClass_ptr DerivedHistoIterator::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *DerivedHistoIterator::Class_Name()
{
   return "CAP::DerivedHistoIterator";
}

//______________________________________________________________________________
const char *DerivedHistoIterator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::DerivedHistoIterator*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int DerivedHistoIterator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CAP::DerivedHistoIterator*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *DerivedHistoIterator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::DerivedHistoIterator*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *DerivedHistoIterator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CAP::DerivedHistoIterator*)nullptr)->GetClass(); }
   return fgIsA;
}

} // namespace CAP
namespace CAP {
//______________________________________________________________________________
void Timer::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Timer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Timer::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Timer::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLTimer(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Timer : new ::CAP::Timer;
   }
   static void *newArray_CAPcLcLTimer(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Timer[nElements] : new ::CAP::Timer[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLTimer(void *p) {
      delete (static_cast<::CAP::Timer*>(p));
   }
   static void deleteArray_CAPcLcLTimer(void *p) {
      delete [] (static_cast<::CAP::Timer*>(p));
   }
   static void destruct_CAPcLcLTimer(void *p) {
      typedef ::CAP::Timer current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Timer

namespace CAP {
//______________________________________________________________________________
void Counter::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Counter.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Counter::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Counter::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLCounter(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Counter : new ::CAP::Counter;
   }
   static void *newArray_CAPcLcLCounter(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Counter[nElements] : new ::CAP::Counter[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLCounter(void *p) {
      delete (static_cast<::CAP::Counter*>(p));
   }
   static void deleteArray_CAPcLcLCounter(void *p) {
      delete [] (static_cast<::CAP::Counter*>(p));
   }
   static void destruct_CAPcLcLCounter(void *p) {
      typedef ::CAP::Counter current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Counter

namespace CAP {
//______________________________________________________________________________
void Property::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Property.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Property::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Property::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLProperty(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Property : new ::CAP::Property;
   }
   static void *newArray_CAPcLcLProperty(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Property[nElements] : new ::CAP::Property[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLProperty(void *p) {
      delete (static_cast<::CAP::Property*>(p));
   }
   static void deleteArray_CAPcLcLProperty(void *p) {
      delete [] (static_cast<::CAP::Property*>(p));
   }
   static void destruct_CAPcLcLProperty(void *p) {
      typedef ::CAP::Property current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Property

namespace CAP {
//______________________________________________________________________________
void Properties::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Properties.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Properties::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Properties::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLProperties(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Properties : new ::CAP::Properties;
   }
   static void *newArray_CAPcLcLProperties(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Properties[nElements] : new ::CAP::Properties[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLProperties(void *p) {
      delete (static_cast<::CAP::Properties*>(p));
   }
   static void deleteArray_CAPcLcLProperties(void *p) {
      delete [] (static_cast<::CAP::Properties*>(p));
   }
   static void destruct_CAPcLcLProperties(void *p) {
      typedef ::CAP::Properties current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Properties

namespace CAP {
//______________________________________________________________________________
void EnvironmentVariables::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::EnvironmentVariables.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::EnvironmentVariables::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::EnvironmentVariables::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLEnvironmentVariables(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EnvironmentVariables : new ::CAP::EnvironmentVariables;
   }
   static void *newArray_CAPcLcLEnvironmentVariables(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::EnvironmentVariables[nElements] : new ::CAP::EnvironmentVariables[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLEnvironmentVariables(void *p) {
      delete (static_cast<::CAP::EnvironmentVariables*>(p));
   }
   static void deleteArray_CAPcLcLEnvironmentVariables(void *p) {
      delete [] (static_cast<::CAP::EnvironmentVariables*>(p));
   }
   static void destruct_CAPcLcLEnvironmentVariables(void *p) {
      typedef ::CAP::EnvironmentVariables current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::EnvironmentVariables

namespace CAP {
//______________________________________________________________________________
void MessageLogger::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::MessageLogger.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::MessageLogger::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::MessageLogger::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLMessageLogger(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::MessageLogger : new ::CAP::MessageLogger;
   }
   static void *newArray_CAPcLcLMessageLogger(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::MessageLogger[nElements] : new ::CAP::MessageLogger[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLMessageLogger(void *p) {
      delete (static_cast<::CAP::MessageLogger*>(p));
   }
   static void deleteArray_CAPcLcLMessageLogger(void *p) {
      delete [] (static_cast<::CAP::MessageLogger*>(p));
   }
   static void destruct_CAPcLcLMessageLogger(void *p) {
      typedef ::CAP::MessageLogger current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::MessageLogger

namespace CAP {
//______________________________________________________________________________
void Configuration::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Configuration.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Configuration::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Configuration::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLConfiguration(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Configuration : new ::CAP::Configuration;
   }
   static void *newArray_CAPcLcLConfiguration(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Configuration[nElements] : new ::CAP::Configuration[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLConfiguration(void *p) {
      delete (static_cast<::CAP::Configuration*>(p));
   }
   static void deleteArray_CAPcLcLConfiguration(void *p) {
      delete [] (static_cast<::CAP::Configuration*>(p));
   }
   static void destruct_CAPcLcLConfiguration(void *p) {
      typedef ::CAP::Configuration current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Configuration

namespace CAP {
//______________________________________________________________________________
void ConfigurationManager::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::ConfigurationManager.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::ConfigurationManager::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::ConfigurationManager::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLConfigurationManager(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ConfigurationManager : new ::CAP::ConfigurationManager;
   }
   static void *newArray_CAPcLcLConfigurationManager(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::ConfigurationManager[nElements] : new ::CAP::ConfigurationManager[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLConfigurationManager(void *p) {
      delete (static_cast<::CAP::ConfigurationManager*>(p));
   }
   static void deleteArray_CAPcLcLConfigurationManager(void *p) {
      delete [] (static_cast<::CAP::ConfigurationManager*>(p));
   }
   static void destruct_CAPcLcLConfigurationManager(void *p) {
      typedef ::CAP::ConfigurationManager current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::ConfigurationManager

namespace CAP {
//______________________________________________________________________________
void TaskAccountant::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::TaskAccountant.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::TaskAccountant::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::TaskAccountant::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLTaskAccountant(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::TaskAccountant : new ::CAP::TaskAccountant;
   }
   static void *newArray_CAPcLcLTaskAccountant(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::TaskAccountant[nElements] : new ::CAP::TaskAccountant[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLTaskAccountant(void *p) {
      delete (static_cast<::CAP::TaskAccountant*>(p));
   }
   static void deleteArray_CAPcLcLTaskAccountant(void *p) {
      delete [] (static_cast<::CAP::TaskAccountant*>(p));
   }
   static void destruct_CAPcLcLTaskAccountant(void *p) {
      typedef ::CAP::TaskAccountant current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::TaskAccountant

namespace CAP {
//______________________________________________________________________________
void NamedObject::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::NamedObject.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::NamedObject::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::NamedObject::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLNamedObject(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::NamedObject : new ::CAP::NamedObject;
   }
   static void *newArray_CAPcLcLNamedObject(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::NamedObject[nElements] : new ::CAP::NamedObject[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLNamedObject(void *p) {
      delete (static_cast<::CAP::NamedObject*>(p));
   }
   static void deleteArray_CAPcLcLNamedObject(void *p) {
      delete [] (static_cast<::CAP::NamedObject*>(p));
   }
   static void destruct_CAPcLcLNamedObject(void *p) {
      typedef ::CAP::NamedObject current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::NamedObject

namespace CAP {
//______________________________________________________________________________
void Task::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Task.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Task::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Task::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLTask(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Task : new ::CAP::Task;
   }
   static void *newArray_CAPcLcLTask(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Task[nElements] : new ::CAP::Task[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLTask(void *p) {
      delete (static_cast<::CAP::Task*>(p));
   }
   static void deleteArray_CAPcLcLTask(void *p) {
      delete [] (static_cast<::CAP::Task*>(p));
   }
   static void destruct_CAPcLcLTask(void *p) {
      typedef ::CAP::Task current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Task

namespace CAP {
//______________________________________________________________________________
void HistogramTask::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::HistogramTask.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::HistogramTask::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::HistogramTask::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLHistogramTask(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::HistogramTask : new ::CAP::HistogramTask;
   }
   static void *newArray_CAPcLcLHistogramTask(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::HistogramTask[nElements] : new ::CAP::HistogramTask[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLHistogramTask(void *p) {
      delete (static_cast<::CAP::HistogramTask*>(p));
   }
   static void deleteArray_CAPcLcLHistogramTask(void *p) {
      delete [] (static_cast<::CAP::HistogramTask*>(p));
   }
   static void destruct_CAPcLcLHistogramTask(void *p) {
      typedef ::CAP::HistogramTask current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::HistogramTask

namespace CAP {
//______________________________________________________________________________
void FileIterator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::FileIterator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::FileIterator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::FileIterator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLFileIterator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::FileIterator : new ::CAP::FileIterator;
   }
   static void *newArray_CAPcLcLFileIterator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::FileIterator[nElements] : new ::CAP::FileIterator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLFileIterator(void *p) {
      delete (static_cast<::CAP::FileIterator*>(p));
   }
   static void deleteArray_CAPcLcLFileIterator(void *p) {
      delete [] (static_cast<::CAP::FileIterator*>(p));
   }
   static void destruct_CAPcLcLFileIterator(void *p) {
      typedef ::CAP::FileIterator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::FileIterator

namespace CAP {
//______________________________________________________________________________
void Parser::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::Parser.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::Parser::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::Parser::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLParser(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Parser : new ::CAP::Parser;
   }
   static void *newArray_CAPcLcLParser(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::Parser[nElements] : new ::CAP::Parser[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLParser(void *p) {
      delete (static_cast<::CAP::Parser*>(p));
   }
   static void deleteArray_CAPcLcLParser(void *p) {
      delete [] (static_cast<::CAP::Parser*>(p));
   }
   static void destruct_CAPcLcLParser(void *p) {
      typedef ::CAP::Parser current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::Parser

namespace CAP {
//______________________________________________________________________________
void PropertiesParser::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::PropertiesParser.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::PropertiesParser::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::PropertiesParser::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLPropertiesParser(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PropertiesParser : new ::CAP::PropertiesParser;
   }
   static void *newArray_CAPcLcLPropertiesParser(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::PropertiesParser[nElements] : new ::CAP::PropertiesParser[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLPropertiesParser(void *p) {
      delete (static_cast<::CAP::PropertiesParser*>(p));
   }
   static void deleteArray_CAPcLcLPropertiesParser(void *p) {
      delete [] (static_cast<::CAP::PropertiesParser*>(p));
   }
   static void destruct_CAPcLcLPropertiesParser(void *p) {
      typedef ::CAP::PropertiesParser current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::PropertiesParser

namespace CAP {
//______________________________________________________________________________
void HistogramGroup::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::HistogramGroup.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::HistogramGroup::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::HistogramGroup::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLHistogramGroup(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::HistogramGroup : new ::CAP::HistogramGroup;
   }
   static void *newArray_CAPcLcLHistogramGroup(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::HistogramGroup[nElements] : new ::CAP::HistogramGroup[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLHistogramGroup(void *p) {
      delete (static_cast<::CAP::HistogramGroup*>(p));
   }
   static void deleteArray_CAPcLcLHistogramGroup(void *p) {
      delete [] (static_cast<::CAP::HistogramGroup*>(p));
   }
   static void destruct_CAPcLcLHistogramGroup(void *p) {
      typedef ::CAP::HistogramGroup current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::HistogramGroup

namespace CAP {
//______________________________________________________________________________
void HistogramSet::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::HistogramSet.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::HistogramSet::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::HistogramSet::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLHistogramSet(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::HistogramSet : new ::CAP::HistogramSet;
   }
   static void *newArray_CAPcLcLHistogramSet(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::HistogramSet[nElements] : new ::CAP::HistogramSet[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLHistogramSet(void *p) {
      delete (static_cast<::CAP::HistogramSet*>(p));
   }
   static void deleteArray_CAPcLcLHistogramSet(void *p) {
      delete [] (static_cast<::CAP::HistogramSet*>(p));
   }
   static void destruct_CAPcLcLHistogramSet(void *p) {
      typedef ::CAP::HistogramSet current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::HistogramSet

namespace CAP {
//______________________________________________________________________________
void SelectionGenerator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::SelectionGenerator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::SelectionGenerator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::SelectionGenerator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLSelectionGenerator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::SelectionGenerator : new ::CAP::SelectionGenerator;
   }
   static void *newArray_CAPcLcLSelectionGenerator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::SelectionGenerator[nElements] : new ::CAP::SelectionGenerator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLSelectionGenerator(void *p) {
      delete (static_cast<::CAP::SelectionGenerator*>(p));
   }
   static void deleteArray_CAPcLcLSelectionGenerator(void *p) {
      delete [] (static_cast<::CAP::SelectionGenerator*>(p));
   }
   static void destruct_CAPcLcLSelectionGenerator(void *p) {
      typedef ::CAP::SelectionGenerator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::SelectionGenerator

namespace CAP {
//______________________________________________________________________________
void DerivedHistoIterator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CAP::DerivedHistoIterator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CAP::DerivedHistoIterator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CAP::DerivedHistoIterator::Class(),this);
   }
}

} // namespace CAP
namespace ROOT {
   // Wrappers around operator new
   static void *new_CAPcLcLDerivedHistoIterator(void *p) {
      return  p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::DerivedHistoIterator : new ::CAP::DerivedHistoIterator;
   }
   static void *newArray_CAPcLcLDerivedHistoIterator(Long_t nElements, void *p) {
      return p ? ::new(static_cast<::ROOT::Internal::TOperatorNewHelper*>(p)) ::CAP::DerivedHistoIterator[nElements] : new ::CAP::DerivedHistoIterator[nElements];
   }
   // Wrapper around operator delete
   static void delete_CAPcLcLDerivedHistoIterator(void *p) {
      delete (static_cast<::CAP::DerivedHistoIterator*>(p));
   }
   static void deleteArray_CAPcLcLDerivedHistoIterator(void *p) {
      delete [] (static_cast<::CAP::DerivedHistoIterator*>(p));
   }
   static void destruct_CAPcLcLDerivedHistoIterator(void *p) {
      typedef ::CAP::DerivedHistoIterator current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
} // end of namespace ROOT for class ::CAP::DerivedHistoIterator

namespace {
  void TriggerDictionaryInitialization_libBase_Impl() {
    static const char* headers[] = {
"Timer.hpp",
"Counter.hpp",
"EnvironmentVariables.hpp",
"FileIterator.hpp",
"Property.hpp",
"Properties.hpp",
"PropertiesParser.hpp",
"NamedObject.hpp",
"Configuration.hpp",
"ConfigurationManager.hpp",
"Parser.hpp",
"Factory.hpp",
"Filter.hpp",
"Collection.hpp",
"Task.hpp",
"HistogramGroup.hpp",
"HistogramSet.hpp",
"HistogramTask.hpp",
"TaskAccountant.hpp",
"MessageLogger.hpp",
"SelectionGenerator.hpp",
"DerivedHistoIterator.hpp",
"PrintHelpers.hpp",
"RootHelpers.hpp",
"StreamHelpers.hpp",
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
"/Users/aa7526/Documents/GitHub/CAP6.1/wsuBuild/Base/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libBase dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
namespace CAP{class __attribute__((annotate("$clingAutoload$Timer.hpp")))  Timer;}
namespace CAP{class __attribute__((annotate("$clingAutoload$Counter.hpp")))  Counter;}
namespace CAP{class __attribute__((annotate("$clingAutoload$Property.hpp")))  __attribute__((annotate("$clingAutoload$EnvironmentVariables.hpp")))  Property;}
namespace CAP{class __attribute__((annotate("$clingAutoload$Properties.hpp")))  __attribute__((annotate("$clingAutoload$EnvironmentVariables.hpp")))  Properties;}
namespace CAP{class __attribute__((annotate("$clingAutoload$EnvironmentVariables.hpp")))  EnvironmentVariables;}
namespace CAP{class __attribute__((annotate("$clingAutoload$MessageLogger.hpp")))  __attribute__((annotate("$clingAutoload$FileIterator.hpp")))  MessageLogger;}
namespace CAP{class __attribute__((annotate("$clingAutoload$Configuration.hpp")))  __attribute__((annotate("$clingAutoload$FileIterator.hpp")))  Configuration;}
namespace CAP{class __attribute__((annotate("$clingAutoload$ConfigurationManager.hpp")))  __attribute__((annotate("$clingAutoload$FileIterator.hpp")))  ConfigurationManager;}
namespace CAP{class __attribute__((annotate("$clingAutoload$TaskAccountant.hpp")))  __attribute__((annotate("$clingAutoload$FileIterator.hpp")))  TaskAccountant;}
namespace CAP{class __attribute__((annotate("$clingAutoload$NamedObject.hpp")))  __attribute__((annotate("$clingAutoload$FileIterator.hpp")))  NamedObject;}
namespace CAP{class __attribute__((annotate("$clingAutoload$Task.hpp")))  __attribute__((annotate("$clingAutoload$FileIterator.hpp")))  Task;}
namespace CAP{class __attribute__((annotate("$clingAutoload$HistogramTask.hpp")))  __attribute__((annotate("$clingAutoload$FileIterator.hpp")))  HistogramTask;}
namespace CAP{class __attribute__((annotate("$clingAutoload$FileIterator.hpp")))  FileIterator;}
namespace CAP{class __attribute__((annotate("$clingAutoload$Parser.hpp")))  __attribute__((annotate("$clingAutoload$PropertiesParser.hpp")))  Parser;}
namespace CAP{class __attribute__((annotate("$clingAutoload$PropertiesParser.hpp")))  PropertiesParser;}
namespace CAP{class __attribute__((annotate("$clingAutoload$HistogramGroup.hpp")))  HistogramGroup;}
namespace CAP{class __attribute__((annotate("$clingAutoload$HistogramSet.hpp")))  HistogramSet;}
namespace CAP{class __attribute__((annotate("$clingAutoload$SelectionGenerator.hpp")))  SelectionGenerator;}
namespace CAP{class __attribute__((annotate("$clingAutoload$DerivedHistoIterator.hpp")))  DerivedHistoIterator;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libBase dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "Timer.hpp"
#include "Counter.hpp"
#include "EnvironmentVariables.hpp"
#include "FileIterator.hpp"
#include "Property.hpp"
#include "Properties.hpp"
#include "PropertiesParser.hpp"
#include "NamedObject.hpp"
#include "Configuration.hpp"
#include "ConfigurationManager.hpp"
#include "Parser.hpp"
#include "Factory.hpp"
#include "Filter.hpp"
#include "Collection.hpp"
#include "Task.hpp"
#include "HistogramGroup.hpp"
#include "HistogramSet.hpp"
#include "HistogramTask.hpp"
#include "TaskAccountant.hpp"
#include "MessageLogger.hpp"
#include "SelectionGenerator.hpp"
#include "DerivedHistoIterator.hpp"
#include "PrintHelpers.hpp"
#include "RootHelpers.hpp"
#include "StreamHelpers.hpp"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"CAP::Configuration", payloadCode, "@",
"CAP::ConfigurationManager", payloadCode, "@",
"CAP::Counter", payloadCode, "@",
"CAP::DerivedHistoIterator", payloadCode, "@",
"CAP::EnvironmentVariables", payloadCode, "@",
"CAP::FileIterator", payloadCode, "@",
"CAP::HistogramGroup", payloadCode, "@",
"CAP::HistogramSet", payloadCode, "@",
"CAP::HistogramTask", payloadCode, "@",
"CAP::MessageLogger", payloadCode, "@",
"CAP::NamedObject", payloadCode, "@",
"CAP::Parser", payloadCode, "@",
"CAP::Properties", payloadCode, "@",
"CAP::PropertiesParser", payloadCode, "@",
"CAP::Property", payloadCode, "@",
"CAP::SelectionGenerator", payloadCode, "@",
"CAP::Task", payloadCode, "@",
"CAP::TaskAccountant", payloadCode, "@",
"CAP::Timer", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libBase",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libBase_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libBase_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libBase() {
  TriggerDictionaryInitialization_libBase_Impl();
}
