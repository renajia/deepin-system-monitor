/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2011 ~ 2017 Deepin, Inc.
 *               2011 ~ 2017 Wang Yong
 *
 * Author:     Wang Yong <wangyong@deepin.com>
 * Maintainer: Wang Yong <wangyong@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */ 

#ifndef PROCESSSWITCHTAB_H
#define PROCESSSWITCHTAB_H

#include <QMouseEvent>
#include <QWidget>

class ProcessSwitchTab : public QWidget 
{
    Q_OBJECT
    
public:
    ProcessSwitchTab(QWidget *parent = 0);
    
    void mouseMoveEvent(QMouseEvent *mouseEvent);
    void mousePressEvent(QMouseEvent *mouseEvent);
    void paintEvent(QPaintEvent *);
    
signals:
    void activeTab(int index);
    
protected:
    virtual void leaveEvent(QEvent * event);
    
private:
    QImage allProcessActiveImage;
    QImage allProcessHoverImage;
    QImage allProcessNormalImage;
    QImage onlyGuiActiveImage;
    QImage onlyGuiHoverImage;
    QImage onlyGuiNormalImage;
    QImage onlyMeActiveImage;
    QImage onlyMeHoverImage;
    QImage onlyMeNormalImage;
    int activeIndex = 0;
    int height = 24;
    int hoverIndex = -1;
    int width = 26;
};

#endif 
