#ifndef WFCTILE_H
#define WFCTILE_H
#include <string>
#include <memory>

#include <QLabel>
#include <QPixmap>

class WFCTile {
public:
    WFCTile();
    WFCTile(const float length,const float height,const std::string& imagePath);
    std::shared_ptr<QLabel> GetPresenter() const;

private:
    float _length{.0f};
    float _height{.0f};
    std::string _imagePath{};

    std::shared_ptr<QLabel> _label{nullptr};
    QPixmap _pixMap{};
};

#endif // WFCTILE_H
