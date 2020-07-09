#include "principal.h"
#include "ui_principal.h"
#include<QFileDialog>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    connect(ui->OkpushButton,SIGNAL(released()),this,SLOT(Calcular()));
    connect(ui->actionGuardar,SIGNAL(triggered(bool)),
           this,SLOT(guardar()));


    QStringList cabecera= {"Marca","Modelo","Num Serie","Tipo","Contador","Precio"};
    ui->outResumen->setColumnCount(6);
    ui->outResumen->setHorizontalHeaderLabels(cabecera);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::precioTotal(float precio)
{
    m_subtotal+=precio;

    precio+=precio;
    qDebug()<<precio;
  QString precioS=QString::number(m_subtotal);
  ui->outTotal->setText(precioS);

}



void Principal::Calcular()
{
    QString tipo;
    //Obtener datos
    QString  marca = ui->inMarca->text();

    qDebug()<< marca;
    QString modelo =ui->inModelo->text();
    QString numeroSerie = ui->inNumSerie->text();
    if(ui->inColor->isChecked()){
        tipo="Color";
    }else if(ui->inBlancoNegro->isChecked()){
        tipo="Blanco & Negro";
    }
    qDebug()<<tipo;
    float contadorImpresiones =ui->inContador->value();
    qDebug()<<contadorImpresiones;
    QString precio= ui->inPrecio->text();
    float pre=precio.toInt();

    int posicion=ui->outResumen->rowCount();
    ui->outResumen->insertRow(posicion);
    ui->outResumen->setItem(posicion,0,new QTableWidgetItem(marca));
    ui->outResumen->setItem(posicion,1,new QTableWidgetItem(modelo));
    ui->outResumen->setItem(posicion,2,new QTableWidgetItem(numeroSerie));
    ui->outResumen->setItem(posicion,3,new QTableWidgetItem(tipo));
    ui->outResumen->setItem(posicion,4,new QTableWidgetItem(QString::number(contadorImpresiones)));
    ui->outResumen->setItem(posicion,5,new QTableWidgetItem(precio));

    precioTotal(pre);


}

void Principal::guardar()
{

    QString filename=QFileDialog::getSaveFileName(this,
    "Guardar datos",QDir::home().absolutePath(),"Archivo de texto (*.csv)");

    QFile data (filename);


    if(data.open(QFile::WriteOnly|QFile::Truncate)){
        QTextStream salida(&data);
      //  salida<<ui->outResumen->item(1,1);
        ui->statusbar->showMessage("Datos almacenados en "+filename,5000);

    }
    data.close();
}

