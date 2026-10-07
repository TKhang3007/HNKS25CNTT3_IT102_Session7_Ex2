1. Phân tích Input / Output
Nhóm	        Dữ liệu	            Kiểu	    Ý nghĩa
Smart           Device	            deviceID	int	Mã thiết bị
	            deviceName	        char[]	    Tên thiết bị
	            status	            int	        1: bật, 0: tắt
	            ratedPowerKW	    float	    Công suất định mức

EnergySensor	voltageVolts	    float	    Điện áp đo được
	            currentAmperes	    float	    Dòng điện đo được
	            unoccupancyMinutes	int	        Thời gian phòng không có người

Biến phụ	    operatingHours	    float	    Số giờ hoạt động trong tháng

Kết quả cần xuất
Trạng thái thiết bị sau khi kiểm tra.
Cảnh báo quá tải nếu currentAmperes > 30.0.
Tự động tắt nếu phòng trống từ 15 phút trở lên.
Tổng điện năng tiêu thụ kWh.
Tổng tiền điện chưa VAT theo 4 bậc.

2. Luồng xử lý

Nhập dữ liệu -> Kiểm tra dữ liệu cảm biến → Kiểm tra giờ vận hành → Kiểm tra quá tải → Kiểm tra phòng trống → Tính kWh → Tính tiền điện → Xuất báo cáo

Lưu ý thứ tự ưu tiên:
Dữ liệu cảm biến sai -> dừng chương trình xử lý.
Giờ vận hành sai -> không tính hóa đơn.
Quá tải -> tắt thiết bị khẩn cấp.
Không có người >= 15 phút -> tắt thiết bị.
Sau khi dữ liệu hợp lệ mới tính điện năng và tiền điện.