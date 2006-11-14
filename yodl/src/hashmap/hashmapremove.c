#include "hashmap.ih"

void hashmap_remove(register HashMap *map, size_t idx)
{
    free(map->d_map[idx]);
    map->d_map[idx] = (HashItem *)~0;
    map->d_n--;
}
