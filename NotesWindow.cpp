#include "NotesWindow.h"
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>

NotesWindow::NotesWindow(QWidget *parent) : QWidget(parent) {
    setWindowTitle("FloatNoteQt – Sticky Notes");
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);

    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(12,12,12,12);
    mainLayout->setSpacing(8);

    // Topbar
    auto *topbar = new QWidget(this);
    auto *topbarLayout = new QHBoxLayout(topbar);
    topbarLayout->setContentsMargins(0,0,0,0);

    closeBtn = new QPushButton("✕", this);
    closeBtn->setFixedSize(32,32);
    closeBtn->setStyleSheet("background:#ff69b4;color:white;border-radius:16px;font-size:18px;");
    connect(closeBtn, &QPushButton::clicked, this, &NotesWindow::closeWindow);

    minBtn = new QPushButton("–", this);
    minBtn->setFixedSize(32,32);
    minBtn->setStyleSheet("background:#ffc0dd;color:#ff69b4;border-radius:16px;font-size:18px;");
    connect(minBtn, &QPushButton::clicked, this, &NotesWindow::minimizeWindow);

    auto *title = new QLabel("FloatNoteQt", this);
    title->setStyleSheet("color:#ff69b4;font-weight:bold;font-size:18px;");

    topbarLayout->addWidget(closeBtn);
    topbarLayout->addWidget(minBtn);
    topbarLayout->addWidget(title);
    topbarLayout->addStretch();

    // Editor
    editor = new QPlainTextEdit(this);
    editor->setPlaceholderText("Tulis catatan di sini...");
    editor->setStyleSheet(
        "background:rgba(255,255,255,0.7);color:#222;border-radius:12px;"
        "font-size:15px;padding:12px;font-family:'Consolas','Menlo','monospace';"
    );
    editor->setMinimumHeight(260);

    auto *shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(36);
    shadow->setOffset(0,18);
    shadow->setColor(QColor(255,110,180,80));
    editor->setGraphicsEffect(shadow);

    // Opacity slider
    auto *opacityLabel = new QLabel("Opacity", this);
    opacitySlider = new QSlider(Qt::Horizontal, this);
    opacitySlider->setRange(50,255);
    opacitySlider->setValue(180);
    connect(opacitySlider, &QSlider::valueChanged, this, &NotesWindow::changeOpacity);

    mainLayout->addWidget(topbar);
    mainLayout->addWidget(editor);
    mainLayout->addWidget(opacityLabel);
    mainLayout->addWidget(opacitySlider);

    resize(400, 350);
    changeOpacity(opacitySlider->value());
}

void NotesWindow::mousePressEvent(QMouseEvent *event) 
{
    if (event->button() == Qt::LeftButton) {
        dragPos = event->globalPosition().toPoint() - frameGeometry().topLeft();
        event->accept();
    }
}

void NotesWindow::mouseMoveEvent(QMouseEvent *event) 
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPosition().toPoint() - dragPos);
        event->accept();
    }
}


void NotesWindow::changeOpacity(int value) {
    setWindowOpacity(value / 255.0);
}

void NotesWindow::minimizeWindow() {
    setWindowState(Qt::WindowMinimized);
}

void NotesWindow::closeWindow() {
    close();
}