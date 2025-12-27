#pragma once

#include <vector>
#include "ArchiveRecord.hpp"

class ArchiveReport
{
public:
    static void printSummary(const std::vector<ArchiveRecord>& records);

    static void writeSummaryToFile(
        const std::vector<ArchiveRecord>& records,
        const std::string& filePath
    );

};