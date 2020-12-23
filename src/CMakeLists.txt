set(HEADER_FILES Student.h StudentAfterFirstSession.h StudentAfterSecondSession.h)
set(SOURCE_FILES Student.cpp StudentAfterFirstSession.cpp StudentAfterSecondSession.cpp)


add_library(src ${HEADER_FILES} ${SOURCE_FILES})