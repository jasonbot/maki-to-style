'Type library'
__all__ = ['IProgressDialog', 'ICommand', 'IComponentTip', 'IComboBoxHook', 'IComboBox', 'ICompletionNotify', 'IToolControl', 'IToolPalette', 'ITool', 'IToolKeys', 'IItemDef', 'ICommandSubType', 'IToolBarDef', 'IMenuDef', 'IPaletteDef', 'IMultiItemSeparator', 'IMultiItem', 'IMultiItemEx', 'IComPropertySheetEvents', 'IOperation', 'IOperationStack', 'IToolSelectedLayer', 'ISystemMouseCursor', 'IDataObjectHelper', 'ICommandHost', 'IArcGISPortal', 'IArcGISSingleSignon', 'IArcGISSingleSignon2', 'DataObjectHelper', 'ControlsOperationStack', 'CommandHost', 'ToolHost', 'ComPropertySheetEventsProxyHelper', 'SystemFont', 'SystemMouseCursor', 'ArcGISSingleSignon', 'IID_IProgressDialog', 'IID_ICommand', 'IID_IComponentTip', 'IID_IComboBoxHook', 'IID_IComboBox', 'IID_ICompletionNotify', 'IID_IToolControl', 'IID_IToolPalette', 'IID_ITool', 'IID_IToolKeys', 'IID_IItemDef', 'IID_ICommandSubType', 'IID_IToolBarDef', 'IID_IMenuDef', 'IID_IPaletteDef', 'IID_IMultiItemSeparator', 'IID_IMultiItem', 'IID_IMultiItemEx', 'IID_IComPropertySheetEvents', 'IID_IOperation', 'IID_IOperationStack', 'IID_IToolSelectedLayer', 'IID_ISystemMouseCursor', 'IID_IDataObjectHelper', 'IID_ICommandHost', 'IID_IArcGISPortal', 'IID_IArcGISSingleSignon', 'IID_IArcGISSingleSignon2', 'CLSID_DataObjectHelper', 'CLSID_ControlsOperationStack', 'CLSID_CommandHost', 'CLSID_ToolHost', 'CLSID_ComPropertySheetEventsProxyHelper', 'CLSID_SystemFont', 'CLSID_SystemMouseCursor', 'CLSID_ArcGISSingleSignon', 'esriArcGISUri', 'esriCommandStyles', 'esriCmdBarType', 'esriSystemMouseCursor', 'esriTipStyle', 'esriKeyIntercept']
from cartocomutils import _esriSystemUI
from cartocomutils._esriSystemUI import DataObjectHelper, ControlsOperationStack, CommandHost, ToolHost, ComPropertySheetEventsProxyHelper, SystemFont, SystemMouseCursor, ArcGISSingleSignon
from cartocomutils import Enumeration, IndexProperty, _IIDMap, _CLSIDMap, _RecordMap
import uuid


