# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'F:\parai@foxmail.com\nt\gainos-tkernel\gainos_studio\ui_forms\comstack\EcuC_Dlg.ui'
#
# Created: Sun Apr 21 21:43:46 2013
#      by: PyQt4 UI code generator 4.8.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_EcuC_Dlg(object):
    def setupUi(self, EcuC_Dlg):
        EcuC_Dlg.setObjectName(_fromUtf8("EcuC_Dlg"))
        EcuC_Dlg.resize(802, 471)
        self.groupBox = QtGui.QGroupBox(EcuC_Dlg)
        self.groupBox.setGeometry(QtCore.QRect(0, 90, 781, 371))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.trEcucCfg = QtGui.QTreeWidget(self.groupBox)
        self.trEcucCfg.setGeometry(QtCore.QRect(20, 30, 256, 321))
        self.trEcucCfg.setObjectName(_fromUtf8("trEcucCfg"))
        item_0 = QtGui.QTreeWidgetItem(self.trEcucCfg)
        self.tabCfg = QtGui.QTabWidget(self.groupBox)
        self.tabCfg.setGeometry(QtCore.QRect(410, 20, 351, 141))
        self.tabCfg.setObjectName(_fromUtf8("tabCfg"))
        self.tab = QtGui.QWidget()
        self.tab.setObjectName(_fromUtf8("tab"))
        self.layoutWidget = QtGui.QWidget(self.tab)
        self.layoutWidget.setGeometry(QtCore.QRect(10, 21, 321, 80))
        self.layoutWidget.setObjectName(_fromUtf8("layoutWidget"))
        self.verticalLayout_2 = QtGui.QVBoxLayout(self.layoutWidget)
        self.verticalLayout_2.setMargin(0)
        self.verticalLayout_2.setObjectName(_fromUtf8("verticalLayout_2"))
        self.horizontalLayout_36 = QtGui.QHBoxLayout()
        self.horizontalLayout_36.setObjectName(_fromUtf8("horizontalLayout_36"))
        self.label_33 = QtGui.QLabel(self.layoutWidget)
        self.label_33.setObjectName(_fromUtf8("label_33"))
        self.horizontalLayout_36.addWidget(self.label_33)
        self.lePduName = QtGui.QLineEdit(self.layoutWidget)
        self.lePduName.setText(_fromUtf8(""))
        self.lePduName.setObjectName(_fromUtf8("lePduName"))
        self.horizontalLayout_36.addWidget(self.lePduName)
        self.verticalLayout_2.addLayout(self.horizontalLayout_36)
        self.horizontalLayout = QtGui.QHBoxLayout()
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.label = QtGui.QLabel(self.layoutWidget)
        self.label.setObjectName(_fromUtf8("label"))
        self.horizontalLayout.addWidget(self.label)
        self.spbxRxPduSize = QtGui.QSpinBox(self.layoutWidget)
        self.spbxRxPduSize.setMinimumSize(QtCore.QSize(220, 0))
        self.spbxRxPduSize.setObjectName(_fromUtf8("spbxRxPduSize"))
        self.horizontalLayout.addWidget(self.spbxRxPduSize)
        self.verticalLayout_2.addLayout(self.horizontalLayout)
        self.horizontalLayout_2 = QtGui.QHBoxLayout()
        self.horizontalLayout_2.setObjectName(_fromUtf8("horizontalLayout_2"))
        self.label_2 = QtGui.QLabel(self.layoutWidget)
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.horizontalLayout_2.addWidget(self.label_2)
        self.spbxTxPduSize = QtGui.QSpinBox(self.layoutWidget)
        self.spbxTxPduSize.setMinimumSize(QtCore.QSize(220, 0))
        self.spbxTxPduSize.setObjectName(_fromUtf8("spbxTxPduSize"))
        self.horizontalLayout_2.addWidget(self.spbxTxPduSize)
        self.verticalLayout_2.addLayout(self.horizontalLayout_2)
        self.tabCfg.addTab(self.tab, _fromUtf8(""))
        self.layoutWidget1 = QtGui.QWidget(self.groupBox)
        self.layoutWidget1.setGeometry(QtCore.QRect(290, 50, 101, 54))
        self.layoutWidget1.setObjectName(_fromUtf8("layoutWidget1"))
        self.verticalLayout = QtGui.QVBoxLayout(self.layoutWidget1)
        self.verticalLayout.setMargin(0)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.btnAdd = QtGui.QPushButton(self.layoutWidget1)
        self.btnAdd.setObjectName(_fromUtf8("btnAdd"))
        self.verticalLayout.addWidget(self.btnAdd)
        self.btnDel = QtGui.QPushButton(self.layoutWidget1)
        self.btnDel.setObjectName(_fromUtf8("btnDel"))
        self.verticalLayout.addWidget(self.btnDel)

        self.retranslateUi(EcuC_Dlg)
        self.tabCfg.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(EcuC_Dlg)

    def retranslateUi(self, EcuC_Dlg):
        EcuC_Dlg.setWindowTitle(QtGui.QApplication.translate("EcuC_Dlg", "EcuC Config", None, QtGui.QApplication.UnicodeUTF8))
        self.groupBox.setTitle(QtGui.QApplication.translate("EcuC_Dlg", "GroupBox", None, QtGui.QApplication.UnicodeUTF8))
        self.trEcucCfg.headerItem().setText(0, QtGui.QApplication.translate("EcuC_Dlg", "EcuC", None, QtGui.QApplication.UnicodeUTF8))
        __sortingEnabled = self.trEcucCfg.isSortingEnabled()
        self.trEcucCfg.setSortingEnabled(False)
        self.trEcucCfg.topLevelItem(0).setText(0, QtGui.QApplication.translate("EcuC_Dlg", "Pdus", None, QtGui.QApplication.UnicodeUTF8))
        self.trEcucCfg.setSortingEnabled(__sortingEnabled)
        self.label_33.setText(QtGui.QApplication.translate("EcuC_Dlg", "Name:", None, QtGui.QApplication.UnicodeUTF8))
        self.label.setText(QtGui.QApplication.translate("EcuC_Dlg", "Rx Size (bits):", None, QtGui.QApplication.UnicodeUTF8))
        self.spbxRxPduSize.setToolTip(QtGui.QApplication.translate("EcuC_Dlg", "May related to Com/Dcm IPDU and so on. Its size is up to the use of this Rx PDU.", None, QtGui.QApplication.UnicodeUTF8))
        self.label_2.setText(QtGui.QApplication.translate("EcuC_Dlg", "Tx Size (bits):", None, QtGui.QApplication.UnicodeUTF8))
        self.spbxTxPduSize.setToolTip(QtGui.QApplication.translate("EcuC_Dlg", "May related to Com/Dcm IPDU and so on. Its size is up to the use of this Tx PDU.", None, QtGui.QApplication.UnicodeUTF8))
        self.tabCfg.setTabText(self.tabCfg.indexOf(self.tab), QtGui.QApplication.translate("EcuC_Dlg", "Pdu", None, QtGui.QApplication.UnicodeUTF8))
        self.btnAdd.setText(QtGui.QApplication.translate("EcuC_Dlg", "Add Pdu", None, QtGui.QApplication.UnicodeUTF8))
        self.btnDel.setText(QtGui.QApplication.translate("EcuC_Dlg", "Del", None, QtGui.QApplication.UnicodeUTF8))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    EcuC_Dlg = QtGui.QDialog()
    ui = Ui_EcuC_Dlg()
    ui.setupUi(EcuC_Dlg)
    EcuC_Dlg.show()
    sys.exit(app.exec_())

