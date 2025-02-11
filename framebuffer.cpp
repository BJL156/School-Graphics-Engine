#include "framebuffer.h"

Framebuffer::Framebuffer(
    const std::uint32_t &width,
    double aspectRatio)
    : m_width(width), m_height(width / aspectRatio) {
    std::uint32_t pixelCount = m_width * m_height;
    createColorAttachment(pixelCount);
    createDepthBuffer(pixelCount);
}

Framebuffer::~Framebuffer() {

}

void Framebuffer::setPixel(
    const std::uint32_t &x,
    const std::uint32_t &y,
    const Vec3 &color,
    double depth) {
    if (x > m_width + 1 ||
        y > m_height + 1) {
        throw std::out_of_range("Pixel coordinates are out of range.");
    }

    std::uint32_t index = y * m_width + x;

    if (depth < m_depthBuffer[index]) {
        m_colorAttachment[index] = color;

        m_depthBuffer[index] = depth;
    }
}

void Framebuffer::clear() {
    std::fill(
        m_colorAttachment.begin(),
        m_colorAttachment.end(),
        m_clearColor);

    std::fill(
        m_depthBuffer.begin(),
        m_depthBuffer.end(),
        std::numeric_limits<double>::infinity());
}

void Framebuffer::present() {
    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            std::string ansiString = getAnsiString(m_colorAttachment[y * m_width + x]);
            std::cout << ansiString << "  ";
        }

        resetTerminal();
        std::cout << '\n';
    }
}

const std::uint32_t Framebuffer::getWidth() const {
    return m_width;
}

const std::uint32_t Framebuffer::getHeight() const {
    return m_height;
}

void Framebuffer::createColorAttachment(const std::uint32_t &pixelCount) {
    m_colorAttachment.resize(pixelCount, m_clearColor);
}

void Framebuffer::createDepthBuffer(const std::uint32_t &pixelCount) {
    m_depthBuffer.resize(pixelCount, std::numeric_limits<double>::infinity());
}