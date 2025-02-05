#pragma once

#include <string>

#include "constraints.h"

#define DEVICE_PATH "/proc/device-tree/model"

struct device_type {
    enum type {
        unknown,
        jetson,
        pi
    };
    type value;
    std::string name;

    device_type() : value(unknown), name("unknown") {} // Default constructor
    device_type(type value, std::string name) : value(value), name(name) {}
};

struct device_params {
    std::string input_source;
    std::string input_format;
    std::string video_converter;
    std::string output_encoder;
};

device_type get_device_type();
device_params get_device_params(device_type device);
