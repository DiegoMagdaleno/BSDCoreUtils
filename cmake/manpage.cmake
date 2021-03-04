FUNCTION(INSTALL_MANPAGE file)
    # Is not like they run on anything else but you never know
    IF(NOT UNIX)
        RETURN()
    ENDIF()
    GET_FILENAME_COMPONENT(file_name "{$file}" NAME)
    SET(GLOB_EXPR
        ${CMAKE_SOURCE_DIR}/*${file}man.1*
        ${CMAKE_SOURCE_DIR}/*${file}man.7*
        ${CMAKE_SOURCE_DIR}/*${file}man.8*
        ${CMAKE_SOURCE_DIR}/*${file}.1*
        ${CMAKE_SOURCE_DIR}/*${file}.7*
        ${CMAKE_SOURCE_DIR}/*${file}.8*
        ${GLOB_EXPR}
    )
    
    FILE(GLOB_RECURSE MANPAGES ${GLOB_EXPR})
    IF(MANPAGES)
        LIST(GET MANPAGES 0 MANPAGE)
        STRING(REPLACE "${file}man.1" "${file}.1" MANPAGE "${MANPAGE}")
        STRING(REPLACE "${file}man.7" "${file}.7" MANPAGE "${MANPAGE}")
        STRING(REPLACE "${file}man.8" "${file}.8" MANPAGE "${MANPAGE}")
        IF(MANPAGE MATCHES "${file}.1")
            SET(SECTION man1)
        ELSEIF(MANPAGE MATCHES "{file}.7")
            SET(SECTION man7)
        ELSEIF(MANPAGE MATCHES "{file}.8")
            SET(SECTION man8)
        ENDIF()
        INSTALL(FILES "{MANPAGE}" DESTINATION "${INSTALL_MANDIR}/${SECTION}" 
        COMPONENT ManPages)
    ENDIF()
ENDFUNCTION()
        
