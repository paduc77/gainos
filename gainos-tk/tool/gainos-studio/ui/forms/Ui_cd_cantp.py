# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'F:\parai@foxmail.com\github\gainos-tk\tool\gainos-studio\ui\forms\cd_cantp.ui'
#
# Created: Sun May 19 10:15:09 2013
#      by: PyQt4 UI code generator 4.8.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_cd_cantp(object):
    def setupUi(self, cd_cantp):
        cd_cantp.setObjectName(_fromUtf8("cd_cantp"))
        cd_cantp.resize(934, 592)
        self.groupBox = QtGui.QGroupBox(cd_cantp)
        self.groupBox.setGeometry(QtCore.QRect(10, 10, 911, 51))
        self.groupBox.setObjectName(_fromUtf8("groupBox"))
        self.label_36 = QtGui.QLabel(self.groupBox)
        self.label_36.setGeometry(QtCore.QRect(570, 20, 21, 20))
        self.label_36.setObjectName(_fromUtf8("label_36"))
        self.layoutWidget = QtGui.QWidget(self.groupBox)
        self.layoutWidget.setGeometry(QtCore.QRect(230, 20, 334, 22))
        self.layoutWidget.setObjectName(_fromUtf8("layoutWidget"))
        self.horizontalLayout = QtGui.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout.setMargin(0)
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.label_35 = QtGui.QLabel(self.layoutWidget)
        self.label_35.setObjectName(_fromUtf8("label_35"))
        self.horizontalLayout.addWidget(self.label_35)
        self.spbxMainFunctionPeriod = QtGui.QSpinBox(self.layoutWidget)
        self.spbxMainFunctionPeriod.setMinimumSize(QtCore.QSize(200, 0))
        self.spbxMainFunctionPeriod.setObjectName(_fromUtf8("spbxMainFunctionPeriod"))
        self.horizontalLayout.addWidget(self.spbxMainFunctionPeriod)
        self.cbxDevErr = QtGui.QCheckBox(self.groupBox)
        self.cbxDevErr.setGeometry(QtCore.QRect(30, 20, 125, 16))
        self.cbxDevErr.setObjectName(_fromUtf8("cbxDevErr"))
        self.groupBox_2 = QtGui.QGroupBox(cd_cantp)
        self.groupBox_2.setGeometry(QtCore.QRect(10, 70, 911, 511))
        self.groupBox_2.setMaximumSize(QtCore.QSize(16777214, 16777215))
        self.groupBox_2.setObjectName(_fromUtf8("groupBox_2"))
        self.trCanTpCfg = QtGui.QTreeWidget(self.groupBox_2)
        self.trCanTpCfg.setGeometry(QtCore.QRect(20, 30, 256, 471))
        self.trCanTpCfg.setObjectName(_fromUtf8("trCanTpCfg"))
        item_0 = QtGui.QTreeWidgetItem(self.trCanTpCfg)
        item_0 = QtGui.QTreeWidgetItem(self.trCanTpCfg)
        self.tabCfg = QtGui.QTabWidget(self.groupBox_2)
        self.tabCfg.setGeometry(QtCore.QRect(420, 20, 471, 481))
        self.tabCfg.setObjectName(_fromUtf8("tabCfg"))
        self.tab_3 = QtGui.QWidget()
        self.tab_3.setObjectName(_fromUtf8("tab_3"))
        self.layoutWidget1 = QtGui.QWidget(self.tab_3)
        self.layoutWidget1.setGeometry(QtCore.QRect(21, 21, 426, 422))
        self.layoutWidget1.setObjectName(_fromUtf8("layoutWidget1"))
        self.verticalLayout_4 = QtGui.QVBoxLayout(self.layoutWidget1)
        self.verticalLayout_4.setMargin(0)
        self.verticalLayout_4.setObjectName(_fromUtf8("verticalLayout_4"))
        self.verticalLayout = QtGui.QVBoxLayout()
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.horizontalLayout_15 = QtGui.QHBoxLayout()
        self.horizontalLayout_15.setObjectName(_fromUtf8("horizontalLayout_15"))
        self.label_44 = QtGui.QLabel(self.layoutWidget1)
        self.label_44.setObjectName(_fromUtf8("label_44"))
        self.horizontalLayout_15.addWidget(self.label_44)
        self.leRxPduName = QtGui.QLineEdit(self.layoutWidget1)
        self.leRxPduName.setText(_fromUtf8(""))
        self.leRxPduName.setObjectName(_fromUtf8("leRxPduName"))
        self.horizontalLayout_15.addWidget(self.leRxPduName)
        self.verticalLayout.addLayout(self.horizontalLayout_15)
        self.horizontalLayout_4 = QtGui.QHBoxLayout()
        self.horizontalLayout_4.setObjectName(_fromUtf8("horizontalLayout_4"))
        self.label_40 = QtGui.QLabel(self.layoutWidget1)
        self.label_40.setObjectName(_fromUtf8("label_40"))
        self.horizontalLayout_4.addWidget(self.label_40)
        self.cmbxRxPduId = QtGui.QComboBox(self.layoutWidget1)
        self.cmbxRxPduId.setMinimumSize(QtCore.QSize(300, 0))
        self.cmbxRxPduId.setObjectName(_fromUtf8("cmbxRxPduId"))
        self.horizontalLayout_4.addWidget(self.cmbxRxPduId)
        self.verticalLayout.addLayout(self.horizontalLayout_4)
        self.horizontalLayout_2 = QtGui.QHBoxLayout()
        self.horizontalLayout_2.setObjectName(_fromUtf8("horizontalLayout_2"))
        self.label_29 = QtGui.QLabel(self.layoutWidget1)
        self.label_29.setObjectName(_fromUtf8("label_29"))
        self.horizontalLayout_2.addWidget(self.label_29)
        self.cmbxTxFcPduId = QtGui.QComboBox(self.layoutWidget1)
        self.cmbxTxFcPduId.setMinimumSize(QtCore.QSize(300, 0))
        self.cmbxTxFcPduId.setObjectName(_fromUtf8("cmbxTxFcPduId"))
        self.horizontalLayout_2.addWidget(self.cmbxTxFcPduId)
        self.verticalLayout.addLayout(self.horizontalLayout_2)
        self.horizontalLayout_5 = QtGui.QHBoxLayout()
        self.horizontalLayout_5.setObjectName(_fromUtf8("horizontalLayout_5"))
        self.label_2 = QtGui.QLabel(self.layoutWidget1)
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.horizontalLayout_5.addWidget(self.label_2)
        self.spbxRxPduDlc = QtGui.QSpinBox(self.layoutWidget1)
        self.spbxRxPduDlc.setMinimumSize(QtCore.QSize(200, 0))
        self.spbxRxPduDlc.setObjectName(_fromUtf8("spbxRxPduDlc"))
        self.horizontalLayout_5.addWidget(self.spbxRxPduDlc)
        self.verticalLayout.addLayout(self.horizontalLayout_5)
        self.horizontalLayout_6 = QtGui.QHBoxLayout()
        self.horizontalLayout_6.setObjectName(_fromUtf8("horizontalLayout_6"))
        self.label_30 = QtGui.QLabel(self.layoutWidget1)
        self.label_30.setObjectName(_fromUtf8("label_30"))
        self.horizontalLayout_6.addWidget(self.label_30)
        self.cmbxRxPduPadding = QtGui.QComboBox(self.layoutWidget1)
        self.cmbxRxPduPadding.setMinimumSize(QtCore.QSize(300, 0))
        self.cmbxRxPduPadding.setObjectName(_fromUtf8("cmbxRxPduPadding"))
        self.cmbxRxPduPadding.addItem(_fromUtf8(""))
        self.cmbxRxPduPadding.addItem(_fromUtf8(""))
        self.horizontalLayout_6.addWidget(self.cmbxRxPduPadding)
        self.verticalLayout.addLayout(self.horizontalLayout_6)
        self.horizontalLayout_16 = QtGui.QHBoxLayout()
        self.horizontalLayout_16.setObjectName(_fromUtf8("horizontalLayout_16"))
        self.label_32 = QtGui.QLabel(self.layoutWidget1)
        self.label_32.setObjectName(_fromUtf8("label_32"))
        self.horizontalLayout_16.addWidget(self.label_32)
        self.cmbxRxTaType = QtGui.QComboBox(self.layoutWidget1)
        self.cmbxRxTaType.setMinimumSize(QtCore.QSize(250, 0))
        self.cmbxRxTaType.setObjectName(_fromUtf8("cmbxRxTaType"))
        self.cmbxRxTaType.addItem(_fromUtf8(""))
        self.cmbxRxTaType.addItem(_fromUtf8(""))
        self.horizontalLayout_16.addWidget(self.cmbxRxTaType)
        self.verticalLayout.addLayout(self.horizontalLayout_16)
        self.horizontalLayout_3 = QtGui.QHBoxLayout()
        self.horizontalLayout_3.setObjectName(_fromUtf8("horizontalLayout_3"))
        self.label = QtGui.QLabel(self.layoutWidget1)
        self.label.setObjectName(_fromUtf8("label"))
        self.horizontalLayout_3.addWidget(self.label)
        self.spbxRxBs = QtGui.QSpinBox(self.layoutWidget1)
        self.spbxRxBs.setMinimumSize(QtCore.QSize(200, 0))
        self.spbxRxBs.setObjectName(_fromUtf8("spbxRxBs"))
        self.horizontalLayout_3.addWidget(self.spbxRxBs)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        self.horizontalLayout_17 = QtGui.QHBoxLayout()
        self.horizontalLayout_17.setObjectName(_fromUtf8("horizontalLayout_17"))
        self.label_5 = QtGui.QLabel(self.layoutWidget1)
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.horizontalLayout_17.addWidget(self.label_5)
        self.spbxRxSTmin = QtGui.QSpinBox(self.layoutWidget1)
        self.spbxRxSTmin.setMinimumSize(QtCore.QSize(200, 0))
        self.spbxRxSTmin.setObjectName(_fromUtf8("spbxRxSTmin"))
        self.horizontalLayout_17.addWidget(self.spbxRxSTmin)
        self.verticalLayout.addLayout(self.horizontalLayout_17)
        self.horizontalLayout_18 = QtGui.QHBoxLayout()
        self.horizontalLayout_18.setObjectName(_fromUtf8("horizontalLayout_18"))
        self.label_6 = QtGui.QLabel(self.layoutWidget1)
        self.label_6.setObjectName(_fromUtf8("label_6"))
        self.horizontalLayout_18.addWidget(self.label_6)
        self.spbxRxWftMax = QtGui.QSpinBox(self.layoutWidget1)
        self.spbxRxWftMax.setMinimumSize(QtCore.QSize(200, 0))
        self.spbxRxWftMax.setObjectName(_fromUtf8("spbxRxWftMax"))
        self.horizontalLayout_18.addWidget(self.spbxRxWftMax)
        self.verticalLayout.addLayout(self.horizontalLayout_18)
        self.verticalLayout_4.addLayout(self.verticalLayout)
        self.verticalLayout_2 = QtGui.QVBoxLayout()
        self.verticalLayout_2.setObjectName(_fromUtf8("verticalLayout_2"))
        self.horizontalLayout_19 = QtGui.QHBoxLayout()
        self.horizontalLayout_19.setObjectName(_fromUtf8("horizontalLayout_19"))
        self.label_33 = QtGui.QLabel(self.layoutWidget1)
        self.label_33.setObjectName(_fromUtf8("label_33"))
        self.horizontalLayout_19.addWidget(self.label_33)
        self.cmbxRxAddressingFormat = QtGui.QComboBox(self.layoutWidget1)
        self.cmbxRxAddressingFormat.setMinimumSize(QtCore.QSize(250, 0))
        self.cmbxRxAddressingFormat.setObjectName(_fromUtf8("cmbxRxAddressingFormat"))
        self.cmbxRxAddressingFormat.addItem(_fromUtf8(""))
        self.cmbxRxAddressingFormat.addItem(_fromUtf8(""))
        self.horizontalLayout_19.addWidget(self.cmbxRxAddressingFormat)
        self.verticalLayout_2.addLayout(self.horizontalLayout_19)
        self.horizontalLayout_20 = QtGui.QHBoxLayout()
        self.horizontalLayout_20.setObjectName(_fromUtf8("horizontalLayout_20"))
        self.label_7 = QtGui.QLabel(self.layoutWidget1)
        self.label_7.setObjectName(_fromUtf8("label_7"))
        self.horizontalLayout_20.addWidget(self.label_7)
        self.spbxRxNTa = QtGui.QSpinBox(self.layoutWidget1)
        self.spbxRxNTa.setMinimumSize(QtCore.QSize(200, 0))
        self.spbxRxNTa.setObjectName(_fromUtf8("spbxRxNTa"))
        self.horizontalLayout_20.addWidget(self.spbxRxNTa)
        self.verticalLayout_2.addLayout(self.horizontalLayout_20)
        self.horizontalLayout_21 = QtGui.QHBoxLayout()
        self.horizontalLayout_21.setObjectName(_fromUtf8("horizontalLayout_21"))
        self.label_8 = QtGui.QLabel(self.layoutWidget1)
        self.label_8.setObjectName(_fromUtf8("label_8"))
        self.horizontalLayout_21.addWidget(self.label_8)
        self.spbxRxNSa = QtGui.QSpinBox(self.layoutWidget1)
        self.spbxRxNSa.setMinimumSize(QtCore.QSize(200, 0))
        self.spbxRxNSa.setObjectName(_fromUtf8("spbxRxNSa"))
        self.horizontalLayout_21.addWidget(self.spbxRxNSa)
        self.verticalLayout_2.addLayout(self.horizontalLayout_21)
        self.verticalLayout_4.addLayout(self.verticalLayout_2)
        self.verticalLayout_3 = QtGui.QVBoxLayout()
        self.verticalLayout_3.setObjectName(_fromUtf8("verticalLayout_3"))
        self.horizontalLayout_24 = QtGui.QHBoxLayout()
        self.horizontalLayout_24.setObjectName(_fromUtf8("horizontalLayout_24"))
        self.label_12 = QtGui.QLabel(self.layoutWidget1)
        self.label_12.setObjectName(_fromUtf8("label_12"))
        self.horizontalLayout_24.addWidget(self.label_12)
        self.spbxRxNar = QtGui.QSpinBox(self.layoutWidget1)
        self.spbxRxNar.setMinimumSize(QtCore.QSize(200, 0))
        self.spbxRxNar.setObjectName(_fromUtf8("spbxRxNar"))
        self.horizontalLayout_24.addWidget(self.spbxRxNar)
        self.label_37 = QtGui.QLabel(self.layoutWidget1)
        self.label_37.setObjectName(_fromUtf8("label_37"))
        self.horizontalLayout_24.addWidget(self.label_37)
        self.verticalLayout_3.addLayout(self.horizontalLayout_24)
        self.horizontalLayout_25 = QtGui.QHBoxLayout()
        self.horizontalLayout_25.setObjectName(_fromUtf8("horizontalLayout_25"))
        self.label_13 = QtGui.QLabel(self.layoutWidget1)
        self.label_13.setObjectName(_fromUtf8("label_13"))
        self.horizontalLayout_25.addWidget(self.label_13)
        self.spbxRxNbr = QtGui.QSpinBox(self.layoutWidget1)
        self.spbxRxNbr.setMinimumSize(QtCore.QSize(150, 0))
        self.spbxRxNbr.setObjectName(_fromUtf8("spbxRxNbr"))
        self.horizontalLayout_25.addWidget(self.spbxRxNbr)
        self.label_45 = QtGui.QLabel(self.layoutWidget1)
        self.label_45.setObjectName(_fromUtf8("label_45"))
        self.horizontalLayout_25.addWidget(self.label_45)
        self.verticalLayout_3.addLayout(self.horizontalLayout_25)
        self.horizontalLayout_26 = QtGui.QHBoxLayout()
        self.horizontalLayout_26.setObjectName(_fromUtf8("horizontalLayout_26"))
        self.label_14 = QtGui.QLabel(self.layoutWidget1)
        self.label_14.setObjectName(_fromUtf8("label_14"))
        self.horizontalLayout_26.addWidget(self.label_14)
        self.spbxRxNcr = QtGui.QSpinBox(self.layoutWidget1)
        self.spbxRxNcr.setMinimumSize(QtCore.QSize(150, 0))
        self.spbxRxNcr.setObjectName(_fromUtf8("spbxRxNcr"))
        self.horizontalLayout_26.addWidget(self.spbxRxNcr)
        self.label_46 = QtGui.QLabel(self.layoutWidget1)
        self.label_46.setObjectName(_fromUtf8("label_46"))
        self.horizontalLayout_26.addWidget(self.label_46)
        self.verticalLayout_3.addLayout(self.horizontalLayout_26)
        self.verticalLayout_4.addLayout(self.verticalLayout_3)
        self.tabCfg.addTab(self.tab_3, _fromUtf8(""))
        self.tab_5 = QtGui.QWidget()
        self.tab_5.setObjectName(_fromUtf8("tab_5"))
        self.layoutWidget2 = QtGui.QWidget(self.tab_5)
        self.layoutWidget2.setGeometry(QtCore.QRect(20, 300, 382, 80))
        self.layoutWidget2.setObjectName(_fromUtf8("layoutWidget2"))
        self.verticalLayout_8 = QtGui.QVBoxLayout(self.layoutWidget2)
        self.verticalLayout_8.setMargin(0)
        self.verticalLayout_8.setObjectName(_fromUtf8("verticalLayout_8"))
        self.horizontalLayout_34 = QtGui.QHBoxLayout()
        self.horizontalLayout_34.setObjectName(_fromUtf8("horizontalLayout_34"))
        self.label_19 = QtGui.QLabel(self.layoutWidget2)
        self.label_19.setObjectName(_fromUtf8("label_19"))
        self.horizontalLayout_34.addWidget(self.label_19)
        self.spbxTxNas = QtGui.QSpinBox(self.layoutWidget2)
        self.spbxTxNas.setMinimumSize(QtCore.QSize(200, 0))
        self.spbxTxNas.setObjectName(_fromUtf8("spbxTxNas"))
        self.horizontalLayout_34.addWidget(self.spbxTxNas)
        self.label_42 = QtGui.QLabel(self.layoutWidget2)
        self.label_42.setObjectName(_fromUtf8("label_42"))
        self.horizontalLayout_34.addWidget(self.label_42)
        self.verticalLayout_8.addLayout(self.horizontalLayout_34)
        self.horizontalLayout_35 = QtGui.QHBoxLayout()
        self.horizontalLayout_35.setObjectName(_fromUtf8("horizontalLayout_35"))
        self.label_20 = QtGui.QLabel(self.layoutWidget2)
        self.label_20.setObjectName(_fromUtf8("label_20"))
        self.horizontalLayout_35.addWidget(self.label_20)
        self.spbxTxNbs = QtGui.QSpinBox(self.layoutWidget2)
        self.spbxTxNbs.setMinimumSize(QtCore.QSize(150, 0))
        self.spbxTxNbs.setObjectName(_fromUtf8("spbxTxNbs"))
        self.horizontalLayout_35.addWidget(self.spbxTxNbs)
        self.label_48 = QtGui.QLabel(self.layoutWidget2)
        self.label_48.setObjectName(_fromUtf8("label_48"))
        self.horizontalLayout_35.addWidget(self.label_48)
        self.verticalLayout_8.addLayout(self.horizontalLayout_35)
        self.horizontalLayout_36 = QtGui.QHBoxLayout()
        self.horizontalLayout_36.setObjectName(_fromUtf8("horizontalLayout_36"))
        self.label_21 = QtGui.QLabel(self.layoutWidget2)
        self.label_21.setObjectName(_fromUtf8("label_21"))
        self.horizontalLayout_36.addWidget(self.label_21)
        self.spbxTxNcs = QtGui.QSpinBox(self.layoutWidget2)
        self.spbxTxNcs.setMinimumSize(QtCore.QSize(150, 0))
        self.spbxTxNcs.setObjectName(_fromUtf8("spbxTxNcs"))
        self.horizontalLayout_36.addWidget(self.spbxTxNcs)
        self.label_49 = QtGui.QLabel(self.layoutWidget2)
        self.label_49.setObjectName(_fromUtf8("label_49"))
        self.horizontalLayout_36.addWidget(self.label_49)
        self.verticalLayout_8.addLayout(self.horizontalLayout_36)
        self.layoutWidget3 = QtGui.QWidget(self.tab_5)
        self.layoutWidget3.setGeometry(QtCore.QRect(20, 200, 368, 80))
        self.layoutWidget3.setObjectName(_fromUtf8("layoutWidget3"))
        self.verticalLayout_7 = QtGui.QVBoxLayout(self.layoutWidget3)
        self.verticalLayout_7.setMargin(0)
        self.verticalLayout_7.setObjectName(_fromUtf8("verticalLayout_7"))
        self.horizontalLayout_31 = QtGui.QHBoxLayout()
        self.horizontalLayout_31.setObjectName(_fromUtf8("horizontalLayout_31"))
        self.label_39 = QtGui.QLabel(self.layoutWidget3)
        self.label_39.setObjectName(_fromUtf8("label_39"))
        self.horizontalLayout_31.addWidget(self.label_39)
        self.cmbxTxAddressingFormat = QtGui.QComboBox(self.layoutWidget3)
        self.cmbxTxAddressingFormat.setMinimumSize(QtCore.QSize(250, 0))
        self.cmbxTxAddressingFormat.setObjectName(_fromUtf8("cmbxTxAddressingFormat"))
        self.cmbxTxAddressingFormat.addItem(_fromUtf8(""))
        self.cmbxTxAddressingFormat.addItem(_fromUtf8(""))
        self.horizontalLayout_31.addWidget(self.cmbxTxAddressingFormat)
        self.verticalLayout_7.addLayout(self.horizontalLayout_31)
        self.horizontalLayout_32 = QtGui.QHBoxLayout()
        self.horizontalLayout_32.setObjectName(_fromUtf8("horizontalLayout_32"))
        self.label_17 = QtGui.QLabel(self.layoutWidget3)
        self.label_17.setObjectName(_fromUtf8("label_17"))
        self.horizontalLayout_32.addWidget(self.label_17)
        self.spbxTxNTa = QtGui.QSpinBox(self.layoutWidget3)
        self.spbxTxNTa.setMinimumSize(QtCore.QSize(200, 0))
        self.spbxTxNTa.setObjectName(_fromUtf8("spbxTxNTa"))
        self.horizontalLayout_32.addWidget(self.spbxTxNTa)
        self.verticalLayout_7.addLayout(self.horizontalLayout_32)
        self.horizontalLayout_33 = QtGui.QHBoxLayout()
        self.horizontalLayout_33.setObjectName(_fromUtf8("horizontalLayout_33"))
        self.label_18 = QtGui.QLabel(self.layoutWidget3)
        self.label_18.setObjectName(_fromUtf8("label_18"))
        self.horizontalLayout_33.addWidget(self.label_18)
        self.spbxTxNSa = QtGui.QSpinBox(self.layoutWidget3)
        self.spbxTxNSa.setMinimumSize(QtCore.QSize(200, 0))
        self.spbxTxNSa.setObjectName(_fromUtf8("spbxTxNSa"))
        self.horizontalLayout_33.addWidget(self.spbxTxNSa)
        self.verticalLayout_7.addLayout(self.horizontalLayout_33)
        self.layoutWidget4 = QtGui.QWidget(self.tab_5)
        self.layoutWidget4.setGeometry(QtCore.QRect(20, 20, 424, 164))
        self.layoutWidget4.setObjectName(_fromUtf8("layoutWidget4"))
        self.verticalLayout_6 = QtGui.QVBoxLayout(self.layoutWidget4)
        self.verticalLayout_6.setMargin(0)
        self.verticalLayout_6.setObjectName(_fromUtf8("verticalLayout_6"))
        self.horizontalLayout_27 = QtGui.QHBoxLayout()
        self.horizontalLayout_27.setObjectName(_fromUtf8("horizontalLayout_27"))
        self.label_47 = QtGui.QLabel(self.layoutWidget4)
        self.label_47.setObjectName(_fromUtf8("label_47"))
        self.horizontalLayout_27.addWidget(self.label_47)
        self.leTxPduName = QtGui.QLineEdit(self.layoutWidget4)
        self.leTxPduName.setText(_fromUtf8(""))
        self.leTxPduName.setObjectName(_fromUtf8("leTxPduName"))
        self.horizontalLayout_27.addWidget(self.leTxPduName)
        self.verticalLayout_6.addLayout(self.horizontalLayout_27)
        self.horizontalLayout_8 = QtGui.QHBoxLayout()
        self.horizontalLayout_8.setObjectName(_fromUtf8("horizontalLayout_8"))
        self.label_41 = QtGui.QLabel(self.layoutWidget4)
        self.label_41.setObjectName(_fromUtf8("label_41"))
        self.horizontalLayout_8.addWidget(self.label_41)
        self.cmbxTxPduId = QtGui.QComboBox(self.layoutWidget4)
        self.cmbxTxPduId.setMinimumSize(QtCore.QSize(300, 0))
        self.cmbxTxPduId.setObjectName(_fromUtf8("cmbxTxPduId"))
        self.horizontalLayout_8.addWidget(self.cmbxTxPduId)
        self.verticalLayout_6.addLayout(self.horizontalLayout_8)
        self.horizontalLayout_9 = QtGui.QHBoxLayout()
        self.horizontalLayout_9.setObjectName(_fromUtf8("horizontalLayout_9"))
        self.label_31 = QtGui.QLabel(self.layoutWidget4)
        self.label_31.setObjectName(_fromUtf8("label_31"))
        self.horizontalLayout_9.addWidget(self.label_31)
        self.cmbxRxFcPduId = QtGui.QComboBox(self.layoutWidget4)
        self.cmbxRxFcPduId.setMinimumSize(QtCore.QSize(300, 0))
        self.cmbxRxFcPduId.setObjectName(_fromUtf8("cmbxRxFcPduId"))
        self.horizontalLayout_9.addWidget(self.cmbxRxFcPduId)
        self.verticalLayout_6.addLayout(self.horizontalLayout_9)
        self.horizontalLayout_10 = QtGui.QHBoxLayout()
        self.horizontalLayout_10.setObjectName(_fromUtf8("horizontalLayout_10"))
        self.label_3 = QtGui.QLabel(self.layoutWidget4)
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.horizontalLayout_10.addWidget(self.label_3)
        self.spbxTxPduDlc = QtGui.QSpinBox(self.layoutWidget4)
        self.spbxTxPduDlc.setMinimumSize(QtCore.QSize(200, 0))
        self.spbxTxPduDlc.setObjectName(_fromUtf8("spbxTxPduDlc"))
        self.horizontalLayout_10.addWidget(self.spbxTxPduDlc)
        self.verticalLayout_6.addLayout(self.horizontalLayout_10)
        self.horizontalLayout_11 = QtGui.QHBoxLayout()
        self.horizontalLayout_11.setObjectName(_fromUtf8("horizontalLayout_11"))
        self.label_34 = QtGui.QLabel(self.layoutWidget4)
        self.label_34.setObjectName(_fromUtf8("label_34"))
        self.horizontalLayout_11.addWidget(self.label_34)
        self.cmbxTxPduPadding = QtGui.QComboBox(self.layoutWidget4)
        self.cmbxTxPduPadding.setMinimumSize(QtCore.QSize(300, 0))
        self.cmbxTxPduPadding.setObjectName(_fromUtf8("cmbxTxPduPadding"))
        self.cmbxTxPduPadding.addItem(_fromUtf8(""))
        self.cmbxTxPduPadding.addItem(_fromUtf8(""))
        self.horizontalLayout_11.addWidget(self.cmbxTxPduPadding)
        self.verticalLayout_6.addLayout(self.horizontalLayout_11)
        self.horizontalLayout_28 = QtGui.QHBoxLayout()
        self.horizontalLayout_28.setObjectName(_fromUtf8("horizontalLayout_28"))
        self.label_38 = QtGui.QLabel(self.layoutWidget4)
        self.label_38.setObjectName(_fromUtf8("label_38"))
        self.horizontalLayout_28.addWidget(self.label_38)
        self.cmbxTxTaType = QtGui.QComboBox(self.layoutWidget4)
        self.cmbxTxTaType.setMinimumSize(QtCore.QSize(250, 0))
        self.cmbxTxTaType.setObjectName(_fromUtf8("cmbxTxTaType"))
        self.cmbxTxTaType.addItem(_fromUtf8(""))
        self.cmbxTxTaType.addItem(_fromUtf8(""))
        self.horizontalLayout_28.addWidget(self.cmbxTxTaType)
        self.verticalLayout_6.addLayout(self.horizontalLayout_28)
        self.tabCfg.addTab(self.tab_5, _fromUtf8(""))
        self.btnAdd = QtGui.QPushButton(self.groupBox_2)
        self.btnAdd.setGeometry(QtCore.QRect(291, 55, 111, 23))
        self.btnAdd.setObjectName(_fromUtf8("btnAdd"))

        self.retranslateUi(cd_cantp)
        self.tabCfg.setCurrentIndex(1)
        QtCore.QMetaObject.connectSlotsByName(cd_cantp)

    def retranslateUi(self, cd_cantp):
        cd_cantp.setWindowTitle(QtGui.QApplication.translate("cd_cantp", "Can Transport Protocal", None, QtGui.QApplication.UnicodeUTF8))
        self.groupBox.setTitle(QtGui.QApplication.translate("cd_cantp", "CanTp General", None, QtGui.QApplication.UnicodeUTF8))
        self.label_36.setText(QtGui.QApplication.translate("cd_cantp", "ms", None, QtGui.QApplication.UnicodeUTF8))
        self.label_35.setText(QtGui.QApplication.translate("cd_cantp", "Main Function Period:", None, QtGui.QApplication.UnicodeUTF8))
        self.cbxDevErr.setText(QtGui.QApplication.translate("cd_cantp", "DevErrorDetection", None, QtGui.QApplication.UnicodeUTF8))
        self.groupBox_2.setTitle(QtGui.QApplication.translate("cd_cantp", "CanTp Entities", None, QtGui.QApplication.UnicodeUTF8))
        self.trCanTpCfg.headerItem().setText(0, QtGui.QApplication.translate("cd_cantp", "CanTp", None, QtGui.QApplication.UnicodeUTF8))
        __sortingEnabled = self.trCanTpCfg.isSortingEnabled()
        self.trCanTpCfg.setSortingEnabled(False)
        self.trCanTpCfg.topLevelItem(0).setText(0, QtGui.QApplication.translate("cd_cantp", "RX SDU", None, QtGui.QApplication.UnicodeUTF8))
        self.trCanTpCfg.topLevelItem(1).setText(0, QtGui.QApplication.translate("cd_cantp", "TX SDU", None, QtGui.QApplication.UnicodeUTF8))
        self.trCanTpCfg.setSortingEnabled(__sortingEnabled)
        self.label_44.setText(QtGui.QApplication.translate("cd_cantp", "Name:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_40.setText(QtGui.QApplication.translate("cd_cantp", "Rx Pdu:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_29.setText(QtGui.QApplication.translate("cd_cantp", "Tx Fc Pdu:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_2.setText(QtGui.QApplication.translate("cd_cantp", "Data Length Code:", None, QtGui.QApplication.UnicodeUTF8))
        self.spbxRxPduDlc.setToolTip(QtGui.QApplication.translate("cd_cantp", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Consolas\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">this means nothing,so you have no need to configure it.Just make compatible with arccore.</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.label_30.setText(QtGui.QApplication.translate("cd_cantp", "Padding Activation:", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxRxPduPadding.setToolTip(QtGui.QApplication.translate("cd_cantp", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Consolas\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This type is really decided by Can Hth,Configue it has no affect.</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxRxPduPadding.setItemText(0, QtGui.QApplication.translate("cd_cantp", "CANTP_OFF", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxRxPduPadding.setItemText(1, QtGui.QApplication.translate("cd_cantp", "CANTP_ON", None, QtGui.QApplication.UnicodeUTF8))
        self.label_32.setText(QtGui.QApplication.translate("cd_cantp", "Communication Type:", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxRxTaType.setToolTip(QtGui.QApplication.translate("cd_cantp", "Only Physical is allowed Now!", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxRxTaType.setItemText(0, QtGui.QApplication.translate("cd_cantp", "CANTP_PHYSICAL", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxRxTaType.setItemText(1, QtGui.QApplication.translate("cd_cantp", "CANTP_FUNCTIONAL", None, QtGui.QApplication.UnicodeUTF8))
        self.label.setText(QtGui.QApplication.translate("cd_cantp", "Max Receive Block Size:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_5.setText(QtGui.QApplication.translate("cd_cantp", "Min Transmission Delay(STmin):", None, QtGui.QApplication.UnicodeUTF8))
        self.label_6.setText(QtGui.QApplication.translate("cd_cantp", "Max Busy Transmission:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_33.setText(QtGui.QApplication.translate("cd_cantp", "Addressing Format:", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxRxAddressingFormat.setItemText(0, QtGui.QApplication.translate("cd_cantp", "CANTP_STANDARD", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxRxAddressingFormat.setItemText(1, QtGui.QApplication.translate("cd_cantp", "CANTP_EXTENDED", None, QtGui.QApplication.UnicodeUTF8))
        self.label_7.setText(QtGui.QApplication.translate("cd_cantp", "Target Address:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_8.setText(QtGui.QApplication.translate("cd_cantp", "Source Address:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_12.setText(QtGui.QApplication.translate("cd_cantp", "Transmission Time(Nar):", None, QtGui.QApplication.UnicodeUTF8))
        self.label_37.setText(QtGui.QApplication.translate("cd_cantp", "ms", None, QtGui.QApplication.UnicodeUTF8))
        self.label_13.setText(QtGui.QApplication.translate("cd_cantp", "Transmission Time uintill FC(Nbr):", None, QtGui.QApplication.UnicodeUTF8))
        self.label_45.setText(QtGui.QApplication.translate("cd_cantp", "ms", None, QtGui.QApplication.UnicodeUTF8))
        self.label_14.setText(QtGui.QApplication.translate("cd_cantp", "Transmit Request Delay(Ncr):", None, QtGui.QApplication.UnicodeUTF8))
        self.label_46.setText(QtGui.QApplication.translate("cd_cantp", "ms", None, QtGui.QApplication.UnicodeUTF8))
        self.tabCfg.setTabText(self.tabCfg.indexOf(self.tab_3), QtGui.QApplication.translate("cd_cantp", "Rx Pdu", None, QtGui.QApplication.UnicodeUTF8))
        self.label_19.setText(QtGui.QApplication.translate("cd_cantp", "Transmission Time(Nas):", None, QtGui.QApplication.UnicodeUTF8))
        self.label_42.setText(QtGui.QApplication.translate("cd_cantp", "ms", None, QtGui.QApplication.UnicodeUTF8))
        self.label_20.setText(QtGui.QApplication.translate("cd_cantp", "Transmission Time uintill FC(Nbs):", None, QtGui.QApplication.UnicodeUTF8))
        self.label_48.setText(QtGui.QApplication.translate("cd_cantp", "ms", None, QtGui.QApplication.UnicodeUTF8))
        self.label_21.setText(QtGui.QApplication.translate("cd_cantp", "Transmit Request Delay(Ncs):", None, QtGui.QApplication.UnicodeUTF8))
        self.label_49.setText(QtGui.QApplication.translate("cd_cantp", "ms", None, QtGui.QApplication.UnicodeUTF8))
        self.label_39.setText(QtGui.QApplication.translate("cd_cantp", "Addressing Format:", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxTxAddressingFormat.setItemText(0, QtGui.QApplication.translate("cd_cantp", "CANTP_STANDARD", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxTxAddressingFormat.setItemText(1, QtGui.QApplication.translate("cd_cantp", "CANTP_EXTENDED", None, QtGui.QApplication.UnicodeUTF8))
        self.label_17.setText(QtGui.QApplication.translate("cd_cantp", "Target Address:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_18.setText(QtGui.QApplication.translate("cd_cantp", "Source Address:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_47.setText(QtGui.QApplication.translate("cd_cantp", "Name:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_41.setText(QtGui.QApplication.translate("cd_cantp", "Tx Pdu:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_31.setText(QtGui.QApplication.translate("cd_cantp", "Rx Fc Pdu:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_3.setText(QtGui.QApplication.translate("cd_cantp", "Data Length Code:", None, QtGui.QApplication.UnicodeUTF8))
        self.spbxTxPduDlc.setToolTip(QtGui.QApplication.translate("cd_cantp", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Consolas\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">this means nothing,so you have no need to configure it.Just make compatible with arccore.</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.label_34.setText(QtGui.QApplication.translate("cd_cantp", "Padding Activation:", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxTxPduPadding.setToolTip(QtGui.QApplication.translate("cd_cantp", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'Consolas\'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This type is really decided by Can Hth,Configue it has no affect.</p></body></html>", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxTxPduPadding.setItemText(0, QtGui.QApplication.translate("cd_cantp", "CANTP_OFF", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxTxPduPadding.setItemText(1, QtGui.QApplication.translate("cd_cantp", "CANTP_ON", None, QtGui.QApplication.UnicodeUTF8))
        self.label_38.setText(QtGui.QApplication.translate("cd_cantp", "Communication Type:", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxTxTaType.setToolTip(QtGui.QApplication.translate("cd_cantp", "Only Physical is allowed Now!", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxTxTaType.setItemText(0, QtGui.QApplication.translate("cd_cantp", "CANTP_PHYSICAL", None, QtGui.QApplication.UnicodeUTF8))
        self.cmbxTxTaType.setItemText(1, QtGui.QApplication.translate("cd_cantp", "CANTP_FUNCTIONAL", None, QtGui.QApplication.UnicodeUTF8))
        self.tabCfg.setTabText(self.tabCfg.indexOf(self.tab_5), QtGui.QApplication.translate("cd_cantp", "Tx Pdu", None, QtGui.QApplication.UnicodeUTF8))
        self.btnAdd.setText(QtGui.QApplication.translate("cd_cantp", "Add Rx NSdu", None, QtGui.QApplication.UnicodeUTF8))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    cd_cantp = QtGui.QDialog()
    ui = Ui_cd_cantp()
    ui.setupUi(cd_cantp)
    cd_cantp.show()
    sys.exit(app.exec_())

