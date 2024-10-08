################################################################################################
# Project CAP/Math
################################################################################################
ROOT_GENERATE_DICTIONARY(G__Math Complex.hpp Vector3.hpp  VectorLorentz.hpp VectorField.hpp LINKDEF MathLinkDef.h)

################################################################################################
# Create a shared library with geneated dictionary
################################################################################################
add_compile_options(-Wall -Wextra -pedantic)
add_library(Math SHARED MathConstants.cpp MathExceptions.cpp  MathBasicFunctions.cpp MathBasicGeometry.cpp MathBasicSearch.cpp MathBasicInterpolation.cpp  MathBasicIntegration.cpp MathBasicSortingFunctions.cpp MathBasicStatistics.cpp BesselFunctions.cpp Complex.cpp Vector3.cpp VectorLorentz.cpp VectorField.cpp G__Math.cxx)

target_link_libraries(Math Base ${ROOT_LIBRARIES} ${EXTRA_LIBS} )
target_include_directories(Math  PUBLIC Base ${EXTRA_INCLUDES} )

install(FILES  "${CMAKE_CURRENT_BINARY_DIR}/libMath.rootmap" "${CMAKE_CURRENT_BINARY_DIR}/libMath_rdict.pcm" DESTINATION "$ENV{CAP_LIB_PATH}")
install(TARGETS Math  LIBRARY DESTINATION "$ENV{CAP_LIB_PATH}")

