# 3.0 because of "The NEW behavior", CMP0048
cmake_minimum_required (VERSION 3.0)

cmake_policy(SET CMP0048 NEW)

project (fact
	VERSION 1.2.3.4
	LANGUAGES C)

add_library(fact ${PROJECT_SOURCE_DIR}/src/fact.c)

configure_file (
	"${PROJECT_SOURCE_DIR}/inc/factConfig.h.in"
	"${PROJECT_BINARY_DIR}/inc/factConfig.h"
	)

include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories(${PROJECT_BINARY_DIR}/inc)

# install(TARGETS fact DESTINATION ${PROJECT_BINARY_DIR}/install/lib)
# install(FILES ${PROJECT_BINARY_DIR}/inc/factConfig.h DESTINATION ${PROJECT_BINARY_DIR}/install/include)
# install(FILES ${PROJECT_SOURCE_DIR}/inc/fact.h DESTINATION ${PROJECT_BINARY_DIR}/install/include)
