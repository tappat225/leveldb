#include <iostream>
#include <cassert>
#include "leveldb/db.h"

int main()
{
    //open database
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);

    if (!status.ok()) 
    {
        std::cout << "open db failed" << std::endl;
        return -1;
    }
    
    std::string key, value, op;
    while (1) {
        printf("> ");
        op.clear();
        key.clear();
        value.clear();
        std::cin >> op;
        if (op == "set") {
            std::cin >> key >> value;
            leveldb::Status s = db->Put(leveldb::WriteOptions(), key, value);
            if (s.ok()) {
                printf("Set kv success.\n");
            }
        } else if (op == "show") {
            std::cin >> key;
            leveldb::Status s = db->Get(leveldb::ReadOptions(), key, &value);
            if (s.ok()) {
                std::cout << value << std::endl;
            }
        } else if (op == "quit") {
            break;
        } else {
            printf("Invalid operation.\n");
            continue;
        }
    }
    
    //close database
    delete db;

    return 0;
}
