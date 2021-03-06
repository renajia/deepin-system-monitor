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

#include "process_switch_tab.h"
#include "utils.h"

ProcessSwitchTab::ProcessSwitchTab(QWidget *parent) : QWidget(parent)
{
    installEventFilter(this);   // add event filter
    setMouseTracking(true);    // make MouseMove can response
    
    setFixedSize(width * 3, height);
    
    onlyGuiNormalImage = QImage(Utils::getQrcPath("only_gui_normal.png"));
    onlyGuiHoverImage = QImage(Utils::getQrcPath("only_gui_hover.png"));
    onlyGuiActiveImage = QImage(Utils::getQrcPath("only_gui_active.png"));
    onlyMeNormalImage = QImage(Utils::getQrcPath("only_me_normal.png"));
    onlyMeHoverImage = QImage(Utils::getQrcPath("only_me_hover.png"));
    onlyMeActiveImage = QImage(Utils::getQrcPath("only_me_active.png"));
    allProcessNormalImage = QImage(Utils::getQrcPath("all_process_normal.png"));
    allProcessHoverImage = QImage(Utils::getQrcPath("all_process_hover.png"));
    allProcessActiveImage = QImage(Utils::getQrcPath("all_process_active.png"));
}

void ProcessSwitchTab::mouseMoveEvent(QMouseEvent *mouseEvent)
{
    int prevHoverIndex = hoverIndex;
    
    if (mouseEvent->x() < width) {
        hoverIndex = 0;
    } else if (mouseEvent->x() < width * 2) {
        hoverIndex = 1;
    } else {
        hoverIndex = 2;
    }
    
    if (hoverIndex != prevHoverIndex) {
        repaint();
    }
}

void ProcessSwitchTab::mousePressEvent(QMouseEvent *mouseEvent)
{
    int prevActiveIndex = activeIndex;
    
    if (mouseEvent->x() < width) {
        activeIndex = 0;
    } else if (mouseEvent->x() < width * 2) {
        activeIndex = 1;
    } else {
        activeIndex = 2;
    }
    
    if (activeIndex != prevActiveIndex) {
        activeTab(activeIndex);
        
        repaint();
    }
}

void ProcessSwitchTab::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int penSize = 1;
    
    QPainterPath path;
    path.addRoundedRect(QRect(rect().x() + penSize, rect().y() + penSize, rect().width() - penSize * 2, rect().height() - penSize * 2 - 1), 5, 5);
    
    QPen pen(QColor("#ffffff"));
    painter.setOpacity(0.05);
    pen.setWidth(penSize);
    painter.setPen(pen);
    painter.drawPath(path);
    
    painter.drawLine(rect().x() + width, rect().y() + penSize + 1, rect().x() + width, rect().y() + rect().height() - penSize * 2 - 1);
    painter.drawLine(rect().x() + width * 2, rect().y() + penSize + 1, rect().x() + width * 2, rect().y() + rect().height() - penSize * 2 - 1);
    
    painter.setOpacity(1);
    for (int i = 0; i < 3; i++) {
        if (i == activeIndex) {
            if (i == 0) {
                painter.drawImage(QPoint(rect().x() + width * i, rect().y()), onlyGuiActiveImage);
            } else if (i == 1) {
                painter.drawImage(QPoint(rect().x() + width * i, rect().y()), onlyMeActiveImage);
            } else {
                painter.drawImage(QPoint(rect().x() + width * i, rect().y()), allProcessActiveImage);
            }
        } else if (i == hoverIndex) {
            if (i == 0) {
                painter.drawImage(QPoint(rect().x() + width * i, rect().y()), onlyGuiHoverImage);
            } else if (i == 1) {
                painter.drawImage(QPoint(rect().x() + width * i, rect().y()), onlyMeHoverImage);
            } else {
                painter.drawImage(QPoint(rect().x() + width * i, rect().y()), allProcessHoverImage);
            }
        } else {
            if (i == 0) {
                painter.drawImage(QPoint(rect().x() + width * i, rect().y()), onlyGuiNormalImage);
            } else if (i == 1) {
                painter.drawImage(QPoint(rect().x() + width * i, rect().y()), onlyMeNormalImage);
            } else {
                painter.drawImage(QPoint(rect().x() + width * i, rect().y()), allProcessNormalImage);
            }
        }
    }
}

void ProcessSwitchTab::leaveEvent(QEvent * event){
    hoverIndex = -1;

    QWidget::leaveEvent(event);
    
    repaint();
}


