# このパッケージは何？
- 実際にGold Twitterでモータ制御を行ってみたときのプログラム集
- Gold TwitterはG-TWI 6/100EEとG-TWI 25/100EEの２種類使用

# プログラム一覧
- read_motor.c : モータの情報を読み取り、端末に表示するプログラム
- torque_control.c : 実際にトルク指令を送信して動かし、データをcsvファイルに保存するプログラム
- test_program.c : テスト用のプログラム(現在はだんだんトルクをあげたり、要求トルクを取得したりしている)
- PD_control.c : トルクベースでPD制御するプログラム
- dualmotor_read.c : モータ２つを読み取る、トルク指令を送信するプログラム

# その他
- math.hをincludeするときは、CMakeLists.txtのtarget_link_libraries(プログラム名 soem)をtarget_link_libraries(プログラム名 soem m)にする
- トルク指令を与える場合のデジタル値は、G-TWI 6/100EEでは80、G-TWI 25/100EEでは18が安全
