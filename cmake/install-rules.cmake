install(
    TARGETS json-playground_exe
    RUNTIME COMPONENT json-playground_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
