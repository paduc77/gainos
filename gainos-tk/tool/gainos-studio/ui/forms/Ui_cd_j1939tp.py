# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'F:\parai@foxmail.com\github\gainos-tk\tool\gainos-studio\ui\forms\cd_j1939tp.ui'
#
# Created: Mon Jun 10 12:17:12 2013
#      by: PyQt4 UI code generator 4.8.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_cd_j1939tp(object):
    def setupUi(self, cd_j1939tp):
        cd_j1939tp.setObjectName(_fromUtf8("cd_j1939tp"))
        cd_j1939tp.resize(856, 578)
        cd_j1939tp.setStyleSheet(_fromUtf8("font: 12pt \"Consolas\";"))
        self.groupBox = QtGui.QGroupBox(cd_j1939tp)
        self.groupBox.setGeometry(QtCore.QRect(10, 0, 831, 91))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.layoutWidget = QtGui.QWidget(self.groupBox)
        self.layoutWidget.setGeometry(QtCore.QRect(380, 20, 441, 62))
        self.layoutWidget.setObjectName(_fromUtf8("layoutWidget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.layoutWidget)
        self.verticalLayout.setMargin(0)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.horizontalLayout_2 = QtGui.QHBoxLayout()
        self.horizontalLayout_2.setObjectName(_fromUtf8("horizontalLayout_2"))
        self.label_2 = QtGui.QLabel(self.layoutWidget)
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.horizontalLayout_2.addWidget(self.label_2)
        self.spbxMainFncPeriod = QtGui.QSpinBox(self.layoutWidget)
        self.spbxMainFncPeriod.setMaximum(65535)
        self.spbxMainFncPeriod.setObjectName(_fromUtf8("spbxMainFncPeriod"))
        self.horizontalLayout_2.addWidget(self.spbxMainFncPeriod)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.horizontalLayout_3 = QtGui.QHBoxLayout()
        self.horizontalLayout_3.setObjectName(_fromUtf8("horizontalLayout_3"))
        self.label_3 = QtGui.QLabel(self.layoutWidget)
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.horizontalLayout_3.addWidget(self.label_3)
        self.spbxCfTmo = QtGui.QSpinBox(self.layoutWidget)
        self.spbxCfTmo.setMaximum(65535)
        self.spbxCfTmo.setObjectName(_fromUtf8("spbxCfTmo"))
        self.horizontalLayout_3.addWidget(self.spbxCfTmo)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        self.layoutWidget1 = QtGui.QWidget(self.groupBox)
        self.layoutWidget1.setGeometry(QtCore.QRect(20, 20, 311, 58))
        self.layoutWidget1.setObjectName(_fromUtf8("layoutWidget1"))
        self.verticalLayout_2 = QtGui.QVBoxLayout(self.layoutWidget1)
        self.verticalLayout_2.setMargin(0)
        self.verticalLayout_2.setObjectName(_fromUtf8("verticalLayout_2"))
        self.cbxDevError = QtGui.QCheckBox(self.layoutWidget1)
        self.cbxDevError.setObjectName(_fromUtf8("cbxDevError"))
        self.verticalLayout_2.addWidget(self.cbxDevError)
        self.horizontalLayout = QtGui.QHBoxLayout()
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.label = QtGui.QLabel(self.layoutWidget1)
        self.label.setObjectName(_fromUtf8("label"))
        self.horizontalLayout.addWidget(self.label)
        self.spbxPktBlk = QtGui.QSpinBox(self.layoutWidget1)
        self.spbxPktBlk.setMaximum(65535)
        self.spbxPktBlk.setObjectName(_fromUtf8("spbxPktBlk"))
        self.horizontalLayout.addWidget(self.spbxPktBlk)
        self.verticalLayout_2.addLayout(self.horizontalLayout)
        self.groupBox_2 = QtGui.QGroupBox(cd_j1939tp)
        self.groupBox_2.setGeometry(QtCore.QRect(10, 100, 841, 471))
        self.groupBox_2.setObjectName(_fromUtf8("groupBox_2"))
        self.trJ1939Tp = QtGui.QTreeWidget(self.groupBox_2)
        self.trJ1939Tp.setGeometry(QtCore.QRect(10, 30, 251, 431))
        self.trJ1939Tp.setObjectName(_fromUtf8("trJ1939Tp"))
        item_0 = QtGui.QTreeWidgetItem(self.trJ1939Tp)
        item_0 = QtGui.QTreeWidgetItem(self.trJ1939Tp)
        self.tabJ1939Tp = QtGui.QTabWidget(self.groupBox_2)
        self.tabJ1939Tp.setGeometry(QtCore.QRect(420, 30, 421, 431))
        self.tabJ1939Tp.setObjectName(_fromUtf8("tabJ1939Tp"))
        self.tab = QtGui.QWidget()
        self.tab.setObjectName(_fromUtf8("tab"))
        self.layoutWidget2 = QtGui.QWidget(self.tab)
        self.layoutWidget2.setGeometry(QtCore.QRect(10, 20, 391, 161))
        self.layoutWidget2.setObjectName(_fromUtf8("layoutWidget2"))
        self.verticalLayout_4 = QtGui.QVBoxLayout(self.layoutWidget2)
        self.verticalLayout_4.setMargin(0)
        self.verticalLayout_4.setObjectName(_fromUtf8("verticalLayout_4"))
        self.horizontalLayout_4 = QtGui.QHBoxLayout()
        self.horizontalLayout_4.setObjectName(_fromUtf8("horizontalLayout_4"))
        self.label_4 = QtGui.QLabel(self.layoutWidget2)
        self.label_4.setObjectName(_fromUtf8("label_4"))
        self.horizontalLayout_4.addWidget(self.label_4)
        self.leRxChlName = QtGui.QLineEdit(self.layoutWidget2)
        self.leRxChlName.setObjectName(_fromUtf8("leRxChlName"))
        self.horizontalLayout_4.addWidget(self.leRxChlName)
        self.verticalLayout_4.addLayout(self.horizontalLayout_4)
        self.horizontalLayout_5 = QtGui.QHBoxLayout()
        self.horizontalLayout_5.setObjectName(_fromUtf8("horizontalLayout_5"))
        self.label_5 = QtGui.QLabel(self.layoutWidget2)
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.horizontalLayout_5.addWidget(self.label_5)
        self.cmbxRxProType = QtGui.QComboBox(self.layoutWidget2)
        self.cmbxRxProType.setObjectName(_fromUtf8("cmbxRxProType"))
        self.cmbxRxProType.addItem(_fromUtf8(""))
        self.cmbxRxProType.addItem(_fromUtf8(""))
        self.horizontalLayout_5.addWidget(self.cmbxRxProType)
        self.verticalLayout_4.addLayout(self.horizontalLayout_5)
        self.horizontalLayout_6 = QtGui.QHBoxLayout()
        self.horizontalLayout_6.setObjectName(_fromUtf8("horizontalLayout_6"))
        self.label_6 = QtGui.QLabel(self.layoutWidget2)
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.horizontalLayout_6.addWidget(self.label_6)
        self.cmbxRxCmNpdu = QtGui.QComboBox(self.layoutWidget2)
        self.cmbxRxCmNpdu.setObjectName(_fromUtf8("cmbxRxCmNpdu"))
        self.horizontalLayout_6.addWidget(self.cmbxRxCmNpdu)
        self.verticalLayout_4.addLayout(self.horizontalLayout_6)
        self.horizontalLayout_7 = QtGui.QHBoxLayout()
        self.horizontalLayout_7.setObjectName(_fromUtf8("horizontalLayout_7"))
        self.label_7 = QtGui.QLabel(self.layoutWidget2)
        self.label_7.setObjectName(_fromUtf8("label_7"))
        self.horizontalLayout_7.addWidget(self.label_7)
        self.cmbxRxDtNpdu = QtGui.QComboBox(self.layoutWidget2)
        self.cmbxRxDtNpdu.setObjectName(_fromUtf8("cmbxRxDtNpdu"))
        self.horizontalLayout_7.addWidget(self.cmbxRxDtNpdu)
        self.verticalLayout_4.addLayout(self.horizontalLayout_7)
        self.horizontalLayout_8 = QtGui.QHBoxLayout()
        self.horizontalLayout_8.setObjectName(_fromUtf8("horizontalLayout_8"))
        self.label_8 = QtGui.QLabel(self.layoutWidget2)
        self.label_8.setObjectName(_fromUtf8("label_8"))
        self.horizontalLayout_8.addWidget(self.label_8)
        self.cmbxTxFcNpdu = QtGui.QComboBox(self.layoutWidget2)
        self.cmbxTxFcNpdu.setObjectName(_fromUtf8("cmbxTxFcNpdu"))
        self.horizontalLayout_8.addWidget(self.cmbxTxFcNpdu)
        self.verticalLayout_4.addLayout(self.horizontalLayout_8)
        self.tabJ1939Tp.addTab(self.tab, _fromUtf8(""))
        self.tab_2 = QtGui.QWidget()
        self.tab_2.setObjectName(_fromUtf8("tab_2"))
        self.layoutWidget3 = QtGui.QWidget(self.tab_2)
        self.layoutWidget3.setGeometry(QtCore.QRect(10, 21, 391, 186))
        self.layoutWidget3.setObjectName(_fromUtf8("layoutWidget3"))
        self.verticalLayout_5 = QtGui.QVBoxLayout(self.layoutWidget3)
        self.verticalLayout_5.setMargin(0)
        self.verticalLayout_5.setObjectName(_fromUtf8("verticalLayout_5"))
        self.horizontalLayout_9 = QtGui.QHBoxLayout()
        self.horizontalLayout_9.setObjectName(_fromUtf8("horizontalLayout_9"))
        self.label_9 = QtGui.QLabel(self.layoutWidget3)
        self.label_9.setObjectName(_fromUtf8("label_9"))
        self.horizontalLayout_9.addWidget(self.label_9)
        self.leParmName = QtGui.QLineEdit(self.layoutWidget3)
        self.leParmName.setObjectName(_fromUtf8("leParmName"))
        self.horizontalLayout_9.addWidget(self.leParmName)
        self.verticalLayout_5.addLayout(self.horizontalLayout_9)
        self.horizontalLayout_10 = QtGui.QHBoxLayout()
        self.horizontalLayout_10.setObjectName(_fromUtf8("horizontalLayout_10"))
        self.label_10 = QtGui.QLabel(self.layoutWidget3)
        self.label_10.setObjectName(_fromUtf8("label_10"))
        self.horizontalLayout_10.addWidget(self.label_10)
        self.lePgn = QtGui.QLineEdit(self.layoutWidget3)
        self.lePgn.setObjectName(_fromUtf8("lePgn"))
        self.horizontalLayout_10.addWidget(self.lePgn)
        self.verticalLayout_5.addLayout(self.horizontalLayout_10)
        self.horizontalLayout_12 = QtGui.QHBoxLayout()
        self.horizontalLayout_12.setObjectName(_fromUtf8("horizontalLayout_12"))
        self.label_12 = QtGui.QLabel(self.layoutWidget3)
        self.label_12.setObjectName(_fromUtf8("label_12"))
        self.horizontalLayout_12.addWidget(self.label_12)
        self.cmbxParmNSdu = QtGui.QComboBox(self.layoutWidget3)
        self.cmbxParmNSdu.setObjectName(_fromUtf8("cmbxParmNSdu"))
        self.horizontalLayout_12.addWidget(self.cmbxParmNSdu)
        self.verticalLayout_5.addLayout(self.horizontalLayout_12)
        self.cbxDynNPdu = QtGui.QCheckBox(self.layoutWidget3)
        self.cbxDynNPdu.setObjectName(_fromUtf8("cbxDynNPdu"))
        self.verticalLayout_5.addWidget(self.cbxDynNPdu)
        self.cbxEnDrtNPdu = QtGui.QCheckBox(self.layoutWidget3)
        self.cbxEnDrtNPdu.setObjectName(_fromUtf8("cbxEnDrtNPdu"))
        self.verticalLayout_5.addWidget(self.cbxEnDrtNPdu)
        self.horizontalLayout_13 = QtGui.QHBoxLayout()
        self.horizontalLayout_13.setObjectName(_fromUtf8("horizontalLayout_13"))
        self.label_13 = QtGui.QLabel(self.layoutWidget3)
        self.label_13.setObjectName(_fromUtf8("label_13"))
        self.horizontalLayout_13.addWidget(self.label_13)
        self.cmbxDrtNpdu = QtGui.QComboBox(self.layoutWidget3)
        self.cmbxDrtNpdu.setObjectName(_fromUtf8("cmbxDrtNpdu"))
        self.horizontalLayout_13.addWidget(self.cmbxDrtNpdu)
        self.verticalLayout_5.addLayout(self.horizontalLayout_13)
        self.tabJ1939Tp.addTab(self.tab_2, _fromUtf8(""))
        self.tab_3 = QtGui.QWidget()
        self.tab_3.setObjectName(_fromUtf8("tab_3"))
        self.layoutWidget_7 = QtGui.QWidget(self.tab_3)
        self.layoutWidget_7.setGeometry(QtCore.QRect(10, 20, 391, 161))
        self.layoutWidget_7.setObjectName(_fromUtf8("layoutWidget_7"))
        self.verticalLayout_6 = QtGui.QVBoxLayout(self.layoutWidget_7)
        self.verticalLayout_6.setMargin(0)
        self.verticalLayout_6.setObjectName(_fromUtf8("verticalLayout_6"))
        self.horizontalLayout_11 = QtGui.QHBoxLayout()
        self.horizontalLayout_11.setObjectName(_fromUtf8("horizontalLayout_11"))
        self.label_11 = QtGui.QLabel(self.layoutWidget_7)
        self.label_11.setObjectName(_fromUtf8("label_11"))
        self.horizontalLayout_11.addWidget(self.label_11)
        self.leTxChlName = QtGui.QLineEdit(self.layoutWidget_7)
        self.leTxChlName.setObjectName(_fromUtf8("leTxChlName"))
        self.horizontalLayout_11.addWidget(self.leTxChlName)
        self.verticalLayout_6.addLayout(self.horizontalLayout_11)
        self.horizontalLayout_14 = QtGui.QHBoxLayout()
        self.horizontalLayout_14.setObjectName(_fromUtf8("horizontalLayout_14"))
        self.label_14 = QtGui.QLabel(self.layoutWidget_7)
        self.label_14.setObjectName(_fromUtf8("label_14"))
        self.horizontalLayout_14.addWidget(self.label_14)
        self.cmbxTxProType = QtGui.QComboBox(self.layoutWidget_7)
        self.cmbxTxProType.setObjectName(_fromUtf8("cmbxTxProType"))
        self.cmbxTxProType.addItem(_fromUtf8(""))
        self.cmbxTxProType.addItem(_fromUtf8(""))
        self.horizontalLayout_14.addWidget(self.cmbxTxProType)
        self.verticalLayout_6.addLayout(self.horizontalLayout_14)
        self.horizontalLayout_15 = QtGui.QHBoxLayout()
        self.horizontalLayout_15.setObjectName(_fromUtf8("horizontalLayout_15"))
        self.label_15 = QtGui.QLabel(self.layoutWidget_7)
        self.label_15.setObjectName(_fromUtf8("label_15"))
        self.horizontalLayout_15.addWidget(self.label_15)
        self.cmbxTxCmNpdu = QtGui.QComboBox(self.layoutWidget_7)
        self.cmbxTxCmNpdu.setObjectName(_fromUtf8("cmbxTxCmNpdu"))
        self.horizontalLayout_15.addWidget(self.cmbxTxCmNpdu)
        self.verticalLayout_6.addLayout(self.horizontalLayout_15)
        self.horizontalLayout_16 = QtGui.QHBoxLayout()
        self.horizontalLayout_16.setObjectName(_fromUtf8("horizontalLayout_16"))
        self.label_16 = QtGui.QLabel(self.layoutWidget_7)
        self.label_16.setObjectName(_fromUtf8("label_16"))
        self.horizontalLayout_16.addWidget(self.label_16)
        self.cmbxTxDtNpdu = QtGui.QComboBox(self.layoutWidget_7)
        self.cmbxTxDtNpdu.setObjectName(_fromUtf8("cmbxTxDtNpdu"))
        self.horizontalLayout_16.addWidget(self.cmbxTxDtNpdu)
        self.verticalLayout_6.addLayout(self.horizontalLayout_16)
        self.horizontalLayout_17 = QtGui.QHBoxLayout()
        self.horizontalLayout_17.setObjectName(_fromUtf8("horizontalLayout_17"))
        self.label_17 = QtGui.QLabel(self.layoutWidget_7)
        self.label_17.setObjectName(_fromUtf8("label_17"))
        self.horizontalLayout_17.addWidget(self.label_17)
        self.cmbxRxFcNpdu = QtGui.QComboBox(self.layoutWidget_7)
        self.cmbxRxFcNpdu.setObjectName(_fromUtf8("cmbxRxFcNpdu"))
        self.horizontalLayout_17.addWidget(self.cmbxRxFcNpdu)
        self.verticalLayout_6.addLayout(self.horizontalLayout_17)
        self.tabJ1939Tp.addTab(self.tab_3, _fromUtf8(""))
        self.layoutWidget4 = QtGui.QWidget(self.groupBox_2)
        self.layoutWidget4.setGeometry(QtCore.QRect(270, 70, 141, 62))
        self.layoutWidget4.setObjectName(_fromUtf8("layoutWidget4"))
        self.verticalLayout_3 = QtGui.QVBoxLayout(self.layoutWidget4)
        self.verticalLayout_3.setMargin(0)
        self.verticalLayout_3.setObjectName(_fromUtf8("verticalLayout_3"))
        self.btn1 = QtGui.QPushButton(self.layoutWidget4)
        self.btn1.setObjectName(_fromUtf8("btn1"))
        self.verticalLayout_3.addWidget(self.btn1)
        self.btn2 = QtGui.QPushButton(self.layoutWidget4)
        self.btn2.setObjectName(_fromUtf8("btn2"))
        self.verticalLayout_3.addWidget(self.btn2)

        self.retranslateUi(cd_j1939tp)
        self.tabJ1939Tp.setCurrentIndex(1)
        QtCore.QMetaObject.connectSlotsByName(cd_j1939tp)

    def retranslateUi(self, cd_j1939tp):
        cd_j1939tp.setWindowTitle(QtGui.QApplication.translate("cd_j1939tp", "Dialog", None, QtGui.QApplication.UnicodeUTF8))
        self.groupBox.setTitle(QtGui.QApplication.translate("cd_j1939tp", "General", None, QtGui.QApplication.UnicodeUTF8))
        self.label_2.setText(QtGui.QApplication.translate("cd_j1939tp", "Main Function Period(ms):", None, QtGui.QApplication.UnicodeUTF8))
        self.label_3.setText(QtGui.QApplication.translate("cd_j1939tp", "Tx Confirmation Timeout(ms):", None, QtGui.QApplication.UnicodeUTF8))
        self.cbxDevError.setText(QtGui.QApplication.translate("cd_j1939tp", "Development Error Detection", None, QtGui.QApplication.UnicodeUTF8))
        self.label.setText(QtGui.QApplication.translate("cd_j1939tp", "Packets/Block:", None, QtGui.QApplication.UnicodeUTF8))
        self.groupBox_2.setTitle(QtGui.QApplication.translate("cd_j1939tp", "J1939Tp Entities", None, QtGui.QApplication.UnicodeUTF8))
        self.trJ1939Tp.headerItem().setText(0, QtGui.QApplication.translate("cd_j1939tp", "J1939Tp", None, QtGui.QApplication.UnicodeUTF8))
        __sortingEnabled = self.trJ1939Tp.isSortingEnabled()
        self.trJ1939Tp.setSortingEnabled(False)
        self.trJ1939Tp.topLevelItem(0).setText(0, QtGui.QApplication.translate("cd_j1939tp", "RxChannel", None, QtGui.QApplication.UnicodeUTF8))
        self.trJ1939Tp.topLevelItem(1).setText(0, QtGui.QApplication.translate("cd_j1939tp", "TxChannel", None, QtGui.QApplication.UnicodeUTF8))
        self.trJ1939Tp.setSortingEnabled(__sortingEnabled)
        self.label_4.setText(QtGui.QApplication.translate("cd_j1939tp", "Name:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_5.setText(QtGui.QApplication.translate("cd_j1939tp", "Protocol Type:", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxRxProType.setItemText(0, QtGui.QApplication.translate("cd_j1939tp", "J1939TP_PROTOCOL_BAM", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxRxProType.setItemText(1, QtGui.QApplication.translate("cd_j1939tp", "J1939TP_PROTOCOL_CMDT", None, QtGui.QApplication.UnicodeUTF8))
        self.label_6.setText(QtGui.QApplication.translate("cd_j1939tp", "CM N-PDU:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_7.setText(QtGui.QApplication.translate("cd_j1939tp", "DT N-PDU:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_8.setText(QtGui.QApplication.translate("cd_j1939tp", "Tx FC N-PDU:", None, QtGui.QApplication.UnicodeUTF8))
        self.tabJ1939Tp.setTabText(self.tabJ1939Tp.indexOf(self.tab), QtGui.QApplication.translate("cd_j1939tp", "Rx Channel", None, QtGui.QApplication.UnicodeUTF8))
        self.label_9.setText(QtGui.QApplication.translate("cd_j1939tp", "Name:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_10.setText(QtGui.QApplication.translate("cd_j1939tp", "PGN:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_12.setText(QtGui.QApplication.translate("cd_j1939tp", "N-SDU:", None, QtGui.QApplication.UnicodeUTF8))
        self.cbxDynNPdu.setText(QtGui.QApplication.translate("cd_j1939tp", "Dynamic N-PDU", None, QtGui.QApplication.UnicodeUTF8))
        self.cbxEnDrtNPdu.setText(QtGui.QApplication.translate("cd_j1939tp", "Enable Direct N-Pdu", None, QtGui.QApplication.UnicodeUTF8))
        self.label_13.setText(QtGui.QApplication.translate("cd_j1939tp", "Direct N-PDU:", None, QtGui.QApplication.UnicodeUTF8))
        self.tabJ1939Tp.setTabText(self.tabJ1939Tp.indexOf(self.tab_2), QtGui.QApplication.translate("cd_j1939tp", "Parameter Group", None, QtGui.QApplication.UnicodeUTF8))
        self.label_11.setText(QtGui.QApplication.translate("cd_j1939tp", "Name:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_14.setText(QtGui.QApplication.translate("cd_j1939tp", "Protocol Type:", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxTxProType.setItemText(0, QtGui.QApplication.translate("cd_j1939tp", "J1939TP_PROTOCOL_BAM", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxTxProType.setItemText(1, QtGui.QApplication.translate("cd_j1939tp", "J1939TP_PROTOCOL_CMDT", None, QtGui.QApplication.UnicodeUTF8))
        self.label_15.setText(QtGui.QApplication.translate("cd_j1939tp", "CM N-PDU:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_16.setText(QtGui.QApplication.translate("cd_j1939tp", "DT N-PDU:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_17.setText(QtGui.QApplication.translate("cd_j1939tp", "Rx FC N-PDU:", None, QtGui.QApplication.UnicodeUTF8))
        self.tabJ1939Tp.setTabText(self.tabJ1939Tp.indexOf(self.tab_3), QtGui.QApplication.translate("cd_j1939tp", "Tx Channel", None, QtGui.QApplication.UnicodeUTF8))
        self.btn1.setText(QtGui.QApplication.translate("cd_j1939tp", "Add", None, QtGui.QApplication.UnicodeUTF8))
        self.btn2.setText(QtGui.QApplication.translate("cd_j1939tp", "Del", None, QtGui.QApplication.UnicodeUTF8))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    cd_j1939tp = QtGui.QDialog()
    ui = Ui_cd_j1939tp()
    ui.setupUi(cd_j1939tp)
    cd_j1939tp.show()
    sys.exit(app.exec_())

