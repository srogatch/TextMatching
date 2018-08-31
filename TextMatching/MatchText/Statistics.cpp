#include "stdafx.h"
#include "Statistics.h"

namespace {
  const std::string gPunctStr = ".,;:!?";
  const std::unordered_set<char> gPunctSet(gPunctStr.begin(), gPunctStr.end());
}

Statistics::Statistics(const std::string& text) {
  std::string lastToken;
  for (size_t i = 0; i < text.size(); i++) {
    int ch = static_cast<uint8_t>(text[i]);
    if (!isspace(ch)) {
      lastToken.push_back(tolower(ch));
      continue;
    }
    process(lastToken);
  }
  process(lastToken);
}

void Statistics::process(std::string& token) {
  do {
    if (token.size() == 0) {
      break;
    }
    if (gPunctSet.find(token.back()) != gPunctSet.end()) {
      token.pop_back();
    }
  } while (false);
  if (token.size() != 0) {
    auto it = _counts.find(token);
    if (it == _counts.end()) {
      _counts.emplace(token, 1);
    }
    else {
      it->second++;
    }
    _totWords++;
    token.clear();
  }
}

double Statistics::Dist(const Statistics& fellow) const {
  double sum = 0;
  for (const auto& wordInfo : _counts) {
    const std::string wordText = wordInfo.first;
    const double freq = double(wordInfo.second) / _totWords;
    auto it = fellow._counts.find(wordText);
    double fellowFreq;
    if (it == fellow._counts.end()) {
      fellowFreq = 0;
    }
    else {
      fellowFreq = double(it->second) / fellow._totWords;
    }
    const double d = freq - fellowFreq;
    sum += d * d;
  }
  return std::sqrt(sum);
}
