#include <QCoreApplication>
#include "QDebug"

struct Data8_t{
template<typename Type>
void operator=(Type);
operator uint8_t() const ;
    struct toBits
    {
        toBits();
        template<typename Type>
        void operator=(Type);
        operator uint8_t() const ;
        uint8_t b0:1;  // :1 =0-1 aralığı   :3 olsaydı 0-111 aralığı olacaktı.
        uint8_t b1:1;
        uint8_t b2:1;
        uint8_t b3:1;
        uint8_t b4:1;
        uint8_t b5:1;
        uint8_t b6:1;
        uint8_t b7:1;
    private:

      uint8_t operator_toBits; // 1 bite dönüştürülmüş değer tutuluyor
      toBits& toBit();
    };

toBits operator_Data8_t;  // 1 byte dönüştürülmüş değer tutuluyor

toBits& toBits(){
    return operator_Data8_t;
}

};

////// Data8_t's function implimentation
template<typename Type>
void Data8_t:: operator=(Type item){  //= operatörü ile değeri almak için
     operator_Data8_t=(uint8_t)item;

     operator_Data8_t.b0=((operator_Data8_t)& 0x01)>>0;
     operator_Data8_t.b1=((operator_Data8_t)& 0x02)>>1;
     operator_Data8_t.b2=((operator_Data8_t)& 0x04)>>2;
     operator_Data8_t.b3=((operator_Data8_t)& 0x08)>>3;
     operator_Data8_t.b4=((operator_Data8_t)& 0x10)>>4;
     operator_Data8_t.b5=((operator_Data8_t)& 0x20)>>5;
     operator_Data8_t.b6=((operator_Data8_t)& 0x40)>>6;
     operator_Data8_t.b7=((operator_Data8_t)& 0x80)>>7;

}

Data8_t::operator uint8_t() const {   //değeri okumak için

    return (unsigned char)operator_Data8_t;
}

////// toBits's function implimentation
template<typename Type>
void Data8_t::toBits::operator=(Type item){  //1 bitlik değeri değiştirmek için
    operator_toBits=(uint8_t)item;
}
Data8_t::toBits:: operator uint8_t()const{  // 1 bitlik değeri okumak için
    return (unsigned char)operator_toBits;
}
Data8_t::toBits::toBits(){
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
     Data8_t data;
     data=7;
     unsigned char temp_data=data;
     qDebug()<<"temp_data:"<<temp_data;

    qDebug()<<"0. Bit değeri ="<< data.toBits().b0;
    qDebug()<<"1. Bit değeri ="<< data.toBits().b1;
    qDebug()<<"2. Bit değeri ="<< data.toBits().b2;
    qDebug()<<"3. Bit değeri ="<< data.toBits().b3;
    qDebug()<<"4. Bit değeri ="<< data.toBits().b4;
    qDebug()<<"5. Bit değeri ="<< data.toBits().b5;
    qDebug()<<"6. Bit değeri ="<< data.toBits().b6;
    qDebug()<<"7. Bit değeri ="<< data.toBits().b7;
    data.toBits().b5=1;
    qDebug()<<"5. Bitin yeni değeri="<<data.toBits().b5;
    return a.exec();
}
