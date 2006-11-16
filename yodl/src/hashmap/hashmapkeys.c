#include "hashmap.ih"

void hashmap_keys(register HashMap *map)
{
    size_t idx;

    fprintf(stderr, "There are %u active keys\n", (unsigned int)map->d_n);

    for (idx = 0; idx < map->d_size; idx++)
    {
        register HashItem *atIdx = map->d_map[idx];

        switch ((size_t)atIdx)
        {
            case FREE:
            continue;

            case REMOVED:
                fprintf(stderr, "   %3d: <removed>\n", (int)idx);
            break;

            default:
                fprintf(stderr, "   %3d: `%s'\n", (int)idx, atIdx->d_key);
            break;
        }
    }
    fputs("[completed]\n", stderr);
}
