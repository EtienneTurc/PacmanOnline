window.onload = function () {
	var canvas = document.getElementById('canvas');
	if (!canvas) {
		alert("Impossible to get the canvas");
		return;
	}

	var context = canvas.getContext('2d');
	if (!context) {
		alert("Impossible to get the canvas context");
		return;
	}

	var myInterval = setInterval(animate, 1000 / 30);

	var xPos = 10
	var yPos = 10

	function animate() {
		context.fillRect(xPos, yPos, 100, 100);
		context.fillRect(200, 200, 100, 100);
	}
}
