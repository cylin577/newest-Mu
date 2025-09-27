#include "titlebar.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QApplication>
#include <QMainWindow>

TitleBar::TitleBar(QWidget* parent)
    : QWidget(parent), m_maximized(false){
    m_titleLabel = new QLabel("Mu");
    m_minimizeButton = new QPushButton(QString::fromUtf8("—"));
    m_maximizeButton = new QPushButton(QString::fromUtf8("☐"));
    m_closeButton = new QPushButton(QString::fromUtf8("✕"));

    m_minimizeButton->setFixedSize(30, 30);
    m_maximizeButton->setFixedSize(30, 30);
    m_closeButton->setFixedSize(30, 30);

    QString buttonStyle = "QPushButton { background-color: transparent; border: none; border-radius: 15px; }";
    m_minimizeButton->setStyleSheet(buttonStyle);
    m_maximizeButton->setStyleSheet(buttonStyle);
    m_closeButton->setStyleSheet(buttonStyle);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(m_titleLabel);
    layout->addStretch();
    layout->addWidget(m_minimizeButton);
    layout->addWidget(m_maximizeButton);
    layout->addWidget(m_closeButton);

    connect(m_minimizeButton, &QPushButton::clicked, this, &TitleBar::onMinimizeClicked);
    connect(m_maximizeButton, &QPushButton::clicked, this, &TitleBar::onMaximizeClicked);
    connect(m_closeButton, &QPushButton::clicked, this, &TitleBar::onCloseClicked);
}

TitleBar::~TitleBar(){
}

void TitleBar::mousePressEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPosition().toPoint() - window()->frameGeometry().topLeft();
        event->accept();
    }
}

void TitleBar::mouseMoveEvent(QMouseEvent* event){
    if (event->buttons() & Qt::LeftButton) {
        window()->move(event->globalPosition().toPoint() - m_dragPosition);
        event->accept();
    }
}

void TitleBar::onMinimizeClicked(){
    window()->showMinimized();
}

void TitleBar::onMaximizeClicked(){
    if (m_maximized) {
        window()->showNormal();
    } else {
        window()->showMaximized();
    }
    m_maximized = !m_maximized;
}

void TitleBar::onCloseClicked(){
    window()->close();
}
