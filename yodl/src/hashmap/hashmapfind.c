#include "hashmap.ih"

/* Returns pointer to HashItem corresponding to  searched element or PFAILED */

HashItem *hashmap_find(register HashMap *map, char const *key, SymbolType type)
{
    unsigned idx = hm_find_idx(map, key, type);

    return idx == FAILED ? PFAILED : map->d_map[idx];
}