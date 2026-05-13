#include "hilo.h"
#include "util.h"
hilo::hilo() {
}
void hilo::run(){
    while(true){
        sleep(30);
        QJsonArray jsonArray;
        QJsonObject objCarga;
        QJsonObject objTipo;
        QDateTime fechaActual = QDateTime::currentDateTime();
        // Formatear a: yyyy-MM-dd HH:mm:ss
        QString formato = fechaActual.toString("yyyy-MM-dd HH:mm:ss");
        objCarga.insert("id",QJsonValue::Null);
        objCarga.insert("fecha",formato);
        objCarga.insert("valor",3.14);
        objTipo.insert("id",QJsonValue::Null);
        objTipo.insert("tipo","CARGA");
        objCarga.insert("idBateria",1);
        objCarga.insert("tipo",objTipo);
        jsonArray.append(objCarga);
        QJsonObject objCorriente;
        objCarga.insert("id",QJsonValue::Null);
        objCorriente.insert("fecha",formato);
        objCorriente.insert("valor",1.14);
        objTipo.insert("id",QJsonValue::Null);
        objTipo.insert("tipo","CORRIENTE");
        objCorriente.insert("tipo",objTipo);
        objCorriente.insert("idBateria",1);
        jsonArray.append(objCorriente);
        QJsonObject objTension;
        objCarga.insert("id",QJsonValue::Null);
        objTension.insert("fecha",formato);
        objTension.insert("valor",2.14);
        objTipo.insert("id",QJsonValue::Null);
        objTipo.insert("tipo","TENSION");
        objTension.insert("tipo",objTipo);
        objTension.insert("idBateria",1);
        jsonArray.append(objTension);
        QJsonObject objTemperatura;
        objCarga.insert("id",QJsonValue::Null);
        objTemperatura.insert("fecha",formato);
        objTemperatura.insert("valor",10.14);
        objTipo.insert("id",QJsonValue::Null);
        objTipo.insert("tipo","TEMPERATURA");
        objTemperatura.insert("tipo",objTipo);
        objTemperatura.insert("idBateria",1);
        jsonArray.append(objTemperatura);
        util::postHttp(jsonArray);
    }
}
