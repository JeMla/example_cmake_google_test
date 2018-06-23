# 3.0 because of "The NEW behavior", CMP0048
cmake_minimum_required (VERSION 3.0)

cmake_policy(SET CMP0048 NEW)

project (fact
	VERSION 1.0
	LANGUAGES C)

include_directories(${PROJECT_SOURCE_DIR}/inc)
subdirs(src)

