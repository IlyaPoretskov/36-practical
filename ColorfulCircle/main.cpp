#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>
#include <QPainter>
#include <QPixmap>
#include <QLabel>

class ColorfulCircle : public QWidget {
    Q_OBJECT

public:
    ColorfulCircle(QWidget* parent = nullptr) : QWidget(parent) {
        mGreenCircle = QPixmap(":/resources/green_circle.png");
        mYellowCircle = QPixmap(":/resources/yellow_circle.png");
        mRedCircle = QPixmap(":/resources/red_circle.png");
        mCurrentCircle = mGreenCircle;
        setFixedSize(200, 200);
    }

    QSize minimumSizeHint() const override {
        return QSize(100, 100);
    }

public slots:
    void setGreen() {
        mCurrentCircle = mGreenCircle;
        update();
    }

    void setYellow() {
        mCurrentCircle = mYellowCircle;
        update();
    }

    void setRed() {
        mCurrentCircle = mRedCircle;
        update();
    }

protected:
    void paintEvent(QPaintEvent* event) override {
        QPainter painter(this);
        int x = (width() - mCurrentCircle.width()) / 2;
        int y = (height() - mCurrentCircle.height()) / 2;
        painter.drawPixmap(x, y, mCurrentCircle);
    }

private:
    QPixmap mGreenCircle;
    QPixmap mYellowCircle;
    QPixmap mRedCircle;
    QPixmap mCurrentCircle;
};

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    QVBoxLayout* layout = new QVBoxLayout(&window);

    ColorfulCircle* circle = new ColorfulCircle();
    QSlider* slider = new QSlider(Qt::Horizontal);

    layout->addWidget(circle);
    layout->addWidget(slider);

    slider->setRange(0, 100);

    QObject::connect(slider, &QSlider::valueChanged, [circle](int newValue) {
        if (newValue <= 33) {
            circle->setGreen();
        }
        else if (newValue <= 66) {
            circle->setYellow();
        }
        else {
            circle->setRed();
        }
        });

    window.setFixedSize(200, 250);
    window.show();

    return app.exec();
}

#include "main.moc"
