#include <WiFi.h>
#include <ESP32Servo.h>
#include <WebServer.h>
// Настройки Wi-Fi и пинов 
const char* ssid = "ITmens10";  
const char* password = "124556789"; 
const int mpin1=13;
const int mpin2=12;
const int mpin3=14;
const int mpin4=27;
WebServer server(80);
Servo punch_servo;

// Реализация Web-интерфейса
void IndexHandle(){
  const char index_html[] PROGMEM = R"rawliteral( 
  <!DOCTYPE html>
<html>
	<head>
	<style>
	body{
		background-color:#64e9b9;	
	}
	.btn{
		display:block;
		text-decoration:none;	
		color:white;
		height: 30vh;
		width: 30vw;
		background-color: #4458ff;
		color:white;
		text-align:center;
		border-radius:0.5rem;
		border: 0.1rem solid #4c9ae7; 
	}
	span{	
		font-family:"Comic Sans MS", cursive, sans-serif;
		font-size:3rem;
		display:flex;
		height: 30vh;
		width: 30vw;
		align-items:center;
		justify-content:center;
	}
	.btn_patterns{
		width:95vw;
		height:95vh;
		display:flex;
		gap:0.2rem;
		flex-wrap:wrap;
		align-content: center;
		justify-content: space-around;
	}
	.red{
		background-color:red;
		border: 0.1rem solid #fd5a2f; 
	}
	.green{
		background-color:rgb(50,245,50);
		border: 0.1rem solid #4ce75b; 
	}
	</style>
	</head>
	<body>
	<div class="btn_patterns">
		<button class="btn red" id="stop"><span>Стоп</span></a>
		<button class="btn" id="forward"><span>A</span></a>
		<button class="btn green" id="punch" ><span>Удар</span></a>
		<button class="btn" id="left"><span><--</span></a>
		<button class="btn" id="back"><span>V</span></a>
		<button class="btn" id="right"><span>--></span></a>
		<button class="btn" id="left45"><span><-- 45</span></a>
		<button class="btn" id="turn180"><span>45V</span></a>
		<button class="btn" id="right45"><span> --> 45</span></a>
	</div>
	<script>
		let finter=0;
		let linter=0;
		let binter=0;
		let rinter=0;
		let l45inter=0;
		let r45inter=0;
		let t180inter=0;
		const stopBtn = document.getElementById("stop");
		const forwardBtn = document.getElementById("forward");
		const punchBtn = document.getElementById("punch");
		const leftBtn = document.getElementById("left");
		const backBtn = document.getElementById("back");
		const rightBtn = document.getElementById("right");
		const left45Btn = document.getElementById("left45");
		const turn180Btn = document.getElementById("turn180");
		const right45Btn = document.getElementById("right45");
		stopBtn.addEventListener("touchstart", (e)=>{
			e.preventDefault();
			fetch("/stop");
		});
		forwardBtn.addEventListener("touchstart", (e)=>{
			e.preventDefault();
			fetch("/forward");
		});
		forwardBtn.addEventListener("touchend", (e)=>{
			e.preventDefault();
			fetch("/stop");
		});
		punchBtn.addEventListener("touchstart", (e)=>{
			e.preventDefault();
			fetch("/punch");
		});
		leftBtn.addEventListener("touchstart", (e)=>{
			e.preventDefault();
			fetch("/left");
		});
		leftBtn.addEventListener("touchend", (e)=>{
			e.preventDefault();
			fetch("/stop");
		});
		rightBtn.addEventListener("touchstart", (e)=>{
			e.preventDefault();
			fetch("/right");
		});
		rightBtn.addEventListener("touchend", (e)=>{
			e.preventDefault();
			fetch("/stop");
		});
		backBtn.addEventListener("touchstart", (e)=>{
			e.preventDefault();
			fetch("/back");
		});
		backBtn.addEventListener("touchend", (e)=>{
			e.preventDefault();
			fetch("/stop");
		});
		left45Btn.addEventListener("touchstart", (e)=>{
			e.preventDefault();
			fetch("/left45");
		});
		left45Btn.addEventListener("touchend", (e)=>{
			e.preventDefault();
			fetch("/stop");
		});
		right45Btn.addEventListener("touchstart", (e)=>{
			e.preventDefault();
			fetch("/right45");
		});
		right45Btn.addEventListener("touchend", (e)=>{
			e.preventDefault();
			fetch("/stop");
		});
		turn180Btn.addEventListener("touchstart", (e)=>{
			e.preventDefault();
			fetch("/turn180");
		});
		turn180Btn.addEventListener("touchend", (e)=>{
			e.preventDefault();
			fetch("/stop");
		});
	</script>
	</body>
</html>)rawliteral"; 
  server.send(200, "text/html; charset=utf-8", index_html);
}
// Функции управления движением робота
void forward() { 
  Serial.println("Forward");
  digitalWrite(mpin1,0);
  digitalWrite(mpin2,1);
  digitalWrite(mpin3,0);
  digitalWrite(mpin4,1);
  IndexHandle();
} 
void left() { 
  Serial.println("Left");
  digitalWrite(mpin1,0);
  digitalWrite(mpin2,1);
  digitalWrite(mpin3,1);
  digitalWrite(mpin4,0); 
  IndexHandle();
} 
void right() { 
  Serial.println("Right"); 
  digitalWrite(mpin1,1);
  digitalWrite(mpin2,0);
  digitalWrite(mpin3,0);
  digitalWrite(mpin4,1);
  IndexHandle();
} 
void back() { 
  digitalWrite(mpin1,1);
  digitalWrite(mpin2,0);
  digitalWrite(mpin3,1);
  digitalWrite(mpin4,0);
  Serial.println("Back");
  IndexHandle();
} 
void punch() { 
  Serial.println("Punch"); 
  punch_servo.write(90);
  delay(300);
  punch_servo.write(-90);
  IndexHandle();
} 
void stop() { 
  Serial.println("Stop");
  digitalWrite(mpin1,0);
  digitalWrite(mpin2,0);
  digitalWrite(mpin3,0);
  digitalWrite(mpin4,0);
  IndexHandle();
} 
void left45() { 
  Serial.println("Left45");
  digitalWrite(mpin1,0);
  digitalWrite(mpin2,1);
  digitalWrite(mpin3,1);
  digitalWrite(mpin4,0);  
  delay(200);
  digitalWrite(mpin1,0);
  digitalWrite(mpin2,0);
  digitalWrite(mpin3,0);
  digitalWrite(mpin4,0);
  delay(1000);
  IndexHandle();
} 
void right45() { 
  Serial.println("Left45");
  digitalWrite(mpin1,1);
  digitalWrite(mpin2,0);
  digitalWrite(mpin3,0);
  digitalWrite(mpin4,1);  
  delay(200);
  digitalWrite(mpin1,0);
  digitalWrite(mpin2,0);
  digitalWrite(mpin3,0);
  digitalWrite(mpin4,0);
  delay(1000);
  IndexHandle();
} 
// подключение к Wi-Fi и настройка сервера
void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.println("...");
  }
  Serial.print("IP : ");
  Serial.println(WiFi.localIP());
  punch_servo.attach(25);
  pinMode(mpin1, OUTPUT);
  pinMode(mpin2, OUTPUT);
  pinMode(mpin3, OUTPUT);
  pinMode(mpin4, OUTPUT);
  digitalWrite(mpin1,0);
  digitalWrite(mpin2,0);
  digitalWrite(mpin3,0);
  digitalWrite(mpin4,0);
  server.on("/",  HTTP_GET,  IndexHandle);
  server.on("/forward", HTTP_GET, forward); 
  server.on("/left", HTTP_GET, left); 
  server.on("/right", HTTP_GET, right);   
  server.on("/back", HTTP_GET, back);
  server.on("/punch", HTTP_GET, punch);   
  server.on("/stop", HTTP_GET, stop);
  server.on("/left45", HTTP_GET, left45); 
  server.on("/right45", HTTP_GET, right45);  
  server.begin();
}

void loop() {
  server.handleClient();

}

