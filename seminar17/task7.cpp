/*
    Works with string, vector libraries
    A logging system with filtering by importance level and categories
*/

#include <iostream>
#include <string>
#include <vector>

enum class LogLevel {
    DEBUG = 1 << 0, INFO = 1 << 1, WARNING = 1 << 2, ERROR = 1 << 3, CRITICAL = 1 << 4
};

LogLevel operator|(LogLevel _per1, LogLevel _per2) {
    return (LogLevel)(((int)(_per1) | (int)(_per2)));
}

LogLevel operator&(LogLevel _per1, LogLevel _per2) {
    return (LogLevel)(((int)(_per1) & (int)(_per2)));
}

LogLevel operator~(LogLevel _per) {
    return (LogLevel)((int)(_per));
}

enum class LogCategory {
    NETWORK = 1 << 0, DATABASE = 1 << 1, UI = 1 << 2, SECURITY = 1 << 3, PERFORMANCE = 1 << 4
};

LogCategory operator|(LogCategory _per1, LogCategory _per2) {
    return (LogCategory)(((int)(_per1) | (int)(_per2)));
}

LogCategory operator&(LogCategory _per1, LogCategory _per2) {
    return (LogCategory)(((int)(_per1) & (int)(_per2)));
}

LogCategory operator~(LogCategory _per) {
    return (LogCategory)((int)(_per));
}

struct LogEntry {
    LogLevel level;
    LogCategory cat;
    //int timestamp;
    std::string mess;
};

std::string toString(LogLevel level) {
    switch (level) {
        case LogLevel::DEBUG:
            return "DEBUG";
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::CRITICAL:
            return "CRITICAL";
    }
    return "UNKNOWN";
}

std::string toString(LogCategory cat) {
    switch (cat) {
        case LogCategory::NETWORK:
            return "NETWORK";
        case LogCategory::DATABASE:
            return "DATABASE";
        case LogCategory::UI:
            return "UI";
        case LogCategory::SECURITY:
            return "SECURITY";
        case LogCategory::PERFORMANCE: 
            return "PERFORMANCE";
    }
    return "UNKNOWN";
}

void filterLogs(const LogEntry& entry) {
    std::cout << "[" << toString(entry.level) << "]" << " [" << toString(entry.cat) << "] " << entry.mess << '\n';
}


void filterLogsHelp(LogCategory cat) {
    
}

int main() {
    LogEntry log1 = {LogLevel::INFO, LogCategory::NETWORK, "Соединение установлено"};
    LogEntry log2 = {LogLevel::ERROR, LogCategory::DATABASE, "Не удалось выполнить запрос"};
    LogEntry log3 = {LogLevel::DEBUG, LogCategory::UI, "Кнопка нажата"};
    LogEntry log4 = {LogLevel::CRITICAL, LogCategory::SECURITY, "Попытка несанкционированного доступа"};
    std::vector<LogEntry> logs = {log1, log2, log3, log4};
    for (auto& lo : logs) {
        filterLogs(lo);
    }
    LogLevel minLevel = LogLevel::WARNING;
    LogCategory activeCategories = LogCategory::DATABASE | LogCategory::SECURITY;
    /*
    ---output---
    [INFO] [NETWORK] Соединение установлено
    [ERROR] [DATABASE] Не удалось выполнить запрос
    [DEBUG] [UI] Кнопка нажата
    [CRITICAL] [SECURITY] Попытка несанкционированного доступа
    */
    return 0;
}