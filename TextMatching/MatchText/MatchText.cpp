#include "stdafx.h"
#include "Statistics.h"
#include "Utils.h"
namespace fs = std::experimental::filesystem;

struct RepoEntry {
  std::string _filePath;
  double _dist;

  RepoEntry(const std::string& filePath, const double dist) : _filePath(filePath), _dist(dist) { }
  bool operator<(const RepoEntry& fellow) const {
    return _dist < fellow._dist;
  }
};

int main(int argc, char *argv[])
{
  if (argc < 3) {
    printf("Usage: %s <Sample File> <Repository Directory>", argv[0]);
    return 1;
  }
  const std::string sampleText = ReadAllText(argv[1]);
  if (sampleText.empty()) {
    fprintf(stderr, "Sample file must be non-empty: this corner case is not supported.\n");
    return 2;
  }
  const Statistics sampleStat(sampleText);
  std::vector<RepoEntry> entries;
  for (const fs::directory_entry& repoFile : fs::directory_iterator(argv[2])) {
    const std::string repoFilePath = repoFile.path().string();
    if (repoFilePath == "." || repoFilePath == "..") {
      continue;
    }
    const std::string repoText = ReadAllText(repoFilePath);
    const Statistics repoStat(repoText);
    if (repoStat.IsEmpty()) {
      fprintf(stderr, "Skipping empty file %s", repoFilePath.c_str());
      continue;
    }
    entries.emplace_back(repoFilePath, sampleStat.Dist(repoStat));
  }
  std::sort(entries.begin(), entries.end());
  for (size_t i = 0; i < entries.size(); i++) {
    fprintf(stdout, "%.16lg %s\n", entries[i]._dist, entries[i]._filePath.c_str());
  }
  return 0;
}