# Interfaces
class IProgressDialog(_esriSystemUI.IProgressDialog):
    _IID = uuid.UUID('923a1b5a-90e5-4d23-add8-eca3d7d6b1c8')

    def __init__(self, *args, **kw):
        super(IProgressDialog, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def ShowDialog(self):
        '''Method IProgressDialog.ShowDialog'''
        return super(IProgressDialog, self).ShowDialog()
    def HideDialog(self):
        '''Method IProgressDialog.HideDialog'''
        return super(IProgressDialog, self).HideDialog()
    def get_CancelEnabled(self):
        '''Method IProgressDialog.get_CancelEnabled

           OUTPUT
            bVal                : VARIANT_BOOL*'''
        return super(IProgressDialog, self).get_CancelEnabled()
    def put_CancelEnabled(self, bVal):
        '''Method IProgressDialog.put_CancelEnabled

           INPUT
            bVal                : VARIANT_BOOL'''
        return super(IProgressDialog, self).put_CancelEnabled(bVal)
    CancelEnabled = property(get_CancelEnabled, put_CancelEnabled, None)

class ICommand(_esriSystemUI.ICommand):
    _IID = uuid.UUID('36b06538-4437-11d1-b970-080009ee4e51')
    def get_Enabled(self):
        '''Method ICommand.get_Enabled

           OUTPUT
            Enabled             : VARIANT_BOOL*'''
        return super(ICommand, self).get_Enabled()
    def get_Checked(self):
        '''Method ICommand.get_Checked

           OUTPUT
            Checked             : VARIANT_BOOL*'''
        return super(ICommand, self).get_Checked()
    def get_Name(self):
        '''Method ICommand.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(ICommand, self).get_Name()
    def get_Caption(self):
        '''Method ICommand.get_Caption

           OUTPUT
            Caption             : BSTR*'''
        return super(ICommand, self).get_Caption()
    def get_Tooltip(self):
        '''Method ICommand.get_Tooltip

           OUTPUT
            Tooltip             : BSTR*'''
        return super(ICommand, self).get_Tooltip()
    def get_Message(self):
        '''Method ICommand.get_Message

           OUTPUT
            Message             : BSTR*'''
        return super(ICommand, self).get_Message()
    def get_HelpFile(self):
        '''Method ICommand.get_HelpFile

           OUTPUT
            HelpFile            : BSTR*'''
        return super(ICommand, self).get_HelpFile()
    def get_HelpContextID(self):
        '''Method ICommand.get_HelpContextID

           OUTPUT
            helpID              : long*'''
        return super(ICommand, self).get_HelpContextID()
    def get_Bitmap(self):
        '''Method ICommand.get_Bitmap

           OUTPUT
            Bitmap              : OLE_HANDLE*'''
        return super(ICommand, self).get_Bitmap()
    def get_Category(self):
        '''Method ICommand.get_Category

           OUTPUT
            categoryName        : BSTR*'''
        return super(ICommand, self).get_Category()
    def OnCreate(self, Hook):
        '''Method ICommand.OnCreate

           INPUT
            Hook                : IDispatch*'''
        return super(ICommand, self).OnCreate(Hook)
    def OnClick(self):
        '''Method ICommand.OnClick'''
        return super(ICommand, self).OnClick()
    Bitmap = property(get_Bitmap, None, None)
    Caption = property(get_Caption, None, None)
    Category = property(get_Category, None, None)
    Checked = property(get_Checked, None, None)
    Enabled = property(get_Enabled, None, None)
    HelpContextID = property(get_HelpContextID, None, None)
    HelpFile = property(get_HelpFile, None, None)
    Message = property(get_Message, None, None)
    Name = property(get_Name, None, None)
    Tooltip = property(get_Tooltip, None, None)

class IComponentTip(_esriSystemUI.IComponentTip):
    _IID = uuid.UUID('fd86ed38-01c7-4a41-a72c-5502031aa216')
    def get_Heading(self):
        '''Method IComponentTip.get_Heading

           OUTPUT
            Heading             : BSTR*'''
        return super(IComponentTip, self).get_Heading()
    def get_Tip(self):
        '''Method IComponentTip.get_Tip

           OUTPUT
            Tip                 : BSTR*'''
        return super(IComponentTip, self).get_Tip()
    def get_Image(self):
        '''Method IComponentTip.get_Image

           OUTPUT
            Image               : OLE_HANDLE*'''
        return super(IComponentTip, self).get_Image()
    Heading = property(get_Heading, None, None)
    Image = property(get_Image, None, None)
    Tip = property(get_Tip, None, None)

class IComboBoxHook(_esriSystemUI.IComboBoxHook):
    _IID = uuid.UUID('457fa6e9-2b50-4335-9990-b321ff228daf')

    def __init__(self, *args, **kw):
        super(IComboBoxHook, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def get_Hook(self):
        '''Method IComboBoxHook.get_Hook

           OUTPUT
            app                 : IDispatch**'''
        return super(IComboBoxHook, self).get_Hook()
    def Add(self, str):
        '''Method IComboBoxHook.Add

           INPUT
            str                 : BSTR

           OUTPUT
            cookie              : long*'''
        return super(IComboBoxHook, self).Add(str)
    def Remove(self, cookie):
        '''Method IComboBoxHook.Remove

           INPUT
            cookie              : long'''
        return super(IComboBoxHook, self).Remove(cookie)
    def put_Value(self, Value):
        '''Method IComboBoxHook.put_Value

           INPUT
            Value               : BSTR'''
        return super(IComboBoxHook, self).put_Value(Value)
    def get_Value(self):
        '''Method IComboBoxHook.get_Value

           OUTPUT
            Value               : BSTR*'''
        return super(IComboBoxHook, self).get_Value()
    def Clear(self):
        '''Method IComboBoxHook.Clear'''
        return super(IComboBoxHook, self).Clear()
    def Select(self, cookie):
        '''Method IComboBoxHook.Select

           INPUT
            cookie              : long'''
        return super(IComboBoxHook, self).Select(cookie)
    def get_Selected(self):
        '''Method IComboBoxHook.get_Selected

           OUTPUT
            cookie              : long*'''
        return super(IComboBoxHook, self).get_Selected()
    Hook = property(get_Hook, None, None)
    Selected = property(get_Selected, None, None)
    Value = property(get_Value, put_Value, None)

class IComboBox(_esriSystemUI.IComboBox):
    _IID = uuid.UUID('b3cf6f42-40b5-42c4-8714-0b6fd2de8c85')
    def get_Editable(self):
        '''Method IComboBox.get_Editable

           OUTPUT
            Editable            : VARIANT_BOOL*'''
        return super(IComboBox, self).get_Editable()
    def get_Width(self):
        '''Method IComboBox.get_Width

           OUTPUT
            stringForWidth      : BSTR*'''
        return super(IComboBox, self).get_Width()
    def get_DropDownWidth(self):
        '''Method IComboBox.get_DropDownWidth

           OUTPUT
            stringForWidth      : BSTR*'''
        return super(IComboBox, self).get_DropDownWidth()
    def get_DropDownHeight(self):
        '''Method IComboBox.get_DropDownHeight

           OUTPUT
            rowsHigh            : long*'''
        return super(IComboBox, self).get_DropDownHeight()
    def get_HintText(self):
        '''Method IComboBox.get_HintText

           OUTPUT
            HintText            : BSTR*'''
        return super(IComboBox, self).get_HintText()
    def OnSelChange(self, cookie):
        '''Method IComboBox.OnSelChange

           INPUT
            cookie              : long'''
        return super(IComboBox, self).OnSelChange(cookie)
    def OnEditChange(self, editString):
        '''Method IComboBox.OnEditChange

           INPUT
            editString          : BSTR'''
        return super(IComboBox, self).OnEditChange(editString)
    def OnFocus(self, set):
        '''Method IComboBox.OnFocus

           INPUT
            set                 : VARIANT_BOOL'''
        return super(IComboBox, self).OnFocus(set)
    def OnEnter(self):
        '''Method IComboBox.OnEnter'''
        return super(IComboBox, self).OnEnter()
    def get_ShowCaption(self):
        '''Method IComboBox.get_ShowCaption

           OUTPUT
            ShowCaption         : VARIANT_BOOL*'''
        return super(IComboBox, self).get_ShowCaption()
    DropDownHeight = property(get_DropDownHeight, None, None)
    DropDownWidth = property(get_DropDownWidth, None, None)
    Editable = property(get_Editable, None, None)
    HintText = property(get_HintText, None, None)
    ShowCaption = property(get_ShowCaption, None, None)
    Width = property(get_Width, None, None)

class ICompletionNotify(_esriSystemUI.ICompletionNotify):
    _IID = uuid.UUID('12f412e9-2cbc-11d2-94c8-080009eebecb')
    def SetComplete(self):
        '''Method ICompletionNotify.SetComplete'''
        return super(ICompletionNotify, self).SetComplete()

class IToolControl(_esriSystemUI.IToolControl):
    _IID = uuid.UUID('e2287753-940f-11d0-835b-080009b996cc')
    def get_hWnd(self):
        '''Method IToolControl.get_hWnd

           OUTPUT
            hWnd                : OLE_HANDLE*'''
        return super(IToolControl, self).get_hWnd()
    def OnFocus(self, complete):
        '''Method IToolControl.OnFocus

           INPUT
            complete            : ICompletionNotify*'''
        return super(IToolControl, self).OnFocus(complete)
    def OnDrop(self, barType):
        '''Method IToolControl.OnDrop

           INPUT
            barType             : esriCmdBarType

           OUTPUT
            bValid              : VARIANT_BOOL*'''
        return super(IToolControl, self).OnDrop(barType)
    hWnd = property(get_hWnd, None, None)

class IToolPalette(_esriSystemUI.IToolPalette):
    _IID = uuid.UUID('5678b14a-102b-493f-badb-1a83ae8a3830')
    def get_PaletteItemCount(self):
        '''Method IToolPalette.get_PaletteItemCount

           OUTPUT
            numItems            : long*'''
        return super(IToolPalette, self).get_PaletteItemCount()
    def get_PaletteItem(self, pos):
        '''Method IToolPalette.get_PaletteItem

           INPUT
            pos                 : long

           OUTPUT
            ID                  : BSTR*'''
        return super(IToolPalette, self).get_PaletteItem(pos)
    def get_PaletteColumns(self):
        '''Method IToolPalette.get_PaletteColumns

           OUTPUT
            columns             : long*'''
        return super(IToolPalette, self).get_PaletteColumns()
    def get_MenuStyle(self):
        '''Method IToolPalette.get_MenuStyle

           OUTPUT
            menu                : VARIANT_BOOL*'''
        return super(IToolPalette, self).get_MenuStyle()
    def get_TearOff(self):
        '''Method IToolPalette.get_TearOff

           OUTPUT
            TearOff             : VARIANT_BOOL*'''
        return super(IToolPalette, self).get_TearOff()
    MenuStyle = property(get_MenuStyle, None, None)
    PaletteColumns = property(get_PaletteColumns, None, None)
    PaletteItemCount = property(get_PaletteItemCount, None, None)
    TearOff = property(get_TearOff, None, None)
    PaletteItem = IndexProperty(get_PaletteItem, None)

class ITool(_esriSystemUI.ITool):
    _IID = uuid.UUID('2a6b0172-4ed2-11d0-98be-00805f7ced21')
    def get_Cursor(self):
        '''Method ITool.get_Cursor

           OUTPUT
            Cursor              : OLE_HANDLE*'''
        return super(ITool, self).get_Cursor()
    def OnMouseDown(self, button, shift, x, y):
        '''Method ITool.OnMouseDown

           INPUTS
            button              : long
            shift               : long
            x                   : long
            y                   : long'''
        return super(ITool, self).OnMouseDown(button, shift, x, y)
    def OnMouseMove(self, button, shift, x, y):
        '''Method ITool.OnMouseMove

           INPUTS
            button              : long
            shift               : long
            x                   : long
            y                   : long'''
        return super(ITool, self).OnMouseMove(button, shift, x, y)
    def OnMouseUp(self, button, shift, x, y):
        '''Method ITool.OnMouseUp

           INPUTS
            button              : long
            shift               : long
            x                   : long
            y                   : long'''
        return super(ITool, self).OnMouseUp(button, shift, x, y)
    def OnDblClick(self):
        '''Method ITool.OnDblClick'''
        return super(ITool, self).OnDblClick()
    def OnKeyDown(self, keyCode, shift):
        '''Method ITool.OnKeyDown

           INPUTS
            keyCode             : long
            shift               : long'''
        return super(ITool, self).OnKeyDown(keyCode, shift)
    def OnKeyUp(self, keyCode, shift):
        '''Method ITool.OnKeyUp

           INPUTS
            keyCode             : long
            shift               : long'''
        return super(ITool, self).OnKeyUp(keyCode, shift)
    def OnContextMenu(self, x, y):
        '''Method ITool.OnContextMenu

           INPUTS
            x                   : long
            y                   : long

           OUTPUT
            handled             : VARIANT_BOOL*'''
        return super(ITool, self).OnContextMenu(x, y)
    def Refresh(self, hdc):
        '''Method ITool.Refresh

           INPUT
            hdc                 : OLE_HANDLE'''
        return super(ITool, self).Refresh(hdc)
    def Deactivate(self):
        '''Method ITool.Deactivate

           OUTPUT
            complete            : VARIANT_BOOL*'''
        return super(ITool, self).Deactivate()
    Cursor = property(get_Cursor, None, None)

class IToolKeys(_esriSystemUI.IToolKeys):
    _IID = uuid.UUID('10107f77-6a0f-413f-8e88-ede3b6dedf66')
    def OverrideKey(self, keyCode, shift):
        '''Method IToolKeys.OverrideKey

           INPUTS
            keyCode             : long
            shift               : long

           OUTPUT
            override            : VARIANT_BOOL*'''
        return super(IToolKeys, self).OverrideKey(keyCode, shift)

class IItemDef(_esriSystemUI.IItemDef):
    _IID = uuid.UUID('857336bf-e12b-11d1-9495-080009eebecb')

    def __init__(self, *args, **kw):
        super(IItemDef, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_ID(self, _arg1):
        '''Method IItemDef.put_ID

           INPUT
            _arg1               : BSTR'''
        return super(IItemDef, self).put_ID(_arg1)
    def put_Group(self, _arg1):
        '''Method IItemDef.put_Group

           INPUT
            _arg1               : VARIANT_BOOL'''
        return super(IItemDef, self).put_Group(_arg1)
    def put_SubType(self, _arg1):
        '''Method IItemDef.put_SubType

           INPUT
            _arg1               : long'''
        return super(IItemDef, self).put_SubType(_arg1)
    Group = property(None, put_Group, None)
    ID = property(None, put_ID, None)
    SubType = property(None, put_SubType, None)

class ICommandSubType(_esriSystemUI.ICommandSubType):
    _IID = uuid.UUID('5a141a5b-d096-11d1-b9a9-080009ee4e51')
    def SetSubType(self, SubType):
        '''Method ICommandSubType.SetSubType

           INPUT
            SubType             : long'''
        return super(ICommandSubType, self).SetSubType(SubType)
    def GetCount(self):
        '''Method ICommandSubType.GetCount

           OUTPUT
            Count               : long*'''
        return super(ICommandSubType, self).GetCount()

class IToolBarDef(_esriSystemUI.IToolBarDef):
    _IID = uuid.UUID('61b318f0-cda0-11d1-b9a8-080009ee4e51')
    def get_ItemCount(self):
        '''Method IToolBarDef.get_ItemCount

           OUTPUT
            numItems            : long*'''
        return super(IToolBarDef, self).get_ItemCount()
    def GetItemInfo(self, pos, itemDef):
        '''Method IToolBarDef.GetItemInfo

           INPUTS
            pos                 : long
            itemDef             : IItemDef*'''
        return super(IToolBarDef, self).GetItemInfo(pos, itemDef)
    def get_Name(self):
        '''Method IToolBarDef.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IToolBarDef, self).get_Name()
    def get_Caption(self):
        '''Method IToolBarDef.get_Caption

           OUTPUT
            Name                : BSTR*'''
        return super(IToolBarDef, self).get_Caption()
    Caption = property(get_Caption, None, None)
    ItemCount = property(get_ItemCount, None, None)
    Name = property(get_Name, None, None)

