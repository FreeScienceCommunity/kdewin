set(CMAKE_DEBUG_POSTFIX "d")

if(MINGW)
    add_library(wbemuuid STATIC wbemuuid.cpp)

install(TARGETS wbemuuid
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
)

endif(MINGW)
