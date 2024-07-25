/* **********************************************************************
 * Copyright (C) 2019-2022, Claude Pruneau, Victor Gonzalez, Sumit Basu
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2022
 *
 * *********************************************************************/
#include "MessageLogger.hpp"
using CAP::MessageLogger;
using CAP::String;

ClassImp(MessageLogger);

String MessageLogger::unknownSeverityName   = "<Unknown>";
String MessageLogger::traceSeverityName     = "<Trace>";;
String MessageLogger::startSeverityString   = "<Start>";
String MessageLogger::endSeverityString     = "<End>";
String MessageLogger::debugSeverityName     = "<Debug>";
String MessageLogger::infoSeverityName      = "<Info>";
String MessageLogger::warningSeverityName   = "<Warning>";
String MessageLogger::errorSeverityName     = "<Error>";
String MessageLogger::fatalSeverityName     = "<Fatal>";

MessageLogger::MessageLogger()
:
reportLevel( Info ),
holdReportLevel(Info),
className("MessageLogger"),
instanceName("MessageLogger"),
fctName("CTOR")
{   }

MessageLogger::MessageLogger(const MessageLogger & logger)
:
reportLevel(logger.reportLevel),
holdReportLevel(logger.holdReportLevel),
className(logger.className),
instanceName(logger.instanceName),
fctName(logger.fctName)
{   }

MessageLogger MessageLogger::operator=(const MessageLogger & logger)
{
  if (this!=&logger)
    {
    reportLevel     = logger.reportLevel;
    holdReportLevel = logger.holdReportLevel;
    className       = logger.className;
    instanceName    = logger.instanceName;
    fctName         = logger.fctName;
    }
  return *this;
}


bool MessageLogger::report(Severity severity, const String &  className, const String &  instanceName, const String &  fctName, std::ostream & output) const
{
  if (reportLevel<=severity)
    {
    switch (severity)
      {
        default:
        case Unknown:  output << traceSeverityName; break;
        case Trace:    output << traceSeverityName; break;
        case Debug:    output << debugSeverityName; break;
        case Info:     output << infoSeverityName; break;
        case Warning:  output << warningSeverityName; break;
        case Error:    output << errorSeverityName; break;
        case Fatal:    output << fatalSeverityName; break;
      }
    std::cout << "  " << className << "[" << instanceName << "]::" << fctName << ": ";
    return true;
    }
  else
    return false;
}
