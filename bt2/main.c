#include <stdio.h>

struct SmartDevice {
    int deviceID;
    char deviceName[100];
    int status;
    float ratedPowerKW;
};

struct EnergySensor {
    float voltageVolts;
    float currentAmperes;
    int unoccupancyMinutes;
};

int main() {
    struct SmartDevice device;
    struct EnergySensor sensor;

    float operatingHours;
    float totalKWh;
    float totalMoney = 0.0f;

    printf("========================================\n");
    printf("   RIKKEI SMARTHOME - QUAN LY NANG LUONG\n");
    printf("========================================\n");

    printf("\n--- NHAP THONG TIN THIET BI ---\n");

    printf("Nhap ma thiet bi: ");
    scanf("%d", &device.deviceID);

    printf("Nhap ten thiet bi: ");
    scanf(" %[^\n]", device.deviceName);

    printf("Nhap trang thai (1: Bat, 0: Tat): ");
    scanf("%d", &device.status);

    printf("Nhap cong suat dinh muc (kW): ");
    scanf("%f", &device.ratedPowerKW);

    printf("\n--- NHAP THONG TIN CAM BIEN ---\n");

    printf("Nhap dien ap (V): ");
    scanf("%f", &sensor.voltageVolts);

    printf("Nhap dong dien (A): ");
    scanf("%f", &sensor.currentAmperes);

    printf("Nhap thoi gian vang nguoi (phut): ");
    scanf("%d", &sensor.unoccupancyMinutes);

    printf("\nNhap so gio van hanh trong thang: ");
    scanf("%f", &operatingHours);

    if (sensor.voltageVolts < 0 ||
        sensor.currentAmperes < 0 ||
        sensor.unoccupancyMinutes < 0) {

        printf("\n========================================\n");
        printf("LOI DU LIEU CAM BIEN!\n");
        printf("Dien ap, dong dien va thoi gian vang nguoi\n");
        printf("khong duoc la so am.\n");
        printf("He thong huy thao tac xu ly.\n");
        printf("========================================\n");

        return 0;
    }

    if (operatingHours <= 0 || operatingHours > 744) {

        printf("\n========================================\n");
        printf("LOI THOI GIAN VAN HANH!\n");
        printf("So gio van hanh phai lon hon 0\n");
        printf("va khong duoc vuot qua 744 gio/thang.\n");
        printf("He thong tu choi tinh tien dien.\n");
        printf("========================================\n");

        return 0;
    }

    if (sensor.currentAmperes > 30.0f) {
        device.status = 0;

        printf("\n========================================\n");
        printf("CANH BAO NGUY HIEM!\n");
        printf("Dong dien %.2fA vuot qua nguong 30.0A.\n", sensor.currentAmperes);
        printf("He thong da NGAT KHAN CAP thiet bi.\n");
        printf("Nguy co chay no!\n");
        printf("========================================\n");
    }

    if (device.status == 1 &&
        sensor.unoccupancyMinutes >= 15) {

        device.status = 0;

        printf("\nCANH BAO TIET KIEM NANG LUONG!\n");
        printf("Phong da vang nguoi %d phut.\n",
               sensor.unoccupancyMinutes);
        printf("He thong tu dong TAT thiet bi.\n");
    }

    totalKWh = device.ratedPowerKW * operatingHours;

    if (totalKWh <= 50) {
        totalMoney = totalKWh * 1806;
    } else if (totalKWh <= 100) {
        totalMoney = 50 * 1806 + (totalKWh - 50) * 1866;
    } else if (totalKWh <= 200) {
        totalMoney = 50 * 1806 + 50 * 1866 + (totalKWh - 100) * 2167;
    } else {
        totalMoney = 50 * 1806 + 50 * 1866 + 100 * 2167 + (totalKWh - 200) * 2729;
    }


    printf("\n========================================\n");
    printf("       BAO CAO NANG LUONG\n");
    printf("========================================\n");
    printf("Ma thiet bi       : %d\n", device.deviceID);
    printf("Ten thiet bi      : %s\n", device.deviceName);
    printf("Cong suat dinh muc: %.2f kW\n", device.ratedPowerKW);
    printf("Dien ap           : %.2f V\n", sensor.voltageVolts);
    printf("Dong dien         : %.2f A\n", sensor.currentAmperes);
    printf("Vang nguoi        : %d phut\n", sensor.unoccupancyMinutes);
    printf("Thoi gian van hanh: %.2f gio\n", operatingHours);
    printf("Trang thai         : %s\n", device.status == 1 ? "DANG BAT" : "DA TAT");
    printf("----------------------------------------\n");
    printf("Tong dien nang     : %.2f kWh\n", totalKWh);
    printf("Tong tien dien     : %.0f VND\n", totalMoney);
    printf("(Chua bao gom VAT)\n");
    printf("========================================\n");

    return 0;
}