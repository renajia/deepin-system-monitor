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

#ifndef CpuMONITOR_H
#define CpuMONITOR_H

#include <QList>
#include <QPointF>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>

class CpuMonitor : public QWidget
{
    Q_OBJECT
    
public:
    CpuMonitor(QWidget *parent = 0);
    ~CpuMonitor();
    
public slots:
    void render();
    void updateStatus(double cpuPercent);
    
protected:
    void paintEvent(QPaintEvent *event);
    
private:
    QImage iconImage;
    QList<double> *cpuPercents;
    QPainterPath cpuPath;
    QTimer *timer;
    double animationFrames = 20;
    int animationIndex = 0;
    int cpuRenderMaxHeight = 45;
    int iconPadding = 0;
    int iconRenderOffsetY = 195;
    int percentRenderOffsetY = 157;
    int pointsNumber = 24;
    int ringRadius = 90;
    int ringRenderOffsetY = 100;
    int ringWidth = 8;
    int titleAreaPaddingX = 5;
    int titleRenderOffsetY = 190;
    int waveformsRenderOffsetX = 80;
    int waveformsRenderOffsetY = 110;
};

#endif    
