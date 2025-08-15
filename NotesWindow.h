#pragma once

#include <QWidget>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMouseEvent> // Needed for mouse events
#include <QPoint>      // Needed for QPoint

class NotesWindow : public QWidget {
    Q_OBJECT // Required for Qt signal/slot mechanism

public:
    NotesWindow(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void changeOpacity(int value);
    void minimizeWindow();
    void closeWindow();

private:
    QPoint dragPos;
    QPlainTextEdit *editor;
    QSlider *opacitySlider;
    QPushButton *minBtn;
    QPushButton *closeBtn;
};