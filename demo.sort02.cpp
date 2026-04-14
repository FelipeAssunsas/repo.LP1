/*! This program simulates a random dice. */

#include <iostream>
#include <limits>
#include <optional>
#include <stdexcept>
#include <string>

using value_type = unsigned short;
constexpr value_type default_faces{ 6 };
constexpr value_type defatul_rolls{ 1 };

struct RunningOptions {
  value_type n_faces{ default_faces };
  value_type n_rolls{ defatul_rolls };
  bool show_sum{ false };
  bool show_stats{ false };
  bool verbose{ false };
};

void usage(const std::string& msg = "") {
  if (not msg.empty()) {
    std::cout << "Error: " << msg << "\n";
  } else {
    std::cout << " -- Welcome to dice simulation --\n";
  }
  std::cout << "Usage: dice [<options>]\n"
            << "  --sides n   The number (>0) of dice faces (default is " << default_faces
            << ", max is " << std::numeric_limits<value_type>::max() << ")\n"
            << "  --rolls n   Defines how many times (>0) the dice is rolled "
               "(default is "
            << defatul_rolls << ", max is " << std::numeric_limits<value_type>::max() << ")\n"
            << "  --sum       Prints the sum of all rolled faces\n"
            << "  --stats     Prints min, max and median of the values rolled\n"
            << "  --verbose   Prints extra information\n"
            << "  -h, --help  Show this help screen.\n\n";
  // exit(msg.empty() ? EXIT_SUCCESS : EXIT_FAILURE);
  exit(0);
}

/*!
 * Esta função retornar um valor inteiro correspondente a string `valu_str`.
 * Se a conversão falhar, a função retornar um optional vazio.
 * @param valu_str Valor a ser convertido na forma de string.
 * @return Valor convertido ou optional vazio se falhar.
 */

std::optional<value_type> validate_number(const std::string& value_str) {
  value_type temp{ 0 };
  try {
    temp = std::stoi(value_str);
  } catch (const std::invalid_argument& e) {
    return {};

  } catch (const std::out_of_range& e) {
    return {};
  }

  return { temp };
}

RunningOptions validate_cli(int argc, char* argv[]) {
  RunningOptions run_opt;

  // Percorrer os argumentos cli
  for (short idx{ 1 }; idx < argc; idx++) {
    std::string argument{ argv[idx] };  // Converte para string.
    if (argument == "--sides") {
      if (idx + 1 < argc) {
        // Tentar converter para inteiro
        auto temp_val = validate_number(argv[++idx]);
        if (not temp_val.has_value()) {
          usage("The value provided for --sides is invalid or out of range.");
        }
        // Valor ok, salvar no run_opt
        run_opt.n_faces = temp_val.value();
      } else {
        usage("Missing value for --sides");
      }
    } else if (argument == "--rolls") {
    }
  }

  return run_opt;
}

int main(int argc, char* argv[]) {
  // [1]: Make sure we've got valid arguments.
  auto run_opt = validate_cli(argc, argv);

  // [2]: Roll dice

  // [3]: Show the rolling dice results.

  // [4]: Show sum

  // [5]: Calculate statistics, if required.

  return 0;
}

