#pragma once

class Statistics {
  std::unordered_map<std::string, int64_t> _counts;
  int64_t _totWords;

  void process(std::string& token);
public:
  explicit Statistics(const std::string& text);

  double Dist(const Statistics& fellow) const;

  bool IsEmpty() const { return _totWords == 0; }
};
