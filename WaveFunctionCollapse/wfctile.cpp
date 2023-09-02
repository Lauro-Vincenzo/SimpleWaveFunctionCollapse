#include "wfctile.h"
#include <memory>

#include <QLabel>
#include <QPixmap>

#include "tilepresenter.h"

WFCTile::WFCTile(){
}

WFCTile::WFCTile(const float length,const float height, const std::string& imagePath) : _length(length), _height(height), _imagePath(imagePath){
    _label = std::make_shared<QLabel>();
    _pixMap = QPixmap();

    _pixMap.load(QString(_imagePath.c_str()));
    _label->setPixmap(_pixMap);
    _label->setFixedSize(length,height);
    auto labelStyle = QString("border: 1px solid black;");
    _label->setStyleSheet(labelStyle);
}

std::shared_ptr<QLabel> WFCTile::GetPresenter() const{
    return _label;
}
