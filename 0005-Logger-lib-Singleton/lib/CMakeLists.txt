# to make the static lib (.a)
add_library( mylog STATIC src/logger.cpp )
# # to make the shared lib (.so)
# add_library( mylog SHARED src/logger.cpp )

target_include_directories(mylog PUBLIC ./include/)
