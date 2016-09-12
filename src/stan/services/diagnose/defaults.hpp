#ifndef STAN_SERVICES_DIAGNOSE_DEFAULTS_HPP
#define STAN_SERVICES_DIAGNOSE_DEFAULTS_HPP

#include <stdexcept>
#include <string>

namespace stan {
  namespace services {
    namespace diagnose {

      /**
       * Epsilon is the finite differences stepsize.
       */
      struct epsilon {

        /**
         * Description of epsilon.
         *
         * @returns description
         */
        static std::string description() {
          return "Finite difference stepsize.";
        }

        /**
         * Validates epsilon; epsilon must be greater than 0.
         *
         * @param[in] epsilon argument to validate
         * @throw std::invalid_argument if epsilon <= 0
         */
        static void validate(double epsilon) {
          if (!(epsilon > 0))
            throw std::invalid_argument("epsilon must be greater than 0.");
        }

        /**
         * Default error value: 1e-6.
         *
         * @returns default
         */
        static double default_value() {
          return 1e-6;
        }
      };


      /**
       * Error is the absolute error threshold for evaluating
       * gradients relative to the finite differences calculation.
       */
      struct error {

        /**
         * Description of error.
         *
         * @returns description
         */
        static std::string description() {
          return "Absolute error threshold.";
        }

        /**
         * Validates error; error must be greater than 0.
         *
         * @throw std::invalid_argument if error <= 0
         * equal to 0.
         */
        static void validate(double error) {
          if (!(error > 0))
            throw std::invalid_argument("error must be greater than 0.");
        }

        /**
         * Default error value: 1e-6.
         *
         * @returns default
         */
        static double default_value() {
          return 1e-6;
        }
      };

    }
  }
}
#endif