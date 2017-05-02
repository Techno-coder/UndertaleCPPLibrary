#ifndef PROJECT_LOGGER_H
#define PROJECT_LOGGER_H

#include <string>

#define DEBUG_MODE

namespace ug {
    class Logger {
        static Logger logger;
        Logger();

        const time_t start;

        /**
         * Get the time since program launch
         * @return A string representation of the minutes and seconds since launch
         */
        std::string getStringTime();
    public:

        /**
         * Get the logger instance
         * @return The logger instance
         */
        static Logger& instance();

        /**
         * Print an error log message
         * @param module The module that the error came from
         * @param message The message to print
         */
        void error(const std::string &module, const std::string &message);

        /**
         * Print a warning log message
         * @param module The module that the warning came from
         * @param message The message to print
         */
        void warning(const std::string &module, const std::string &message);

        /**
         * Print an information log message
         * @param module The module that the information message came from
         * @param message The message to print
         */
        void info(const std::string &module, const std::string &message);

        /**
         * Print a debug message
         * @param module The module that the debug message came from
         * @param message The message to print
         */
        void debug(const std::string &module, const std::string &message);
    };
}

#endif //PROJECT_LOGGER_H
