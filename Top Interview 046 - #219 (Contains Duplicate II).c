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
    int bucket_index = abs(key) % hash_table->num_buckets; //hash to get which bucket to search
    Entry* entry = hash_table->buckets[bucket_index];
    while (entry != NULL && entry->key != key) {entry = entry->next;} //traverse linked list at that index
    return entry;
}

void hash_table_put(HashTable* hash_table, int key, int value) {
    int bucket_index = abs(key) % hash_table->num_buckets; //hash to get which bucket to store val
    Entry* existing_entry = hash_table_get(hash_table, key); //get existing val at key to check collisions
    if (existing_entry != NULL) {
        existing_entry->value = value; //no collisions, just add
    } else {
        Entry* new_entry = malloc(sizeof(Entry)); //collision, add node at beginning of linked list
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
    free(hash_table->buckets); //deallocate memory for buckets
    free(hash_table); //deallocate memory for table
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    HashTable* hash_table = hash_table_create(numsSize);
    for (int i = 0; i < numsSize; i++) {
        Entry* existing_entry = hash_table_get(hash_table, nums[i]);
        if (existing_entry != NULL && i - existing_entry->value <= k) {
            hash_table_destroy(hash_table);
            return true;
        }
        hash_table_put(hash_table, nums[i], i);
    }
    hash_table_destroy(hash_table);
    return false;
}
