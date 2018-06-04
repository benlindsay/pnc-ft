// summary_output.hpp
//
// Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

#ifndef SUMMARY_OUTPUT_HPP
#define SUMMARY_OUTPUT_HPP

#include "../output.hpp"

class Output;

class Summary_Output : public Output {
 public:
  Summary_Output(Sim *sim, std::vector<std::string> var_list, int print_freq,
                 std::string file_name, int column_width);
  Summary_Output(Sim *sim, std::vector<std::string> var_list);
  virtual ~Summary_Output();
  virtual void write(void);
  virtual bool is_time_to_write(void);
  static const std::string default_file_name;

 private:
  int print_freq;
  int column_width;
  std::vector<std::string> var_list;
  std::string file_name;
  std::ofstream file;
  void init(Sim *sim, std::vector<std::string> var_list, int print_freq,
            std::string file_name, int column_width);
  void init(Sim *sim, std::vector<std::string> var_list);
};

#endif  // SUMMARY_OUTPUT_HPP