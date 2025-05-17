#include <Arduino.h>

// 定义 LED 连接的引脚 (ESP32)
const int ledPin1 = 27;
const int ledPin2 = 26;
const int ledPin3 = 25;
const int ledPin4 = 33;
const int ledPin5 = 32;

 
void setup() {
  // 初始化 LED 引脚为输出模式
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  
  // 确保启动时所有 LED 都是熄灭的
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
  digitalWrite(ledPin5, LOW);

  // 初始化串口通信，波特率设置为 9600
  Serial.begin(9600);

  // 在串口监视器上显示启动信息和控制指令
  Serial.println("ESP32 5 LED 控制程序已启动！");
  Serial.println("输入 '1' 控制 LED1 (GPIO27) 亮/灭");
  Serial.println("输入 '2' 控制 LED2 (GPIO26) 亮/灭");
  Serial.println("输入 '3' 控制 LED3 (GPIO25) 亮/灭");
  Serial.println("输入 '4' 控制 LED4 (GPIO33) 亮/灭");
  Serial.println("输入 '5' 控制 LED5 (GPIO32) 亮/灭");
}

void loop() {
  // 检查串口是否有数据可读
  if (Serial.available() > 0) {
    // 读取串口接收到的指令
    String command = Serial.readStringUntil('\n');
    command.trim();

    // 根据接收到的指令执行相应的操作
    if (command == "1") {
      digitalWrite(ledPin1, !digitalRead(ledPin1)); // 切换 LED1 的状态
      Serial.print("LED1 (GPIO27) 状态已切换为: ");
      Serial.println(digitalRead(ledPin1) ? "亮" : "灭");
    } else if (command == "2") {
      digitalWrite(ledPin2, !digitalRead(ledPin2)); // 切换 LED2 的状态
      Serial.print("LED2 (GPIO26) 状态已切换为: ");
      Serial.println(digitalRead(ledPin2) ? "亮" : "灭");
    } else if (command == "3") {
      digitalWrite(ledPin3, !digitalRead(ledPin3)); // 切换 LED3 的状态
      Serial.print("LED3 (GPIO25) 状态已切换为: ");
      Serial.println(digitalRead(ledPin3) ? "亮" : "灭");
    } else if (command == "4") {
      digitalWrite(ledPin4, !digitalRead(ledPin4)); // 切换 LED4 的状态
      Serial.print("LED4 (GPIO33) 状态已切换为: ");
      Serial.println(digitalRead(ledPin4) ? "亮" : "灭");
    } else if (command == "5") {
      digitalWrite(ledPin5, !digitalRead(ledPin5)); // 切换 LED5 的状态
      Serial.print("LED5 (GPIO32) 状态已切换为: ");
      Serial.println(digitalRead(ledPin5) ? "亮" : "灭");
    } else {
      Serial.print("未知指令: ");
      Serial.println(command);
    }
  }
}