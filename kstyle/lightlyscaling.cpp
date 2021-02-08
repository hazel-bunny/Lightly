
/*************************************************************************
 * Copyright (C) 2018 by Steffen Coenen <steffen@steffen-coenen.de>      *
 *                                                                       *
 * This program is free software; you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation; either version 2 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program; if not, write to the                         *
 * Free Software Foundation, Inc.,                                       *
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 *************************************************************************/

#include <algorithm>
#include <cmath>
#include <QApplication>
#include <QDesktopWidget>

#include "lightly.h"
#include "lightlyscaling.h"

namespace Lightly
{
    int dpiScaleR(qreal a) {
            return std::round( a * Metrics::ScaleFactor );
    }

namespace Metrics
{
    qreal CalculateScaleFactor() {
        qreal ScaleFactor;
        if (qgetenv("BREEZE_SCALE").isEmpty())
            {
            qreal CalculatedScaleFactor = (QApplication::desktop()->logicalDpiX()/96.0);
            ScaleFactor = std::max(1.0, CalculatedScaleFactor);
            }
        else
            {
            ScaleFactor = std::max(0.5, qgetenv("BREEZE_SCALE").toDouble());
            }
        return ScaleFactor;
        }
    qreal ScaleFactor = CalculateScaleFactor();

    // frames
    int Frame_FrameWidth = qBound(3.0, std::round(MetricsUnscaled::Frame_FrameWidth * ScaleFactor), 8.0); //5;
    //int Frame_FrameRadius = qBound(3.0, std::floor(MetricsUnscaled::Frame_FrameRadius * ScaleFactor), 6.0); //3;

    // layout
    int Layout_TopLevelMarginWidth = dpiScaleR(MetricsUnscaled::Layout_TopLevelMarginWidth); // 10
    int Layout_ChildMarginWidth = dpiScaleR(MetricsUnscaled::Layout_ChildMarginWidth); // 6
    int Layout_DefaultSpacing = dpiScaleR(MetricsUnscaled::Layout_DefaultSpacing); // 8

    // line editors
    int LineEdit_FrameWidth = dpiScaleR(MetricsUnscaled::LineEdit_FrameWidth); //6,

    // menu items
    //int Menu_FrameWidth = MetricsUnscaled::Menu_FrameWidth; //4,
    int MenuItem_MarginWidth = dpiScaleR(MetricsUnscaled::MenuItem_MarginWidth); //5,
    int MenuItem_MarginHeight = dpiScaleR(MetricsUnscaled::MenuItem_MarginHeight); //3,
    int MenuItem_ItemSpacing = dpiScaleR(MetricsUnscaled::MenuItem_ItemSpacing); //4,
    int MenuItem_AcceleratorSpace = dpiScaleR(MetricsUnscaled::MenuItem_AcceleratorSpace); //16,
    int MenuButton_IndicatorWidth = dpiScaleR(MetricsUnscaled::MenuButton_IndicatorWidth); //20,

    // combobox
    int ComboBox_FrameWidth = dpiScaleR(MetricsUnscaled::ComboBox_FrameWidth); //5+x,

    // spinbox
    int SpinBox_FrameWidth = dpiScaleR(MetricsUnscaled::SpinBox_FrameWidth); //LineEdit_FrameWidth,
    int SpinBox_ArrowButtonWidth = dpiScaleR(MetricsUnscaled::SpinBox_ArrowButtonWidth); //20,

    // groupbox title margin
    int GroupBox_TitleMarginWidth = dpiScaleR(MetricsUnscaled::GroupBox_TitleMarginWidth); //4,

    // buttons
    int Button_MinWidth = dpiScaleR(MetricsUnscaled::Button_MinWidth); //80,
    int Button_MarginWidth = dpiScaleR(MetricsUnscaled::Button_MarginWidth); //6,
    int Button_ItemSpacing = dpiScaleR(MetricsUnscaled::Button_ItemSpacing); //4,

    // tool buttons
    int ToolButton_MarginWidth = dpiScaleR(MetricsUnscaled::ToolButton_MarginWidth); //6,
    int ToolButton_ItemSpacing = dpiScaleR(MetricsUnscaled::ToolButton_ItemSpacing); //4,
    int ToolButton_InlineIndicatorWidth = dpiScaleR(MetricsUnscaled::ToolButton_InlineIndicatorWidth); //12,

    // checkboxes and radio buttons
    int CheckBox_Size = dpiScaleR(MetricsUnscaled::CheckBox_Size); //18+x,
    int CheckBox_FocusMarginWidth = dpiScaleR(MetricsUnscaled::CheckBox_FocusMarginWidth); //2,
    int CheckBox_ItemSpacing = dpiScaleR(MetricsUnscaled::CheckBox_ItemSpacing); //4,

    // menubar items
    int MenuBarItem_MarginWidth = dpiScaleR(MetricsUnscaled::MenuBarItem_MarginWidth); //10,
    int MenuBarItem_MarginHeight = dpiScaleR(MetricsUnscaled::MenuBarItem_MarginHeight); //6,

