#ifndef lightly_h
#define lightly_h

/*************************************************************************
 * Copyright (C) 2014 by Hugo Pereira Da Costa <hugo.pereira@free.fr>    *
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

#include <QFlags>
#include <QPointer>
#include <QScopedPointer>
#include <QWeakPointer>

namespace Lightly
{

    //*@name convenience typedef
    //@{

    //* scoped pointer convenience typedef
    template <typename T> using WeakPointer = QPointer<T>;

    //* scoped pointer convenience typedef
    template <typename T> using ScopedPointer = QScopedPointer<T, QScopedPointerPodDeleter>;

    //@}

    //* metrics
    enum Metrics
    {

        // frames
        Frame_FrameWidth = 2,
        //Frame_FrameRadius = 6,

        // layout
        Layout_TopLevelMarginWidth = 5,
        Layout_ChildMarginWidth = 2,
        Layout_DefaultSpacing = 1,

        // line editors
        LineEdit_FrameWidth = 2 + Frame_FrameWidth,

        // menu items
        //Menu_FrameWidth = 4,
        MenuItem_MarginWidth = 3,
        MenuItem_MarginHeight = 3,
        MenuItem_ItemSpacing = 2,
        MenuItem_AcceleratorSpace = 16,
        MenuButton_IndicatorWidth = 20,

        // combobox
        ComboBox_FrameWidth = 2 + Frame_FrameWidth,

        // spinbox
        SpinBox_FrameWidth = LineEdit_FrameWidth,
        SpinBox_ArrowButtonWidth = 20,

        // groupbox title margin
        GroupBox_TitleMarginWidth = 2,

        // buttons
        Button_MinWidth = 70,
        Button_MarginWidth = 4,
        Button_ItemSpacing = 3,

        // tool buttons
        ToolButton_MarginWidth = 3,
        ToolButton_ItemSpacing = 3,
        ToolButton_InlineIndicatorWidth = 12,

        // checkboxes and radio buttons
        CheckBox_Size = 16 + ( Frame_FrameWidth - 1 )*2,
        CheckBox_FocusMarginWidth = 2,
        CheckBox_ItemSpacing = 4,

        // menubar items
        MenuBarItem_MarginWidth = 5,
        MenuBarItem_MarginHeight = 3,

        // scrollbars
        ScrollBar_Extend = 21,
        ScrollBar_SliderWidth = 6,
        ScrollBar_MinSliderHeight = 20,
        ScrollBar_NoButtonHeight = (ScrollBar_Extend-ScrollBar_SliderWidth)/2,
        ScrollBar_SingleButtonHeight = ScrollBar_Extend,
        ScrollBar_DoubleButtonHeight = 2*ScrollBar_Extend,

        // toolbars
        ToolBar_FrameWidth = 2,
        ToolBar_HandleExtent = 10,
        ToolBar_HandleWidth = 6,
        ToolBar_SeparatorWidth = 4,
        ToolBar_ExtensionWidth = 20,
        ToolBar_ItemSpacing = 0,

        // progressbars
        ProgressBar_BusyIndicatorSize = 14,
        ProgressBar_Thickness = 4,
        ProgressBar_ItemSpacing = 2,

        // mdi title bar
        TitleBar_MarginWidth = 3,

        // sliders
        Slider_TickLength = 8,
        Slider_TickMarginWidth = 2,
        Slider_GrooveThickness = 4,
        Slider_ControlThickness = 20,

        // tabbar
        TabBar_TabMarginHeight = 2,
        TabBar_TabMarginWidth = 2,
        TabBar_TabMinWidth = 80,
        TabBar_TabMinHeight = 24,
        TabBar_TabItemSpacing = 1,
        TabBar_TabOverlap = 0,
        TabBar_BaseOverlap = 2,

        // tab widget
        TabWidget_MarginWidth = 2,

        // toolbox
        ToolBox_TabMinWidth = 80,
        ToolBox_TabItemSpacing = 3,
        ToolBox_TabMarginWidth = 4,

        // tooltips
        ToolTip_FrameWidth = 3,

        // list headers
        Header_MarginWidth = 3,
        Header_ItemSpacing = 3,
        Header_ArrowSize = 10,

        // tree view
        ItemView_ArrowSize = 10,
        ItemView_ItemMarginWidth = 2,
        SidePanel_ItemMarginWidth = 3,

        // splitter
        Splitter_SplitterWidth = 1,

        // shadow dimensions
        Shadow_Overlap = 2

    };

    //* standard pen widths
    namespace PenWidth
    {
        /* Using 1 instead of slightly more than 1 causes symbols drawn with
         * pen strokes to look skewed. The exact amount added does not matter
         * as long as it isn't too visible.
         */
        // The standard pen stroke width for symbols.
        static constexpr qreal Symbol = 1.01;

        // The standard pen stroke width for frames.
        static constexpr int Frame = 1;

        // The standard pen stroke width for shadows.
        static constexpr int Shadow = 1;
        
        // A value for pen width arguments to make it clear that there is no pen stroke
        static constexpr int NoPen = 0;
    }
    
    //* animation mode
    enum AnimationMode
    {
        AnimationNone = 0,
        AnimationHover = 0x1,
        AnimationFocus = 0x2,
        AnimationEnable = 0x4,
        AnimationPressed = 0x8
    };

    Q_DECLARE_FLAGS(AnimationModes, AnimationMode)
    
    //* extra animation parameters for custom widget animations
    enum AnimationParameter
    {
        AnimationDefaut = 0,
        AnimationForwardOnly = 0x1,
        AnimationOutBack = 0x2,
        AnimationLongDuration = 0x4 
    };
    
    Q_DECLARE_FLAGS(AnimationParameters, AnimationParameter)

    //* corners
    enum Corner
    {
        CornerTopLeft = 0x1,
        CornerTopRight = 0x2,
        CornerBottomLeft = 0x4,
        CornerBottomRight = 0x8,
        CornersTop = CornerTopLeft|CornerTopRight,
        CornersBottom = CornerBottomLeft|CornerBottomRight,
        CornersLeft = CornerTopLeft|CornerBottomLeft,
        CornersRight = CornerTopRight|CornerBottomRight,
        AllCorners = CornerTopLeft|CornerTopRight|CornerBottomLeft|CornerBottomRight
    };

    Q_DECLARE_FLAGS( Corners, Corner )

    //* sides
    enum Side
    {
        SideLeft = 0x1,
        SideTop = 0x2,
        SideRight = 0x4,
        SideBottom = 0x8,
        AllSides = SideLeft|SideTop|SideRight|SideBottom
    };

    Q_DECLARE_FLAGS( Sides, Side )

    //* checkbox state
    enum CheckBoxState
    {
        CheckOff,
        CheckPartial,
        CheckOn,
        CheckAnimated
    };

    //* radio button state
    enum RadioButtonState
    {
        RadioOff,
        RadioOn,
        RadioAnimated
    };

    //* arrow orientation
    enum ArrowOrientation
    {
        ArrowNone,
        ArrowUp,
        ArrowDown,
        ArrowLeft,
        ArrowRight,
        ArrowDown_Small,
    };

    //* button type
    enum ButtonType
    {
        ButtonClose,
        ButtonMaximize,
        ButtonMinimize,
        ButtonRestore
    };

}

Q_DECLARE_OPERATORS_FOR_FLAGS( Lightly::AnimationModes )
Q_DECLARE_OPERATORS_FOR_FLAGS( Lightly::AnimationParameters )
Q_DECLARE_OPERATORS_FOR_FLAGS( Lightly::Corners )
Q_DECLARE_OPERATORS_FOR_FLAGS( Lightly::Sides )

#endif
