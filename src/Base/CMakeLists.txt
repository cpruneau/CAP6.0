################################################################################################
# Project CAP/Base
################################################################################################

#include(${ROOT_USE_FILE})
#include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
#add_definitions(${ROOT_CXX_FLAGS})

ROOT_GENERATE_DICTIONARY(G__Base Timer.hpp Counter.hpp EnvironmentVariables.hpp FileIterator.hpp Property.hpp Properties.hpp PropertiesParser.hpp NamedObject.hpp  Configuration.hpp ConfigurationManager.hpp  Parser.hpp  Factory.hpp   Filter.hpp Collection.hpp   Task.hpp HistogramGroup.hpp HistogramSet.hpp  HistogramTask.hpp  TaskAccountant.hpp   MessageLogger.hpp    SelectionGenerator.hpp   DerivedHistoIterator.hpp PrintHelpers.hpp RootHelpers.hpp StreamHelpers.hpp
LINKDEF BaseLinkDef.h)

################################################################################################
# Create a shared library with geneated dictionary
################################################################################################
add_compile_options(-Wall -Wextra -pedantic)
add_library(Base SHARED Aliases.cpp Exceptions.cpp PhysicsConstants.cpp Timer.cpp Crc32.cpp Counter.cpp EnvironmentVariables.cpp  FileIterator.cpp  NamedObject.cpp Property.cpp  Properties.cpp PropertiesParser.cpp NameHelpers.cpp Configuration.cpp ConfigurationManager.cpp  Parser.cpp   Factory.cpp Filter.cpp   Task.cpp  HistogramGroup.cpp  HistogramSet.cpp HistogramTask.cpp   TaskAccountant.cpp   MessageLogger.cpp   SelectionGenerator.cpp     DerivedHistoIterator.cpp PrintHelpers.cpp  RootHelpers.cpp StreamHelpers.cpp Manager.cpp
 G__Base.cxx)

target_link_libraries(Base ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
target_include_directories(Base PUBLIC Base Math ${EXTRA_INCLUDES} )

# optimization for big histogram access within the pair inner loop
# WARNING: the sumw2 structure is not used -> estimate uncertainties using sub-samples
add_definitions(-DOPTIMIZEADDBINCONTENT)


install(FILES  "${CMAKE_CURRENT_BINARY_DIR}/libBase.rootmap" "${CMAKE_CURRENT_BINARY_DIR}/libBase_rdict.pcm" DESTINATION "$ENV{CAP_LIB_PATH}")
install(TARGETS Base  LIBRARY DESTINATION "$ENV{CAP_LIB_PATH}")

