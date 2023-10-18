#include <iostream>
#include <bitset>
#include <vector>

int main() {
    
    // Verificación de Paridad
    std::bitset<8> data_parity("10010101");
    int countOnes = data_parity.count();
    int parityBit = countOnes % 2;
    std::cout << "Bit de Paridad: " << parityBit << std::endl;



    // Comprobación de Redundancia Cíclica (CRC)
    std::bitset<10> data_crc("1101101011");
    std::bitset<3> crc("011"); // Valor de CRC
    std::bitset<13> packet_crc = data_crc.to_ulong();
    packet_crc <<= 3;
    packet_crc |= crc.to_ulong();
    std::cout << "Paquete enviado (CRC): " << packet_crc << std::endl;



    // Comprobación de Redundancia Longitudinal (LRC)
    std::bitset<8> data_lrc("01000001");
    int parity_lrc = 0;
    for (size_t i = 0; i < data_lrc.size(); ++i) {
        parity_lrc ^= data_lrc[i];
    }
    std::cout << "Bit de Paridad (LRC): " << parity_lrc << std::endl;



    // Sumas de Verificación
    std::vector<int> numbers = {5, 7, 2, 8};
    int checksum = 0;
    for (int num : numbers) {
        checksum += num;
    }
    checksum %= 256; // Restringir el resultado a 8 bits (0-255)
    std::cout << "Suma de Verificación: " << checksum << std::endl;

    // Envío de datos junto con la suma de verificación
    std::cout << "Datos enviados: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "Checksum: " << checksum << std::endl;

    // Receptor
    std::vector<int> receivedNumbers = {5, 7, 2, 8};
    int receivedChecksum = 22; // Supongamos que el receptor recibe el checksum 22

    int receivedChecksumCalculated = 0;
    for (int num : receivedNumbers) {
        receivedChecksumCalculated += num;
    }
    receivedChecksumCalculated %= 256; // Calcular el checksum recibido

    // Verificar si el checksum recibido coincide con el calculado
    if (receivedChecksum == receivedChecksumCalculated) {
        std::cout << "Checksum recibido es correcto." << std::endl;
    } else {
        std::cout << "Error: el checksum recibido no coincide." << std::endl;
    }

    return 0;
}
