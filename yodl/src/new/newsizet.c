#include "new.ih"

size_t *new_size_t(size_t value)
{
    size_t *ret = n_malloc(sizeof(size_t));
    *ret = value;

    return ret;
}
