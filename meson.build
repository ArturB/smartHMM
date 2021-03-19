# Project settings
project(
  # Project name and language
  'smarthmm', ['c', 'cpp'], 
  # Language standard (or other required options)
  default_options : ['c_std=c11','cpp_std=c++14']
  )

# Targets to build
TARGETS = {
  'smart-hmm': ['src/scientific/ml/smart-hmm.h'] # Specify each target name and list of its sources
}
# Project-wide binary dependencies
DEPS = [
#   dependency('openblas'),
#   dependency('armadillo'),
]
# Tests to compile
TESTS = {
   'test1': ['test/scientific/ml/test/smart-hmm.cc'] # Specify each test executable and list of its sources
}

# Build all specified targets
# and keep references to them in OBJECTS list
OBJECTS = []
foreach object, sources : TARGETS
  OBJECTS += library(       # Target may be executable or shared or static library
    object, sources,        # Process each target from TARGETS dictionary
    dependencies: DEPS,     # Binary dependencies
    include_directories: [] # Additional include dirs
  )
endforeach

# Build all specified tests
foreach test_object, sources : TESTS
  executable(
    test_object, sources,        # Process all tests from TESTS dictionary and place them in proper subdirectory
    link_with: OBJECTS,          # Link each test to all targets by default
    include_directories: ['src'] # Test executable usually depends on library headers
  )
endforeach
