# 3.0 because of "The NEW behavior", CMP0048
cmake_minimum_required (VERSION 3.0)

cmake_policy(SET CMP0048 NEW)

project (fact
	VERSION 1.2.3.4
	LANGUAGES C)

configure_file (
	"${PROJECT_SOURCE_DIR}/inc/factConfig.h.in"
	"${PROJECT_BINARY_DIR}/inc/factConfig.h"
	)


include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories(${PROJECT_BINARY_DIR}/inc)
subdirs(src)

