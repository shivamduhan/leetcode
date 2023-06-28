typedef struct Entry {
    int key;
    int value;
    struct Entry* next;
} Entry; //each hash table entry will have key value pair

typedef struct HashTable {
    Entry** buckets;
    int num_buckets;
} HashTable; //hash table is an array of buckets where each bucket holds frequencies

HashTable* hash_table_create(int num_buckets) {
    HashTable* hash_table = malloc(sizeof(HashTable));
    hash_table->buckets = calloc(num_buckets, sizeof(Entry*)); //init the buckets
    hash_table->num_buckets = num_buckets;
    return hash_table; //hash table created
}

Entry* hash_table_get(HashTable* hash_table, int key) {
    int bucket_index = abs(key) % hash_table->num_buckets; //retriece value of key
    Entry* entry = hash_table->buckets[bucket_index];
    while (entry != NULL && entry->key != key) {entry = entry->next;}
    return entry;
}

void hash_table_put(HashTable* hash_table, int key, int value) {
    int bucket_index = abs(key) % hash_table->num_buckets;
    Entry* existing_entry = hash_table_get(hash_table, key);
    if (existing_entry != NULL) {
        existing_entry->value = value;
    } else {
        Entry* new_entry = malloc(sizeof(Entry));
        new_entry->key = key;
        new_entry->value = value;
        new_entry->next = hash_table->buckets[bucket_index];
        hash_table->buckets[bucket_index] = new_entry;
    }
}

void hash_table_destroy(HashTable* hash_table) {
    for (int i = 0; i < hash_table->num_buckets; i++) {
        Entry* entry = hash_table->buckets[i];
        while (entry != NULL) {
            Entry* next_entry = entry->next;
            free(entry);
            entry = next_entry;
        }
    }
    free(hash_table->buckets);
    free(hash_table);
}

int longestConsecutive(int * nums, int numsSize) {
    HashTable* hash_table = hash_table_create(numsSize);
    for (int i = 0; i < numsSize; i++) {hash_table_put(hash_table, nums[i], i);}
    int longestStreak = 0;
    for (int i = 0; i < numsSize; i++) {
        if (!hash_table_get(hash_table, nums[i] - 1)) {
            int currentNum = nums[i];
            int currentStreak = 1;
            while (hash_table_get(hash_table, currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }
            if (currentStreak > longestStreak) {
                longestStreak = currentStreak;
            }
        }
    }
    hash_table_destroy(hash_table);
    return longestStreak;    
}