    // scrollbars
    int ScrollBar_Extend = dpiScaleR(MetricsUnscaled::ScrollBar_Extend); //21,
    int ScrollBar_SliderWidth = dpiScaleR(MetricsUnscaled::ScrollBar_SliderWidth); //6,
    int ScrollBar_MinSliderHeight = dpiScaleR(MetricsUnscaled::ScrollBar_MinSliderHeight); //20,
    int ScrollBar_NoButtonHeight = dpiScaleR(MetricsUnscaled::ScrollBar_NoButtonHeight); //(ScrollBar_Extend-ScrollBar_SliderWidth)/2,
    int ScrollBar_SingleButtonHeight = dpiScaleR(MetricsUnscaled::ScrollBar_SingleButtonHeight); //ScrollBar_Extend,
    int ScrollBar_DoubleButtonHeight = dpiScaleR(MetricsUnscaled::ScrollBar_DoubleButtonHeight); //2*ScrollBar_Extend,

    // toolbars
    int ToolBar_FrameWidth = dpiScaleR(MetricsUnscaled::ToolBar_FrameWidth); //2,
    int ToolBar_HandleExtent = dpiScaleR(MetricsUnscaled::ToolBar_HandleExtent); //10,
    int ToolBar_HandleWidth = dpiScaleR(MetricsUnscaled::ToolBar_HandleWidth); //6,
    int ToolBar_SeparatorWidth = dpiScaleR(MetricsUnscaled::ToolBar_SeparatorWidth); //8,
    int ToolBar_ExtensionWidth = dpiScaleR(MetricsUnscaled::ToolBar_ExtensionWidth); //20,
    int ToolBar_ItemSpacing = MetricsUnscaled::ToolBar_ItemSpacing; //0,

    // progressbars
    int ProgressBar_BusyIndicatorSize = dpiScaleR(MetricsUnscaled::ProgressBar_BusyIndicatorSize); //14,
    int ProgressBar_Thickness = dpiScaleR(MetricsUnscaled::ProgressBar_Thickness); //4,
    int ProgressBar_ItemSpacing = dpiScaleR(MetricsUnscaled::ProgressBar_ItemSpacing); //4,

    // mdi title bar
    int TitleBar_MarginWidth = dpiScaleR(MetricsUnscaled::TitleBar_MarginWidth); //4,

    // sliders
    int Slider_TickLength = dpiScaleR(MetricsUnscaled::Slider_TickLength); //8,
    int Slider_TickMarginWidth = dpiScaleR(MetricsUnscaled::Slider_TickMarginWidth); //2,
    int Slider_GrooveThickness = dpiScaleR(MetricsUnscaled::Slider_GrooveThickness); //4,
    int Slider_ControlThickness = dpiScaleR(MetricsUnscaled::Slider_ControlThickness); //20,

    // tabbar
    int TabBar_TabMarginHeight = dpiScaleR(MetricsUnscaled::TabBar_TabMarginHeight); //4,
    int TabBar_TabMarginWidth = dpiScaleR(MetricsUnscaled::TabBar_TabMarginWidth); //8,
    int TabBar_TabMinWidth = dpiScaleR(MetricsUnscaled::TabBar_TabMinWidth); //80,
    int TabBar_TabMinHeight = dpiScaleR(MetricsUnscaled::TabBar_TabMinHeight); //33,
    int TabBar_TabItemSpacing = dpiScaleR(MetricsUnscaled::TabBar_TabItemSpacing); //8,
    int TabBar_TabOverlap = MetricsUnscaled::TabBar_TabOverlap; //0,
    int TabBar_BaseOverlap = MetricsUnscaled::TabBar_BaseOverlap; //2,

    // tab widget
    int TabWidget_MarginWidth = dpiScaleR(MetricsUnscaled::TabWidget_MarginWidth); //4,

    // toolbox
    int ToolBox_TabMinWidth = dpiScaleR(MetricsUnscaled::ToolBox_TabMinWidth); //80,
    int ToolBox_TabItemSpacing = dpiScaleR(MetricsUnscaled::ToolBox_TabItemSpacing); //4,
    int ToolBox_TabMarginWidth = dpiScaleR(MetricsUnscaled::ToolBox_TabMarginWidth); //8,

    // tooltips
    int ToolTip_FrameWidth = dpiScaleR(MetricsUnscaled::ToolTip_FrameWidth); //3,

    // list headers
    int Header_MarginWidth = dpiScaleR(MetricsUnscaled::Header_MarginWidth); //6,
    int Header_ItemSpacing = dpiScaleR(MetricsUnscaled::Header_ItemSpacing); //4,
    int Header_ArrowSize = dpiScaleR(MetricsUnscaled::Header_ArrowSize); //10,

    // tree view
    int ItemView_ArrowSize = dpiScaleR(MetricsUnscaled::ItemView_ArrowSize); //10,
    int ItemView_ItemMarginWidth = dpiScaleR(MetricsUnscaled::ItemView_ItemMarginWidth); //3,
    int SidePanel_ItemMarginWidth = dpiScaleR(MetricsUnscaled::SidePanel_ItemMarginWidth); //4,

    // splitter
    int Splitter_SplitterWidth = MetricsUnscaled::Splitter_SplitterWidth; //1,

    // shadow dimensions
    int Shadow_Overlap = dpiScaleR(MetricsUnscaled::Shadow_Overlap); //2
}
}
