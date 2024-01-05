#pragma once
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <sstream>

class Buffer {
    std::fstream fs;
    std::string m_name = "out.ppm";
    std::string m_buffer;
    unsigned long long m_size;

    void _buffer(char* buf, unsigned int size) {
        m_buffer.append(buf, size);
        m_size = m_buffer.size();
    }

  public:
    Buffer(int height, int width) {
        m_buffer = std::string("P3\n");
        std::ostringstream fmt;
        fmt << width << ' ' << height << "\n255\n"; 
        m_buffer.append(fmt.str());

        m_size = m_buffer.size();

        fs.open(m_name, std::ios::out | std::ios::trunc);
        if (!fs.is_open()) {
            std::cerr << "Error opening file: " << m_name << '\n';
        }
    }

    ~Buffer() {
        fs.close();
    }

    std::string& buffer() {
        return m_buffer;
    }

    void flush() {
        fs.write(m_buffer.c_str(), (std::streamsize)m_size);
        if (!fs) {
            std::cerr << "Error writing to file: " << m_name << '\n';
        }
    }

    friend Buffer& operator<<(Buffer& buf, std::string& str) {
        buf._buffer(str.data(), (unsigned int)str.size());
        return buf;
    }

    friend Buffer& operator<<(Buffer& buf, char chr) { 
        buf._buffer(&chr, sizeof(char));
        return buf;
    }

    friend Buffer& operator<<(Buffer& buf, int val) {
        auto str = std::to_string(val);
        buf._buffer(str.data(), (unsigned int)str.size());
        return buf;
    }
};