class IMenuDef(_esriSystemUI.IMenuDef):
    _IID = uuid.UUID('58e2c6a1-cd8d-11d1-91a7-0080c718df97')
    def get_ItemCount(self):
        '''Method IMenuDef.get_ItemCount

           OUTPUT
            numItems            : long*'''
        return super(IMenuDef, self).get_ItemCount()
    def GetItemInfo(self, pos, itemDef):
        '''Method IMenuDef.GetItemInfo

           INPUTS
            pos                 : long
            itemDef             : IItemDef*'''
        return super(IMenuDef, self).GetItemInfo(pos, itemDef)
    def get_Name(self):
        '''Method IMenuDef.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IMenuDef, self).get_Name()
    def get_Caption(self):
        '''Method IMenuDef.get_Caption

           OUTPUT
            Name                : BSTR*'''
        return super(IMenuDef, self).get_Caption()
    Caption = property(get_Caption, None, None)
    ItemCount = property(get_ItemCount, None, None)
    Name = property(get_Name, None, None)

class IPaletteDef(_esriSystemUI.IPaletteDef):
    _IID = uuid.UUID('1db60dbd-ab2b-4d46-a2ee-f2fa3c5b55fb')
    def get_Caption(self):
        '''Method IPaletteDef.get_Caption

           OUTPUT
            pVal                : BSTR*'''
        return super(IPaletteDef, self).get_Caption()
    def get_Name(self):
        '''Method IPaletteDef.get_Name

           OUTPUT
            pVal                : BSTR*'''
        return super(IPaletteDef, self).get_Name()
    def get_ItemCount(self):
        '''Method IPaletteDef.get_ItemCount

           OUTPUT
            pVal                : long*'''
        return super(IPaletteDef, self).get_ItemCount()
    def GetItemInfo(self, pos, itemDef):
        '''Method IPaletteDef.GetItemInfo

           INPUTS
            pos                 : long
            itemDef             : IItemDef*'''
        return super(IPaletteDef, self).GetItemInfo(pos, itemDef)
    Caption = property(get_Caption, None, None)
    ItemCount = property(get_ItemCount, None, None)
    Name = property(get_Name, None, None)

class IMultiItemSeparator(_esriSystemUI.IMultiItemSeparator):
    _IID = uuid.UUID('5398cee2-0a8e-4bdf-af26-77c9af2ebc63')
    def get_Separator(self, index):
        '''Method IMultiItemSeparator.get_Separator

           INPUT
            index               : long

           OUTPUT
            bSeparator          : VARIANT_BOOL*'''
        return super(IMultiItemSeparator, self).get_Separator(index)
    Separator = IndexProperty(get_Separator, None)

class IMultiItem(_esriSystemUI.IMultiItem):
    _IID = uuid.UUID('af948931-11d1-11d2-94b4-080009eebecb')
    def get_Name(self):
        '''Method IMultiItem.get_Name

           OUTPUT
            Name                : BSTR*'''
        return super(IMultiItem, self).get_Name()
    def get_Caption(self):
        '''Method IMultiItem.get_Caption

           OUTPUT
            Name                : BSTR*'''
        return super(IMultiItem, self).get_Caption()
    def get_Message(self):
        '''Method IMultiItem.get_Message

           OUTPUT
            Message             : BSTR*'''
        return super(IMultiItem, self).get_Message()
    def get_HelpFile(self):
        '''Method IMultiItem.get_HelpFile

           OUTPUT
            HelpFile            : BSTR*'''
        return super(IMultiItem, self).get_HelpFile()
    def get_HelpContextID(self):
        '''Method IMultiItem.get_HelpContextID

           OUTPUT
            ID                  : long*'''
        return super(IMultiItem, self).get_HelpContextID()
    def OnPopup(self, Hook):
        '''Method IMultiItem.OnPopup

           INPUT
            Hook                : IDispatch*

           OUTPUT
            ItemCount           : long*'''
        return super(IMultiItem, self).OnPopup(Hook)
    def get_ItemCaption(self, index):
        '''Method IMultiItem.get_ItemCaption

           INPUT
            index               : long

           OUTPUT
            itemName            : BSTR*'''
        return super(IMultiItem, self).get_ItemCaption(index)
    def get_ItemBitmap(self, index):
        '''Method IMultiItem.get_ItemBitmap

           INPUT
            index               : long

           OUTPUT
            Bitmap              : OLE_HANDLE*'''
        return super(IMultiItem, self).get_ItemBitmap(index)
    def OnItemClick(self, index):
        '''Method IMultiItem.OnItemClick

           INPUT
            index               : long'''
        return super(IMultiItem, self).OnItemClick(index)
    def get_ItemChecked(self, index):
        '''Method IMultiItem.get_ItemChecked

           INPUT
            index               : long

           OUTPUT
            bChecked            : VARIANT_BOOL*'''
        return super(IMultiItem, self).get_ItemChecked(index)
    def get_ItemEnabled(self, index):
        '''Method IMultiItem.get_ItemEnabled

           INPUT
            index               : long

           OUTPUT
            bEnabled            : VARIANT_BOOL*'''
        return super(IMultiItem, self).get_ItemEnabled(index)
    Caption = property(get_Caption, None, None)
    HelpContextID = property(get_HelpContextID, None, None)
    HelpFile = property(get_HelpFile, None, None)
    Message = property(get_Message, None, None)
    Name = property(get_Name, None, None)
    ItemBitmap = IndexProperty(get_ItemBitmap, None)
    ItemCaption = IndexProperty(get_ItemCaption, None)
    ItemChecked = IndexProperty(get_ItemChecked, None)
    ItemEnabled = IndexProperty(get_ItemEnabled, None)

class IMultiItemEx(_esriSystemUI.IMultiItemEx):
    _IID = uuid.UUID('1e29f387-f77a-42cc-ad58-5fb1f5f8e11d')
    def get_ItemMessage(self, index):
        '''Method IMultiItemEx.get_ItemMessage

           INPUT
            index               : long

           OUTPUT
            Message             : BSTR*'''
        return super(IMultiItemEx, self).get_ItemMessage(index)
    def get_ItemHelpFile(self, index):
        '''Method IMultiItemEx.get_ItemHelpFile

           INPUT
            index               : long

           OUTPUT
            HelpFile            : BSTR*'''
        return super(IMultiItemEx, self).get_ItemHelpFile(index)
    def get_ItemHelpContextID(self, index):
        '''Method IMultiItemEx.get_ItemHelpContextID

           INPUT
            index               : long

           OUTPUT
            ID                  : long*'''
        return super(IMultiItemEx, self).get_ItemHelpContextID(index)
    ItemHelpContextID = IndexProperty(get_ItemHelpContextID, None)
    ItemHelpFile = IndexProperty(get_ItemHelpFile, None)
    ItemMessage = IndexProperty(get_ItemMessage, None)

class IComPropertySheetEvents(_esriSystemUI.IComPropertySheetEvents):
    _IID = uuid.UUID('6b7b57f8-5765-11d0-92d9-00805f7c28b0')
    def OnApply(self):
        '''Method IComPropertySheetEvents.OnApply'''
        return super(IComPropertySheetEvents, self).OnApply()

class IOperation(_esriSystemUI.IOperation):
    _IID = uuid.UUID('80a807ab-7bb9-11d0-87ec-080009ec732a')
    def get_MenuString(self):
        '''Method IOperation.get_MenuString

           OUTPUT
            text                : BSTR*'''
        return super(IOperation, self).get_MenuString()
    def get_CanUndo(self):
        '''Method IOperation.get_CanUndo

           OUTPUT
            result              : VARIANT_BOOL*'''
        return super(IOperation, self).get_CanUndo()
    def get_CanRedo(self):
        '''Method IOperation.get_CanRedo

           OUTPUT
            result              : VARIANT_BOOL*'''
        return super(IOperation, self).get_CanRedo()
    def Do(self):
        '''Method IOperation.Do'''
        return super(IOperation, self).Do()
    def Undo(self):
        '''Method IOperation.Undo'''
        return super(IOperation, self).Undo()
    def Redo(self):
        '''Method IOperation.Redo'''
        return super(IOperation, self).Redo()
    CanRedo = property(get_CanRedo, None, None)
    CanUndo = property(get_CanUndo, None, None)
    MenuString = property(get_MenuString, None, None)

class IOperationStack(_esriSystemUI.IOperationStack):
    _IID = uuid.UUID('303ee675-3087-11d2-94c9-080009eebecb')
    def get_Count(self):
        '''Method IOperationStack.get_Count

           OUTPUT
            Count               : long*'''
        return super(IOperationStack, self).get_Count()
    def get_Item(self, index):
        '''Method IOperationStack.get_Item

           INPUT
            index               : long

           OUTPUT
            operation           : IOperation**'''
        return super(IOperationStack, self).get_Item(index)
    def Reset(self):
        '''Method IOperationStack.Reset'''
        return super(IOperationStack, self).Reset()
    def Do(self, operation):
        '''Method IOperationStack.Do

           INPUT
            operation           : IOperation*'''
        return super(IOperationStack, self).Do(operation)
    def Undo(self):
        '''Method IOperationStack.Undo'''
        return super(IOperationStack, self).Undo()
    def Redo(self):
        '''Method IOperationStack.Redo'''
        return super(IOperationStack, self).Redo()
    def get_UndoOperation(self):
        '''Method IOperationStack.get_UndoOperation

           OUTPUT
            operation           : IOperation**'''
        return super(IOperationStack, self).get_UndoOperation()
    def get_RedoOperation(self):
        '''Method IOperationStack.get_RedoOperation

           OUTPUT
            operation           : IOperation**'''
        return super(IOperationStack, self).get_RedoOperation()
    def Remove(self, index):
        '''Method IOperationStack.Remove

           INPUT
            index               : long'''
        return super(IOperationStack, self).Remove(index)
    Count = property(get_Count, None, None)
    RedoOperation = property(get_RedoOperation, None, None)
    UndoOperation = property(get_UndoOperation, None, None)
    Item = IndexProperty(get_Item, None)

class IToolSelectedLayer(_esriSystemUI.IToolSelectedLayer):
    _IID = uuid.UUID('fc6732db-6295-4b39-b257-8c799ae20567')

    def __init__(self, *args, **kw):
        super(IToolSelectedLayer, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def put_LayerIndex(self, LayerIndex):
        '''Method IToolSelectedLayer.put_LayerIndex

           INPUT
            LayerIndex          : long'''
        return super(IToolSelectedLayer, self).put_LayerIndex(LayerIndex)
    def get_LayerIndex(self):
        '''Method IToolSelectedLayer.get_LayerIndex

           OUTPUT
            LayerIndex          : long*'''
        return super(IToolSelectedLayer, self).get_LayerIndex()
    LayerIndex = property(get_LayerIndex, put_LayerIndex, None)

class ISystemMouseCursor(_esriSystemUI.ISystemMouseCursor):
    _IID = uuid.UUID('623bf41c-3e34-4586-a729-c2e34cbe8fa9')

    def __init__(self, *args, **kw):
        super(ISystemMouseCursor, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def Load(self, mouseCursorType):
        '''Method ISystemMouseCursor.Load

           INPUT
            mouseCursorType     : esriSystemMouseCursor'''
        return super(ISystemMouseCursor, self).Load(mouseCursorType)
    def LoadFromFile(self, fileName):
        '''Method ISystemMouseCursor.LoadFromFile

           INPUT
            fileName            : BSTR'''
        return super(ISystemMouseCursor, self).LoadFromFile(fileName)
    def get_Cursor(self):
        '''Method ISystemMouseCursor.get_Cursor

           OUTPUT
            mouseCursor         : OLE_HANDLE*'''
        return super(ISystemMouseCursor, self).get_Cursor()
    def put_Cursor(self, mouseCursor):
        '''Method ISystemMouseCursor.put_Cursor

           INPUT
            mouseCursor         : OLE_HANDLE'''
        return super(ISystemMouseCursor, self).put_Cursor(mouseCursor)
    Cursor = property(get_Cursor, put_Cursor, None)

class IDataObjectHelper(_esriSystemUI.IDataObjectHelper):
    _IID = uuid.UUID('e0ccbcb0-cd47-11d5-a9e6-00104bb6fc1c')

    def __init__(self, *args, **kw):
        super(IDataObjectHelper, self).__init__(*args)
        for k, a in kw.iteritems():
            setattr(self, k, a)

    def putref_InternalObject(self, ppObject):
        '''Method IDataObjectHelper.putref_InternalObject

           INPUT
            ppObject            : IUnknown*'''
        return super(IDataObjectHelper, self).putref_InternalObject(ppObject)
    def get_InternalObject(self):
        '''Method IDataObjectHelper.get_InternalObject

           OUTPUT
            ppObject            : IUnknown**'''
        return super(IDataObjectHelper, self).get_InternalObject()
    def GetData(self, format):
        '''Method IDataObjectHelper.GetData

           INPUT
            format              : long

           OUTPUT
            pvData              : VARIANT*'''
        return super(IDataObjectHelper, self).GetData(format)
    def GetFormat(self, format):
        '''Method IDataObjectHelper.GetFormat

           INPUT
            format              : long

           OUTPUT
            pbFormatSupported   : VARIANT_BOOL*'''
        return super(IDataObjectHelper, self).GetFormat(format)
    def CanGetFiles(self):
        '''Method IDataObjectHelper.CanGetFiles

           OUTPUT
            CanGetFiles         : VARIANT_BOOL*'''
        return super(IDataObjectHelper, self).CanGetFiles()
    def GetFiles(self):
        '''Method IDataObjectHelper.GetFiles

           OUTPUT
            pvData              : VARIANT*'''
        return super(IDataObjectHelper, self).GetFiles()
    def CanGetNames(self):
        '''Method IDataObjectHelper.CanGetNames

           OUTPUT
            CanGetNames         : VARIANT_BOOL*'''
        return super(IDataObjectHelper, self).CanGetNames()
    def GetNames(self):
        '''Method IDataObjectHelper.GetNames

           OUTPUT
            ppNames             : IEnumName**'''
        return super(IDataObjectHelper, self).GetNames()
    InternalObject = property(get_InternalObject, putref_InternalObject, None)

class ICommandHost(_esriSystemUI.ICommandHost):
    _IID = uuid.UUID('14cb3146-6fdd-4b45-8759-0a297a4dad10')
    def SetCommand(self, commandInstance):
        '''Method ICommandHost.SetCommand

           INPUT
            commandInstance     : VARIANT*'''
        return super(ICommandHost, self).SetCommand(commandInstance)

class IArcGISPortal(_esriSystemUI.IArcGISPortal):
    _IID = uuid.UUID('a128a18c-6769-4e4f-90a9-df413d139192')
    def get_Portal(self):
        '''Method IArcGISPortal.get_Portal

           OUTPUT
            bsPortal            : BSTR*'''
        return super(IArcGISPortal, self).get_Portal()
    def get_SignonImage(self):
        '''Method IArcGISPortal.get_SignonImage

           OUTPUT
            hBitmap             : long*'''
        return super(IArcGISPortal, self).get_SignonImage()
    def get_BannerImage(self):
        '''Method IArcGISPortal.get_BannerImage

           OUTPUT
            hBitmap             : long*'''
        return super(IArcGISPortal, self).get_BannerImage()
    def get_BannerImageUrl(self):
        '''Method IArcGISPortal.get_BannerImageUrl

           OUTPUT
            bsUrl               : BSTR*'''
        return super(IArcGISPortal, self).get_BannerImageUrl()
    def get_Name(self):
        '''Method IArcGISPortal.get_Name

           OUTPUT
            bsName              : BSTR*'''
        return super(IArcGISPortal, self).get_Name()
    def get_IsMultiTenant(self):
        '''Method IArcGISPortal.get_IsMultiTenant

           OUTPUT
            isMulti             : VARIANT_BOOL*'''
        return super(IArcGISPortal, self).get_IsMultiTenant()
    BannerImage = property(get_BannerImage, None, None)
    BannerImageUrl = property(get_BannerImageUrl, None, None)
    IsMultiTenant = property(get_IsMultiTenant, None, None)
    Name = property(get_Name, None, None)
    Portal = property(get_Portal, None, None)
    SignonImage = property(get_SignonImage, None, None)

class IArcGISSingleSignon(_esriSystemUI.IArcGISSingleSignon):
    _IID = uuid.UUID('e36dc321-5c5b-4d6b-884e-19ff4b5bbcac')
    def GetToken(self, hParentHWND):
        '''Method IArcGISSingleSignon.GetToken

           INPUT
            hParentHWND         : long

           OUTPUTS
            bsToken             : BSTR*
            bsReferer           : BSTR*
            lExpiration         : long*
            bsUser              : BSTR*'''
        return super(IArcGISSingleSignon, self).GetToken(hParentHWND)
    def SignOut(self):
        '''Method IArcGISSingleSignon.SignOut'''
        return super(IArcGISSingleSignon, self).SignOut()
    def GetCurrentToken(self):
        '''Method IArcGISSingleSignon.GetCurrentToken

           OUTPUTS
            bsToken             : BSTR*
            bsReferer           : BSTR*
            lExpiration         : long*
            bsUser              : BSTR*'''
        return super(IArcGISSingleSignon, self).GetCurrentToken()
    def GetURI(self, eType):
        '''Method IArcGISSingleSignon.GetURI

           INPUT
            eType               : esriArcGISUri

           OUTPUT
            bsURI               : BSTR*'''
        return super(IArcGISSingleSignon, self).GetURI(eType)

class IArcGISSingleSignon2(_esriSystemUI.IArcGISSingleSignon2):
    _IID = uuid.UUID('10ef05c7-241f-4da0-a623-23ef607e0cab')
    def GetBingToken(self):
        '''Method IArcGISSingleSignon2.GetBingToken

           OUTPUTS
            bsToken             : BSTR*
            bsReferer           : BSTR*
            lExpiration         : long*'''
        return super(IArcGISSingleSignon2, self).GetBingToken()
    def GetToken(self, hParentHWND):
        '''Method IArcGISSingleSignon.GetToken (from IArcGISSingleSignon)

           INPUT
            hParentHWND         : long

           OUTPUTS
            bsToken             : BSTR*
            bsReferer           : BSTR*
            lExpiration         : long*
            bsUser              : BSTR*'''
        return super(IArcGISSingleSignon2, self).GetToken(hParentHWND)
    def SignOut(self):
        '''Method IArcGISSingleSignon.SignOut (from IArcGISSingleSignon)'''
        return super(IArcGISSingleSignon2, self).SignOut()
    def GetCurrentToken(self):
        '''Method IArcGISSingleSignon.GetCurrentToken (from IArcGISSingleSignon)

           OUTPUTS
            bsToken             : BSTR*
            bsReferer           : BSTR*
            lExpiration         : long*
            bsUser              : BSTR*'''
        return super(IArcGISSingleSignon2, self).GetCurrentToken()
    def GetURI(self, eType):
        '''Method IArcGISSingleSignon.GetURI (from IArcGISSingleSignon)

           INPUT
            eType               : esriArcGISUri

           OUTPUT
            bsURI               : BSTR*'''
        return super(IArcGISSingleSignon2, self).GetURI(eType)


# IIDs
IID_IProgressDialog = IProgressDialog._IID
IID_ICommand = ICommand._IID
IID_IComponentTip = IComponentTip._IID
IID_IComboBoxHook = IComboBoxHook._IID
IID_IComboBox = IComboBox._IID
IID_ICompletionNotify = ICompletionNotify._IID
IID_IToolControl = IToolControl._IID
IID_IToolPalette = IToolPalette._IID
IID_ITool = ITool._IID
IID_IToolKeys = IToolKeys._IID
IID_IItemDef = IItemDef._IID
IID_ICommandSubType = ICommandSubType._IID
IID_IToolBarDef = IToolBarDef._IID
IID_IMenuDef = IMenuDef._IID
IID_IPaletteDef = IPaletteDef._IID
IID_IMultiItemSeparator = IMultiItemSeparator._IID
IID_IMultiItem = IMultiItem._IID
IID_IMultiItemEx = IMultiItemEx._IID
IID_IComPropertySheetEvents = IComPropertySheetEvents._IID
IID_IOperation = IOperation._IID
IID_IOperationStack = IOperationStack._IID
IID_IToolSelectedLayer = IToolSelectedLayer._IID
IID_ISystemMouseCursor = ISystemMouseCursor._IID
IID_IDataObjectHelper = IDataObjectHelper._IID
IID_ICommandHost = ICommandHost._IID
IID_IArcGISPortal = IArcGISPortal._IID
IID_IArcGISSingleSignon = IArcGISSingleSignon._IID
IID_IArcGISSingleSignon2 = IArcGISSingleSignon2._IID
_IIDMap[IID_IProgressDialog] = IProgressDialog
_IIDMap[IID_ICommand] = ICommand
_IIDMap[IID_IComponentTip] = IComponentTip
_IIDMap[IID_IComboBoxHook] = IComboBoxHook
_IIDMap[IID_IComboBox] = IComboBox
_IIDMap[IID_ICompletionNotify] = ICompletionNotify
_IIDMap[IID_IToolControl] = IToolControl
_IIDMap[IID_IToolPalette] = IToolPalette
_IIDMap[IID_ITool] = ITool
_IIDMap[IID_IToolKeys] = IToolKeys
_IIDMap[IID_IItemDef] = IItemDef
_IIDMap[IID_ICommandSubType] = ICommandSubType
_IIDMap[IID_IToolBarDef] = IToolBarDef
_IIDMap[IID_IMenuDef] = IMenuDef
_IIDMap[IID_IPaletteDef] = IPaletteDef
_IIDMap[IID_IMultiItemSeparator] = IMultiItemSeparator
_IIDMap[IID_IMultiItem] = IMultiItem
_IIDMap[IID_IMultiItemEx] = IMultiItemEx
_IIDMap[IID_IComPropertySheetEvents] = IComPropertySheetEvents
_IIDMap[IID_IOperation] = IOperation
_IIDMap[IID_IOperationStack] = IOperationStack
_IIDMap[IID_IToolSelectedLayer] = IToolSelectedLayer
_IIDMap[IID_ISystemMouseCursor] = ISystemMouseCursor
_IIDMap[IID_IDataObjectHelper] = IDataObjectHelper
_IIDMap[IID_ICommandHost] = ICommandHost
_IIDMap[IID_IArcGISPortal] = IArcGISPortal
_IIDMap[IID_IArcGISSingleSignon] = IArcGISSingleSignon
_IIDMap[IID_IArcGISSingleSignon2] = IArcGISSingleSignon2


# CLSIDs
CLSID_DataObjectHelper = uuid.UUID('e0ccbcb1-cd47-11d5-a9e6-00104bb6fc1c')
CLSID_ControlsOperationStack = uuid.UUID('05e57adb-7785-4d48-b982-8255730a41e3')
CLSID_CommandHost = uuid.UUID('a318a696-3ed1-4775-a922-147e8c36d79d')
CLSID_ToolHost = uuid.UUID('60598c68-56ca-4a38-a2d4-328cb74dc665')
CLSID_ComPropertySheetEventsProxyHelper = uuid.UUID('ef32cd1c-e37d-4524-b8d5-6d89d1e85bed')
CLSID_SystemFont = uuid.UUID('f130210c-5478-43de-8012-1c02ddd97ba1')
CLSID_SystemMouseCursor = uuid.UUID('cf0c4485-2091-4e5a-a64c-69e4b802f444')
CLSID_ArcGISSingleSignon = uuid.UUID('dae2351b-241b-426d-a3da-056839a54743')

# Enumerations
class esriArcGISUri(Enumeration):
    __slots__ = ['esriArcGISUriBase',
                 'esriArcGISUriSecure',
                 'esriArcGISUriUpdate',
                 'esriArcGISUriPing',
                 'esriArcGISUriSpeed',
                 'esriArcGISBasemapQuery',
                 'esriArcGISGlobeBasemapQuery',
                 'esriArcGISUriForgottenPassword',
                 'esriArcGISUriNewAccount',
                 'esriArcGISSiteName']
    esriArcGISUriBase = 0
    esriArcGISUriSecure = 1
    esriArcGISUriUpdate = 2
    esriArcGISUriPing = 3
    esriArcGISUriSpeed = 4
    esriArcGISBasemapQuery = 5
    esriArcGISGlobeBasemapQuery = 6
    esriArcGISUriForgottenPassword = 7
    esriArcGISUriNewAccount = 8
    esriArcGISSiteName = 9

class esriCommandStyles(Enumeration):
    __slots__ = ['esriCommandStyleTextOnly',
                 'esriCommandStyleIconOnly',
                 'esriCommandStyleIconAndText',
                 'esriCommandStyleMenuBar']
    esriCommandStyleTextOnly = 0
    esriCommandStyleIconOnly = 1
    esriCommandStyleIconAndText = 2
    esriCommandStyleMenuBar = 4

class esriCmdBarType(Enumeration):
    __slots__ = ['esriCmdBarTypeToolbar',
                 'esriCmdBarTypeMenu',
                 'esriCmdBarTypeShortcutMenu']
    esriCmdBarTypeToolbar = 0
    esriCmdBarTypeMenu = 1
    esriCmdBarTypeShortcutMenu = 2

class esriSystemMouseCursor(Enumeration):
    __slots__ = ['esriSystemMouseCursorDefault',
                 'esriSystemMouseCursorArrow',
                 'esriSystemMouseCursorCrosshair',
                 'esriSystemMouseCursorIBeam',
                 'esriSystemMouseCursorIcon',
                 'esriSystemMouseCursorSize',
                 'esriSystemMouseCursorSizeNESW',
                 'esriSystemMouseCursorSizeNS',
                 'esriSystemMouseCursorSizeNWSE',
                 'esriSystemMouseCursorSizeWE',
                 'esriSystemMouseCursorUpArrow',
                 'esriSystemMouseCursorHourglass',
                 'esriSystemMouseCursorNoDrop',
                 'esriSystemMouseCursorArrowHourglass',
                 'esriSystemMouseCursorArrowQuestion',
                 'esriSystemMouseCursorSizeAll',
                 'esriSystemMouseCursorZoom',
                 'esriSystemMouseCursorZoomIn',
                 'esriSystemMouseCursorZoomOut',
                 'esriSystemMouseCursorPan',
                 'esriSystemMouseCursorPanning',
                 'esriSystemMouseCursorIdentify',
                 'esriSystemMouseCursorLabel',
                 'esriSystemMouseCursorHotLink',
                 'esriSystemMouseCursorPencil',
                 'esriSystemMouseCursorHand',
                 'esriSystemMouseCursorPageZoomIn',
                 'esriSystemMouseCursorPageZoomOut',
                 'esriSystemMouseCursorPagePan',
                 'esriSystemMouseCursorPagePanning']
    esriSystemMouseCursorDefault = 0
    esriSystemMouseCursorArrow = 1
    esriSystemMouseCursorCrosshair = 2
    esriSystemMouseCursorIBeam = 3
    esriSystemMouseCursorIcon = 4
    esriSystemMouseCursorSize = 5
    esriSystemMouseCursorSizeNESW = 6
    esriSystemMouseCursorSizeNS = 7
    esriSystemMouseCursorSizeNWSE = 8
    esriSystemMouseCursorSizeWE = 9
    esriSystemMouseCursorUpArrow = 10
    esriSystemMouseCursorHourglass = 11
    esriSystemMouseCursorNoDrop = 12
    esriSystemMouseCursorArrowHourglass = 13
    esriSystemMouseCursorArrowQuestion = 14
    esriSystemMouseCursorSizeAll = 15
    esriSystemMouseCursorZoom = 50
    esriSystemMouseCursorZoomIn = 51
    esriSystemMouseCursorZoomOut = 52
    esriSystemMouseCursorPan = 53
    esriSystemMouseCursorPanning = 54
    esriSystemMouseCursorIdentify = 55
    esriSystemMouseCursorLabel = 56
    esriSystemMouseCursorHotLink = 57
    esriSystemMouseCursorPencil = 58
    esriSystemMouseCursorHand = 59
    esriSystemMouseCursorPageZoomIn = 60
    esriSystemMouseCursorPageZoomOut = 61
    esriSystemMouseCursorPagePan = 62
    esriSystemMouseCursorPagePanning = 63

class esriTipStyle(Enumeration):
    __slots__ = ['esriTipStyleSolid',
                 'esriTipStyleTransparent']
    esriTipStyleSolid = 0
    esriTipStyleTransparent = 1

class esriKeyIntercept(Enumeration):
    __slots__ = ['esriKeyInterceptNone',
                 'esriKeyInterceptArrowKeys',
                 'esriKeyInterceptAlt',
                 'esriKeyInterceptTab',
                 'esriKeyInterceptEnter']
    esriKeyInterceptNone = 0
    esriKeyInterceptArrowKeys = 1
    esriKeyInterceptAlt = 2
    esriKeyInterceptTab = 4
    esriKeyInterceptEnter = 8

