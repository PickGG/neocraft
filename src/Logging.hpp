#pragma once

#include <SDL3/SDL_log.h>

#define LOG_TRACE(fmt, ...) SDL_LogTrace(SDL_LOG_CATEGORY_APPLICATION, fmt __VA_OPT__(,) __VA_ARGS__)
#define LOG_INFO(fmt, ...)  SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, fmt __VA_OPT__(,) __VA_ARGS__)
#define LOG_DEBUG(fmt, ...) SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, fmt __VA_OPT__(,) __VA_ARGS__)
#define LOG_ERROR(fmt, ...) SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, fmt __VA_OPT__(,) __VA_ARGS__)
#define LOG_CRIT(fmt, ...) SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, fmt __VA_OPT__(,) __VA_ARGS__)
