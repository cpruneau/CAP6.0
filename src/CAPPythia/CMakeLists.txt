################################################################################################
# Project CAP/Pythia
################################################################################################

ROOT_GENERATE_DICTIONARY(G__CAPPythia PythiaEventGenerator.hpp PythiaEventReader.hpp LINKDEF CAPPythiaLinkDef.h)

################################################################################################
# Create a shared library with geneated dictionary
################################################################################################
add_library(CAPPythia SHARED PythiaEventGenerator.cpp PythiaEventReader.cpp  G__CAPPythia.cxx)
target_link_libraries(CAPPythia  Base  Particles  PYTHIA8_LIB  ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
#target_link_libraries(CAPPythia  Base  Particles    ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
target_include_directories(CAPPythia  PUBLIC  Base  Particles CAPPythia ${PYTHIA_INCLUDE_PATH} ${PYTHIA_INCLUDE_PATH}/Pythia8 ${EXTRA_INCLUDES})

install(FILES  "${CMAKE_CURRENT_BINARY_DIR}/libCAPPythia.rootmap" "${CMAKE_CURRENT_BINARY_DIR}/libCAPPythia_rdict.pcm" DESTINATION "$ENV{CAP_LIB_PATH}")
install(TARGETS CAPPythia  LIBRARY DESTINATION "$ENV{CAP_LIB_PATH}") 
