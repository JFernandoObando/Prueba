#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include<QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
    float m_subtotal;
     void precioTotal(float);

public slots:
    void Calcular();
  //  void guardar();

private:
    Ui::Principal *ui;
};
#endif // PRINCIPAL_H
