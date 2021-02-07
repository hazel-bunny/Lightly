
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

#ifndef LIGHTLYSCALING_H
#define LIGHTLYSCALING_H

namespace Lightly
{
    int dpiScaleR(qreal a);

namespace Metrics
{
    extern qreal ScaleFactor;

    // frames
    extern int Frame_FrameWidth;
    //extern int Frame_FrameRadius;

    // layout
    extern int Layout_TopLevelMarginWidth;
    extern int Layout_ChildMarginWidth;
    extern int Layout_DefaultSpacing;

    // line editors
    extern int LineEdit_FrameWidth;

    // menu items
    //extern int Menu_FrameWidth;
    extern int MenuItem_MarginWidth;
    extern int MenuItem_MarginHeight;
    extern int MenuItem_ItemSpacing;
    extern int MenuItem_AcceleratorSpace;
    extern int MenuButton_IndicatorWidth;

    // combobox
    extern int ComboBox_FrameWidth;

    // spinbox
    extern int SpinBox_FrameWidth;
    extern int SpinBox_ArrowButtonWidth;

    // groupbox title margin
    extern int GroupBox_TitleMarginWidth;

    // buttons
    extern int Button_MinWidth;
    extern int Button_MarginWidth;
    extern int Button_ItemSpacing;

    // tool buttons
    extern int ToolButton_MarginWidth;
    extern int ToolButton_ItemSpacing;
    extern int ToolButton_InlineIndicatorWidth;

    // checkboxes and radio buttons
    extern int CheckBox_Size;
    extern int CheckBox_FocusMarginWidth;
    extern int CheckBox_ItemSpacing;

    // menubar items
    extern int MenuBarItem_MarginWidth;
    extern int MenuBarItem_MarginHeight;

    // scrollbars
    extern int ScrollBar_Extend;
    extern int ScrollBar_SliderWidth;
    extern int ScrollBar_MinSliderHeight;
    extern int ScrollBar_NoButtonHeight;
    extern int ScrollBar_SingleButtonHeight;
    extern int ScrollBar_DoubleButtonHeight;

    // toolbars
    extern int ToolBar_FrameWidth;
    extern int ToolBar_HandleExtent;
    extern int ToolBar_HandleWidth;
    extern int ToolBar_SeparatorWidth;
    extern int ToolBar_ExtensionWidth;
    extern int ToolBar_ItemSpacing;

    // progressbars
    extern int ProgressBar_BusyIndicatorSize;
    extern int ProgressBar_Thickness;
    extern int ProgressBar_ItemSpacing;

    // mdi title bar
    extern int TitleBar_MarginWidth;

    // sliders
    extern int Slider_TickLength;
    extern int Slider_TickMarginWidth;
    extern int Slider_GrooveThickness;
    extern int Slider_ControlThickness;

    // tabbar
    extern int TabBar_TabMarginHeight;
    extern int TabBar_TabMarginWidth;
    extern int TabBar_TabMinWidth;
    extern int TabBar_TabMinHeight;
    extern int TabBar_TabItemSpacing;
    extern int TabBar_TabOverlap;
    extern int TabBar_BaseOverlap;

    // tab widget
    extern int TabWidget_MarginWidth;

    // toolbox
    extern int ToolBox_TabMinWidth;
    extern int ToolBox_TabItemSpacing;
    extern int ToolBox_TabMarginWidth;

    // tooltips
    extern int ToolTip_FrameWidth;

    // list headers
    extern int Header_MarginWidth;
    extern int Header_ItemSpacing;
    extern int Header_ArrowSize;

    // tree view
    extern int ItemView_ArrowSize;
    extern int ItemView_ItemMarginWidth;
    extern int SidePanel_ItemMarginWidth;

    // splitter
    extern int Splitter_SplitterWidth;

    // shadow dimensions
    extern int Shadow_Overlap;
}
}

#endif
