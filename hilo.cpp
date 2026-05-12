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
        objCarga.insert("id",QJsonValue::Null);
        objCarga.insert("fecha","2026-01-06 00:00:00");
        objCarga.insert("valor",3.14);
        objTipo.insert("id",QJsonValue::Null);
        objTipo.insert("tipo","CARGA");
        objCarga.insert("idBateria",1);
        objCarga.insert("tipo",objTipo);
        jsonArray.append(objCarga);
        QJsonObject objCorriente;
        objCarga.insert("id",QJsonValue::Null);
        objCorriente.insert("fecha","2026-01-06 00:00:00");
        objCorriente.insert("valor",1.14);
        objTipo.insert("id",QJsonValue::Null);
        objTipo.insert("tipo","CORRIENTE");
        objCorriente.insert("tipo",objTipo);
        objCorriente.insert("idBateria",1);
        jsonArray.append(objCorriente);
        QJsonObject objTension;
        objCarga.insert("id",QJsonValue::Null);
        objTension.insert("fecha","2026-01-06 00:00:00");
        objTension.insert("valor",2.14);
        objTipo.insert("id",QJsonValue::Null);
        objTipo.insert("tipo","TENSION");
        objTension.insert("tipo",objTipo);
        objTension.insert("idBateria",1);
        jsonArray.append(objTension);
        QJsonObject objTemperatura;
        objCarga.insert("id",QJsonValue::Null);
        objTemperatura.insert("fecha","2026-01-06 00:00:00");
        objTemperatura.insert("valor",2.14);
        objTipo.insert("id",QJsonValue::Null);
        objTipo.insert("tipo","TEMPERATURA");
        objTemperatura.insert("tipo",objTipo);
        objTemperatura.insert("idBateria",1);
        jsonArray.append(objTemperatura);
        util::postHttp(jsonArray);
    }
}
