#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "hellolib::hellolib" for configuration ""
set_property(TARGET hellolib::hellolib APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(hellolib::hellolib PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libhellolib.so"
  IMPORTED_SONAME_NOCONFIG "libhellolib.so"
  )

list(APPEND _cmake_import_check_targets hellolib::hellolib )
list(APPEND _cmake_import_check_files_for_hellolib::hellolib "${_IMPORT_PREFIX}/lib/libhellolib.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
