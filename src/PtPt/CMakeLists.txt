################################################################################################
# Project CAP/PtPt
################################################################################################
ROOT_GENERATE_DICTIONARY(G__PtPt PtPtHistos.hpp PtPtDerivedHistos.hpp  PtPtAnalyzer.hpp PtPtCalculator.hpp LINKDEF PtPtLinkDef.h)

################################################################################################
# Create a shared library with geneated dictionary
################################################################################################
add_compile_options(-Wall -Wextra -pedantic)
add_library(PtPt SHARED PtPtHistos.cpp PtPtDerivedHistos.cpp PtPtAnalyzer.cpp PtPtCalculator.cpp G__PtPt.cxx)

target_link_libraries(PtPt Base  Particles  ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
target_include_directories(PtPt  PUBLIC Base  Particles  PtPt ${EXTRA_INCLUDES} ) 

install(FILES  "${CMAKE_CURRENT_BINARY_DIR}/libPtPt.rootmap" "${CMAKE_CURRENT_BINARY_DIR}/libPtPt_rdict.pcm" DESTINATION "$ENV{CAP_LIB_PATH}")
install(TARGETS PtPt  LIBRARY DESTINATION "$ENV{CAP_LIB_PATH}")

