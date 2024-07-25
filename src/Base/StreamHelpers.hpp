/* **********************************************************************
 * Copyright (C) 2019-2024, Claude Pruneau
 * All rights reserved.
 *
 * Based on the ROOT package and environment
 *
 * For the licensing terms see LICENSE.
 *
 * Author: Claude Pruneau,   04/01/2022-2024
 *
 * *********************************************************************/
#ifndef CAP__StreamHelpers
#define CAP__StreamHelpers
#include <iostream>
#include <vector>
#include "TSystem.h"
#include "TSystemFile.h"
#include "TSystemDirectory.h"
#include "TParameter.h"
#include "RootHelpers.hpp"
#include "Manager.hpp"

namespace CAP
{
  std::ifstream & openInputAsciiFile(const String & path,
                                     const String & name,
                                     const String & extension);

  std::ofstream & openOutputAsciiFile(const String & path,
                                      const String & name,
                                      const String & extension);

  std::ifstream & openInputBinaryFile(const String & path,
                                      const String & fileName,
                                      const String & extension);

  std::ofstream & openOutputBinaryFile(const String & outputPath,
                                       const String & fileName,
                                       const String & extension);

  void copyFile(const String & inputPath,  const String & inputFileName, const String & inExtension,
                const String & outputPath, const String & outputFileName, const String & outExtension);


}

#endif /* CAP__FileManager */
