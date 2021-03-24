//
// Created by Junior Trust on 3/5/2020.
//

#ifndef SOURCEAFIS_CPP_LOGGER_H
#define SOURCEAFIS_CPP_LOGGER_H

#include <string>


#define SPDLOG

#if defined(SPDLOG)

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h" // or "../stdout_sinks.h" if no colors needed
#include "spdlog/fmt/ostr.h" // must be included


class SpdlogImpl {

    static std::vector<spdlog::sink_ptr> sinks;
    std::shared_ptr<spdlog::logger> _logger;

    static std::shared_ptr<spdlog::logger> spdFactory(const std::string &name) {

        std::shared_ptr<spdlog::logger> logger = spdlog::get(name);
        if (!logger) {
            logger = std::make_shared<spdlog::logger>(name, sinks.begin(), sinks.end());
            // globally register the loggers so so the can be accessed using spdlog::get(logger_name)
            spdlog::register_logger(logger);
        }

        return logger;

    }

public:
    explicit SpdlogImpl(const std::string &name) noexcept : _logger(spdFactory(name)) {

    }

    template<typename... Args>
    void trace(const std::string &fmt, const Args &... args) const {
        _logger->trace(fmt, args...);
    }

    template<typename... Args>
    void debug(const std::string &fmt, const Args &... args) const {
        _logger->debug(fmt, args...);
    }

    template<typename... Args>
    void info(const std::string &fmt, const Args &... args) const {
        _logger->info(fmt, args...);
    }

    template<typename... Args>
    void warn(const std::string &fmt, const Args &... args) const {
        _logger->warn(fmt, args...);
    }

    template<typename... Args>
    void error(const std::string &fmt, const Args &... args) const {
        _logger->error(fmt, args...);
    }

    template<typename... Args>
    void critical(const std::string &fmt, const Args &... args)const {
        _logger->critical(fmt, args...);
    }


    template<typename T>
    void trace(const T &msg)const {
        _logger->trace(msg);
    }

    template<typename T>
    void debug(const T &msg) const {
        _logger->debug(msg);
    }

    template<typename T>
    void info(const T &msg) const {
        _logger->info(msg);
    }

    template<typename T>
    void warn(const T &msg) const {
        _logger->warn(msg);
    }

    template<typename T>
    void error(const T &msg) const {
        _logger->error(msg);
    }

    template<typename T>
    void critical(const T &msg) const {
        _logger->critical(msg);
    }


};

std::vector<spdlog::sink_ptr> SpdlogImpl::sinks = {
        std::make_shared<spdlog::sinks::daily_file_sink_mt>("logs/daily.txt", 23, 59),
        std::make_shared<spdlog::sinks::stdout_color_sink_mt>()
};

typedef  SpdlogImpl Logger;
#else
class NoImpl {


public:
    explicit NoImpl(const std::string &name)noexcept {

    }

    template<typename... Args>
    void trace(const std::string &fmt, const Args &... args) {

    }

    template<typename... Args>
    void debug(const std::string &fmt, const Args &... args) {

    }

    template<typename... Args>
    void info(const std::string &fmt, const Args &... args) {

    }

    template<typename... Args>
    void warn(const std::string &fmt, const Args &... args) {

    }

    template<typename... Args>
    void error(const std::string &fmt, const Args &... args) {

    }

    template<typename... Args>
    void critical(const std::string &fmt, const Args &... args) {

    }


    template<typename T>
    void trace(const T &msg) {

    }

    template<typename T>
    void debug(const T &msg) {

    }

    template<typename T>
    void info(const T &msg) {

    }

    template<typename T>
    void warn(const T &msg) {

    }

    template<typename T>
    void error(const T &msg) {

    }

    template<typename T>
    void critical(const T &msg) {

    }


};
typedef  NoImpl Logger;
#endif


/*
class Logger : public CurImpl


{

    Logger(const std::string &name) :CurImpl(name) {

    }
};
*/


#endif //SOURCEAFIS_CPP_LOGGER_H
