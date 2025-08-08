#include "mainwindow.h"

// Vendor ID y Product ID del chip CH341 en la placa Lihuiyu
#define USB_LOCK_VENDOR 0x1A86
#define USB_LOCK_PRODUCT 0x5512

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(200, 200);


    libusb_init(NULL);

    libusb_device **deviceList;
    libusb_device_handle *handle;

    int count = libusb_get_device_list(NULL, &deviceList);

    libusb_device_descriptor descriptor;
    for(int i = 0; i < count; i++){
        libusb_device *device = deviceList[i];
        libusb_get_device_descriptor(device, &descriptor);

        qDebug() << "Product ID: " << descriptor.idProduct;
        qDebug() << "Vendor ID: " << descriptor.idVendor;
        libusb_open(device, &handle);
        unsigned char manufacturer[256];
        unsigned char product[256];
        libusb_get_string_descriptor_ascii(handle, descriptor.iManufacturer, manufacturer, sizeof(manufacturer));
        qDebug() << "Fabricante:" << (char*)manufacturer;
        libusb_get_string_descriptor_ascii(handle, descriptor.iProduct, product, sizeof(product));
        qDebug() << "Producto:" << (char*)product;

    }

    libusb_free_device_list(deviceList, 1);
    libusb_close(handle);
}

MainWindow::~MainWindow(){
    libusb_exit(NULL);
}
