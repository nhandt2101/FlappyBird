# FlappyBird
UET - Assignment - Project
# Giới thiệu
- Họ và tên: Đặng Trí Nhân 
- Lớp: K66CB - UET
- Bài Tập Lớn: Flappy Bird (INT2215_1 - Lập trình nâng cao).
# Mô tả:
- Đây là bản làm lại của trò chơi Flappy Bird của anh Đông Nguyễn.
- Phiên bản dành cho PC.
- Có âm thanh mô phỏng các hành động của con chim trong game.
- Game có các chức năng như: chơi lại, thoát game, lưu lại điểm cao,...
- Video demo: 
# Hướng dẫn chơi
- Sử dụng phím Space để điều khiển con chim vượt qua các chướng ngại vật.
# Priview:
![image](https://user-images.githubusercontent.com/100189455/169855197-c2543c68-dacb-4a0c-b001-8805b9f00182.png)
![image](https://user-images.githubusercontent.com/100189455/169855575-ca813a8b-303a-477c-bb0f-a6ff0dd9241e.png)
![image](https://user-images.githubusercontent.com/100189455/169856097-862eb975-0354-4b28-8c83-2935f5b778da.png)
# Cài đặt
* Yêu cầu : Cần có Visual Studio Code và C++ compiler.
- Sử dụng terminal dowload soure code: git clone https://github.com/nhandt2101/FlappyBird.git
- Tại terminal: sử dụng câu lệnh sau để makefile: make
- Sau đó trò chơi sẽ được bắt đầu.

# Các kỹ thuật được sử dụng:
- Thư viện SDL2(hình ảnh, âm thanh, font chữ).
- Tạo ra nhiều các đối tượng như: con chim, background, menu,...
- Sử dụng nhiều tính kế thừa, đa hình của phương pháp lập trình hướng đối tượng. 
- Có thể lưu được high score thông qua lưu, ghi file.
- Dùng kiến thức toán / lý để tính toán được độ rơi và góc nghiêng của con chim sao cho hợp lý.
- Có thể chơi lại nhiều lần.
- Xử lý thời gian, thao tác chuột, âm thanh hình ảnh, bàn phím.

# Nguồn tham khảo:
- Set up SDL2 cho VSCode(mingw): https://www.youtube.com/watch?v=H08t6gD1Y1E
- Hình ảnh và âm thanh đều được tìm kiếm trên google.
- LazyFoo: https://lazyfoo.net/tutorials/SDL/index.php
- Askari Hassan: https://www.youtube.com/channel/UC2Ab_b49frkmgFJajOvtkpw

# Kết luận:
*Điểm tâm đắc :
- Hiểu được cách chia, tách file.
- Sử dụng được thành thạo được class và các tính chất của chúng.
- Kĩ thuật lập trình được nâng cao hơn.
- Học được cách setup môi trường thư viện ngoài.
- Chương trình có thể dễ dành refactor và cập nhật.

*Hướng phát triển thêm:
- Multiplayer.
- Sử dụng AI để con chim có thể tự động vượt qua chướng ngại vật.

