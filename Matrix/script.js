const langs = [
	"Hello World",
	"Le Anh Duc",
	"Thang Long IT",
	"Anh Duc IT",
	"Anh Duc Blog",
	"Admin Duc Blog",
	"Thang Long University",
	"Nguyen Duong Hoang Thanh",
	"Kumusta Kalibutan",
	"leanhduc.pro.vn",
	"thanglongit.vn",
	"Lê Anh Đức",
	"Thăng Long IT",
	"Đại Học Thăng Long",
	"Xin Chào",
	"Hello World",
	"Hihi",
	"Hacker",
	"Hacking",
	"Dong Anh IT",
	"Đong Anh IT",
	"Dan 29",
	"Ha Noi",
	"Hà Nội",
	"Việt Nam",
	"Novorepnoye",
	"Hello World",
	"Mylta Power",
	"Sosnovka Military Base",
	"Mylta",
	"Yasnaya Polyana",
	"Pochinki",
	"Georgopol",
	"Prison",
	"Mansion",
	"Stalber",
	"Primorsk",
	"Hello World",
	"Sanhok",
	"Đà Nẵng",
	"Việt Nam",
	"Đông Anh",
	"Kim Nỗ",
	"Thọ Đa",
	"Lê Anh Đức",
	"Quảng Bình",
	"Bắc Ninh",
	"Hello World",
	"Sài Gòi",
	"Cần Thơ",
	"Cà Mau",
	"Bãi Cháy",
	"Vịnh Hạ Long",
	"Sầm Sơn",
	"Nghệ An",
	"Thanh Hóa",
	"PUBG",
	"ROS",
	"Hei Verden",
	"Xin Chào",
	"Xin chao tat ca cac ban",
	"From Dong Anh with love",
	"Le Anh Duc",
];

let charSize = 20;
let fallRate = charSize / 2;
let streams;

// -------------------------------
class Char {
	constructor(value, x, y, speed) {
		this.value = value;
		this.x = x;
		this.y = y;
		this.speed = speed;
	}

	draw() {
		const flick = random(100);
		// 10 percent chance of flickering a number instead
		if (flick < 10) {
			fill(120, 30, 100);
			text(round(random(9)), this.x, this.y);
		} else {
			text(this.value, this.x, this.y);
		}

		// fall down
		this.y = this.y > height ? 0 : this.y + this.speed;
	}
}

// -------------------------------------
class Stream {
	constructor(text, x) {
		const y = random(text.length);
		const speed = random(2, 10);
		this.chars = [];

		for (let i = text.length; i >= 0; i--) {
			this.chars.push(
				new Char(text[i], x, (y + text.length - i) * charSize, speed)
			);
		}
	}

	draw() {
		fill(120, 100, 100);
		this.chars.forEach((c, i) => {
			// 30 percent chance of lit tail
			const lit = random(100);
			if (lit < 30) {
				if (i === this.chars.length - 1) {
					fill(120, 30, 100);
				} else {
					fill(120, 100, 90);
				}
			}

			c.draw();
		});
	}
}

function createStreams() {
	// create random streams from langs that span the width
	for (let i = 0; i < width; i += charSize) {
		streams.push(new Stream(random(langs), i));
	}
}

function reset() {
	streams = [];
	createStreams();
}

function setup() {
	createCanvas(innerWidth, innerHeight);
	reset();
	frameRate(20);
	colorMode(HSB);
	noStroke();
	textSize(charSize);
	textFont("monospace");
	background(0);
}

function draw() {
	background(0, 0.4);
	streams.forEach((s) => s.draw());
}

function windowResized() {
	resizeCanvas(innerWidth, innerHeight);
	background(0);
	reset();
}
