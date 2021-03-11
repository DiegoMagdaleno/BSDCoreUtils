macro(install_symlink filepath sympath)
    install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${filepath} $ENV{DESTDIR}${sympath})")
    install(CODE "message(\"-- Created symlink: ${sympath} -> $ENV{DESTDIR}${filepath}\")")
endmacro(install_symlink)