#include "hilo.h"
#include "util.h"
hilo::hilo() {
}
void hilo::run(){
    int idBateria = variableUtil.leerIdArchivo();
    Servidor ser;
    while(true){
        sleep(30);
        QJsonArray jsonArray;
        QJsonObject objCarga;
        QJsonObject objTipo;
        QJsonObject datos = ser.getDatos();
        if(!datos.isEmpty()){
            QDateTime horaUtc = QDateTime::currentDateTimeUtc();
            // 2. Crear la zona horaria UTC-3 (3 horas * 3600 segundos = 10800)
            QTimeZone zonaMenosTres(-10800);
            // 3. Convertir la hora a la nueva zona
            QDateTime horaLocal = horaUtc.toTimeZone(zonaMenosTres);
            // Formatear a: yyyy-MM-dd HH:mm:ss
            QString formato = horaLocal.toString("yyyy-MM-dd HH:mm:ss");
            objCarga.insert("id",QJsonValue::Null);
            objCarga.insert("fecha",formato);
            objCarga.insert("valor",datos["carga"]);
            objTipo.insert("id",QJsonValue::Null);
            objTipo.insert("tipo","CARGA");
            objCarga.insert("idBateria",idBateria);
            objCarga.insert("tipo",objTipo);
            jsonArray.append(objCarga);
            QJsonObject objCorriente;
            objCorriente.insert("id",QJsonValue::Null);
            objCorriente.insert("fecha",formato);
            objCorriente.insert("valor",datos["corriente"]);
            objTipo.insert("id",QJsonValue::Null);
            objTipo.insert("tipo","CORRIENTE");
            objCorriente.insert("tipo",objTipo);
            objCorriente.insert("idBateria",idBateria);
            jsonArray.append(objCorriente);
            QJsonObject objTension;
            objCarga.insert("id",QJsonValue::Null);
            objTension.insert("fecha",formato);
            objTension.insert("valor",datos["tension"]);
            objTipo.insert("id",QJsonValue::Null);
            objTipo.insert("tipo","TENSION");
            objTension.insert("tipo",objTipo);
            objTension.insert("idBateria",idBateria);
            jsonArray.append(objTension);
            QJsonObject objTemperatura;
            objCarga.insert("id",QJsonValue::Null);
            objTemperatura.insert("fecha",formato);
            objTemperatura.insert("valor",datos["temperatura"]);
            objTipo.insert("id",QJsonValue::Null);
            objTipo.insert("tipo","TEMPERATURA");
            objTemperatura.insert("tipo",objTipo);
            objTemperatura.insert("idBateria",idBateria);
            jsonArray.append(objTemperatura);
            int respuesta =variableUtil.postHttp(jsonArray);
            if(respuesta != -1 && id != -1){
                idBateria = respuesta;
                variableUtil.guardarIdArchivo(idBateria);
            }

        }
    }
}
