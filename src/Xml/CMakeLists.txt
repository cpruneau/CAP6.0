################################################################################################
# Project CAP/Xml
################################################################################################
#include(${ROOT_USE_FILE})
#include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
#add_definitions(${ROOT_CXX_FLAGS})
################################################################################################

ROOT_GENERATE_DICTIONARY(G__Xml  XmlParser.hpp  XmlDocument.hpp XmlVectorField.hpp LINKDEF XmlLinkDef.h)

################################################################################################
# Create a shared library with geneated dictionary
################################################################################################

add_compile_options(-Wall -Wextra -pedantic)
add_library(Xml SHARED  XmlParser.cpp  XmlDocument.cpp XmlVectorField.cpp G__Xml.cxx)

target_link_libraries(Xml Math Base  ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
target_include_directories(Xml PUBLIC Base Math ParticleDb ${EXTRA_INCLUDES} )

install(FILES  "${CMAKE_CURRENT_BINARY_DIR}/libXml.rootmap" "${CMAKE_CURRENT_BINARY_DIR}/libXml_rdict.pcm" DESTINATION "$ENV{CAP_LIB_PATH}")
install(TARGETS Xml  LIBRARY DESTINATION "$ENV{CAP_LIB_PATH}")

