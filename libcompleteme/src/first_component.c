#include "first_component.h"

struct list *
get_comp_of_path (const char *path)
{
    struct list *result;
    size_t count = 0;
    char* last_splitter = 0;
    char *token;
    const char delim[2] = "/";
    

    char* tmp = (char *)malloc(strlen(path));
    strcpy(tmp, path);

    token = strtok(tmp, delim);

    result = new_list();
    
    while (token != NULL) {
        append(result, token);

        token = strtok(NULL, delim);
    }

    return result;
}