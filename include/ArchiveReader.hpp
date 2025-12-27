#pragma once
#include <string>
#include <vector>
#include "ArchiveRecord.hpp"

class ArchiveReader
{
public:

    ArchiveReader(const std::string& path);
    std::vector <ArchiveRecord> readAll() const;

private:

    std::string path_;

};