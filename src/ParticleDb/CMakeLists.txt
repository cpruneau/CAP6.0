################################################################################################
# Project CAP/ParticleDb
################################################################################################

#include(${ROOT_USE_FILE})
#include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
#add_definitions(${ROOT_CXX_FLAGS})

ROOT_GENERATE_DICTIONARY(G__ParticleDb  ParticleType.hpp  ParticleDb.hpp ParticleDbParser.hpp ParticleDbParser_CS.hpp ParticleDbTask.hpp ParticleDecayMode.hpp
LINKDEF ParticleDbLinkDef.h)

#ParticleDigit.hpp

################################################################################################
# Create a shared library with geneated dictionary
################################################################################################
add_compile_options(-Wall -Wextra -pedantic)
add_library(ParticleDb SHARED   ParticleType.cpp ParticleDbExceptions.cpp  ParticleDb.cpp ParticleDbParser.cpp ParticleDbParser_CS.cpp  ParticleDbTask.cpp ParticleDecayMode.cpp
 G__ParticleDb.cxx)

target_link_libraries(ParticleDb Base  ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
target_include_directories(ParticleDb  PUBLIC Base ParticleDb ${EXTRA_INCLUDES} )

install(FILES  "${CMAKE_CURRENT_BINARY_DIR}/libParticleDb.rootmap" "${CMAKE_CURRENT_BINARY_DIR}/libParticleDb_rdict.pcm" DESTINATION "$ENV{CAP_LIB_PATH}")
install(TARGETS ParticleDb  LIBRARY DESTINATION "$ENV{CAP_LIB_PATH}")

